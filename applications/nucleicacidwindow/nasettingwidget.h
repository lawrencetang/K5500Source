#ifndef NASETTINGWIDGET_H
#define NASETTINGWIDGET_H

#include <QFrame>

namespace Ui {
class NASettingWidget;
}

class OScrollArea;
class OFullKeyboard;
class NAParameterWidget;
class NASettingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit NASettingWidget(QWidget *parent = 0);
    ~NASettingWidget();

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
    Ui::NASettingWidget *ui;
    QStringList m_motorSetting;
    QStringList m_measureSetting;

    OScrollArea *m_pScrollArea;
    OFullKeyboard *m_pFullKeyboard;
    NAParameterWidget *m_pParameterWidget;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDSETTING_H
