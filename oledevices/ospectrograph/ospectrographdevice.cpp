#include "ospectrographdevice.h"
#include "ousb.h"
#include <QtDebug>
#include "protocol.h"

OSpectrographDevice::OSpectrographDevice(QObject *parent) :
    QObject(parent) {

    m_nIntegrationTime = 0;
    m_nSaturationLevel = 0xFFFF;
    m_vWlCalibCoef.clear();
    m_vWavelength.clear();
    // 设置parent，不用额外delete
    m_pUsb = new OUsb(this);
}

/**
 * @brief OSpectrographDevice::openSpectrometer：打开光谱仪设备
 *          1、打开USB设备
 *          2、初始化频谱仪
 *          3、读取相关参数：波长标定参数、波长值(2048个)、饱和度值
 * @return
 */
bool OSpectrographDevice::openSpectrometer() {

    m_vWlCalibCoef.clear();
    m_vWavelength.clear();
    if (!m_pUsb->openUsb(SPECTROMETER_VID, SPECTROMETER_PID)) {
        return false;
    }

    // 初始化频谱仪
    char reset[1];
    reset[0] = 0x01;
    if (!m_pUsb->writeUsb(EP_OUT_1, reset, 1)) {
        m_pUsb->closeUsb();
        return false;
    }

    // 读取相关参数
    for (int i = WL_INTERCEPT; i <= WL_THIRD; i++) {
        m_vWlCalibCoef.append(getEEPromInfo(i).toDouble());
    }
    for (int i = 0; i < 2048; i++) {
        m_vWavelength.append(m_vWlCalibCoef.at(0) + m_vWlCalibCoef.at(1) * i +
                             m_vWlCalibCoef.at(2) * i * i + m_vWlCalibCoef.at(3) * i * i * i);
    }
    QByteArray slot17Array = getEEPromInfoPriv(SLOT_17);
    if (slot17Array.size() == EEPROM_SLOT_SIZE) {
        m_nSaturationLevel = (BYTE)slot17Array.at(4) + ((BYTE)slot17Array.at(5) << 8);
        m_nSaturationLevel = (m_nSaturationLevel == 0) ? 0xFFFF : m_nSaturationLevel;
    }

    return true;
}

/**
 * @brief OSpectrographDevice::closeSpectrometer：关闭光谱仪
 */
void OSpectrographDevice::closeSpectrometer() {
    return m_pUsb->closeUsb();
}

/**
 * @brief OSpectrographDevice::setTimeout：设置通讯超时时间
 * @param timeout
 */
void OSpectrographDevice::setTimeout(int timeout) {
    m_pUsb->setTimeout(timeout);
}

/**
 * @brief OSpectrographDevice::getSerialNumber：获取光谱仪序列号
 * @return
 */
QString OSpectrographDevice::getSerialNumber() {
    char write[2];
    write[0] = 0x05;
    write[1] = 0x00;
    QByteArray readArray = m_pUsb->writeReadUsb(EP_OUT_1, write, 2, EP_IN_1, EEPROM_COMMAND_SIZE);
    if (readArray.size() >= 2 && readArray.at(0) == write[0] && readArray.at(1) == write[1]) {
        return QString(readArray.mid(2));
    } else {
        return "";
    }
}

/**
 * @brief OSpectrographDevice::setIntegrationTime：设置积分时间
 * @param usec
 */
void OSpectrographDevice::setIntegrationTime(int usec) {
    // 积分时间范围：[10us, 6553500us]
    m_nIntegrationTime = usec < 10 ? 10 : usec;
    m_nIntegrationTime = m_nIntegrationTime < 6553500 ? m_nIntegrationTime : 6553500;
    char write[5];
    write[0] = 0x02;
    write[1] = m_nIntegrationTime;
    write[2] = m_nIntegrationTime >> 8;
    write[3] = m_nIntegrationTime >> 16;
    write[4] = m_nIntegrationTime >> 24;
    m_pUsb->writeUsb(EP_OUT_1, write, 5);
}

/**
 * @brief OSpectrographDevice::getIntegrationTime：获取积分时间
 * @return
 */
int OSpectrographDevice::getIntegrationTime() {
    return m_nIntegrationTime;
}

/**
 * @brief OSpectrographDevice::getSaturationLevel：获取饱和度值
 * @return
 */
int OSpectrographDevice::getSaturationLevel() {
    return m_nSaturationLevel;
}

/**
 * @brief OSpectrographDevice::setStrobeEnable：开/关灯
 * @param lampOn
 */
void OSpectrographDevice::setStrobeEnable(bool lampOn) {
    char write[3];
    write[0] = 0x03;
    write[1] = lampOn ? 0x01 : 0x00;
    write[2] = 0x00;
    m_pUsb->writeUsb(EP_OUT_1, write, 3);
}

/**
 * @brief OSpectrographDevice::getEEPromInfo：读取EEPROM信息
 * @param slot
 * @return QString：QByteArray中第1个'\0'以前的内容
 */
QString OSpectrographDevice::getEEPromInfo(int slot) {
    QByteArray readArray = getEEPromInfoPriv(slot);
    return readArray.isEmpty() ? "" : QString(readArray);
}

/**
 * @brief OSpectrographDevice::getEEPromInfoPriv：读取EEPROM信息，私有函数
 * @param slot
 * @return QByteArray：所有数据，包括'\0'信息，长度固定为EEPROM_COMMAND_SIZE
 */
QByteArray OSpectrographDevice::getEEPromInfoPriv(int slot) {

    char write[2];
    write[0] = 0x05;
    write[1] = slot;
    QByteArray readArray = m_pUsb->writeReadUsb(EP_OUT_1, write, 2, EP_IN_1, EEPROM_COMMAND_SIZE);
    if (readArray.size() == EEPROM_COMMAND_SIZE && readArray.at(0) == write[0] && readArray.at(1) == write[1]) {
        return readArray.mid(2);
    } else {
        return QByteArray();
    }
}

/**
 * @brief OSpectrographDevice::setEEPromInfo：写入EEPROM信息，最多写入EEPROM_SLOT_SIZE(15)字节
 * @param slot
 * @param info
 * @return
 */
bool OSpectrographDevice::setEEPromInfo(int slot, QString info) {

    char write[EEPROM_COMMAND_SIZE];
    memset(write, 0, EEPROM_COMMAND_SIZE);
    write[0] = 0x06;
    write[1] = slot;
    int infoLen = (info.size() <= EEPROM_SLOT_SIZE) ? info.size() : EEPROM_SLOT_SIZE;
    for (int i = 0; i < infoLen; i++) {
        write[i + 2] = info.at(i).toLatin1();
    }
    return m_pUsb->writeUsb(EP_OUT_1, write, EEPROM_COMMAND_SIZE);
}

/**
 * @brief OSpectrographDevice::getWavelengths：获取波长数据
 * @return
 */
QVector<double> OSpectrographDevice::getWavelengths() {
    return m_vWavelength;
}

/**
 * @brief OSpectrographDevice::getSpectrum：读取光谱数据
 * @param times：读取光谱数据的次数，由于开灯后第1次读取的光谱数据不准确，传出的数据为最后一次读取的光谱数据
 * @return
 */
QVector<double> OSpectrographDevice::getSpectrum(int times) {

    QVector<double> spectrumList;
    QByteArray spectrumArray;
    QByteArray synchArray;
    char write[1];
    write[0] = 0x09;
    for (int i = 0; i < times; i++) {
        spectrumArray = m_pUsb->writeReadUsb(EP_OUT_1, write, 1, EP_IN_2, 4096);
        if (spectrumArray.size() != 4096) {
            return spectrumList;
        }
        synchArray = m_pUsb->readUsb(EP_IN_2, 1);
        if (synchArray.size() != 1 || synchArray.at(0) != 0x69) {
            return spectrumList;
        }
    }
    for (int i = 0; i < 4096; i += 2) {
        int value = (BYTE)spectrumArray.at(i) + ((BYTE)spectrumArray.at(i + 1) << 8);
        double spectrumValue = 65535.0 * value / m_nSaturationLevel;
        spectrumList.append(spectrumValue);
    }

    spectrumList.replace(0, spectrumList.at(2));
    spectrumList.replace(1, spectrumList.at(2));

    return spectrumList;
}

/**
 * @brief OSpectrographDevice::isValidSpectrum
 * @param spectrum
 * @return
 */
bool OSpectrographDevice::isValidSpectrum(QVector<double> spectrum, double avgMinValue) {

    if (spectrum.size() != 2048) {
        return false;
    }
    int totalValue = 0;
    for (int i = 0; i < spectrum.size(); i++) {
        totalValue += spectrum.at(i);
    }
    totalValue /= 2048;
    return (totalValue >= avgMinValue);
}

/**
 * @brief OSpectrographDevice::heart：获取心跳
 * @return
 */
QString OSpectrographDevice::heart() {
    return getSerialNumber();
}

/**
 * @brief OSpectrographDevice::reconnect：重连
 */
void OSpectrographDevice::reconnect() {
    openSpectrometer();
}

