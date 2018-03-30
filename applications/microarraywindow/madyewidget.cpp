#include "madyewidget.h"
#include "ui_madyewidget.h"

#include "omessageboxutil.h"
#include "madyetablewidget.h"

#include <QDebug>
#include <QCheckBox>
#include <QPropertyAnimation>

MADyeWidget::MADyeWidget(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MADyeWidget) {
    ui->setupUi(this);

    m_isAnimation = true;
    QStringList labels;
    labels << tr("Dye Name") << tr("Wave Length") << tr("1/M*cm") << tr("260m%") << tr("280m%");
    m_dyeList << ui->lineEditDyeName << ui->spinBoxWaveLength << ui->doubleSpinBoxMcm
              << ui->doubleSpinBox260 << ui->doubleSpinBox280;
    m_pTableWidget = new MADyeTableWidget(labels, this);

    layout = new QHBoxLayout();
    layout->addWidget(m_pTableWidget);
    layout->setMargin(0);
    ui->frameTable_l->setLayout(layout);

    connect(ui->toolButtonAdd, SIGNAL(clicked(bool)), this, SLOT(showAddPage()));
    connect(ui->toolButtonRemove, SIGNAL(clicked(bool)), this, SLOT(showRemovePage()));
    connect(ui->radioButtonCheckAll_l, SIGNAL(clicked(bool)), this, SLOT(checkAll(bool)));
    connect(ui->radioButtonCheckAll_r, SIGNAL(clicked(bool)), this, SLOT(checkAll(bool)));

    connect(ui->toolButtonCancel_a, SIGNAL(clicked(bool)), this, SLOT(showListPage()));
    connect(ui->toolButtonCancel_r, SIGNAL(clicked(bool)), this, SLOT(showListPage()));
    connect(ui->toolButtonOk_a, SIGNAL(clicked(bool)), this, SLOT(showListPage()));
    connect(ui->toolButtonOk_r, SIGNAL(clicked(bool)), this, SLOT(showListPage()));
}

MADyeWidget::~MADyeWidget() {
    delete ui;
}

/**
 * @brief MADyeWidget::getDyes
 * @return
 */
QList<QStringList> MADyeWidget::getSelectedDyes() {

    QList<QStringList> result;
    int rowCount = m_pTableWidget->rowCount();
    for(int r = 0; r < rowCount; r ++) {
        QCheckBox *checkBox = static_cast<QCheckBox *>(m_pTableWidget->cellWidget(r, 0));
        if(checkBox->isChecked()) {
            QStringList dyeData;
            dyeData << checkBox->text();
            int columnCount = m_pTableWidget->columnCount();
            for(int c = 1; c < columnCount; c ++) {
                dyeData << m_pTableWidget->item(r, c)->text();
            }
            result.append(dyeData);
        }
    }
    return result;
}

/**
 * @brief MADyeWidget::showAddPage
 */
void MADyeWidget::showAddPage() {
    ui->stackedWidget->setCurrentWidget(ui->pageAdd);
    flipOverAnimation(ui->pageAdd);
    emit headerDisabled(false);
}

/**
 * @brief MADyeWidget::showListPage
 */
void MADyeWidget::showListPage() {

    if(sender() == ui->toolButtonOk_r) {
        m_pTableWidget->remove();
    }else if(sender() == ui->toolButtonOk_a) {
        if(ui->lineEditDyeName->text().isEmpty()) {
            OMessageBoxUtil::staticNotice(0, tr( "Dye name can not be empty!" ), QStringList() << tr( "OK" ), 10);
            return;
        }
        QStringList dyes;
        foreach(QWidget *w, m_dyeList) {
            if (w->inherits( "QLineEdit" )) {
                QLineEdit *lineEdit = static_cast<QLineEdit *>(w);
                dyes.append(lineEdit->text());
            } else if (w->inherits( "QSpinBox" )) {
                QSpinBox *spinBox = static_cast<QSpinBox *>(w);
                dyes.append(QString::number( spinBox->value() ));
            } else if (w->inherits( "QDoubleSpinBox" )) {
                QDoubleSpinBox *spinBox = static_cast<QDoubleSpinBox *>(w);
                dyes.append(QString::number( spinBox->value() ));
            }
        }
        m_pTableWidget->append(dyes);
    }
    ui->frameTable_l->setLayout(layout);
    ui->stackedWidget->setCurrentWidget(ui->pageList);
    flipOverAnimation(ui->pageList);

    ui->radioButtonCheckAll_r->setChecked(false);
    checkAll(ui->radioButtonCheckAll_l->isChecked());
    emit headerDisabled(true);
}

/**
 * @brief MADyeWidget::showRemovePage
 */
void MADyeWidget::showRemovePage() {
    ui->frameTable_r->setLayout(layout);
    ui->stackedWidget->setCurrentWidget(ui->pageRemove);
    flipOverAnimation(ui->pageRemove);
    checkAll(ui->radioButtonCheckAll_r->isChecked());
    emit headerDisabled(false);
}

/**
 * @brief MADyeWidget::checkAll
 * @param ok
 */
void MADyeWidget::checkAll(bool ok) {
    int rowCount = m_pTableWidget->rowCount();
    for(int r = 0; r < rowCount; r ++) {
        QRadioButton *radioButton = static_cast<QRadioButton *>( m_pTableWidget->cellWidget(r, 0) );
        radioButton->setChecked(ok);
    }
}

/**
 * @brief MADyeWidget::flipOverAnimation
 * @param w
 */
void MADyeWidget::flipOverAnimation(QWidget *w) {

    if (m_isAnimation) {
        QPropertyAnimation *a = new QPropertyAnimation( w, "geometry" );
        QRect rect = w->geometry();
        a->setDuration( 1000 );
        a->setStartValue( QRect( rect.topLeft(), QSize( rect.width(), 0 ) ) );
        a->setEndValue( rect );
        a->setEasingCurve(QEasingCurve::OutCubic);
        a->start();
    }
}
