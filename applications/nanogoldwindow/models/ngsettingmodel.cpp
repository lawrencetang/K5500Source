#include "ngsettingmodel.h"
#include "cuvetteopticalmodel.h"
#include "microscaleopticalmodel.h"

//#define PROFILE "/configs/nanogold/nanogold.ini"
#define PROFILE "/configs/optical.ini"

NGSettingModel::NGSettingModel(QStringList measureParameters,
                           QStringList motorParameters, int maxChannelNumber) {

    m_pCuvetteOpticalModel = new CuvetteOpticalModel(PROFILE);
    m_pMicroscaleOpticalModel = new MicroscaleOpticalModel(PROFILE);
    m_maxChannelNumber = maxChannelNumber;

    setMeasureParameters( measureParameters );
    setMotorParameters( motorParameters );
}

NGSettingModel::~NGSettingModel() {
    delete m_pCuvetteOpticalModel;
    delete m_pMicroscaleOpticalModel;
}

/**
 * @brief NGSettingModel::setMeasureParameters
 * @param settings
 */
void NGSettingModel::setMeasureParameters(QStringList settings) {

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
 * @brief NGSettingModel::setMotorParameters
 * @param settings
 */
void NGSettingModel::setMotorParameters(QStringList settings) {

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
 * @brief NGSettingModel::getIdList
 * @return
 */
QList<int> NGSettingModel::getIdList() {
    QList<int> result;
    for(int i = 0; i < m_channelNumber; i++) {
        result.append(i);
    }
    return result;
}

/**
 * @brief NGSettingModel::getMicroscaleOpticalList
 * @return
 */
QStringList NGSettingModel::getMicroscaleOpticalList() {
    return m_pMicroscaleOpticalModel->getOpticalList();
}

/**
 * @brief NGSettingModel::getMicroscaleIntegrationTime
 * @param opticalStr
 * @return
 */
int NGSettingModel::getMicroscaleIntegrationTime(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getIntegrationTime(opticalStr);
}

/**
 * @brief NGSettingModel::getMicroscaleFrequency
 * @param opticalStr
 * @return
 */
int NGSettingModel::getMicroscaleFrequency(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getFrequency(opticalStr);
}

/**
 * @brief NGSettingModel::getMicroscaleRotateAngle
 * @param opticalStr
 * @return
 */
int NGSettingModel::getMicroscaleRotateAngle(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getRotateAngle(opticalStr);
}

/**
 * @brief NGSettingModel::getMicroscaleCorrectionFactor
 * @param opticalStr
 * @return
 */
double NGSettingModel::getMicroscaleCorrectionFactor(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getCorrectionFactor(opticalStr);
}

/**
 * @brief NGSettingModel::getMicroscaleUpperLimit
 * @return
 */
double NGSettingModel::getMicroscaleUpperLimit() {
    return m_pMicroscaleOpticalModel->getUpperLimit();
}

/**
 * @brief NGSettingModel::getMicroscaleLowerLimit
 * @return
 */
double NGSettingModel::getMicroscaleLowerLimit() {
    return m_pMicroscaleOpticalModel->getLowerLimit();
}

/**
 * @brief NGSettingModel::getMicroscaleStdOptical
 * @return
 */
QString NGSettingModel::getMicroscaleStdOptical() {
    return m_pMicroscaleOpticalModel->getStdOptical();
}

/**
 * @brief NGSettingModel::getMicroscaleMaxOptical
 * @return
 */
QString NGSettingModel::getMicroscaleMaxOptical() {
    return m_pMicroscaleOpticalModel->getMaxOptical();
}

/**
 * @brief NGSettingModel::getMicroscaleMinOptical
 * @return
 */
QString NGSettingModel::getMicroscaleMinOptical() {
    return m_pMicroscaleOpticalModel->getMinOptical();
}

/**
 * @brief NGSettingModel::getCuvetteIntegrationTime
 * @return
 */
int NGSettingModel::getCuvetteIntegrationTime() {
    return m_pCuvetteOpticalModel->getIntegrationTime();
}

/**
 * @brief NGSettingModel::getCuvetteFrequency
 * @return
 */
int NGSettingModel::getCuvetteFrequency() {
    return m_pCuvetteOpticalModel->getFrequency();
}

/**
 * @brief NGSettingModel::getCuvetteCorrectionFactor
 * @return
 */
int NGSettingModel::getCuvetteCorrectionFactor() {
    return m_pCuvetteOpticalModel->getCorrectionFactor();
}

