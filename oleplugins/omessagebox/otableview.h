#ifndef OTABLEVIEW_H
#define OTABLEVIEW_H

#include <QDialog>

namespace Ui {
class OTableView;
}

class OTableView : public QDialog
{
    Q_OBJECT

public:
    explicit OTableView(QStringList headerLabels, QList<QStringList> infos, QWidget *parent = 0);
    ~OTableView();

    void setTitle(QString title);

protected:
    virtual void showEvent(QShowEvent *e);
    virtual void closeEvent(QCloseEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);

private:
    Ui::OTableView *ui;
    bool m_isPressed;
    QPoint m_dragOrigin;

    void showAnimation();
};

#endif // OTABLEWIDGET_H
