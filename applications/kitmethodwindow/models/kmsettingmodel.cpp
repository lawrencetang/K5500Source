#include "kmsettingmodel.h"
#include "cuvetteopticalmodel.h"
#include "microscaleopticalmodel.h"

//#define PROFILE "/configs/kitmethod/kitmethod.ini"
#define PROFILE "/configs/optical.ini"

KMSettingModel::KMSettingModel(QStringList measureParameters,
                           QStringList motorParameters, int maxChannelNumber) {

    m_pCuvetteOpticalModel = new CuvetteOpticalModel(PROFILE);
    m_pMicroscaleOpticalModel = new MicroscaleOpticalModel(PROFILE);
    m_maxChannelNumber = maxChannelNumber;

    setMeasureParameters( measureParameters );
    setMotorParameters( motorParameters );
}

KMSettingModel::~KMSettingModel() {
    delete m_pCuvetteOpticalModel;
    delete m_pMicroscaleOpticalModel;
}

/**
 * @brief KMSettingModel::setMeasureParameters
 * @param settings
 */
void KMSettingModel::setMeasureParameters(QStringList settings) {

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
            m_order = str.toInt();
            break;
        }
    }
}

/**
 * @brief KMSettingModel::setMotorParameters
 * @param settings
 */
void KMSettingModel::setMotorParameters(QStringList settings) {

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
 * @brief KMSettingModel::getIdList
 * @return
 */
QList<int> KMSettingModel::getIdList() {
    QList<int> result;
    for(int i = 0; i < m_channelNumber; i++) {
        result.append(i);
    }
    return result;
}

/**
 * @brief KMSettingModel::getMicroscaleOpticalList
 * @return
 */
QStringList KMSettingModel::getMicroscaleOpticalList() {
    return m_pMicroscaleOpticalModel->getOpticalList();
}

/**
 * @brief KMSettingModel::getMicroscaleIntegrationTime
 * @param opticalStr
 * @return
 */
int KMSettingModel::getMicroscaleIntegrationTime(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getIntegrationTime(opticalStr);
}

/**
 * @brief KMSettingModel::getMicroscaleFrequency
 * @param opticalStr
 * @return
 */
int KMSettingModel::getMicroscaleFrequency(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getFrequency(opticalStr);
}

/**
 * @brief KMSettingModel::getMicroscaleRotateAngle
 * @param opticalStr
 * @return
 */
int KMSettingModel::getMicroscaleRotateAngle(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getRotateAngle(opticalStr);
}

/**
 * @brief KMSettingModel::getMicroscaleCorrectionFactor
 * @param opticalStr
 * @return
 */
double KMSettingModel::getMicroscaleCorrectionFactor(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getCorrectionFactor(opticalStr);
}

/**
 * @brief KMSettingModel::getMicroscaleUpperLimit
 * @return
 */
double KMSettingModel::getMicroscaleUpperLimit() {
    return m_pMicroscaleOpticalModel->getUpperLimit();
}

/**
 * @brief KMSettingModel::getMicroscaleLowerLimit
 * @return
 */
double KMSettingModel::getMicroscaleLowerLimit() {
    return m_pMicroscaleOpticalModel->getLowerLimit();
}

/**
 * @brief KMSettingModel::getMicroscaleStdOptical
 * @return
 */
QString KMSettingModel::getMicroscaleStdOptical() {
    return m_pMicroscaleOpticalModel->getStdOptical();
}

/**
 * @brief KMSettingModel::getMicroscaleMaxOptical
 * @return
 */
QString KMSettingModel::getMicroscaleMaxOptical() {
    return m_pMicroscaleOpticalModel->getMaxOptical();
}

/**
 * @brief KMSettingModel::getMicroscaleMinOptical
 * @return
 */
QString KMSettingModel::getMicroscaleMinOptical() {
    return m_pMicroscaleOpticalModel->getMinOptical();
}

/**
 * @brief KMSettingModel::getCuvetteIntegrationTime
 * @return
 */
int KMSettingModel::getCuvetteIntegrationTime() {
    return m_pCuvetteOpticalModel->getIntegrationTime();
}

/**
 * @brief KMSettingModel::getCuvetteFrequency
 * @return
 */
int KMSettingModel::getCuvetteFrequency() {
    return m_pCuvetteOpticalModel->getFrequency();
}

/**
 * @brief KMSettingModel::getCuvetteCorrectionFactor
 * @return
 */
int KMSettingModel::getCuvetteCorrectionFactor() {
    return m_pCuvetteOpticalModel->getCorrectionFactor();
}

