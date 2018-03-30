#include "nasettingmodel.h"
#include "cuvetteopticalmodel.h"
#include "microscaleopticalmodel.h"

#define PROFILE "/configs/optical.ini"

NASettingModel::NASettingModel(QStringList measureParameters,
                           QStringList motorParameters, int maxChannelNumber) {

    m_pCuvetteOpticalModel = new CuvetteOpticalModel(PROFILE);
    m_pMicroscaleOpticalModel = new MicroscaleOpticalModel(PROFILE);
    m_maxChannelNumber = maxChannelNumber;

    setMeasureParameters( measureParameters );
    setMotorParameters( motorParameters );
}

NASettingModel::~NASettingModel() {
    delete m_pCuvetteOpticalModel;
    delete m_pMicroscaleOpticalModel;
}

/**
 * @brief NASettingModel::setMeasureParameters
 * @param settings
 */
void NASettingModel::setMeasureParameters(QStringList settings) {

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
            m_mwl = str.toInt();
            break;
        case 4:
            m_channelNumber = str.toInt();
            break;
        case 5:
            m_opticalStr = str;
            break;
        case 6:
            m_unit = str;
            break;
        case 7:
            m_method = str;
            break;
        case 8:
            m_coefficient = str.toDouble();
            break;
        }
    }
}

/**
 * @brief NASettingModel::setMotorParameters
 * @param settings
 */
void NASettingModel::setMotorParameters(QStringList settings) {

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
 * @brief NASettingModel::getIdList
 * @return
 */
QList<int> NASettingModel::getIdList() {
    QList<int> result;
    for(int i = 0; i < m_channelNumber; i++) {
        result.append(i);
    }
    return result;
}

/**
 * @brief NASettingModel::getMicroscaleOpticalList
 * @return
 */
QStringList NASettingModel::getMicroscaleOpticalList() {
    return m_pMicroscaleOpticalModel->getOpticalList();
}

/**
 * @brief NASettingModel::getMicroscaleIntegrationTime
 * @param opticalStr
 * @return
 */
int NASettingModel::getMicroscaleIntegrationTime(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getIntegrationTime(opticalStr);
}

/**
 * @brief NASettingModel::getMicroscaleFrequency
 * @param opticalStr
 * @return
 */
int NASettingModel::getMicroscaleFrequency(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getFrequency(opticalStr);
}

/**
 * @brief NASettingModel::getMicroscaleRotateAngle
 * @param opticalStr
 * @return
 */
int NASettingModel::getMicroscaleRotateAngle(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getRotateAngle(opticalStr);
}

/**
 * @brief NASettingModel::getMicroscaleCorrectionFactor
 * @param opticalStr
 * @return
 */
double NASettingModel::getMicroscaleCorrectionFactor(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getCorrectionFactor(opticalStr);
}

/**
 * @brief NASettingModel::getMicroscaleUpperLimit
 * @return
 */
double NASettingModel::getMicroscaleUpperLimit() {
    return m_pMicroscaleOpticalModel->getUpperLimit();
}

/**
 * @brief NASettingModel::getMicroscaleLowerLimit
 * @return
 */
double NASettingModel::getMicroscaleLowerLimit() {
    return m_pMicroscaleOpticalModel->getLowerLimit();
}

/**
 * @brief NASettingModel::getMicroscaleStdOptical
 * @return
 */
QString NASettingModel::getMicroscaleStdOptical() {
    return m_pMicroscaleOpticalModel->getStdOptical();
}

/**
 * @brief NASettingModel::getMicroscaleMaxOptical
 * @return
 */
QString NASettingModel::getMicroscaleMaxOptical() {
    return m_pMicroscaleOpticalModel->getMaxOptical();
}

/**
 * @brief NASettingModel::getMicroscaleMinOptical
 * @return
 */
QString NASettingModel::getMicroscaleMinOptical() {
    return m_pMicroscaleOpticalModel->getMinOptical();
}

/**
 * @brief NASettingModel::getCuvetteIntegrationTime
 * @return
 */
int NASettingModel::getCuvetteIntegrationTime() {
    return m_pCuvetteOpticalModel->getIntegrationTime();
}

/**
 * @brief NASettingModel::getCuvetteFrequency
 * @return
 */
int NASettingModel::getCuvetteFrequency() {
    return m_pCuvetteOpticalModel->getFrequency();
}

/**
 * @brief NASettingModel::getCuvetteCorrectionFactor
 * @return
 */
int NASettingModel::getCuvetteCorrectionFactor() {
    return m_pCuvetteOpticalModel->getCorrectionFactor();
}

