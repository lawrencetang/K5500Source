#ifndef PTSETTINGWIDGET_H
#define PTSETTINGWIDGET_H

#include <QFrame>

namespace Ui {
class PTSettingWidget;
}

class OScrollArea;
class OFullKeyboard;
class PTParameterWidget;
class PTSettingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit PTSettingWidget(QWidget *parent = 0);
    ~PTSettingWidget();

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
    Ui::PTSettingWidget *ui;
    QStringList m_motorSetting;
    QStringList m_measureSetting;

    OScrollArea *m_pScrollArea;
    OFullKeyboard *m_pFullKeyboard;
    PTParameterWidget *m_pParameterWidget;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDSETTING_H
