#include "devicecheckwindow.h"
#include "ui_devicecheckwindow.h"

#include <QDir>
#include <QDebug>
#include <QListView>
#include <QSettings>
#include <QElapsedTimer>
#include <QCoreApplication>

#include "oplot.h"
#include "usunit.h"
#include "omessagebox.h"
#include "oserialport.h"
#include "ospectrograph.h"
#include "odigitkeyboard.h"
#include "omessageboxutil.h"
#include "opticalintensity.h"

#define TIMEOUT 3000

DeviceCheckWindow::DeviceCheckWindow(OSerialPort *serialPort, OSpectrograph *spectrograph, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DeviceCheckWindow) {
    ui->setupUi(this);

    m_pSerialPort = serialPort;
    m_pSpectrograph = spectrograph;

    initializeSystem();
    initializeWidget();
    initializeSignal();
}

DeviceCheckWindow::~DeviceCheckWindow() {
    delete ui;
}

/**
 * @brief DeviceCheckWindow::closeEvent
 * @param event
 */
void DeviceCheckWindow::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    if (m_isWaiting) {
        m_isWaiting = false;
    }
}

/**
 * @brief DeviceCheckWindow::clearCurves
 */
void DeviceCheckWindow::clearCurves() {
    int ok = OMessageBoxUtil::staticNotice(0, tr("Do you want to clear all curves?"),
                                           QStringList()<<tr("OK")<<tr("Cancel"), 10);
    if (ok == 0) {
        m_pPlot->clearCurves();
    }
}

/**
 * @brief DeviceCheckWindow::excuteCheck
 */
void DeviceCheckWindow::excuteCheck() {

    OMessageBox *messageBox = OMessageBoxUtil::dynamicNotice(this, tr( "Checking, Please waiting..." ));
    m_pPlot->clearCurves();
    int it = 0, rc = 0, ra = 0;
    if (ui->comboBoxMethod->currentText() == "Cuvette") {

        it = ui->spinBoxIntergralTime->value();
        rc = m_cuvetteFrequency;
    } else {

        int i = ui->comboBoxOptical->currentIndex();
        it = ui->spinBoxIntergralTime->value();
        if (i >= 0 && i < m_microscaleFrequency.size()) {
            QString rcStr = m_microscaleFrequency.at(i);
            rc = rcStr.toInt();
        }
        if (i >= 0 && i < m_microscaleRotateAngle.size()) {
            QString raStr = m_microscaleRotateAngle.at(i);
            ra = raStr.toInt();
        }

        // 1.运行到选择的光程
        if (m_pSerialPort != NULL) {
            QByteArray rxBuffer;
            QByteArray txBuffer = USUnit::startStepMotor(MOTOR_01, ra*10);
            qDebug() << "Optical order:" << toHexStr(txBuffer);
            QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << "Optical order:" << toHexStr(rxBuffer);
            if (ok != "Success") {
                messageBox->close();
                OMessageBoxUtil::staticNotice(0, ok, QStringList()<<"OK", 10);
                return;
            }
            delay(500);
        }

        // 2.运行到选择的通道
        if (m_pSerialPort != NULL && m_channelNumber != 1) {
            QByteArray rxBuffer;
            double targetAngle = ui->comboBoxChannel->currentIndex()*10/m_channelNumber;
            QByteArray txBuffer = USUnit::startStepMotor(MOTOR_02, targetAngle);
            qDebug() << "Channel order:" << toHexStr(txBuffer);
            QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << "Channel order:" << toHexStr(rxBuffer);
            if (ok != "Success") {
                messageBox->close();
                OMessageBoxUtil::staticNotice(0, ok, QStringList()<<"OK", 10);
                return;
            }
            delay(500);
        }
    }

    OpticalIntensity intensity = m_pSpectrograph->readSpectrograph(it, rc);
    m_pPlot->drawStaticCurve("Check", intensity.waveLength(), intensity.intensity());

    if (ui->comboBoxMethod->currentText() == "Microscale") {
        // 1.复位通道
        if (m_pSerialPort != NULL && m_channelNumber != 1) {
            QByteArray rxBuffer;
            QByteArray txBuffer = USUnit::startStepMotor(MOTOR_02, 0);
            qDebug() << "Channel order:" << toHexStr(txBuffer);
            QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << "Channel order:" << toHexStr(rxBuffer);
            if (ok != "Success") {
                messageBox->close();
                OMessageBoxUtil::staticNotice(0, ok, QStringList()<<"OK", 10);
                return;
            }
            delay(500);
        }

        // 2.复位光程
        if (m_pSerialPort != NULL) {
            QByteArray rxBuffer;
            QByteArray txBuffer = USUnit::startStepMotor(MOTOR_01, 0);
            qDebug() << "Optical order:" << toHexStr(txBuffer);
            QString ok = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << "Optical order:" << toHexStr(rxBuffer);
            if (ok != "Success") {
                messageBox->close();
                OMessageBoxUtil::staticNotice(0, ok, QStringList()<<"OK", 10);
                return;
            }
            delay(500);
        }
    }
    messageBox->close();
}

/**
 * @brief DeviceCheckWindow::changeMethod
 * @param method
 */
void DeviceCheckWindow::changeMethod(QString method) {

    disconnect(ui->comboBoxOptical, SIGNAL(currentIndexChanged(QString)),
               this, SLOT(changeOptical(QString)));
    ui->comboBoxOptical->clear();
    int iTime = 0;
    if (method == "Microscale") {
        ui->comboBoxOptical->addItems(m_microscaleOptical);
        QString iTimeStr = m_microscaleIntegrationTime.first();
        iTime = iTimeStr.toInt();
    } else {
        iTime = m_cuvetteIntegrationTime;
    }
    ui->spinBoxIntergralTime->setValue(iTime);
    ui->labelChannel->setVisible(method == "Microscale" && m_channelNumber != 1);
    ui->comboBoxChannel->setVisible(method == "Microscale" && m_channelNumber != 1);
    ui->labelOptical->setVisible(method == "Microscale" && m_microscaleOptical.size() != 1);
    ui->comboBoxOptical->setVisible(method == "Microscale" && m_microscaleOptical.size() != 1);
    connect(ui->comboBoxOptical, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(changeOptical(QString)));
}

/**
 * @brief DeviceCheckWindow::changeOptical
 * @param optical
 */
void DeviceCheckWindow::changeOptical(QString optical) {
    if (ui->comboBoxMethod->currentText() == "Cuvette") {
        ui->spinBoxIntergralTime->setValue(m_cuvetteIntegrationTime);
    } else {
        int index = m_microscaleOptical.indexOf(optical);
        if (index >= 0 &&
                index < m_microscaleIntegrationTime.size()) {
            QString iTime = m_microscaleIntegrationTime.at(index);
            ui->spinBoxIntergralTime->setValue(iTime.toInt());
        }
    }
}

/**
 * @brief DeviceCheckWindow::delay
 * @param timeout
 */
void DeviceCheckWindow::delay(int timeout) {
    QElapsedTimer t;
    t.start();
    m_isWaiting = true;
    while(t.elapsed() < timeout) {
        QCoreApplication::processEvents();
        if (!m_isWaiting) {
            return;
        }
    }
    m_isWaiting = false;
}

/**
 * @brief DeviceCheckWindow::initializeSystem
 */
void DeviceCheckWindow::initializeSystem() {

    QString fileName = QDir::currentPath() + "/configs/optical.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);

    m_microscaleOptical = configIniReader->value("Microscale/Optical").toStringList();
    m_microscaleIntegrationTime = configIniReader->value("Microscale/IntegrationTime").toStringList();
    m_microscaleFrequency = configIniReader->value("Microscale/Frequency").toStringList();
    m_microscaleRotateAngle = configIniReader->value("Microscale/RotateAngle").toStringList();
    m_microscaleFactor = configIniReader->value("Microscale/CorrectionFactor").toStringList();

    m_cuvetteOptical = configIniReader->value("Cuvette/Optical").toStringList();
    m_cuvetteIntegrationTime = configIniReader->value("Cuvette/IntegrationTime").toInt();
    m_cuvetteFrequency = configIniReader->value("Cuvette/Frequency").toInt();
    m_cuvetteFactor = configIniReader->value("Cuvette/CorrectionFactor").toDouble();

    delete configIniReader;
    configIniReader = NULL;
}

/**
 * @brief DeviceCheckWindow::initializeWidget
 */
void DeviceCheckWindow::initializeWidget() {

    QString fileName = QDir::currentPath() + "/configs/devicecheck/devicecheck.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);

    m_pPlot = new OPlot();
    m_pPlot->setPlotTitle(configIniReader->value("Plot/Title").toString());
    m_pPlot->setAxisXLabel(configIniReader->value("Plot/XAxisText").toString());
    m_pPlot->setAxisYLabel(configIniReader->value("Plot/YAxisText").toString());
    m_pPlot->uninstallZoomer();
    m_pPlot->setAxisXScale(configIniReader->value("Plot/XAxisMinVaule").toDouble(),
                           configIniReader->value("Plot/XAxisMaxVaule").toDouble());
    m_pPlot->setAxisYScale(configIniReader->value("Plot/YAxisMinVaule").toDouble(),
                           configIniReader->value("Plot/YAxisMaxVaule").toDouble());
    m_pPlot->addRulers(configIniReader->value("Plot/RulerCount").toInt(),
                       configIniReader->value("Plot/RulerPosition").toStringList());
    m_pPlot->addDynamicCureves(configIniReader->value("Plot/DynamicsCurves").toStringList());
    m_pPlot->installZoomer();

    ui->comboBoxMethod->setView(new QListView());
    ui->comboBoxMethod->addItems(configIniReader->value("Setting/Method").toStringList());

    QStringList channels;
    m_channelNumber = configIniReader->value("Setting/ChannelNumber").toInt();
    for (int i = 0; i < m_channelNumber; i ++) {
        channels << QString::number(i + 1);
    }
    ui->comboBoxChannel->setView(new QListView());
    ui->comboBoxChannel->addItems(channels);

    QHBoxLayout *plotLayout = new QHBoxLayout();
    plotLayout->addWidget(m_pPlot);
    plotLayout->setMargin(0);
    ui->framePlot->setLayout(plotLayout);

    ui->framePlot->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255));
    ui->framePlot->setPalette(palette);

    m_pKeyboard = new ODigitKeyboard(this, this);
    m_pKeyboard->setKeySize(QSize(64, 64));
    QHBoxLayout *keyboardLayout = new QHBoxLayout();
    keyboardLayout->addWidget(m_pKeyboard);
    keyboardLayout->setMargin(0);
    ui->frameKeyboard->setLayout(keyboardLayout);

    delete configIniReader;
    configIniReader = NULL;

    QString method = ui->comboBoxMethod->currentText();
    ui->labelOptical->setVisible(method == "Microscale" && m_microscaleOptical.size() != 1);
    ui->comboBoxOptical->setVisible(method == "Microscale" && m_microscaleOptical.size() != 1);
    ui->labelChannel->setVisible(method == "Microscale" && m_channelNumber != 1);
    ui->comboBoxChannel->setVisible(method == "Microscale" && m_channelNumber != 1);

    ui->comboBoxOptical->setView(new QListView());
    ui->comboBoxOptical->addItems(m_microscaleOptical);

    QString iTime = m_microscaleIntegrationTime.first();
    ui->spinBoxIntergralTime->setValue(iTime.toInt());
}

/**
 * @brief DeviceCheckWindow::initializeSignal
 */
void DeviceCheckWindow::initializeSignal() {

    connect(ui->comboBoxMethod, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(changeMethod(QString)));

    connect(ui->comboBoxOptical, SIGNAL(currentIndexChanged(QString)),
            this, SLOT(changeOptical(QString)));

    connect(ui->toolButtonBack, SIGNAL(clicked(bool)), this, SIGNAL(backToMainPage()));

    connect(ui->toolButtonCheck, SIGNAL(clicked(bool)), this, SLOT(excuteCheck()));

    connect(ui->toolButtonClear, SIGNAL(clicked(bool)), this, SLOT(clearCurves()));
}
