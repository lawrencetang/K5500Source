#include "dytestingwidget.h"
#include "ui_dytestingwidget.h"

#include <QDir>
#include <QLabel>
#include <QDebug>
#include <QFileInfo>
#include <QDateTime>
#include <QSettings>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

#include "oplot.h"
#include "ofileexplorer.h"
#include "oimageviewutil.h"
#include "omessagebox.h"
#include "omessageboxutil.h"
#include "orecordtablewidget.h"

#define DATA_PATH "data/dynamics/"

DYTestingWidget::DYTestingWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DYTestingWidget) {
    ui->setupUi(this);

    m_isShow = false;
    m_pDyMsgBox = NULL;
    initalizeWidgets();
    initalizeSignals();
}

DYTestingWidget::~DYTestingWidget() {
    delete ui;
}

/**
 * @brief DYTestingWidget::setPlotTitle
 * @param title
 */
void DYTestingWidget::setPlotTitle(QString title) {
    m_pPlot->setPlotTitle(m_plotTitle + "(" + title + ")");
}

/**
 * @brief DYTestingWidget::setOperatingKeyEnable
 * @param ok
 */
void DYTestingWidget::setOperatingKeyEnable(bool ok) {
    if (m_pDyMsgBox != NULL) {
        m_pDyMsgBox->close();
        delete m_pDyMsgBox;
        m_pDyMsgBox = NULL;
    }
    ui->frameHeader->setEnabled(ok);
}

/**
 * @brief DYTestingWidget::setAnimationEnable
 * @param ok
 */
void DYTestingWidget::setAnimationEnable(bool ok) {
    m_pFileExplorer->setAnimationEnable(ok);
    m_pRecordTableWidget->setAnimationEnable(ok);
}

/**
 * @brief DYTestingWidget::showEvent
 * @param event
 */
void DYTestingWidget::showEvent(QShowEvent *event) {
    Q_UNUSED(event)
    if (!m_isShow) {
        m_isShow = true;
        m_leftRect = ui->frameLeft->geometry();
        m_mainRect = ui->frameMain->geometry();
        m_bottomRect = ui->frameBottom->geometry();
    }
}

/**
 * @brief DYTestingWidget::mousePressEvent
 * @param event
 */
void DYTestingWidget::mousePressEvent(QMouseEvent *event) {
    m_isPressed = true;
    m_pressPos = event->pos();
}

/**
 * @brief DYTestingWidget::mouseReleaseEvent
 * @param event
 */
void DYTestingWidget::mouseReleaseEvent(QMouseEvent *event) {
    m_isPressed = false;
    QPoint d_pos = event->pos() - m_pressPos;
    int length = d_pos.manhattanLength();
    if (length <= 10) {
        return;
    }
    if (abs(d_pos.x()) < 1.1*length && abs(d_pos.x()) > 0.9*length) {

        QPropertyAnimation *a1 = new QPropertyAnimation( ui->frameMain, "geometry" );
        QPropertyAnimation *a2 = new QPropertyAnimation( ui->frameBottom, "geometry" );
        a1->setDuration( 1000 );
        a2->setDuration( 1000 );
        QRect startRect1 = ui->frameMain->geometry();
        QRect startRect2 = ui->frameBottom->geometry();
        QRect endRect1 = startRect1;
        QRect endRect2 = startRect2;
        a1->setStartValue( startRect1 );
        a2->setStartValue( startRect2 );
        if (d_pos.x() < 0) {
            endRect1.setTopLeft(geometry().topLeft());
            endRect1.setWidth(geometry().width());
            endRect2.setTopLeft(endRect1.bottomLeft());
            endRect2.setWidth(geometry().width());
        } else {
            endRect1.setTopLeft(m_mainRect.topLeft());
            endRect2.setTopLeft(m_bottomRect.topLeft());
            endRect1.setWidth(m_mainRect.width());
            endRect2.setWidth(m_bottomRect.width());
        }
        a1->setEndValue( endRect1 );
        a2->setEndValue( endRect2 );
        a1->setEasingCurve( QEasingCurve::OutCubic );
        a2->setEasingCurve( QEasingCurve::OutCubic );

        QParallelAnimationGroup *group = new QParallelAnimationGroup();
        group->addAnimation(a1);
        group->addAnimation(a2);
        group->start();

    } else if (abs(d_pos.y()) < 1.1*length && abs(d_pos.y()) > 0.9*length) {

        QPropertyAnimation *a1 = new QPropertyAnimation( ui->frameMain, "geometry" );
        QPropertyAnimation *a2 = new QPropertyAnimation( ui->frameBottom, "geometry" );
        a1->setDuration( 1000 );
        a2->setDuration( 1000 );
        QRect startRect1 = ui->frameMain->geometry();
        QRect startRect2 = ui->frameBottom->geometry();
        QRect endRect1 = startRect1;
        QRect endRect2 = startRect2;
        a1->setStartValue( startRect1 );
        a2->setStartValue( startRect2 );
        if (d_pos.y() > 0) {
            endRect1.setHeight(geometry().height());
            endRect2.setTopLeft(endRect1.bottomLeft());
            endRect2.setHeight(0);
        } else {
            endRect1.setHeight(m_mainRect.height());
            endRect2.setTopLeft(endRect1.bottomLeft());
            endRect2.setHeight(m_bottomRect.height());
        }
        a1->setEndValue( endRect1 );
        a2->setEndValue( endRect2 );
        a1->setEasingCurve( QEasingCurve::OutCubic );
        a2->setEasingCurve( QEasingCurve::OutCubic );

        QParallelAnimationGroup *group = new QParallelAnimationGroup();
        group->addAnimation(a1);
        group->addAnimation(a2);
        group->start();
    }
}

/**
 * @brief DYTestingWidget::drawDynamicsCurve
 * @param x
 * @param y
 */
void DYTestingWidget::drawDynamicsCurve(double x, QVector<double> y) {
    m_pPlot->drawDynamicCurve(x, y);
}

/**
 * @brief DYTestingWidget::saveResult
 * @param fileName
 * @param data
 */
void DYTestingWidget::saveResult(QString fileName, QStringList data) {

    QFileInfo fileInfo(fileName);
    if (fileInfo.filePath() != QDir::currentPath() + "/" + DATA_PATH + "files/") {
        fileName = QDir::currentPath() + "/" + DATA_PATH + "files/" + fileInfo.fileName();
    }

    m_pFileExplorer->insertDataFile(fileName, data);
    /*
    int ret = OMessageBoxUtil::staticNotice(0, tr("Success, do you want to save file(%1)?").arg(fileInfo.fileName()),
                                            QStringList() << tr("OK") << tr("Cancel"), 10);
    if (ret == 0) {
        m_pFileExplorer->insertDataFile(fileName, data);
    }
    */
}

/**
 * @brief DYTestingWidget::saveRecord
 * @param data
 */
void DYTestingWidget::saveRecord(QStringList data) {
    m_pRecordTableWidget->insert(data);
}

/**
 * @brief DYTestingWidget::capture
 */
void DYTestingWidget::capture() {

    ui->frameHeader->setEnabled(false);
    m_pFileExplorer->reset();
    QPixmap pixmap = m_pPlot->grab();
    QString path = QDir::currentPath() + "/" + DATA_PATH + "images/";
    QString fileName = QDateTime::currentDateTime().toString( "yyyyMMddhhmmss" ) + ".png";
    bool ok = pixmap.save(path + fileName, "png");
    if (ok) {
        m_pFileExplorer->insertImage(path + fileName);
        int ret = OMessageBoxUtil::staticNotice(0, tr("Success, do you want to show the picture?"), QStringList() << tr("OK") << tr("Cancel"), 10);
        if (ret == 0) {
            OImageViewUtil::showImage(fileName, QPixmap(path+fileName));
        }
    } else {
        OMessageBoxUtil::staticNotice(0, tr("Capture failed!"), QStringList() << tr("OK"), 10);
    }
    ui->frameHeader->setEnabled(true);
}

/**
 * @brief DYTestingWidget::showData
 * @param fileName
 */
void DYTestingWidget::showData(QString fileName) {

    if (fileName.endsWith( ".png" )) {
        QFileInfo fileInfo(fileName);
        OImageViewUtil::showImage(fileInfo.fileName(), QPixmap(fileName));
    } else {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            OMessageBoxUtil::staticNotice(0, tr("Open data file failed!"), QStringList() << tr("OK"), 10);
            return;
        }

        QStringList record;
        double x;
        QVector<double> y;
        clearCurves();

        QTextStream in( &file );
        in.setCodec( "GB2312" );
        while(!in.atEnd()) {
            QString lineStr = in.readLine();
            if (lineStr.startsWith( "result:," )) {
                lineStr = lineStr.replace( "result:,", "" );
                record = lineStr.split( ",", QString::SkipEmptyParts );

            } else if (lineStr.startsWith( "data:," )) {
                y.clear();
                lineStr = lineStr.replace( "data:,", "" );
                QStringList value = lineStr.split( ",", QString::SkipEmptyParts );
                if (value.size() == 6) {
                    QString xStr = value.at(0);
                    x = xStr.toDouble();
                    for (int i = 1; i < value.size(); i ++) {
                        QString yStr = value.at(i);
                        y.append(yStr.toDouble());
                    }
                    drawDynamicsCurve(x, y);
                }
            }
        }
        file.close();

        QString title = "Sample";
        if (record.size() > 8) {
            title = QString( "%1%2" ).arg(record.first()).arg(record.at(8));
        }
        saveRecord(record);
    }
}

/**
 * @brief DYTestingWidget::clearCurves
 */
void DYTestingWidget::clearCurves() {

    m_pPlot->clearCurves();
    QString fileName = QDir::currentPath() + "/configs/dynamics/dynamics.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);

    m_pPlot->uninstallZoomer();
    m_pPlot->setAxisScale(QwtPlot::xBottom, configIniReader->value("Plot/XAxisMinVaule").toDouble(),
                          configIniReader->value("Plot/XAxisMaxVaule").toDouble());
    m_pPlot->setAxisScale(QwtPlot::yLeft, configIniReader->value("Plot/YAxisMinVaule").toDouble(),
                          configIniReader->value("Plot/YAxisMaxVaule").toDouble());
    m_pPlot->addDynamicCureves(configIniReader->value("Plot/DynamicsCurves").toStringList());
    m_pPlot->installZoomer();

    delete configIniReader;
    configIniReader = NULL;
}

/**
 * @brief DYTestingWidget::doubleClickPlot
 */
void DYTestingWidget::doubleClickPlot() {

    if (m_mainRect == ui->frameMain->geometry()) {
        // 最大化
        QPropertyAnimation *a = new QPropertyAnimation( ui->frameMain, "geometry" );
        a->setDuration( 1000 );
        ui->frameMain->raise();
        a->setStartValue( m_mainRect );
        a->setEndValue( geometry() );
        a->setEasingCurve(QEasingCurve::OutCubic);
        a->start();
    } else {
        // 还原
        QPropertyAnimation *a1 = new QPropertyAnimation( ui->frameMain, "geometry" );
        a1->setDuration( 1000 );
        a1->setStartValue( ui->frameMain->geometry() );
        a1->setEndValue( m_mainRect );
        a1->setEasingCurve(QEasingCurve::OutCubic);

        QPropertyAnimation *a2 = new QPropertyAnimation( ui->frameBottom, "geometry" );
        a2->setDuration( 1000 );
        a2->setStartValue( ui->frameBottom->geometry() );
        a2->setEndValue( m_bottomRect );
        a2->setEasingCurve(QEasingCurve::OutCubic);
        QParallelAnimationGroup *group = new QParallelAnimationGroup();
        group->addAnimation(a1);
        group->addAnimation(a2);
        group->start();
    }
}

/**
 * @brief DYTestingWidget::doubleClickRecordTableWidget
 */
void DYTestingWidget::doubleClickRecordTableWidget() {

    if (m_bottomRect == ui->frameBottom->geometry()) {
        // 最大化
        ui->frameBottom->raise();
        QPropertyAnimation *a = new QPropertyAnimation( ui->frameBottom, "geometry" );
        a->setDuration( 1000 );
        a->setStartValue( m_bottomRect );
        a->setEndValue( geometry() );
        a->setEasingCurve(QEasingCurve::OutCubic);
        a->start();
    } else {
        // 还原
        QPropertyAnimation *a1 = new QPropertyAnimation( ui->frameMain, "geometry" );
        a1->setDuration( 1000 );
        a1->setStartValue( ui->frameMain->geometry() );
        a1->setEndValue( m_mainRect );
        a1->setEasingCurve(QEasingCurve::OutCubic);

        QPropertyAnimation *a2 = new QPropertyAnimation( ui->frameBottom, "geometry" );
        a2->setDuration( 1000 );
        a2->setStartValue( ui->frameBottom->geometry() );
        a2->setEndValue( m_bottomRect );
        a2->setEasingCurve(QEasingCurve::OutCubic);
        QParallelAnimationGroup *group = new QParallelAnimationGroup();
        group->addAnimation(a1);
        group->addAnimation(a2);
        group->start();
    }
}

/**
 * @brief DYTestingWidget::onBlankBtnClicked
 */
void DYTestingWidget::onBlankBtnClicked() {
    ui->frameHeader->setEnabled(false);
    m_pDyMsgBox = OMessageBoxUtil::dynamicNotice(this, tr("Blanking, Please waiting..."));
    emit toStartBlank();
}

/**
 * @brief DYTestingWidget::onMeasureBtnClicked
 */
void DYTestingWidget::onMeasureBtnClicked() {
    ui->frameHeader->setEnabled(false);
    clearCurves();
    m_pDyMsgBox = OMessageBoxUtil::dynamicNotice(this, tr("Measuring, Please waiting..."));
    emit toStartMeasure();
}

/**
 * @brief DYTestingWidget::initalizeSignals
 */
void DYTestingWidget::initalizeSignals() {
    connect(ui->toolButtonBack, SIGNAL(clicked(bool)), this, SIGNAL(backBtnClicked()));
    connect(ui->toolButtonSetting, SIGNAL(clicked(bool)), this, SIGNAL(toSettingPage()));
    connect(ui->toolButtonCapture, SIGNAL(clicked(bool)), this, SLOT(capture()));
    connect(ui->toolButtonClear, SIGNAL(clicked(bool)), this, SLOT(clearCurves()));

    connect(m_pPlot, SIGNAL(doubleClicked()), this, SLOT(doubleClickPlot()));
    connect(m_pRecordTableWidget, SIGNAL(doubleClicked()), this, SLOT(doubleClickRecordTableWidget()));
    connect(m_pFileExplorer, SIGNAL(doubleClicked(QString)), this, SLOT(showData(QString)));

    connect(ui->toolButtonBlank, SIGNAL(clicked(bool)), this, SLOT(onBlankBtnClicked()));
    connect(ui->toolButtonMeasure, SIGNAL(clicked(bool)), this, SLOT(onMeasureBtnClicked()));
}

/**
 * @brief DYTestingWidget::initalizeWidgets
 */
void DYTestingWidget::initalizeWidgets() {

    QString fileName = QDir::currentPath() + "/configs/dynamics/dynamics.ini";
    QSettings *configIniReader = new QSettings(fileName, QSettings::IniFormat);

    QString title = configIniReader->value("RecordTableWidget/Title").toString();
    QStringList headerLabels = configIniReader->value("RecordTableWidget/Header").toStringList();

    m_pFileExplorer = new OFileExplorer(DATA_PATH);
    m_pFileExplorer->setFrameShape(QFrame::NoFrame);
    m_pRecordTableWidget = new ORecordTableWidget(headerLabels, title);
    m_pRecordTableWidget->setFrameShape(QFrame::NoFrame);

    QHBoxLayout *leftLayout = new QHBoxLayout();
    leftLayout->addWidget(m_pFileExplorer);
    leftLayout->setMargin(0);
    ui->frameLeft->setLayout(leftLayout);

    QHBoxLayout *bottomLayout = new QHBoxLayout();
    bottomLayout->addWidget(m_pRecordTableWidget);
    bottomLayout->setMargin(0);
    ui->frameBottom->setLayout(bottomLayout);

    m_pPlot = new OPlot();
    m_plotTitle = configIniReader->value("Plot/Title").toString();
    m_pPlot->setPlotTitle(m_plotTitle);
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

    ui->toolButtonBack->setIconSize(QSize(80, 80));
    ui->toolButtonBack->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButtonBack->setIcon(QIcon(QDir::currentPath() + "/images/controller/Back.png"));
    ui->toolButtonBlank->setIconSize(QSize(80, 80));
    ui->toolButtonBlank->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButtonBlank->setIcon(QIcon(QDir::currentPath() + "/images/controller/Blank.png"));
    ui->toolButtonMeasure->setIconSize(QSize(80, 80));
    ui->toolButtonMeasure->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButtonMeasure->setIcon(QIcon(QDir::currentPath() + "/images/controller/Measure.png"));
    ui->toolButtonSetting->setIconSize(QSize(80, 80));
    ui->toolButtonSetting->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButtonSetting->setIcon(QIcon(QDir::currentPath() + "/images/controller/Setting.png"));
    ui->toolButtonCapture->setIconSize(QSize(80, 80));
    ui->toolButtonCapture->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButtonCapture->setIcon(QIcon(QDir::currentPath() + "/images/controller/Capture.png"));
    ui->toolButtonClear->setIconSize(QSize(80, 80));
    ui->toolButtonClear->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolButtonClear->setIcon(QIcon(QDir::currentPath() + "/images/controller/Clear.png"));

    QHBoxLayout *plotLayout = new QHBoxLayout();
    plotLayout->addWidget(m_pPlot);
    plotLayout->setMargin(0);
    ui->framePlot->setLayout(plotLayout);

    ui->framePlot->setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(255,255,255));
    ui->framePlot->setPalette(palette);

    delete configIniReader;
    configIniReader = NULL;
}
