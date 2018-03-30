#include "omessagebox.h"
#include "ui_omessagebox.h"

#include <QDebug>
#include <QTimer>
#include <QMovie>
#include <QPushButton>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

OMessageBox::OMessageBox(int timeout, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OMessageBox) {
    ui->setupUi(this);

    m_btn = NULL;
    m_isShown = false;
    m_timeout = timeout;
    ui->toolButtonClose->setVisible((m_timeout == 0));

    m_isPressed = false;
    m_pRefreshTimer = new QTimer();
    connect(m_pRefreshTimer, SIGNAL(timeout()), this, SLOT(refresh()));
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setModal(true);

    initializeStyleSheet();
    connect(ui->buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(onBtnClicked(QAbstractButton*)));
    connect(ui->toolButtonClose, SIGNAL(clicked(bool)), this, SLOT(close()));

}

OMessageBox::~OMessageBox() {
    delete ui;
}

/**
 * @brief OMessageBox::title
 * @return
 */
QString OMessageBox::title() {
    return ui->labelTitle->text();
}

/**
 * @brief OMessageBox::setTitle
 * @param title
 */
void OMessageBox::setTitle(QString title) {
    ui->labelTitle->setText( title );
}

/**
 * @brief OMessageBox::titleIcon
 * @return
 */
QIcon OMessageBox::titleIcon() {

    const QPixmap *pixmap = ui->labelTitleImage->pixmap();
    return QIcon(*pixmap);
}

/**
 * @brief OMessageBox::setTitleIcon
 * @param icon
 */
void OMessageBox::setTitleIcon(QIcon icon) {
    QSize size = ui->labelTitleImage->size();
    ui->labelTitleImage->setPixmap( icon.pixmap( size ) );
}

/**
 * @brief OMessageBox::text
 * @return
 */
QString OMessageBox::text() {
    return ui->labelText->text();
}

/**
 * @brief OMessageBox::setText
 * @param text
 */
void OMessageBox::setText(QString text) {

    ui->labelText->setText(text);
}

/**
 * @brief OMessageBox::textIcon
 * @return
 */
QIcon OMessageBox::textIcon() {

    const QPixmap *pixmap = ui->labelImage->pixmap();
    return QIcon(*pixmap);
}

/**
 * @brief OMessageBox::setTextIcon
 * @param icon
 */
void OMessageBox::setTextIcon(QIcon icon) {

    QSize size = ui->labelTitleImage->size();
    ui->labelImage->setPixmap( icon.pixmap( size ) );
}

/**
 * @brief OMessageBox::gifEnable
 */
void OMessageBox::gifEnable() {
    QMovie *movie = new QMovie( ":/images/detail.gif" );
    ui->labelImage->setMovie(movie);
    movie->start();
}

/**
 * @brief OMessageBox::addButton
 * @param labels
 */
void OMessageBox::addButtons(QStringList labels) {

    if (labels.isEmpty()) {
        return;
    }

    m_text = labels.first();
    for (int i = 0; i < labels.size(); i ++) {
        QPushButton *btn = new QPushButton( labels.at( i ) );
        if (m_timeout != 0 && i == 0) {
            QString text = QString( "%1(%2)" ).arg( m_text ).arg( m_timeout );
            btn->setText(text);
        }
        btn->setMinimumSize(120, 40);
        ui->buttonBox->addButton( btn, QDialogButtonBox::NoRole );
    }
}

/**
 * @brief OMessageBox::setClosable
 * @param ok
 */
void OMessageBox::setClosable(bool ok) {
    ui->toolButtonClose->setVisible( ok );
}

/**
 * @brief OMessageBox::quit
 */
void OMessageBox::quit() {

    done( ui->buttonBox->buttons().indexOf( m_btn ) );
    m_btn = NULL;
}

/**
 * @brief OMessageBox::refresh
 */
void OMessageBox::refresh() {

    m_timeout --;
    QList<QAbstractButton *> btnList = ui->buttonBox->buttons();
    if (m_timeout == 0) {
        m_pRefreshTimer->stop();
        if (btnList.isEmpty()) {
            m_btn = NULL;
        } else {
            m_btn = btnList.first();
        }
        closeAnimation();
        return;
    }

    if (btnList.isEmpty()) {
        if (m_text.isEmpty()) {
            m_text = ui->labelText->text();
        } else {
            QString text = QString( "%1(%2s)" ).arg(m_text).arg(m_timeout);
            ui->labelText->setText( text );
        }
    } else {
        QString text = QString( "%1(%2s)" ).arg(m_text).arg(m_timeout);
        QAbstractButton *btn = btnList.first();
        btn->setText( text );
    }
}

/**
 * @brief OMessageBox::onFinished
 */
void OMessageBox::onFinished() {
    m_isShown = true;
}

/**
 * @brief OMessageBox::onBtnClicked
 * @param btn
 */
void OMessageBox::onBtnClicked(QAbstractButton *btn) {

    m_btn = btn;
    closeAnimation();
}

/**
 * @brief OMessageBox::showEvent
 */
void OMessageBox::showEvent(QShowEvent */*e*/) {

    if (m_timeout != 0) {
        if (m_pRefreshTimer != NULL) {
            m_pRefreshTimer->start(1000);
        }
    }
    showAnimation();
}

/**
 * @brief OMessageBox::closeEvent
 */
void OMessageBox::closeEvent(QCloseEvent */*e*/) {

    m_btn = NULL;
    m_isShown = false;
    done(-1);
}

/**
 * @brief OMessageBox::mousePressEvent
 * @param e
 */
void OMessageBox::mousePressEvent(QMouseEvent *e) {

    if (e->button() == Qt::LeftButton && !m_isPressed) {
        m_dragOrigin = e->globalPos() - frameGeometry().topLeft();
        m_isPressed = true;
        e->accept();
    }
}

/**
 * @brief OMessageBox::mouseReleaseEvent
 * @param e
 */
void OMessageBox::mouseReleaseEvent(QMouseEvent *e) {

    m_isPressed = false;
    QWidget::mousePressEvent( e );
}

/**
 * @brief OMessageBox::mouseMoveEvent
 * @param e
 */
void OMessageBox::mouseMoveEvent(QMouseEvent *e) {

    if (e->buttons() == Qt::LeftButton && m_isPressed) {
        move(e->globalPos() - m_dragOrigin);
        e->accept();
    }
}

/**
 * @brief OMessageBox::showAnimation
 */
void OMessageBox::showAnimation() {

    QPropertyAnimation *a1 = new QPropertyAnimation( this, "windowOpacity" );
    a1->setDuration( 800 );
    a1->setStartValue( 0 );
    a1->setEndValue( 1 );

    QRect rect = geometry();
    QPropertyAnimation *a2 = new QPropertyAnimation( this, "geometry" );
    a2->setDuration( 1000 );
    a2->setStartValue( QRect(rect.center(), QSize(0, 0)) );
    a2->setEndValue( rect );
    a2->setEasingCurve(QEasingCurve::OutCubic);

    QParallelAnimationGroup *g = new QParallelAnimationGroup();
    g->addAnimation( a1 );
    g->addAnimation( a2 );
    g->start();

    connect(g, SIGNAL(finished()), this, SLOT(onFinished()));
}

/**
 * @brief OMessageBox::closeAnimation
 */
void OMessageBox::closeAnimation() {

    QPropertyAnimation *a1 = new QPropertyAnimation( this, "windowOpacity" );
    QRect rect = geometry();
    a1->setDuration( 800 );
    a1->setStartValue( 1 );
    a1->setEndValue( 0.0 );

    QPropertyAnimation *a2 = new QPropertyAnimation( this, "geometry" );
    a2->setDuration( 1000 );
    a2->setStartValue( rect );
    a2->setEndValue( QRect(rect.center(), QSize(0, 0)) );
    a2->setEasingCurve(QEasingCurve::OutCubic);

    QParallelAnimationGroup *g = new QParallelAnimationGroup();
    g->addAnimation( a1 );
    g->addAnimation( a2 );
    g->start();

    connect(g, SIGNAL(finished()), this, SLOT(quit()));
}

/**
 * @brief OMessageBox::initializeStyleSheet
 */
void OMessageBox::initializeStyleSheet() {

    QString styleSheet = QString( "QDialog { "
                                      "background-color:white;"
                                  "}"
                                  "QLabel#labelTitle {"
                                      "color:white;"
                                      "font: 16pt \"微软雅黑\";"
                                      "background:transparent;"
                                  "}"
                                  "QLabel#labelText {"
                                      "color:blue;"
                                      "font: 12pt \"微软雅黑\";"
                                      "background:transparent;"
                                  "}"
                                  "QFrame#frameTitle{"
                                      "background-color:blue;"
                                  "}"
                                  "QFrame#frameText{"
                                      "border: 1px solid blue;"
                                      "border-left: 0px solid white;"
                                      "border-top: 0px solid white;"
                                      "border-right: 0px solid white;"
                                  "}"
                                  "QFrame#frameBtnBox{"
                                      "background-color:lightgray;"
                                  "}"
                                  "QToolButton {"
                                      "background: transparent;"
                                  "}"
                                  "QPushButton {"
                                      "color: blue;"
                                      "font: 12pt \"微软雅黑\";"
                                      "border: 1px solid blue;"
                                  "}"
                                  "QPushButton::checked{"
                                      "color:blue;"
                                      "background-color: rgb(255, 255, 255);"
                                  "}"
                                  "QPushButton::hover {"
                                      "background-color: rgba(0, 0, 255, 120);"
                                  "}"
                                  "QPushButton::disabled{"
                                      "color:gray;"
                                      "border: 1px solid gray;"
                                      "background-color: rgba(25, 25, 25, 200);"
                                  "}"
                                  "QPushButton::pressed{"
                                      "padding-top:3px;"
                                      "padding-left:3px;"
                                  "}"
                                  );
    setStyleSheet(styleSheet);
}
