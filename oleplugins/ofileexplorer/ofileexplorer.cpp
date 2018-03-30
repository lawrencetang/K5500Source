#include "ofileexplorer.h"
#include "ui_ofileexplorer.h"

#include <QDir>
#include <QDebug>
#include <QPropertyAnimation>
#include "oexplorerlistview.h"
#include "oexplorerlistmodel.h"
#include "oexplorerlistdelegate.h"
#include "omessageboxutil.h"

OFileExplorer::OFileExplorer(QString dirPath, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OFileExplorer) {

    ui->setupUi(this);
    m_dir = QDir::currentPath() + "/" + dirPath;//lt:dirPath=data/nanogold/或其他
    if (!m_dir.endsWith("/")) {
        m_dir.append( "/" );
    }

    QDir dir(m_dir);
    if (!dir.exists()) {
        m_dir = QDir::currentPath() + "/";
        QStringList pathList = dirPath.split("/", QString::SkipEmptyParts);
        foreach(QString path, pathList) {
            m_dir = m_dir + path + "/";
            dir.mkdir(m_dir);
        }
    }
    initializeWidget();
}

OFileExplorer::~OFileExplorer() {
    delete ui;
}

/**
 * @brief OFileExplorer::reset
 */
void OFileExplorer::reset() {
    toMainView();
}

/**
 * @brief OFileExplorer::insertImage
 * @param fileName
 */
void OFileExplorer::insertImage(QString fileName) {
    OExplorerListModel *model = static_cast<OExplorerListModel *>(m_pExplorerListView->model());
    if (model == NULL) {
        return;
    }
    model->insert(0, fileName);
    ui->toolButtonCut->setEnabled(model->count() != 0);
    ui->toolButtonRemove->setEnabled(model->count() != 0);
}

/**
 * @brief OFileExplorer::insert
 * @param fileName
 * @param data
 */
void OFileExplorer::insertDataFile(QString fileName, QStringList data) {

    OExplorerListModel *model = static_cast<OExplorerListModel *>(m_pExplorerListView->model());
    if (model == NULL) {
        return;
    }
    model->insert(0, fileName, data);
    ui->toolButtonCut->setEnabled(model->count() != 0);
    ui->toolButtonRemove->setEnabled(model->count() != 0);
}

/**
 * @brief OFileExplorer::toMainView
 */
void OFileExplorer::toMainView() {

    m_operation.clear();
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    flipOverAnimation(ui->pageMain);
}

/**
 * @brief OFileExplorer::toListView
 */
void OFileExplorer::toListView() {

    OExplorerListModel *model = static_cast<OExplorerListModel *>(m_pExplorerListView->model());
    if (model == NULL) {
        return;
    }

    QToolButton *tBtn = static_cast<QToolButton *>(this->sender());//lt:确定是哪个键发的信号
    if (m_dirMapper.contains(tBtn)) {
        QString rootPath = m_dir + m_dirMapper.value(tBtn);//lt:进入该按键的相应目录
        model->setRootPath(rootPath);
    } else {
        if (tBtn == ui->toolButtonOk) {
            if (m_operation == "Cut") {
                model->cutSelectedItems();
            } else if (m_operation == "Remove") {
                int ret = OMessageBoxUtil::staticNotice(0, tr("Do you want to remove which you selected items?"),
                                                        QStringList() << tr("OK") << tr("Cancel"), 10);
                if (ret == 0) {
                    model->removeSelectedItems();
                }
            }
        }
        ui->checkBoxCheckAll->setChecked(false);
    }

    ui->toolButtonCut->setEnabled(model->count() != 0);
    ui->toolButtonRemove->setEnabled(model->count() != 0);

    model->selectAll(false);
    model->setCheckable(false);
    ui->frameList->setLayout(layout);
    ui->stackedWidget->setCurrentWidget(ui->pageList);
    flipOverAnimation(ui->pageList);
}

/**
 * @brief OFileExplorer::toEditView
 */
void OFileExplorer::toEditView() {

    OExplorerListModel *model = static_cast<OExplorerListModel *>(m_pExplorerListView->model());
    if (model == NULL) {
        return;
    }

    model->setCheckable(true);
    ui->frameEdit->setLayout(layout);
    QToolButton *tBtn = static_cast<QToolButton *>(this->sender());
    if (m_operationMapper.contains(tBtn)) {
        m_operation = m_operationMapper.value(tBtn);
        ui->labelTitle->setText(m_operation);
    }
    ui->stackedWidget->setCurrentWidget(ui->pageEdit);
    flipOverAnimation(ui->pageEdit);
}

/**
 * @brief OFileExplorer::onDoubleClicked
 * @param index
 */
void OFileExplorer::onDoubleClicked(const QModelIndex &index) {

    if (!index.isValid()) {
        return;
    }

    if (ui->stackedWidget->currentWidget() != ui->pageList) {
        return;
    }

    QString fileName = index.model()->data(index, Qt::DisplayRole).toString();
    emit doubleClicked(fileName);
}

/**
 * @brief ExcuteView::flipOverAnimation
 * @param w
 */
void OFileExplorer::flipOverAnimation(QWidget *w) {

    if (m_isAnimation) {
        QPropertyAnimation *a = new QPropertyAnimation( w, "geometry" );
        QRect rect = w->geometry();
        a->setDuration( 1000 );
        a->setStartValue( QRect(rect.topLeft(), QSize(0, rect.height())) );
        a->setEndValue( rect );
        a->setEasingCurve(QEasingCurve::OutCubic);
        a->start();
    }
}

/**
 * @brief OFileExplorer::initializeWidget
 */
void OFileExplorer::initializeWidget() {

    m_isAnimation = true;
    QStringList subDirs;
    subDirs << "files/" << "images/";
    QString subDirPath;
    foreach(QString subDir, subDirs) {
        subDirPath = m_dir + subDir;//lt:遍历subdirs这个list第一次循环吧files字符串赋给subdir,第二次循环赋值images
        QDir dir(subDirPath);
        if (!dir.exists()) {
            dir.mkdir(subDirPath);
        }
    }

    QList<QToolButton *> tBtnList;
    tBtnList << ui->toolButtonFile << ui->toolButtonImage;
    int size = subDirs.size();
    for (int i = 0; i < tBtnList.size(); i ++) {
        if (i < size) {
            m_dirMapper.insert(tBtnList.at(i), subDirs.at(i));//lt:值和按键对应
        }
    }
    for(int i = 0; i < tBtnList.size(); i ++) {
        connect(tBtnList.at(i), SIGNAL(clicked(bool)), this, SLOT(toListView()));//lt:两个按键的信号连接
    }

    m_operationMapper.insert(ui->toolButtonCut, "Cut");
    m_operationMapper.insert(ui->toolButtonRemove, "Remove");
    QList<QToolButton *> tBtns = m_operationMapper.keys();
    for(int i = 0; i < tBtns.size(); i ++) {
        connect(tBtns.at(i), SIGNAL(clicked(bool)), this, SLOT(toEditView()));
    }

    connect(ui->toolButtonBack, SIGNAL(clicked(bool)), this, SLOT(toMainView()));
    connect(ui->toolButtonCancel, SIGNAL(clicked(bool)), this, SLOT(toListView()));
    connect(ui->toolButtonOk, SIGNAL(clicked(bool)), this, SLOT(toListView()));

    layout = new QHBoxLayout();
    m_pExplorerListView = new OExplorerListView();
    m_pExplorerListView->setModel(new OExplorerListModel());
    m_pExplorerListView->setItemDelegate(new OExplorerListDelegate());
    layout->addWidget(m_pExplorerListView);
    layout->setMargin(0);
    ui->frameList->setLayout(layout);

    OExplorerListModel *model = static_cast<OExplorerListModel *>(m_pExplorerListView->model());
    connect(ui->checkBoxCheckAll, SIGNAL(clicked(bool)), model, SLOT(selectAll(bool)));
    connect(m_pExplorerListView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onDoubleClicked(QModelIndex)));
}
