#ifndef MASETTINGWIDGET_H
#define MASETTINGWIDGET_H

#include <QFrame>

namespace Ui {
class MASettingWidget;
}

class MADyeWidget;
class OScrollArea;
class OFullKeyboard;
class MAParameterWidget;
class MASettingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit MASettingWidget(QWidget *parent = 0);
    ~MASettingWidget();

    QString getCurrentMethod();
    int getMaxChannelNumber();

    void save();
    QStringList getMeasureSetting() {
        return m_measureSetting;
    }
    QStringList getMotorSetting() {
        return m_motorSetting;
    }
    QList<QStringList> getDyeSetting();

signals:
    void toTestingPage();

private slots:
    void back();
    void setHeaderDisabled(bool ok);

private:
    Ui::MASettingWidget *ui;
    QStringList m_motorSetting;
    QStringList m_measureSetting;

    MADyeWidget *m_pDyeWidget;
    OScrollArea *m_pScrollArea;
    OFullKeyboard *m_pFullKeyboard;
    MAParameterWidget *m_pParameterWidget;

    void initializeSignals();
    void initializeWidgets();
};

#endif // MASettingWidget
