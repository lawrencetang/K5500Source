#ifndef OSERIALPORT_H
#define OSERIALPORT_H

#include <QMutex>
#include <QObject>

class QSerialPort;
class OSerialPort : public QObject
{
    Q_OBJECT
public:
    explicit OSerialPort(QObject *parent = 0);
    ~OSerialPort();

    QString openSerialPort(QString portName);
    QString closeSerialPort();
    QString writeSerialPort(QByteArray txBuffer, QByteArray &rxBuffer, int timeout);
    QString serialPortName();

private slots:
    void receive();

private:
    int m_boundRate;
    QString m_description;
    QSerialPort *m_pSerialPort;

    QMutex m_mutex;
    int m_nestCount;
    QByteArray m_rxBuffer;
    QList<QByteArray> m_rxBufferList;
    void initializeSystem();
};

#endif // OSERIALPORT_H
