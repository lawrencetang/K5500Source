#include "masettingmodel.h"
#include "cuvetteopticalmodel.h"
#include "microscaleopticalmodel.h"

//#define PROFILE "/configs/microarray/microarray.ini"
#define PROFILE "/configs/optical.ini"

MASettingModel::MASettingModel(QStringList measureParameters, QStringList motorParameters,
                               QList<QStringList> dyeInfomations, int maxChannelNumber) {

    m_pCuvetteOpticalModel = new CuvetteOpticalModel(PROFILE);
    m_pMicroscaleOpticalModel = new MicroscaleOpticalModel(PROFILE);
    m_maxChannelNumber = maxChannelNumber;

    setMeasureParameters( measureParameters );
    setMotorParameters( motorParameters );
    setDyeInfoList( dyeInfomations );
}

MASettingModel::~MASettingModel() {
    delete m_pCuvetteOpticalModel;
    delete m_pMicroscaleOpticalModel;
}

/**
 * @brief MASettingModel::setMeasureParameters
 * @param settings
 */
void MASettingModel::setMeasureParameters(QStringList settings) {

    for (int i = 0; i < settings.size(); i ++) {
        QString str = settings.at(i);
        switch(i) {
        case 0:
            m_detectionMethod = str;
            break;
        case 1:
            m_detectionMatter = str;
            break;
        case 2:
            m_sampleName = str;
            break;
        case 3:
            m_bwl = str.toInt();
            break;
        case 4:
            m_mwl = str.toInt();
            break;
        case 5:
            m_channelNumber = str.toInt();
            break;
        case 6:
            m_opticalStr = str;
            break;
        case 7:
            m_unit = str;
            break;
        case 8:
            m_method = str;
            break;
        case 9:
            m_coefficient = str.toDouble();
            break;
        }
    }
}

/**
 * @brief MASettingModel::setMotorParameters
 * @param settings
 */
void MASettingModel::setMotorParameters(QStringList settings) {

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
 * @brief MASettingModel::setDyeInfoList
 * @param dyeInfos
 */
void MASettingModel::setDyeInfoList(QList<QStringList> dyeInfos) {
    m_dyeInfoList.clear();
    m_dyeInfoList.append(dyeInfos);
}

/**
 * @brief MASettingModel::getIdList
 * @return
 */
QList<int> MASettingModel::getIdList() {
    QList<int> result;
    for(int i = 0; i < m_channelNumber; i++) {
        result.append(i);
    }
    return result;
}

/**
 * @brief MASettingModel::getMicroscaleOpticalList
 * @return
 */
QStringList MASettingModel::getMicroscaleOpticalList() {
    return m_pMicroscaleOpticalModel->getOpticalList();
}

/**
 * @brief MASettingModel::getMicroscaleIntegrationTime
 * @param opticalStr
 * @return
 */
int MASettingModel::getMicroscaleIntegrationTime(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getIntegrationTime(opticalStr);
}

/**
 * @brief MASettingModel::getMicroscaleFrequency
 * @param opticalStr
 * @return
 */
int MASettingModel::getMicroscaleFrequency(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getFrequency(opticalStr);
}

/**
 * @brief MASettingModel::getMicroscaleRotateAngle
 * @param opticalStr
 * @return
 */
int MASettingModel::getMicroscaleRotateAngle(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getRotateAngle(opticalStr);
}

/**
 * @brief MASettingModel::getMicroscaleCorrectionFactor
 * @param opticalStr
 * @return
 */
double MASettingModel::getMicroscaleCorrectionFactor(QString opticalStr) {
    return m_pMicroscaleOpticalModel->getCorrectionFactor(opticalStr);
}

/**
 * @brief MASettingModel::getMicroscaleUpperLimit
 * @return
 */
double MASettingModel::getMicroscaleUpperLimit() {
    return m_pMicroscaleOpticalModel->getUpperLimit();
}

/**
 * @brief MASettingModel::getMicroscaleLowerLimit
 * @return
 */
double MASettingModel::getMicroscaleLowerLimit() {
    return m_pMicroscaleOpticalModel->getLowerLimit();
}

/**
 * @brief MASettingModel::getMicroscaleStdOptical
 * @return
 */
QString MASettingModel::getMicroscaleStdOptical() {
    return m_pMicroscaleOpticalModel->getStdOptical();
}

/**
 * @brief MASettingModel::getMicroscaleMaxOptical
 * @return
 */
QString MASettingModel::getMicroscaleMaxOptical() {
    return m_pMicroscaleOpticalModel->getMaxOptical();
}

/**
 * @brief MASettingModel::getMicroscaleMinOptical
 * @return
 */
QString MASettingModel::getMicroscaleMinOptical() {
    return m_pMicroscaleOpticalModel->getMinOptical();
}

/**
 * @brief MASettingModel::getCuvetteIntegrationTime
 * @return
 */
int MASettingModel::getCuvetteIntegrationTime() {
    return m_pCuvetteOpticalModel->getIntegrationTime();
}

/**
 * @brief MASettingModel::getCuvetteFrequency
 * @return
 */
int MASettingModel::getCuvetteFrequency() {
    return m_pCuvetteOpticalModel->getFrequency();
}

/**
 * @brief MASettingModel::getCuvetteCorrectionFactor
 * @return
 */
int MASettingModel::getCuvetteCorrectionFactor() {
    return m_pCuvetteOpticalModel->getCorrectionFactor();
}

