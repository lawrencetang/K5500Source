#include "ofullkeyboard.h"
#include "ui_ofullkeyboard.h"

#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QMouseEvent>

OFullKeyboard::OFullKeyboard(QWidget *receiver, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OFullKeyboard) {
    ui->setupUi(this);

    m_receiver = receiver;
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint |
                   Qt::FramelessWindowHint | Qt::WindowDoesNotAcceptFocus);

    initializeKey();
    loadFontLibrary();
    initializeStyleSheet();

    m_keySize = QSize(80, 80);
    setKeySize( m_keySize );

    setFloated( false );
    setAutoResize( false );

}

OFullKeyboard::~OFullKeyboard() {
    delete ui;
}

/**
 * @brief OFullKeyboard::setAutoResize
 * @param isAuto
 */
void OFullKeyboard::setAutoResize(bool isAuto) {
    m_isAutoResize = isAuto;
    resize();
}

/**
 * @brief OFullKeyboard::setFloated
 * @param isFloated
 */
void OFullKeyboard::setFloated(bool isFloated) {
    m_isFloated = isFloated;
    ui->pushButtonClose->setEnabled( m_isFloated );
    ui->pushButtonClose->setText(isFloated?"Close":"");
}

/**
 * @brief OFullKeyboard::setKeySize
 * @param keySize
 */
void OFullKeyboard::setKeySize(QSize keySize) {

    int width = keySize.width();
    int height = keySize.height();
    m_keySize = keySize;
    QList<QToolButton *> keyList = m_keyMapper.keys();
    for (int i = 0; i < keyList.size(); i ++) {
        QToolButton *toolButton = keyList.at( i );
        if (toolButton == ui->toolButtonSpace) {
            toolButton->setFixedSize( QSize( 4*width, height ) );
        } else if (toolButton == ui->toolButtonDelete) {
            toolButton->setFixedSize( QSize( 2*width, height ) );
        } else if (toolButton == ui->toolButtonEnter) {
            toolButton->setFixedSize( QSize( 2*width, height ) );
        } else {
            toolButton->setFixedSize( keySize );
        }
    }

    ui->toolButtonLeft->setFixedSize( keySize );
    ui->toolButtonRight->setFixedSize( keySize );

    ui->toolButtonCh_En->setFixedSize( QSize( 2*width, height ) );
    ui->toolButtonCap->setFixedSize( QSize( 2*width, height ) );

    ui->frameHeader->setFixedSize( QSize((m_digitKeyList.size() + 2)*width, height) );
    ui->horizontalLayoutHeader->setContentsMargins(m_headerRadius, 0, m_headerRadius, 0);

    initializeStyleSheet();
}

/**
 * @brief OFullKeyboard::setKeyRadius
 * @param radius
 */
void OFullKeyboard::setKeyRadius(int radius) {
    m_keyRadius = radius;
    refresh();
}

/**
 * @brief OFullKeyboard::setKeyFont
 * @param font
 */
void OFullKeyboard::setKeyFont(QString font) {
    m_keyFont = font;
    refresh();
}

/**
 * @brief OFullKeyboard::setKeyColor
 * @param color
 */
void OFullKeyboard::setKeyColor(QString color) {
    m_keyColor = color;
    refresh();
}

/**
 * @brief OFullKeyboard::setKeyBackground
 * @param data
 */
void OFullKeyboard::setKeyBackground(QStringList data){
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
 * @brief OFullKeyboard::setBorderRadius
 * @param radius
 */
void OFullKeyboard::setBorderRadius(int radius) {
    m_borderRadius = radius;
    refresh();
}

/**
 * @brief OFullKeyboard::setBorder
 * @param border
 */
void OFullKeyboard::setBorder(QString border) {
    m_border = border;
    refresh();
}

/**
 * @brief OFullKeyboard::setBorderBackground
 * @param background
 */
void OFullKeyboard::setBorderBackground(QString background) {
    m_borderBackground = background;
    refresh();
}

/**
 * @brief OFullKeyboard::setheaderRadius
 * @param radius
 */
void OFullKeyboard::setheaderRadius(int radius) {
    m_headerRadius = radius;
    refresh();
}

/**
 * @brief OFullKeyboard::setHeaderFont
 * @param font
 */
void OFullKeyboard::setHeaderFont(QString font) {
    m_headerFont = font;
    refresh();
}

/**
 * @brief OFullKeyboard::setHeaderColor
 * @param color
 */
void OFullKeyboard::setHeaderColor(QString color) {
    m_headerColor = color;
    refresh();
}

/**
 * @brief OFullKeyboard::setHeaderBorder
 * @param border
 */
void OFullKeyboard::setHeaderBorder(QString border) {
    m_headerBorder = border;
    refresh();
}

/**
 * @brief OFullKeyboard::setHeaderBackground
 * @param background
 */
void OFullKeyboard::setHeaderBackground(QString background) {
    m_headerBackground = background;
    refresh();
}

/**
 * @brief OFullKeyboard::onKeyPressed
 */
void OFullKeyboard::onKeyPressedEn() {

    QObject *r = (QObject *)m_receiver->focusWidget();
    if (r) {
        QToolButton *toolButton = (QToolButton *)sender();
        if (!m_keyMapper.contains( toolButton )) {
            return;
        }

        Qt::Key keyValue = m_keyMapper.value( toolButton );
        QString key = QString( quint32( keyValue ) );
        if (ui->toolButtonCap->text() == tr( "cap" )) {
            key = key.toLower();
        }

        QKeyEvent keyPress(QEvent::KeyPress, quint32( keyValue ), Qt::NoModifier, key );
        QApplication::sendEvent(r, &keyPress);
        QKeyEvent keyRelease(QEvent::KeyRelease, quint32( keyValue ), Qt::NoModifier, QString());
        QApplication::sendEvent(r, &keyRelease);
    }
}

/**
 * @brief OFullKeyboard::onKeyPressedCh
 */
void OFullKeyboard::onKeyPressedCh() {

    QToolButton *toolButton = (QToolButton *)sender();
    if (!m_keyMapper.contains( toolButton )) {
        return;
    }

    QObject *r = (QObject *)ui->lineEditShow;
    if (m_letterKeyList.contains(toolButton)) {
        r = (QObject *)ui->lineEditShow;
    } else {
        if (ui->toolButtonDelete == toolButton
                && !ui->lineEditShow->text().isEmpty()) {
            r = (QObject *)ui->lineEditShow;
        } else {
            QWidget *w = static_cast<QWidget *>(parent());
            if (w == NULL) {
                 return;
            }
            r = (QObject *)m_receiver->focusWidget();
        }
    }

    Qt::Key keyValue = m_keyMapper.value( toolButton );
    QString key = QString( quint32( keyValue ) );
    key = key.toLower();

    if (r == ui->lineEditShow) {
        ui->lineEditShow->setReadOnly( false );
    }
    QKeyEvent keyPress(QEvent::KeyPress, quint32( keyValue ), Qt::NoModifier, key );
    QApplication::sendEvent(r, &keyPress);
    QKeyEvent keyRelease(QEvent::KeyRelease, quint32( keyValue ), Qt::NoModifier, QString());
    QApplication::sendEvent(r, &keyRelease);
    if (r == ui->lineEditShow) {
        ui->lineEditShow->setReadOnly( true );
    }
}

/**
 * @brief OFullKeyboard::onCapKeyPressed
 */
void OFullKeyboard::onCapKeyPressed() {
    if (ui->toolButtonCap->text() == tr( "cap" )) {

        QList<QToolButton *> keyList = m_keyMapper.keys();
        for (int i = 0; i < keyList.size(); i ++) {
            QToolButton *toolButton = keyList.at( i );
            toolButton->setText( toolButton->text().toUpper() );
        }
        ui->toolButtonCap->setText( tr( "CAP" ) );
    } else {

        QList<QToolButton *> keyList = m_keyMapper.keys();
        for (int i = 0; i < keyList.size(); i ++) {
            QToolButton *toolButton = keyList.at( i );
            toolButton->setText( toolButton->text().toLower() );
        }
        ui->toolButtonCap->setText( tr( "cap" ) );
    }
    ui->labelType->setText( QString( "%1--%2" ).arg(ui->toolButtonCh_En->text()).arg(ui->toolButtonCap->text()) );
}

/**
 * @brief OFullKeyboard::onChEnPressed
 */
void OFullKeyboard::onSwitchKeyPressed() {

    if (ui->toolButtonCh_En->text() == tr( "EN" )) {
        QList<QToolButton *> keyList = m_keyMapper.keys();
        for (int i = 0; i < keyList.size(); i ++) {
            QToolButton *toolButton = keyList.at( i );
            disconnect(toolButton, SIGNAL(clicked(bool)), this, SLOT(onKeyPressedEn()));
            if (!m_digitKeyList.contains(toolButton)) {
                connect(toolButton, SIGNAL(clicked(bool)), this, SLOT(onKeyPressedCh()));
            }
        }

        for (int i = 0; i < m_digitKeyList.size(); i ++) {
            QToolButton *toolButton = m_digitKeyList.at( i );
            toolButton->setEnabled( true );
            toolButton->setText( "" );
            connect(toolButton, SIGNAL(clicked(bool)), this, SLOT(onSelectKeyPressed()));
        }
        m_currentPage = 0;
        ui->lineEditShow->setText( "" );
        ui->toolButtonCh_En->setText( tr( "CN" ) );
    } else {

        for (int i = 0; i < m_digitKeyList.size(); i ++) {
            QToolButton *toolButton = m_digitKeyList.at( i );
            toolButton->setEnabled( true );
            toolButton->setText( QString::number( i + 1 ) );
            disconnect(toolButton, SIGNAL(clicked(bool)), this, SLOT(onSelectKeyPressed()));
        }

        QList<QToolButton *> keyList = m_keyMapper.keys();
        for (int i = 0; i < keyList.size(); i ++) {
            QToolButton *toolButton = keyList.at( i );
            connect(toolButton, SIGNAL(clicked(bool)), this, SLOT(onKeyPressedEn()));
            if (!m_digitKeyList.contains(toolButton)) {
                disconnect(toolButton, SIGNAL(clicked(bool)), this, SLOT(onKeyPressedCh()));
            }
        }
        ui->toolButtonCh_En->setText( tr( "EN" ) );
        ui->lineEditShow->setText( "" );
        ui->toolButtonLeft->setEnabled( false );
        ui->toolButtonRight->setEnabled( false );
    }
    ui->labelType->setText( QString( "%1--%2" ).arg(ui->toolButtonCh_En->text()).arg(ui->toolButtonCap->text()) );
}

/**
 * @brief OFullKeyboard::onSelectKeyPressed
 */
void OFullKeyboard::onSelectKeyPressed() {
    QWidget *w = static_cast<QWidget *>(parent());
    if (w == NULL) {
         return;
    }
    QObject *r = (QObject *)w->focusWidget();
    QToolButton *toolButton = (QToolButton *)sender();
    if (NULL == toolButton) {
        return;
    }

    QKeyEvent keyPress(QEvent::KeyPress, Qt::Key_unknown, Qt::NoModifier, toolButton->text() );
    QApplication::sendEvent(r, &keyPress);
    QKeyEvent keyRelease(QEvent::KeyRelease, Qt::Key_unknown, Qt::NoModifier, QString());
    QApplication::sendEvent(r, &keyRelease);
    ui->lineEditShow->setText( "" );
}

/**
 * @brief OFullKeyboard::updateHz
 */
void OFullKeyboard::updateHz(QString text) {

    if (ui->toolButtonCh_En->text() == tr( "EN" ) ) {
        return;
    }
    if (ui->lineEditShow == sender()) {
        m_currentPage = 0;
    }
    int size = m_digitKeyList.size();
    for (int i = 0; i < size; i ++) {
        QToolButton *toolButton = m_digitKeyList.at( i );
        toolButton->setText( "" );
        toolButton->setEnabled( false );
    }

    QString hzList;
    if (m_hanziMapper.contains( text )) {
        hzList = m_hanziMapper.value( text );
    } else {
        m_currentPage = 0;
        ui->toolButtonLeft->setEnabled( false );
        ui->toolButtonRight->setEnabled( false );
        return;
    }

    int totalPage = hzList.length()%size==0?hzList.length()/size:hzList.length()/size+1;
    if (totalPage > 0) {
        m_currentPage = m_currentPage%totalPage;
    }
    ui->toolButtonLeft->setEnabled( !(m_currentPage == 0 || totalPage == 0) );
    ui->toolButtonRight->setEnabled( !(m_currentPage == totalPage - 1) );

    for (int i = m_currentPage*size; i < hzList.length(); i ++) {
        QToolButton *toolButton = m_digitKeyList.at( i%size );
        toolButton->setText( hzList.at( i ) );
        toolButton->setEnabled( true );
        if ((i+1) % size == 0 && i != 0) {
            break;
        }
    }
}

/**
 * @brief OFullKeyboard::prePage
 */
void OFullKeyboard::prePage() {
    m_currentPage --;
    updateHz(ui->lineEditShow->text());
}

/**
 * @brief OFullKeyboard::nextPage
 */
void OFullKeyboard::nextPage() {
    m_currentPage ++;
    updateHz(ui->lineEditShow->text());
}

/**
 * @brief OFullKeyboard::showEvent
 * @param e
 */
void OFullKeyboard::showEvent(QShowEvent */*e*/) {

    resize();
}

/**
 * @brief OFullKeyboard::mouseMoveEvent
 * @param e
 */
void OFullKeyboard::mouseMoveEvent(QMouseEvent *e) {
    if (e->buttons() == Qt::LeftButton && m_isPressed) {
        move(e->globalPos() - m_dragOrigin);
        e->accept();
    }
}

/**
 * @brief OFullKeyboard::mousePressEvent
 * @param e
 */
void OFullKeyboard::mousePressEvent(QMouseEvent *e) {

    if (e->button() == Qt::LeftButton && m_isFloated) {
        m_dragOrigin = e->globalPos() - frameGeometry().topLeft();
        m_isPressed = true;
        e->accept();
    }
}

/**
 * @brief OFullKeyboard::mouseReleaseEvent
 * @param e
 */
void OFullKeyboard::mouseReleaseEvent(QMouseEvent *e) {
    m_isPressed = false;
    QWidget::mousePressEvent( e );
}

/**
 * @brief OFullKeyboard::resize
 */
void OFullKeyboard::resize() {

    if (m_isAutoResize) {
        int w = width()/(m_digitKeyList.size() + 2);
        int h = height()/6;
        setKeySize( QSize(w, h) );
    }

    int left = 0, top = 0, right = 0, bottom = 0;
    ui->verticalLayoutBorder->getContentsMargins(&left, &top, &right, &bottom);
    ui->frameBorder->setFixedSize( QSize(m_keySize.width()*(m_digitKeyList.size() + 2)+left+right, m_keySize.height()*6+top+right+5) );
}

/**
 * @brief OFullKeyboard::refresh
 */
void OFullKeyboard::refresh() {

    QString keyQss = m_keyStyleSheet.arg(m_keyRadius).arg(m_keyFont).arg(m_keyColor).
            arg(m_keyBackground_enabled).arg(m_keyBackground_hover).arg(m_keyBackground_pressed).arg(m_keyBackground_disabled);

    QString borderQss = m_borderStyleSheet.arg(m_border).arg(m_borderRadius).arg(m_borderBackground);

    QString headerQss = m_headerStyleSheet.arg(m_headerColor).arg(m_headerFont).arg(m_headerBorder).arg(m_headerRadius).arg(m_headerBackground);
    setStyleSheet( keyQss + borderQss + headerQss);
}

/**
 * @brief OFullKeyboard::loadFontLibrary
 */
void OFullKeyboard::loadFontLibrary() {

    QFile file( ":ziku/ziku.dat" );
    if (file.open(QFile::ReadOnly)) {

        QTextStream in(&file);
        in.setCodec("GBK");
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList dataList = line.split( "," );
            if (dataList.isEmpty()) {
                continue;
            }
            m_hanziMapper.insert(dataList.first(), dataList.last());
        }
        file.close();
    }
}

/**
 * @brief OFullKeyboard::initializeKey
 */
void OFullKeyboard::initializeKey() {

    // 数字键
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

    m_digitKeyList.append( ui->toolButton1 );
    m_digitKeyList.append( ui->toolButton2 );
    m_digitKeyList.append( ui->toolButton3 );
    m_digitKeyList.append( ui->toolButton4 );
    m_digitKeyList.append( ui->toolButton5 );
    m_digitKeyList.append( ui->toolButton6 );
    m_digitKeyList.append( ui->toolButton7 );
    m_digitKeyList.append( ui->toolButton8 );
    m_digitKeyList.append( ui->toolButton9 );
    m_digitKeyList.append( ui->toolButton0 );

    // 字母键
    m_keyMapper.insert(ui->toolButtonA, Qt::Key_A);
    m_keyMapper.insert(ui->toolButtonB, Qt::Key_B);
    m_keyMapper.insert(ui->toolButtonC, Qt::Key_C);
    m_keyMapper.insert(ui->toolButtonD, Qt::Key_D);
    m_keyMapper.insert(ui->toolButtonE, Qt::Key_E);
    m_keyMapper.insert(ui->toolButtonF, Qt::Key_F);
    m_keyMapper.insert(ui->toolButtonG, Qt::Key_G);
    m_keyMapper.insert(ui->toolButtonH, Qt::Key_H);
    m_keyMapper.insert(ui->toolButtonI, Qt::Key_I);
    m_keyMapper.insert(ui->toolButtonJ, Qt::Key_J);
    m_keyMapper.insert(ui->toolButtonK, Qt::Key_K);
    m_keyMapper.insert(ui->toolButtonL, Qt::Key_L);
    m_keyMapper.insert(ui->toolButtonM, Qt::Key_M);
    m_keyMapper.insert(ui->toolButtonN, Qt::Key_N);
    m_keyMapper.insert(ui->toolButtonO, Qt::Key_O);
    m_keyMapper.insert(ui->toolButtonP, Qt::Key_P);
    m_keyMapper.insert(ui->toolButtonQ, Qt::Key_Q);
    m_keyMapper.insert(ui->toolButtonR, Qt::Key_R);
    m_keyMapper.insert(ui->toolButtonS, Qt::Key_S);
    m_keyMapper.insert(ui->toolButtonT, Qt::Key_T);
    m_keyMapper.insert(ui->toolButtonU, Qt::Key_U);
    m_keyMapper.insert(ui->toolButtonV, Qt::Key_V);
    m_keyMapper.insert(ui->toolButtonW, Qt::Key_W);
    m_keyMapper.insert(ui->toolButtonX, Qt::Key_X);
    m_keyMapper.insert(ui->toolButtonY, Qt::Key_Y);
    m_keyMapper.insert(ui->toolButtonZ, Qt::Key_Z);

    m_letterKeyList.append( ui->toolButtonA );
    m_letterKeyList.append( ui->toolButtonB );
    m_letterKeyList.append( ui->toolButtonC );
    m_letterKeyList.append( ui->toolButtonD );
    m_letterKeyList.append( ui->toolButtonE );
    m_letterKeyList.append( ui->toolButtonF );
    m_letterKeyList.append( ui->toolButtonG );
    m_letterKeyList.append( ui->toolButtonH );
    m_letterKeyList.append( ui->toolButtonI );
    m_letterKeyList.append( ui->toolButtonJ );
    m_letterKeyList.append( ui->toolButtonK );
    m_letterKeyList.append( ui->toolButtonL );
    m_letterKeyList.append( ui->toolButtonM );
    m_letterKeyList.append( ui->toolButtonN );
    m_letterKeyList.append( ui->toolButtonO );
    m_letterKeyList.append( ui->toolButtonP );
    m_letterKeyList.append( ui->toolButtonQ );
    m_letterKeyList.append( ui->toolButtonR );
    m_letterKeyList.append( ui->toolButtonS );
    m_letterKeyList.append( ui->toolButtonT );
    m_letterKeyList.append( ui->toolButtonU );
    m_letterKeyList.append( ui->toolButtonV );
    m_letterKeyList.append( ui->toolButtonW );
    m_letterKeyList.append( ui->toolButtonX );
    m_letterKeyList.append( ui->toolButtonY );
    m_letterKeyList.append( ui->toolButtonZ );

    // 其他键
    m_keyMapper.insert(ui->toolButtonSemicolon, Qt::Key_Semicolon);
    m_keyMapper.insert(ui->toolButtonComma, Qt::Key_Comma);
    m_keyMapper.insert(ui->toolButtonPeriod, Qt::Key_Period);
    m_keyMapper.insert(ui->toolButtonQuestion, Qt::Key_Question);
    m_keyMapper.insert(ui->toolButtonPlus, Qt::Key_Plus);
    m_keyMapper.insert(ui->toolButtonMinus, Qt::Key_Minus);
    m_keyMapper.insert(ui->toolButtonAsterisk, Qt::Key_Asterisk);
    m_keyMapper.insert(ui->toolButtonSlash, Qt::Key_Slash);
    m_keyMapper.insert(ui->toolButtonEqual, Qt::Key_Equal);
    m_keyMapper.insert(ui->toolButtonExclam, Qt::Key_Exclam);
    m_keyMapper.insert(ui->toolButtonSpace, Qt::Key_Space);
    m_keyMapper.insert(ui->toolButtonDelete, Qt::Key_Backspace);
    m_keyMapper.insert(ui->toolButtonEnter, Qt::Key_Enter);

    QList<QToolButton *> keyList = m_keyMapper.keys();
    for (int i = 0; i < keyList.size(); i ++) {
        QToolButton *toolButton = keyList.at( i );
        connect(toolButton, SIGNAL(clicked(bool)), this, SLOT(onKeyPressedEn()));
    }

    ui->lineEditShow->setText( "" );
    ui->toolButtonLeft->setEnabled( false );
    ui->toolButtonRight->setEnabled( false );

    connect(ui->toolButtonCap, SIGNAL(clicked(bool)), this, SLOT(onCapKeyPressed()));
    connect(ui->toolButtonCh_En, SIGNAL(clicked(bool)), this, SLOT(onSwitchKeyPressed()));
    connect(ui->lineEditShow, SIGNAL(textChanged(QString)), this, SLOT(updateHz(QString)));
    connect(ui->toolButtonLeft, SIGNAL(clicked(bool)), this, SLOT(prePage()));
    connect(ui->toolButtonRight, SIGNAL(clicked(bool)), this, SLOT(nextPage()));
    connect(ui->pushButtonClose, SIGNAL(clicked(bool)), this, SLOT(hide()));
}

/**
 * @brief OFullKeyboard::initializeStyleSheet
 */
void OFullKeyboard::initializeStyleSheet() {

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
    m_borderStyleSheet = QString( "QFrame#OFullKeyboard {"
                                      "background:transparent;"
                                  "}"
                                  "QFrame#frameBorder {"
                                      "border:%1;"
                                      "border-radius:%2px;"
                                      "background-color:%3;"
                                  "}"
                                  );

    m_headerRadius = m_keySize.height()/2;
    m_headerFont = "20pt \"黑体\"";
    m_headerColor = "white";
    m_headerBorder = "0px solid white";
    m_headerBackground = "qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #5B5F5F, stop: 0.5 #0C2436, stop: 1.0 #27405A )";
    m_headerStyleSheet = QString( "QLabel {"
                                      "color:%1;"
                                      "font:%2;"
                                      "background:transparent;"
                                  "}"
                                  "QLineEdit {"
                                      "border: 0px solid white;"
                                      "color:%1;"
                                      "font:%2;"
                                      "background:transparent;"
                                  "}"
                                  "QPushButton {"
                                      "border:0px groove white;"
                                      "color:%1;"
                                      "font:%2;"
                                      "background:transparent;"
                                  "}"
                                  "QPushButton::disable {"
                                      "color:gray;"
                                  "}"
                                  "QFrame#frameHeader{"
                                      "border:%3;"
                                      "border-radius:%4px;"
                                      "background:%5;"
                                  "}"
                                  );
    refresh();
}
