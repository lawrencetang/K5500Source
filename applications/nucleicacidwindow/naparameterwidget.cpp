#include "naparameterwidget.h"
#include "ui_naparameterwidget.h"

#include <QDir>
#include <QDebug>
#include <QListView>
#include <QSettings>
#include "omessageboxutil.h"

NAParameterWidget::NAParameterWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::NAParameterWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

NAParameterWidget::~NAParameterWidget() {
    delete ui;
}

/**
 * @brief NAParameterWidget::getMeasureSetting
 * @return
 */
QStringList NAParameterWidget::getMeasureSetting() {

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
 * @brief NAParameterWidget::setMeasureSetting
 * @param data
 */
void NAParameterWidget::setMeasureSetting(QStringList data) {

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
 * @brief NAParameterWidget::getMotorSetting
 * @return
 */
QStringList NAParameterWidget::getMotorSetting() {

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
 * @brief NAParameterWidget::setMotorSetting
 * @param data
 */
void NAParameterWidget::setMotorSetting(QStringList data) {
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
 * @brief NAParameterWidget::getCurrentMethod
 */
QString NAParameterWidget::getCurrentMethod() {
    return ui->comboBoxMethod->currentText();
}

/**
 * @brief NAParameterWidget::restore
 */
void NAParameterWidget::restore() {

    int result = OMessageBoxUtil::staticNotice( 0,
                                                tr("Are you sure to restore?"),
                                                QStringList() << tr( "OK" ) << tr( "Cancel" ) );
    if (result != 0) {
        return;
    }

    ui->comboBoxDetectionMothed->setCurrentIndex( 0 );
    ui->spinBoxChannelNumber->setValue( ui->spinBoxChannelNumber->maximum() );
    ui->comboBoxMethod->setCurrentIndex( 0 );
    ui->spinBoxBwl->setValue( m_bwl );
    ui->spinBoxMwl->setValue( m_mwl );
    ui->comboBoxUnit->setCurrentIndex( 0 );
    ui->comboBoxMixingLevel->setCurrentIndex( 0 );
    ui->comboBoxMeasureOptical->setCurrentIndex( 0 );
    ui->spinBoxMixingTime->setValue( 0 );
    ui->spinBoxStaticTime->setValue( 0 );
}

/**
 * @brief NAParameterWidget::changeCofficient
 * @param index
 */
void NAParameterWidget::changeCofficient(int index) {

    ui->doubleSpinBoxCoefficient->setReadOnly(true);
    if (ui->comboBoxMethod->itemText(index) == "Custom") {
        ui->doubleSpinBoxCoefficient->setReadOnly(false);
    }
    QString confficient = m_coefficients.at(index);
    ui->doubleSpinBoxCoefficient->setValue(confficient.toDouble());
}

/**
 * @brief NAParameterWidget::changeDetectionMothed
 * @param method
 */
void NAParameterWidget::changeDetectionMothed(QString method) {

    bool ok = false;
    ui->comboBoxMeasureOptical->clear();
    if (method == "Cuvette") {
        ok = true;
        ui->comboBoxMeasureOptical->addItems( m_cuvetteOpticals );
    } else {
        ui->comboBoxMeasureOptical->addItems( m_microscaleOpticals );
    }
    foreach (QWidget *w, m_motor) {
        w->setVisible(ok);
    }
}

/**
 * @brief NAParameterWidget::initializeSignals
 */
void NAParameterWidget::initializeSignals() {
    connect(ui->comboBoxMethod, SIGNAL(currentIndexChanged(int)), this, SLOT(changeCofficient(int)));
    connect(ui->comboBoxDetectionMothed, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeDetectionMothed(QString)));
}

/**
 * @brief NAParameterWidget::initializeWidgets
 */
void NAParameterWidget::initializeWidgets() {

    QString fileName = QDir::currentPath() + "/configs/nucleicacid/nucleicacid.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);

    m_detectionMethods = configIniReader->value("Setting/DetectionMethod").toStringList();
    ui->comboBoxDetectionMothed->setView( new QListView() );
    ui->comboBoxDetectionMothed->addItems( m_detectionMethods );

    m_channelNumber = configIniReader->value("Setting/ChannelNumber").toInt();
    ui->spinBoxChannelNumber->setMaximum( m_channelNumber );
    ui->spinBoxChannelNumber->setValue( m_channelNumber );

    m_methods = configIniReader->value("Setting/Method").toStringList();
    ui->comboBoxMethod->setView( new QListView() );
    ui->comboBoxMethod->addItems( m_methods );

    m_coefficients = configIniReader->value("Setting/Coefficient").toStringList();
    QString coefficient = "50";
    if (!m_coefficients.isEmpty()) {
        coefficient = m_coefficients.first();
    }
    ui->doubleSpinBoxCoefficient->setValue(coefficient.toDouble());

    m_bwl = configIniReader->value("Setting/BaseWaveLength").toInt();
    m_mwl = configIniReader->value("Setting/MeasureWaveLength").toInt();
    ui->spinBoxBwl->setValue( m_bwl );
    ui->spinBoxMwl->setValue( m_mwl );

    m_usedUnits = configIniReader->value("Setting/Unit").toStringList();
    ui->comboBoxUnit->setView( new QListView() );
    ui->comboBoxUnit->addItems( m_usedUnits );

    m_mixingLevels = configIniReader->value("Setting/MixingLevel").toStringList();
    ui->comboBoxMixingLevel->setView( new QListView() );
    ui->comboBoxMixingLevel->addItems( m_mixingLevels );

    ui->spinBoxMwl->setReadOnly(true);
    ui->doubleSpinBoxCoefficient->setReadOnly(true);

    m_cuvetteOpticals = configIniReader->value("Setting/CuvetteOptical").toStringList();
    m_microscaleOpticals = configIniReader->value("Setting/MicroscaleOptical").toStringList();
    ui->comboBoxMeasureOptical->setView( new QListView() );
    ui->comboBoxMeasureOptical->addItems( ui->comboBoxDetectionMothed->currentText() ==
                                          "Microscale"?m_microscaleOpticals:m_cuvetteOpticals );

    ui->spinBoxMixingTime->setValue( configIniReader->value("Setting/MixingTime").toInt() );
    ui->spinBoxStaticTime->setValue( configIniReader->value("Setting/StaticTime").toInt() );

    m_motor << ui->labelMixingLevel << ui->comboBoxMixingLevel << ui->labelMixingTime
            << ui->spinBoxMixingTime << ui->labelStaticTime << ui->spinBoxStaticTime;
    foreach (QWidget *w, m_motor) {
        w->setVisible(ui->comboBoxDetectionMothed->currentText() == "Cuvette");
    }

    m_motorSetting << ui->comboBoxMixingLevel << ui->spinBoxMixingTime << ui->spinBoxStaticTime;
    m_measureSetting << ui->comboBoxDetectionMothed << ui->lineEditSampleName
                     << ui->spinBoxBwl << ui->spinBoxMwl << ui->spinBoxChannelNumber
                     << ui->comboBoxMeasureOptical << ui->comboBoxUnit << ui->comboBoxMethod << ui->doubleSpinBoxCoefficient;

    delete configIniReader;
    configIniReader = NULL;
}
