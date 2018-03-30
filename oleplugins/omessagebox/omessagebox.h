#ifndef OMESSAGEBOX_H
#define OMESSAGEBOX_H

#include <QDialog>

namespace Ui {
class OMessageBox;
}

class QPoint;
class QTimer;
class QAbstractButton;
class OMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit OMessageBox(int timeout = 0, QWidget *parent = 0);
    ~OMessageBox();

    QString title();
    void setTitle(QString title);
    bool isShown() {return m_isShown;}

    QIcon titleIcon();
    void setTitleIcon(QIcon icon);

    QString text();
    void setText(QString text);

    QIcon textIcon();
    void setTextIcon(QIcon icon);

    void gifEnable();

    void addButtons(QStringList labels);
    void setClosable(bool ok);

private slots:
    void quit();
    void refresh();
    void onFinished();
    void onBtnClicked(QAbstractButton *btn);

protected:
    virtual void showEvent(QShowEvent *e);
    virtual void closeEvent(QCloseEvent *e);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void mouseMoveEvent(QMouseEvent *e);

private:
    Ui::OMessageBox *ui;
    int m_timeout;
    bool m_isShown;
    bool m_isPressed;
    QPoint m_dragOrigin;
    QString m_text;
    QAbstractButton *m_btn;
    QTimer *m_pRefreshTimer;

    void showAnimation();
    void closeAnimation();
    void initializeStyleSheet();

};

#endif // OABSTRACTMESSAGEBOX_H
