/********************************************************************************
** Form generated from reading UI file 'ofileexplorer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OFILEEXPLORER_H
#define UI_OFILEEXPLORER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OFileExplorer
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageMain;
    QVBoxLayout *verticalLayout;
    QFrame *frameHeaderMain;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelHeaderMain;
    QFrame *frameBtnBox;
    QVBoxLayout *verticalLayout_2;
    QToolButton *toolButtonFile;
    QToolButton *toolButtonImage;
    QSpacerItem *verticalSpacer;
    QWidget *pageList;
    QVBoxLayout *verticalLayout_3;
    QFrame *frameHeaderList;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButtonBack;
    QToolButton *toolButtonCut;
    QToolButton *toolButtonRemove;
    QFrame *frameList;
    QWidget *pageEdit;
    QVBoxLayout *verticalLayout_4;
    QFrame *frameHeaderEdit;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBoxCheckAll;
    QLabel *labelTitle;
    QFrame *frameEdit;
    QFrame *frameFootEdit;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *toolButtonCancel;
    QToolButton *toolButtonOk;

    void setupUi(QFrame *OFileExplorer)
    {
        if (OFileExplorer->objectName().isEmpty())
            OFileExplorer->setObjectName(QStringLiteral("OFileExplorer"));
        OFileExplorer->resize(283, 638);
        OFileExplorer->setFrameShape(QFrame::StyledPanel);
        OFileExplorer->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(OFileExplorer);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(OFileExplorer);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageMain = new QWidget();
        pageMain->setObjectName(QStringLiteral("pageMain"));
        pageMain->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(pageMain);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameHeaderMain = new QFrame(pageMain);
        frameHeaderMain->setObjectName(QStringLiteral("frameHeaderMain"));
        frameHeaderMain->setMinimumSize(QSize(0, 55));
        frameHeaderMain->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QFrame#frameHeaderMain {\n"
"	background-color: rgb(85, 0, 127);\n"
"}"));
        frameHeaderMain->setFrameShape(QFrame::StyledPanel);
        frameHeaderMain->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameHeaderMain);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelHeaderMain = new QLabel(frameHeaderMain);
        labelHeaderMain->setObjectName(QStringLiteral("labelHeaderMain"));
        labelHeaderMain->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(labelHeaderMain);


        verticalLayout->addWidget(frameHeaderMain);

        frameBtnBox = new QFrame(pageMain);
        frameBtnBox->setObjectName(QStringLiteral("frameBtnBox"));
        frameBtnBox->setStyleSheet(QString::fromUtf8("QToolButton {\n"
"	font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameBtnBox->setFrameShape(QFrame::StyledPanel);
        frameBtnBox->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frameBtnBox);
        verticalLayout_2->setSpacing(50);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 50, 9, -1);
        toolButtonFile = new QToolButton(frameBtnBox);
        toolButtonFile->setObjectName(QStringLiteral("toolButtonFile"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonFile->sizePolicy().hasHeightForWidth());
        toolButtonFile->setSizePolicy(sizePolicy);
        toolButtonFile->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ofileexplorer_icons/document.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonFile->setIcon(icon);
        toolButtonFile->setIconSize(QSize(80, 80));
        toolButtonFile->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        verticalLayout_2->addWidget(toolButtonFile);

        toolButtonImage = new QToolButton(frameBtnBox);
        toolButtonImage->setObjectName(QStringLiteral("toolButtonImage"));
        sizePolicy.setHeightForWidth(toolButtonImage->sizePolicy().hasHeightForWidth());
        toolButtonImage->setSizePolicy(sizePolicy);
        toolButtonImage->setMinimumSize(QSize(0, 0));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ofileexplorer_icons/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonImage->setIcon(icon1);
        toolButtonImage->setIconSize(QSize(80, 80));
        toolButtonImage->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButtonImage->setAutoRaise(false);

        verticalLayout_2->addWidget(toolButtonImage);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(frameBtnBox);

        verticalLayout->setStretch(1, 1);
        stackedWidget->addWidget(pageMain);
        pageList = new QWidget();
        pageList->setObjectName(QStringLiteral("pageList"));
        verticalLayout_3 = new QVBoxLayout(pageList);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frameHeaderList = new QFrame(pageList);
        frameHeaderList->setObjectName(QStringLiteral("frameHeaderList"));
        frameHeaderList->setMinimumSize(QSize(0, 55));
        frameHeaderList->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color:white;\n"
"	font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QToolButton::disabled{\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QFrame#frameHeaderList {\n"
"	background-color: rgb(85, 0, 127);\n"
"}"));
        frameHeaderList->setFrameShape(QFrame::StyledPanel);
        frameHeaderList->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frameHeaderList);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        toolButtonBack = new QToolButton(frameHeaderList);
        toolButtonBack->setObjectName(QStringLiteral("toolButtonBack"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButtonBack->sizePolicy().hasHeightForWidth());
        toolButtonBack->setSizePolicy(sizePolicy1);
        toolButtonBack->setAutoRaise(true);
        toolButtonBack->setArrowType(Qt::NoArrow);

        horizontalLayout_3->addWidget(toolButtonBack);

        toolButtonCut = new QToolButton(frameHeaderList);
        toolButtonCut->setObjectName(QStringLiteral("toolButtonCut"));
        sizePolicy1.setHeightForWidth(toolButtonCut->sizePolicy().hasHeightForWidth());
        toolButtonCut->setSizePolicy(sizePolicy1);
        toolButtonCut->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButtonCut);

        toolButtonRemove = new QToolButton(frameHeaderList);
        toolButtonRemove->setObjectName(QStringLiteral("toolButtonRemove"));
        sizePolicy1.setHeightForWidth(toolButtonRemove->sizePolicy().hasHeightForWidth());
        toolButtonRemove->setSizePolicy(sizePolicy1);
        toolButtonRemove->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButtonRemove);


        verticalLayout_3->addWidget(frameHeaderList);

        frameList = new QFrame(pageList);
        frameList->setObjectName(QStringLiteral("frameList"));
        frameList->setFrameShape(QFrame::StyledPanel);
        frameList->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(frameList);

        verticalLayout_3->setStretch(1, 1);
        stackedWidget->addWidget(pageList);
        pageEdit = new QWidget();
        pageEdit->setObjectName(QStringLiteral("pageEdit"));
        verticalLayout_4 = new QVBoxLayout(pageEdit);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        frameHeaderEdit = new QFrame(pageEdit);
        frameHeaderEdit->setObjectName(QStringLiteral("frameHeaderEdit"));
        frameHeaderEdit->setMinimumSize(QSize(0, 55));
        frameHeaderEdit->setStyleSheet(QString::fromUtf8("QFrame#frameHeaderEdit {\n"
"	background-color: rgb(85, 0, 127);\n"
"}\n"
"\n"
"QCheckBox {\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"	spacing: 5px;\n"
"}\n"
"\n"
"QCheckBox::indicator { \n"
"	width: 24px;height: 24px;\n"
"}\n"
"\n"
"QCheckBox::indicator::unchecked {\n"
"	image: url(:/ofileexplorer_icons/unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"	image: url(:/ofileexplorer_icons/checked.png);\n"
"}\n"
"\n"
"QCheckBox::disabled {\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QLabel {\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"}"));
        frameHeaderEdit->setFrameShape(QFrame::StyledPanel);
        frameHeaderEdit->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frameHeaderEdit);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBoxCheckAll = new QCheckBox(frameHeaderEdit);
        checkBoxCheckAll->setObjectName(QStringLiteral("checkBoxCheckAll"));

        horizontalLayout_4->addWidget(checkBoxCheckAll);

        labelTitle = new QLabel(frameHeaderEdit);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        labelTitle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(labelTitle);

        horizontalLayout_4->setStretch(0, 1);

        verticalLayout_4->addWidget(frameHeaderEdit);

        frameEdit = new QFrame(pageEdit);
        frameEdit->setObjectName(QStringLiteral("frameEdit"));
        frameEdit->setFrameShape(QFrame::StyledPanel);
        frameEdit->setFrameShadow(QFrame::Raised);

        verticalLayout_4->addWidget(frameEdit);

        frameFootEdit = new QFrame(pageEdit);
        frameFootEdit->setObjectName(QStringLiteral("frameFootEdit"));
        frameFootEdit->setMinimumSize(QSize(0, 55));
        frameFootEdit->setStyleSheet(QString::fromUtf8("QFrame#frameFootEdit {\n"
"	background-color: rgb(85, 0, 127);\n"
"}\n"
"\n"
"QToolButton{\n"
"	color:white;\n"
"	font: 75 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameFootEdit->setFrameShape(QFrame::StyledPanel);
        frameFootEdit->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frameFootEdit);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        toolButtonCancel = new QToolButton(frameFootEdit);
        toolButtonCancel->setObjectName(QStringLiteral("toolButtonCancel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButtonCancel->sizePolicy().hasHeightForWidth());
        toolButtonCancel->setSizePolicy(sizePolicy2);
        toolButtonCancel->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButtonCancel);

        toolButtonOk = new QToolButton(frameFootEdit);
        toolButtonOk->setObjectName(QStringLiteral("toolButtonOk"));
        sizePolicy1.setHeightForWidth(toolButtonOk->sizePolicy().hasHeightForWidth());
        toolButtonOk->setSizePolicy(sizePolicy1);
        toolButtonOk->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButtonOk);


        verticalLayout_4->addWidget(frameFootEdit);

        verticalLayout_4->setStretch(1, 1);
        stackedWidget->addWidget(pageEdit);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(OFileExplorer);

        QMetaObject::connectSlotsByName(OFileExplorer);
    } // setupUi

    void retranslateUi(QFrame *OFileExplorer)
    {
        OFileExplorer->setWindowTitle(QApplication::translate("OFileExplorer", "Frame", 0));
        labelHeaderMain->setText(QApplication::translate("OFileExplorer", "File Explorer", 0));
        toolButtonFile->setText(QApplication::translate("OFileExplorer", "Files", 0));
        toolButtonImage->setText(QApplication::translate("OFileExplorer", "Images", 0));
        toolButtonBack->setText(QApplication::translate("OFileExplorer", "Back", 0));
        toolButtonCut->setText(QApplication::translate("OFileExplorer", "Cut", 0));
        toolButtonRemove->setText(QApplication::translate("OFileExplorer", "Remove", 0));
        checkBoxCheckAll->setText(QApplication::translate("OFileExplorer", "check all", 0));
        labelTitle->setText(QApplication::translate("OFileExplorer", "TextLabel", 0));
        toolButtonCancel->setText(QApplication::translate("OFileExplorer", "Cancel", 0));
        toolButtonOk->setText(QApplication::translate("OFileExplorer", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class OFileExplorer: public Ui_OFileExplorer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OFILEEXPLORER_H
