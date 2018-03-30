#include "oexplorerlistdelegate.h"

#include <QDebug>
#include <QPainter>
#include <QFileInfo>
#include <QDateTime>
#include <QMouseEvent>
#include <QApplication>

OExplorerListDelegate::OExplorerListDelegate(QObject *parent):
    QStyledItemDelegate(parent) {
}

/**
 * @brief OExplorerListDelegate::sizeHint 定义每个item的大小，每个item的大小可以不一样
 * @param option
 * @param index
 * @return
 */
QSize OExplorerListDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    Q_UNUSED(index)
    return QSize(option.rect.width(), 100);
}

/**
 * @brief OExplorerListDelegate::paint
 * @param painter
 * @param option
 * @param index
 */
void OExplorerListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {

    QRect rect = option.rect;
    painter->save();
    painter->setPen(QPen(Qt::gray, 1));
    painter->drawLine(rect.bottomLeft(), rect.bottomRight());

    int space = 5;
    int x = rect.left() + space;
    if (index.model()->data(index, Qt::UserRole + 1).toBool()) {
        painter->setPen(QPen(Qt::blue, 1, Qt::SolidLine));
        if(index.model()->data(index, Qt::CheckStateRole).toBool()) {
            painter->setBrush(Qt::blue);
            painter->drawRect(QRect(rect.left()+8, rect.center().y() - 5, 10, 10));
        }
        painter->setBrush(Qt::NoBrush);
        painter->drawRect(QRect(x, rect.center().y() - 8, 16, 16));
        x += (16 + space);
    }

    int iWidth = 64;
    QImage image = qvariant_cast<QImage>(index.model()->data(index, Qt::DecorationRole));
    painter->drawImage(QRect(x, rect.center().y() - iWidth/2, iWidth, iWidth), image);
    painter->restore();
    x += (iWidth + space);

    painter->save();
    painter->setFont(QFont("微软雅黑", 12));
    painter->setPen(QPen(Qt::darkBlue));
    QString filePath = index.model()->data(index, Qt::DisplayRole).toString();
    QFileInfo fileInfo(filePath);
    QString title = QString::number(index.row() + 1) + "." + fileInfo.fileName();
    painter->drawText(QRect(x, rect.topLeft().y(), rect.width()-x, rect.height() - 30), title, Qt::AlignLeft | Qt::AlignVCenter);
    painter->restore();

    painter->setPen(QPen(Qt::darkYellow));
    QString sizeStr = QString("%1KB").arg((double)fileInfo.size()/1024, 0, 'g', 3);
    painter->drawText(QRect(x, rect.topLeft().y() + 60, (rect.width()-x)/2, 30), sizeStr, Qt::AlignLeft | Qt::AlignVCenter);
    QString createStr = fileInfo.created().toString("hh.mm.ss");
    painter->drawText(QRect(x + (rect.width()-x)/2, rect.topLeft().y() + 60, (rect.width()-x)/2, 30), createStr, Qt::AlignRight | Qt::AlignVCenter);
}

/**
 * @brief OExplorerListDelegate::createEditor 触发编辑时, 创建editor
 * @param parent
 * @param option
 * @param index
 * @return
 */
QWidget *OExplorerListDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    Q_UNUSED(parent)
    Q_UNUSED(option)
    Q_UNUSED(index)
    // 此处创建自己的Editor
    return NULL;
}

/**
 * @brief OExplorerListDelegate::editorEvent 触发编辑后, 处理editor的事件
 * @param event
 * @param model
 * @param option
 * @param index
 * @return 返回true表示处理event, false表示不处理event
 */
bool OExplorerListDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) {

    Q_UNUSED(option)
    if (!index.model()->data(index, Qt::UserRole + 1).toBool()) {
        return false;
    }

    if(event->type() == QEvent::MouseButtonRelease) {
        QMouseEvent *e = static_cast<QMouseEvent*>(event);
        if(e->button() != Qt::LeftButton) {
            return false;
        }
    } else {
        return false;
    }

    bool checked = index.model()->data(index, Qt::CheckStateRole).toBool();
    return model->setData(index, !checked, Qt::CheckStateRole);
}

/**
 * @brief OExplorerListDelegate::setEditorData 触发编辑后, 从model中获取数据传递给editor
 * @param editor
 * @param index
 */
void OExplorerListDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
    // 从index中获取数据后传入editor中
    Q_UNUSED(editor)
    Q_UNUSED(index)
}

/**
 * @brief OExplorerListDelegate::setModelData 编辑完成后,根据editor的数据更新model的数据
 * @param editor
 * @param model
 * @param index
 */
void OExplorerListDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    Q_UNUSED(editor)
    Q_UNUSED(model)
    Q_UNUSED(index)
}

/**
 * @brief OExplorerListDelegate::updateEditorGeometry 触发编辑后, 保证editor显示在item的合适位置、大小
 * @param editor
 * @param option
 * @param index
 */
void OExplorerListDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    Q_UNUSED(editor)
    Q_UNUSED(option)
    Q_UNUSED(index)
}

