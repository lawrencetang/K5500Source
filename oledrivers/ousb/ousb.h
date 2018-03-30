#ifndef OUSB_H
#define OUSB_H

#include <QObject>
#include "lusb0_usb.h"

/*
 * PC发送、USB设备接收时的端口
 */
#define EP_OUT_1 0x01
#define EP_OUT_2 0x02
#define EP_OUT_3 0x03
#define EP_OUT_4 0x04
#define EP_OUT_5 0x05
#define EP_OUT_6 0x06
#define EP_OUT_7 0x07
#define EP_OUT_8 0x08

/*
 * USB设备发送，PC接收时的端口
 */
#define EP_IN_1 0x81
#define EP_IN_2 0x82
#define EP_IN_3 0x83
#define EP_IN_4 0x84
#define EP_IN_5 0x85
#define EP_IN_6 0x86
#define EP_IN_7 0x87
#define EP_IN_8 0x88

class OUsb : public QObject
{
    Q_OBJECT
public:
    explicit OUsb(QObject *parent = 0);
    ~OUsb();

public:
    void setTimeout(int timeout);

public slots:
    bool openUsb(int vId, int pId);
    void closeUsb();
    bool writeUsb(int ep, char *content, int len);
    QByteArray readUsb(int ep, int recvLen);
    QByteArray writeReadUsb(int wEp, char *wChar, int len, int rEp, int recvLen);
    void listUsb();

private:
    //struct usb_device *findUsb(int vId, int pId);
    void printDeviceInfo(struct usb_device *dev, usb_dev_handle *udev);
    void printDeviceDescriptor(struct usb_device_descriptor *desc);
    void printConfigDescriptor(struct usb_config_descriptor *config);
    int transfer_bulk_async(usb_dev_handle *dev, int ep, char *bytes, int size, int timeout);

private:
    usb_dev_handle *m_pUsbHandle;
    struct usb_device *m_pUsbDevice;
    int m_nTimeout;
};

#endif // OUSB_H
