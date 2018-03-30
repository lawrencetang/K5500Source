#ifndef PTSETTINGMODEL_H
#define PTSETTINGMODEL_H

#include <QObject>
#include <QStringList>

class CuvetteOpticalModel;
class MicroscaleOpticalModel;
class MASettingModel
{
public:
    explicit MASettingModel(QStringList measureParameters = QStringList(), QStringList motorParameters = QStringList(),
                            QList<QStringList> dyeInfomations = QList<QStringList>(), int maxChannelNumber = 1);
    ~MASettingModel();

    void setMeasureParameters(QStringList settings);
    void setMotorParameters(QStringList settings);
    void setDyeInfoList(QList<QStringList> dyeInfos);
    QList<int> getIdList();
    void setMaxChannelNumber(int channelNumber){ m_maxChannelNumber = channelNumber;}
    int getMaxChannelNumber(){return m_maxChannelNumber;}
    QList<QStringList> getDyeInfoList() {return m_dyeInfoList;}

    QString getDetectionMethod() {return m_detectionMethod;}
    QString getDetectionMatter() {return m_detectionMatter;}
    QString getSampleName() {return m_sampleName;}
    int getChannelNumber() {return m_channelNumber;}
    QString getMethod() {return m_method;}
    double getCoefficient() {return m_coefficient;}
    QString getOptical() {return m_opticalStr;}
    int getBwl() {return m_bwl;}
    int getMwl() {return m_mwl;}
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
    QString m_detectionMatter;
    QString m_sampleName;
    int m_channelNumber;
    QString m_method;
    double m_coefficient;
    QString m_opticalStr;
    int m_bwl;
    int m_mwl;
    QString m_unit;
    int m_mixingLevel;
    int m_mixingTime;
    int m_staticTime;
    int m_maxChannelNumber;
    QList<QStringList> m_dyeInfoList;

    CuvetteOpticalModel *m_pCuvetteOpticalModel;
    MicroscaleOpticalModel *m_pMicroscaleOpticalModel;
};

#endif // NUCLEICACIDSETTINGMODEL_H
