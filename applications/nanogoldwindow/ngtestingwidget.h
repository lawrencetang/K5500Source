#ifndef NGTESTINGWIDGET_H
#define NGTESTINGWIDGET_H

#include <QFrame>

namespace Ui {
class NGTestingWidget;
}

class OPlot;
class OMessageBox;
class OFileExplorer;
class ORecordTableWidget;
class NGTestingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit NGTestingWidget(QWidget *parent = 0);
    ~NGTestingWidget();

    void setPlotTitle(QString title);
    void setOperatingKeyEnable(bool ok);
    void setAnimationEnable(bool ok);

protected:
    virtual void showEvent(QShowEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

signals:
    void backBtnClicked();
    void toSettingPage();
    void toStartBlank();
    void toStartMeasure();

public slots:
    void drawStaticCurve(QString title, QVector<double> x, QVector<double> y);
    void saveResult(QString fileName, QStringList data);
    void saveRecord(QStringList data);

private slots:
    void capture();
    void showData(QString fileName);
    void doubleClickPlot();
    void doubleClickRecordTableWidget();

    void onBlankBtnClicked();
    void onMeasureBtnClicked();

private:
    Ui::NGTestingWidget *ui;
    OMessageBox *m_pDyMsgBox;
    OPlot *m_pPlot;
    QString m_plotTitle;
    OFileExplorer *m_pFileExplorer;
    ORecordTableWidget *m_pRecordTableWidget;

    bool m_isShow;
    QRect m_leftRect;
    QRect m_mainRect;
    QRect m_bottomRect;

    bool m_isPressed;
    QPoint m_pressPos;

    void initalizeSignals();
    void initalizeWidgets();
};

#endif // NUCLEICACIDTESTING_H
