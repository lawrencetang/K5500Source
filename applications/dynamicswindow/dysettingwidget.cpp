#include "dysettingwidget.h"
#include "ui_dysettingwidget.h"

#include <QDebug>
#include "oscrollarea.h"
#include "ofullkeyboard.h"
#include "dyparameterwidget.h"


DYSettingWidget::DYSettingWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DYSettingWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

DYSettingWidget::~DYSettingWidget() {
    delete ui;
}

/**
 * @brief DYSettingWidget::save
 */
void DYSettingWidget::save() {
    m_motorSetting = m_pParameterWidget->getMotorSetting();
    m_measureSetting = m_pParameterWidget->getMeasureSetting();
}

/**
 * @brief DYSettingWidget::back
 */
void DYSettingWidget::back() {

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
 * @brief DYSettingWidget::initializeSignals
 */
void DYSettingWidget::initializeSignals() {

    connect(ui->toolButtonCancel, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonOK, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonRestore, SIGNAL(clicked(bool)), m_pParameterWidget, SLOT(restore()));
}

/**
 * @brief DYSettingWidget::initializeWidgets
 */
void DYSettingWidget::initializeWidgets() {

    m_pScrollArea = new OScrollArea();
    m_pParameterWidget = new DYParameterWidget();
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

    ui->labelTitle->setText( "Dynamics Setting" );

}


