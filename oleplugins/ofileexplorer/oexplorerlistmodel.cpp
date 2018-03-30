#include "oexplorerlistmodel.h"

#include <QDir>
#include <QFile>
#include <QImage>
#include <QDebug>
#include <QFileInfo>
#include <QDateTime>
#include <QFileDialog>

OExplorerListModel::OExplorerListModel(QObject *parent):
     QAbstractListModel(parent) {

    m_checkable = false;
    m_upperLimit = 1000;
}

OExplorerListModel::~OExplorerListModel() {
}

/**
 * @brief OExplorerListModel::setDir
 * @param dir
 */
void OExplorerListModel::setRootPath(QString path) {

    QDir dir(path);
    if (!dir.exists()) {
        bool ok = dir.mkdir(path);
        if (!ok) {
            return;
        }
    }

    qDeleteAll(m_fileItemList);
    m_fileItemList.clear();

    if (!path.endsWith("/")) {
        path += "/";
    }

    QStringList suffixList;
    if (path.endsWith("files/")) {
        m_image = QImage( ":/ofileexplorer_icons/file.png" );
        suffixList = QStringList()<<".csv";
    } else if (path.endsWith("images/")) {
        m_image = QImage( ":/ofileexplorer_icons/picture.png" );
        suffixList = QStringList()<<".png"<<".jpg";
    }

    QFileInfoList files = dir.entryInfoList(QDir::Files, QDir::Time);
    foreach(QFileInfo fileInfo, files) {
        for (int j = 0; j < suffixList.size(); j ++) {
            if (fileInfo.fileName().endsWith(suffixList.at(j))) {
                FileItem *item = new FileItem();
                item->fileName = fileInfo.absoluteFilePath();
                item->isChecked = false;
                m_fileItemList.append(item);
            }
        }
        if (m_fileItemList.size() >= m_upperLimit) {
            break;
        }
    }
    refresh();
}

/**
 * @brief OExplorerListModel::setCheckable
 * @param checkable
 */
void OExplorerListModel::setCheckable(bool checkable) {
    m_checkable = checkable;
}

/**
 * @brief OExplorerListModel::cutSelectedItems
 */
void OExplorerListModel::cutSelectedItems() {

    QString path = QFileDialog::getExistingDirectory(0, tr("Save Directory"), "",
                                                     QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    if (path.isEmpty()) {
        return;
    }

    foreach (FileItem *item, m_fileItemList) {
        if (item->isChecked) {
            QFileInfo fileInfo(item->fileName);
            QFile::copy(item->fileName, path + "/" + fileInfo.fileName());
        }
    }
    removeSelectedItems();
}

/**
 * @brief OExplorerListModel::removeSelectedItems
 */
void OExplorerListModel::removeSelectedItems() {

    int size = m_fileItemList.size();
    for (int i = size - 1; i >= 0; i --) {
        if (m_fileItemList.at(i)->isChecked) {
            romove(i);
        }
    }
}

/**
 * @brief OExplorerListModel::insert
 * @param index
 * @param fileName
 */
void OExplorerListModel::insert(int index, QString fileName) {
    FileItem *item = new FileItem();
    item->fileName = fileName;
    item->isChecked = false;
    m_fileItemList.insert(index, item);
    if (m_fileItemList.size() >= m_upperLimit) {
        romove(m_fileItemList.size() - 1);
    }//lt:多余最多存放上限，移除最后一个文件
    refresh();
}

/**
 * @brief OExplorerListModel::insert
 * @param index
 * @param fileName
 * @param data
 */
void OExplorerListModel::insert(int index, QString fileName, QStringList data) {

    QFile file(fileName);
    if (!file.open( QIODevice::WriteOnly|QIODevice::Truncate )) {
        return;
    }
    QTextStream out(&file);
    out.setCodec("GB2312");
    for (int i = 0; i < data.size(); i ++) {
        out << data.at(i);
        if (i != data.size() - 1) {
            out << "\n";
        }
    }
    file.close();

    FileItem *item = new FileItem();
    item->fileName = fileName;
    item->isChecked = false;
    m_fileItemList.insert(index, item);
    if (m_fileItemList.size() >= m_upperLimit) {
        romove(m_fileItemList.size() - 1);
    }
    refresh();
}

/**
 * @brief OExplorerListModel::romove
 * @param index
 */
void OExplorerListModel::romove(int index) {

    FileItem *item = m_fileItemList.takeAt(index);
    QFile::remove(item->fileName);
    delete item;
    item = NULL;
    refresh();
}

/**
 * @brief OExplorerListModel::rowCount
 * @param parent
 * @return
 */
int OExplorerListModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_fileItemList.size();
}

/**
 * @brief OExplorerListModel::columnCount
 * @param parent
 * @return
 */
int OExplorerListModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return 1;
}

/**
 * @brief OExplorerListModel::data
 * @param index
 * @param role
 * @return
 */
QVariant OExplorerListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return QVariant();
    }

    switch (role) {
    case Qt::DisplayRole:
         // 无操作时, 显示的数据项文字
        return QVariant(m_fileItemList.at(index.row())->fileName);
    case Qt::DecorationRole:
        // 无操作时, 显示的数据项图片
        return m_image;
    case Qt::CheckStateRole:
        // 一个数据项的复选状态
        return QVariant(m_fileItemList.at(index.row())->isChecked);
    case Qt::UserRole + 1:
        return m_checkable;
    default:
        return QVariant();
    }
}

/**
 * @brief OExplorerListModel::headerData
 * @param section
 * @param orientation
 * @param role
 * @return
 */
QVariant OExplorerListModel::headerData(int section, Qt::Orientation orientation, int role) const {
    return QAbstractListModel::headerData(section, orientation, role);
}

/**
 * @brief OExplorerListModel::flags
 * @param index
 * @return
 */
Qt::ItemFlags OExplorerListModel::flags(const QModelIndex &index) const {
    return QAbstractItemModel::flags(index);
}

/**
 * @brief OExplorerListModel::setData
 * @param index
 * @param value
 * @param role
 * @return
 */
bool OExplorerListModel::setData(const QModelIndex &index, const QVariant &value, int role) {

    if (index.isValid() && role == Qt::CheckStateRole) {
        m_fileItemList.at(index.row())->isChecked = value.toBool();
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

/**
 * @brief OExplorerListModel::selectAll
 */
void OExplorerListModel::selectAll(bool ok) {

    for (int i = 0; i < m_fileItemList.size(); i ++) {
        FileItem *item = m_fileItemList.at(i);
        item->isChecked = ok;
    }
    refresh();
}

/**
 * @brief OExplorerListModel::refresh
 */
void OExplorerListModel::refresh() {
    beginResetModel();
    endResetModel();
}

