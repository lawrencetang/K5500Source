#include "ocontrolpanel.h"
#include "ui_ocontrolpanel.h"

#include <QDir>
//#include <QSettings>
#include <QGridLayout>
#include <QToolButton>

OControlPanel::OControlPanel(QStringList applicationNameList, int columnCount, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OControlPanel) {
    ui->setupUi(this);

    m_columnCount = columnCount;
    QString currentPath = QDir::currentPath() + "/images/system/";
    foreach (QString applicationName, applicationNameList) {
        QToolButton *tBtn = new QToolButton();
        tBtn->setText(applicationName);
        tBtn->setIcon(QIcon(currentPath + QString( "%1.png" ).arg(applicationName)));//lt:根据遍历的选择相应的application图片
        tBtn->setAutoRaise(true);//lt:背景自动提升
        tBtn->setIconSize(QSize(200, 200));
        tBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);//lt:文字出现在图标下
        m_tBtnList.append(tBtn);
    }//lt:设置按钮属性
    setStyleSheet(QString("QFrame{background:transparent;}"
                          "QToolButton{color:white; Font:20pt,\"微软雅黑\";}"));

    QGridLayout *gLayout = new QGridLayout();
    for(int i = 0; i < m_tBtnList.size(); i++) {
        int row = i/m_columnCount;//lt:计算图标所在的行
        int colum = i%m_columnCount;//lt:计算图标所在的列
        gLayout->addWidget(m_tBtnList.at(i), row, colum, 1, 1);
        gLayout->setRowMinimumHeight(row, 350);
    }
    this->setLayout(gLayout);
}//lt:网格布局

OControlPanel::~OControlPanel() {
    delete ui;
}

/**
 * @brief OControlPanel::controlKeyList
 * @return
 */
QList<QToolButton *> OControlPanel::controlKeyList() {
    return m_tBtnList;
}

/**
 * @brief OControlPanel::makeControlMapper
 * @param pages
 * @return
 */
QMap<QToolButton *, QWidget *> OControlPanel::makeControlMapper(QList<QWidget *> pages) {
    QMap<QToolButton *, QWidget *> resultMap;
    int size = pages.size();
    for (int i = 0; i < m_tBtnList.size(); i++) {
        if (i < size) {
            resultMap.insert(m_tBtnList.at(i), pages.at(i));
        }
    }//lt:btnlist做键，pagelist做值
    return resultMap;
}
