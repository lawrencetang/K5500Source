#include "ousb.h"
#include <QString>
#include <QtDebug>

OUsb::OUsb(QObject *parent) : QObject(parent)
{
    m_pUsbHandle = NULL;
    m_pUsbDevice = NULL;
    m_nTimeout = 1000;
}

OUsb::~OUsb()
{
    if (m_pUsbHandle) {
        usb_release_interface(m_pUsbHandle, 0);
        usb_close(m_pUsbHandle);
        m_pUsbHandle = NULL;
        m_pUsbDevice = NULL;
    }
}

bool OUsb::openUsb(int vId, int pId)
{
    // 如果已经打开，先关闭
    if (m_pUsbHandle) {
        closeUsb();
    }
    m_pUsbHandle = NULL;
    m_pUsbDevice = NULL;

    // 查找USB设备
    usb_init();         // 初始化动态库
    usb_find_busses();  // 查找所有总线
    usb_find_devices(); // 查找所有连接的设备
    struct usb_bus *bus;
    struct usb_device *dev;
    for (bus = usb_get_busses(); bus; bus = bus->next) {
        for (dev = bus->devices; dev; dev = dev->next) {
            if (dev->descriptor.idVendor == vId && dev->descriptor.idProduct == pId) {
                m_pUsbDevice = dev;
                break;
            }
        }
        if (m_pUsbDevice) {
            break;
        }
    }
    if (!m_pUsbDevice) {
        return false;
    }

    // 打开USB设备
    if (!(m_pUsbHandle = usb_open(m_pUsbDevice))) {
        m_pUsbDevice = NULL;
        return false;
    }

    // 根据配置描述符来设置一个使能的USB设备
    if (usb_set_configuration(m_pUsbHandle, 1) < 0) {
        usb_close(m_pUsbHandle);
        return false;
    }

    // 声明一个有操作系统相关的接口，接口的参数在描述符里的bInterfaceNumber字段里指定
    // 注意：在进行与该接口相关的操作之前，usb_claim_interface()必须被首先调用
    if (usb_claim_interface(m_pUsbHandle, 0) < 0) {
        usb_close(m_pUsbHandle);
        return false;
    }

    return true;
}

void OUsb::closeUsb()
{
    if (m_pUsbHandle) {
        // 释放先前usb_claim_interface()声明的接口
        usb_release_interface(m_pUsbHandle, 0);
        usb_close(m_pUsbHandle);
        m_pUsbHandle = NULL;
        m_pUsbDevice = NULL;
    }
}

/**
 * @brief OUsb::writeUsb
 *          和USB设备写入数据
 * @param ep：endpoint，EP_OUT_?
 * @param content：待写数据的内容
 * @param len：待写数据的长度
 * @return int：实际写入数据的长度
 */
bool OUsb::writeUsb(int ep, char *content, int len)
{
    if (!m_pUsbHandle) {
        return false;
    }

    return (len == usb_bulk_write(m_pUsbHandle, ep, content, len, m_nTimeout));
}

/**
 * @brief OUsb::readUsb
 *          从USB设备读取数据
 * @param ep：endpoint，EP_IN_?
 * @param recvLen：待读取数据的长度
 * @return QByteArray：读取的数据
 */
QByteArray OUsb::readUsb(int ep, int recvLen)
{
    if (!m_pUsbHandle) {
        return QByteArray();
    }

    char recvChar[recvLen];
    int intRet = usb_bulk_read(m_pUsbHandle, ep, recvChar, recvLen, m_nTimeout);
    if (intRet > 0) {
        return QByteArray(recvChar, intRet);
    } else {
        return QByteArray();
    }
}

/**
 * @brief OUsb::writeReadUsb
 *          向USB设备写入数据，并读取USB设备的回复
 * @param wEp：向USB设备写入数据的endpoint，EP_OUT_?
 * @param wChar：待写入的数据内容
 * @param len：待写入的数据长度
 * @param rEp：USB设备回复的endpoint，EP_IN_?
 * @param recvLen：待回复的数据长度
 * @return QByteArray：USB设备回复的数据
 */
QByteArray OUsb::writeReadUsb(int wEp, char *wChar, int len, int rEp, int recvLen)
{
    if (!m_pUsbHandle) {
        return QByteArray();
    }

    if (len != usb_bulk_write(m_pUsbHandle, wEp, wChar, len, m_nTimeout)) {
        //qDebug() << "writeReadUsb(): usb_bulk_write return len error";
        return QByteArray();
    }

    char recvChar[recvLen];
    int intRet = usb_bulk_read(m_pUsbHandle, rEp, recvChar, recvLen, m_nTimeout);
    if (intRet > 0) {
        return QByteArray(recvChar, intRet);
    } else {
        //qDebug() << "writeReadUsb(): usb_bulk_read return len < 0";
        return QByteArray();
    }
}

/**
 * @brief OUsb::setTimeout：设置USB通讯的超时时间
 * @param timeout
 */
void OUsb::setTimeout(int timeout)
{
    m_nTimeout = timeout;
}

/**
 * @brief OUsb::listUsb：列出USB设备的详细信息
 */
void OUsb::listUsb()
{
    if (m_pUsbDevice && m_pUsbHandle) {
        printDeviceInfo(m_pUsbDevice, m_pUsbHandle);
    }
}

/**
 * @brief ListUsb::transfer_bulk_async
 *          通过异步传输方式读/写USB
 * @param dev
 * @param ep
 * @param bytes
 * @param size
 * @param timeout
 * @return
 */
int OUsb::transfer_bulk_async(usb_dev_handle *dev, int ep, char *bytes, int size, int timeout)
{
    void* async_context = NULL;
    int ret;

    // 设置异步传输方式，对于多次提交传输，也只需要执行此函数一次
    ret = usb_bulk_setup_async(dev, &async_context, ep);
    if (ret < 0)
    {
        printf("error usb_bulk_setup_async:\n%s\n", usb_strerror());
        return ret;
    }

    // 提交传输，该函数立即返回
    ret = usb_submit_async(async_context, bytes, size);
    if (ret < 0)
    {
        printf("error usb_submit_async:\n%s\n", usb_strerror());
        usb_free_async(&async_context);
        return ret;
    }

    // 等待传输完成
    ret = usb_reap_async(async_context, timeout);

    // Free the context.
    usb_free_async(&async_context);
    return ret;
}

void OUsb::printDeviceInfo(struct usb_device *dev, usb_dev_handle *udev)
{
    if (!dev || !udev) {
        return;
    }

    QString descStr;
    char str[256];
    int ret;

    if (dev->descriptor.iManufacturer) {
        ret = usb_get_string_simple(udev, dev->descriptor.iManufacturer, str, sizeof(str));
        if (ret > 0) {
            descStr = QString(str).append(" - ");
        } else {
            descStr = QString("%1 - ").arg(dev->descriptor.idVendor, 0, 16);
        }
    } else {
        descStr = QString("%1 - ").arg(dev->descriptor.idVendor, 0, 16);
    }

    if (dev->descriptor.iProduct) {
        ret = usb_get_string_simple(udev, dev->descriptor.iProduct, str, sizeof(str));
        if (ret > 0) {
            descStr += QString(str);
        } else {
            descStr += QString("%1").arg(dev->descriptor.idProduct);
        }
    } else {
        descStr += QString("%1").arg(dev->descriptor.idProduct);
    }
    qDebug() << "dev->devnum = " << dev->devnum << ", desc = " << descStr;

    if (dev->descriptor.iSerialNumber) {
        ret = usb_get_string_simple(udev, dev->descriptor.iSerialNumber, str, sizeof(str));
        if (ret > 0) {
            qDebug() << QString(" - Serial Number: ").append(str);
        }
    }

    printDeviceDescriptor(&dev->descriptor);

    if (!dev->config) {
        qDebug() << "  Couldn't retrieve descriptors";
        return;
    }

    for (int i = 0; i < dev->descriptor.bNumConfigurations; i++) {
        printConfigDescriptor(&dev->config[i]);
    }
}

void OUsb::printDeviceDescriptor(usb_device_descriptor *desc)
{
    QStringList strList;
    strList << QString("bLength:            %1").arg(desc->bLength)
            << QString("bDescriptorType:    %1").arg(desc->bDescriptorType, 0, 16)
            << QString("bcdUSB:             %1").arg(desc->bcdUSB, 0, 16)
            << QString("bDeviceClass:       %1").arg(desc->bDeviceClass, 0, 16)
            << QString("bDeviceSubClass:    %1").arg(desc->bDeviceSubClass, 0, 16)
            << QString("bDeviceProtocol:    %1").arg(desc->bDeviceProtocol, 0, 16)
            << QString("bMaxPacketSize0:    %1").arg(desc->bMaxPacketSize0, 0, 16)
            << QString("idVendor:           %1").arg(desc->idVendor, 0, 16)
            << QString("idProduct:          %1").arg(desc->idProduct, 0, 16)
            << QString("bcdDevice:          %1").arg(desc->bcdDevice, 0, 16)
            << QString("iManufacturer:      %1").arg(desc->iManufacturer)
            << QString("iProduct:           %1").arg(desc->iProduct)
            << QString("iSerialNumber:      %1").arg(desc->iSerialNumber)
            << QString("bNumConfigurations: %1").arg(desc->bNumConfigurations);
    qDebug() << "打印设备描述符: ";
    qDebug() << strList;
}

void OUsb::printConfigDescriptor(usb_config_descriptor *config)
{
    QStringList strList;
    strList << QString("wTotalLength:       %1").arg(config->wTotalLength)
            << QString("bNumInterfaces:     %1").arg(config->bNumInterfaces)
            << QString("bConfigurationValue:%1").arg(config->bConfigurationValue)
            << QString("iConfiguration:     %1").arg(config->iConfiguration)
            << QString("bmAttributes:       %1").arg(config->bmAttributes)
            << QString("MaxPower:           %1").arg(config->MaxPower);
    qDebug() << "打印配置描述符: ";
    qDebug() << strList;

    for (int i = 0; i < config->bNumInterfaces; i++) {
        struct usb_interface *interface = &config->interface[i];
        qDebug() << "打印interface信息：";
        for (int j = 0; j < interface->num_altsetting; j++) {
            struct usb_interface_descriptor *interfaceDesc = &interface->altsetting[j];
            strList.clear();
            strList << QString("bInterfaceNumber:   %1").arg(interfaceDesc->bInterfaceNumber)
                    << QString("bAlternateSetting:  %1").arg(interfaceDesc->bAlternateSetting)
                    << QString("bNumEndpoints:      %1").arg(interfaceDesc->bNumEndpoints)
                    << QString("bInterfaceClass:    %1").arg(interfaceDesc->bInterfaceClass)
                    << QString("bInterfaceSubClass: %1").arg(interfaceDesc->bInterfaceSubClass)
                    << QString("bInterfaceProtocol: %1").arg(interfaceDesc->bInterfaceProtocol)
                    << QString("iInterface:         %1").arg(interfaceDesc->iInterface);
            qDebug() << strList;

            qDebug() << "打印EndPoint信息：";
            for (int k = 0; k < interfaceDesc->bNumEndpoints; k++) {
                struct usb_endpoint_descriptor *endpoint = &interfaceDesc->endpoint[k];
                strList.clear();
                strList << QString("bEndpointAddress: %1").arg(endpoint->bEndpointAddress, 0, 16)
                        << QString("bmAttributes:     %1").arg(endpoint->bmAttributes, 0, 16)
                        << QString("wMaxPacketSize:   %1").arg(endpoint->wMaxPacketSize)
                        << QString("bInterval:        %1").arg(endpoint->bInterval)
                        << QString("bRefresh:         %1").arg(endpoint->bRefresh)
                        << QString("bSynchAddress:    %1").arg(endpoint->bSynchAddress);
                qDebug() << strList;
            }
        }
    }
}

