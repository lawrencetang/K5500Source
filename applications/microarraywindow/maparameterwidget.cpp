#include "maparameterwidget.h"
#include "ui_maparameterwidget.h"

#include <QDir>
#include <QDebug>
#include <QListView>
#include <QSettings>
#include "omessageboxutil.h"

MAParameterWidget::MAParameterWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MAParameterWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

MAParameterWidget::~MAParameterWidget() {
    delete ui;
}

/**
 * @brief MAParameterWidget::getMeasureSetting
 * @return
 */
QStringList MAParameterWidget::getMeasureSetting() {

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
 * @brief MAParameterWidget::setMeasureSetting
 * @param data
 */
void MAParameterWidget::setMeasureSetting(QStringList data) {

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
 * @brief MAParameterWidget::getMotorSetting
 * @return
 */
QStringList MAParameterWidget::getMotorSetting() {

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
 * @brief MAParameterWidget::setMotorSetting
 * @param data
 */
void MAParameterWidget::setMotorSetting(QStringList data) {
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
 * @brief MAParameterWidget::getCurrentMethod
 */
QString MAParameterWidget::getCurrentMethod() {
    return ui->comboBoxMethod->currentText();
}

/**
 * @brief MAParameterWidget::restore
 */
void MAParameterWidget::restore() {

    int result = OMessageBoxUtil::staticNotice( 0,
                                                tr("Are you sure to restore?"),
                                                QStringList() << tr( "OK" ) << tr( "Cancel" ) );
    if (result != 0) {
        return;
    }

    ui->comboBoxDetectionMothed->setCurrentIndex( 0 );
    ui->comboBoxDetectionMatter->setCurrentIndex( 0 );
    ui->spinBoxChannelNumber->setValue( ui->spinBoxChannelNumber->maximum() );
    ui->comboBoxMethod->setCurrentIndex( 0 );
    ui->spinBoxBwl->setValue( m_bwl );
    ui->comboBoxUnit->setCurrentIndex( 0 );
    ui->comboBoxMixingLevel->setCurrentIndex( 0 );
    ui->comboBoxMeasureOptical->setCurrentIndex( 0 );
    ui->spinBoxMixingTime->setValue( 0 );
    ui->spinBoxStaticTime->setValue( 0 );
}

/**
 * @brief MAParameterWidget::changeMatter
 * @param matter
 */
void MAParameterWidget::changeMatter(QString matter) {

    disconnect(ui->comboBoxMethod, SIGNAL(currentIndexChanged(int)), this, SLOT(changeCofficient(int)));
    ui->comboBoxMethod->clear();
    ui->comboBoxMethod->addItems(matter=="Protein"?m_proteinMethods:m_nucleicAcidMethods);
    QString coefficient;
    if (matter=="Protein") {
        coefficient = (!m_proteinCoefficients.isEmpty())?m_proteinCoefficients.first():"10.6";
    } else {
        coefficient = (!m_nucleicAcidCoefficients.isEmpty())?m_nucleicAcidCoefficients.first():"50";
    }
    ui->doubleSpinBoxCoefficient->setValue(coefficient.toDouble());
    ui->spinBoxMwl->setValue(ui->comboBoxDetectionMatter->currentText()=="Protein"?m_proteinMwl:m_nucleicAcidMwl);
    connect(ui->comboBoxMethod, SIGNAL(currentIndexChanged(int)), this, SLOT(changeCofficient(int)));
}

/**
 * @brief MAParameterWidget::changeCofficient
 * @param index
 */
void MAParameterWidget::changeCofficient(int index) {

    ui->doubleSpinBoxCoefficient->setReadOnly(true);
    if (ui->comboBoxMethod->itemText(index) == "Custom") {
        ui->doubleSpinBoxCoefficient->setReadOnly(false);
    }
    QString confficient = ui->comboBoxDetectionMatter->currentText() == "Protein"?
                m_proteinCoefficients.at(index):m_nucleicAcidCoefficients.at(index);
    ui->doubleSpinBoxCoefficient->setValue(confficient.toDouble());
}

/**
 * @brief MAParameterWidget::changeDetectionMothed
 * @param method
 */
void MAParameterWidget::changeDetectionMothed(QString method) {

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
 * @brief MAParameterWidget::initializeSignals
 */
void MAParameterWidget::initializeSignals() {
    connect(ui->comboBoxDetectionMatter, SIGNAL(currentTextChanged(QString)), this, SLOT(changeMatter(QString)));
    connect(ui->comboBoxMethod, SIGNAL(currentIndexChanged(int)), this, SLOT(changeCofficient(int)));
    connect(ui->comboBoxDetectionMothed, SIGNAL(currentIndexChanged(QString)), this, SLOT(changeDetectionMothed(QString)));
}

/**
 * @brief MAParameterWidget::initializeWidgets
 */
void MAParameterWidget::initializeWidgets() {

    QString fileName = QDir::currentPath() + "/configs/microarray/microarray.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);

    m_detectionMethods = configIniReader->value("Setting/DetectionMethod").toStringList();
    ui->comboBoxDetectionMothed->setView( new QListView() );
    ui->comboBoxDetectionMothed->addItems( m_detectionMethods );

    m_channelNumber = configIniReader->value("Setting/ChannelNumber").toInt();
    ui->spinBoxChannelNumber->setMaximum( m_channelNumber );
    ui->spinBoxChannelNumber->setValue( m_channelNumber );

    m_detectionMatters = configIniReader->value("Setting/DetectionMatter").toStringList();
    ui->comboBoxDetectionMatter->setView( new QListView() );
    ui->comboBoxDetectionMatter->addItems( m_detectionMatters );

    m_nucleicAcidMethods = configIniReader->value("Setting/NucleicAcidMethod").toStringList();
    m_proteinMethods = configIniReader->value("Setting/ProteinMethod").toStringList();
    ui->comboBoxMethod->setView(new QListView());
    ui->comboBoxMethod->addItems(ui->comboBoxDetectionMatter->currentText()=="Protein"?m_proteinMethods:m_nucleicAcidMethods);

    m_nucleicAcidCoefficients = configIniReader->value("Setting/NucleicAcidCoefficient").toStringList();
    m_proteinCoefficients = configIniReader->value("Setting/ProteinCoefficient").toStringList();
    QString coefficient;
    if (ui->comboBoxDetectionMatter->currentText()=="Protein") {
        coefficient = (!m_proteinCoefficients.isEmpty())?m_proteinCoefficients.first():"10.6";
    } else {
        coefficient = (!m_nucleicAcidCoefficients.isEmpty())?m_nucleicAcidCoefficients.first():"50";
    }
    ui->doubleSpinBoxCoefficient->setValue(coefficient.toDouble());

    m_bwl = configIniReader->value("Setting/BaseWaveLength").toInt();
    m_nucleicAcidMwl = configIniReader->value("Setting/NucleicAcidMeasureWaveLength").toInt();
    m_proteinMwl = configIniReader->value("Setting/ProteinMeasureWaveLength").toInt();
    ui->spinBoxBwl->setValue( m_bwl );
    ui->spinBoxMwl->setValue( ui->comboBoxDetectionMatter->currentText()=="Protein"?m_proteinMwl:m_nucleicAcidMwl );

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
    m_measureSetting << ui->comboBoxDetectionMothed << ui->comboBoxDetectionMatter
                     << ui->lineEditSampleName << ui->spinBoxBwl << ui->spinBoxMwl
                     << ui->spinBoxChannelNumber << ui->comboBoxMeasureOptical << ui->comboBoxUnit
                     << ui->comboBoxMethod << ui->doubleSpinBoxCoefficient;

    delete configIniReader;
    configIniReader = NULL;
}
