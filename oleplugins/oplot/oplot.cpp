#include "oplot.h"
#include "olegend.h"
#include "oplotcanvas.h"
#include "oplotzoomer.h"

#include <QDebug>
#include <QMouseEvent>
#include <qwt_symbol.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>
#include <qwt_legend_label.h>

OPlot::OPlot(QWidget *parent)
    :QwtPlot( parent ) {
    // 设置画布
    setCanvas( new OPlotCanvas() );

    // 坐标系
    setAxisFont(QwtPlot::yLeft, QFont("微软雅黑", 9));
    setAxisFont(QwtPlot::xBottom, QFont("微软雅黑", 9));

    // 设置网格
    QwtPlotGrid *grid = new QwtPlotGrid();
    grid->setPen( Qt::gray, 0.0, Qt::DotLine );
    grid->enableX( true );
    grid->enableXMin( true );
    grid->enableY( true );
    grid->enableYMin( false );
    grid->attach( this );

    // 设置Legend
    m_pLegend = new OLegend();
    insertLegend( m_pLegend, QwtPlot::RightLegend );
    connect(m_pLegend, SIGNAL(legendChecked(QwtPlotItem *, bool)), this, SLOT(onLegendChecked(QwtPlotItem *, bool)));

    // 安装Zoomer
    m_pZoomer = NULL;
    installZoomer();

    m_colors << Qt::black << Qt::red << Qt::darkRed << Qt::green
             << Qt::darkGreen << Qt::blue << Qt::darkBlue << Qt::cyan
             << Qt::darkCyan << Qt::magenta << Qt::darkMagenta << Qt::yellow
             << Qt::darkYellow << Qt::gray << Qt::darkGray << Qt::darkBlue;
}

OPlot::~OPlot() {

}

/**
 * @brief OPlot::isRuler 是否为ruler
 * @param ruler 甄别对象
 * @return true/false
 */
bool OPlot::isRuler(QwtPlotMarker *ruler) {
    if (m_rulers.contains(ruler)) {
        return true;
    }
    return false;
}

/**
 * @brief OPlot::zoomerReset 恢复显示
 */
void OPlot::zoomerReset() {
    if (NULL != m_pZoomer) {
        m_pZoomer->zoom(0);
    }
}

/**
 * @brief OPlot::installZoomer 装在Zoomer
 */
void OPlot::installZoomer() {
    if (NULL == m_pZoomer) {
        m_pZoomer = new OPlotZoomer(QwtPlot::xBottom, QwtPlot::yLeft, canvas());
    }
}

/**
 * @brief OPlot::uninstallZoomer 卸载Zoomer
 */
void OPlot::uninstallZoomer() {
    zoomerReset();
    if (NULL != m_pZoomer) {
        delete m_pZoomer;
        m_pZoomer = NULL;
    }
}

/**
 * @brief OPlot::setPlotTitle
 * @param title
 */
void OPlot::setPlotTitle(QString title) {
    QwtText qwtText;
    qwtText.setText(title);
    qwtText.setFont(QFont("微软雅黑", 14, QFont::Bold));
    setTitle(qwtText);
}

/**
 * @brief OPlot::setAxisXLabel
 * @param text
 */
void OPlot::setAxisXLabel(QString text) {
    QwtText qwtText;
    qwtText.setText(text);
    qwtText.setFont(QFont("微软雅黑", 12, QFont::Bold));
    setAxisTitle(QwtPlot::xBottom, qwtText);
}

/**
 * @brief OPlot::setAxisXScale
 * @param xMin
 * @param xMax
 */
void OPlot::setAxisXScale(double xMin, double xMax) {
    setAxisScale(QwtPlot::xBottom, xMin, xMax);
    m_axisXMin = xMin;
    m_axisXMax = xMax;
}

/**
 * @brief OPlot::setAxisYLabel
 * @param text
 */
void OPlot::setAxisYLabel(QString text) {
    QwtText qwtText;
    qwtText.setText(text);
    qwtText.setFont(QFont("微软雅黑", 12, QFont::Bold));
    setAxisTitle(QwtPlot::yLeft, qwtText);
}

/**
 * @brief OPlot::setAxisYScale
 * @param yMin
 * @param yMax
 */
void OPlot::setAxisYScale(double yMin, double yMax) {
    setAxisScale(QwtPlot::yLeft, yMin, yMax);
    m_axisYMin = yMin;
    m_axisYMax = yMax;
}

/**
 * @brief OPlot::addRulers
 * @param count
 */
void OPlot::addRulers(int count, QStringList positions) {

    for (int i = 0; i < count; i ++) {
        QwtPlotMarker *ruler = new QwtPlotMarker();
        ruler->setTitle(tr("Ruler%1").arg(i+1));
        ruler->setLineStyle(QwtPlotMarker::VLine);
        ruler->setLinePen(m_colors.at(i%m_colors.size()), 2, Qt::DashLine);
        ruler->setVisible(false);
        ruler->setItemAttribute(QwtPlotItem::Legend, true);
        ruler->attach(this);
        m_rulers.append(ruler);
    }

    m_rulersPos.clear();
    foreach(QString pos, positions) {
        m_rulersPos.append(pos.toDouble());
    }
    refresh();
}

/**
 * @brief OPlot::addDynamicCureves
 * @param titles
 */
void OPlot::addDynamicCureves(QStringList titles) {

    setAxisAutoScale(QwtPlot::yLeft, true);
    setAxisAutoScale(QwtPlot::xBottom, true);
    QwtPlotCurve *curve = NULL;
    for (int i = 0; i < titles.size(); i ++) {
        QColor color = m_colors.at(i%m_colors.size());
        curve = new QwtPlotCurve(titles.at(i));
        curve->setPen(color);
        curve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, color, color, QSize(8, 8)));
        curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
        curve->setPaintAttribute(QwtPlotCurve::ClipPolygons, false);
        curve->attach(this);

        showPlotItem(curve, (i == 0));
        m_curves.append(curve);
    }
    setAxisAutoScale(QwtPlot::yLeft, false);
    setAxisAutoScale(QwtPlot::xBottom, false);
}

/**
 * @brief OPlot::clearRules
 */
void OPlot::clearRulers() {

    while(!m_rulers.isEmpty()) {
        QwtPlotMarker *ruler = m_rulers.takeFirst();
        delete ruler;
        ruler = NULL;
    }
}

/**
 * @brief OPlot::clearCurves
 */
void OPlot::clearCurves() {

    while(!m_curves.isEmpty()) {
        QwtPlotCurve *curve = m_curves.takeFirst();
        if (m_scatterCurveMapper.contains(curve)) {
            QList<QwtPlotMarker *> scatters = m_scatterCurveMapper.take(curve);
            while(!scatters.isEmpty()) {
                QwtPlotMarker *scatter = scatters.takeFirst();
                delete scatter;
                scatter = NULL;
            }
        }
        delete curve;
        curve = NULL;
    }

    uninstallZoomer();
    setAxisScale(QwtPlot::xBottom, m_axisXMin, m_axisXMax);
    setAxisScale(QwtPlot::yLeft, m_axisYMin, m_axisYMax);
    installZoomer();
}

/**
 * @brief OPlot::hideRulers
 */
void OPlot::hideRulers() {
    for (int i = 0; i < m_rulers.size(); i++) {
        QwtPlotMarker *ruler = m_rulers.at(i);
        showPlotItem(ruler, false);
    }
}

/**
 * @brief OPlot::hideCurves
 */
void OPlot::hideCurves() {
    for (int i = 0; i < m_curves.size(); i++) {
        QwtPlotCurve *curve = m_curves.at(i);
        showPlotItem(curve, false);
    }
}

/**
 * @brief OPlot::hideScatters
 * @param item
 */
void OPlot::hideScatters(QwtPlotItem *item, bool off) {
    // 如果是散点图,则将散点和曲线一同隐藏
    if (item->rtti() == QwtPlotItem::Rtti_PlotCurve) {
        QwtPlotCurve *curve = static_cast<QwtPlotCurve *>(item);
        if(m_scatterCurveMapper.contains(curve)) {
            QList<QwtPlotMarker *> scatters = m_scatterCurveMapper.value(curve);
            for (int i = 0; i < scatters.size(); i ++) {
                QwtPlotMarker *scatter = scatters.at(i);
                scatter->setVisible(off);
            }
        }
    }
}

/**
 * @brief OPlot::drawStaticCurve
 * @param title
 * @param x
 * @param y
 */
void OPlot::drawStaticCurve(QString title, QVector<double> x, QVector<double> y) {

    updateXAxisData(x, y);
    if (isExist(title, y)) {
        return;
    }
    uninstallZoomer();
    setAxisAutoScale(QwtPlot::yLeft, true);
    QColor color = m_colors.at(m_curves.size()%m_colors.size());
    QwtPlotCurve *curve = new QwtPlotCurve(title);
    curve->setPen(color);
    curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    curve->setPaintAttribute(QwtPlotCurve::ClipPolygons, false);
    curve->setSamples(x, y);
    curve->attach(this);
    showPlotItem(curve, true);
    m_curves.append(curve);
    refresh();
    setAxisAutoScale(QwtPlot::yLeft, false);
    updateAxisY();
    installZoomer();
}

/**
 * @brief OPlot::drawFittingCurve
 * @param title
 * @param x
 * @param y
 */
void OPlot::drawFittingCurve(QString title, QVector<double> x, QVector<double> y) {

    uninstallZoomer();
    setAxisAutoScale(QwtPlot::yLeft, true);
    setAxisAutoScale(QwtPlot::xBottom, true);
    QColor color = m_colors.at(m_curves.size()%m_colors.size());
    QwtPlotCurve *curve = new QwtPlotCurve(title);
    curve->setPen(color);
    curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    curve->setPaintAttribute(QwtPlotCurve::ClipPolygons, false);
    curve->setSamples(x, y);
    curve->attach(this);
    showPlotItem(curve, true);
    m_curves.append(curve);
    refresh();
    setAxisAutoScale(QwtPlot::yLeft, false);
    setAxisAutoScale(QwtPlot::xBottom, false);
    installZoomer();
}

/**
 * @brief OPlot::drawScatterCurve
 * @param title
 * @param x
 * @param y
 */
void OPlot::drawScatterCurve(QString title, QVector<double> x, QVector<double> y) {

    uninstallZoomer();
    setAxisAutoScale(QwtPlot::yLeft, true);
    QColor color = m_colors.at(m_curves.size()%m_colors.size());
    QwtPlotCurve *curve = new QwtPlotCurve(title);
    curve->setPen(QPen(Qt::NoPen));
    curve->setSymbol(new QwtSymbol(QwtSymbol::Ellipse, Qt::black, color, QSize(8, 8)));
    curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    curve->setPaintAttribute(QwtPlotCurve::ClipPolygons, false);
    curve->setSamples(x, y);
    curve->attach(this);
    showPlotItem(curve, true);
    m_curves.append(curve);
    refresh();
    setAxisAutoScale(QwtPlot::yLeft, false);

    QList<QwtPlotMarker *> scatters;
    for (int i = 0; i < x.size(); i ++) {
        double xVal = x.at(i);
        double yVal = y.at(i);

        QwtPlotMarker *scatter = new QwtPlotMarker();
        scatter->setLineStyle(QwtPlotMarker::NoLine);
        scatter->setVisible(true);
        scatter->setItemAttribute(QwtPlotItem::Legend, false);

        QwtText text(QString("x=%1\ny=%2").arg(xVal).arg(yVal));
        text.setRenderFlags(Qt::AlignLeft);
        text.setColor(Qt::red);
        text.setFont(QFont("微软雅黑", 8, QFont::Bold));

        scatter->setLabel(text);
        scatter->setLabelAlignment(Qt::AlignRight | Qt::AlignBottom);
        scatter->setValue(xVal, yVal);
        scatter->attach(this);
        scatters.append(scatter);
    }
    m_scatterCurveMapper.insert(curve, scatters);
    updateAxisY();
    uninstallZoomer();
}

/**
 * @brief OPlot::drawDynamicCurve
 * @param x
 * @param y
 */
void OPlot::drawDynamicCurve(double x, QVector<double> y) {

    uninstallZoomer();
    setAxisAutoScale(QwtPlot::yLeft, true);
    setAxisAutoScale(QwtPlot::xBottom, true);
    QVector<double> xData;
    QVector<double> yData;
    for (int i = 0; i < m_curves.size(); i ++) {
        xData.clear();
        yData.clear();
        QwtPlotCurve *curve = m_curves.at(i);
        int size = static_cast<int>(curve->dataSize());
        for ( int j = 0; j < size; j ++ ) {
            const QPointF sample = curve->sample(j);
            xData.append(sample.x());
            yData.append(sample.y());
        }
        xData.append(x);
        if (i < y.size()) {
            yData.append(y.at(i));
        } else {
            yData.append(0);
        }
        curve->setSamples(xData, yData);
    }
    refresh();
    setAxisAutoScale(QwtPlot::yLeft, false);
    setAxisAutoScale(QwtPlot::xBottom, false);
    installZoomer();
}

/**
 * @brief OPlot::onLegendChecked
 * @param ok
 */
void OPlot::onLegendChecked(QwtPlotItem *item, bool ok) {
    refresh();
    if (ok) {
        int size = m_rulersPos.size();
        for (int i = 0; i < m_rulers.size(); i++) {
            QwtPlotMarker *ruler = m_rulers.at(i);
            if (item == ruler) {
                OPlotCanvas *canvas = static_cast<OPlotCanvas *>(this->canvas());
                if (NULL == canvas) {
                    continue;
                }
                if (i < size) {
                    canvas->setRulerPos(ruler, m_rulersPos.at(i));
                }
                break;
            }
        }
    }
}

/**
 * @brief OPlot::mouseDoubleClickEvent
 * @param event
 */
void OPlot::mouseDoubleClickEvent(QMouseEvent *event) {
    emit doubleClicked();
    QwtPlot::mouseDoubleClickEvent(event);
}

/**
 * @brief OPlot::refresh
 */
void OPlot::refresh() {

    OPlotCanvas *canvas = static_cast<OPlotCanvas *>(this->canvas());
    if (NULL != canvas) {
        for (int i = 0; i < m_rulers.size(); i++) {
            QwtPlotMarker *ruler = m_rulers.at(i);
            if (ruler->isVisible()) {
                canvas->setRulerPos(ruler, ruler->xValue());
            }
        }
    }
    replot();
}

/**
 * @brief OPlot::isExist
 * @param title
 * @param y
 */
bool OPlot::isExist(QString title, QVector<double> y) {

    int size = 0;
    bool flag = false;
    foreach (QwtPlotCurve *curve, m_curves) {
        if (curve->title().text() == title) {
            flag = false;
            size = static_cast<int>(curve->dataSize());
            for (int i = 0; i < size; i ++) {
                if(QString::number(y.at(i)) != QString::number(curve->sample(i).y())) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                continue;
            }
            return true;
        }
    }
    return false;
}

/**
 * @brief OPlot::updateXAxisData
 * @param x
 * @param y
 */
void OPlot::updateXAxisData(QVector<double> &x, QVector<double> &y) {
    QVector<double> nx;
    QVector<double> ny;
    int maxValue = axisInterval(QwtPlot::xBottom).maxValue();
    int minValue = axisInterval(QwtPlot::xBottom).minValue();
    for (int i = 0; i < x.size(); i ++) {
        if (x.at(i) >= minValue && x.at(i) <= maxValue) {
            nx.append(x.at(i));
            ny.append(y.at(i));
        }
    }
    x.clear();
    y.clear();
    x<<(nx);
    y<<(ny);
}

/**
 * @brief OPlot::updateAxisX
 */
void OPlot::updateAxisX() {
    uninstallZoomer();
    double maxValue = axisInterval(QwtPlot::xBottom).maxValue();
    double minValue = axisInterval(QwtPlot::xBottom).minValue();
    double xMax, xMin;
    if (minValue == maxValue) {
       xMax = minValue + 10;
       xMin = minValue;
    } else {
        xMax = maxValue + 1;
        xMin = minValue - 1;
    }
    setAxisScale(QwtPlot::xBottom, xMin, xMax);
    installZoomer();
    refresh();
}

/**
 * @brief OPlot::updateAxisY
 */
void OPlot::updateAxisY() {

    double maxValue = axisInterval(QwtPlot::yLeft).maxValue();
    double minValue = axisInterval(QwtPlot::yLeft).minValue();
    double yMax, yMin;
    if (minValue > 0) {
        yMax = maxValue*9/8;
        yMin = -maxValue/8;
    } else if (maxValue <= 0) {
        yMax = (-minValue)/8;
        yMin = minValue*9/8;
    } else {
        yMax = maxValue*9/8;
        yMin = -maxValue/8;
    }
    setAxisScale(QwtPlot::yLeft, yMin, yMax);
    refresh();
}

/**
 * @brief OPlot::showPlotItem
 * @param item
 * @param on
 */
void OPlot::showPlotItem(QwtPlotItem *item, bool on) {

    item->setVisible(on);
    OLegend *legend = qobject_cast<OLegend *>( this->legend() );
    QWidget *legendWidget = legend->legendWidget(itemToInfo(item));
    QwtLegendLabel *legendLabel = qobject_cast<QwtLegendLabel *>(legendWidget);
    if (legendLabel) {
        legendLabel->setChecked(on);
    }
    refresh();
}

