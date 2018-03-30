#include "kmdetectionflow.h"

#include <QDir>
#include <QDebug>
#include <QDateTime>
#include <QSettings>
#include <QElapsedTimer>
#include <QCoreApplication>

#include "usunit.h"
#include "absorbance.h"
#include "oserialport.h"
#include "ospectrograph.h"
#include "kmsettingmodel.h"
#include "opticalintensity.h"

#define TIMEOUT 3000

KMDetectionFlow::KMDetectionFlow(OSerialPort *serialPort, OSpectrograph *spectrograph, QObject *parent) :
    QObject(parent) {

    m_pSerialPort = serialPort;
    m_pSpectrograph = spectrograph;

    QString fileName = QDir::currentPath() + "/configs/kitmethod/kitmethod.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);

    QStringList msWidths = configIniReader->value("MicroscaleProcess/SmoothWidth").toStringList();
    foreach(QString width, msWidths) {
        m_msWidths.append(width.toInt());
    }
    QStringList msFactors = configIniReader->value("MicroscaleProcess/CorrectionFactor").toStringList();
    foreach(QString factor, msFactors) {
        m_msFactors.append(factor.toDouble());
    }

    m_ctWidth = configIniReader->value("CuvetteProcess/SmoothWidth").toInt();
    m_ctFactor = configIniReader->value("CuvetteProcess/CorrectionFactor").toInt();

    delete configIniReader;
    configIniReader = NULL;
}

KMDetectionFlow::~KMDetectionFlow() {

}

/**
 * @brief KMDetectionFlow::blank
 * @param setting
 * @return
 */
QString KMDetectionFlow::blank(KMSettingModel *setting) {
    m_ctBlankList.clear();
    m_msBlankMapper.clear();

    QString ok = "Success";
    if (setting->getDetectionMethod() == "Cuvette") {

        // Cuvette空白
        int rc = setting->getCuvetteFrequency();
        int it = setting->getCuvetteIntegrationTime();
        OpticalIntensity intensity = m_pSpectrograph->readSpectrograph(it, rc);
        m_ctBlankList.append(intensity);
        QVector<double> y;
        for (int i = 0; i < intensity.intensity().size(); i ++) {
            y.append(0);
        }
        QString title = QString( "Blank%1" ).arg(setting->getOptical());
        emit toDrawCurve(title, intensity.waveLength(), y);

    } else if (setting->getDetectionMethod() == "Microscale") {

        // Microscale空白
        if (setting->getOptical() != "Auto") {
            ok = excuteMicroscaleBlank(setting, setting->getOptical());
        } else {
            QStringList opticalList = setting->getMicroscaleOpticalList();
            foreach (QString opticalStr, opticalList) {
                ok = excuteMicroscaleBlank(setting, opticalStr);
                if (ok != "Success") {
                    break;
                }
                delay(500);
            }

            if (m_pSerialPort != NULL) {
                QByteArray rxBuffer;
                QByteArray txBuffer = USUnit::startStepMotor(MOTOR_01, 0);
                qDebug() << "Optical order:" << toHexStr(txBuffer);
                QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
                qDebug() << "Optical order:" << toHexStr(rxBuffer);
                if (ok != "Success") {
                    return ok;
                }
            }
        }
    }
    return ok;
}

/**
 * @brief KMDetectionFlow::measure
 * @param setting
 * @return
 */
QString KMDetectionFlow::measure(KMSettingModel *setting) {

    QString ok = "Success";
    if (setting->getDetectionMethod() == "Cuvette") {

        // Cuvette检测
        if (m_ctBlankList.isEmpty()) {
            return tr( "Missing blank data!" );
        }

        if(m_pSerialPort != NULL) {
            QByteArray rxBuffer;
            QByteArray txBuffer = USUnit::startDcMotor(MIXING_MOTOR_01, setting->getMixingLevel());
            qDebug() << "start mixing:" << toHexStr(txBuffer);
            QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << "start mixing:" << toHexStr(rxBuffer);
            if (ok != "Success") {
                return ok;
            }
        }
        delay(setting->getMixingTime());

        if(m_pSerialPort != NULL) {
            QByteArray rxBuffer;
            QByteArray txBuffer = USUnit::stopDcMotor(MIXING_MOTOR_01);
            qDebug() << "stop mixing:" << toHexStr(txBuffer);
            ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << "stop mixing:" << toHexStr(rxBuffer);
            if (ok != "Success") {
                return ok;
            }
        }
        delay(setting->getStaticTime());

        int bwl = setting->getBwl();
        int rc = setting->getCuvetteFrequency();
        int it = setting->getCuvetteIntegrationTime();
        OpticalIntensity mi = m_pSpectrograph->readSpectrograph(it, rc);
        OpticalIntensity bi = m_ctBlankList.first();
        Absorbance *r = OpticalIntensity::toAbsorbance(mi, bi, setting->getOptical().toDouble(), m_ctWidth, bwl);
        r->setCorrectionFactor(m_ctFactor*setting->getCuvetteCorrectionFactor());
        showResult(setting, r, 0);

    } else if (setting->getDetectionMethod() == "Microscale") {

        // Microscale检测
        if (setting->getOptical() != "Auto") {
            // 指定光程
            ok = excuteMicroscaleMeasure(setting, setting->getOptical(),
                                         setting->getIdList(), NULL, KMDetectionFlow::showResult);
        } else {
            // 自动光程
            QList<int> stdId;
            QList<int> maxId;
            QList<int> minId;
            // 1.预判光程
            ok = prejudgement(setting, stdId, maxId, minId);
            if (ok != "Success") {
                return ok;
            }
            // 2.检测标准光程
            if (!stdId.isEmpty()) {
                ok = excuteMicroscaleMeasure(setting, setting->getMicroscaleStdOptical(),
                                             stdId, NULL, KMDetectionFlow::showResult);
                if (ok != "Success") {
                    return ok;
                }
            }

            if (!minId.isEmpty()) {
                delay(500);
                // 3.检测最小光程
                ok = excuteMicroscaleMeasure(setting, setting->getMicroscaleMinOptical(),
                                             minId, NULL, KMDetectionFlow::showResult);
                if (ok != "Success") {
                    return ok;
                }
            }
            if (!maxId.isEmpty()) {
                delay(500);
                // 4.检测最大光程
                ok = excuteMicroscaleMeasure(setting, setting->getMicroscaleMaxOptical(),
                                             maxId, NULL, KMDetectionFlow::showResult);
                if (ok != "Success") {
                    return ok;
                }
            }

            if (m_pSerialPort != NULL) {
                QByteArray rxBuffer;
                QByteArray txBuffer = USUnit::startStepMotor(MOTOR_01, 0);
                qDebug() << "Optical order:" << toHexStr(txBuffer);
                QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
                qDebug() << "Optical order:" << toHexStr(rxBuffer);
                if (ok != "Success") {
                    return ok;
                }
            }
        }
    }
    return ok;
}

/**
 * @brief KMDetectionFlow::transformUnit
 * @param unit
 * @return
 */
double KMDetectionFlow::transformUnit(QString unit) {
    if (unit == "ng/uL" ||
            unit == "ug/mL" || unit == "mg/L") {
        return 1000;
    } else if (unit == "mg/mL" || unit == "g/L") {
        return 1;
    } else if (unit == "ng/mL") {
        return 1000000;
    } else {
        return 1;
    }
}

/**
 * @brief delay
 * @param timeout
 */
void KMDetectionFlow::delay(int timeout) {

    QElapsedTimer t;
    t.start();
    m_isWaiting = true;
    while(t.elapsed() < timeout) {
        QCoreApplication::processEvents();
        if (!m_isWaiting) {
            return;
        }
    }
    m_isWaiting = false;
}

/**
 * @brief KMDetectionFlow::showResult
 * @param a
 */
void KMDetectionFlow::showResult(KMSettingModel *setting, Absorbance *a, int id) {

    // 标准单位为mg/mL
    //double c = a->getAbsoByWL((double)setting->getMwl())*transformUnit(setting->getUnit());//ltg
    double c = a->getAbsoByWL((double)setting->getMwl());
    emit toShowResult(c);

    QVector<double> x = a->waveLength();
    QVector<double> y = a->absorbance();
    QString curveName = QString("%1%2").arg(setting->getSampleName()).arg(id+1);
    emit toDrawCurve(curveName, x, y);
}

/**
 * @brief KMDetectionFlow::prejudgement
 * @param setting
 * @param stdId
 * @param maxId
 * @param minId
 * @return
 */
QString KMDetectionFlow::prejudgement(KMSettingModel *setting,
                                         QList<int> &stdId, QList<int> &maxId, QList<int> &minId) {

    QString opticalStr = setting->getMicroscaleStdOptical();
    QList<Absorbance *> result;
    QString ok = excuteMicroscaleMeasure(setting, opticalStr, setting->getIdList(), &result);
    if (ok != "Success") {
        return tr( "Prejudgement error!" );
    }

    stdId.clear();
    maxId.clear();
    minId.clear();

    double upper = setting->getMicroscaleUpperLimit();
    double lower = setting->getMicroscaleLowerLimit();
    foreach(Absorbance *a, result) {
        double v = a->getAbsoByWL((double)setting->getMwl());
        if (v < lower) {
            // 1.低浓度使用大光程
            maxId.append(result.indexOf(a));
        } else if (v > upper) {
            // 2.高浓度使用小光程
            minId.append(result.indexOf(a));
        } else {
            // 3.其他使用标准光程
            stdId.append(result.indexOf(a));
        }
    }

    qDeleteAll(result);
    result.clear();
    return "Success";
}

/**
 * @brief KMDetectionFlow::excuteMicroscaleBlank
 * @param setting
 * @param opticalStr
 * @return
 */
QString KMDetectionFlow::excuteMicroscaleBlank(KMSettingModel *setting, QString opticalStr) {

    int rc = setting->getMicroscaleFrequency(opticalStr);
    int it = setting->getMicroscaleIntegrationTime(opticalStr);
    int ra = setting->getMicroscaleRotateAngle(opticalStr);
    // 1.调整电机运行到指定的光程的位置
    if (m_pSerialPort != NULL) {
        QByteArray rxBuffer;
        QByteArray txBuffer = USUnit::startStepMotor(MOTOR_01, ra*10);
        qDebug() << "Optical order:" << toHexStr(txBuffer);
        QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
        qDebug() << "Optical order:" << toHexStr(rxBuffer);
        if (ok != "Success") {
            return ok;
        }
    }

    QList<OpticalIntensity> channelBlankList;
    for (int i = 0; i < setting->getChannelNumber(); i ++) {
        // 2.调整运行到指定通道的位置
        if (m_pSerialPort != NULL &&
                setting->getMaxChannelNumber() > 1) {
            QByteArray rxBuffer;
            double targetAngle = i*10/setting->getMaxChannelNumber();
            QByteArray txBuffer = USUnit::startStepMotor(MOTOR_02, targetAngle);
            qDebug() << "Channel order:" << toHexStr(txBuffer);
            QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << "Channel order:" << toHexStr(rxBuffer);
            if (ok != "Success") {
                return ok;
            }
        }

        // 3.读取光谱中的光强数据
        OpticalIntensity intensity = m_pSpectrograph->readSpectrograph(it, rc);
        channelBlankList.append(intensity);
        QVector<double> y;
        for (int i = 0; i < intensity.intensity().size(); i ++) {
            y.append(0);
        }
        QString title = QString( "Blank%1" ).arg(setting->getMicroscaleOpticalList().indexOf(opticalStr) + 1);
        emit toDrawCurve(title, intensity.waveLength(), y);
    }

    if (m_pSerialPort != NULL &&
            setting->getMaxChannelNumber() > 1) {
        QByteArray rxBuffer;
        QByteArray txBuffer = USUnit::startStepMotor(MOTOR_02, 0);
        qDebug() << "Zero order:" << toHexStr(txBuffer);
        QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
        qDebug() << "Zero order:" << toHexStr(rxBuffer);
        if (ok != "Success") {
            return ok;
        }
    }

    m_msBlankMapper.insert(opticalStr, channelBlankList);
    return "Success";
}

/**
 * @brief KMDetectionFlow::excuteMicroscaleMeasure
 * @param setting
 * @param opticalStr
 * @param excuteId
 * @param result
 * @param showResult
 * @return
 */
QString KMDetectionFlow::excuteMicroscaleMeasure(KMSettingModel *setting, QString opticalStr,
                                                    QList<int> excuteId, QList<Absorbance *> *result, pShowResultFunc showResult) {
    if (excuteId.isEmpty()) {
        return "Success";
    }

    int bwl = setting->getBwl();
    int rc = setting->getMicroscaleFrequency(opticalStr);
    int it = setting->getMicroscaleIntegrationTime(opticalStr);
    int ra = setting->getMicroscaleRotateAngle(opticalStr);
    // 1.调整电机运行到指定的光程的位置
    if (m_pSerialPort != NULL) {
        QByteArray rxBuffer;
        QByteArray txBuffer = USUnit::startStepMotor(MOTOR_01, ra*10);
        qDebug() << "Optical order:" << txBuffer;
        QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
        qDebug() << "Optical order:" << rxBuffer;
        if (ok != "Success") {
            return ok;
        }
    }

    double mf = setting->getMicroscaleCorrectionFactor(opticalStr);
    QList<OpticalIntensity> channelBlankList = m_msBlankMapper.value(opticalStr);

    foreach (int i, excuteId) {
        // 2.调整运行到指定通道的位置
        if (m_pSerialPort != NULL &&
                setting->getMaxChannelNumber() > 1) {
            QByteArray rxBuffer;
            int targetAngle = i*10/setting->getMaxChannelNumber();
            QByteArray txBuffer = USUnit::startStepMotor(MOTOR_02, targetAngle);
            qDebug() << "Channel order:" << toHexStr(txBuffer);
            QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << "Channel order:" << toHexStr(rxBuffer);
            if (ok != "Success") {
                return ok;
            }
        }

        // 3.读取光谱中的光强数据
        OpticalIntensity mi = m_pSpectrograph->readSpectrograph(it, rc);
        OpticalIntensity bi = channelBlankList.at(i);
        Absorbance *r = OpticalIntensity::toAbsorbance(mi, bi, opticalStr.toDouble(), m_msWidths.at(i), bwl);
        r->setCorrectionFactor(m_msFactors.at(i)*mf);
        if (result != NULL) {
            result->append(r);
        }
        if (showResult != NULL) {
            (this->*showResult)(setting, r, i);
        }
    }

    if (m_pSerialPort != NULL &&
            setting->getMaxChannelNumber() > 1) {
        QByteArray rxBuffer;
        QByteArray txBuffer = USUnit::startStepMotor(MOTOR_02, 0);
        qDebug() << "Zero order:" << toHexStr(txBuffer);
        QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
        qDebug() << "Zero order:" << toHexStr(rxBuffer);
        if (ok != "Success") {
            return ok;
        }
    }

    return "Success";
}

