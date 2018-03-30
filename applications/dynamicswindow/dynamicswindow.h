#ifndef DYNAMICSWINDOW_H
#define DYNAMICSWINDOW_H

#include <QFrame>

namespace Ui {
class DynamicsWindow;
}

class OSerialPort;
class OSpectrograph;
class DYSettingModel;
class DYDetectionFlow;
class DYSettingWidget;
class DYTestingWidget;
class DynamicsWindow : public QFrame
{
    Q_OBJECT

public:
    explicit DynamicsWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent = 0);
    ~DynamicsWindow();

signals:
    void backToMainPage();

private slots:
    void back();
    void showTestingPage();
    void showSettingPage();
    void startBlank();
    void startMeasure();

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    Ui::DynamicsWindow *ui;
    bool m_isBlanked;
    bool m_isAnimation;
    DYSettingWidget *m_pSettingWidget;
    DYTestingWidget *m_pTestingWidget;
    DYDetectionFlow *m_pDetectionFlow;
    DYSettingModel *m_pSettingModel;

    void flipOverAnimation(QWidget *w);
    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDWINDOW_H
