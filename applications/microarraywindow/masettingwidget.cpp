#include "masettingwidget.h"
#include "ui_masettingwidget.h"

#include <QDebug>
#include "madyewidget.h"
#include "oscrollarea.h"
#include "ofullkeyboard.h"
#include "maparameterwidget.h"


MASettingWidget::MASettingWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MASettingWidget) {
    ui->setupUi(this);

    initializeWidgets();
    initializeSignals();
}

MASettingWidget::~MASettingWidget() {
    delete ui;
}

/**
 * @brief MASettingWidget::getCurrentMethod
 * @return
 */
QString MASettingWidget::getCurrentMethod() {
    return m_pParameterWidget->getCurrentMethod();
}

/**
 * @brief MASettingWidget::getMaxChannelNumber
 * @return
 */
int MASettingWidget::getMaxChannelNumber() {
    return m_pParameterWidget->getMaxChannelNumber();
}

/**
 * @brief MASettingWidget::save
 */
void MASettingWidget::save() {
    m_motorSetting = m_pParameterWidget->getMotorSetting();
    m_measureSetting = m_pParameterWidget->getMeasureSetting();
}

/**
 * @brief MASettingWidget::getDyeSetting
 * @return
 */
QList<QStringList> MASettingWidget::getDyeSetting() {
    return m_pDyeWidget->getSelectedDyes();
}

/**
 * @brief MASettingWidget::back
 */
void MASettingWidget::back() {

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
 * @brief MASettingWidget::setHeaderDisabled
 * @param ok
 */
void MASettingWidget::setHeaderDisabled(bool ok) {
    ui->frameHeader->setEnabled(ok);
}

/**
 * @brief MASettingWidget::initializeSignals
 */
void MASettingWidget::initializeSignals() {

    connect(m_pDyeWidget, SIGNAL(headerDisabled(bool)), this, SLOT(setHeaderDisabled(bool)));
    connect(ui->toolButtonCancel, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonOK, SIGNAL(clicked(bool)), this, SLOT(back()));
    connect(ui->toolButtonRestore, SIGNAL(clicked(bool)), m_pParameterWidget, SLOT(restore()));
}

/**
 * @brief MASettingWidget::initializeWidgets
 */
void MASettingWidget::initializeWidgets() {

    m_pScrollArea = new OScrollArea();
    m_pParameterWidget = new MAParameterWidget();
    m_motorSetting = m_pParameterWidget->getMotorSetting();
    m_measureSetting = m_pParameterWidget->getMeasureSetting();
    m_pScrollArea->setWidget(m_pParameterWidget);

    QHBoxLayout *scrollAreaLayout = new QHBoxLayout();
    scrollAreaLayout->addWidget(m_pScrollArea);
    ui->frameParameter->setLayout(scrollAreaLayout);

    m_pFullKeyboard = new OFullKeyboard(this, this);
    m_pFullKeyboard->setKeySize(QSize(60, 60));
    QHBoxLayout *keyboardLayout = new QHBoxLayout();
    keyboardLayout->addWidget(m_pFullKeyboard);
    keyboardLayout->setMargin(0);
    ui->frameKeyboard->setLayout(keyboardLayout);

    ui->labelTitle->setText( "Micro Array Setting" );

    m_pDyeWidget = new MADyeWidget();
    m_pDyeWidget->setFixedWidth(800);
    QHBoxLayout *dyeLayout = new QHBoxLayout();
    dyeLayout->addWidget(m_pDyeWidget);
    dyeLayout->setMargin(0);
    ui->frameDye->setLayout(dyeLayout);
}


