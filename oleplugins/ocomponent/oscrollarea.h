#ifndef OSCROLLAREA_H
#define OSCROLLAREA_H

#include <QScrollArea>

namespace Ui {
class OScrollArea;
}

class OScrollArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit OScrollArea(QWidget *parent = 0);
    ~OScrollArea();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::OScrollArea *ui;
    bool m_leftButtonPressed;
    QPoint m_originalPoint;
};

#endif // OSCROLLAREA_H
