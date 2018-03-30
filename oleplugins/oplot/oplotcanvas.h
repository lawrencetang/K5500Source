#ifndef OPLOTCANVAS_H
#define OPLOTCANVAS_H

#include <qwt_plot_canvas.h>

class OPlotZoomer;
class QwtPlotMarker;
class OPlotCanvas : public QwtPlotCanvas
{
    Q_OBJECT
public:
    explicit OPlotCanvas(QwtPlot *plot = NULL);
    ~OPlotCanvas();

    void setRulerPos(QwtPlotMarker *ruler, int x);

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    QwtPlotMarker *m_pSelectedRuler;
    void moveRuler(double targetX);
};

#endif // OPLOTCANVAS_H
