#ifndef DYSETTINGWIDGET_H
#define DYSETTINGWIDGET_H

#include <QFrame>

namespace Ui {
class DYSettingWidget;
}

class OScrollArea;
class OFullKeyboard;
class DYParameterWidget;
class DYSettingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit DYSettingWidget(QWidget *parent = 0);
    ~DYSettingWidget();

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
    Ui::DYSettingWidget *ui;
    QStringList m_motorSetting;
    QStringList m_measureSetting;

    OScrollArea *m_pScrollArea;
    OFullKeyboard *m_pFullKeyboard;
    DYParameterWidget *m_pParameterWidget;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDSETTING_H
