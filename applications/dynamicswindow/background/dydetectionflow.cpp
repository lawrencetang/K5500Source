#include "dydetectionflow.h"

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
#include "dysettingmodel.h"
#include "opticalintensity.h"

#define TIMEOUT 3000

DYDetectionFlow::DYDetectionFlow(OSerialPort *serialPort, OSpectrograph *spectrograph, QObject *parent) :
    QObject(parent) {

    m_pSerialPort = serialPort;
    m_pSpectrograph = spectrograph;

    QString fileName = QDir::currentPath() + "/configs/dynamics/dynamics.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);

    m_ctWidth = configIniReader->value("CuvetteProcess/SmoothWidth").toInt();
    m_ctFactor = configIniReader->value("CuvetteProcess/CorrectionFactor").toInt();

    delete configIniReader;
    configIniReader = NULL;
}

DYDetectionFlow::~DYDetectionFlow() {

}

/**
 * @brief DYDetectionFlow::blank
 * @param setting
 * @return
 */
QString DYDetectionFlow::blank(DYSettingModel *setting) {

    m_ctBlankList.clear();
    QString ok = tr( "Unknown detection method." );
    if (setting->getDetectionMethod() == "Cuvette") {

        // Cuvette空白
        int rc = setting->getCuvetteFrequency();
        int it = setting->getCuvetteIntegrationTime();
        OpticalIntensity intensity = m_pSpectrograph->readSpectrograph(it, rc);
        m_ctBlankList.append(intensity);
        ok = "Success";
    }
    return ok;
}

/**
 * @brief DYDetectionFlow::measure
 * @param setting
 * @return
 */
QString DYDetectionFlow::measure(DYSettingModel *setting) {

    QString ok = tr( "Unknown detection method." );
    if (setting->getDetectionMethod() == "Cuvette") {

        // Cuvette检测
        if (m_ctBlankList.isEmpty()) {
            return tr( "Missing blank data!" );
        }

        int eCount = 0;
        Absorbance *r = NULL;
        QStringList data;
        int count = setting->getIncubationCount();
        double target = setting->getTargetValue();

        QElapsedTimer elapsedTimer;
        elapsedTimer.start();
        for (int i = 0; i < count; i ++) {

            eCount = i + 1;
            if(r != NULL) {
                delete r;
                r = NULL;
            }

            if (i != 0) {
                // 搅拌电机控制
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

                qDebug() << setting->getMixingTime();
                delay(setting->getMixingTime()*1000);
                if (m_pSerialPort != NULL) {
                    QByteArray rxBuffer;
                    QByteArray txBuffer = USUnit::stopDcMotor(MIXING_MOTOR_01);
                    qDebug() << "Stop mixing:" << toHexStr(txBuffer);
                    ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
                    qDebug() << "Stop mixing:" << toHexStr(rxBuffer);
                    if (ok != "Success") {
                        return ok;
                    }
                }
                qDebug() << setting->getStaticTime();
                delay(setting->getStaticTime()*1000);
            }

            // 采集数据
            if(r == NULL) {
                int bwl = setting->getBwl();
                int rc = setting->getCuvetteFrequency();
                int it = setting->getCuvetteIntegrationTime();
                OpticalIntensity mi = m_pSpectrograph->readSpectrograph(it, rc);
                OpticalIntensity bi = m_ctBlankList.first();
                r = OpticalIntensity::toAbsorbance(mi, bi, setting->getOptical().toDouble(), m_ctWidth, bwl);
                r->setCorrectionFactor(m_ctFactor*setting->getCuvetteCorrectionFactor());
            }

            // 计算结果
            double t = (double)elapsedTimer.elapsed()/1000;
            double abso0 = r->getAbsoByWL((double)setting->getMwl());
            double abso1 = r->getAbsoByWL((double)setting->getSwl1());
            double abso2 = r->getAbsoByWL((double)setting->getSwl2());
            double abso3 = r->getAbsoByWL((double)setting->getSwl3());
            double abso4 = r->getAbsoByWL((double)setting->getSwl4());
            QVector<double> a;
            a << abso0 << abso1 << abso2 << abso3 << abso4;
            emit toDrawCurve(t, a);
            QString aStr = QString::number(t) + ",";
            foreach(double v, a) {
                aStr.append(QString::number(v) + ",");
            }
            data.append(aStr);
            if (abso0 > target) {
                break;
            }
        }

        showResult(setting, r, eCount, data);
        if(r != NULL) {
            delete r;
            r = NULL;
        }
        ok = "Success";
    }
    return ok;
}

/**
 * @brief DYDetectionFlow::transformUnit
 * @param unit
 * @return
 */
double DYDetectionFlow::transformUnit(QString unit) {
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
void DYDetectionFlow::delay(int timeout) {

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
 * @brief DYDetectionFlow::showResult
 * @param a
 */
void DYDetectionFlow::showResult(DYSettingModel *setting, Absorbance *a, int count, QStringList data) {

    QString fileName = QDateTime::currentDateTime().toString("yyyyMMddhhmmss") + ".csv";
    // 计算浓度,A230,A260,A280,标准单位为mg/mL
    double abso = a->getAbsoByWL((double)setting->getMwl());
    double abso1 = a->getAbsoByWL((double)setting->getSwl1());
    double abso2 = a->getAbsoByWL((double)setting->getSwl2());
    double abso3 = a->getAbsoByWL((double)setting->getSwl3());
    double abso4 = a->getAbsoByWL((double)setting->getSwl4());

    QStringList record;
    record << "result:" << setting->getSampleName() << QString::number(setting->getMwl()) << QString::number(abso)
           << QString::number(setting->getSwl1()) << QString::number(abso1)
           << QString::number(setting->getSwl2()) << QString::number(abso2)
           << QString::number(setting->getSwl3()) << QString::number(abso3)
           << QString::number(setting->getSwl4()) << QString::number(abso4)
           << setting->getOptical() << QString::number(setting->getTargetValue()) << QString::number(count)
           << QString::number(setting->getIncubationCount()) << fileName;

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

    QString dataStr;
    for(int i = 0; i < data.size(); i ++) {
        dataStr = QString("data:,%1").arg(data.at(i));
        result.append(dataStr);
    }
    emit toSaveResult(fileName, result);
    emit toSaveRecord(record);
}


