#include "ultramicrospectrophotometer.h"

#include <QDir>
#include <QDate>
#include <QFile>
#include <QSettings>
#include <QFileInfo>
#include <QTextStream>
#include <QApplication>
#include <QElapsedTimer>
#include <QSplashScreen>
#include <QDesktopWidget>
//#include <QDebug> //ltj

#include "accrediti.h"
#include "omessageboxutil.h"
#include "singleapplication.h"

void delay(int timeout);
void launch(QWidget &w);
void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &message);

bool m_isLogger = false;
int main(int argc, char *argv[])
{
    qInstallMessageHandler(messageHandler); //lt:参数是一个typedef的函数指针
    SingleApplication a(argc, argv, "uniquekey:UltramicroSpectrophotometer");
    if (a.alreadyExists()) {
        a.sendMessage("allready running!");
        return 0;
    }

    // 1.加载配置文件
    QString fileName = QDir::currentPath() + "/configs/system.ini";
    QSettings *configIniReader = new QSettings( fileName, QSettings::IniFormat );//lt:读配置文件system
    bool isFullScreen = configIniReader->value( "/System/FullScreenEnable" ).toBool();//lt:配置全屏
    bool isSplashScreen = configIniReader->value( "/System/SplashScreenEnable" ).toBool();
    m_isLogger = configIniReader->value( "/System/LoggerEnable" ).toBool();//lt:是否有配置文件
    QString productName = configIniReader->value( "/System/ProductName" ).toString();
    delete configIniReader;
    configIniReader = NULL;

    // 2.加载配置文件
    QString keyFileName = QDir::currentPath() + "/license/accredit.key";
    QString userFileName = QDir::currentPath() + "/license/accredit.note";
    bool ok = AccreditI::check( keyFileName, userFileName, productName );
    if (!ok) {
        OMessageBoxUtil::staticNotice(0, QObject::tr( "License expire." ), QStringList() <<  QObject::tr( "OK" ), 10);
        return -1;
    }//lt:判断授权文件

    UltramicroSpectrophotometer w;
    w.setWindowTitle(productName);//lt:设置窗口标题

    // 3.启动开机动画
    if (isSplashScreen) {
        launch(w);
    }

    // 4. 是否全屏显示
    if (!isFullScreen) {
        w.setFixedSize(1280, 800);
        w.show();
    } else {
        QDesktopWidget *desktopWidget = QApplication::desktop();
        w.setFixedSize(desktopWidget->size());
        w.showFullScreen();
    }
    //qDebug() << "s"; //ltj

    QObject::connect(&a, SIGNAL(messageAvailable(QStringList)), &w, SLOT(receiveAppMessage(QStringList)));
    return a.exec();
}

/**
 * @brief launch
 * @param w
 */
void launch(QWidget &w) {

    // 获取当前屏幕的分辨率
    QDesktopWidget *desktopWidget = QApplication::desktop();
    QPixmap startImage(QDir::currentPath() + "/images/startup/startup.png");
    startImage = startImage.scaled(desktopWidget->size());

    // 显示启动画面
    QSplashScreen splashScreen(startImage);
    splashScreen.resize(startImage.size());
    splashScreen.setDisabled(true);
    splashScreen.show();

    // 显示情动信息
    splashScreen.setFont(QFont("黑体", 32, QFont::Bold));
    splashScreen.showMessage(QObject::tr( "Initializing Data, Please waiting..." ), Qt::AlignLeft|Qt::AlignBottom, Qt::white);
    delay(1000);
    splashScreen.showMessage(QObject::tr( "Initializing Views, Please waiting..." ), Qt::AlignLeft|Qt::AlignBottom, Qt::white);
    delay(1000);
    splashScreen.showMessage(QObject::tr( "Initializing Devices, Please waiting..." ), Qt::AlignLeft|Qt::AlignBottom, Qt::white);
    delay(1000);
    splashScreen.finish(&w);
}

/**
 * @brief delay
 * @param timeout
 */
void delay(int timeout) {

    QElapsedTimer t;
    t.start();
    while(t.elapsed() < timeout) {
        QCoreApplication::processEvents();
    }
}

/**
 * @brief messageHandler
 * @param type
 * @param context
 * @param msg
 */
#define OUTPUT_ENABLE   1 // 打印是否使能
void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &message) {

    QString typeStr;
    switch (type) {
    case QtDebugMsg:
        typeStr = "Debug";
        break;
    case QtSystemMsg:
        typeStr = "Info";
        break;
    case QtWarningMsg:
        typeStr = "Warning";
        return;
    case QtInfoMsg:
        typeStr = "Critical";
        break;
    case QtFatalMsg:
        typeStr = "Fatal";
        abort();
    }

    QString timestampStr = QString( "[%1]:" ).arg( QDateTime::currentDateTime().toString( "yyyy-MM-dd hh:mm:ss.zzz" ) );
    QString contextInfo = QString( "%1 %2.%3.%4-" ).arg(typeStr).arg( context.file ).arg( context.function ).arg( context.line );

    if (m_isLogger) {

        QString dateStr = QDate::currentDate().toString( "yyyy-MM-dd" );
        QString fileName = QDir::currentPath() + QString( "/log/%1.txt" ).arg( dateStr );
        QFile file( fileName );
        if ( file.open( QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text) ) {

            QTextStream out(&file);
            out.setCodec( "UTF-8" );
            out << timestampStr << contextInfo << message << "\n";
        }
        file.close();

    } else {

        if (OUTPUT_ENABLE == 1) {
            QTextStream cout(stdout, QIODevice::WriteOnly);
            cout.setCodec( "UTF-8" );
            QString text = timestampStr + contextInfo + message;
            cout << text << endl;
        }

    }
}//lt:输出调试信息到日志里
