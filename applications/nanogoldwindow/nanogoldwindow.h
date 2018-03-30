#ifndef NANOGOLDWINDOW_H
#define NANOGOLDWINDOW_H

#include <QFrame>

namespace Ui {
class NanoGoldWindow;
}

class OSerialPort;
class OSpectrograph;
class NGSettingModel;
class NGDetectionFlow;
class NGSettingWidget;
class NGTestingWidget;
class NanoGoldWindow : public QFrame
{
    Q_OBJECT

public:
    explicit NanoGoldWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent = 0);
    ~NanoGoldWindow();

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
    Ui::NanoGoldWindow *ui;
    bool m_isBlanked;
    bool m_isAnimation;
    NGSettingWidget *m_pSettingWidget;
    NGTestingWidget *m_pTestingWidget;
    NGDetectionFlow *m_pDetectionFlow;
    NGSettingModel *m_pSettingModel;

    void flipOverAnimation(QWidget *w);
    void initializeSignals();
    void initializeWidgets();
};

#endif // NANOGOLDWINDOW_H
