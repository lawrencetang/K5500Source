#ifndef MADYEWIDGET_H
#define MADYEWIDGET_H

#include <QFrame>

namespace Ui {
class MADyeWidget;
}

class QHBoxLayout;
class MADyeTableWidget;
class MADyeWidget : public QFrame
{
    Q_OBJECT

public:
    explicit MADyeWidget(QWidget *parent = 0);
    ~MADyeWidget();

    QList<QStringList> getSelectedDyes();

signals:
    void headerDisabled(bool ok);

public slots:
    void showAddPage();
    void showListPage();
    void showRemovePage();

private slots:
    void checkAll(bool ok);

private:
    Ui::MADyeWidget *ui;
    bool m_isAnimation;
    MADyeTableWidget *m_pTableWidget;
    QHBoxLayout *layout;
    QList<QWidget *> m_dyeList;

    void flipOverAnimation(QWidget *w);
};

#endif // MADYEWIDGET_H
