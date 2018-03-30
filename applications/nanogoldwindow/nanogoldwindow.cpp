#include "nanogoldwindow.h"
#include "ui_nanogoldwindow.h"

#include <QDir>
#include <QDebug>
#include <QSettings>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include "oserialport.h"
#include "ospectrograph.h"
#include "omessageboxutil.h"

#include "ngsettingmodel.h"
#include "ngdetectionflow.h"
#include "ngtestingwidget.h"
#include "ngsettingwidget.h"

NanoGoldWindow::NanoGoldWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::NanoGoldWindow) {
    ui->setupUi(this);

    m_isBlanked = false;
    m_isAnimation = true;
    m_pDetectionFlow = new NGDetectionFlow(serialPort, spectrograph, this);

    QString fileName = QDir::currentPath() + "/configs/nanogold/nanogold.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);
    m_isAnimation = configIniReader->value("/System/AnimationEnable").toBool();
    delete configIniReader;
    configIniReader = NULL;

    initializeWidgets();
    initializeSignals();
}

NanoGoldWindow::~NanoGoldWindow() {
    delete ui;
    delete m_pSettingModel;
}

/**
 * @brief NanoGoldWindow::back
 */
void NanoGoldWindow::back() {
    m_isBlanked = false;
    m_pDetectionFlow->quit();
    emit backToMainPage();
}

/**
 * @brief NanoGoldWindow::showTestingPage
 */
void NanoGoldWindow::showTestingPage() {
    if (sender() == m_pSettingWidget) {
        m_pSettingModel->setMaxChannelNumber(m_pSettingWidget->getMaxChannelNumber());
        m_pSettingModel->setMeasureParameters(m_pSettingWidget->getMeasureSetting());
        m_pSettingModel->setMotorParameters(m_pSettingWidget->getMotorSetting());
    }
    m_pTestingWidget->setPlotTitle(m_pSettingWidget->getCurrentMethod());
    QWidget *page = ui->pageTesting;
    ui->stackedWidget->setCurrentWidget(page);
    flipOverAnimation(page);
}

/**
 * @brief NanoGoldWindow::showSettingPage
 */
void NanoGoldWindow::showSettingPage() {
    QWidget *page = ui->pageSetting;
    ui->stackedWidget->setCurrentWidget(page);
    m_pSettingWidget->save();
    flipOverAnimation(page);
}

/**
 * @brief NanoGoldWindow::startBlank
 */
void NanoGoldWindow::startBlank() {
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
 * @brief NanoGoldWindow::startMeasure
 */
void NanoGoldWindow::startMeasure() {
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

/**
 * @brief NanoGoldWindow::closeEvent
 * @param e
 */
void NanoGoldWindow::closeEvent(QCloseEvent *e) {
    m_pDetectionFlow->quit();
    QFrame::closeEvent(e);
}

/**
 * @brief NanoGoldWindow::flipOverAnimation
 * @param w
 */
void NanoGoldWindow::flipOverAnimation(QWidget *w) {

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
 * @brief NanoGoldWindow::initializeSignals
 */
void NanoGoldWindow::initializeSignals() {
    connect(m_pTestingWidget, SIGNAL(backBtnClicked()), this, SLOT(back()));
    connect(m_pTestingWidget, SIGNAL(toSettingPage()), this, SLOT(showSettingPage()));
    connect(m_pSettingWidget, SIGNAL(toTestingPage()), this, SLOT(showTestingPage()));
    connect(m_pTestingWidget, SIGNAL(toStartBlank()), this, SLOT(startBlank()));
    connect(m_pTestingWidget, SIGNAL(toStartMeasure()), this, SLOT(startMeasure()));

    connect(m_pDetectionFlow, SIGNAL(toDrawCurve(QString,QVector<double>,QVector<double>)),
            m_pTestingWidget, SLOT(drawStaticCurve(QString,QVector<double>,QVector<double>)));

    connect(m_pDetectionFlow, SIGNAL(toSaveResult(QString,QStringList)),
            m_pTestingWidget, SLOT(saveResult(QString,QStringList)));

    connect(m_pDetectionFlow, SIGNAL(toSaveRecord(QStringList)),
            m_pTestingWidget, SLOT(saveRecord(QStringList)));
}

/**
 * @brief NanoGoldWindow::initializeWidgets
 */
void NanoGoldWindow::initializeWidgets() {

    m_pSettingWidget = new NGSettingWidget();
    QHBoxLayout *settingLayout = new QHBoxLayout();
    settingLayout->addWidget(m_pSettingWidget);
    settingLayout->setMargin(0);
    ui->pageSetting->setLayout(settingLayout);

    m_pSettingModel = new NGSettingModel();
    m_pSettingModel->setMaxChannelNumber(m_pSettingWidget->getMaxChannelNumber());
    m_pSettingModel->setMeasureParameters(m_pSettingWidget->getMeasureSetting());
    m_pSettingModel->setMotorParameters(m_pSettingWidget->getMotorSetting());

    m_pTestingWidget = new NGTestingWidget();
    m_pTestingWidget->setAnimationEnable(m_isAnimation);
    m_pTestingWidget->setPlotTitle(m_pSettingWidget->getCurrentMethod());
    QHBoxLayout *testingLayout = new QHBoxLayout();
    testingLayout->addWidget(m_pTestingWidget);
    testingLayout->setMargin(0);
    ui->pageTesting->setLayout(testingLayout);
}
