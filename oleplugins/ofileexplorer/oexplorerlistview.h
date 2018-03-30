#ifndef OEXPLORERLISTVIEW_H
#define OEXPLORERLISTVIEW_H

#include <QListView>

class OExplorerListView : public QListView
{
    Q_OBJECT
public:
    OExplorerListView(QWidget *parent = 0);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    bool m_leftButtonPressed;
    QPoint m_originalPoint;
    QPoint m_originalPointBackup;
};

#endif // OEXPLORERLISTVIEW_H
