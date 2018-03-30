#ifndef UVSETTINGMODEL_H
#define UVSETTINGMODEL_H

#include <QObject>
#include <QStringList>

class CuvetteOpticalModel;
class MicroscaleOpticalModel;
class UVSettingModel
{
public:
    explicit UVSettingModel(QStringList measureParameters = QStringList(),
                                     QStringList motorParameters = QStringList(), int maxChannelNumber = 1);
    ~UVSettingModel();

    void setMeasureParameters(QStringList settings);
    void setMotorParameters(QStringList settings);
    QList<int> getIdList();
    void setMaxChannelNumber(int channelNumber){ m_maxChannelNumber = channelNumber;}
    int getMaxChannelNumber(){return m_maxChannelNumber;}

    QString getDetectionMethod() {return m_detectionMethod;}
    QString getSampleName() {return m_sampleName;}
    int getChannelNumber() {return m_channelNumber;}
    QString getOptical() {return m_opticalStr;}
    int getBwl() {return m_bwl;}
    int getWl1() {return m_wl1;}
    int getWl2() {return m_wl2;}
    int getWl3() {return m_wl3;}
    int getWl4() {return m_wl4;}
    int getWl5() {return m_wl5;}
    double getCoef1() {return m_coef1;}
    double getCoef2() {return m_coef2;}
    double getCoef3() {return m_coef3;}
    double getCoef4() {return m_coef4;}
    double getCoef5() {return m_coef5;}
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
    QString m_opticalStr;
    int m_bwl;

    int m_wl1;
    int m_wl2;
    int m_wl3;
    int m_wl4;
    int m_wl5;

    double m_coef1;
    double m_coef2;
    double m_coef3;
    double m_coef4;
    double m_coef5;

    int m_mixingLevel;
    int m_mixingTime;
    int m_staticTime;
    int m_maxChannelNumber;

    CuvetteOpticalModel *m_pCuvetteOpticalModel;
    MicroscaleOpticalModel *m_pMicroscaleOpticalModel;
};

#endif // UVSETTINGMODEL_H
