#include "otabelwidget.h"

#include <QDebug>
#include <QCheckBox>
#include <QScrollBar>
#include <QHeaderView>
#include <QFileDialog>
#include <QMouseEvent>

OTabelWidget::OTabelWidget(QStringList headerLabels, QWidget *parent) :
    QTableWidget(parent) {

    setColumnCount(headerLabels.size());
    setHorizontalHeaderLabels(headerLabels);
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
    verticalHeader->setFont(QFont("微软雅黑", 12, QFont::Bold));
    verticalHeader->setDefaultSectionSize(40);

    QHeaderView *horizontalHeader = this->horizontalHeader();
    horizontalHeader->setSectionsClickable(false);
    horizontalHeader->setFont(QFont("微软雅黑", 12, QFont::Bold));
    horizontalHeader->setMinimumHeight(40);
    horizontalHeader->setDefaultSectionSize(150);

    this->setColumnWidth(0, 80);
    this->setColumnWidth(this->columnCount()-1, 200);
    setFrameShape(QFrame::NoFrame);

    setStyleSheet(QString("QHeaderView::section, QTableCornerButton::section {padding: 1px;border: none;border-bottom: "
                          "1px solid rgb(160, 160, 160);border-right: 1px solid rgb(160, 160, 160);border-bottom: 1px solid gray;"
                          "background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(164, 164, 164, 255));}"));
    m_isCheckable =  false;//ltj
}

/**
 * @brief OTabelWidget::setCheckable
 * @param ok
 */
void OTabelWidget::setCheckable(bool ok) {

    m_isCheckable = ok;
    int rowCount = this->rowCount();
    if (ok) {
        for (int r = 0; r < rowCount; r ++) {
            QTableWidgetItem *item = this->item(r, 0);
            if (item) {
                QCheckBox *checkBox = new QCheckBox(item->text());
                if (r == 0) {
                    checkBox->setStyleSheet(QString("QCheckBox{ color:yellow; background:darkBlue; font: bold 12pt \"微软雅黑\"; }"));
                } else {
                    checkBox->setStyleSheet(QString("QCheckBox{ color:darkRed; background:lightGray; font: bold 9pt \"微软雅黑\"; }"));
                }
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
                if (r == 0) {
                    item->setFont(QFont("微软雅黑", 12, QFont::Bold));
                    item->setTextColor(Qt::yellow);
                    item->setBackgroundColor(Qt::darkBlue);
                } else {
                    item->setFont(QFont("微软雅黑", 9, QFont::Bold));
                    item->setTextColor(Qt::darkRed);
                    item->setBackground(Qt::lightGray);
                }
                this->removeCellWidget(r, 0);
                this->setItem(r, 0, item);
            }
        }
    }
}

/**
 * @brief OTabelWidget::insert
 * @param data
 */
void OTabelWidget::insert(QStringList data) {

    refresh();
    this->insertRow(0);
    QString itemText = "";
    int dataSize = data.size();
    int columnCount = this->columnCount();
    for (int c = 0; c < columnCount; c ++) {
        if (c > 0 ){
        QTableWidgetItem *itemth = this->horizontalHeaderItem(c);
        if( itemth->text() == "Conc" ) {
            data.replaceInStrings(data.at(c-1), QString::number( data.at(c-1).toDouble(), 'f', 1));
        }
        if( itemth->text().contains("A")) {
            data.replaceInStrings(data.at(c-1), QString::number( data.at(c-1).toDouble(), 'f', 4));
        }
        if( itemth->text().contains("Watch")) {
            data.replaceInStrings(data.at(c-1), QString::number( data.at(c-1).toDouble(), 'f', 4));
        }//ltj
        if (c < dataSize+1) {
            itemText = data.at(c-1);
        }
        }
        if (c == 0) {
            itemText = QString::number( this->rowCount() , 10);
        }
        //qDebug() << itemText;
        QTableWidgetItem *item = new QTableWidgetItem(itemText);
        item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        item->setFont(QFont("微软雅黑", 12, QFont::Bold));
        item->setTextColor(Qt::yellow);
        item->setBackgroundColor(Qt::darkBlue);
        setItem(0, c, item);

    }
}

/**
 * @brief OTabelWidget::isExist
 * @param fileName
 */
bool OTabelWidget::isExist(QString fileName) {
    QList<QTableWidgetItem *> items = this->findItems(fileName, Qt::MatchFixedString);
    if (items.isEmpty()) {
        return false;
    }
    refresh();
    foreach (QTableWidgetItem *item, items) {
        int row = this->row(item);
        for (int c = 0; c < this->columnCount(); c ++) {
            QTableWidgetItem *item = this->item( row, c );
            item->setFont( QFont( "微软雅黑", 12, QFont::Bold ) );
            item->setTextColor( Qt::yellow );
            item->setBackgroundColor( Qt::darkBlue );
        }
    }
    return true;
}

/**
 * @brief OTabelWidget::selectAll
 */
void OTabelWidget::selectAll(bool ok) {

    int rowCount = this->rowCount();
    for (int r = 0; r < rowCount; r ++) {
        QCheckBox *checkBox = static_cast<QCheckBox *>(this->cellWidget(r, 0));
        checkBox->setChecked(ok);
    }
}

/**
 * @brief OTabelWidget::exportSelecedItems
 */
void OTabelWidget::exportSelecedItems() {

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Files (*.csv)"));
    if (fileName.isEmpty()) {
        return;
    }
    //qDebug() << "acesess";

    QList<QString> dataList;
    int rowCount = this->rowCount();//lt:行数
    int columnCount = this->columnCount();//lt:列数
    //qDebug() << QString::number( rowCount, 10 );
    //qDebug() << QString::number( columnCount, 10 );


    for (int r = 0; r < rowCount ; r ++) {
        if (!m_isCheckable) {   //ltg
            QString d;
            QString th;
            if (r == 0) {
                for (int c = 0; c < columnCount; c++ ) {
                    th.append(this->horizontalHeaderItem(c)->text() + ",");
                }
                dataList.append(th);
            }//ltj

            for (int c = 0; c < columnCount; c ++) {
                d.append(this->item(r, c)->text() + ",");
            }
            //qDebug()<< d;//ltj
            dataList.append(d);
        } else {
            QCheckBox *checkBox = static_cast<QCheckBox *>(this->cellWidget(r, 0));
            if (checkBox != NULL) {
                //qDebug() << "acesess1";
                if (checkBox->isChecked()) {
                    //qDebug() << "acesess2";
                    QString d;
                    QString th;
                    if (r == 0) {
                        for (int c = 0; c < columnCount; c++ ) {
                            th.append(this->horizontalHeaderItem(c)->text() + ",");
                        }
                        dataList.append(th);
                    }//ltj

                    d.append(checkBox->text() + ",");
                    for (int c = 1; c < columnCount; c ++) {
                        d.append(this->item(r, c)->text() + ",");
                    }
                    qDebug()<< d;//ltj
                    dataList.append(d);
                }
            }
        }
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly|QIODevice::Truncate)) {
        return;
    }
    QTextStream out(&file);
    out.setCodec("GB2312");
    for (int i = 0; i < dataList.size(); i ++) {
        out << dataList.at(i);
        if (i < dataList.size() - 1) {
            out << "\n";
        }
    }
    file.close();
}

/**
 * @brief OTabelWidget::removeSelecedItems
 */
void OTabelWidget::removeSelecedItems() {
    if (!m_isCheckable) {
        return;
    }
    int rowCount = this->rowCount();
    for (int r = rowCount - 1; r >=0 ; r --) {
        QCheckBox *checkBox = static_cast<QCheckBox *>(this->cellWidget(r, 0));
        if (checkBox->isChecked()) {
            this->removeRow(r);
        }
    }
}

/**
 * @brief OTabelWidget::mousePressEvent
 * @param event
 */
void OTabelWidget::mousePressEvent(QMouseEvent *event) {

    if (event->button() == Qt::LeftButton) {
        m_leftButtonPressed = true;
        m_originalPoint = event->globalPos();
        m_originalPointBackup = m_originalPoint;
    }
    QTableWidget::mousePressEvent(event);
}

/**
 * @brief OTabelWidget::mouseMoveEvent
 * @param event
 */
void OTabelWidget::mouseMoveEvent(QMouseEvent *event) {

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
 * @brief OTabelWidget::mouseReleaseEvent
 * @param event
 */
void OTabelWidget::mouseReleaseEvent(QMouseEvent *event) {

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
 * @brief OTabelWidget::refresh
 */
void OTabelWidget::refresh() {

    int rowCount = this->rowCount();
    int columnCount = this->columnCount();
    for (int r = 0; r < rowCount; r ++) {
        for (int c = 0; c < columnCount; c ++) {
            QTableWidgetItem *item = this->item(r, c);
            item->setFont(QFont("微软雅黑", 9, QFont::Bold));
            item->setTextColor(Qt::darkRed);
            item->setBackground(Qt::lightGray);
        }
    }
}

