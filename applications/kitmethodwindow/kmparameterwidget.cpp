#include "kmparameterwidget.h"
#include "ui_kmparameterwidget.h"

#include <QDir>
#include <QDebug>
#include <QListView>
#include <QSettings>
#include "omessageboxutil.h"

KMParameterWidget::KMParameterWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::KMParameterWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

KMParameterWidget::~KMParameterWidget() {
    delete ui;
}

/**
 * @brief KMParameterWidget::getMeasureSetting
 * @return
 */
QStringList KMParameterWidget::getMeasureSetting() {

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
 * @brief KMParameterWidget::setMeasureSetting
 * @param data
 */
void KMParameterWidget::setMeasureSetting(QStringList data) {

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
 * @brief KMParameterWidget::getMotorSetting
 * @return
 */
QStringList KMParameterWidget::getMotorSetting() {

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
 * @brief KMParameterWidget::setMotorSetting
 * @param data
 */
void KMParameterWidget::setMotorSetting(QStringList data) {
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
 * @brief KMParameterWidget::getCurrentMethod
 */
QString KMParameterWidget::getCurrentMethod() {
    return ui->comboBoxMethod->currentText();
}

/**
 * @brief KMParameterWidget::setUnit
 * @param unit
 */
void KMParameterWidget::setUnit(QString unit) {
    ui->comboBoxUnit->setCurrentText(unit);
}

/**
 * @brief KMParameterWidget::setMethod
 * @param method
 */
void KMParameterWidget::setMethod(QString method) {
    ui->comboBoxMethod->setCurrentText(method);
}

/**
 * @brief KMParameterWidget::setSampleName
 * @param name
 */
void KMParameterWidget::setSampleName(QString name) {
    ui->lineEditSampleName->setText(name);
}

/**
 * @brief KMParameterWidget::setOrder
 * @param order
 */
void KMParameterWidget::setOrder(QString order) {
    ui->comboBoxOrder->setCurrentText(order);
}

/**
 * @brief KMParameterWidget::restore
 */
void KMParameterWidget::restore() {

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
    QString wlStr = m_waveLengths.first();
    ui->spinBoxMwl->setValue( wlStr.toInt() );
    ui->comboBoxUnit->setCurrentIndex( 0 );
    ui->comboBoxMixingLevel->setCurrentIndex( 0 );
    ui->comboBoxMeasureOptical->setCurrentIndex( 0 );
    ui->spinBoxMixingTime->setValue( 0 );
    ui->spinBoxStaticTime->setValue( 0 );
    ui->comboBoxOrder->setCurrentIndex(0);
}

/**
 * @brief KMParameterWidget::changeCofficient
 * @param index
 */
void KMParameterWidget::changeWaveLength(int index) {

    ui->spinBoxMwl->setReadOnly(true);
    if (ui->comboBoxMethod->itemText(index) == "Custom") {
        ui->spinBoxMwl->setReadOnly(false);
    }
    QString wlStr = m_waveLengths.at(index);
    ui->spinBoxMwl->setValue(wlStr.toInt());
}

/**
 * @brief KMParameterWidget::changeDetectionMothed
 * @param method
 */
void KMParameterWidget::changeDetectionMothed(QString method) {

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
 * @brief KMParameterWidget::initializeSignals
 */
void KMParameterWidget::initializeSignals() {
    connect(ui->comboBoxMethod, SIGNAL(currentIndexChanged(int)), this, SLOT(changeWaveLength(int)));
    connect(ui->comboBoxDetectionMothed, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeDetectionMothed(QString)));
}

/**
 * @brief KMParameterWidget::initializeWidgets
 */
void KMParameterWidget::initializeWidgets() {

    QString fileName = QDir::currentPath() + "/configs/kitmethod/kitmethod.ini";
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

    m_bwl = configIniReader->value("Setting/BaseWaveLength").toInt();
    ui->spinBoxBwl->setValue( m_bwl );

    m_usedUnits = configIniReader->value("Setting/Unit").toStringList();
    ui->comboBoxUnit->setView( new QListView() );
    ui->comboBoxUnit->addItems( m_usedUnits );

    m_mixingLevels = configIniReader->value("Setting/MixingLevel").toStringList();
    ui->comboBoxMixingLevel->setView( new QListView() );
    ui->comboBoxMixingLevel->addItems( m_mixingLevels );

    m_waveLengths = configIniReader->value("Setting/MeasureWaveLength").toStringList();
    QString wlStr = "562";
    if (m_waveLengths.isEmpty()) {
        wlStr = m_waveLengths.first();
    }
    ui->spinBoxMwl->setValue(wlStr.toInt());
    ui->spinBoxMwl->setReadOnly(true);

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

    m_orders = configIniReader->value("Setting/Order").toStringList();
    ui->comboBoxOrder->setView( new QListView() );
    ui->comboBoxOrder->addItems( m_orders );

    m_motorSetting << ui->comboBoxMixingLevel << ui->spinBoxMixingTime << ui->spinBoxStaticTime;
    m_measureSetting << ui->comboBoxDetectionMothed << ui->lineEditSampleName
                     << ui->spinBoxBwl << ui->spinBoxMwl << ui->spinBoxChannelNumber
                     << ui->comboBoxMeasureOptical << ui->comboBoxUnit << ui->comboBoxMethod << ui->comboBoxOrder;

    delete configIniReader;
    configIniReader = NULL;
}
