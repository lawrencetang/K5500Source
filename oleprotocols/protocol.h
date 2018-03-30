#ifndef PROTOCOL
#define PROTOCOL

#include <QObject>

typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;
typedef int int32;

#define COMMAND    0xC0       // 命令
#define RESPOND    0xB0       // 回复

typedef struct _COMMAND_FRAME {
    uint8 header[2];          // 帧头
    uint8 frameFlag;          // 帧标识
    uint8 orderNum;           // 命令号
    uint8 deviceNum;          // 设备编号
    uint8 status;             // 操作状态
    uint8 dataFlag;           // 参数标志
    uint8 data[4];            // 帧数据
    uint8 bccValue;           // 校验位
} CommandFrame;

QString toHexStr(QByteArray byteArray);
QString toHex(uint8 byte);

#endif // PROTOCOL

