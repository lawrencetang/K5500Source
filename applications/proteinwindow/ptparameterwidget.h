#ifndef PTPARAMETERWIDGET_H
#define PTPARAMETERWIDGET_H

#include <QFrame>

namespace Ui {
class PTParameterWidget;
}

class PTParameterWidget : public QFrame
{
    Q_OBJECT

public:
    explicit PTParameterWidget(QWidget *parent = 0);
    ~PTParameterWidget();

    QStringList getMeasureSetting();
    void setMeasureSetting(QStringList data);
    QStringList getMotorSetting();
    void setMotorSetting(QStringList data);

    int getMaxChannelNumber() {return m_channelNumber;}
    QString getCurrentMethod();

public slots:
    void restore();

private slots:
    void changeCofficient(int index);
    void changeDetectionMothed(QString method);

private:
    Ui::PTParameterWidget *ui;
    QList<QWidget *> m_motor;
    QList<QWidget *> m_motorSetting;
    QList<QWidget *> m_measureSetting;

    QStringList m_detectionMethods;
    QStringList m_methods;
    QStringList m_coefficients;
    QStringList m_usedUnits;
    QStringList m_mixingLevels;
    QStringList m_microscaleOpticals;
    QStringList m_cuvetteOpticals;
    int m_bwl;
    int m_mwl;
    int m_channelNumber;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDPARAMETER_H
