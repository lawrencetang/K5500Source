#ifndef DYSETTINGMODEL_H
#define DYSETTINGMODEL_H

#include <QObject>
#include <QStringList>

class CuvetteOpticalModel;
class DYSettingModel
{
public:
    explicit DYSettingModel(QStringList measureParameters = QStringList(),
                            QStringList motorParameters = QStringList());
    ~DYSettingModel();

    void setMeasureParameters(QStringList settings);
    void setMotorParameters(QStringList settings);

    QString getDetectionMethod() {return m_detectionMethod;}
    QString getSampleName() {return m_sampleName;}
    QString getOptical() {return m_opticalStr;}
    int getBwl() {return m_bwl;}
    int getMwl() {return m_mwl;}
    double getTargetValue() {return m_targetValue;}
    int getIncubationCount() {return m_incubationCount;}
    int getSwl1() {return m_swl1;}
    int getSwl2() {return m_swl2;}
    int getSwl3() {return m_swl3;}
    int getSwl4() {return m_swl4;}
    int getMixingLevel() {return m_mixingLevel;}
    int getMixingTime() {return m_mixingTime;}
    int getStaticTime() {return m_staticTime;}

    int getCuvetteIntegrationTime();
    int getCuvetteFrequency();
    int getCuvetteCorrectionFactor();

private:
    QString m_detectionMethod;
    QString m_sampleName;
    QString m_opticalStr;
    int m_bwl;
    int m_mwl;
    double m_targetValue;
    int m_incubationCount;
    int m_swl1;
    int m_swl2;
    int m_swl3;
    int m_swl4;
    int m_mixingLevel;
    int m_mixingTime;
    int m_staticTime;

    CuvetteOpticalModel *m_pCuvetteOpticalModel;
};

#endif // NUCLEICACIDSETTINGMODEL_H
