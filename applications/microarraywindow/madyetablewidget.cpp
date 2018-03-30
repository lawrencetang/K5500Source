#include "madyetablewidget.h"

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QCheckBox>
#include <QScrollBar>
#include <QMouseEvent>
#include <QTextStream>
#include <QHeaderView>

MADyeTableWidget::MADyeTableWidget(QStringList headerLabels, QWidget *parent) :
    QTableWidget(parent) {

    setColumnCount(headerLabels.size());
    setHorizontalHeaderLabels(headerLabels);
    initializeSystem();

    setShowGrid(false);
    setStyleSheet(QString("QTableWidget::item{border-bottom:1px solid rgb(160, 160, 160);}"
                          "QHeaderView::section, QTableCornerButton::section {padding: 1px;border: none;border-bottom: "
                          "1px solid rgb(160, 160, 160);border-right: 1px solid rgb(160, 160, 160);border-bottom: 1px solid gray;"
                          "background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(164, 164, 164, 255));}"));
}

MADyeTableWidget::~MADyeTableWidget() {

}

/**
 * @brief MADyeTableWidget::append
 * @param items
 */
void MADyeTableWidget::append(QStringList itemLabels) {

    int row = this->rowCount();
    this->insertRow(row);
    QString itemText = "";
    int dataSize = itemLabels.size();
    int columnCount = this->columnCount();
    for (int c = 0; c < columnCount; c ++) {
        if (c < dataSize) {
            itemText = itemLabels.at(c);
        }
        if (m_isCheckable && c == 0) {
            QCheckBox *checkBox = new QCheckBox(itemText);
            checkBox->setStyleSheet(QString("QCheckBox{ color:black; font: bold 9pt \"微软雅黑\"; }"));
            setCellWidget(row, 0, checkBox);
        } else {
            QTableWidgetItem *item = new QTableWidgetItem(itemText);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            item->setFont(QFont("微软雅黑", 9, QFont::Bold));
            item->setTextColor(Qt::black);
            setItem(row, c, item);
        }
    }

    QHeaderView *horizontalHeader = this->horizontalHeader();
    horizontalHeader->resizeSections(QHeaderView::Stretch);
    if (!m_loading) {
        saveDye();
    }
}

/**
 * @brief MADyeTableWidget::remove
 */
void MADyeTableWidget::remove() {
    if (!m_isCheckable) {
        return;
    }
    int rowCount = this->rowCount();
    for (int r = rowCount - 1; r >=0 ; r --) {
        QCheckBox *checkBox = static_cast<QCheckBox *>(this->cellWidget(r, 0));
        if (checkBox) {
            if (checkBox->isChecked()) {
                this->removeRow(r);
            }
        }
    }
    saveDye();
}

/**
 * @brief MADyeTableWidget::showEvent
 * @param event
 */
void MADyeTableWidget::showEvent(QShowEvent *event) {
    Q_UNUSED(event)
    QHeaderView *horizontalHeader = this->horizontalHeader();
    horizontalHeader->resizeSections(QHeaderView::Stretch);
    horizontalHeader->setStretchLastSection(true);
}

/**
 * @brief MADyeTableWidget::mousePressEvent
 * @param event
 */
void MADyeTableWidget::mousePressEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        m_leftButtonPressed = true;
        m_originalPoint = event->globalPos();
        m_originalPointBackup = m_originalPoint;
    }
    QTableWidget::mousePressEvent(event);
}

/**
 * @brief MADyeTableWidget::mouseMoveEvent
 * @param event
 */
void MADyeTableWidget::mouseMoveEvent(QMouseEvent *event) {

    if (m_leftButtonPressed) {
        int xMoved = event->globalPos().x() - m_originalPoint.x();
        int yMoved = event->globalPos().y() - m_originalPoint.y();
        verticalScrollBar()->setValue(verticalScrollBar()->value() - yMoved);
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - xMoved);
        m_originalPoint = event->globalPos();
        return;
    }
    QTableWidget::mouseMoveEvent(event);
}

/**
 * @brief MADyeTableWidget::mouseReleaseEvent
 * @param event
 */
void MADyeTableWidget::mouseReleaseEvent(QMouseEvent *event) {

    if (m_leftButtonPressed) {
        m_leftButtonPressed = false;
        int yMoved = event->globalPos().y() - m_originalPointBackup.y();
        int xMoved = event->globalPos().x() - m_originalPointBackup.x();
        if (abs(yMoved) > 10 || abs(xMoved) > 10) {
            return;
        }
    }

    if (m_isCheckable) {
        int row = this->rowAt(event->pos().y());
        if (row >= 0) {
            QCheckBox *checkBox = static_cast<QCheckBox *>(this->cellWidget(row, 0));
            if (checkBox) {
                checkBox->setChecked(!checkBox->isChecked());
            }
        }
    }
    QTableWidget::mouseReleaseEvent(event);
}

/**
 * @brief MADyeTableWidget::loadDye
 */
void MADyeTableWidget::loadDye() {

    QFile file(QDir::currentPath() + "/configs/microarray/dye.csv");
    if (file.open(QIODevice::ReadOnly)) {

        m_loading = true;
        QTextStream in(&file);
        while(!in.atEnd()) {
            QStringList strList = in.readLine().split( ",", QString::SkipEmptyParts );
            if (!strList.isEmpty()) {
                append( strList );
            }
        }
        file.close();
        m_loading = false;
    }
}

/**
 * @brief MADyeTableWidget::saveDye
 * @param dye
 */
void MADyeTableWidget::saveDye() {

    QFile file(QDir::currentPath() + "/configs/microarray/dye.csv");
    if (file.open(QIODevice::WriteOnly|QIODevice::Truncate)) {
        QTextStream out(&file);
        int rowCount = this->rowCount();
        int columnCount = this->columnCount();
        for (int r = 0; r < rowCount; r ++) {
            for (int c = 0; c < columnCount; c ++) {
                QString text;
                if (m_isCheckable && c == 0) {
                    QCheckBox *checkBox = static_cast<QCheckBox *>(this->cellWidget(r, c));
                    text = checkBox->text() + ",";
                } else {
                    text = this->item(r, c)->text() + ",";
                }
                out << text;
            }
            out << "\n";
        }
        file.close();
    }
}

/**
 * @brief MADyeTableWidget::initializeSystem
 */
void MADyeTableWidget::initializeSystem() {

    m_loading = false;
    m_isCheckable = true;
    m_leftButtonPressed = false;

    setEditTriggers(QTableWidget::NoEditTriggers);
    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSelectionMode(QAbstractItemView::NoSelection);
    setSelectionBehavior(QAbstractItemView::SelectRows);

    setGridStyle(Qt::NoPen);
    QHeaderView *verticalHeader = this->verticalHeader();
    verticalHeader->setSectionsClickable(false);
    verticalHeader->setFont(QFont("微软雅黑", 10));
    verticalHeader->setDefaultSectionSize(40);

    QHeaderView *horizontalHeader = this->horizontalHeader();
    horizontalHeader->setStretchLastSection(true);
    horizontalHeader->resizeSections(QHeaderView::Stretch);
    horizontalHeader->setSectionsClickable(false);
    horizontalHeader->setFont(QFont("微软雅黑", 10, QFont::Bold));
    horizontalHeader->setMinimumHeight(40);
    setFrameShape(QFrame::NoFrame);
    loadDye();
}
