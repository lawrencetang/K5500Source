/********************************************************************************
** Form generated from reading UI file 'ocontrolpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OCONTROLPANEL_H
#define UI_OCONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_OControlPanel
{
public:

    void setupUi(QFrame *OControlPanel)
    {
        if (OControlPanel->objectName().isEmpty())
            OControlPanel->setObjectName(QStringLiteral("OControlPanel"));
        OControlPanel->resize(531, 396);
        OControlPanel->setFrameShape(QFrame::StyledPanel);
        OControlPanel->setFrameShadow(QFrame::Raised);

        retranslateUi(OControlPanel);

        QMetaObject::connectSlotsByName(OControlPanel);
    } // setupUi

    void retranslateUi(QFrame *OControlPanel)
    {
        OControlPanel->setWindowTitle(QApplication::translate("OControlPanel", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class OControlPanel: public Ui_OControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OCONTROLPANEL_H
