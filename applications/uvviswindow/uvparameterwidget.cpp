#include "uvparameterwidget.h"
#include "ui_uvparameterwidget.h"

#include <QDir>
#include <QDebug>
#include <QListView>
#include <QSettings>
#include "omessageboxutil.h"

UVParameterWidget::UVParameterWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::UVParameterWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

UVParameterWidget::~UVParameterWidget() {
    delete ui;
}

/**
 * @brief UVParameterWidget::getMeasureSetting
 * @return
 */
QStringList UVParameterWidget::getMeasureSetting() {

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
 * @brief UVParameterWidget::setMeasureSetting
 * @param data
 */
void UVParameterWidget::setMeasureSetting(QStringList data) {

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
 * @brief UVParameterWidget::getMotorSetting
 * @return
 */
QStringList UVParameterWidget::getMotorSetting() {

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
 * @brief UVParameterWidget::setMotorSetting
 * @param data
 */
void UVParameterWidget::setMotorSetting(QStringList data) {
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
 * @brief UVParameterWidget::restore
 */
void UVParameterWidget::restore() {

    int result = OMessageBoxUtil::staticNotice( 0,
                                                tr("Are you sure to restore?"),
                                                QStringList() << tr( "OK" ) << tr( "Cancel" ) );
    if (result != 0) {
        return;
    }

    ui->comboBoxDetectionMothed->setCurrentIndex( 0 );
    ui->spinBoxChannelNumber->setValue( ui->spinBoxChannelNumber->maximum() );
    ui->spinBoxBwl->setValue( m_bwl );
    ui->comboBoxMixingLevel->setCurrentIndex( 0 );
    ui->comboBoxMeasureOptical->setCurrentIndex( 0 );
    ui->spinBoxMixingTime->setValue( 0 );
    ui->spinBoxStaticTime->setValue( 0 );

    foreach (QSpinBox *sBox, m_maveLengthSetting) {
        int i = m_maveLengthSetting.indexOf(sBox);
        if (i < m_maveLengths.size()) {
            QString ml = m_maveLengths.at(i);
            sBox->setValue(ml.toInt());
        }
    }

    foreach (QDoubleSpinBox *sBox, m_coefficientSetting) {
        int i = m_coefficientSetting.indexOf(sBox);
        if (i < m_cofficients.size()) {
            QString cf = m_cofficients.at(i);
            sBox->setValue(cf.toDouble());
        }
    }
}

/**
 * @brief UVParameterWidget::changeDetectionMothed
 * @param method
 */
void UVParameterWidget::changeDetectionMothed(QString method) {

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
 * @brief UVParameterWidget::initializeSignals
 */
void UVParameterWidget::initializeSignals() {
    connect(ui->comboBoxDetectionMothed, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeDetectionMothed(QString)));
}

/**
 * @brief UVParameterWidget::initializeWidgets
 */
void UVParameterWidget::initializeWidgets() {

    QString fileName = QDir::currentPath() + "/configs/uv_vis/uv_vis.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);

    m_detectionMethods = configIniReader->value("Setting/DetectionMethod").toStringList();
    ui->comboBoxDetectionMothed->setView( new QListView() );
    ui->comboBoxDetectionMothed->addItems( m_detectionMethods );

    m_channelNumber = configIniReader->value("Setting/ChannelNumber").toInt();
    ui->spinBoxChannelNumber->setMaximum( m_channelNumber );
    ui->spinBoxChannelNumber->setValue( m_channelNumber );

    m_bwl = configIniReader->value("Setting/BaseWaveLength").toInt();
    ui->spinBoxBwl->setValue( m_bwl );

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
        w->setVisible( ui->comboBoxDetectionMothed->currentText() == "Cuvette" );
    }

    m_maveLengths = configIniReader->value("Setting/MeasureWaveLength").toStringList();
    m_maveLengthSetting << ui->spinBoxMwl1 << ui->spinBoxMwl2
                        << ui->spinBoxMwl3 << ui->spinBoxMwl4
                        << ui->spinBoxMwl5;
    foreach (QSpinBox *sBox, m_maveLengthSetting) {
        int i = m_maveLengthSetting.indexOf(sBox);
        if (i < m_maveLengths.size()) {
            QString ml = m_maveLengths.at(i);
            sBox->setValue(ml.toInt());
        }
    }

    m_cofficients = configIniReader->value("Setting/Coefficient").toStringList();
    m_coefficientSetting << ui->doubleSpinBoxCoef1 << ui->doubleSpinBoxCoef2
                         << ui->doubleSpinBoxCoef3 << ui->doubleSpinBoxCoef4
                         << ui->doubleSpinBoxCoef5;
    foreach (QDoubleSpinBox *sBox, m_coefficientSetting) {
        int i = m_coefficientSetting.indexOf(sBox);
        if (i < m_cofficients.size()) {
            QString cf = m_cofficients.at(i);
            sBox->setValue(cf.toDouble());
        }
    }

    m_motorSetting << ui->comboBoxMixingLevel << ui->spinBoxMixingTime << ui->spinBoxStaticTime;
    m_measureSetting << ui->comboBoxDetectionMothed << ui->lineEditSampleName << ui->spinBoxBwl << ui->spinBoxChannelNumber << ui->comboBoxMeasureOptical
                     << ui->spinBoxMwl1 << ui->doubleSpinBoxCoef1 << ui->spinBoxMwl2  << ui->doubleSpinBoxCoef2
                     << ui->spinBoxMwl3 << ui->doubleSpinBoxCoef3 << ui->spinBoxMwl4  << ui->doubleSpinBoxCoef4
                     << ui->spinBoxMwl5 << ui->doubleSpinBoxCoef5;

    delete configIniReader;
    configIniReader = NULL;
}
