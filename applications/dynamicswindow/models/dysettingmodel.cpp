#include "dysettingmodel.h"
#include "cuvetteopticalmodel.h"

//#define PROFILE "/configs/dynamics/dynamics.ini"
#define PROFILE "/configs/optical.ini"

DYSettingModel::DYSettingModel(QStringList measureParameters,
                               QStringList motorParameters) {

    m_pCuvetteOpticalModel = new CuvetteOpticalModel(PROFILE);
    setMeasureParameters( measureParameters );
    setMotorParameters( motorParameters );
}

DYSettingModel::~DYSettingModel() {
    delete m_pCuvetteOpticalModel;
}

/**
 * @brief DYSettingModel::setMeasureParameters
 * @param settings
 */
void DYSettingModel::setMeasureParameters(QStringList settings) {

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
            m_targetValue = str.toDouble();
            break;
        case 5:
            m_incubationCount = str.toInt();
            break;
        case 6:
            m_swl1 = str.toInt();
            break;
        case 7:
            m_swl2 = str.toInt();
            break;
        case 8:
            m_swl3 = str.toInt();
            break;
        case 9:
            m_swl4 = str.toInt();
            break;
        case 10:
            m_opticalStr = str;
            break;
        }
    }
}

/**
 * @brief DYSettingModel::setMotorParameters
 * @param settings
 */
void DYSettingModel::setMotorParameters(QStringList settings) {

    for (int i = 0; i < settings.size(); i ++) {
        QString str = settings.at(i);
        switch(i) {
        case 0:
            m_mixingLevel = str.toInt() + 1;
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
 * @brief DYSettingModel::getCuvetteIntegrationTime
 * @return
 */
int DYSettingModel::getCuvetteIntegrationTime() {
    return m_pCuvetteOpticalModel->getIntegrationTime();
}

/**
 * @brief DYSettingModel::getCuvetteFrequency
 * @return
 */
int DYSettingModel::getCuvetteFrequency() {
    return m_pCuvetteOpticalModel->getFrequency();
}

/**
 * @brief DYSettingModel::getCuvetteCorrectionFactor
 * @return
 */
int DYSettingModel::getCuvetteCorrectionFactor() {
    return m_pCuvetteOpticalModel->getCorrectionFactor();
}

