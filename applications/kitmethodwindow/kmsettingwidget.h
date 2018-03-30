#ifndef KMSETTINGWIDGET_H
#define KMSETTINGWIDGET_H

#include <QFrame>

namespace Ui {
class KMSettingWidget;
}

class OScrollArea;
class OFullKeyboard;
class KMParameterWidget;
class KMSettingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit KMSettingWidget(QWidget *parent = 0);
    ~KMSettingWidget();

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

public slots:
    void updateData(QStringList record);

private slots:
    void back();

private:
    Ui::KMSettingWidget *ui;
    QStringList m_motorSetting;
    QStringList m_measureSetting;

    OScrollArea *m_pScrollArea;
    OFullKeyboard *m_pFullKeyboard;
    KMParameterWidget *m_pParameterWidget;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDSETTING_H
