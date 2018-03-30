#ifndef UVVISWINDOW_H
#define UVVISWINDOW_H

#include <QFrame>

namespace Ui {
class UvVisWindow;
}

class OSerialPort;
class OSpectrograph;
class UVSettingModel;
class UVDetectionFlow;
class UVSettingWidget;
class UVTestingWidget;
class UvVisWindow : public QFrame
{
    Q_OBJECT

public:
    explicit UvVisWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent = 0);
    ~UvVisWindow();

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
    Ui::UvVisWindow *ui;
    bool m_isBlanked;
    bool m_isAnimation;
    UVSettingWidget *m_pSettingWidget;
    UVTestingWidget *m_pTestingWidget;
    UVDetectionFlow *m_pDetectionFlow;
    UVSettingModel *m_pSettingModel;

    void flipOverAnimation(QWidget *w);
    void initializeSignals();
    void initializeWidgets();
};

#endif // UVVISWINDOW_H
