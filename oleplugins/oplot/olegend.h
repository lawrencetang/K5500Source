#ifndef OLEGEND_H
#define OLEGEND_H

#include <qwt_legend.h>

class OPlot;
class QwtPlotItem;
class OLegend : public QwtLegend
{
    Q_OBJECT
public:
    OLegend(QWidget *parent = NULL);
    ~OLegend();

    OPlot *plot();

signals:
    void legendChecked(QwtPlotItem *item, bool on);

private slots:
    void onLegendChecked(const QVariant &itemInfo, bool on);
};

#endif // OLEGEND_H
