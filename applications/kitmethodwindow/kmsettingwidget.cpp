#include "kmsettingwidget.h"
#include "ui_kmsettingwidget.h"

#include <QDebug>
#include "oscrollarea.h"
#include "ofullkeyboard.h"
#include "kmparameterwidget.h"


KMSettingWidget::KMSettingWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::KMSettingWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

KMSettingWidget::~KMSettingWidget() {
    delete ui;
}

/**
 * @brief KMSettingWidget::getCurrentMethod
 * @return
 */
QString KMSettingWidget::getCurrentMethod() {
    return m_pParameterWidget->getCurrentMethod();
}

/**
 * @brief KMSettingWidget::getMaxChannelNumber
 * @return
 */
int KMSettingWidget::getMaxChannelNumber() {
    return m_pParameterWidget->getMaxChannelNumber();
}

/**
 * @brief KMSettingWidget::save
 */
void KMSettingWidget::save() {
    m_motorSetting = m_pParameterWidget->getMotorSetting();
    m_measureSetting = m_pParameterWidget->getMeasureSetting();
}

/**
 * @brief KMSettingWidget::updateData
 * @param record
 */
void KMSettingWidget::updateData(QStringList record) {

    if(record.size() >= 7) {
        m_pParameterWidget->setUnit(record.at(7));
        m_pParameterWidget->setOrder(record.at(4));
        m_pParameterWidget->setMethod(record.at(1));
        m_pParameterWidget->setSampleName(record.at(0));
    }
}

/**
 * @brief KMSettingWidget::back
 */
void KMSettingWidget::back() {

    if (ui->toolButtonOK == sender()) {
        m_motorSetting = m_pParameterWidget->getMotorSetting();
        m_measureSetting = m_pParameterWidget->getMeasureSetting();
    } else {
        m_pParameterWidget->setMotorSetting( m_motorSetting );
        m_pParameterWidget->setMeasureSetting( m_measureSetting );
    }
    emit toTestingPage();
}

/**
 * @brief KMSettingWidget::initializeSignals
 */
void KMSettingWidget::initializeSignals() {

    connect(ui->toolButtonCancel, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonOK, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonRestore, SIGNAL(clicked(bool)), m_pParameterWidget, SLOT(restore()));
}

/**
 * @brief KMSettingWidget::initializeWidgets
 */
void KMSettingWidget::initializeWidgets() {

    m_pScrollArea = new OScrollArea();
    m_pParameterWidget = new KMParameterWidget();
    m_motorSetting = m_pParameterWidget->getMotorSetting();
    m_measureSetting = m_pParameterWidget->getMeasureSetting();
    m_pScrollArea->setWidget(m_pParameterWidget);

    QHBoxLayout *scrollAreaLayout = new QHBoxLayout();
    scrollAreaLayout->addWidget(m_pScrollArea);
    ui->frameParameter->setLayout(scrollAreaLayout);

    m_pFullKeyboard = new OFullKeyboard(m_pParameterWidget, this);
    m_pFullKeyboard->setKeySize(QSize(60, 60));
    QHBoxLayout *keyboardLayout = new QHBoxLayout();
    keyboardLayout->addWidget(m_pFullKeyboard);
    ui->frameKeyboard->setLayout(keyboardLayout);

    ui->labelTitle->setText( "Kit Method Setting" );

}


