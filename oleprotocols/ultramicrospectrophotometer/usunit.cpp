#include "usunit.h"

USUnit::USUnit(QObject *parent)
    : QObject(parent) {

}

QList<QByteArray> USUnit::decodingDataFrame(QByteArray &buffer) {
    QByteArray data;
    int endPos = 0;
    char bccValue = 0x00;
    QList<QByteArray> frameBufferList;
    for (int i = 0; i < buffer.size(); i++) {
        unsigned char byte = (unsigned char)buffer.at(i);
        int dataSize = data.size();
        if (0 == dataSize) {
            if (byte == 0xFF) {
                data.append( byte );
            }
        } else if (1 == dataSize) {
            if (byte != 0xFF) {
                data.append(0xFF);
                bccValue ^= byte;
            }
            data.append(byte);
        } else if (2 == dataSize) {
            if (byte != 0xFF) {
                bccValue ^= byte;
                data.append(byte);
            }
        } else {
            bccValue ^= byte;
            data.append(byte);
            if (data.size() == sizeof( CommandFrame )) {
                if (0x00 == bccValue) {
                    frameBufferList.append( data );
                }

                data.clear();
                endPos = i;
                bccValue = 0x00;
            }
        }
    }
    if (endPos != 0) {
        buffer.remove( 0, endPos+1 );
    }
    return frameBufferList;
}

int USUnit::decodingAngle(QByteArray buffer) {
    CommandFrame rxCommand;
    memcpy(&rxCommand, buffer.data(), sizeof(CommandFrame));
    if (0x01 == rxCommand.dataFlag) {
        int angle = (double)((rxCommand.data[0] << 24) +
                (rxCommand.data[1] << 16) + (rxCommand.data[2] << 8) + rxCommand.data[3]);
        return angle;
    }
    return -1;
}

int USUnit::decodingTemperature(QByteArray buffer) {
    CommandFrame rxCommand;
    memcpy(&rxCommand, buffer.data(), sizeof(CommandFrame));
    if (0x01 == rxCommand.dataFlag) {
        int temperature = (double)((rxCommand.data[0] << 24) +
                (rxCommand.data[1] << 16) + (rxCommand.data[2] << 8) + rxCommand.data[3]);
        return temperature;
    }
    return -1;
}

QString USUnit::decodingSerialNumber(QByteArray buffer) {
    CommandFrame rxCommand;
    memcpy(&rxCommand, buffer.data(), sizeof(CommandFrame));
    QString serialNumber;
    if (0x01 == rxCommand.dataFlag) {
        serialNumber.append( toHex(rxCommand.data[0]) );
        serialNumber.append( toHex(rxCommand.data[1]) );
        serialNumber.append( toHex(rxCommand.data[2]) );
        serialNumber.append( toHex(rxCommand.data[3]) );
    }
    return serialNumber;
}

QByteArray USUnit::checkMainboard(int deviceNumber) {

    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0X70 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::checkStepMotor(int deviceNumber) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0X80 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::startStepMotor(int deviceNumber, int targetAngle) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0X81 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x01 );

    buffer.append( (char)(targetAngle >> 24 & 0xFF) );
    buffer.append( (char)(targetAngle >> 16 & 0xFF));
    buffer.append( (char)(targetAngle >> 8 & 0xFF) );
    buffer.append( (char)(targetAngle & 0xFF) );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::stopStepMotor(int deviceNumber) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0X82 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::getAngle(int deviceNumber) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0X83 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::setAngle(int deviceNumber, int targetAngle) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0X84 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x01 );

    buffer.append( (char)(targetAngle >> 24 & 0xFF) );
    buffer.append( (char)(targetAngle >> 16 & 0xFF));
    buffer.append( (char)(targetAngle >> 8 & 0xFF) );
    buffer.append( (char)(targetAngle & 0xFF) );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::checkDcMotor(int deviceNumber) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0X90 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::startDcMotor(int deviceNumber, int mixingLevel) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0X91 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x01 );

    buffer.append( (char)(mixingLevel >> 24 & 0xFF) );
    buffer.append( (char)(mixingLevel >> 16 & 0xFF));
    buffer.append( (char)(mixingLevel >> 8 & 0xFF) );
    buffer.append( (char)(mixingLevel & 0xFF) );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::stopDcMotor(int deviceNumber) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0X92 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::checkThermostat(int deviceNumber) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0XA0 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::startThermostat(int deviceNumber, int targetTemperature) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0XA1 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x01 );

    buffer.append( (char)(targetTemperature >> 24 & 0xFF) );
    buffer.append( (char)(targetTemperature >> 16 & 0xFF));
    buffer.append( (char)(targetTemperature >> 8 & 0xFF) );
    buffer.append( (char)(targetTemperature & 0xFF) );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::stopThermostat(int deviceNumber) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0XA2 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

QByteArray USUnit::getTemperature(int deviceNumber) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0XA3 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

/**
 * @brief USUnit::getControllerSn
 * @param deviceNumber
 * @return
 */
QByteArray USUnit::getControllerSn(int deviceNumber) {
    QByteArray buffer;
    buffer.append( 0xC0 );
    buffer.append( (char)ORDER_0X75 );
    buffer.append( (char)deviceNumber );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );
    buffer.append( (char)0x00 );

    char bccValue = 0x00;
    for (int i = 0; i < buffer.size(); i ++) {
        bccValue ^= buffer.at( i );
    }

    buffer.append( bccValue );
    buffer.insert( 0, 0xFF );
    buffer.insert( 0, 0xFF );
    return buffer;
}

