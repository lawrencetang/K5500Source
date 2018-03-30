#ifndef OCONTROLPANEL_H
#define OCONTROLPANEL_H

#include <QFrame>

namespace Ui {
class OControlPanel;
}

class QToolButton;
class OControlPanel : public QFrame
{
    Q_OBJECT

public:
    explicit OControlPanel(QStringList applicationNameList, int columnCount = 4, QWidget *parent = 0);
    ~OControlPanel();

    QList<QToolButton *> controlKeyList();
    QMap<QToolButton *, QWidget *> makeControlMapper(QList<QWidget *> pages);

private:
    Ui::OControlPanel *ui;
    QList<QToolButton *> m_tBtnList;
    int m_columnCount;
};

#endif // OCONTROLPANEL_H
