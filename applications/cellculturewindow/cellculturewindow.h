#ifndef CELLCULTUREWINDOW_H
#define CELLCULTUREWINDOW_H

#include <QFrame>

namespace Ui {
class CellCultureWindow;
}

class OSerialPort;
class OSpectrograph;
class CCSettingModel;
class CCDetectionFlow;
class CCSettingWidget;
class CCTestingWidget;
class CellCultureWindow : public QFrame
{
    Q_OBJECT

public:
    explicit CellCultureWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent = 0);
    ~CellCultureWindow();

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
    Ui::CellCultureWindow *ui;
    bool m_isBlanked;
    bool m_isAnimation;
    CCSettingWidget *m_pSettingWidget;
    CCTestingWidget *m_pTestingWidget;
    CCDetectionFlow *m_pDetectionFlow;
    CCSettingModel *m_pSettingModel;

    void flipOverAnimation(QWidget *w);
    void initializeSignals();
    void initializeWidgets();
};

#endif // CELLCULTUREWINDOW_H
