#ifndef OIMAGEVIEW_H
#define OIMAGEVIEW_H

#include <QDialog>

namespace Ui {
class OImageView;
}

class OImageView : public QDialog
{
    Q_OBJECT

public:
    explicit OImageView(QString title, QPixmap pixmap, QWidget *parent = 0);
    ~OImageView();

protected:
    virtual void showEvent(QShowEvent *e);
    virtual void closeEvent(QCloseEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);

private:
    Ui::OImageView *ui;
    bool m_isPressed;
    QPoint m_dragOrigin;

    void showAnimation();
};

#endif // OIMAGEVIEW_H
