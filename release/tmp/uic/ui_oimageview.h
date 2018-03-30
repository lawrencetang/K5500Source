/********************************************************************************
** Form generated from reading UI file 'oimageview.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OIMAGEVIEW_H
#define UI_OIMAGEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OImageView
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameHeader;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTitle;
    QToolButton *toolButtonClose;
    QFrame *frameImage;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelImage;

    void setupUi(QDialog *OImageView)
    {
        if (OImageView->objectName().isEmpty())
            OImageView->setObjectName(QStringLiteral("OImageView"));
        OImageView->resize(669, 421);
        verticalLayout = new QVBoxLayout(OImageView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameHeader = new QFrame(OImageView);
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
        horizontalLayout = new QHBoxLayout(frameHeader);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(frameHeader);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelTitle);

        toolButtonClose = new QToolButton(frameHeader);
        toolButtonClose->setObjectName(QStringLiteral("toolButtonClose"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonClose->sizePolicy().hasHeightForWidth());
        toolButtonClose->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonClose->setIcon(icon);
        toolButtonClose->setIconSize(QSize(48, 48));
        toolButtonClose->setAutoRaise(true);

        horizontalLayout->addWidget(toolButtonClose);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addWidget(frameHeader);

        frameImage = new QFrame(OImageView);
        frameImage->setObjectName(QStringLiteral("frameImage"));
        frameImage->setFrameShape(QFrame::NoFrame);
        frameImage->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameImage);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelImage = new QLabel(frameImage);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setScaledContents(true);

        horizontalLayout_2->addWidget(labelImage);


        verticalLayout->addWidget(frameImage);

        verticalLayout->setStretch(1, 1);

        retranslateUi(OImageView);

        QMetaObject::connectSlotsByName(OImageView);
    } // setupUi

    void retranslateUi(QDialog *OImageView)
    {
        OImageView->setWindowTitle(QApplication::translate("OImageView", "Dialog", 0));
        labelTitle->setText(QString());
        toolButtonClose->setText(QApplication::translate("OImageView", "...", 0));
        labelImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OImageView: public Ui_OImageView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OIMAGEVIEW_H
