#ifndef TOOLWINDOW_H
#define TOOLWINDOW_H

#include <QFrame>

namespace Ui {
class ToolWindow;
}

class ToolWindow : public QFrame
{
    Q_OBJECT

public:
    explicit ToolWindow(QWidget *parent = 0);
    ~ToolWindow();

    void setBackEnable(bool ok);

signals:
    void backToMainPage();

private slots:
    void showTeamViewer();
    void showManual();
    void restart();
    void shutDown();

private:
    Ui::ToolWindow *ui;

    QString m_teamViewer;
    QString m_document;
};

#endif // TOOLWINDOW_H
