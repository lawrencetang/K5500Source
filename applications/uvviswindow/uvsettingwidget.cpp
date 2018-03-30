#include "uvsettingwidget.h"
#include "ui_uvsettingwidget.h"

#include <QDebug>
#include "oscrollarea.h"
#include "ofullkeyboard.h"
#include "uvparameterwidget.h"


UVSettingWidget::UVSettingWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::UVSettingWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

UVSettingWidget::~UVSettingWidget() {
    delete ui;
}


/**
 * @brief UVSettingWidget::getMaxChannelNumber
 * @return
 */
int UVSettingWidget::getMaxChannelNumber() {
    return m_pParameterWidget->getMaxChannelNumber();
}

/**
 * @brief UVSettingWidget::save
 */
void UVSettingWidget::save() {
    m_motorSetting = m_pParameterWidget->getMotorSetting();
    m_measureSetting = m_pParameterWidget->getMeasureSetting();
}

/**
 * @brief UVSettingWidget::back
 */
void UVSettingWidget::back() {

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
 * @brief UVSettingWidget::initializeSignals
 */
void UVSettingWidget::initializeSignals() {

    connect(ui->toolButtonCancel, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonOK, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonRestore, SIGNAL(clicked(bool)), m_pParameterWidget, SLOT(restore()));
}

/**
 * @brief UVSettingWidget::initializeWidgets
 */
void UVSettingWidget::initializeWidgets() {

    m_pScrollArea = new OScrollArea();
    m_pParameterWidget = new UVParameterWidget();
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

    ui->labelTitle->setText( "UV-VIS Setting" );

}


