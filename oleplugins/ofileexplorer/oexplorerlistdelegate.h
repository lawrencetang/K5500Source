#ifndef OEXPLORERLISTDELEGATE_H
#define OEXPLORERLISTDELEGATE_H

#include <QStyledItemDelegate>


class OExplorerListDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit OExplorerListDelegate(QObject *parent = 0);

    // 1.如果需要重绘，需要实现以下几个函数：
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual void paint(QPainter * painter,const QStyleOptionViewItem & option,const QModelIndex & index) const;
    // 2.如果需要自定义编辑器，需要实现以下几个函数：
    virtual QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
    virtual void setEditorData(QWidget *editor, const QModelIndex &index) const;
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // OEXPLORERLISTDELEGATE_H
