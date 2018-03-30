#ifndef KMTESTINGWIDGET_H
#define KMTESTINGWIDGET_H

#include <QFrame>

namespace Ui {
class KMTestingWidget;
}

class OPlot;
class OMessageBox;
class OFileExplorer;
class KMSettingModel;
class KMFittingWidget;
class ORecordTableWidget;
class KMTestingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit KMTestingWidget(QWidget *parent = 0);
    ~KMTestingWidget();

    void startFitting(KMSettingModel *setting);
    void setPlotTitle(QString title);
    void setOperatingKeyEnable(bool ok);
    void updateUnit(QString unit);
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
    void toStartFitting();
    void toUpdateSetting(QStringList record);

public slots:
    void saveResult(QString fileName, QStringList data);
    void saveRecord(QStringList data);
    void showResult(double c);

private slots:
    void capture();
    void clearAll();
    void showData(QString fileName);
    void doubleClickPlot();
    void doubleClickRecordTableWidget();

    void onBlankBtnClicked();
    void onMeasureBtnClicked();

private:
    Ui::KMTestingWidget *ui;
    OMessageBox *m_pDyMsgBox;
    OPlot *m_pPlot;
    QString m_plotTitle;
    OFileExplorer *m_pFileExplorer;
    KMFittingWidget *m_pFittingWidget;
    ORecordTableWidget *m_pRecordTableWidget;

    bool m_isShow;
    QRect m_leftRect;
    QRect m_mainRect;
    QRect m_bottomRect;

    bool m_isPressed;
    QPoint m_pressPos;
    QString m_axisYTitle;

    void initalizeSignals();
    void initalizeWidgets();
};

#endif // NUCLEICACIDTESTING_H
