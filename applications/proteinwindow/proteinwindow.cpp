#include "proteinwindow.h"
#include "ui_proteinwindow.h"

#include <QDir>
#include <QDebug>
#include <QSettings>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include "oserialport.h"
#include "ospectrograph.h"
#include "omessageboxutil.h"

#include "ptsettingmodel.h"
#include "ptdetectionflow.h"
#include "pttestingwidget.h"
#include "ptsettingwidget.h"

ProteinWindow::ProteinWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ProteinWindow) {
    ui->setupUi(this);

    m_isBlanked = false;
    m_isAnimation = true;
    m_pDetectionFlow = new PTDetectionFlow(serialPort, spectrograph, this);

    QString fileName = QDir::currentPath() + "/configs/protein/protein.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);
    m_isAnimation = configIniReader->value("/System/AnimationEnable").toBool();
    delete configIniReader;
    configIniReader = NULL;

    initializeWidgets();
    initializeSignals();
}

ProteinWindow::~ProteinWindow() {
    delete ui;
    delete m_pSettingModel;
}

/**
 * @brief ProteinWindow::back
 */
void ProteinWindow::back() {
    m_isBlanked = false;
    m_pDetectionFlow->quit();
    emit backToMainPage();
}

/**
 * @brief ProteinWindow::showTestingPage
 */
void ProteinWindow::showTestingPage() {
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
 * @brief ProteinWindow::showSettingPage
 */
void ProteinWindow::showSettingPage() {
    QWidget *page = ui->pageSetting;
    ui->stackedWidget->setCurrentWidget(page);
    m_pSettingWidget->save();
    flipOverAnimation(page);
}

/**
 * @brief ProteinWindow::startBlank
 */
void ProteinWindow::startBlank() {
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
 * @brief ProteinWindow::startMeasure
 */
void ProteinWindow::startMeasure() {
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
 * @brief ProteinWindow::closeEvent
 * @param e
 */
void ProteinWindow::closeEvent(QCloseEvent *e) {
    m_pDetectionFlow->quit();
    QFrame::closeEvent(e);
}

/**
 * @brief ProteinWindow::flipOverAnimation
 * @param w
 */
void ProteinWindow::flipOverAnimation(QWidget *w) {

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
 * @brief ProteinWindow::initializeSignals
 */
void ProteinWindow::initializeSignals() {
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
 * @brief ProteinWindow::initializeWidgets
 */
void ProteinWindow::initializeWidgets() {

    m_pSettingWidget = new PTSettingWidget();
    QHBoxLayout *settingLayout = new QHBoxLayout();
    settingLayout->addWidget(m_pSettingWidget);
    settingLayout->setMargin(0);
    ui->pageSetting->setLayout(settingLayout);

    m_pSettingModel = new PTSettingModel();
    m_pSettingModel->setMaxChannelNumber(m_pSettingWidget->getMaxChannelNumber());
    m_pSettingModel->setMeasureParameters(m_pSettingWidget->getMeasureSetting());
    m_pSettingModel->setMotorParameters(m_pSettingWidget->getMotorSetting());

    m_pTestingWidget = new PTTestingWidget();
    m_pTestingWidget->setAnimationEnable(m_isAnimation);
    m_pTestingWidget->setPlotTitle(m_pSettingWidget->getCurrentMethod());
    QHBoxLayout *testingLayout = new QHBoxLayout();
    testingLayout->addWidget(m_pTestingWidget);
    testingLayout->setMargin(0);
    ui->pageTesting->setLayout(testingLayout);
}
