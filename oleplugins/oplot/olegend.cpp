#include "olegend.h"
#include "oplot.h"
#include <qwt_plot_item.h>
#include <qwt_legend_label.h>

OLegend::OLegend(QWidget *parent)
    :QwtLegend(parent) {
    setDefaultItemMode(QwtLegendData::Checkable);
    setStyleSheet(QString("font: bold 20pt \"微软雅黑\";color: black;"));
    connect(this, SIGNAL(checked(QVariant,bool,int)), this, SLOT(onLegendChecked(QVariant,bool)));
}

OLegend::~OLegend() {

}

/**
 * @brief OLegend::plot
 * @return
 */
OPlot *OLegend::plot() {
    return static_cast<OPlot *>(this->parent());
}

/**
 * @brief OLegend::onLegendChecked
 * @param itemInfo
 * @param on
 */
void OLegend::onLegendChecked(const QVariant &itemInfo, bool on) {
    OPlot *plot = this->plot();
    if (NULL == plot) {
        return;
    }
    QwtPlotItem *item = plot->infoToItem(itemInfo);
    if (NULL == item) {
        return;
    }
    QwtLegendLabel *legendLabel = qobject_cast<QwtLegendLabel *>(this->legendWidget(itemInfo));
    if (NULL == legendLabel) {
        return;
    }
    item->setVisible(on);
    legendLabel->setChecked(on);
    plot->hideScatters(item, on);
    emit legendChecked(item, on);
}

