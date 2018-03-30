#ifndef NGPARAMETERWIDGET_H
#define NGPARAMETERWIDGET_H

#include <QFrame>

namespace Ui {
class NGParameterWidget;
}

class NGParameterWidget : public QFrame
{
    Q_OBJECT

public:
    explicit NGParameterWidget(QWidget *parent = 0);
    ~NGParameterWidget();

    QStringList getMeasureSetting();
    void setMeasureSetting(QStringList data);
    QStringList getMotorSetting();
    void setMotorSetting(QStringList data);

    int getMaxChannelNumber() {return m_channelNumber;}
    QString getCurrentMethod();

public slots:
    void restore();

private slots:
    void changeParameter(int index);
    void changeDetectionMothed(QString method);

private:
    Ui::NGParameterWidget *ui;
    QList<QWidget *> m_motor;
    QList<QWidget *> m_motorSetting;
    QList<QWidget *> m_measureSetting;

    QStringList m_detectionMethods;
    QStringList m_methods;
    QStringList m_coefficients;
    QStringList m_mixingLevels;
    QStringList m_microscaleOpticals;
    QStringList m_cuvetteOpticals;
    QStringList m_mwls;
    int m_bwl;
    int m_channelNumber;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDPARAMETER_H
