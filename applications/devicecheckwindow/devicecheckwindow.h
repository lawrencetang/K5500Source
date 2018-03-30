#ifndef DEVICECHECKWINDOW_H
#define DEVICECHECKWINDOW_H

#include <QFrame>
#include <QStringList>

namespace Ui {
class DeviceCheckWindow;
}

class OPlot;
class OSerialPort;
class OSpectrograph;
class ODigitKeyboard;
class DeviceCheckWindow : public QFrame
{
    Q_OBJECT

public:
    explicit DeviceCheckWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent = 0);
    ~DeviceCheckWindow();

signals:
    void backToMainPage();
    void toDrawCurve(QString title, QVector<double> x, QVector<double> y);

protected:
    virtual void closeEvent(QCloseEvent *event);

private slots:
    void clearCurves();
    void excuteCheck();
    void changeMethod(QString method);
    void changeOptical(QString optical);

private:
    Ui::DeviceCheckWindow *ui;
    int m_channelNumber;
    int m_cuvetteIntegrationTime;
    int m_cuvetteFrequency;
    double m_cuvetteFactor;
    QStringList m_cuvetteOptical;

    QStringList m_microscaleFactor;
    QStringList m_microscaleRotateAngle;
    QStringList m_microscaleFrequency;
    QStringList m_microscaleIntegrationTime;
    QStringList m_microscaleOptical;

    OPlot *m_pPlot;
    OSerialPort *m_pSerialPort;
    OSpectrograph *m_pSpectrograph;
    ODigitKeyboard *m_pKeyboard;

    bool m_isWaiting;
    void delay(int timeout);

    void initializeSystem();
    void initializeWidget();
    void initializeSignal();
};

#endif // DEVICECHECKWINDOW_H
