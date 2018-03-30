#include "ccsettingmodel.h"
#include "cuvetteopticalmodel.h"
#include "microscaleopticalmodel.h"

//#define PROFILE "/configs/cellculture/cellculture.ini"
#define PROFILE "/configs/optical.ini"

CCSettingModel::CCSettingModel(QStringList measureParameters,
                           QStringList motorParameters, int maxChannelNumber) {

    m_pCuvetteOpticalModel = new CuvetteOpticalModel(PROFILE);
    m_pMicroscaleOpticalModel = new MicroscaleOpticalModel(PROFILE);
    m_maxChannelNumber = maxChannelNumber;

    setMeasureParameters( measureParameters );
    setMotorParameters( motorParameters );
}

CCSettingModel::~CCSettingModel() {
    delete m_pCuvetteOpticalModel;
    delete m_pMicroscaleOpticalModel;
}

/**
 * @brief CCSettingModel::setMeasureParameters
 * @param settings
 */
void CCSettingModel::setMeasureParameters(QStringList settings) {

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
            m_method = str;
            break;
        case 7:
            m_coefficient = str.toDouble();
            break;
        }
    }
}

/**
 * @brief CCSettingModel::setMotorParameters
 * @param settings
 */
void CCSettingModel::setMotorParameters(QStringList settings) {

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
 * @brief CCSettingModel::getIdList
 * @return
 */
QList<int> CCSettingModel::getIdList() {
    QList<int> result;
    for(int i = 0; i < m_channelNumber; i++) {
        result.append(i);
    }
    return result;
}

/**
 * @brief CCSettingModel::getMicroscaleOpticalList
 * @return
 */
QStringList CCSettingModel::getMicroscaleOpticalList() {
    return m_pMicroscaleOpticalModel->getOpticalList();
}

/**
 * @brief CCSettingModel::getMicroscaleIntegrationTime
 * @param opticalStr
 * @return
 */
int CCSettingModel::getMicroscaleIntegrationTime(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getIntegrationTime(opticalStr);
}

/**
 * @brief CCSettingModel::getMicroscaleFrequency
 * @param opticalStr
 * @return
 */
int CCSettingModel::getMicroscaleFrequency(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getFrequency(opticalStr);
}

/**
 * @brief CCSettingModel::getMicroscaleRotateAngle
 * @param opticalStr
 * @return
 */
int CCSettingModel::getMicroscaleRotateAngle(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getRotateAngle(opticalStr);
}

/**
 * @brief CCSettingModel::getMicroscaleCorrectionFactor
 * @param opticalStr
 * @return
 */
double CCSettingModel::getMicroscaleCorrectionFactor(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getCorrectionFactor(opticalStr);
}

/**
 * @brief CCSettingModel::getMicroscaleUpperLimit
 * @return
 */
double CCSettingModel::getMicroscaleUpperLimit() {
    return m_pMicroscaleOpticalModel->getUpperLimit();
}

/**
 * @brief CCSettingModel::getMicroscaleLowerLimit
 * @return
 */
double CCSettingModel::getMicroscaleLowerLimit() {
    return m_pMicroscaleOpticalModel->getLowerLimit();
}

/**
 * @brief CCSettingModel::getMicroscaleStdOptical
 * @return
 */
QString CCSettingModel::getMicroscaleStdOptical() {
    return m_pMicroscaleOpticalModel->getStdOptical();
}

/**
 * @brief CCSettingModel::getMicroscaleMaxOptical
 * @return
 */
QString CCSettingModel::getMicroscaleMaxOptical() {
    return m_pMicroscaleOpticalModel->getMaxOptical();
}

/**
 * @brief CCSettingModel::getMicroscaleMinOptical
 * @return
 */
QString CCSettingModel::getMicroscaleMinOptical() {
    return m_pMicroscaleOpticalModel->getMinOptical();
}

/**
 * @brief CCSettingModel::getCuvetteIntegrationTime
 * @return
 */
int CCSettingModel::getCuvetteIntegrationTime() {
    return m_pCuvetteOpticalModel->getIntegrationTime();
}

/**
 * @brief CCSettingModel::getCuvetteFrequency
 * @return
 */
int CCSettingModel::getCuvetteFrequency() {
    return m_pCuvetteOpticalModel->getFrequency();
}

/**
 * @brief CCSettingModel::getCuvetteCorrectionFactor
 * @return
 */
int CCSettingModel::getCuvetteCorrectionFactor() {
    return m_pCuvetteOpticalModel->getCorrectionFactor();
}

