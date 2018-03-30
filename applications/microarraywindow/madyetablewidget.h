#ifndef MADYETABLEWIDGET_H
#define MADYETABLEWIDGET_H

#include <QTableWidget>

class MADyeTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit MADyeTableWidget(QStringList headerLabels, QWidget *parent = 0);
    ~MADyeTableWidget();

public slots:
    void append(QStringList itemLabels);
    void remove();

protected:
    virtual void showEvent(QShowEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

private:
    bool m_loading;
    bool m_isCheckable;
    bool m_leftButtonPressed;
    QPoint m_originalPoint;
    QPoint m_originalPointBackup;

    void loadDye();
    void saveDye();
    void initializeSystem();
};

#endif // MADYETABLEWIDGET_H
