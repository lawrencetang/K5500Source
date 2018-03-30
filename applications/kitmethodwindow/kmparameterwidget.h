#ifndef KMPARAMETERWIDGET_H
#define KMPARAMETERWIDGET_H

#include <QFrame>

namespace Ui {
class KMParameterWidget;
}

class KMParameterWidget : public QFrame
{
    Q_OBJECT

public:
    explicit KMParameterWidget(QWidget *parent = 0);
    ~KMParameterWidget();

    QStringList getMeasureSetting();
    void setMeasureSetting(QStringList data);
    QStringList getMotorSetting();
    void setMotorSetting(QStringList data);

    int getMaxChannelNumber() {return m_channelNumber;}
    QString getCurrentMethod();

    void setUnit(QString unit);
    void setMethod(QString method);
    void setSampleName(QString name);
    void setOrder(QString order);

public slots:
    void restore();

private slots:
    void changeWaveLength(int index);
    void changeDetectionMothed(QString method);

private:
    Ui::KMParameterWidget *ui;
    QList<QWidget *> m_motor;
    QList<QWidget *> m_motorSetting;
    QList<QWidget *> m_measureSetting;

    QStringList m_detectionMethods;
    QStringList m_methods;
    QStringList m_waveLengths;
    QStringList m_usedUnits;
    QStringList m_mixingLevels;
    QStringList m_microscaleOpticals;
    QStringList m_cuvetteOpticals;
    int m_bwl;
    int m_channelNumber;
    QStringList m_orders;

    void initializeSignals();
    void initializeWidgets();
};

#endif // NUCLEICACIDPARAMETER_H
