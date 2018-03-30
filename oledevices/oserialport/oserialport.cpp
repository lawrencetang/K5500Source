#include "oserialport.h"

#include <QDir>
#include <QSettings>
#include <QSerialPort>
#include <QElapsedTimer>
#include <QSerialPortInfo>
#include <QCoreApplication>
#include "usunit.h"

OSerialPort::OSerialPort(QObject *parent) : QObject(parent) {
    initializeSystem();
}

OSerialPort::~OSerialPort() {

}

/**
 * @brief OSerialPort::openSerialPort
 * @param portName
 * @return
 */
QString OSerialPort::openSerialPort(QString portName) {

    if (NULL == m_pSerialPort) {
        return tr( "SerialPort missing!" );
    }

    if (m_pSerialPort->isOpen()) {
        m_pSerialPort->close();
    }

    m_pSerialPort->setPortName( portName );
    m_pSerialPort->setBaudRate( m_boundRate );
    m_pSerialPort->setDataBits( QSerialPort::Data8 );
    m_pSerialPort->setParity( QSerialPort::NoParity );
    m_pSerialPort->setStopBits( QSerialPort::OneStop );
    m_pSerialPort->setFlowControl( QSerialPort::NoFlowControl );
    if (!m_pSerialPort->open( QIODevice::ReadWrite )) {
        return tr( "Open serialport failed!" );
    }
    return "Success";
}

/**
 * @brief OSerialPort::closeSerialPort
 * @return
 */
QString OSerialPort::closeSerialPort() {

    if (NULL != m_pSerialPort) {
        return tr( "SerialPort missing!" );
    }
    m_nestCount = -1000;
    if (m_pSerialPort->isOpen()) {
        m_pSerialPort->close();
    }
    return "Success";
}

/**
 * @brief OSerialPort::writeSerialPort
 * @param txBuffer
 * @param rxBuffer
 * @param timeout
 * @return
 */
QString OSerialPort::writeSerialPort(QByteArray txBuffer, QByteArray &rxBuffer, int timeout) {

    if (NULL != m_pSerialPort &&
            !m_pSerialPort->isOpen()) {
        return tr( "SerialPort is closed!" );
    }

    if (txBuffer.isEmpty()) {
        return tr( "Send buffer is empty!" );
    }

    CommandFrame txCommand;
    m_pSerialPort->write(txBuffer);
    memcpy(&txCommand, txBuffer.data(), sizeof( CommandFrame ));

    QElapsedTimer t;
    t.start();
    m_nestCount ++;
    while(t.elapsed() < timeout) {
        // 处理其他事件
        QCoreApplication::processEvents();
        if (0 >= m_nestCount) {
            m_nestCount = 0;
            return tr( "Force quit!" );
        }

        if (!m_rxBufferList.isEmpty()) {
            CommandFrame rxCommand;
            foreach(QByteArray buffer, m_rxBufferList) {
                memcpy(&rxCommand, buffer.data(), sizeof( CommandFrame ));
                if (rxCommand.frameFlag != RESPOND ||
                        txCommand.orderNum != rxCommand.orderNum) {
                    continue;
                }

                rxBuffer = buffer;
                m_mutex.lock();
                m_rxBufferList.removeAt(m_rxBufferList.indexOf(buffer));
                m_mutex.unlock();
                m_nestCount --;
                if (0x00 != rxCommand.status) {
                    return tr( "Error Code:%1" ).arg((int)rxCommand.status);
                }
                return "Success";
            }
        }
    }
    m_nestCount --;
    return tr( "Response timeout!" );
}

/**
 * @brief OSerialPort::serialPortName
 * @return
 */
QString OSerialPort::serialPortName() {
    QString portName = "";
    QList<QSerialPortInfo> serialPortInfos = QSerialPortInfo::availablePorts();
    for (int i = 0; i < serialPortInfos.size(); i ++) {
        QSerialPortInfo serialPortInfo = serialPortInfos.at( i );
        if (serialPortInfo.description().contains( m_description ) ) {
            portName = serialPortInfo.portName();
            break;
        }
    }
    return portName;
}

/**
 * @brief OSerialPort::receive
 */
void OSerialPort::receive() {
    if (NULL == m_pSerialPort) {
        return;
    }
    if (!m_pSerialPort->isOpen()) {
        return;
    }
    int size = m_pSerialPort->bytesAvailable();
    if (size > 0) {
        m_rxBuffer.append(m_pSerialPort->read(size));
        m_mutex.lock();
        m_rxBufferList.append(USUnit::decodingDataFrame(m_rxBuffer));
        m_mutex.unlock();
    }
}

/**
 * @brief OSerialPort::initializeSystem
 */
void OSerialPort::initializeSystem() {

    m_nestCount = 0;
    m_rxBuffer.clear();
    m_rxBufferList.clear();

    QString fileName = QDir::currentPath() + "/configs/system.ini";
    QSettings *configIniReader = new QSettings( fileName, QSettings::IniFormat );
    m_description = configIniReader->value( "/SerialPort/Description" ).toString();
    m_boundRate = configIniReader->value( "/SerialPort/BaudRate" ).toInt();
    delete configIniReader;
    configIniReader = NULL;

    m_pSerialPort = new QSerialPort(this);
    connect(m_pSerialPort, &QSerialPort::readyRead, this, &OSerialPort::receive);
}

