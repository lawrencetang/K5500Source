#ifndef MICROARRAyWINDOW_H
#define MICROARRAyWINDOW_H

#include <QFrame>

namespace Ui {
class MicroArrayWindow;
}

class OSerialPort;
class OSpectrograph;
class MASettingModel;
class MADetectionFlow;
class MASettingWidget;
class MATestingWidget;
class MicroArrayWindow : public QFrame
{
    Q_OBJECT

public:
    explicit MicroArrayWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent = 0);
    ~MicroArrayWindow();

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
    Ui::MicroArrayWindow *ui;
    bool m_isBlanked;
    bool m_isAnimation;
    MASettingWidget *m_pSettingWidget;
    MATestingWidget *m_pTestingWidget;
    MADetectionFlow *m_pDetectionFlow;
    MASettingModel *m_pSettingModel;

    void flipOverAnimation(QWidget *w);
    void initializeSignals();
    void initializeWidgets();
};

#endif // MICROARRAyWINDOW_H
