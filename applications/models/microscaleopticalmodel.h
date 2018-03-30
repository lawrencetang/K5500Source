#ifndef MICROSCALEOPTICALMODEL_H
#define MICROSCALEOPTICALMODEL_H

#include <QObject>
#include <QStringList>

class MicroscaleOpticalModel : public QObject
{
    Q_OBJECT
public:
    explicit MicroscaleOpticalModel(QString fileName, QObject *parent = 0);
    ~MicroscaleOpticalModel();

    QString getStdOptical();
    QString getMaxOptical();
    QString getMinOptical();

    QStringList getOpticalList() {return m_opticalList;}
    int getIntegrationTime(QString opticalStr);
    int getFrequency(QString opticalStr);
    int getRotateAngle(QString opticalStr);
    double getCorrectionFactor(QString opticalStr);

    double getUpperLimit() {return m_upperLimit;}
    double getLowerLimit() {return m_lowerLimit;}

    void reset();

private:
    QString m_fileName;
    QStringList m_opticalList;
    QStringList m_integrationTimeList;
    QStringList m_frequencyList;
    QStringList m_rotateAngleList;
    QStringList m_correctionFactorList;

    double m_upperLimit;
    double m_lowerLimit;

    void clear();
    void initialize();
};

#endif // MICROSCALEOPTICALMODEL_H
