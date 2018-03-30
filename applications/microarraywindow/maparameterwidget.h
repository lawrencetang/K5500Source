#ifndef MAPARAMETERWIDGET_H
#define MAPARAMETERWIDGET_H

#include <QFrame>

namespace Ui {
class MAParameterWidget;
}

class MAParameterWidget : public QFrame
{
    Q_OBJECT

public:
    explicit MAParameterWidget(QWidget *parent = 0);
    ~MAParameterWidget();

    QStringList getMeasureSetting();
    void setMeasureSetting(QStringList data);
    QStringList getMotorSetting();
    void setMotorSetting(QStringList data);

    int getMaxChannelNumber() {return m_channelNumber;}
    QString getCurrentMethod();

public slots:
    void restore();

private slots:
    void changeMatter(QString matter);
    void changeCofficient(int index);
    void changeDetectionMothed(QString method);

private:
    Ui::MAParameterWidget *ui;
    QList<QWidget *> m_motor;
    QList<QWidget *> m_motorSetting;
    QList<QWidget *> m_measureSetting;

    QStringList m_detectionMethods;
    QStringList m_detectionMatters;
    QStringList m_nucleicAcidMethods;
    QStringList m_nucleicAcidCoefficients;
    QStringList m_proteinMethods;
    QStringList m_proteinCoefficients;
    QStringList m_usedUnits;
    QStringList m_mixingLevels;
    QStringList m_microscaleOpticals;
    QStringList m_cuvetteOpticals;
    int m_bwl;
    int m_nucleicAcidMwl;
    int m_proteinMwl;
    int m_channelNumber;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDPARAMETER_H
