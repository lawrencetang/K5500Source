#include "ptsettingwidget.h"
#include "ui_ptsettingwidget.h"

#include <QDebug>
#include "oscrollarea.h"
#include "ofullkeyboard.h"
#include "ptparameterwidget.h"


PTSettingWidget::PTSettingWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PTSettingWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

PTSettingWidget::~PTSettingWidget() {
    delete ui;
}

/**
 * @brief PTSettingWidget::getCurrentMethod
 * @return
 */
QString PTSettingWidget::getCurrentMethod() {
    return m_pParameterWidget->getCurrentMethod();
}

/**
 * @brief PTSettingWidget::getMaxChannelNumber
 * @return
 */
int PTSettingWidget::getMaxChannelNumber() {
    return m_pParameterWidget->getMaxChannelNumber();
}

/**
 * @brief PTSettingWidget::save
 */
void PTSettingWidget::save() {
    m_motorSetting = m_pParameterWidget->getMotorSetting();
    m_measureSetting = m_pParameterWidget->getMeasureSetting();
}

/**
 * @brief PTSettingWidget::back
 */
void PTSettingWidget::back() {

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
 * @brief PTSettingWidget::initializeSignals
 */
void PTSettingWidget::initializeSignals() {

    connect(ui->toolButtonCancel, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonOK, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonRestore, SIGNAL(clicked(bool)), m_pParameterWidget, SLOT(restore()));
}

/**
 * @brief PTSettingWidget::initializeWidgets
 */
void PTSettingWidget::initializeWidgets() {

    m_pScrollArea = new OScrollArea();
    m_pParameterWidget = new PTParameterWidget();
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

    ui->labelTitle->setText( "Protein Setting" );

}


