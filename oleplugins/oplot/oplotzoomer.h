#ifndef OPLOTZOOMER_H
#define OPLOTZOOMER_H

#include <qwt_plot_zoomer.h>

class OPlotZoomer : public QwtPlotZoomer
{
    Q_OBJECT
public:
    OPlotZoomer(QWidget *canvas);
    OPlotZoomer(int xAxis, int yAxis, QWidget *canvas);
    ~OPlotZoomer();

protected:
    virtual QwtText trackerTextF(const QPointF &pos) const;

private:
    void initialize();
};

#endif // OPLOTZOOMER_H
