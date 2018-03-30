#ifndef OFILEEXPLORER_H
#define OFILEEXPLORER_H

#include <QMap>
#include <QFrame>

namespace Ui {
class OFileExplorer;
}

class QHBoxLayout;
class QToolButton;
class OExplorerListView;
class OFileExplorer : public QFrame
{
    Q_OBJECT

public:
    explicit OFileExplorer(QString dirPath = "", QWidget *parent = 0);
    ~OFileExplorer();

    void reset();
    void setAnimationEnable(bool ok) {
        m_isAnimation = ok;
    }
    void insertImage(QString fileName);
    void insertDataFile(QString fileName, QStringList data);

signals:
    void doubleClicked(QString fileName);

private slots:
    void toMainView();
    void toListView();
    void toEditView();
    void onDoubleClicked(const QModelIndex & index);

private:
    Ui::OFileExplorer *ui;
    bool m_isAnimation;
    QString m_dir;
    QString m_type;
    QString m_operation;
    QMap<QToolButton *, QString> m_dirMapper;
    QMap<QToolButton *, QString> m_operationMapper;

    OExplorerListView *m_pExplorerListView;
    QHBoxLayout *layout;

    void flipOverAnimation(QWidget *w);
    void initializeWidget();
};

#endif // OFILEEXPLORER_H
