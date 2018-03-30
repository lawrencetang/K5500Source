#ifndef CCSETTINGWIDGET_H
#define CCSETTINGWIDGET_H

#include <QFrame>

namespace Ui {
class CCSettingWidget;
}

class OScrollArea;
class OFullKeyboard;
class CCParameterWidget;
class CCSettingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit CCSettingWidget(QWidget *parent = 0);
    ~CCSettingWidget();

    QString getCurrentMethod();
    int getMaxChannelNumber();

    void save();
    QStringList getMeasureSetting() {
        return m_measureSetting;
    }
    QStringList getMotorSetting() {
        return m_motorSetting;
    }

signals:
    void toTestingPage();

private slots:
    void back();

private:
    Ui::CCSettingWidget *ui;
    QStringList m_motorSetting;
    QStringList m_measureSetting;

    OScrollArea *m_pScrollArea;
    OFullKeyboard *m_pFullKeyboard;
    CCParameterWidget *m_pParameterWidget;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDSETTING_H
