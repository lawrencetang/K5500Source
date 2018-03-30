#ifndef KMFITTINGWIDGET_H
#define KMFITTINGWIDGET_H

#include <QFrame>

namespace Ui {
class KMFittingWidget;
}

class QHBoxLayout;
class KMTableWidget;
class ODigitKeyboard;
class KMSettingModel;
class KMFittingWidget : public QFrame
{
    Q_OBJECT

public:
    explicit KMFittingWidget(QWidget *parent = 0);
    ~KMFittingWidget();

    bool isReady();
    void clearAll();
    void setAnimationEnable(bool ok){m_isAnimation = ok;}
    void insertAbso(double c);
    void updateUnit(QString unit);
    void updateData(QVector<double> x, QVector<double> y, QStringList record);
    void updateCurve(QString unit);
    void excuteFitting(KMSettingModel *setting);

signals:
    void toDrawFittingCurve(QString title, QVector<double> x, QVector<double> y);
    void toDrawScatterCurve(QString title, QVector<double> x, QVector<double> y);
    void toSaveResult(QString fileName, QStringList result);
    void toSaveRecord(QStringList record);
    void toExcuteFit();
    void toClearCurves();

private slots:
    void showAddView();
    void showRemoveView();
    void showFittingView();
    void showMeasureView();

private:
    Ui::KMFittingWidget *ui;
    bool m_isAnimation;
    bool m_isNewItem;
    QHBoxLayout *m_pFitLayout;
    KMTableWidget *m_pFitTableWidget;
    KMTableWidget *m_pMeasureTableWidget;
    ODigitKeyboard *m_pDigitKeyboard;

    int m_order;
    double m_r2;
    QString m_unit;
    QList<double> m_fitCoefs;

    void drawCurve(QVector<double> x, QVector<double> y, double c=1.0);
    QString getFuncStr(QList<double> coefs);
    QString getCoefStr(QList<double> coefs);
    double transformCoef(QString oUnit, QString nUnit);
    int transform(QString unit);
    void flipOverAnimation(QWidget *w);
};

#endif // KMFITTINGWIDGET_H
