#ifndef NUCLEICACIDWINDOW_H
#define NUCLEICACIDWINDOW_H

#include <QFrame>

namespace Ui {
class NucleicAcidWindow;
}

class OSerialPort;
class OSpectrograph;
class NASettingModel;
class NADetectionFlow;
class NASettingWidget;
class NATestingWidget;
class NucleicAcidWindow : public QFrame
{
    Q_OBJECT

public:
    explicit NucleicAcidWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent = 0);
    ~NucleicAcidWindow();

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
    Ui::NucleicAcidWindow *ui;
    bool m_isBlanked;
    bool m_isAnimation;
    NASettingWidget *m_pSettingWidget;
    NATestingWidget *m_pTestingWidget;
    NADetectionFlow *m_pDetectionFlow;
    NASettingModel *m_pSettingModel;

    void flipOverAnimation(QWidget *w);
    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDWINDOW_H
