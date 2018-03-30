#ifndef OSPECTROGRAPHDEVICE_H
#define OSPECTROGRAPHDEVICE_H

#include <QObject>
#include <QVector>

#define SPECTROMETER_VID    0x2457
#define SPECTROMETER_PID    0x101E

#define SERIAL_NUMBER   0
#define WL_INTERCEPT    1   // 标定波长0阶参数 = 标定波长0阶参数原始值 + 溶液标定参数
#define WL_FIRST        2
#define WL_SECOND       3
#define WL_THIRD        4
#define STRAY_LIGHT     5   // 溶液标定参数
#define NL_0            6
#define NL_1            7
#define NL_2            8
#define NL_3            9
#define NL_4            10
#define NL_5            11
#define NL_6            12
#define NL_7            13
#define NL_ORDER        14
#define BENCH_CONF      15
#define USB2000_CONF    16
#define SLOT_17         17  // 预留，光谱饱和度参数
#define SLOT_18         18  // 预留，光谱基线参数
#define SLOT_19         19  // 预留，标定波长0阶参数原始值

#define EEPROM_SLOT_SIZE        15
#define EEPROM_COMMAND_SIZE     17

class OUsb;
class OSpectrographDevice : public QObject
{
    Q_OBJECT
public:
    explicit OSpectrographDevice(QObject *parent = 0);

    bool openSpectrometer();
    void closeSpectrometer();
    void setTimeout(int timeout);
    QString getSerialNumber();
    void setIntegrationTime(int usec);
    int getIntegrationTime();
    int getSaturationLevel();
    void setStrobeEnable(bool lampOn);
    QString getEEPromInfo(int slot);
    bool setEEPromInfo(int slot, QString info);
    QVector<double> getWavelengths();
    QVector<double> getSpectrum(int times = 1);
    bool isValidSpectrum(QVector<double> spectrum, double avgMinValue = 200.0);

    QString heart();
    void reconnect();

private:
    QByteArray getEEPromInfoPriv(int slot);

private:
    OUsb *m_pUsb;

    int m_nIntegrationTime;
    int m_nSaturationLevel;
    QVector<double> m_vWlCalibCoef;
    QVector<double> m_vWavelength;
};

#endif // OSPECTROMETER_H
