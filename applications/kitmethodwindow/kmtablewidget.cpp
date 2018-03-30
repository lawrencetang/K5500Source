#include "kmtablewidget.h"

#include <QDir>
#include <QFile>
#include <QDebug>
#include <QCheckBox>
#include <QScrollBar>
#include <QMouseEvent>
#include <QTextStream>
#include <QHeaderView>
#include <QRadioButton>

KMTableWidget::KMTableWidget(QStringList headerLabels, QWidget *parent)
    : QTableWidget(parent) {
    setColumnCount(headerLabels.size());
    setHorizontalHeaderLabels(headerLabels);

    m_isCheckable = false;
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
    horizontalHeader->setFont(QFont("微软雅黑", 14, QFont::Bold));
    horizontalHeader->setMinimumHeight(40);
    setFrameShape(QFrame::NoFrame);

    setShowGrid(false);
    setStyleSheet(QString("QTableWidget::item{border:1px solid rgb(160, 160, 160);border-right:0px;border-top:0px;}"
                          "QHeaderView::section, QTableCornerButton::section {padding: 1px;border: none;border-bottom: "
                          "1px solid rgb(160, 160, 160);border-right: 1px solid rgb(160, 160, 160);border-bottom: 1px solid gray;"
                          "background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(164, 164, 164, 255));}"));
}

KMTableWidget::~KMTableWidget() {

}

/**
 * @brief KMTableWidget::add
 * @param data
 */
void KMTableWidget::add(QStringList itemLabels) {
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
            checkBox->setStyleSheet(QString("QCheckBox{ color:black; font: bold 10pt \"微软雅黑\"; }"));
            setCellWidget(row, 0, checkBox);
        } else {
            QTableWidgetItem *item = new QTableWidgetItem(itemText);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            item->setFont(QFont("微软雅黑", 10, QFont::Bold));
            item->setTextColor(Qt::black);
            setItem(row, c, item);
        }
    }

    QHeaderView *horizontalHeader = this->horizontalHeader();
    horizontalHeader->resizeSections(QHeaderView::Stretch);
}

/**
 * @brief KMTableWidget::remove
 */
void KMTableWidget::remove() {
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
}

/**
 * @brief KMTableWidget::setCheckable
 * @param ok
 */
void KMTableWidget::setCheckable(bool ok) {

    m_isCheckable = ok;
    int rowCount = this->rowCount();
    if (ok) {
        for (int r = 0; r < rowCount; r ++) {
            QTableWidgetItem *item = this->item(r, 0);
            if (item) {
                QCheckBox *checkBox = new QCheckBox(item->text());
                checkBox->setStyleSheet(QString("QCheckBox{ color:black; font: bold 10pt \"微软雅黑\"; }"));
                this->setCellWidget(r, 0, checkBox);
                delete item;
            }
        }
    } else {
        for (int r = 0; r < rowCount; r ++) {
            QCheckBox *checkBox = static_cast<QCheckBox *>(this->cellWidget(r, 0));
            if (checkBox) {
                QTableWidgetItem *item = new QTableWidgetItem(checkBox->text());
                item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                item->setFont(QFont("微软雅黑", 10, QFont::Bold));
                item->setTextColor(Qt::black);
                this->removeCellWidget(r, 0);
                this->setItem(r, 0, item);
            }
        }
    }
}

/**
 * @brief KMTableWidget::selectAll
 * @param ok
 */
void KMTableWidget::checkAll(bool ok) {
    int rowCount = this->rowCount();
    for (int r = 0; r < rowCount; r ++) {
        QCheckBox *checkBox = static_cast<QCheckBox *>(this->cellWidget(r, 0));
        checkBox->setChecked(ok);
    }
}

/**
 * @brief KMTableWidget::clearAll
 */
void KMTableWidget::clearAll() {
    int rowCount = this->rowCount();
    for (int r = rowCount - 1; r >=0 ; r --) {
        this->removeRow(r);
    }
}

/**
 * @brief KMTableWidget::showEvent
 * @param event
 */
void KMTableWidget::showEvent(QShowEvent *event) {

    Q_UNUSED(event)
    QHeaderView *horizontalHeader = this->horizontalHeader();
    horizontalHeader->resizeSections(QHeaderView::Stretch);
    horizontalHeader->setStretchLastSection(true);
}

/**
 * @brief KMTableWidget::mousePressEvent
 * @param event
 */
void KMTableWidget::mousePressEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        m_leftButtonPressed = true;
        m_originalPoint = event->globalPos();
        m_originalPointBackup = m_originalPoint;
    }
    QTableWidget::mousePressEvent(event);
}

/**
 * @brief KMTableWidget::mouseMoveEvent
 * @param event
 */
void KMTableWidget::mouseMoveEvent(QMouseEvent *event) {

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
 * @brief KMTableWidget::mouseReleaseEvent
 * @param event
 */
void KMTableWidget::mouseReleaseEvent(QMouseEvent *event) {

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

