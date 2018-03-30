#ifndef TEMPERATUREWINDOW_H
#define TEMPERATUREWINDOW_H

#include <QFrame>

namespace Ui {
class TemperatureWindow;
}

class CqDial;
class OSerialPort;
class ODigitKeyboard;
class TemperatureWindow : public QFrame
{
    Q_OBJECT

public:
    explicit TemperatureWindow(OSerialPort *serialPort, QWidget *parent = 0);
    ~TemperatureWindow();

protected:
    virtual void closeEvent(QCloseEvent *event);

signals:
    void backToMainPage();

private slots:
    void onRunBtnClicked();
    void onBackBtnClicked();
    void showTemperature();

private:
    Ui::TemperatureWindow *ui;
    ODigitKeyboard *m_pKeyboard;
    CqDial *m_pDial;
    OSerialPort *m_pSerialPort;
    QTimer *m_pTimer;
};

#endif // TEMPERATUREWINDOW_H
