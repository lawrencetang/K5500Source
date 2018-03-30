#ifndef ORECORDTABLEWIDGET_H
#define ORECORDTABLEWIDGET_H

#include <QFrame>

namespace Ui {
class ORecordTableWidget;
}

class QModelIndex;
class OTabelWidget;
class ORecordTableWidget : public QFrame
{
    Q_OBJECT

public:
    explicit ORecordTableWidget(QStringList headerLabels, QString title = "", QWidget *parent = 0);
    ~ORecordTableWidget();

    void setTitle(QString title);
    void insert(QStringList data);
    void setAnimationEnable(bool ok) {m_isAnimation = ok;}
    void setHorizontalHeaderStretchLastSection(bool ok);
    void setVerticalHeaderStretchLastSection(bool ok);

signals:
    void doubleClicked();
    void showItemDetail(QString fileName);

protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

private slots:
    void toMainView();
    void toOptionView();
    void onItemDoubleClicked(const QModelIndex & index);

private:
    Ui::ORecordTableWidget *ui;
    bool m_isAnimation;
    OTabelWidget *m_pTableWidget;

    void flipOverAnimation(QWidget *w);
};

#endif // ORECORDTABLEWIDGET_H
