#ifndef NGSETTINGWIDGET_H
#define NGSETTINGWIDGET_H

#include <QFrame>

namespace Ui {
class NGSettingWidget;
}

class OScrollArea;
class OFullKeyboard;
class NGParameterWidget;
class NGSettingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit NGSettingWidget(QWidget *parent = 0);
    ~NGSettingWidget();

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
    Ui::NGSettingWidget *ui;
    QStringList m_motorSetting;
    QStringList m_measureSetting;

    OScrollArea *m_pScrollArea;
    OFullKeyboard *m_pFullKeyboard;
    NGParameterWidget *m_pParameterWidget;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDSETTING_H
