#include "odigitkeyboard.h"
#include "ui_odigitkeyboard.h"

#include <QDebug>
#include <QMouseEvent>

ODigitKeyboard::ODigitKeyboard(QWidget *receiver, QWidget *parent) :
    QFrame(parent), ui(new Ui::ODigitKeyboard) {
    ui->setupUi(this);

    m_reveiver = receiver;
    m_isPressed = false;
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint |
                   Qt::FramelessWindowHint | Qt::WindowDoesNotAcceptFocus);

    setFloated(false);
    initializeKey();
    initializeStyleSheet();
}

ODigitKeyboard::~ODigitKeyboard() {
    delete ui;
}

/**
 * @brief ODigitKeyboard::setAutoResize
 * @param isAuto
 */
void ODigitKeyboard::setAutoResize(bool isAuto) {
    m_isAutoResize = isAuto;
    resize();
}

/**
 * @brief ODigitKeyboard::setFloated
 * @param isFloated
 */
void ODigitKeyboard::setFloated(bool isFloated) {
    m_isFloated = isFloated;
    ui->toolButtonEsc->setEnabled( m_isFloated );
    //ui->toolButtonEsc->setText( m_isFloated?"Esc":"" );
}

/**
 * @brief ODigitKeyboard::setKeySize 设置按键大小
 * @param size 按键的尺寸
 */
void ODigitKeyboard::setKeySize(QSize keySize) {

    m_keySize = keySize;
    QList<QToolButton *> keyList = m_keyMapper.keys();
    for (int i = 0; i < keyList.size(); i ++) {
        QToolButton *toolButton = keyList.at( i );
        toolButton->setFixedSize( keySize );
    }
    ui->toolButtonEsc->setFixedSize( keySize );
    initializeStyleSheet();
}

/**
 * @brief ODigitKeyboard::setKeyRadius 设置按键边框半径
 * @param radius 半径值
 */
void ODigitKeyboard::setKeyRadius(int radius) {
    m_keyRadius = radius;
    refresh();
}

/**
 * @brief ODigitKeyboard::setKeyFont 设置按键字体
 * @param font 字体, 如“"20pt \"黑体\""”
 */
void ODigitKeyboard::setKeyFont(QString font) {
    m_keyFont = font;
    refresh();
}

/**
 * @brief ODigitKeyboard::setKeyColor 设置按键字体颜色
 * @param color 字体颜色
 */
void ODigitKeyboard::setKeyColor(QString color) {
    m_keyColor = color;
    refresh();
}

/**
 * @brief ODigitKeyboard::setKeyBackground 设置按键北京颜色
 * @param data 共四个颜色,分别是背景色\悬浮色\按下色\不使能色
 */
void ODigitKeyboard::setKeyBackground(QStringList data) {
    for (int i = 0; i < data.size(); i ++) {
        switch (i) {
        case 0:
            m_keyBackground_enabled = data.at(i);
            break;
        case 1:
            m_keyBackground_hover = data.at(i);
            break;
        case 2:
            m_keyBackground_pressed = data.at(i);
            break;
        case 3:
            m_keyBackground_disabled = data.at(i);
            break;
        }
    }
    refresh();
}

/**
 * @brief ODigitKeyboard::setBorderRadius 设置键盘边框半径
 * @param radius 半径值
 */
void ODigitKeyboard::setBorderRadius(int radius) {
    m_borderRadius = radius;
    refresh();
}

/**
 * @brief ODigitKeyboard::setBorder 设置键盘边框
 * @param border 边框, 如“0px groove white”
 */
void ODigitKeyboard::setBorder(QString border) {
    m_border = border;
    refresh();
}

/**
 * @brief ODigitKeyboard::setBorderBackground 设置键盘背景色
 * @param background 背景色
 */
void ODigitKeyboard::setBorderBackground(QString background) {
    m_borderBackground = background;
    refresh();
}

/**
 * @brief ODigitKeyboard::showEvent
 * @param e
 */
void ODigitKeyboard::showEvent(QShowEvent */*e*/) {

    resize();
}

/**
 * @brief ODigitKeyboard::onKeyPressed
 */
void ODigitKeyboard::onKeyPressed() {

    QObject *r = (QObject *)m_reveiver->focusWidget();
    if (r) {
        QToolButton *toolButton = (QToolButton *)sender();
        if (!m_keyMapper.contains( toolButton )) {
            return;
        }
        Qt::Key keyValue = m_keyMapper.value( toolButton );
        QKeyEvent keyPress(QEvent::KeyPress, quint32( keyValue ), Qt::NoModifier, QString( quint32( keyValue ) ));
        QApplication::sendEvent(r, &keyPress);
        QKeyEvent keyRelease(QEvent::KeyRelease, quint32( keyValue ), Qt::NoModifier, QString());
        QApplication::sendEvent(r, &keyRelease);
    }
}

/**
 * @brief ODigitKeyboard::mouseMoveEvent
 * @param e
 */
void ODigitKeyboard::mouseMoveEvent(QMouseEvent *e) {

    if (e->buttons() == Qt::LeftButton && m_isPressed) {
        move(e->globalPos() - m_dragOrigin);
        e->accept();
    }
}

/**
 * @brief ODigitKeyboard::mousePressEvent
 * @param e
 */
void ODigitKeyboard::mousePressEvent(QMouseEvent *e) {

    if (e->button() == Qt::LeftButton && m_isFloated) {
        m_dragOrigin = e->globalPos() - frameGeometry().topLeft();
        m_isPressed = true;
        e->accept();
    }
}

/**
 * @brief ODigitKeyboard::mouseReleaseEvent
 * @param e
 */
void ODigitKeyboard::mouseReleaseEvent(QMouseEvent *e) {

    m_isPressed = false;
    QWidget::mousePressEvent( e );
}

/**
 * @brief ODigitKeyboard::resize 重新设置键盘大小
 */
void ODigitKeyboard::resize() {

    if (m_isAutoResize) {
        int length = (width() > height() ? height():width())/4;
        setKeySize( QSize(length, length) );
    }
    int left = 0, top = 0, right = 0, bottom = 0;
    ui->verticalLayoutBorder->getContentsMargins(&left, &top, &right, &bottom);
    ui->frameBorder->setFixedSize( QSize(m_keySize.width()*4+left+right, m_keySize.height()*4+top+right) );
}

/**
 * @brief ODigitKeyboard::refresh 重新设置键盘配色
 */
void ODigitKeyboard::refresh() {

    QString keyQss = m_keyStyleSheet.arg(m_keyRadius).arg(m_keyFont).arg(m_keyColor).
            arg(m_keyBackground_enabled).arg(m_keyBackground_hover).arg(m_keyBackground_pressed).arg(m_keyBackground_disabled);

    QString borderQss = m_borderStyleSheet.arg(m_border).arg(m_borderRadius).arg(m_borderBackground);
    setStyleSheet( keyQss + borderQss );
}

/**
 * @brief ODigitKeyboard::initializeKey
 */
void ODigitKeyboard::initializeKey() {

    m_keyMapper.insert(ui->toolButton0, Qt::Key_0);
    m_keyMapper.insert(ui->toolButton1, Qt::Key_1);
    m_keyMapper.insert(ui->toolButton2, Qt::Key_2);
    m_keyMapper.insert(ui->toolButton3, Qt::Key_3);
    m_keyMapper.insert(ui->toolButton4, Qt::Key_4);
    m_keyMapper.insert(ui->toolButton5, Qt::Key_5);
    m_keyMapper.insert(ui->toolButton6, Qt::Key_6);
    m_keyMapper.insert(ui->toolButton7, Qt::Key_7);
    m_keyMapper.insert(ui->toolButton8, Qt::Key_8);
    m_keyMapper.insert(ui->toolButton9, Qt::Key_9);

    m_keyMapper.insert(ui->toolButtonLeft, Qt::Key_Left);
    m_keyMapper.insert(ui->toolButtonRight, Qt::Key_Right);
    m_keyMapper.insert(ui->toolButtonDelete, Qt::Key_Backspace);
    m_keyMapper.insert(ui->toolButtonMinus, Qt::Key_Minus);
    m_keyMapper.insert(ui->toolButtonPeriod, Qt::Key_Period);

    m_keySize = QSize(64, 64);
    setKeySize( m_keySize );

    QList<QToolButton *> keyList = m_keyMapper.keys();
    for (int i = 0; i < keyList.size(); i ++) {
        QToolButton *toolButton = keyList.at( i );
        connect(toolButton, SIGNAL(clicked(bool)), this, SLOT(onKeyPressed()));
    }

    connect(ui->toolButtonEsc, SIGNAL(clicked(bool)), this, SLOT(hide()));

    setFloated( false );
    setAutoResize( false );
}

/**
 * @brief ODigitKeyboard::initializeStyleSheet
 */
void ODigitKeyboard::initializeStyleSheet() {

    m_keyRadius = m_keySize.height()/2;
    m_keyFont = "20pt \"黑体\"";
    m_keyColor = "white";
    m_keyBackground_enabled = "qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #5B5F5F, stop: 0.5 #0C2436, stop: 1.0 #27405A )";
    m_keyBackground_hover = "qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #758385, stop: 0.5 #122C39, stop: 1.0 #0E7788 )";
    m_keyBackground_pressed = "qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #969B9C, stop: 0.5 #16354B, stop: 1.0 #244F76 )";
    m_keyBackground_disabled = "qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #282B2C, stop: 0.5 #09121A, stop: 1.0 #111D29)";

    m_keyStyleSheet = QString( "QToolButton {"
                                "border:0px groove white;"
                                "border-radius:%1px;"
                                "font:%2;"
                                "color:%3;"
                                "background:%4;"
                                "}"
                                "QToolButton::hover{"
                                    "background:%5;"
                                "}"
                                "QToolButton::pressed{"
                                    "background:%6;"
                                "}"
                                "QToolButton::disabled{"
                                    "background:%7;"
                                    "color:#6A6864;"
                                "}"
                              );


    m_borderRadius = 0;
    m_border = "0px groove white";
    m_borderBackground = "transparent";
    m_borderStyleSheet = QString( "QFrame#ODigitKeyboard {"
                                      "background:transparent;"
                                  "}"
                                  "QFrame#frameBorder {"
                                      "border:%1;"
                                      "border-radius:%2px;"
                                      "background-color:%3;"
                                  "}"
                                  );


    refresh();
}
