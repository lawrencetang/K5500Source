#include "otableview.h"
#include "ui_otableview.h"

#include <QHeaderView>
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

OTableView::OTableView(QStringList headerLabels, QList<QStringList> infos, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OTableView) {
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(headerLabels.size());
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);

    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    m_isPressed = false;
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    QHeaderView *verticalHeader = ui->tableWidget->verticalHeader();
    verticalHeader->setSectionsClickable(false);
    verticalHeader->setFont(QFont("微软雅黑", 10));
    verticalHeader->setDefaultSectionSize(40);

    QHeaderView *horizontalHeader = ui->tableWidget->horizontalHeader();
    horizontalHeader->setStretchLastSection(true);
    horizontalHeader->resizeSections(QHeaderView::Stretch);
    horizontalHeader->setSectionsClickable(false);
    horizontalHeader->setFont(QFont("微软雅黑", 10, QFont::Bold));
    horizontalHeader->setMinimumHeight(40);
    horizontalHeader->resizeSections(QHeaderView::Stretch);
    connect(ui->toolButtonClose, SIGNAL(clicked(bool)), this, SLOT(close()));


    foreach(QStringList data, infos) {

        int row = ui->tableWidget->rowCount();
        int column = ui->tableWidget->columnCount();
        ui->tableWidget->insertRow( row );
        int size = data.size();
        for (int c = 0; c < column; c ++) {
            if (c < size) {
                QTableWidgetItem *item = new QTableWidgetItem(data.at(c));
                item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
                item->setFont(QFont("微软雅黑", 9, QFont::Bold));
                ui->tableWidget->setItem(row, c, item);
            }
        }
    }

    setStyleSheet(QString("QHeaderView::section, QTableCornerButton::section {padding: 1px;border: none;border-bottom: "
                          "1px solid rgb(160, 160, 160);border-right: 1px solid rgb(160, 160, 160);border-bottom: 1px solid gray;"
                          "background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(164, 164, 164, 255));}"));

}

OTableView::~OTableView() {
    delete ui;
}

/**
 * @brief OTableView::setTitle
 * @param title
 */
void OTableView::setTitle(QString title) {
    ui->labelTitle->setText(title);
}

/**
 * @brief OTableView::showEvent
 */
void OTableView::showEvent(QShowEvent */*e*/) {
    QHeaderView *horizontalHeader = ui->tableWidget->horizontalHeader();
    horizontalHeader->resizeSections(QHeaderView::Stretch);
    horizontalHeader->setStretchLastSection(true);
    showAnimation();
}

/**
 * @brief OTableView::closeEvent
 */
void OTableView::closeEvent(QCloseEvent */*e*/) {
    done(-1);
}

/**
 * @brief OTableView::mousePressEvent
 * @param e
 */
void OTableView::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::LeftButton && !m_isPressed) {
        m_dragOrigin = e->globalPos() - frameGeometry().topLeft();
        m_isPressed = true;
        e->accept();
    }
}

/**
 * @brief OTableView::mouseReleaseEvent
 * @param e
 */
void OTableView::mouseReleaseEvent(QMouseEvent *e) {
    m_isPressed = false;
    QWidget::mousePressEvent( e );
}

/**
 * @brief OTableView::mouseMoveEvent
 * @param e
 */
void OTableView::mouseMoveEvent(QMouseEvent *e) {
    if (e->buttons() == Qt::LeftButton && m_isPressed) {
        move(e->globalPos() - m_dragOrigin);
        e->accept();
    }
}

/**
 * @brief OTableView::showAnimation
 */
void OTableView::showAnimation() {

    QPropertyAnimation *a1 = new QPropertyAnimation( this, "windowOpacity" );
    a1->setDuration( 800 );
    a1->setStartValue( 0 );
    a1->setEndValue( 1 );

    QRect rect = geometry();
    QDesktopWidget *desktopWidget = QApplication::desktop();
    QRect r = QRect(desktopWidget->geometry().center() - QPoint(rect.width(), rect.height())/2, rect.size() );

    QPropertyAnimation *a2 = new QPropertyAnimation( this, "geometry" );
    a2->setDuration( 1000 );
    a2->setStartValue( QRect(r.bottomRight(), QSize(0, 0)) );
    a2->setEndValue( r );
    a2->setEasingCurve(QEasingCurve::OutCubic);

    QParallelAnimationGroup *g = new QParallelAnimationGroup();
    g->addAnimation( a1 );
    g->addAnimation( a2 );
    g->start();
}

