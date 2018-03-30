#include "kmtestingwidget.h"
#include "ui_kmtestingwidget.h"

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
#include "omessagebox.h"
#include "ofileexplorer.h"
#include "oimageviewutil.h"
#include "omessageboxutil.h"
#include "orecordtablewidget.h"
#include "kmsettingmodel.h"
#include "kmfittingwidget.h"

#define DATA_PATH "data/kitmethod/"

KMTestingWidget::KMTestingWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::KMTestingWidget) {
    ui->setupUi(this);

    m_isShow = false;
    m_pDyMsgBox = NULL;
    initalizeWidgets();
    initalizeSignals();
}

KMTestingWidget::~KMTestingWidget() {
    delete ui;
}

/**
 * @brief KMTestingWidget::setPlotTitle
 * @param title
 */
void KMTestingWidget::setPlotTitle(QString title) {
    m_pPlot->setPlotTitle(m_plotTitle + "(" + title + ")");
}

/**
 * @brief KMTestingWidget::setOperatingKeyEnable
 * @param ok
 */
void KMTestingWidget::setOperatingKeyEnable(bool ok) {
    if (m_pDyMsgBox != NULL) {
        m_pDyMsgBox->close();
        delete m_pDyMsgBox;
        m_pDyMsgBox = NULL;
    }
    ui->frameHeader->setEnabled(ok);
}

/**
 * @brief KMTestingWidget::setUnit
 * @param unit
 */
void KMTestingWidget::updateUnit(QString unit) {
    m_pPlot->setAxisYLabel(QString("%1(%2)").arg(m_axisYTitle).arg(unit));
    m_pFittingWidget->updateUnit(unit);
}

/**
 * @brief KMTestingWidget::setAnimationEnable
 * @param ok
 */
void KMTestingWidget::setAnimationEnable(bool ok) {
    m_pFileExplorer->setAnimationEnable(ok);
    m_pFittingWidget->setAnimationEnable(ok);
    m_pRecordTableWidget->setAnimationEnable(ok);
}

/**
 * @brief KMTestingWidget::showEvent
 * @param event
 */
void KMTestingWidget::showEvent(QShowEvent *event) {
    Q_UNUSED(event)
    if (!m_isShow) {
        m_isShow = true;
        m_leftRect = ui->frameLeft->geometry();
        m_mainRect = ui->frameMain->geometry();
        m_bottomRect = ui->frameBottom->geometry();
    }
}

/**
 * @brief KMTestingWidget::mousePressEvent
 * @param event
 */
void KMTestingWidget::mousePressEvent(QMouseEvent *event) {
    m_isPressed = true;
    m_pressPos = event->pos();
}

/**
 * @brief KMTestingWidget::mouseReleaseEvent
 * @param event
 */
void KMTestingWidget::mouseReleaseEvent(QMouseEvent *event) {
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
 * @brief KMTestingWidget::startFitting
 * @param setting
 */
void KMTestingWidget::startFitting(KMSettingModel *setting) {
    m_pFittingWidget->excuteFitting(setting);
}

/**
 * @brief KMTestingWidget::saveResult
 * @param fileName
 * @param data
 */
void KMTestingWidget::saveResult(QString fileName, QStringList data) {

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
 * @brief KMTestingWidget::saveRecord
 * @param data
 */
void KMTestingWidget::saveRecord(QStringList data) {
    m_pRecordTableWidget->insert(data);
}

/**
 * @brief KMTestingWidget::showResult
 * @param c
 */
void KMTestingWidget::showResult(double c) {
    m_pFittingWidget->insertAbso(c);
}

/**
 * @brief KMTestingWidget::capture
 */
void KMTestingWidget::capture() {

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
 * @brief KMTestingWidget::clearAll
 */
void KMTestingWidget::clearAll() {
    m_pPlot->clearCurves();
    m_pFittingWidget->clearAll();
}

/**
 * @brief KMTestingWidget::showData
 * @param fileName
 */
void KMTestingWidget::showData(QString fileName) {
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
        QVector<double> x;
        QVector<double> y;

        QTextStream in( &file );
        in.setCodec( "GB2312" );
        while(!in.atEnd()) {
            QString lineStr = in.readLine();
            if (lineStr.startsWith( "result:," )) {
                lineStr = lineStr.replace( "result:,", "" );
                record = lineStr.split( ",", QString::SkipEmptyParts );

            } else if (lineStr.startsWith( "data:," )) {
                lineStr = lineStr.replace( "data:,", "" );
                QStringList value = lineStr.split( ",", QString::SkipEmptyParts );
                if (value.size() == 2) {
                    QString xStr = value.at(0);
                    QString yStr = value.at(1);
                    x.append(xStr.toDouble());
                    y.append(yStr.toDouble());
                }
            }
        }
        file.close();

        emit toUpdateSetting(record);
        // 显示记录并画图
        saveRecord(record);
        m_pFittingWidget->updateData(x, y, record);
        if (record.size() >= 7) {
            m_pPlot->setAxisYLabel(QString("%1(%2)").arg(m_axisYTitle).arg(record.at(7)));
        }
    }
}

/**
 * @brief KMTestingWidget::doubleClickPlot
 */
void KMTestingWidget::doubleClickPlot() {

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
 * @brief KMTestingWidget::doubleClickRecordTableWidget
 */
void KMTestingWidget::doubleClickRecordTableWidget() {

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
 * @brief KMTestingWidget::onBlankBtnClicked
 */
void KMTestingWidget::onBlankBtnClicked() {
    ui->frameHeader->setEnabled(false);
    m_pPlot->clearCurves();
    m_pDyMsgBox = OMessageBoxUtil::dynamicNotice(this, tr("Blanking, Please waiting..."));
    emit toStartBlank();
}

/**
 * @brief KMTestingWidget::onMeasureBtnClicked
 */
void KMTestingWidget::onMeasureBtnClicked() {

    if (!m_pFittingWidget->isReady()) {
        OMessageBoxUtil::staticNotice(this, tr("Please add item which is used for fitting first!"), QStringList() << tr("OK"), 10);
        return;
    }
    ui->frameHeader->setEnabled(false);
    m_pPlot->clearCurves();
    m_pDyMsgBox = OMessageBoxUtil::dynamicNotice(this, tr("Measuring, Please waiting..."));
    emit toStartMeasure();
}

/**
 * @brief KMTestingWidget::initalizeSignals
 */
void KMTestingWidget::initalizeSignals() {
    connect(ui->toolButtonBack, SIGNAL(clicked(bool)), this, SIGNAL(backBtnClicked()));
    connect(ui->toolButtonSetting, SIGNAL(clicked(bool)), this, SIGNAL(toSettingPage()));
    connect(ui->toolButtonCapture, SIGNAL(clicked(bool)), this, SLOT(capture()));
    connect(ui->toolButtonClear, SIGNAL(clicked(bool)), this, SLOT(clearAll()));

    connect(m_pPlot, SIGNAL(doubleClicked()), this, SLOT(doubleClickPlot()));
    connect(m_pRecordTableWidget, SIGNAL(doubleClicked()), this, SLOT(doubleClickRecordTableWidget()));
    connect(m_pFileExplorer, SIGNAL(doubleClicked(QString)), this, SLOT(showData(QString)));

    connect(ui->toolButtonBlank, SIGNAL(clicked(bool)), this, SLOT(onBlankBtnClicked()));
    connect(ui->toolButtonMeasure, SIGNAL(clicked(bool)), this, SLOT(onMeasureBtnClicked()));

    connect(m_pFittingWidget, SIGNAL(toExcuteFit()), this, SIGNAL(toStartFitting()));
    connect(m_pFittingWidget, SIGNAL(toDrawFittingCurve(QString,QVector<double>,QVector<double>)),
            m_pPlot, SLOT(drawFittingCurve(QString,QVector<double>,QVector<double>)));
    connect(m_pFittingWidget, SIGNAL(toDrawScatterCurve(QString,QVector<double>,QVector<double>)),
            m_pPlot, SLOT(drawScatterCurve(QString,QVector<double>,QVector<double>)));
    connect(m_pFittingWidget, SIGNAL(toSaveResult(QString,QStringList)), this, SLOT(saveResult(QString,QStringList)));
    connect(m_pFittingWidget, SIGNAL(toSaveRecord(QStringList)), this, SLOT(saveRecord(QStringList)));
    connect(m_pFittingWidget, SIGNAL(toClearCurves()), m_pPlot, SLOT(clearCurves()));
}

/**
 * @brief KMTestingWidget::initalizeWidgets
 */
void KMTestingWidget::initalizeWidgets() {

    QString fileName = QDir::currentPath() + "/configs/kitmethod/kitmethod.ini";
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
    m_pPlot->setAxisXLabel(configIniReader->value("Plot/XAxisText").toString());
    m_axisYTitle = configIniReader->value("Plot/YAxisText").toString();
    m_pPlot->setAxisYLabel(m_axisYTitle);
    m_pPlot->uninstallZoomer();
    m_pPlot->setAxisXScale(configIniReader->value("Plot/XAxisMinVaule").toDouble(),
                           configIniReader->value("Plot/XAxisMaxVaule").toDouble());
    m_pPlot->setAxisYScale(configIniReader->value("Plot/YAxisMinVaule").toDouble(),
                           configIniReader->value("Plot/YAxisMaxVaule").toDouble());
    m_pPlot->addRulers(configIniReader->value("Plot/RulerCount").toInt(),
                       configIniReader->value("Plot/RulerPosition").toStringList());
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

    m_pFittingWidget = new KMFittingWidget();
    QHBoxLayout *fitLayout = new QHBoxLayout();
    fitLayout->addWidget(m_pFittingWidget);
    fitLayout->setMargin(0);
    ui->frameFit->setLayout(fitLayout);

    delete configIniReader;
    configIniReader = NULL;
}
