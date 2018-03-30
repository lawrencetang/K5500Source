#ifndef CCSETTINGMODEL_H
#define CCSETTINGMODEL_H

#include <QObject>
#include <QStringList>

class CuvetteOpticalModel;
class MicroscaleOpticalModel;
class CCSettingModel
{
public:
    explicit CCSettingModel(QStringList measureParameters = QStringList(),
                                     QStringList motorParameters = QStringList(), int maxChannelNumber = 1);
    ~CCSettingModel();

    void setMeasureParameters(QStringList settings);
    void setMotorParameters(QStringList settings);
    QList<int> getIdList();
    void setMaxChannelNumber(int channelNumber){ m_maxChannelNumber = channelNumber;}
    int getMaxChannelNumber(){return m_maxChannelNumber;}

    QString getDetectionMethod() {return m_detectionMethod;}
    QString getSampleName() {return m_sampleName;}
    int getChannelNumber() {return m_channelNumber;}
    QString getMethod() {return m_method;}
    double getCoefficient() {return m_coefficient;}
    QString getOptical() {return m_opticalStr;}
    int getBwl() {return m_bwl;}
    int getMwl() {return m_mwl;}
    int getMixingLevel() {return m_mixingLevel;}
    int getMixingTime() {return m_mixingTime;}
    int getStaticTime() {return m_staticTime;}

    QStringList getMicroscaleOpticalList();
    int getMicroscaleIntegrationTime(QString opticalStr);
    int getMicroscaleFrequency(QString opticalStr);
    int getMicroscaleRotateAngle(QString opticalStr);
    double getMicroscaleCorrectionFactor(QString opticalStr);
    double getMicroscaleUpperLimit();
    double getMicroscaleLowerLimit();
    QString getMicroscaleStdOptical();
    QString getMicroscaleMaxOptical();
    QString getMicroscaleMinOptical();

    int getCuvetteIntegrationTime();
    int getCuvetteFrequency();
    int getCuvetteCorrectionFactor();

private:
    QString m_detectionMethod;
    QString m_sampleName;
    int m_channelNumber;
    QString m_method;
    double m_coefficient;
    QString m_opticalStr;
    int m_bwl;
    int m_mwl;
    int m_mixingLevel;
    int m_mixingTime;
    int m_staticTime;
    int m_maxChannelNumber;

    CuvetteOpticalModel *m_pCuvetteOpticalModel;
    MicroscaleOpticalModel *m_pMicroscaleOpticalModel;
};

#endif // NUCLEICACIDSETTINGMODEL_H
