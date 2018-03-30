#ifndef USUNIT_H
#define USUNIT_H

#include <QObject>
#include "protocol.h"

#define MOTOR_01        0x01     // 光程的电机编号
#define MOTOR_02        0x02     // 通道的电机编号
#define MIXING_MOTOR_01 0x01     // 搅拌电机编号
#define THERMOSTAT      0x01

#define ORDER_0X70  0x70   // 主板状态查寻
#define ORDER_0X75  0x75   // 读芯片序列号
#define ORDER_0X80  0x80   // 获取步进电机状态
#define ORDER_0X81  0x81   // 启动步进电机
#define ORDER_0X82  0x82   // 停止步进电机
#define ORDER_0X83  0x83   // 读取步进电机角度
#define ORDER_0X84  0x84   // 设置步进电机角度
#define ORDER_0X90  0x90   // 获取电机状态
#define ORDER_0X91  0x91   // 启动直流电机
#define ORDER_0X92  0x92   // 停止直流电机
#define ORDER_0XA0  0xA0   // 获取温控状态
#define ORDER_0XA1  0xA1   // 启动温控系统
#define ORDER_0XA2  0xA2   // 停止温控系统
#define ORDER_0XA3  0xA3   // 读取当前温度
#define ORDER_0X04  0x04   // 器皿闭合指令

class USUnit : public QObject
{
    Q_OBJECT
public:
    explicit USUnit(QObject *parent = 0);

    static QList<QByteArray> decodingDataFrame(QByteArray &buffer);
    static int decodingAngle(QByteArray buffer);
    static int decodingTemperature(QByteArray buffer);
    static QString decodingSerialNumber(QByteArray buffer);

    // 指令接口
    static QByteArray checkMainboard(int deviceNumber);

    static QByteArray checkStepMotor(int deviceNumber);
    static QByteArray startStepMotor(int deviceNumber, int targetAngle);
    static QByteArray stopStepMotor(int deviceNumber);
    static QByteArray getAngle(int deviceNumber);
    static QByteArray setAngle(int deviceNumber, int targetAngle);

    static QByteArray checkDcMotor(int deviceNumber);
    static QByteArray startDcMotor(int deviceNumber, int mixingLevel);
    static QByteArray stopDcMotor(int deviceNumber);

    static QByteArray checkThermostat(int deviceNumber);
    static QByteArray startThermostat(int deviceNumber, int targetTemperature);
    static QByteArray stopThermostat(int deviceNumber);
    static QByteArray getTemperature(int deviceNumber);

    static QByteArray getControllerSn(int deviceNumber);

};

#endif // ULTRAMICROSPECTROPHOTOMETERUNIT_H
