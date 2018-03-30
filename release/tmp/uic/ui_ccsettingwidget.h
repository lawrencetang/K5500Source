/********************************************************************************
** Form generated from reading UI file 'ccsettingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCSETTINGWIDGET_H
#define UI_CCSETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CCSettingWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameHeader;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelTitle;
    QToolButton *toolButtonRestore;
    QToolButton *toolButtonCancel;
    QToolButton *toolButtonOK;
    QHBoxLayout *horizontalLayout;
    QFrame *frameParameter;
    QFrame *frameKeyboard;

    void setupUi(QFrame *CCSettingWidget)
    {
        if (CCSettingWidget->objectName().isEmpty())
            CCSettingWidget->setObjectName(QStringLiteral("CCSettingWidget"));
        CCSettingWidget->resize(882, 646);
        CCSettingWidget->setStyleSheet(QStringLiteral(""));
        CCSettingWidget->setFrameShape(QFrame::NoFrame);
        CCSettingWidget->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(CCSettingWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameHeader = new QFrame(CCSettingWidget);
        frameHeader->setObjectName(QStringLiteral("frameHeader"));
        frameHeader->setMinimumSize(QSize(0, 55));
        frameHeader->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QToolButton::disabled{\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QFrame#frameHeader {\n"
"	background-color: rgb(85, 0, 127);\n"
"}\n"
"\n"
"QLabel{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameHeader->setFrameShape(QFrame::NoFrame);
        frameHeader->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameHeader);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(frameHeader);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        horizontalLayout_2->addWidget(labelTitle);

        toolButtonRestore = new QToolButton(frameHeader);
        toolButtonRestore->setObjectName(QStringLiteral("toolButtonRestore"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonRestore->sizePolicy().hasHeightForWidth());
        toolButtonRestore->setSizePolicy(sizePolicy);
        toolButtonRestore->setMinimumSize(QSize(140, 0));
        toolButtonRestore->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonRestore);

        toolButtonCancel = new QToolButton(frameHeader);
        toolButtonCancel->setObjectName(QStringLiteral("toolButtonCancel"));
        sizePolicy.setHeightForWidth(toolButtonCancel->sizePolicy().hasHeightForWidth());
        toolButtonCancel->setSizePolicy(sizePolicy);
        toolButtonCancel->setMinimumSize(QSize(140, 0));
        toolButtonCancel->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonCancel);

        toolButtonOK = new QToolButton(frameHeader);
        toolButtonOK->setObjectName(QStringLiteral("toolButtonOK"));
        sizePolicy.setHeightForWidth(toolButtonOK->sizePolicy().hasHeightForWidth());
        toolButtonOK->setSizePolicy(sizePolicy);
        toolButtonOK->setMinimumSize(QSize(140, 0));
        toolButtonOK->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonOK);

        horizontalLayout_2->setStretch(0, 1);

        verticalLayout->addWidget(frameHeader);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frameParameter = new QFrame(CCSettingWidget);
        frameParameter->setObjectName(QStringLiteral("frameParameter"));
        frameParameter->setStyleSheet(QLatin1String("QFrame#frameParameter{\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #5B5F5F, stop: 0.5 #0C2436, stop: 1.0 #27405A );\n"
"}"));
        frameParameter->setFrameShape(QFrame::NoFrame);
        frameParameter->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frameParameter);

        frameKeyboard = new QFrame(CCSettingWidget);
        frameKeyboard->setObjectName(QStringLiteral("frameKeyboard"));
        frameKeyboard->setFrameShape(QFrame::NoFrame);
        frameKeyboard->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frameKeyboard);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(1, 1);

        retranslateUi(CCSettingWidget);

        QMetaObject::connectSlotsByName(CCSettingWidget);
    } // setupUi

    void retranslateUi(QFrame *CCSettingWidget)
    {
        CCSettingWidget->setWindowTitle(QApplication::translate("CCSettingWidget", "Frame", 0));
        labelTitle->setText(QApplication::translate("CCSettingWidget", "TextLabel", 0));
        toolButtonRestore->setText(QApplication::translate("CCSettingWidget", "Restore", 0));
        toolButtonCancel->setText(QApplication::translate("CCSettingWidget", "Cancel", 0));
        toolButtonOK->setText(QApplication::translate("CCSettingWidget", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class CCSettingWidget: public Ui_CCSettingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCSETTINGWIDGET_H
