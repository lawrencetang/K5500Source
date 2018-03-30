#include "uvdetectionflow.h"

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
#include "uvsettingmodel.h"
#include "opticalintensity.h"

#define TIMEOUT 3000

UVDetectionFlow::UVDetectionFlow(OSerialPort *serialPort, OSpectrograph *spectrograph, QObject *parent) :
    QObject(parent) {

    m_isWaiting = false;
    m_pSerialPort = serialPort;
    m_pSpectrograph = spectrograph;

    QString fileName = QDir::currentPath() + "/configs/protein/protein.ini";
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

UVDetectionFlow::~UVDetectionFlow() {

}

/**
 * @brief UVDetectionFlow::blank
 * @param setting
 * @return
 */
QString UVDetectionFlow::blank(UVSettingModel *setting) {
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
        QString opticalStr = setting->getOptical();
        if (opticalStr != "1") {
            opticalStr = "1";
        }
        ok = excuteMicroscaleBlank(setting, opticalStr);
    }
    return ok;
}

/**
 * @brief UVDetectionFlow::measure
 * @param setting
 * @return
 */
QString UVDetectionFlow::measure(UVSettingModel *setting) {

    QString ok = "Success";
    if (setting->getDetectionMethod() == "Cuvette") {

        // Cuvette检测
        if (m_ctBlankList.isEmpty()) {
            return tr( "Missing blank data!" );
        }

        if(m_pSerialPort != NULL) {
            QByteArray rxBuffer;
            QByteArray txBuffer = USUnit::startDcMotor(MIXING_MOTOR_01, setting->getMixingLevel());
            qDebug() << "Start mixing:" << toHexStr(txBuffer);
            QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << "Start mixing:" << toHexStr(rxBuffer);
            if (ok != "Success") {
                return ok;
            }
        }
        delay(setting->getMixingTime());
        if(m_pSerialPort != NULL) {
            QByteArray rxBuffer;
            QByteArray txBuffer = USUnit::stopDcMotor(MIXING_MOTOR_01);
            qDebug() << "Stop mixing:" << toHexStr(txBuffer);
            ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << "Stop mixing:" << toHexStr(rxBuffer);
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
        showResult(setting, r, 0, setting->getOptical());

    } else if (setting->getDetectionMethod() == "Microscale") {

        QString opticalStr = setting->getOptical();
        if (opticalStr != "1") {
            opticalStr = "1";
        }
        ok = excuteMicroscaleMeasure(setting, opticalStr, setting->getIdList(), NULL, UVDetectionFlow::showResult);
    }
    return ok;
}

/**
 * @brief UVDetectionFlow::delay
 * @param timeout
 */
void UVDetectionFlow::delay(int timeout) {
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
 * @brief UVDetectionFlow::showResult
 * @param a
 */
void UVDetectionFlow::showResult(UVSettingModel *setting, Absorbance *a, int id, QString optical) {

    QString fileName = QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".csv";
    // 计算浓度,A230,A260,A280
    double c1 = a->getAbsoByWL((double)setting->getWl1()) * setting->getCoef1();
    double c2 = a->getAbsoByWL((double)setting->getWl2()) * setting->getCoef2();
    double c3 = a->getAbsoByWL((double)setting->getWl3()) * setting->getCoef3();
    double c4 = a->getAbsoByWL((double)setting->getWl4()) * setting->getCoef4();
    double c5 = a->getAbsoByWL((double)setting->getWl5()) * setting->getCoef5();

    QStringList record;
    record << "result:" << setting->getSampleName()
           << QString::number(setting->getWl1()) << QString::number(setting->getCoef1()) << QString::number(c1)
           << QString::number(setting->getWl2()) << QString::number(setting->getCoef2()) << QString::number(c2)
           << QString::number(setting->getWl3()) << QString::number(setting->getCoef3()) << QString::number(c3)
           << QString::number(setting->getWl4()) << QString::number(setting->getCoef4()) << QString::number(c4)
           << QString::number(setting->getWl5()) << QString::number(setting->getCoef5()) << QString::number(c5)
           << QString::number(id+1) << optical << fileName;

    QStringList result;
    QString resultStr;
    foreach(QString item, record){
        resultStr.append(item);
        if (!result.endsWith(item)) {
            resultStr.append( "," );
        }
    }
    record.removeFirst();
    result.append(resultStr);

    QVector<double> x = a->waveLength();
    QVector<double> y = a->absorbance();

    QString dataStr;
    for(int i = 0; i < x.size(); i ++) {
        dataStr = QString("data:,%1,%2").arg(x.at(i)).arg(y.at(i));
        result.append(dataStr);
    }
    QString curveName = QString("%1%2").arg(setting->getSampleName()).arg(id+1);
    emit toDrawCurve(curveName, x, y);
    emit toSaveResult(fileName, result);
    emit toSaveRecord(record);
}

/**
 * @brief UVDetectionFlow::excuteMicroscaleBlank
 * @param setting
 * @param opticalStr
 * @return
 */
QString UVDetectionFlow::excuteMicroscaleBlank(UVSettingModel *setting, QString opticalStr) {

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
        qDebug() << "Channel order:" << toHexStr(txBuffer);
        QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
        qDebug() << "Channel order:" << toHexStr(rxBuffer);
        if (ok != "Success") {
            return ok;
        }
    }

    m_msBlankMapper.insert(opticalStr, channelBlankList);
    return "Success";
}

/**
 * @brief UVDetectionFlow::excuteMicroscaleMeasure
 * @param setting
 * @param opticalStr
 * @param excuteId
 * @param result
 * @param showResult
 * @return
 */
QString UVDetectionFlow::excuteMicroscaleMeasure(UVSettingModel *setting, QString opticalStr,
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
        qDebug() << "Optical order:" << toHexStr(txBuffer);
        QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
        qDebug() << "Optical order:" << toHexStr(rxBuffer);
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
            (this->*showResult)(setting, r, i, opticalStr);
        }
    }

    if (m_pSerialPort != NULL &&
            setting->getMaxChannelNumber() > 1) {
        QByteArray rxBuffer;
        QByteArray txBuffer = USUnit::startStepMotor(MOTOR_02, 0);
        qDebug() << "Channel order:" << toHexStr(txBuffer);
        QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
        qDebug() << "Channel order:" << toHexStr(rxBuffer);
        if (ok != "Success") {
            return ok;
        }
    }

    return "Success";
}

