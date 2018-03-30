#include "dyparameterwidget.h"
#include "ui_dyparameterwidget.h"

#include <QDir>
#include <QDebug>
#include <QListView>
#include <QSettings>
#include "omessageboxutil.h"

DYParameterWidget::DYParameterWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DYParameterWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

DYParameterWidget::~DYParameterWidget() {
    delete ui;
}

/**
 * @brief DYParameterWidget::getMeasureSetting
 * @return
 */
QStringList DYParameterWidget::getMeasureSetting() {

    QStringList result;
    foreach (QWidget *w, m_measureSetting) {
        if (w->inherits( "QComboBox" )) {
            QComboBox *cBox = (QComboBox *)w;
            result.append( cBox->currentText() );
        } else if (w->inherits( "QSpinBox" )) {
            QSpinBox *sBox = (QSpinBox *)w;
            result.append( QString::number( sBox->value() ) );
        } else if (w->inherits( "QLineEdit" )) {
            QLineEdit *lineEdit = (QLineEdit *)w;
            result.append( lineEdit->text() );
        } else if (w->inherits( "QDoubleSpinBox" )) {
            QDoubleSpinBox *sBox = (QDoubleSpinBox *)w;
            result.append( QString::number( sBox->value() ) );
        }
    }
    return result;
}

/**
 * @brief DYParameterWidget::setMeasureSetting
 * @param data
 */
void DYParameterWidget::setMeasureSetting(QStringList data) {

    for (int i = 0; i < data.size(); i ++) {
        QString s = data.at(i);
        QWidget *w = m_measureSetting.at(i);
        if (w->inherits( "QComboBox" )) {
            QComboBox *cBox = (QComboBox *)w;
            cBox->setCurrentText( s );
        } else if (w->inherits( "QSpinBox" )) {
            QSpinBox *sBox = (QSpinBox *)w;
            sBox->setValue( s.toInt() );
        } else if (w->inherits( "QLineEdit" )) {
            QLineEdit *lineEdit = (QLineEdit *)w;
            lineEdit->setText( s );
        } else if (w->inherits( "QDoubleSpinBox" )) {
            QDoubleSpinBox *sBox = (QDoubleSpinBox *)w;
            sBox->setValue( s.toDouble() );
        }
    }
}

/**
 * @brief DYParameterWidget::getMotorSetting
 * @return
 */
QStringList DYParameterWidget::getMotorSetting() {

    QStringList result;
    foreach (QWidget *w, m_motorSetting) {
        if (w->inherits( "QComboBox" )) {
            QComboBox *cBox = (QComboBox *)w;
            result.append( QString::number( cBox->currentIndex() ) );
        } else if (w->inherits( "QSpinBox" )) {
            QSpinBox *sBox = (QSpinBox *)w;
            result.append( QString::number( sBox->value() ) );
        }
    }
    return result;
}

/**
 * @brief DYParameterWidget::setMotorSetting
 * @param data
 */
void DYParameterWidget::setMotorSetting(QStringList data) {
    for (int i = 0; i < data.size(); i ++) {
        QString s = data.at(i);
        QWidget *w = m_motorSetting.at(i);
        if (w->inherits( "QComboBox" )) {
            QComboBox *cBox = (QComboBox *)w;
            cBox->setCurrentIndex( s.toInt() );
        } else if (w->inherits( "QSpinBox" )) {
            QSpinBox *sBox = (QSpinBox *)w;
            sBox->setValue( s.toInt() );
        }
    }
}

/**
 * @brief DYParameterWidget::restore
 */
void DYParameterWidget::restore() {

    int result = OMessageBoxUtil::staticNotice( 0,
                                                tr("Are you sure to restore?"),
                                                QStringList() << tr( "OK" ) << tr( "Cancel" ) );
    if (result != 0) {
        return;
    }

    ui->comboBoxDetectionMothed->setCurrentIndex( 0 );
    ui->comboBoxMeasureOptical->setCurrentIndex( 0 );

    ui->spinBoxBwl->setValue( m_bwl );
    ui->spinBoxMwl->setValue( m_mwl );
    ui->doubleSpinBoxTarget->setValue(m_targetValue);
    ui->spinBoxIncubationCount->setValue( m_incubationCount );

    ui->spinBoxSubWaveLength1->setValue( m_swl1 );
    ui->spinBoxSubWaveLength1->setValue( m_swl2 );
    ui->spinBoxSubWaveLength1->setValue( m_swl3 );
    ui->spinBoxSubWaveLength1->setValue( m_swl4 );

    ui->comboBoxMixingLevel->setCurrentIndex( 0 );
    ui->spinBoxMixingTime->setValue( m_mixingTime );
    ui->spinBoxStaticTime->setValue( m_staticTime );
}

/**
 * @brief DYParameterWidget::initializeSignals
 */
void DYParameterWidget::initializeSignals() {

}

/**
 * @brief DYParameterWidget::initializeWidgets
 */
void DYParameterWidget::initializeWidgets() {

    QString fileName = QDir::currentPath() + "/configs/dynamics/dynamics.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);

    m_detectionMethods = configIniReader->value("Setting/DetectionMethod").toStringList();
    ui->comboBoxDetectionMothed->setView( new QListView() );
    ui->comboBoxDetectionMothed->addItems( m_detectionMethods );

    m_bwl = configIniReader->value("Setting/BaseWaveLength").toInt();
    m_mwl = configIniReader->value("Setting/MainWaveLength").toInt();
    ui->spinBoxBwl->setValue( m_bwl );
    ui->spinBoxMwl->setValue( m_mwl );

    m_cuvetteOpticals = configIniReader->value("Setting/CuvetteOptical").toStringList();
    ui->comboBoxMeasureOptical->setView( new QListView() );
    ui->comboBoxMeasureOptical->addItems( ui->comboBoxDetectionMothed->currentText() ==
                                          "Microscale"?QStringList():m_cuvetteOpticals );

    m_targetValue = configIniReader->value("Setting/TargetValue").toDouble();
    ui->doubleSpinBoxTarget->setValue(m_targetValue);

    m_incubationCount = configIniReader->value("Setting/IncubationCount").toInt();
    ui->spinBoxIncubationCount->setValue( m_incubationCount );

    m_swl1 = configIniReader->value("Setting/SubWaveLength1").toDouble();
    m_swl2 = configIniReader->value("Setting/SubWaveLength2").toDouble();
    m_swl3 = configIniReader->value("Setting/SubWaveLength3").toDouble();
    m_swl4 = configIniReader->value("Setting/SubWaveLength4").toDouble();
    ui->spinBoxSubWaveLength1->setValue( m_swl1 );
    ui->spinBoxSubWaveLength2->setValue( m_swl2 );
    ui->spinBoxSubWaveLength3->setValue( m_swl3 );
    ui->spinBoxSubWaveLength4->setValue( m_swl4 );

    m_mixingLevels = configIniReader->value("Setting/MixingLevel").toStringList();
    ui->comboBoxMixingLevel->setView( new QListView() );
    ui->comboBoxMixingLevel->addItems( m_mixingLevels );

    m_mixingTime = configIniReader->value("Setting/MixingTime").toInt();
    m_staticTime = configIniReader->value("Setting/StaticTime").toInt();
    ui->spinBoxMixingTime->setValue( m_mixingTime );
    ui->spinBoxStaticTime->setValue( m_staticTime );

    m_motor << ui->labelMixingLevel << ui->comboBoxMixingLevel << ui->labelMixingTime
            << ui->spinBoxMixingTime << ui->labelStaticTime << ui->spinBoxStaticTime;
    foreach (QWidget *w, m_motor) {
        w->setVisible(ui->comboBoxDetectionMothed->currentText() == "Cuvette");
    }

    m_motorSetting << ui->comboBoxMixingLevel << ui->spinBoxMixingTime << ui->spinBoxStaticTime;
    m_measureSetting << ui->comboBoxDetectionMothed << ui->lineEditSampleName << ui->spinBoxBwl
                     << ui->spinBoxMwl << ui->doubleSpinBoxTarget << ui->spinBoxIncubationCount
                     << ui->spinBoxSubWaveLength1 << ui->spinBoxSubWaveLength2 << ui->spinBoxSubWaveLength3
                     << ui->spinBoxSubWaveLength4 << ui->comboBoxMeasureOptical;

    delete configIniReader;
    configIniReader = NULL;
}
