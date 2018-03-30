#include "ospectrograph.h"

#include "opticalintensity.h"
#include "ospectrographdevice.h"


#include <QDir>
#include <QDebug>
#include <QSettings>
#include <QApplication>
#include <QElapsedTimer>


OSpectrograph::OSpectrograph(QObject *parent) : QObject(parent) {

    m_isOpened = false;
    m_pSpectrographDevice = new OSpectrographDevice(this);

    QString fileName = QDir::currentPath() + "/configs/system.ini";
    QSettings *configIniReader = new QSettings( fileName, QSettings::IniFormat );
    m_threshold = configIniReader->value("Spectrograph/Threshold").toDouble();
    delete configIniReader;
    configIniReader = NULL;
}

OSpectrograph::~OSpectrograph() {
}

/**
 * @brief OSpectrograph::openSpectrograph
 * @param count
 * @return
 */
QString OSpectrograph::openSpectrograph() {

    m_isOpened = m_pSpectrographDevice->openSpectrometer();
    return m_isOpened ? "Success" : "Not Found Spectrograph!";
}

/**
 * @brief OSpectrograph::closeSpectrograph
 */
void OSpectrograph::closeSpectrograph() {

    if (m_isOpened) {
        m_isOpened = false;
        m_pSpectrographDevice->closeSpectrometer();
    }
}

/**
 * @brief OSpectrograph::readSpectrograph
 * @param iData
 * @param iTime
 * @param rCount
 * @param timeout
 * @return
 */
OpticalIntensity OSpectrograph::readSpectrograph(int iTime, int rCount, int timeout) {

    QVector<double> r_iAvg, r_wAvg;
    if (!m_isOpened) {
        return OpticalIntensity(r_wAvg, r_iAvg);
    }

    QVector<double> t_i, t_w, r_i, r_w;
    int times = 2, count = rCount/times;
    for (int i = 0; i < times; i ++) {

        r_i.clear();
        r_w.clear();

        // 设置超时时间\积分时间\开灯
        m_pSpectrographDevice->setTimeout(timeout);
        m_pSpectrographDevice->setIntegrationTime(iTime);
        m_pSpectrographDevice->setStrobeEnable(true);

        int c = 0, s = 2, p = 10;
        for (int j = 0; j < count+s+p; j ++) {
            QCoreApplication::processEvents();
            // 获取波长\光强
            t_w = m_pSpectrographDevice->getWavelengths();
            t_i = m_pSpectrographDevice->getSpectrum();

            bool ok = m_pSpectrographDevice->isValidSpectrum(t_i, m_threshold);
            if (j < s || !ok) {
                continue;
            }

            if (r_w.isEmpty()) {
                r_w<<(t_w);
                r_i<<(t_i);
            } else {
                double yValue;
                for (int m = 0; m < t_i.size(); m ++) {
                    yValue = (r_i.at(m)*c + t_i.at(m)) / (c + 1);
                    r_i.replace(m, yValue);
                }
            }
            c ++;
        }
        // 关灯
        m_pSpectrographDevice->setStrobeEnable(false);

        if (r_wAvg.isEmpty()) {
            r_wAvg<<(r_w);
            r_iAvg<<(r_i);
        } else {
            double yValue;
            for (int m = 0; m < r_iAvg.size(); m ++) {
                yValue = (r_iAvg.at(m)*i + r_i.at(m)) / (i + 1);
                r_iAvg.replace(m, yValue);
            }
        }
    }

    QVector<double> t_iAvg, t_wAvg;
    transformWaveLength(r_wAvg, r_iAvg, t_iAvg, t_wAvg);
    return OpticalIntensity(t_iAvg, t_wAvg);
}

/**
 * @brief OSpectrograph::readSerialNumber
 * @param id
 * @return
 */
QString OSpectrograph::serialNumber() {
    QString serialNumber;
    if (m_isOpened) {
        serialNumber = m_pSpectrographDevice->getSerialNumber();
    }
    return serialNumber;
}

/**
 * @brief OSpectrograph::delay
 * @param timeout
 */
void OSpectrograph::delay(int timeout) {
    QElapsedTimer t;
    t.start();
    while(t.elapsed() < timeout) {
        if (!m_isOpened) {
            break;
        }
        QCoreApplication::processEvents();
    }
}

/**
 * @brief OSpectrograph::transformWaveLength
 * @param w
 * @param i
 * @param r_w
 * @param r_i
 */
void OSpectrograph::transformWaveLength(QVector<double> w, QVector<double> i,
                                        QVector<double> &r_w, QVector<double> &r_i) {
    int    key = 0;
    int    valueCount = 0;
    double valueTotal = 0;

    r_w.clear();
    r_i.clear();

    int size = w.size();
    for (int j = 0; j < size; ) {
        key = w.at( j );
        valueCount = 0;
        valueTotal = 0;
        while (j < size && (int)w.at( j ) == key) {
            valueTotal += i.at( j );
            valueCount ++;
            j ++;
        }
        r_w.append( key );
        r_i.append( valueTotal / valueCount );
    }
}

