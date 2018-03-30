#ifndef OEXPLORERLISTMODEL_H
#define OEXPLORERLISTMODEL_H

#include <QMap>
#include <QImage>
#include <QAbstractListModel>

struct FileItem {
    QString fileName;
    bool isChecked;
};

class QFileInfo;
class OExplorerListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit OExplorerListModel(QObject *parent = 0);
    ~OExplorerListModel();

    int count() { return m_fileItemList.size(); }
    void setRootPath(QString path);
    void setCheckable(bool checkable);

    void cutSelectedItems();
    void removeSelectedItems();

    void insert(int index, QString fileName);
    void insert(int index, QString fileName, QStringList data);
    void romove(int index);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);

public slots:
    void selectAll(bool ok);

private:
    int m_upperLimit;
    bool m_checkable;
    QImage m_image;
    QList<FileItem *> m_fileItemList;

    void refresh();
};

#endif // OEXPLORERLISTMODEL_H
