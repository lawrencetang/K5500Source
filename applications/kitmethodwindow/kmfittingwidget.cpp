#include "kmfittingwidget.h"
#include "ui_kmfittingwidget.h"

#include "kmtablewidget.h"
#include "kmsettingmodel.h"
#include "kmolsfit.h"
#include "odigitkeyboard.h"
#include "omessageboxutil.h"
#include "omessagebox.h"

#include <QDir>
#include <QDebug>
#include <QtMath>
#include <QDateTime>
#include <QPropertyAnimation>

#define COEF_SPLIT "_"

KMFittingWidget::KMFittingWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::KMFittingWidget) {
    ui->setupUi(this);

    m_isNewItem = false;
    m_isAnimation = true;
    m_pFitTableWidget = new KMTableWidget(QStringList()<<tr("Conc")<<tr("Abso"), this);
    m_pFitLayout = new QHBoxLayout();
    m_pFitLayout->addWidget(m_pFitTableWidget);
    m_pFitLayout->setMargin(0);
    ui->frameTable_m->setLayout(m_pFitLayout);

    m_pMeasureTableWidget = new KMTableWidget(QStringList()<<tr("Conc")<<tr("Abso"), this);
    QHBoxLayout *measureLayout = new QHBoxLayout();
    measureLayout->addWidget(m_pMeasureTableWidget);
    measureLayout->setMargin(0);
    ui->frameTableMeasure->setLayout(measureLayout);

    m_pDigitKeyboard = new ODigitKeyboard(this, this);
    QHBoxLayout *boardLayout = new QHBoxLayout();
    boardLayout->addWidget(m_pDigitKeyboard);
    boardLayout->setMargin(0);
    ui->frameKeyboard->setLayout(boardLayout);

    ui->toolButtonFit->setEnabled(m_pFitTableWidget->rowCount() >= 5);
    ui->toolButtonRemove->setEnabled(m_pFitTableWidget->rowCount() != 0);
    ui->toolButtonSwitch->setEnabled(!m_fitCoefs.isEmpty());

    connect(ui->toolButtonAdd, SIGNAL(clicked(bool)), this, SLOT(showAddView()));
    connect(ui->toolButtonRemove, SIGNAL(clicked(bool)), this, SLOT(showRemoveView()));
    connect(ui->toolButtonSwitch, SIGNAL(clicked(bool)), this, SLOT(showMeasureView()));

    connect(ui->toolButtonOk_a, SIGNAL(clicked(bool)), this, SLOT(showFittingView()));
    connect(ui->toolButtonCancel_a, SIGNAL(clicked(bool)), this, SLOT(showFittingView()));
    connect(ui->toolButtonOk_r, SIGNAL(clicked(bool)), this, SLOT(showFittingView()));
    connect(ui->toolButtonCancel_r, SIGNAL(clicked(bool)), this, SLOT(showFittingView()));

    connect(ui->toolButtonBack, SIGNAL(clicked(bool)), this, SLOT(showFittingView()));
    connect(ui->toolButtonClear, SIGNAL(clicked(bool)), m_pMeasureTableWidget, SLOT(clearAll()));

    connect(ui->toolButtonFit, SIGNAL(clicked(bool)), this, SIGNAL(toExcuteFit()));
    connect(ui->radioButtonCheckAll, SIGNAL(clicked(bool)), m_pFitTableWidget, SLOT(checkAll(bool)));
}

/**
 * @brief KMFittingWidget::~KMFittingWidget
 */
KMFittingWidget::~KMFittingWidget() {
    delete ui;
}

/**
 * @brief KMFittingWidget::isReady
 * @return
 */
bool KMFittingWidget::isReady() {
    return m_pFitTableWidget->rowCount() != 0;
}

void KMFittingWidget::clearAll() {

    m_r2 = 0;
    m_unit = "ng/uL";
    m_order = 0;
    m_fitCoefs.clear();
    m_pFitTableWidget->clearAll();
    m_pMeasureTableWidget->clearAll();

    ui->stackedWidget->setCurrentWidget(ui->pageFitting);
    ui->toolButtonFit->setEnabled(m_pFitTableWidget->rowCount() >= 5);
    ui->toolButtonRemove->setEnabled(m_pFitTableWidget->rowCount() != 0);
    ui->toolButtonSwitch->setEnabled(!m_fitCoefs.isEmpty());
}

/**
 * @brief KMFittingWidget::insertAbso
 * @param c
 */
void KMFittingWidget::insertAbso(double c) {
    if (ui->pageFitting ==
            ui->stackedWidget->currentWidget()) {

        if (m_pFitTableWidget->rowCount() > 0) {
            QTableWidgetItem *item = m_pFitTableWidget->item(m_pFitTableWidget->rowCount() - 1, 1);
            if (!m_isNewItem) {
                c = (item->text().toDouble() + c)/2;
            }
            m_isNewItem = false;
            item->setText(QString::number(c));
        }
    } else {

        double abso = c;
        double conc = 0.0;
        if (!m_fitCoefs.isEmpty()) {
            int coefSize = m_fitCoefs.size();
            for (int j = 0; j < coefSize; j ++) {
                conc += qPow( c, coefSize-j-1 )*m_fitCoefs.at( j );
            }
        }
        QStringList data;
        data << QString::number(conc) << QString::number(abso);
        m_pMeasureTableWidget->add(data);
    }
}

/**
 * @brief KMFittingWidget::updateUnit
 * @param unit
 */
void KMFittingWidget::updateUnit(QString unit) {

    QString unit_o = ui->doubleSpinBoxConcentration->suffix();
    double c = transformCoef(unit_o, unit);

    ui->doubleSpinBoxConcentration->setSuffix(unit);
    ui->doubleSpinBoxConcentration->setValue(ui->doubleSpinBoxConcentration->value() * c);

    QVector<double> x;
    QVector<double> y;
    int rowCount_f = m_pFitTableWidget->rowCount();
    for(int r = 0; r < rowCount_f; r ++) {
        QTableWidgetItem *item = m_pFitTableWidget->item(r, 0);
        item->setText(QString::number(item->text().toDouble() * c));
        x.append(m_pFitTableWidget->item(r, 1)->text().toDouble());
        y.append(item->text().toDouble());
    }
    if (rowCount_f > 0) {
        emit toClearCurves();
        drawCurve(x, y, transformCoef(m_unit, unit));
    }

    int rowCount_m = m_pMeasureTableWidget->rowCount();
    for(int r = 0; r < rowCount_m; r ++) {
        QTableWidgetItem *item = m_pMeasureTableWidget->item(r, 0);
        item->setText(QString::number(item->text().toDouble() * c));
    }
}

/**
 * @brief KMFittingWidget::updateData
 * @param x
 * @param y
 * @param record
 */
void KMFittingWidget::updateData(QVector<double> x, QVector<double> y, QStringList record) {

    if (record.size() < 7) {
        OMessageBoxUtil::staticNotice(this, tr("Record missing!"), QStringList()<<tr("OK"), 10);
        return;
    }

    emit toClearCurves();
    QString orderStr = record.at(4);
    QString r2Str = record.at(5);
    QString coefStr = record.at(6);

    m_r2 = r2Str.toDouble();
    m_unit = record.at(7);
    m_order = orderStr.toInt();
    ui->doubleSpinBoxConcentration->setSuffix(m_unit);

    QStringList coefList = coefStr.split(COEF_SPLIT, QString::SkipEmptyParts);
    if(!coefList.isEmpty()) {
        m_fitCoefs.clear();
        foreach(QString coefStr, coefList) {
            m_fitCoefs.append(coefStr.toDouble());
        }
    }

    m_pFitTableWidget->clearAll();
    QStringList data;
    for(int i = 0; i < x.size(); i ++) {
        data.clear();
        data << QString::number(x.at(i)) << QString::number(y.at(i));
        m_pFitTableWidget->add(data);
    }
    ui->toolButtonFit->setEnabled(m_pFitTableWidget->rowCount() >= 5);
    ui->toolButtonRemove->setEnabled(m_pFitTableWidget->rowCount() != 0);
    ui->toolButtonSwitch->setEnabled(!m_fitCoefs.isEmpty());
    drawCurve(x, y);
}

/**
 * @brief KMFittingWidget::updateCurve
 * @param unit
 */
void KMFittingWidget::updateCurve(QString unit) {

    emit toClearCurves();
    QString unit_o = ui->doubleSpinBoxConcentration->suffix();
    double c = transformCoef(unit_o, unit);
    ui->doubleSpinBoxConcentration->setSuffix(unit);
    ui->doubleSpinBoxConcentration->setValue(ui->doubleSpinBoxConcentration->value() * c);

    QVector<double> x;
    QVector<double> y;
    int rowCount_f = m_pFitTableWidget->rowCount();
    for(int r = 0; r < rowCount_f; r ++) {
        QTableWidgetItem *itemY = m_pFitTableWidget->item(r, 0);
        QTableWidgetItem *itemX = m_pFitTableWidget->item(r, 1);
        x.append(itemX->text().toDouble());
        y.append(itemY->text().toDouble());
    }
    if (rowCount_f > 0) {
        drawCurve(x, y);
    }
}

/**
 * @brief KMFittingWidget::excuteFitting
 * @param setting
 */
void KMFittingWidget::excuteFitting(KMSettingModel *setting) {

    if (setting == NULL) {
        OMessageBoxUtil::staticNotice(this, tr("Setting model lose!"), QStringList()<<tr("OK"), 10);
        return;
    }

    OMessageBox *msgBox = OMessageBoxUtil::dynamicNotice(this, tr( "Fitting,please wait..." ));

    QVector<double> x;
    QVector<double> y;
    for (int r = 0; r < m_pFitTableWidget->rowCount(); r ++) {
        x.append(m_pFitTableWidget->item(r, 1)->text().toDouble());
        y.append(m_pFitTableWidget->item(r, 0)->text().toDouble());
    }
    m_order = setting->getOrder();
    m_unit = setting->getUnit();
    // 执行拟合
    m_fitCoefs.clear();
    int ok = CalFit( x, y, x.size(), m_order+1, &m_fitCoefs );
    if (0 != ok) {
        msgBox->close();
        delete msgBox;
        msgBox = NULL;
        OMessageBoxUtil::staticNotice(this, tr("Fitting failed!"), QStringList()<<tr("OK"), 10);
        return;
    }

    // 获取r2
    ok = CalAvgVar( x, y, x.size(), m_order+1, m_fitCoefs, &m_r2 );
    if (0 != ok) {
        msgBox->close();
        delete msgBox;
        msgBox = NULL;
        OMessageBoxUtil::staticNotice(this, tr("Get R-Squared failed!"),QStringList()<<tr("OK"), 10);
        return;
    }

    // 画图
    emit toClearCurves();
    drawCurve(x, y);

    // 生成记录
    QString fileName = QDateTime::currentDateTime().toString("yyyyMMddhhmmss")+".csv";
    QStringList result;
    QStringList record;
    record << "result:" << setting->getSampleName() << setting->getMethod() << QString::number(setting->getMwl())
           << getFuncStr(m_fitCoefs) << QString::number(m_order) << QString::number(m_r2) << getCoefStr(m_fitCoefs)
           << setting->getUnit() << setting->getOptical() << fileName;

    QString resultStr;
    foreach(QString item, record){
        resultStr.append(item);
        if (!result.endsWith(item)) {
            resultStr.append( "," );
        }
    }
    record.removeFirst();
    result.append(resultStr);

    QString dataStr;
    for(int i = 0; i < x.size(); i ++) {
        dataStr = QString("data:,%1,%2").arg(x.at(i)).arg(y.at(i));
        result.append(dataStr);
    }

    emit toSaveRecord(record);
    emit toSaveResult(fileName, result);
    ui->toolButtonSwitch->setEnabled(!m_fitCoefs.isEmpty());
    msgBox->close();
    delete msgBox;
    msgBox = NULL;
}

/**
 * @brief KMFittingWidget::showAddView
 */
void KMFittingWidget::showAddView() {
    ui->stackedWidgetFitting->setCurrentWidget(ui->pageAdd);
    flipOverAnimation(ui->pageAdd);
}

/**
 * @brief KMFittingWidget::showRemoveView
 */
void KMFittingWidget::showRemoveView() {
    ui->stackedWidgetFitting->setCurrentWidget(ui->pageRemove);
    ui->frameTable_r->setLayout(m_pFitLayout);
    m_pFitTableWidget->setCheckable(true);
    m_pFitTableWidget->checkAll(ui->radioButtonCheckAll->isChecked());
    flipOverAnimation(ui->pageRemove);
}

/**
 * @brief KMFittingWidget::showFittingView
 */
void KMFittingWidget::showFittingView() {
    QWidget *w;
    if (sender() == ui->toolButtonBack) {
        ui->stackedWidget->setCurrentWidget(ui->pageFitting);
        w = ui->pageFitting;
    } else {

        if (sender() == ui->toolButtonOk_a) {
            QStringList data;
            //data << QString::number( ui->doubleSpinBoxConcentration->value() ) << "0";
            data << QString::number( ui->doubleSpinBoxConcentration->value() ) << QString::number( ui->doubleSpinBoxConcentration->value() );
            m_pFitTableWidget->add(data);
            m_isNewItem = true;
        } else if (sender() == ui->toolButtonOk_r) {
            m_pFitTableWidget->remove();
            ui->radioButtonCheckAll->setChecked(false);
        }

        m_pFitTableWidget->setCheckable(false);
        ui->stackedWidgetFitting->setCurrentWidget(ui->pageMain);
        ui->frameTable_m->setLayout(m_pFitLayout);
        w = ui->pageMain;
    }
    ui->toolButtonFit->setEnabled(m_pFitTableWidget->rowCount() >= 5);
    ui->toolButtonRemove->setEnabled(m_pFitTableWidget->rowCount() != 0);
    flipOverAnimation(w);
}

/**
 * @brief KMFittingWidget::showMeasureView
 */
void KMFittingWidget::showMeasureView() {
    ui->stackedWidget->setCurrentWidget(ui->pageMeasure);
    flipOverAnimation(ui->pageMeasure);
}

/**
 * @brief KMFittingWidget::drawCurve
 * @param x
 * @param y
 */
void KMFittingWidget::drawCurve(QVector<double> x, QVector<double> y, double c) {

    int size = x.size();
    double xMin = 10000.0;
    double xMax = -10000.0;
    for (int i = 0; i < size; i ++) {
        double value = x.at(i);
        if (value < xMin) {
            xMin = value;
        }
        if (value > xMax) {
            xMax = value;
        }
    }

    QVector<double> curveX;
    QVector<double> curveY;
    double width = xMax - xMin;
    xMin = xMin - width/5;
    xMax = xMax + width/5;
    double step = (xMax - xMin)/100;
    for (int i = 0; i <= 100; i ++) {

        double yData = 0.0;
        double xData = xMin + i*step;
        int coefSize = m_fitCoefs.size();
        for (int j = 0; j < coefSize; j ++) {
            yData += qPow( xData, coefSize-j-1 )*m_fitCoefs.at( j );
        }

        curveX.append(xData);
        curveY.append(yData*c);
    }
    emit toDrawScatterCurve("Measure", x, y);
    emit toDrawFittingCurve("Fitting", curveX, curveY);
}

/**
 * @brief KMFittingWidget::getFuncStr
 * @param coefs
 * @return
 */
QString KMFittingWidget::getFuncStr(QList<double> coefs) {
    QString result;
    if (coefs.isEmpty()) {
        return result;
    }
    result.append( "y=" );
    int size = coefs.size();
    for(int i = 0; i < size; i ++) {
        if (i < size -1) {
            result.append( QString( "%1x^%2+" ).arg( coefs.at( i ) ).arg( size - i - 1 ) );
        } else {
            result.append( QString( "%1" ).arg( coefs.at( i ) ) );
        }
    }
    return result;
}

/**
 * @brief KMFittingWidget::getCoefStr
 * @param coefs
 * @return
 */
QString KMFittingWidget::getCoefStr(QList<double> coefs) {

    QString result;
    for (int i = 0; i < coefs.size(); i ++) {
        result.append( QString::number( coefs.at( i ) ) );
        if (i < coefs.size() - 1) {
            result.append( COEF_SPLIT );
        }
    }
    return result;
}

/**
 * @brief KMFittingWidget::transform
 * @param oUnit
 * @param nUnit
 */
double KMFittingWidget::transformCoef(QString oUnit, QString nUnit) {
    int c1 = transform(oUnit);
    int c2 = transform(nUnit);
    return (double)c1/(double)c2;
}

/**
 * @brief KMFittingWidget::transformCoef 获取转换系数
 * @param unit 单位
 * @return 系数
 */
int KMFittingWidget::transform(QString unit) {

    QStringList units;
    units << tr("ng/uL") << tr("mg/mL") << tr("ug/mL") << tr("ng/mL") << tr("g/L") << tr("mg/L");
    int coef = 1;
    switch(units.indexOf(unit)) {
    case 0:
    case 2:
    case 5:
        coef = 1000;
        break;
    case 1:
    case 4:
        coef = 1;
        break;
    case 3:
        coef = 1000000;
        break;
    default:
        break;
    }
    return coef;
}

/**
 * @brief KMFittingWidget::flipOverAnimation
 * @param w
 */
void KMFittingWidget::flipOverAnimation(QWidget *w) {

    if (m_isAnimation) {
        QPropertyAnimation *a = new QPropertyAnimation( w, "geometry" );
        QRect rect = w->geometry();
        a->setDuration( 1000 );
        a->setStartValue( QRect( rect.topRight(), QSize( 0, rect.height() ) ) );
        a->setEndValue( rect );
        a->setEasingCurve(QEasingCurve::OutCubic);
        a->start();
    }
}
