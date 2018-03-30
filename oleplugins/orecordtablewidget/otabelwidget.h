#ifndef OTABELWIDGET_H
#define OTABELWIDGET_H

#include <QTableWidget>

class OTabelWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit OTabelWidget(QStringList headerLabels, QWidget *parent = 0);

    void setCheckable(bool ok);
    void insert(QStringList data);
    bool isExist(QString fileName);

public slots:
    void selectAll(bool ok);
    void exportSelecedItems();
    void removeSelecedItems();

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    bool m_isCheckable;
    bool m_leftButtonPressed;
    QPoint m_originalPoint;
    QPoint m_originalPointBackup;
    void refresh();
};

#endif // OTABELWIDGET_H
