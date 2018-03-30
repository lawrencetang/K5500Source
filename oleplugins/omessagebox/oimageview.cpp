#include "oimageview.h"
#include "ui_oimageview.h"

#include <QDebug>
#include <QMouseEvent>
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

OImageView::OImageView(QString title, QPixmap pixmap, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OImageView) {
    ui->setupUi(this);

    m_isPressed = false;
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);

    ui->labelImage->resize( pixmap.size() );
    ui->labelTitle->setText( title );
    ui->labelImage->setPixmap( pixmap );
    connect(ui->toolButtonClose, SIGNAL(clicked(bool)), this, SLOT(close()));
}

OImageView::~OImageView() {
    delete ui;
}

void OImageView::showEvent(QShowEvent */*e*/) {
    showAnimation();
}

void OImageView::closeEvent(QCloseEvent */*e*/) {
    done(-1);
}

void OImageView::mousePressEvent(QMouseEvent *e) {
    if (e->button() == Qt::LeftButton && !m_isPressed) {
        m_dragOrigin = e->globalPos() - frameGeometry().topLeft();
        m_isPressed = true;
        e->accept();
    }
}

void OImageView::mouseReleaseEvent(QMouseEvent *e) {
    m_isPressed = false;
    QWidget::mousePressEvent( e );
}

void OImageView::mouseMoveEvent(QMouseEvent *e) {
    if (e->buttons() == Qt::LeftButton && m_isPressed) {
        move(e->globalPos() - m_dragOrigin);
        e->accept();
    }
}

void OImageView::showAnimation() {
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
