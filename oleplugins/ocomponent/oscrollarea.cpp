#include "oscrollarea.h"
#include "ui_oscrollarea.h"

#include <QDebug>
#include <QScrollBar>
#include <QMouseEvent>

OScrollArea::OScrollArea(QWidget *parent) :
    QScrollArea(parent),
    ui(new Ui::OScrollArea) {
    ui->setupUi(this);
    m_leftButtonPressed = false;
    setStyleSheet(QString("QScrollArea#OScrollArea { background:transparent; } "
                          "QWidget#scrollAreaWidgetContents {background:transparent; } "));
}

OScrollArea::~OScrollArea() {
    delete ui;
}

/**
 * @brief OScrollArea::mousePressEvent
 * @param event
 */
void OScrollArea::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_leftButtonPressed = true;
        m_originalPoint = event->pos();
        return;
    }
    QScrollArea::mousePressEvent(event);
}

/**
 * @brief OScrollArea::mouseMoveEvent
 * @param event
 */
void OScrollArea::mouseMoveEvent(QMouseEvent *event) {
    if (m_leftButtonPressed) {
        int yMoved = event->pos().y() - m_originalPoint.y();
        verticalScrollBar()->setValue(verticalScrollBar()->value() - yMoved);//lt:新值=原始值-移动值
        m_originalPoint = event->pos();
        return;
    }
    QScrollArea::mouseMoveEvent(event);
}

/**
 * @brief OScrollArea::mouseReleaseEvent
 * @param event
 */
void OScrollArea::mouseReleaseEvent(QMouseEvent *event) {
    m_leftButtonPressed = false;
    QScrollArea::mouseReleaseEvent(event);
}
