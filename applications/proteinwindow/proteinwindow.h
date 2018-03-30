#ifndef PROTEINWINDOW_H
#define PROTEINWINDOW_H

#include <QFrame>

namespace Ui {
class ProteinWindow;
}

class OSerialPort;
class OSpectrograph;
class PTSettingModel;
class PTDetectionFlow;
class PTSettingWidget;
class PTTestingWidget;
class ProteinWindow : public QFrame
{
    Q_OBJECT

public:
    explicit ProteinWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent = 0);
    ~ProteinWindow();

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
    Ui::ProteinWindow *ui;
    bool m_isBlanked;
    bool m_isAnimation;
    PTSettingWidget *m_pSettingWidget;
    PTTestingWidget *m_pTestingWidget;
    PTDetectionFlow *m_pDetectionFlow;
    PTSettingModel *m_pSettingModel;

    void flipOverAnimation(QWidget *w);
    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDWINDOW_H
