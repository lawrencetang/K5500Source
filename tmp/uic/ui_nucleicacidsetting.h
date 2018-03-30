/********************************************************************************
** Form generated from reading UI file 'nucleicacidsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUCLEICACIDSETTING_H
#define UI_NUCLEICACIDSETTING_H

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

class Ui_NucleicAcidSetting
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

    void setupUi(QFrame *NucleicAcidSetting)
    {
        if (NucleicAcidSetting->objectName().isEmpty())
            NucleicAcidSetting->setObjectName(QStringLiteral("NucleicAcidSetting"));
        NucleicAcidSetting->resize(882, 646);
        NucleicAcidSetting->setStyleSheet(QLatin1String("QFrame#NucleicAcidSetting{\n"
"	background-color: white;\n"
"}"));
        NucleicAcidSetting->setFrameShape(QFrame::NoFrame);
        NucleicAcidSetting->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(NucleicAcidSetting);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameHeader = new QFrame(NucleicAcidSetting);
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
        frameParameter = new QFrame(NucleicAcidSetting);
        frameParameter->setObjectName(QStringLiteral("frameParameter"));
        frameParameter->setStyleSheet(QLatin1String("QFrame#frameParameter{\n"
"	background-color: qlineargradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #5B5F5F, stop: 0.5 #0C2436, stop: 1.0 #27405A );\n"
"}"));
        frameParameter->setFrameShape(QFrame::NoFrame);
        frameParameter->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frameParameter);

        frameKeyboard = new QFrame(NucleicAcidSetting);
        frameKeyboard->setObjectName(QStringLiteral("frameKeyboard"));
        frameKeyboard->setFrameShape(QFrame::NoFrame);
        frameKeyboard->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frameKeyboard);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(1, 1);

        retranslateUi(NucleicAcidSetting);

        QMetaObject::connectSlotsByName(NucleicAcidSetting);
    } // setupUi

    void retranslateUi(QFrame *NucleicAcidSetting)
    {
        NucleicAcidSetting->setWindowTitle(QApplication::translate("NucleicAcidSetting", "Frame", 0));
        labelTitle->setText(QApplication::translate("NucleicAcidSetting", "TextLabel", 0));
        toolButtonRestore->setText(QApplication::translate("NucleicAcidSetting", "Restore", 0));
        toolButtonCancel->setText(QApplication::translate("NucleicAcidSetting", "Cancel", 0));
        toolButtonOK->setText(QApplication::translate("NucleicAcidSetting", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class NucleicAcidSetting: public Ui_NucleicAcidSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUCLEICACIDSETTING_H
