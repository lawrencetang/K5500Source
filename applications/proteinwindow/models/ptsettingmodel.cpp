#include "ptsettingmodel.h"
#include "cuvetteopticalmodel.h"
#include "microscaleopticalmodel.h"

//#define PROFILE "/configs/protein/protein.ini"
#define PROFILE "/configs/optical.ini"

PTSettingModel::PTSettingModel(QStringList measureParameters,
                           QStringList motorParameters, int maxChannelNumber) {

    m_pCuvetteOpticalModel = new CuvetteOpticalModel(PROFILE);
    m_pMicroscaleOpticalModel = new MicroscaleOpticalModel(PROFILE);
    m_maxChannelNumber = maxChannelNumber;

    setMeasureParameters( measureParameters );
    setMotorParameters( motorParameters );
}

PTSettingModel::~PTSettingModel() {
    delete m_pCuvetteOpticalModel;
    delete m_pMicroscaleOpticalModel;
}

/**
 * @brief PTSettingModel::setMeasureParameters
 * @param settings
 */
void PTSettingModel::setMeasureParameters(QStringList settings) {

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
 * @brief PTSettingModel::setMotorParameters
 * @param settings
 */
void PTSettingModel::setMotorParameters(QStringList settings) {

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
 * @brief PTSettingModel::getIdList
 * @return
 */
QList<int> PTSettingModel::getIdList() {
    QList<int> result;
    for(int i = 0; i < m_channelNumber; i++) {
        result.append(i);
    }
    return result;
}

/**
 * @brief PTSettingModel::getMicroscaleOpticalList
 * @return
 */
QStringList PTSettingModel::getMicroscaleOpticalList() {
    return m_pMicroscaleOpticalModel->getOpticalList();
}

/**
 * @brief PTSettingModel::getMicroscaleIntegrationTime
 * @param opticalStr
 * @return
 */
int PTSettingModel::getMicroscaleIntegrationTime(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getIntegrationTime(opticalStr);
}

/**
 * @brief PTSettingModel::getMicroscaleFrequency
 * @param opticalStr
 * @return
 */
int PTSettingModel::getMicroscaleFrequency(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getFrequency(opticalStr);
}

/**
 * @brief PTSettingModel::getMicroscaleRotateAngle
 * @param opticalStr
 * @return
 */
int PTSettingModel::getMicroscaleRotateAngle(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getRotateAngle(opticalStr);
}

/**
 * @brief PTSettingModel::getMicroscaleCorrectionFactor
 * @param opticalStr
 * @return
 */
double PTSettingModel::getMicroscaleCorrectionFactor(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getCorrectionFactor(opticalStr);
}

/**
 * @brief PTSettingModel::getMicroscaleUpperLimit
 * @return
 */
double PTSettingModel::getMicroscaleUpperLimit() {
    return m_pMicroscaleOpticalModel->getUpperLimit();
}

/**
 * @brief PTSettingModel::getMicroscaleLowerLimit
 * @return
 */
double PTSettingModel::getMicroscaleLowerLimit() {
    return m_pMicroscaleOpticalModel->getLowerLimit();
}

/**
 * @brief PTSettingModel::getMicroscaleStdOptical
 * @return
 */
QString PTSettingModel::getMicroscaleStdOptical() {
    return m_pMicroscaleOpticalModel->getStdOptical();
}

/**
 * @brief PTSettingModel::getMicroscaleMaxOptical
 * @return
 */
QString PTSettingModel::getMicroscaleMaxOptical() {
    return m_pMicroscaleOpticalModel->getMaxOptical();
}

/**
 * @brief PTSettingModel::getMicroscaleMinOptical
 * @return
 */
QString PTSettingModel::getMicroscaleMinOptical() {
    return m_pMicroscaleOpticalModel->getMinOptical();
}

/**
 * @brief PTSettingModel::getCuvetteIntegrationTime
 * @return
 */
int PTSettingModel::getCuvetteIntegrationTime() {
    return m_pCuvetteOpticalModel->getIntegrationTime();
}

/**
 * @brief PTSettingModel::getCuvetteFrequency
 * @return
 */
int PTSettingModel::getCuvetteFrequency() {
    return m_pCuvetteOpticalModel->getFrequency();
}

/**
 * @brief PTSettingModel::getCuvetteCorrectionFactor
 * @return
 */
int PTSettingModel::getCuvetteCorrectionFactor() {
    return m_pCuvetteOpticalModel->getCorrectionFactor();
}

