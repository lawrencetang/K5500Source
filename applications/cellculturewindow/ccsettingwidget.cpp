#include "ccsettingwidget.h"
#include "ui_ccsettingwidget.h"

#include <QDebug>
#include "oscrollarea.h"
#include "ofullkeyboard.h"
#include "ccparameterwidget.h"


CCSettingWidget::CCSettingWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CCSettingWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

CCSettingWidget::~CCSettingWidget() {
    delete ui;
}

/**
 * @brief CCSettingWidget::getCurrentMethod
 * @return
 */
QString CCSettingWidget::getCurrentMethod() {
    return m_pParameterWidget->getCurrentMethod();
}

/**
 * @brief CCSettingWidget::getMaxChannelNumber
 * @return
 */
int CCSettingWidget::getMaxChannelNumber() {
    return m_pParameterWidget->getMaxChannelNumber();
}

/**
 * @brief CCSettingWidget::save
 */
void CCSettingWidget::save() {
    m_motorSetting = m_pParameterWidget->getMotorSetting();
    m_measureSetting = m_pParameterWidget->getMeasureSetting();
}

/**
 * @brief CCSettingWidget::back
 */
void CCSettingWidget::back() {

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
 * @brief CCSettingWidget::initializeSignals
 */
void CCSettingWidget::initializeSignals() {

    connect(ui->toolButtonCancel, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonOK, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonRestore, SIGNAL(clicked(bool)), m_pParameterWidget, SLOT(restore()));
}

/**
 * @brief CCSettingWidget::initializeWidgets
 */
void CCSettingWidget::initializeWidgets() {

    m_pScrollArea = new OScrollArea();
    m_pParameterWidget = new CCParameterWidget();
    m_motorSetting = m_pParameterWidget->getMotorSetting();
    m_measureSetting = m_pParameterWidget->getMeasureSetting();
    m_pScrollArea->setWidget(m_pParameterWidget);

    QHBoxLayout *scrollAreaLayout = new QHBoxLayout();
    scrollAreaLayout->addWidget(m_pScrollArea);
    ui->frameParameter->setLayout(scrollAreaLayout);

    m_pFullKeyboard = new OFullKeyboard(m_pScrollArea, this);
    m_pFullKeyboard->setKeySize(QSize(60, 60));
    QHBoxLayout *keyboardLayout = new QHBoxLayout();
    keyboardLayout->addWidget(m_pFullKeyboard);
    ui->frameKeyboard->setLayout(keyboardLayout);

    ui->labelTitle->setText( "Cell Culture Setting" );

}


