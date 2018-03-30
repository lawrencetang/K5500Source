#include "oexplorerlistview.h"

#include <QDebug>
#include <QScrollBar>
#include <QMouseEvent>

OExplorerListView::OExplorerListView(QWidget *parent):
    QListView(parent),m_leftButtonPressed(false) {

    setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSelectionMode(QAbstractItemView::NoSelection);
    setFrameShape(QFrame::NoFrame);
}

/**
 * @brief OExplorerListView::mousePressEvent
 * @param event
 */
void OExplorerListView::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_leftButtonPressed = true;
        m_originalPoint = event->globalPos();
        m_originalPointBackup = m_originalPoint;
    }
    QListView::mousePressEvent(event);
}

/**
 * @brief OExplorerListView::mouseMoveEvent
 * @param event
 */
void OExplorerListView::mouseMoveEvent(QMouseEvent *event) {
    if (m_leftButtonPressed) {
        int yMoved = event->globalPos().y() - m_originalPoint.y();
        verticalScrollBar()->setValue(verticalScrollBar()->value() - yMoved);
        m_originalPoint = event->globalPos();
        return;
    }
    QListView::mouseMoveEvent(event);
}

/**
 * @brief OExplorerListView::mouseReleaseEvent
 * @param event
 */
void OExplorerListView::mouseReleaseEvent(QMouseEvent *event) {
    if (m_leftButtonPressed) {
        m_leftButtonPressed = false;
        int yMoved = event->globalPos().y() - m_originalPointBackup.y();
        if (abs(yMoved) > 10) {
            return;
        }
    }
    QListView::mouseReleaseEvent(event);
}

