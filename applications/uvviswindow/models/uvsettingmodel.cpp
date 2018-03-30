#include "uvsettingmodel.h"

#include <QDebug>
#include "cuvetteopticalmodel.h"
#include "microscaleopticalmodel.h"

//#define PROFILE "/configs/uv_vis/uv_vis.ini"
#define PROFILE "/configs/optical.ini"

UVSettingModel::UVSettingModel(QStringList measureParameters,
                           QStringList motorParameters, int maxChannelNumber) {

    m_pCuvetteOpticalModel = new CuvetteOpticalModel(PROFILE);
    m_pMicroscaleOpticalModel = new MicroscaleOpticalModel(PROFILE);
    m_maxChannelNumber = maxChannelNumber;

    setMeasureParameters( measureParameters );
    setMotorParameters( motorParameters );
}

UVSettingModel::~UVSettingModel() {
    delete m_pCuvetteOpticalModel;
    delete m_pMicroscaleOpticalModel;
}

/**
 * @brief UVSettingModel::setMeasureParameters
 * @param settings
 */
void UVSettingModel::setMeasureParameters(QStringList settings) {

    for (int i = 0; i < settings.size(); i ++) {
        QString str = settings.at(i);
        switch(i) {
        case 0:
            m_detectionMethod = str;
            break;
        case 1:
            m_sampleName = str;
            break;
        case 2:
            m_bwl = str.toInt();
            break;
        case 3:
            m_channelNumber = str.toInt();
            break;
        case 4:
            m_opticalStr = str;
            break;
        case 5:
            m_wl1 = str.toInt();
            break;
        case 6:
            m_coef1 = str.toDouble();
            break;
        case 7:
            m_wl2 = str.toInt();
            break;
        case 8:
            m_coef2 = str.toDouble();
            break;
        case 9:
            m_wl3 = str.toInt();
            break;
        case 10:
            m_coef3 = str.toDouble();
            break;
        case 11:
            m_wl4 = str.toInt();
            break;
        case 12:
            m_coef4 = str.toDouble();
            break;
        case 13:
            m_wl5 = str.toInt();
            break;
        case 14:
            m_coef5 = str.toDouble();
            break;
        }
    }
}

/**
 * @brief UVSettingModel::setMotorParameters
 * @param settings
 */
void UVSettingModel::setMotorParameters(QStringList settings) {

    for (int i = 0; i < settings.size(); i ++) {
        QString str = settings.at(i);
        switch(i) {
        case 0:
            m_mixingLevel = str.toInt();
            break;
        case 1:
            m_mixingTime = str.toInt();
            break;
        case 2:
            m_staticTime = str.toInt();
            break;
        }
    }
}

/**
 * @brief UVSettingModel::getIdList
 * @return
 */
QList<int> UVSettingModel::getIdList() {
    QList<int> result;
    for(int i = 0; i < m_channelNumber; i++) {
        result.append(i);
    }
    return result;
}

/**
 * @brief UVSettingModel::getMicroscaleOpticalList
 * @return
 */
QStringList UVSettingModel::getMicroscaleOpticalList() {
    return m_pMicroscaleOpticalModel->getOpticalList();
}

/**
 * @brief UVSettingModel::getMicroscaleIntegrationTime
 * @param opticalStr
 * @return
 */
int UVSettingModel::getMicroscaleIntegrationTime(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getIntegrationTime(opticalStr);
}

/**
 * @brief UVSettingModel::getMicroscaleFrequency
 * @param opticalStr
 * @return
 */
int UVSettingModel::getMicroscaleFrequency(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getFrequency(opticalStr);
}

/**
 * @brief UVSettingModel::getMicroscaleRotateAngle
 * @param opticalStr
 * @return
 */
int UVSettingModel::getMicroscaleRotateAngle(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getRotateAngle(opticalStr);
}

/**
 * @brief UVSettingModel::getMicroscaleCorrectionFactor
 * @param opticalStr
 * @return
 */
double UVSettingModel::getMicroscaleCorrectionFactor(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getCorrectionFactor(opticalStr);
}

/**
 * @brief UVSettingModel::getMicroscaleUpperLimit
 * @return
 */
double UVSettingModel::getMicroscaleUpperLimit() {
    return m_pMicroscaleOpticalModel->getUpperLimit();
}

/**
 * @brief UVSettingModel::getMicroscaleLowerLimit
 * @return
 */
double UVSettingModel::getMicroscaleLowerLimit() {
    return m_pMicroscaleOpticalModel->getLowerLimit();
}

/**
 * @brief UVSettingModel::getMicroscaleStdOptical
 * @return
 */
QString UVSettingModel::getMicroscaleStdOptical() {
    return m_pMicroscaleOpticalModel->getStdOptical();
}

/**
 * @brief UVSettingModel::getMicroscaleMaxOptical
 * @return
 */
QString UVSettingModel::getMicroscaleMaxOptical() {
    return m_pMicroscaleOpticalModel->getMaxOptical();
}

/**
 * @brief UVSettingModel::getMicroscaleMinOptical
 * @return
 */
QString UVSettingModel::getMicroscaleMinOptical() {
    return m_pMicroscaleOpticalModel->getMinOptical();
}

/**
 * @brief UVSettingModel::getCuvetteIntegrationTime
 * @return
 */
int UVSettingModel::getCuvetteIntegrationTime() {
    return m_pCuvetteOpticalModel->getIntegrationTime();
}

/**
 * @brief UVSettingModel::getCuvetteFrequency
 * @return
 */
int UVSettingModel::getCuvetteFrequency() {
    return m_pCuvetteOpticalModel->getFrequency();
}

/**
 * @brief UVSettingModel::getCuvetteCorrectionFactor
 * @return
 */
int UVSettingModel::getCuvetteCorrectionFactor() {
    return m_pCuvetteOpticalModel->getCorrectionFactor();
}

