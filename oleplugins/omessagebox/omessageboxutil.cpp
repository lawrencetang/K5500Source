#include "omessageboxutil.h"
#include "omessagebox.h"

#include <QDebug>
#include <QCoreApplication>

OMessageBoxUtil::OMessageBoxUtil() {
}

OMessageBoxUtil::~OMessageBoxUtil() {
}

/**
 * @brief OMessageBoxI::setStyleSheet
 * @param stylesheet
 */
QString OMessageBoxUtil::m_styleSheet = "";
void OMessageBoxUtil::setStyleSheet(QString stylesheet) {
    m_styleSheet = stylesheet;
}

/**
 * @brief OMessageBoxI::staticNotice
 * @param parent
 * @param text
 * @param btnLabels
 * @param timeout
 * @return
 */
int OMessageBoxUtil::staticNotice(QWidget *parent, QString text,
                               QStringList btnLabels, int timeout) {

    OMessageBox msgBox(timeout, parent);
    msgBox.resize(400, 300);
    if (!m_styleSheet.isEmpty()) {
        msgBox.setStyleSheet(m_styleSheet);
        m_styleSheet = "";
    }
    msgBox.setText( text );
    msgBox.addButtons( btnLabels );
    return msgBox.exec();
}

/**
 * @brief OMessageBoxI::dynamicNotice
 * @param parent
 * @param text
 * @param btnLabels
 * @return
 */
OMessageBox *OMessageBoxUtil::dynamicNotice(QWidget *parent, QString text) {

    OMessageBox *msgBox = new OMessageBox(0, parent);
    msgBox->setClosable( false );
    msgBox->resize(400, 300);
    msgBox->gifEnable();
    if (!m_styleSheet.isEmpty()) {
        msgBox->setStyleSheet(m_styleSheet);
        m_styleSheet = "";
    }
    msgBox->setText( text );
    msgBox->open();
    while(!msgBox->isShown()) {
        QCoreApplication::processEvents();
    }
    return msgBox;
}


