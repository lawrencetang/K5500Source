#ifndef OSPECTROGRAPH_H
#define OSPECTROGRAPH_H

#include <QObject>
#include <QVector>

class OpticalIntensity;
class OSpectrographDevice;
class OSpectrograph : public QObject
{
    Q_OBJECT
public:
    explicit OSpectrograph(QObject *parent = 0);
    ~OSpectrograph();

    bool isOpened() { return m_isOpened; }
    QString openSpectrograph();
    void closeSpectrograph();
    OpticalIntensity readSpectrograph(int iTime = 40000, int rCount = 1, int timeout = 500);
    QString serialNumber();

private:
    bool m_isOpened;
    double m_threshold;
    OSpectrographDevice *m_pSpectrographDevice;
    void delay(int timeout);
    void transformWaveLength(QVector<double> w, QVector<double> i,
                             QVector<double> &r_w, QVector<double> &r_i);
};

#endif // OSPECTROGRAPH_H
