#include "orecordtablewidget.h"
#include "ui_orecordtablewidget.h"

#include <QDebug>
#include <QModelIndex>
#include <QPropertyAnimation>
#include "otabelwidget.h"

ORecordTableWidget::ORecordTableWidget(QStringList headerLabels, QString title, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ORecordTableWidget) {
    ui->setupUi(this);

    setTitle(title);
    m_isAnimation = true;
    m_pTableWidget = new OTabelWidget(headerLabels);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(m_pTableWidget);
    layout->setMargin(0);
    ui->frameTable->setLayout(layout);

    ui->toolButtonRemove->setEnabled(m_pTableWidget->rowCount() != 0);
    ui->toolButtonExport->setEnabled(m_pTableWidget->rowCount() != 0);

    connect(m_pTableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onItemDoubleClicked(QModelIndex)));

    connect(ui->checkBoxSelectAll, SIGNAL(clicked(bool)), m_pTableWidget, SLOT(selectAll(bool)));
    connect(ui->toolButtonExport, SIGNAL(clicked(bool)), m_pTableWidget, SLOT(exportSelecedItems()));

    connect(ui->toolButtonRemove, SIGNAL(clicked(bool)), this, SLOT(toOptionView()));
    connect(ui->toolButtonCanel, SIGNAL(clicked(bool)), this, SLOT(toMainView()));
    connect(ui->toolButtonOk, SIGNAL(clicked(bool)), this, SLOT(toMainView()));
}

ORecordTableWidget::~ORecordTableWidget() {
    delete ui;
}

/**
 * @brief ORecordTableWidget::setTitle
 * @param title
 */
void ORecordTableWidget::setTitle(QString title) {
    ui->labelTitle->setText(title);
}

/**
 * @brief ORecordTableWidget::insert
 * @param data
 */
void ORecordTableWidget::insert(QStringList data) {

    if (!data.isEmpty()) {
        if (m_pTableWidget->isExist(data.last())) {
            return;
        }
    }

    m_pTableWidget->insert(data);
    ui->toolButtonRemove->setEnabled(m_pTableWidget->rowCount() != 0);
    ui->toolButtonExport->setEnabled(m_pTableWidget->rowCount() != 0);
}

/**
 * @brief ORecordTableWidget::setHorizontalHeaderStretchLastSection
 * @param ok
 */
void ORecordTableWidget::setHorizontalHeaderStretchLastSection(bool ok) {
    m_pTableWidget->horizontalHeader()->setStretchLastSection(ok);
}

/**
 * @brief ORecordTableWidget::setVerticalHeaderStretchLastSection
 * @param ok
 */
void ORecordTableWidget::setVerticalHeaderStretchLastSection(bool ok) {
    m_pTableWidget->verticalHeader()->setStretchLastSection(ok);
}

/**
 * @brief ORecordTableWidget::mouseDoubleClickEvent
 * @param event
 */
void ORecordTableWidget::mouseDoubleClickEvent(QMouseEvent *event) {
    emit doubleClicked();
    QFrame::mouseDoubleClickEvent(event);
}

/**
 * @brief ORecordTableWidget::toMainView
 */
void ORecordTableWidget::toMainView() {
    ui->stackedWidget->setCurrentWidget(ui->pageMain);
    if (sender() == ui->toolButtonOk) {
        m_pTableWidget->removeSelecedItems();
    }

    ui->toolButtonRemove->setEnabled(m_pTableWidget->rowCount() != 0);
    ui->toolButtonExport->setEnabled(m_pTableWidget->rowCount() != 0);

    ui->checkBoxSelectAll->setChecked(false);
    m_pTableWidget->setCheckable(false);
    flipOverAnimation(ui->pageMain);
}

/**
 * @brief ORecordTableWidget::toOptionView
 */
void ORecordTableWidget::toOptionView() {
    ui->stackedWidget->setCurrentWidget(ui->pageOption);
    m_pTableWidget->setCheckable(true);
    flipOverAnimation(ui->pageOption);
}

/**
 * @brief ORecordTableWidget::onItemDoubleClicked
 * @param index
 */
void ORecordTableWidget::onItemDoubleClicked(const QModelIndex &index) {
    int row = index.row();
    int columnCount = m_pTableWidget->columnCount();
    QTableWidgetItem *item = m_pTableWidget->item(row, columnCount - 1);
    if (NULL != item) {
        QString fileName = item->text();
        emit showItemDetail(fileName);
    }
}

/**
 * @brief ExcuteView::flipOverAnimation
 * @param w
 */
void ORecordTableWidget::flipOverAnimation(QWidget *w) {

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
