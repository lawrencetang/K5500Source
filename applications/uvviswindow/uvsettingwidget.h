#ifndef UVSETTINGWIDGET_H
#define UVSETTINGWIDGET_H

#include <QFrame>

namespace Ui {
class UVSettingWidget;
}

class OScrollArea;
class OFullKeyboard;
class UVParameterWidget;
class UVSettingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit UVSettingWidget(QWidget *parent = 0);
    ~UVSettingWidget();

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
    Ui::UVSettingWidget *ui;
    QStringList m_motorSetting;
    QStringList m_measureSetting;

    OScrollArea *m_pScrollArea;
    OFullKeyboard *m_pFullKeyboard;
    UVParameterWidget *m_pParameterWidget;

    void initializeSignals();
    void initializeWidgets();
};

#endif // UVSETTINGWIDGET_H
