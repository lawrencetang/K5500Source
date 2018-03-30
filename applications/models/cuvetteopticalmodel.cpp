#include "cuvetteopticalmodel.h"

#include <QDir>
#include <QSettings>

CuvetteOpticalModel::CuvetteOpticalModel(QString fileName, QObject *parent) :
    QObject(parent) {
    m_fileName = QDir::currentPath() + fileName;
    initialize();
}

CuvetteOpticalModel::~CuvetteOpticalModel() {

}

/**
 * @brief CuvetteOpticalModel::reset
 */
void CuvetteOpticalModel::reset() {
    clear();
    initialize();
}

/**
 * @brief CuvetteOpticalModel::clear
 */
void CuvetteOpticalModel::clear() {
    m_opticalList.clear();
    m_integrationTime = "40000";
    m_frequency = "100";
    m_correctionFactor = "1";
}

/**
 * @brief CuvetteOpticalModel::initialize
 */
void CuvetteOpticalModel::initialize() {

    QSettings *configIniReader = new QSettings(m_fileName, QSettings::IniFormat);
    m_opticalList = configIniReader->value( "Cuvette/Optical" ).toStringList();
    m_integrationTime = configIniReader->value( "Cuvette/IntegrationTime" ).toString();
    m_frequency = configIniReader->value( "Cuvette/Frequency" ).toString();
    m_correctionFactor = configIniReader->value( "Cuvette/CorrectionFactor" ).toString();
    delete configIniReader;
    configIniReader = NULL;
}
