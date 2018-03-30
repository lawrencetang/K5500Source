#include "protocol.h"


QString toHexStr(QByteArray byteArray) {
    QString hexStr;
    for (int i = 0; i < byteArray.size(); i ++) {
        hexStr.append(toHex((uint8)byteArray.at(i)));
        if (i < byteArray.size() - 1) {
            hexStr.append(" ");
        }
    }
    return hexStr;
}


QString toHex(uint8 byte) {
    QString hex;
    if (byte < 0x10) {
        hex.append( "0" );
    }
    hex.append( QString::number( byte, 16 ).toUpper() );
    return hex;
}
