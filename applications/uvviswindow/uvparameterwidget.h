#ifndef UVPARAMETERWIDGET_H
#define UVPARAMETERWIDGET_H

#include <QFrame>

namespace Ui {
class UVParameterWidget;
}

class QSpinBox;
class QDoubleSpinBox;
class UVParameterWidget : public QFrame
{
    Q_OBJECT

public:
    explicit UVParameterWidget(QWidget *parent = 0);
    ~UVParameterWidget();

    QStringList getMeasureSetting();
    void setMeasureSetting(QStringList data);
    QStringList getMotorSetting();
    void setMotorSetting(QStringList data);

    int getMaxChannelNumber() {return m_channelNumber;}

public slots:
    void restore();

private slots:
    void changeDetectionMothed(QString method);

private:
    Ui::UVParameterWidget *ui;
    QList<QWidget *> m_motor;
    QList<QWidget *> m_motorSetting;
    QList<QWidget *> m_measureSetting;
    QList<QSpinBox *> m_maveLengthSetting;
    QList<QDoubleSpinBox *> m_coefficientSetting;

    QStringList m_detectionMethods;
    QStringList m_mixingLevels;
    QStringList m_microscaleOpticals;
    QStringList m_cuvetteOpticals;
    QStringList m_maveLengths;
    QStringList m_cofficients;
    int m_bwl;
    int m_channelNumber;

    void initializeSignals();
    void initializeWidgets();
};

#endif // UVPARAMETERWIDGET_H
