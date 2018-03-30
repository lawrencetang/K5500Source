#include "toolwindow.h"
#include "ui_toolwindow.h"

#include <QDir>
#include <QUrl>
#include <QProcess>
#include <QSettings>
#include <QDesktopServices>

#include "omessageboxutil.h"

ToolWindow::ToolWindow(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ToolWindow) {
    ui->setupUi(this);

    QString fileName = QDir::currentPath() + "/configs/system.ini";
    QSettings *configIniReader = new QSettings( fileName, QSettings::IniFormat );
    m_teamViewer = configIniReader->value("Tool/TeamViewer").toString();
    m_document = QDir::currentPath() + configIniReader->value("Tool/Documnet").toString();
    delete configIniReader;
    configIniReader = NULL;

    connect(ui->toolButtonBack, SIGNAL(clicked(bool)), this, SIGNAL(backToMainPage()));
    connect(ui->toolButtonAssistant, SIGNAL(clicked(bool)), this, SLOT(showTeamViewer()));
    connect(ui->toolButtonHelp, SIGNAL(clicked(bool)), this, SLOT(showManual()));
    connect(ui->toolButtonRestart, SIGNAL(clicked(bool)), this, SLOT(restart()));
    connect(ui->toolButtonShutdown, SIGNAL(clicked(bool)), this, SLOT(shutDown()));
}

ToolWindow::~ToolWindow() {
    delete ui;
}

/**
 * @brief ToolWindow::setBackEnable
 * @param ok
 */
void ToolWindow::setBackEnable(bool ok) {
    ui->toolButtonBack->setEnabled(ok);
}

/**
 * @brief ToolWindow::showTeamViewer
 */
void ToolWindow::showTeamViewer() {
    QProcess::startDetached( m_teamViewer, QStringList() );
}

/**
 * @brief ToolWindow::showManual
 */
void ToolWindow::showManual() {
    QDesktopServices::openUrl( QUrl::fromLocalFile( QFileInfo(m_document).absoluteFilePath() ) );
}

/**
 * @brief ToolWindow::restart
 */
void ToolWindow::restart() {

    int ret = OMessageBoxUtil::staticNotice(0, tr("Do you want to restart now?"),
                                            QStringList() << tr("OK") << tr("Cancel"), 10);
    if (ret == 0) {
#ifdef Q_OS_WIN32
        system( "shutdown -r -t 0" );
#endif
#ifdef Q_OS_LINUX
        system( "shutdown -r now" );
#endif
    }
}

/**
 * @brief ToolWindow::shutDown
 */
void ToolWindow::shutDown() {

    int ret = OMessageBoxUtil::staticNotice(0, tr("Do you want to shut down now?"),
                                            QStringList() << tr("OK") << tr("Cancel"), 10);
    if (ret == 0) {
#ifdef Q_OS_WIN32
        system( "shutdown -s -t 0" );
#endif
#ifdef Q_OS_LINUX
        system( "shutdown -h now" );
#endif
    }
}
