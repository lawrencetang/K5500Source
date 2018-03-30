#include "oplotcanvas.h"
#include <QDebug>
#include <QMouseEvent>

#include <qwt_plot.h>
#include <qwt_plot_item.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_marker.h>

#include "oplot.h"
#include "oplotzoomer.h"

OPlotCanvas::OPlotCanvas(QwtPlot *plot)
    : QwtPlotCanvas(plot) {

    setPaintAttribute(QwtPlotCanvas::BackingStore, false);
    setBorderRadius(10);
}

OPlotCanvas::~OPlotCanvas() {

}

/**
 * @brief OPlotCanvas::setRulerPos
 * @param ruler
 * @param x
 */
void OPlotCanvas::setRulerPos(QwtPlotMarker *ruler, int x) {
    m_pSelectedRuler = ruler;
    moveRuler(x);
    m_pSelectedRuler = NULL;
}

/**
 * @brief OPlotCanvas::mouseDoubleClickEvent
 * @param event
 */
void OPlotCanvas::mouseDoubleClickEvent(QMouseEvent *event) {
    // 双击还原
    if (Qt::LeftButton == event->button()) {
        OPlot *plot = static_cast<OPlot *>(this->plot());
        if (NULL != plot) {
            plot->zoomerReset();
            return;
        }
    }
    QwtPlotCanvas::mouseDoubleClickEvent(event);
}

/**
 * @brief OPlotCanvas::mouseMoveEvent
 * @param event
 */
void OPlotCanvas::mouseMoveEvent(QMouseEvent *event) {
    // 移动标尺
    if (NULL != m_pSelectedRuler) {
        OPlot *plot = static_cast<OPlot *>(this->plot());
        if (NULL != plot) {
            if (plot->isRuler(m_pSelectedRuler)) {
                moveRuler(plot->invTransform(QwtPlot::xBottom, event->pos().x()));
                replot();
                return;
            }
        }
    }
    QwtPlotCanvas::mouseMoveEvent(event);

}

/**
 * @brief OPlotCanvas::mousePressEvent
 * @param event
 */
void OPlotCanvas::mousePressEvent(QMouseEvent *event) {
    // 选中标尺
    if (Qt::LeftButton == event->button()) {
        OPlot *plot = static_cast<OPlot *>(this->plot());
        if (NULL != plot) {
            double x = plot->invTransform(QwtPlot::xBottom, event->pos().x());
            double d = plot->axisInterval(QwtPlot::xBottom).width()/100;

            const QwtPlotItemList &itemList = plot->itemList();
            for (QwtPlotItemIterator item = itemList.begin(); item != itemList.end(); ++item) {
                if ( ( *item )->rtti() == QwtPlotItem::Rtti_PlotMarker ) {
                    QwtPlotMarker *ruler = static_cast<QwtPlotMarker *>(*item);

                    // 不是ruler
                    if (!plot->isRuler(ruler)) {
                        continue;
                    }

                    // ruler不可见
                    if (!ruler->isVisible()) {
                        continue;
                    }

                    int dx = abs(ruler->xValue() - x);
                    if (dx < d) {
                        m_pSelectedRuler = ruler;
                        plot->uninstallZoomer();
                        return;
                    }
                }
            }
        }
    }
    QwtPlotCanvas::mousePressEvent(event);
}

/**
 * @brief OPlotCanvas::mouseReleaseEvent
 * @param event
 */
void OPlotCanvas::mouseReleaseEvent(QMouseEvent *event) {
    // 释放标尺
    if (Qt::LeftButton == event->button()) {
        if (NULL != m_pSelectedRuler) {
            OPlot *plot = static_cast<OPlot *>(this->plot());
            if (NULL != plot) {
                m_pSelectedRuler = NULL;
                plot->installZoomer();
                return;
            }
        }
    }
    //QwtPlotCanvas::mouseReleaseEvent(event);
}

/**
 * @brief OPlotCanvas::moveRuler
 * @param targetX
 */
void OPlotCanvas::moveRuler(double targetX) {

    if (NULL == m_pSelectedRuler) {
        return;
    }

    OPlot *plot = static_cast<OPlot *>(this->plot());
    if (NULL == plot) {
        return;
    }

    // 找焦点
    int x = qRound(targetX);
    QMap<QString, double> curveMap;
    const QwtPlotItemList& itmList = plot->itemList();
    for (QwtPlotItemIterator item = itmList.begin(); item != itmList.end(); ++item) {
        if (( *item )->rtti() == QwtPlotItem::Rtti_PlotCurve) {
            QwtPlotCurve *curve = static_cast<QwtPlotCurve *>( *item );
            if (!curve->isVisible()) {
                continue;
            }

            int index = x - curve->minXValue();
            int size = static_cast<int>(curve->dataSize());
            if (index < 0 || index >= size) {
                continue;
            }

            const QPointF sample = curve->sample(index);
            curveMap.insert(curve->title().text(), sample.y());
        }
    }
    m_pSelectedRuler->setValue(x, 0.0);

    // 显示内容
    QString text = QString("%1:\nx=%2").arg(m_pSelectedRuler->title().text()).arg(x);
    QMapIterator<QString, double> i(curveMap);
    while (i.hasNext()) {
        i.next();
        text.append(QString("\ny%1=%2").arg(i.key()).arg(i.value()));
    }
    QwtText rulerText(text);
    rulerText.setRenderFlags(Qt::AlignLeft);
    rulerText.setColor(m_pSelectedRuler->linePen().color());
    rulerText.setFont(QFont("黑体", 8, QFont::Bold));
    m_pSelectedRuler->setLabel(rulerText);

    // 显示位置
    double width = plot->axisInterval(QwtPlot::xBottom).width();
    double minValue = plot->axisInterval(QwtPlot::xBottom).minValue();
    if (x > minValue + width/2) {
        m_pSelectedRuler->setLabelAlignment(Qt::AlignLeft|Qt::AlignTop);
    } else {
        m_pSelectedRuler->setLabelAlignment(Qt::AlignRight|Qt::AlignTop);
    }
    m_pSelectedRuler->setLabelOrientation(Qt::Horizontal);
}

