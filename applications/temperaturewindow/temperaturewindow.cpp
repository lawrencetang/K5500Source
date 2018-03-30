#include "temperaturewindow.h"
#include "ui_temperaturewindow.h"

#include <QDebug>
#include <QTimer>

#include "usunit.h"
#include "cqdial.h"
#include "oserialport.h"
#include "odigitkeyboard.h"
#include "omessageboxutil.h"

#define TIMEOUT 3000

TemperatureWindow::TemperatureWindow(OSerialPort *serialPort, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::TemperatureWindow) {
    ui->setupUi(this);

    m_pSerialPort = serialPort;
    m_pKeyboard = new ODigitKeyboard(this, this);
    QHBoxLayout *keyboardLayout = new QHBoxLayout();
    keyboardLayout->addWidget(m_pKeyboard);
    ui->frameKeyboard->setLayout(keyboardLayout);

    m_pDial = new CqDial();
    m_pDial->setScaleStepSize( 10.0 );
    m_pDial->setScale( 0.0, 120.0 );
    m_pDial->setLineWidth( 10 );
    QHBoxLayout *dialLayout = new QHBoxLayout();
    dialLayout->addWidget( m_pDial );
    dialLayout->setMargin( 0 );
    ui->frameDial->setLayout( dialLayout );

    m_pTimer = new QTimer();

    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(showTemperature()));
    connect(ui->toolButtonRun, SIGNAL(clicked(bool)), this, SLOT(onRunBtnClicked()));
    connect(ui->toolButtonBack, SIGNAL(clicked(bool)), this, SLOT(onBackBtnClicked()));

}

TemperatureWindow::~TemperatureWindow() {
    delete ui;
}

/**
 * @brief TemperatureWindow::closeEvent
 * @param event
 */
void TemperatureWindow::closeEvent(QCloseEvent *event) {
    Q_UNUSED(event);
    if (m_pSerialPort != NULL) {
        QByteArray rxBuffer;
        QByteArray txBuffer = USUnit::stopThermostat(THERMOSTAT);
        qDebug() << toHexStr(txBuffer);
        QString result = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
        qDebug() << toHexStr(rxBuffer);
        if (result != "Success") {
            OMessageBoxUtil::staticNotice(0, tr("Stop thermostat failed!"), QStringList() << tr("OK"), 10);
            return;
        }
    }
}

/**
 * @brief TemperatureWindow::onRunBtnClicked
 */
void TemperatureWindow::onRunBtnClicked() {

    if (ui->toolButtonRun->text() == "Start") {

        if (m_pSerialPort != NULL) {
            QByteArray rxBuffer;
            QByteArray txBuffer = USUnit::startThermostat(THERMOSTAT, ui->doubleSpinBoxTarget->value()*10);
            qDebug() << toHexStr(txBuffer);
            QString result = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << toHexStr(rxBuffer);
            if (result != "Success") {
                OMessageBoxUtil::staticNotice(0, tr("Start thermostat failed!"), QStringList() << tr("OK"), 10);
                return;
            }
        }

        m_pTimer->start(1000);
        ui->doubleSpinBoxTarget->setReadOnly(true);
        ui->toolButtonRun->setText("Stop");
        ui->toolButtonRun->setIcon(QIcon(":/temperature_icons/stop.png"));
    } else {
        m_pTimer->stop();
        if (m_pSerialPort != NULL) {
            QByteArray rxBuffer;
            QByteArray txBuffer = USUnit::stopThermostat(THERMOSTAT);
            qDebug() << toHexStr(txBuffer);
            QString result = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << toHexStr(rxBuffer);
            if (result != "Success") {
                OMessageBoxUtil::staticNotice(0, tr("Stop thermostat failed!"), QStringList() << tr("OK"), 10);
                return;
            }
        }

        ui->doubleSpinBoxTarget->setReadOnly(false);
        ui->toolButtonRun->setText("Start");
        ui->toolButtonRun->setIcon(QIcon(":/temperature_icons/run.png"));
    }
}

/**
 * @brief TemperatureWindow::onBackBtnClicked
 */
void TemperatureWindow::onBackBtnClicked() {

    if (ui->toolButtonRun->text() == "Stop") {

        m_pTimer->stop();
        int result = OMessageBoxUtil::staticNotice(0, tr("Do you want to close !"), QStringList() << tr("OK") << tr("Cancel"), 10);
        if (result != 0) {
            return;
        }

        if (m_pSerialPort != NULL) {
            QByteArray rxBuffer;
            QByteArray txBuffer = USUnit::stopThermostat(THERMOSTAT);
            qDebug() << toHexStr(txBuffer);
            QString result = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
            qDebug() << toHexStr(rxBuffer);
            if (result != "Success") {
                OMessageBoxUtil::staticNotice(0, tr("Stop thermostat failed!"), QStringList() << tr("OK"), 10);
                return;
            }
        }

        ui->doubleSpinBoxTarget->setReadOnly(false);
        ui->toolButtonRun->setText("Start");
        ui->toolButtonRun->setIcon(QIcon(":/temperature_icons/run.png"));
    }

    emit backToMainPage();
}

/**
 * @brief TemperatureWindow::showTemperature
 */
void TemperatureWindow::showTemperature() {

    if (m_pSerialPort != NULL) {
        QByteArray rxBuffer;
        QByteArray txBuffer = USUnit::getTemperature(THERMOSTAT);
        qDebug() << toHexStr(txBuffer);
        QString result = m_pSerialPort->writeSerialPort(txBuffer, rxBuffer, TIMEOUT);
        qDebug() << toHexStr(rxBuffer);
        if (result != "Success") {
            OMessageBoxUtil::staticNotice(0, tr("Stop thermostat failed!"), QStringList() << tr("OK"), 10);
            return;
        }
        double t = USUnit::decodingTemperature(rxBuffer)/10;
        ui->labelShowTemperature->setText(QString::number(t) + "℃");
    }
}
