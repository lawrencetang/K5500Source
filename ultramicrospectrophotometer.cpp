#include "ultramicrospectrophotometer.h"
#include "ui_ultramicrospectrophotometer.h"

#include <QDir>
#include <QDebug>
#include <QTimer>
#include <QSettings>
#include <QToolButton>
#include <QFontMetrics>
#include <QDesktopWidget>
#include <QPropertyAnimation>

#include "oscrollarea.h"
#include "oserialport.h"
#include "ocontrolpanel.h"
#include "ospectrograph.h"
#include "omessageboxutil.h"
#include "singleapplication.h"
#include "protocol.h"

#include "usunit.h"
#include "toolwindow.h"
#include "uvviswindow.h"
#include "proteinwindow.h"
#include "nanogoldwindow.h"
#include "dynamicswindow.h"
#include "kitmethodwindow.h"
#include "oligocalculator.h"
#include "microarraywindow.h"
#include "cellculturewindow.h"
#include "nucleicacidwindow.h"
#include "temperaturewindow.h"
#include "devicecheckwindow.h"

#define STATUSBAR_FONT_SIZE   9

UltramicroSpectrophotometer::UltramicroSpectrophotometer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UltramicroSpectrophotometer) {

    ui->setupUi(this);
    initializeSystems();
    initializeWidgets();
    initializeSignals();
    installStyleSheet();
}

UltramicroSpectrophotometer::~UltramicroSpectrophotometer() {
    delete ui;
}

/**
 * @brief UltramicroSpectrophotometer::receiveAppMessage
 * @param messages
 */
void UltramicroSpectrophotometer::receiveAppMessage(QStringList messages) {
    Q_UNUSED(messages)
    ((SingleApplication *)qApp)->BringWindowToTop(this->winId());
}

/**
 * @brief MainWindow::changePage
 */
void UltramicroSpectrophotometer::changePage() {

    QToolButton *tBtn = (QToolButton *)sender();
    if (m_tBtnPagerMapper.contains(tBtn)) {
        QWidget *page = m_tBtnPagerMapper.value(tBtn);
        ui->stackedWidget->setCurrentWidget(page);
        flipOverAnimation(page);
    }
}

/**
 * @brief MainWindow::toMainPage
 */
void UltramicroSpectrophotometer::toMainPage() {
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    flipOverAnimation(ui->pageMain);
}

/**
 * @brief UltramicroSpectrophotometer::selfChecking
 */
void UltramicroSpectrophotometer::selfChecking() {

    //qDebug() << "selfChecking";
    //  1.检查串口
    if (NULL != m_pSerialPort) {
        if (m_pSerialPort->serialPortName().isEmpty()) {
            m_pSelfCheckingTimer->stop();
            m_pSerialPort->closeSerialPort();
            if (m_pSpectrograph->isOpened()) {
                m_pSpectrograph->closeSpectrograph();
            }
            m_pToolWindow->setBackEnable(false);
            ui->stackedWidget->setCurrentWidget(m_pToolWindow);
            showStatusMessage(tr( "Connect failed! Starting reconnection later, Please waiting..." ), m_company);
            m_pReconnectingTimer->start(m_reconnectingTime);
            return;
        }
    }

    // 2.检查光谱
    if (m_pSpectrograph->serialNumber().isEmpty()) {
        m_pSelfCheckingTimer->stop();
        if (NULL != m_pSerialPort) {
            m_pSerialPort->closeSerialPort();
        }
        if (m_pSpectrograph->isOpened()) {
            m_pSpectrograph->closeSpectrograph();
        }
        m_pToolWindow->setBackEnable(false);
        ui->stackedWidget->setCurrentWidget(m_pToolWindow);
        showStatusMessage(tr( "Connect failed! Starting reconnection later, Please waiting..." ), m_company);
        m_pReconnectingTimer->start(m_reconnectingTime);
    }
}

/**
 * @brief UltramicroSpectrophotometer::reconnecting
 */
void UltramicroSpectrophotometer::reconnecting() {

    //qDebug() << "reconnecting";
    m_rCount ++;
    m_pReconnectingTimer->stop();
    QString errCode = openDevice();
    if (errCode != "Success") {
        m_pReconnectingTimer->start(m_reconnectingTime);
        showStatusMessage(tr( "Connect failed! Please waiting for next time(%1)..." ).arg(m_rCount), m_company);
        return;
    }
    m_rCount = 0;
    m_pToolWindow->setBackEnable(true);
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    m_pSelfCheckingTimer->start(m_selfCheckingTime);
}

/**
 * @brief UltramicroSpectrophotometer::checkDevice
 * @return
 */
bool UltramicroSpectrophotometer::checkDevice() {

    QString fileName = QDir::currentPath() + "/configs/device.ini";
    QSettings *configIniWriter = new QSettings( fileName, QSettings::IniFormat );

    if(!m_obaitn_sn_s) {
        if(m_sn_s != m_pSpectrograph->serialNumber()) {
            OMessageBoxUtil::staticNotice(0, tr("Spectrograph mismatching!"), QStringList() << tr("OK"), 10);
            return false;
        }
    } else {
        configIniWriter->setValue("Spectrograph/Sn", m_pSpectrograph->serialNumber());
        configIniWriter->setValue("Spectrograph/Obtain", false);
    }

    if (m_pSerialPort != NULL) {

        QByteArray rxBuffer;
        QByteArray txBuffer = USUnit::getControllerSn(m_id_c);
        qDebug() << "checkDevice:" << toHexStr(txBuffer);
        QString result = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, 3000);
        qDebug() << "checkDevice:" << toHexStr(txBuffer);
        if(result != "Success") {
            OMessageBoxUtil::staticNotice(0, tr("Get controller sn failed!"), QStringList() << tr("OK"), 10);
            return false;
        }

        QString snStr = USUnit::decodingSerialNumber(rxBuffer);
        if(!m_obaitn_sn_c) {
            if (m_sn_c != snStr) {
                OMessageBoxUtil::staticNotice(0, tr("Controller mismatching!"), QStringList() << tr("OK"), 10);
                return false;
            }
        } else {
            configIniWriter->setValue("Controller/Sn", snStr);
            configIniWriter->setValue("Controller/Obtain", false);
        }
    }

    delete configIniWriter;
    configIniWriter = NULL;
    return true;
}

/**
 * @brief UltramicroSpectrophotometer::resetDevice
 */
void UltramicroSpectrophotometer::resetDevice() {

    if (m_pSerialPort != NULL) {
        QByteArray rxBuffer;
        QByteArray txBuffer = USUnit::stopStepMotor(MOTOR_01);
        qDebug() << "Stop:" << toHexStr(txBuffer);
        m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, 3000);
        qDebug() << "Stop:" << toHexStr(rxBuffer);

        txBuffer = USUnit::stopStepMotor(MOTOR_02);
        qDebug() << "Stop:" << toHexStr(txBuffer);
        m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, 3000);
        qDebug() << "Stop:" << toHexStr(rxBuffer);

        txBuffer = USUnit::stopDcMotor(MIXING_MOTOR_01);
        qDebug() << "Stop:" << toHexStr(txBuffer);
        m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, 3000);
        qDebug() << "Stop:" << toHexStr(rxBuffer);

        txBuffer = USUnit::stopThermostat(THERMOSTAT);
        qDebug() << "Stop:" << toHexStr(txBuffer);
        m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, 3000);
        qDebug() << "Stop:" << toHexStr(rxBuffer);

        txBuffer = USUnit::startStepMotor(MOTOR_01, 0);
        qDebug() << "Zero:" << toHexStr(txBuffer);
        m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, 3000);
        qDebug() << "Zero:" << toHexStr(rxBuffer);

        if (m_channelNumber == 8) {
            txBuffer = USUnit::startStepMotor(MOTOR_02, 0);
            qDebug() << "Zero:" << toHexStr(txBuffer);
            m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, 3000);
            qDebug() << "Zero:" << toHexStr(rxBuffer);
        }
    }
}

/**
 * @brief UltramicroSpectrophotometer::openDevice
 * @return
 */
QString UltramicroSpectrophotometer::openDevice() {

    // 1.连接串口
    QString leftMessage = tr( "Connected! " );
    QString errCode = "Success";
    if (NULL != m_pSerialPort) {
        errCode = m_pSerialPort->openSerialPort(m_pSerialPort->serialPortName());
        if (errCode != "Success") {
            return errCode;
        }
        leftMessage.append( tr("Controller Port:%1 ").arg(m_pSerialPort->serialPortName()) );
    }

    // 2.连接光谱
    errCode = m_pSpectrograph->openSpectrograph();
    if (errCode != "Success") {
        if (NULL != m_pSerialPort) {
            m_pSerialPort->closeSerialPort();
        }
        m_pSpectrograph->closeSpectrograph();
    }
    leftMessage.append( tr( "Spectrograph ID:%1 " ).arg(m_pSpectrograph->serialNumber()) );
    showStatusMessage(leftMessage, m_company);
    return errCode;
}

/**
 * @brief UltramicroSpectrophotometer::showStatusMessage
 * @param leftMessage
 * @param rightMessage
 */
void UltramicroSpectrophotometer::showStatusMessage(QString leftMessage, QString rightMessage) {
    QFontMetrics fm( QFont("\"微软雅黑\"", STATUSBAR_FONT_SIZE) );
    int times = (1280 - fm.width(leftMessage) - fm.width(rightMessage) - 40)/fm.width( " " );
    QString text = leftMessage + QString( " " ).repeated(times) + rightMessage;
    ui->statusBar->showMessage(text);
}

/**
 * @brief MainWindow::flipOverAnimation
 * @param w
 */
void UltramicroSpectrophotometer::flipOverAnimation(QWidget *w) {

    if (m_isAnimation) {
        QPropertyAnimation *a = new QPropertyAnimation( w, "geometry" );
        QRect rect = w->geometry();
        a->setDuration( 1000 );
        a->setStartValue( QRect(rect.center(), QSize(0, 0)) );
        a->setEndValue( rect );
        a->setEasingCurve(QEasingCurve::OutCubic);
        a->start();
    }
}

/**
 * @brief UltramicroSpectrophotometer::initializeSystems
 */
void UltramicroSpectrophotometer::initializeSystems() {

    QString fileName = QDir::currentPath() + "/configs/system.ini";
    QSettings *configIniReader = new QSettings( fileName, QSettings::IniFormat );
    bool serialPortEnable = configIniReader->value( "/System/SerialPortEnable" ).toBool();//lt:->value是qvariant值
    m_selfCheckingTime = configIniReader->value( "/System/SelfCheckingTime" ).toInt();
    m_reconnectingTime = configIniReader->value( "/System/ReconnectingTime" ).toInt();
    m_company = configIniReader->value( "/System/Company" ).toString();//lt:理解：qvariant是先把数据保存为二进制再通过toxxx上下文决定该二进制表示的数据类型
    m_applicationNameList = configIniReader->value("/System/Applications").toStringList();
    m_channelNumber = configIniReader->value("/System/ChannelNumber").toInt();//lt:1
    m_isAnimation = configIniReader->value("/System/AnimationEnable").toBool();
    delete configIniReader;
    configIniReader = NULL;

    fileName = QDir::currentPath() + "/configs/device.ini";
    configIniReader = new QSettings( fileName, QSettings::IniFormat );
    m_obaitn_sn_s = configIniReader->value( "/Spectrograph/Obtain" ).toBool();
    m_sn_s = configIniReader->value( "/Spectrograph/Sn" ).toString(); //lt:光谱的序列号
    m_obaitn_sn_c = configIniReader->value( "/Controller/Obtain" ).toBool();
    m_sn_c = configIniReader->value( "/Controller/Sn" ).toString();
    m_id_c = configIniReader->value( "/Controller/Id" ).toInt();
    delete configIniReader;
    configIniReader = NULL;//lt:配置光谱仪参数

    m_rCount = 0;
    m_pSpectrograph = new OSpectrograph(this);
    m_pSerialPort = serialPortEnable?new OSerialPort(this):NULL;//lt:使能serialportenable则为该类指针赋值

    m_pSelfCheckingTimer = new QTimer(this);
    m_pReconnectingTimer = new QTimer(this);
    connect(m_pSelfCheckingTimer, SIGNAL(timeout()), this, SLOT(selfChecking()));//lt:未开始计时,仅将信号和槽连接起来
    connect(m_pReconnectingTimer, SIGNAL(timeout()), this, SLOT(reconnecting()));

    ui->statusBar->setStyleSheet(QString("QStatusBar#statusBar{font: %1pt \"微软雅黑\";color: white;}").arg(STATUSBAR_FONT_SIZE));//lt:9号字体,白色
    //lt:id选择器：匹配所有object name为statusBar的QStatusBar对象实例
}

/**
 * @brief MainWindow::initializeSignals
 */
void UltramicroSpectrophotometer::initializeSignals() {
    QList<QToolButton *> tBtnList = m_tBtnPagerMapper.keys();
    for (int i = 0; i < tBtnList.size(); i++){
        connect(tBtnList.at(i), SIGNAL(clicked(bool)), this, SLOT(changePage()));
    }
    connect(m_pNucleicAcidWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pProteinWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pUvVisWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pCellCultureWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pNanoGoldWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pMicroArrayWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pKitMethodWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pDynamicsWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pDeviceCheckWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pTemperatureWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pOligoCalculator, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
    connect(m_pToolWindow, SIGNAL(backToMainPage()), this, SLOT(toMainPage()));
}

/**
 * @brief MainWindow::initializeWidget
 */
void UltramicroSpectrophotometer::initializeWidgets() {

    qDeleteAll(m_tBtnPagerMapper);
    m_tBtnPagerMapper.clear();

    // 核酸-蛋白-微阵列-全波长-试剂盒-细胞液-纳米金-动力学,需要与panel中对应//lt:即m_application变量中
    QList<QWidget *> pageList;
    m_pNucleicAcidWindow = new NucleicAcidWindow(m_pSerialPort, m_pSpectrograph);
    m_pProteinWindow = new ProteinWindow(m_pSerialPort, m_pSpectrograph);
    m_pMicroArrayWindow = new MicroArrayWindow(m_pSerialPort, m_pSpectrograph);
    m_pUvVisWindow = new UvVisWindow(m_pSerialPort, m_pSpectrograph);
    m_pCellCultureWindow = new CellCultureWindow(m_pSerialPort, m_pSpectrograph);
    m_pNanoGoldWindow = new NanoGoldWindow(m_pSerialPort, m_pSpectrograph);
    m_pDynamicsWindow = new DynamicsWindow(m_pSerialPort, m_pSpectrograph);
    m_pKitMethodWindow = new KitMethodWindow(m_pSerialPort, m_pSpectrograph);

    m_pDeviceCheckWindow = new DeviceCheckWindow(m_pSerialPort, m_pSpectrograph);
    m_pToolWindow = new ToolWindow();
    m_pTemperatureWindow = new TemperatureWindow(m_pSerialPort);
    m_pOligoCalculator = new OligoCalculator();

    ui->stackedWidget->addWidget(m_pNucleicAcidWindow);//lt:核酸
    ui->stackedWidget->addWidget(m_pProteinWindow);//lt:蛋白
    ui->stackedWidget->addWidget(m_pMicroArrayWindow);//lt:微阵列
    ui->stackedWidget->addWidget(m_pUvVisWindow);//lt:全波长
    ui->stackedWidget->addWidget(m_pKitMethodWindow);//lt:试剂盒
    ui->stackedWidget->addWidget(m_pCellCultureWindow);//lt:细胞液
    ui->stackedWidget->addWidget(m_pNanoGoldWindow);//lt:胶体金
    ui->stackedWidget->addWidget(m_pDynamicsWindow);//lt:动态
    ui->stackedWidget->addWidget(m_pDeviceCheckWindow);//lt:设备检测
    if (m_pSerialPort != NULL) {
        ui->stackedWidget->addWidget(m_pTemperatureWindow);//lt:温度检测
    }
    ui->stackedWidget->addWidget(m_pOligoCalculator);//lt:计算器
    ui->stackedWidget->addWidget(m_pToolWindow);//lt:工具箱,加到stackedwidget中

    pageList << m_pNucleicAcidWindow << m_pProteinWindow << m_pMicroArrayWindow << m_pUvVisWindow
             << m_pKitMethodWindow << m_pCellCultureWindow << m_pNanoGoldWindow << m_pDynamicsWindow
             << m_pDeviceCheckWindow;
    if (m_pSerialPort != NULL) {
        pageList << m_pTemperatureWindow;
    }
    pageList << m_pOligoCalculator << m_pToolWindow;//lt:widget加到pagelist中

    OControlPanel *panel = new OControlPanel(m_applicationNameList, 4);//lt:由配置文件system调入,panel为4列
    m_tBtnPagerMapper = panel->makeControlMapper(pageList);//lt:在qmap中将button和widget对应
    OScrollArea *scrollArea = new OScrollArea(ui->pageMain);
    scrollArea->setWidget(panel);//lt:panel可移动

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(scrollArea);
    ui->pageMain->setLayout(mainLayout);

    QString errCode = openDevice();
    if (errCode == "Success") {
        if(!checkDevice()) {
            m_pToolWindow->setBackEnable(false);
            ui->stackedWidget->setCurrentWidget(m_pToolWindow);
        } else {
            m_pReconnectingTimer->stop();
            m_pSelfCheckingTimer->start(m_selfCheckingTime);
            resetDevice();
        }
    } else {
        m_pToolWindow->setBackEnable(false);
        ui->stackedWidget->setCurrentWidget(m_pToolWindow);
        OMessageBoxUtil::staticNotice(0, errCode, QStringList()<<tr( "OK" ), 10);
        showStatusMessage(tr( "Connect failed! Starting reconnection later, Please waiting..." ), m_company);

        m_pSelfCheckingTimer->stop();
        m_pReconnectingTimer->start(m_reconnectingTime);
    }
}

/**
 * @brief MainWindow::installStyleSheet
 */
void UltramicroSpectrophotometer::installStyleSheet() {

    QString backgroundPath = QDir::currentPath() + "/images/background/background.jpg";
    QString backgroundStyleSheet = QString("QMainWindow { background-image: url(%1); }").arg( backgroundPath );
    setStyleSheet(backgroundStyleSheet);
}
