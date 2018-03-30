#include "kitmethodwindow.h"
#include "ui_kitmethodwindow.h"

#include <QDir>
#include <QDebug>
#include <QSettings>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include "oserialport.h"
#include "ospectrograph.h"
#include "omessageboxutil.h"

#include "kmsettingmodel.h"
#include "kmdetectionflow.h"
#include "kmtestingwidget.h"
#include "kmsettingwidget.h"

KitMethodWindow::KitMethodWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::KitMethodWindow) {
    ui->setupUi(this);

    m_isBlanked = false;
    m_isAnimation = true;
    m_pDetectionFlow = new KMDetectionFlow(serialPort, spectrograph, this);

    QString fileName = QDir::currentPath() + "/configs/kitmethod/kitmethod.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);
    m_isAnimation = configIniReader->value("/System/AnimationEnable").toBool();
    delete configIniReader;
    configIniReader = NULL;

    initializeWidgets();
    initializeSignals();
}

KitMethodWindow::~KitMethodWindow() {
    delete ui;
    delete m_pSettingModel;
}

/**
 * @brief KitMethodWindow::back
 */
void KitMethodWindow::back() {
    m_isBlanked = false;
    m_pDetectionFlow->quit();
    emit backToMainPage();
}

/**
 * @brief KitMethodWindow::showTestingPage
 */
void KitMethodWindow::showTestingPage() {
    if (sender() == m_pSettingWidget) {
        m_pSettingModel->setMaxChannelNumber(m_pSettingWidget->getMaxChannelNumber());
        m_pSettingModel->setMeasureParameters(m_pSettingWidget->getMeasureSetting());
        m_pSettingModel->setMotorParameters(m_pSettingWidget->getMotorSetting());
        m_pTestingWidget->updateUnit(m_pSettingModel->getUnit());
    }
    m_pTestingWidget->setPlotTitle(m_pSettingWidget->getCurrentMethod());
    QWidget *page = ui->pageTesting;
    ui->stackedWidget->setCurrentWidget(page);
    flipOverAnimation(page);
}

/**
 * @brief KitMethodWindow::showSettingPage
 */
void KitMethodWindow::showSettingPage() {
    QWidget *page = ui->pageSetting;
    ui->stackedWidget->setCurrentWidget(page);
    m_pSettingWidget->save();
    flipOverAnimation(page);
}

/**
 * @brief KitMethodWindow::startBlank
 */
void KitMethodWindow::startBlank() {
    if (m_pDetectionFlow == NULL) {
        m_pTestingWidget->setOperatingKeyEnable(true);
        OMessageBoxUtil::staticNotice(0, tr( "System error, please restart to fix!" ), QStringList() << tr( "OK" ), 10);
        return;
    }

    m_isBlanked = true;
    QString result = m_pDetectionFlow->blank(m_pSettingModel);
    if (result != "Success") {
        OMessageBoxUtil::staticNotice(0, result, QStringList() << tr( "OK" ), 10);
    }
    m_pTestingWidget->setOperatingKeyEnable(true);
}

/**
 * @brief KitMethodWindow::startMeasure
 */
void KitMethodWindow::startMeasure() {

    if (m_pDetectionFlow == NULL) {
        m_pTestingWidget->setOperatingKeyEnable(true);
        OMessageBoxUtil::staticNotice(0, tr( "System error, please restart to fix!" ), QStringList() << tr( "OK" ), 10);
        return;
    }
    if (!m_isBlanked) {
        m_pTestingWidget->setOperatingKeyEnable(true);
        OMessageBoxUtil::staticNotice(0, tr( "Please blank first!" ), QStringList() << tr( "OK" ), 10);
        return;
    }
    QString result = m_pDetectionFlow->measure(m_pSettingModel);
    if (result != "Success") {
        OMessageBoxUtil::staticNotice(0, result, QStringList() << tr( "OK" ), 10);
    }
    m_pTestingWidget->setOperatingKeyEnable(true);
}


void KitMethodWindow::startFitting() {
    m_pTestingWidget->startFitting(m_pSettingModel);
}

/**
 * @brief KitMethodWindow::closeEvent
 * @param e
 */
void KitMethodWindow::closeEvent(QCloseEvent *e) {
    m_pDetectionFlow->quit();
    QFrame::closeEvent(e);
}

/**
 * @brief KitMethodWindow::flipOverAnimation
 * @param w
 */
void KitMethodWindow::flipOverAnimation(QWidget *w) {

    if (m_isAnimation) {
        QPropertyAnimation *a = new QPropertyAnimation( w, "geometry" );
        QRect rect = w->geometry();
        a->setDuration( 1000 );
        a->setStartValue( QRect( rect.topLeft(), QSize( 0, rect.height() ) ) );
        a->setEndValue( rect );
        a->setEasingCurve(QEasingCurve::OutCubic);
        a->start();
    }
}

/**
 * @brief KitMethodWindow::initializeSignals
 */
void KitMethodWindow::initializeSignals() {
    connect(m_pTestingWidget, SIGNAL(backBtnClicked()), this, SLOT(back()));
    connect(m_pTestingWidget, SIGNAL(toSettingPage()), this, SLOT(showSettingPage()));
    connect(m_pSettingWidget, SIGNAL(toTestingPage()), this, SLOT(showTestingPage()));
    connect(m_pTestingWidget, SIGNAL(toStartBlank()), this, SLOT(startBlank()));
    connect(m_pTestingWidget, SIGNAL(toStartMeasure()), this, SLOT(startMeasure()));
    connect(m_pTestingWidget, SIGNAL(toStartFitting()), this, SLOT(startFitting()));
    connect(m_pTestingWidget, SIGNAL(toUpdateSetting(QStringList)), m_pSettingWidget, SLOT(updateData(QStringList)));
    connect(m_pDetectionFlow, SIGNAL(toShowResult(double)), m_pTestingWidget, SLOT(showResult(double)));
}

/**
 * @brief KitMethodWindow::initializeWidgets
 */
void KitMethodWindow::initializeWidgets() {

    m_pSettingWidget = new KMSettingWidget();
    QHBoxLayout *settingLayout = new QHBoxLayout();
    settingLayout->addWidget(m_pSettingWidget);
    settingLayout->setMargin(0);
    ui->pageSetting->setLayout(settingLayout);

    m_pSettingModel = new KMSettingModel();
    m_pSettingModel->setMaxChannelNumber(m_pSettingWidget->getMaxChannelNumber());
    m_pSettingModel->setMeasureParameters(m_pSettingWidget->getMeasureSetting());
    m_pSettingModel->setMotorParameters(m_pSettingWidget->getMotorSetting());

    m_pTestingWidget = new KMTestingWidget();
    m_pTestingWidget->setAnimationEnable(m_isAnimation);
    m_pTestingWidget->setPlotTitle(m_pSettingWidget->getCurrentMethod());
    m_pTestingWidget->updateUnit(m_pSettingModel->getUnit());
    QHBoxLayout *testingLayout = new QHBoxLayout();
    testingLayout->addWidget(m_pTestingWidget);
    testingLayout->setMargin(0);
    ui->pageTesting->setLayout(testingLayout);
}
