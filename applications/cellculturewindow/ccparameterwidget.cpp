#include "ccparameterwidget.h"
#include "ui_ccparameterwidget.h"

#include <QDir>
#include <QDebug>
#include <QListView>
#include <QSettings>
#include "omessageboxutil.h"

CCParameterWidget::CCParameterWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CCParameterWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

CCParameterWidget::~CCParameterWidget() {
    delete ui;
}

/**
 * @brief CCParameterWidget::getMeasureSetting
 * @return
 */
QStringList CCParameterWidget::getMeasureSetting() {

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
 * @brief CCParameterWidget::setMeasureSetting
 * @param data
 */
void CCParameterWidget::setMeasureSetting(QStringList data) {

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
 * @brief CCParameterWidget::getMotorSetting
 * @return
 */
QStringList CCParameterWidget::getMotorSetting() {

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
 * @brief CCParameterWidget::setMotorSetting
 * @param data
 */
void CCParameterWidget::setMotorSetting(QStringList data) {
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
 * @brief CCParameterWidget::getCurrentMethod
 */
QString CCParameterWidget::getCurrentMethod() {
    return ui->comboBoxMethod->currentText();
}

/**
 * @brief CCParameterWidget::restore
 */
void CCParameterWidget::restore() {

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
    QString mwl = "600";
    if (!m_mwls.isEmpty()) {mwl = m_mwls.first();}
    QString coef = "1.0";
    if (!m_coefficients.isEmpty()) {coef = m_coefficients.first();}
    ui->spinBoxMwl->setValue( mwl.toInt() );
    ui->doubleSpinBoxCoefficient->setValue( coef.toDouble() );
    ui->comboBoxMeasureOptical->setCurrentIndex( 0 );
    ui->comboBoxMixingLevel->setCurrentIndex( 0 );
    ui->spinBoxMixingTime->setValue( 0 );
    ui->spinBoxStaticTime->setValue( 0 );
}

/**
 * @brief CCParameterWidget::changeCofficient
 * @param index
 */
void CCParameterWidget::changeParameter(int index) {

    QString confficient = m_coefficients.at(index);
    ui->doubleSpinBoxCoefficient->setValue(confficient.toDouble());

    ui->spinBoxMwl->setReadOnly(true);
    if (ui->comboBoxMethod->itemText(index) == "Custom") {
        ui->spinBoxMwl->setReadOnly(false);
    }
    QString mwl = m_mwls.at(index);
    ui->spinBoxMwl->setValue(mwl.toInt());
}

/**
 * @brief CCParameterWidget::changeDetectionMothed
 * @param method
 */
void CCParameterWidget::changeDetectionMothed(QString method) {

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
 * @brief CCParameterWidget::initializeSignals
 */
void CCParameterWidget::initializeSignals() {
    connect(ui->comboBoxMethod, SIGNAL(currentIndexChanged(int)), this, SLOT(changeParameter(int)));
    connect(ui->comboBoxDetectionMothed, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeDetectionMothed(QString)));
}

/**
 * @brief CCParameterWidget::initializeWidgets
 */
void CCParameterWidget::initializeWidgets() {

    QString fileName = QDir::currentPath() + "/configs/cellculture/cellculture.ini";
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
    QString coefficient = "1.0";
    if (!m_coefficients.isEmpty()) {
        coefficient = m_coefficients.first();
    }
    ui->doubleSpinBoxCoefficient->setValue(coefficient.toDouble());

    m_bwl = configIniReader->value("Setting/BaseWaveLength").toInt();
    ui->spinBoxBwl->setValue( m_bwl );

    m_mwls = configIniReader->value("Setting/MeasureWaveLength").toStringList();
    ui->spinBoxMwl->setReadOnly(true);
    QString mwl = "600";
    if (!m_mwls.isEmpty()) {
        mwl = m_mwls.first();
    }
    ui->spinBoxMwl->setValue(mwl.toInt());

    m_mixingLevels = configIniReader->value("Setting/MixingLevel").toStringList();
    ui->comboBoxMixingLevel->setView( new QListView() );
    ui->comboBoxMixingLevel->addItems( m_mixingLevels );

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
                     << ui->comboBoxMeasureOptical << ui->comboBoxMethod << ui->doubleSpinBoxCoefficient;

    delete configIniReader;
    configIniReader = NULL;
}
