/********************************************************************************
** Form generated from reading UI file 'toolwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLWINDOW_H
#define UI_TOOLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_ToolWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButtonBack;
    QToolButton *toolButtonAssistant;
    QToolButton *toolButtonHelp;
    QToolButton *toolButtonRestart;
    QToolButton *toolButtonShutdown;

    void setupUi(QFrame *ToolWindow)
    {
        if (ToolWindow->objectName().isEmpty())
            ToolWindow->setObjectName(QStringLiteral("ToolWindow"));
        ToolWindow->resize(1088, 700);
        ToolWindow->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	color:white;\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        ToolWindow->setFrameShape(QFrame::NoFrame);
        ToolWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(ToolWindow);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButtonBack = new QToolButton(ToolWindow);
        toolButtonBack->setObjectName(QStringLiteral("toolButtonBack"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/tool_icons/Back.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonBack->setIcon(icon);
        toolButtonBack->setIconSize(QSize(200, 200));
        toolButtonBack->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButtonBack->setAutoRaise(true);

        horizontalLayout->addWidget(toolButtonBack);

        toolButtonAssistant = new QToolButton(ToolWindow);
        toolButtonAssistant->setObjectName(QStringLiteral("toolButtonAssistant"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/tool_icons/Assistant.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonAssistant->setIcon(icon1);
        toolButtonAssistant->setIconSize(QSize(200, 200));
        toolButtonAssistant->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButtonAssistant->setAutoRaise(true);

        horizontalLayout->addWidget(toolButtonAssistant);

        toolButtonHelp = new QToolButton(ToolWindow);
        toolButtonHelp->setObjectName(QStringLiteral("toolButtonHelp"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/tool_icons/Help.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonHelp->setIcon(icon2);
        toolButtonHelp->setIconSize(QSize(200, 200));
        toolButtonHelp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButtonHelp->setAutoRaise(true);

        horizontalLayout->addWidget(toolButtonHelp);

        toolButtonRestart = new QToolButton(ToolWindow);
        toolButtonRestart->setObjectName(QStringLiteral("toolButtonRestart"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/tool_icons/Restart.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonRestart->setIcon(icon3);
        toolButtonRestart->setIconSize(QSize(200, 200));
        toolButtonRestart->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButtonRestart->setAutoRaise(true);

        horizontalLayout->addWidget(toolButtonRestart);

        toolButtonShutdown = new QToolButton(ToolWindow);
        toolButtonShutdown->setObjectName(QStringLiteral("toolButtonShutdown"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/tool_icons/Shut Down.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonShutdown->setIcon(icon4);
        toolButtonShutdown->setIconSize(QSize(200, 200));
        toolButtonShutdown->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButtonShutdown->setAutoRaise(true);

        horizontalLayout->addWidget(toolButtonShutdown);


        retranslateUi(ToolWindow);

        QMetaObject::connectSlotsByName(ToolWindow);
    } // setupUi

    void retranslateUi(QFrame *ToolWindow)
    {
        ToolWindow->setWindowTitle(QApplication::translate("ToolWindow", "Frame", 0));
        toolButtonBack->setText(QApplication::translate("ToolWindow", "Back", 0));
        toolButtonAssistant->setText(QApplication::translate("ToolWindow", "Assistant", 0));
        toolButtonHelp->setText(QApplication::translate("ToolWindow", "Help", 0));
        toolButtonRestart->setText(QApplication::translate("ToolWindow", "Restart", 0));
        toolButtonShutdown->setText(QApplication::translate("ToolWindow", "Shutdown", 0));
    } // retranslateUi

};

namespace Ui {
    class ToolWindow: public Ui_ToolWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLWINDOW_H
