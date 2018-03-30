#ifndef OPLOT_H
#define OPLOT_H

#include <qwt_plot.h>

class OLegend;
class OPlotZoomer;
class QwtPlotCurve;
class QwtPlotMarker;
class OPlot : public QwtPlot
{
    Q_OBJECT
public:
    explicit OPlot(QWidget *parent= NULL);
    ~OPlot();

    bool isRuler(QwtPlotMarker *ruler);
    void zoomerReset();
    void installZoomer();
    void uninstallZoomer();

    void setPlotTitle(QString title);
    void setAxisXLabel(QString text);
    void setAxisXScale(double xMin, double xMax);
    void setAxisYLabel(QString text);
    void setAxisYScale(double yMin, double yMax);

    void addRulers(int count, QStringList positions);
    void addDynamicCureves(QStringList titles);

signals:
    void doubleClicked();

public slots:
    void clearRulers();
    void clearCurves();

    void hideRulers();
    void hideCurves();
    void hideScatters(QwtPlotItem *item, bool off);

    void drawStaticCurve(QString title, QVector<double> x, QVector<double> y);
    void drawFittingCurve(QString title, QVector<double> x, QVector<double> y);
    void drawScatterCurve(QString title, QVector<double> x, QVector<double> y);
    void drawDynamicCurve(double x, QVector<double> y);

private slots:
    void onLegendChecked(QwtPlotItem *item, bool ok);

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

private:
    double m_axisXMin;
    double m_axisXMax;
    double m_axisYMin;
    double m_axisYMax;
    OLegend *m_pLegend;
    OPlotZoomer *m_pZoomer;
    QList<QColor> m_colors;
    QList<QwtPlotCurve *> m_curves;
    QList<QwtPlotMarker *> m_rulers;
    QList<double> m_rulersPos;
    QMap<QwtPlotCurve *, QList<QwtPlotMarker *> > m_scatterCurveMapper;

    void refresh();
    bool isExist(QString title, QVector<double> y);
    void updateXAxisData(QVector<double> &x, QVector<double> &y);
    void updateAxisX();
    void updateAxisY();
    void showPlotItem(QwtPlotItem *item, bool on);
};

#endif // OPLOT_H
