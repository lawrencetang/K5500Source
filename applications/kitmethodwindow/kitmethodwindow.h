#ifndef KITMETHODWINDOW_H
#define KITMETHODWINDOW_H

#include <QFrame>

namespace Ui {
class KitMethodWindow;
}

class OSerialPort;
class OSpectrograph;
class KMSettingModel;
class KMDetectionFlow;
class KMSettingWidget;
class KMTestingWidget;
class KitMethodWindow : public QFrame
{
    Q_OBJECT

public:
    explicit KitMethodWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent = 0);
    ~KitMethodWindow();

signals:
    void backToMainPage();

private slots:
    void back();
    void showTestingPage();
    void showSettingPage();

    void startBlank();
    void startMeasure();
    void startFitting();

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    Ui::KitMethodWindow *ui;
    bool m_isBlanked;
    bool m_isAnimation;
    KMSettingWidget *m_pSettingWidget;
    KMTestingWidget *m_pTestingWidget;
    KMDetectionFlow *m_pDetectionFlow;
    KMSettingModel *m_pSettingModel;

    void flipOverAnimation(QWidget *w);
    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDWINDOW_H
