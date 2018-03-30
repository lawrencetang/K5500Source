#include "microscaleopticalmodel.h"

#include <QDir>
#include <QSettings>

MicroscaleOpticalModel::MicroscaleOpticalModel(QString fileName, QObject *parent) :
    QObject(parent) {
    m_fileName = QDir::currentPath() + fileName;
    initialize();
}

MicroscaleOpticalModel::~MicroscaleOpticalModel() {

}

/**
 * @brief MicroscaleOpticalModel::getStdOptical
 * @return
 */
QString MicroscaleOpticalModel::getStdOptical() {

    QString result = "";
    if (!m_opticalList.isEmpty()) {
        result = m_opticalList.first();
    }
    return result;
}

/**
 * @brief MicroscaleOpticalModel::getMaxOptical
 * @return
 */
QString MicroscaleOpticalModel::getMaxOptical() {

    QString result = "";
    if (!m_opticalList.isEmpty()) {
        result = m_opticalList.last();
    }
    return result;
}

/**
 * @brief MicroscaleOpticalModel::getMinOptical
 * @return
 */
QString MicroscaleOpticalModel::getMinOptical() {

    QString result = "";
    if (m_opticalList.size() > 1) {
        result = m_opticalList.at(1);
    }
    return result;
}

/**
 * @brief MicroscaleOpticalModel::getIntegrationTime
 * @param opticalStr
 * @return
 */
int MicroscaleOpticalModel::getIntegrationTime(QString opticalStr) {

    int result = 40000;
    if (m_opticalList.contains(opticalStr)) {
        int index = m_opticalList.indexOf(opticalStr);
        QString integrationTimeStr;
        if (index < m_opticalList.size()) {
            integrationTimeStr = m_integrationTimeList.at(index);
        }
        bool ok = false;
        result = integrationTimeStr.toInt(&ok);
        if (!ok) {
            result = 40000;
        }
    }
    return result;
}

/**
 * @brief MicroscaleOpticalModel::getFrequency
 * @param opticalStr
 * @return
 */
int MicroscaleOpticalModel::getFrequency(QString opticalStr) {

    int result = 100;
    if (m_opticalList.contains(opticalStr)) {
        int index = m_opticalList.indexOf(opticalStr);
        QString frequencyStr;
        if (index < m_opticalList.size()) {
            frequencyStr = m_frequencyList.at(index);
        }
        bool ok = false;
        result = frequencyStr.toInt(&ok);
        if (!ok) {
            result = 100;
        }
    }
    return result;
}

/**
 * @brief MicroscaleOpticalModel::getRotateAngle
 * @param opticalStr
 * @return
 */
int MicroscaleOpticalModel::getRotateAngle(QString opticalStr) {

    int result = 0;
    if (m_opticalList.contains(opticalStr)) {
        int index = m_opticalList.indexOf(opticalStr);
        QString rotateAngleStr;
        if (index < m_opticalList.size()) {
            rotateAngleStr = m_rotateAngleList.at(index);
        }
        bool ok = false;
        result = rotateAngleStr.toInt(&ok);
        if (!ok) {
            result = 0;
        }
    }
    return result;
}

/**
 * @brief MicroscaleOpticalModel::getCorrectionFactor
 * @param opticalStr
 * @return
 */
double MicroscaleOpticalModel::getCorrectionFactor(QString opticalStr) {

    double result = 1.0;
    if (m_opticalList.contains(opticalStr)) {
        int index = m_opticalList.indexOf(opticalStr);
        QString correctionFactorStr;
        if (index < m_opticalList.size()) {
            correctionFactorStr = m_correctionFactorList.at(index);
        }
        bool ok = false;
        result = correctionFactorStr.toDouble(&ok);
        if (!ok) {
            result = 1.0;
        }
    }
    return result;
}

/**
 * @brief MicroscaleOpticalModel::reset
 */
void MicroscaleOpticalModel::reset() {
    clear();
    initialize();
}

/**
 * @brief MicroscaleOpticalModel::clear
 */
void MicroscaleOpticalModel::clear() {
    m_opticalList.clear();
    m_integrationTimeList.clear();
    m_frequencyList.clear();
    m_rotateAngleList.clear();
    m_correctionFactorList.clear();
    m_upperLimit = 0;
    m_lowerLimit = 0;
}


/**
 * @brief MicroscaleOpticalModel::load
 */
void MicroscaleOpticalModel::initialize() {

    QSettings *configIniReader = new QSettings(m_fileName, QSettings::IniFormat);
    m_opticalList = configIniReader->value( "Microscale/Optical" ).toStringList();
    m_integrationTimeList = configIniReader->value( "Microscale/IntegrationTime" ).toStringList();
    m_frequencyList = configIniReader->value( "Microscale/Frequency" ).toStringList();
    m_rotateAngleList = configIniReader->value( "Microscale/RotateAngle" ).toStringList();
    m_correctionFactorList = configIniReader->value( "Microscale/CorrectionFactor" ).toStringList();

    m_upperLimit = configIniReader->value( "Microscale/UpperLimit" ).toDouble();
    m_lowerLimit = configIniReader->value( "Microscale/LowerLimit" ).toDouble();

    delete configIniReader;
    configIniReader = NULL;
}
