#ifndef DYPARAMETERWIDGET_H
#define DYPARAMETERWIDGET_H

#include <QFrame>

namespace Ui {
class DYParameterWidget;
}

class DYParameterWidget : public QFrame
{
    Q_OBJECT

public:
    explicit DYParameterWidget(QWidget *parent = 0);
    ~DYParameterWidget();

    QStringList getMeasureSetting();
    void setMeasureSetting(QStringList data);
    QStringList getMotorSetting();
    void setMotorSetting(QStringList data);

public slots:
    void restore();

private:
    Ui::DYParameterWidget *ui;
    QList<QWidget *> m_motor;
    QList<QWidget *> m_motorSetting;
    QList<QWidget *> m_measureSetting;

    QStringList m_detectionMethods;
    QStringList m_mixingLevels;
    QStringList m_cuvetteOpticals;
    int m_bwl;
    int m_mwl;
    double m_targetValue;
    int m_incubationCount;
    int m_swl1;
    int m_swl2;
    int m_swl3;
    int m_swl4;
    int m_mixingTime;
    int m_staticTime;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDPARAMETER_H
