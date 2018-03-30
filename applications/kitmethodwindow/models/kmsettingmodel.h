#ifndef KMSETTINGMODEL_H
#define KMSETTINGMODEL_H

#include <QObject>
#include <QStringList>

class CuvetteOpticalModel;
class MicroscaleOpticalModel;
class KMSettingModel
{
public:
    explicit KMSettingModel(QStringList measureParameters = QStringList(),
                                     QStringList motorParameters = QStringList(), int maxChannelNumber = 1);
    ~KMSettingModel();

    void setMeasureParameters(QStringList settings);
    void setMotorParameters(QStringList settings);
    QList<int> getIdList();
    void setMaxChannelNumber(int channelNumber){ m_maxChannelNumber = channelNumber;}
    int getMaxChannelNumber(){return m_maxChannelNumber;}

    QString getDetectionMethod() {return m_detectionMethod;}
    QString getSampleName() {return m_sampleName;}
    int getChannelNumber() {return m_channelNumber;}
    QString getMethod() {return m_method;}
    QString getOptical() {return m_opticalStr;}
    int getBwl() {return m_bwl;}
    int getMwl() {return m_mwl;}
    int getOrder() {return m_order;}
    QString getUnit() {return m_unit;}
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
    QString m_opticalStr;
    int m_bwl;
    int m_mwl;
    QString m_unit;
    int m_mixingLevel;
    int m_mixingTime;
    int m_staticTime;
    int m_maxChannelNumber;
    int m_order;

    CuvetteOpticalModel *m_pCuvetteOpticalModel;
    MicroscaleOpticalModel *m_pMicroscaleOpticalModel;
};

#endif // NUCLEICACIDSETTINGMODEL_H
