#ifndef CUVETTEOPTICALMODEL_H
#define CUVETTEOPTICALMODEL_H

#include <QObject>
#include <QStringList>

class CuvetteOpticalModel : public QObject
{
    Q_OBJECT
public:
    explicit CuvetteOpticalModel(QString fileName, QObject *parent = 0);
    ~CuvetteOpticalModel();

    int getIntegrationTime() { return m_integrationTime.toInt(); }
    int getFrequency() { return m_frequency.toInt(); }
    double getCorrectionFactor() { return m_correctionFactor.toDouble(); }

    void reset();

private:
    QString m_fileName;
    QStringList m_opticalList;
    QString m_integrationTime;
    QString m_frequency;
    QString m_correctionFactor;

    void clear();
    void initialize();
};

#endif // NUCLEICACIDOPTICALMODEL_H
