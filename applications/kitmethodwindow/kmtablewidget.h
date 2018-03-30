#ifndef KMTABLEWIDGET_H
#define KMTABLEWIDGET_H

#include <QTableWidget>

class KMTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit KMTableWidget(QStringList headerLabels, QWidget *parent = 0);
    ~KMTableWidget();

    void add(QStringList itemLabels);
    void remove();
    void setCheckable(bool ok);

public slots:
    void checkAll(bool ok);
    void clearAll();

protected:
    virtual void showEvent(QShowEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    bool m_isCheckable;
    bool m_leftButtonPressed;
    QPoint m_originalPoint;
    QPoint m_originalPointBackup;
};

#endif // KMTABLEWIDGET_H
