/********************************************************************************
** Form generated from reading UI file 'orecordtablewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORECORDTABLEWIDGET_H
#define UI_ORECORDTABLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ORecordTableWidget
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageMain;
    QHBoxLayout *horizontalLayout;
    QFrame *frameMainHeader;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelTitle;
    QToolButton *toolButtonExport;
    QToolButton *toolButtonRemove;
    QWidget *pageOption;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frameOptionHeader;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBoxSelectAll;
    QToolButton *toolButtonCanel;
    QToolButton *toolButtonOk;
    QFrame *frameTable;

    void setupUi(QFrame *ORecordTableWidget)
    {
        if (ORecordTableWidget->objectName().isEmpty())
            ORecordTableWidget->setObjectName(QStringLiteral("ORecordTableWidget"));
        ORecordTableWidget->resize(806, 541);
        ORecordTableWidget->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"	spacing: 5px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"	left:5px; \n"
"	width: 24px;height: 24px;\n"
"}\n"
"\n"
"QCheckBox::indicator::unchecked {\n"
"	image: url(:/orecordtablewidget_icons/unchecked.png);\n"
"}\n"
"\n"
"QCheckBox::indicator::checked {\n"
"	image: url(:/orecordtablewidget_icons/checked.png);\n"
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
        ORecordTableWidget->setFrameShape(QFrame::StyledPanel);
        ORecordTableWidget->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(ORecordTableWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(ORecordTableWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(0, 55));
        stackedWidget->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QToolButton{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QToolButton::disabled{\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QWidget#pageMain {\n"
"	background-color: rgb(85, 0, 127);\n"
"}\n"
"\n"
"QWidget#pageOption {\n"
"	background-color: rgb(85, 0, 127);\n"
"}"));
        pageMain = new QWidget();
        pageMain->setObjectName(QStringLiteral("pageMain"));
        horizontalLayout = new QHBoxLayout(pageMain);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frameMainHeader = new QFrame(pageMain);
        frameMainHeader->setObjectName(QStringLiteral("frameMainHeader"));
        frameMainHeader->setFrameShape(QFrame::StyledPanel);
        frameMainHeader->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frameMainHeader);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        labelTitle = new QLabel(frameMainHeader);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        horizontalLayout_3->addWidget(labelTitle);

        toolButtonExport = new QToolButton(frameMainHeader);
        toolButtonExport->setObjectName(QStringLiteral("toolButtonExport"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonExport->sizePolicy().hasHeightForWidth());
        toolButtonExport->setSizePolicy(sizePolicy);
        toolButtonExport->setMinimumSize(QSize(140, 0));
        toolButtonExport->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButtonExport);

        toolButtonRemove = new QToolButton(frameMainHeader);
        toolButtonRemove->setObjectName(QStringLiteral("toolButtonRemove"));
        sizePolicy.setHeightForWidth(toolButtonRemove->sizePolicy().hasHeightForWidth());
        toolButtonRemove->setSizePolicy(sizePolicy);
        toolButtonRemove->setMinimumSize(QSize(140, 0));
        toolButtonRemove->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButtonRemove);

        horizontalLayout_3->setStretch(0, 1);

        horizontalLayout->addWidget(frameMainHeader);

        stackedWidget->addWidget(pageMain);
        pageOption = new QWidget();
        pageOption->setObjectName(QStringLiteral("pageOption"));
        horizontalLayout_2 = new QHBoxLayout(pageOption);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frameOptionHeader = new QFrame(pageOption);
        frameOptionHeader->setObjectName(QStringLiteral("frameOptionHeader"));
        frameOptionHeader->setFrameShape(QFrame::NoFrame);
        frameOptionHeader->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frameOptionHeader);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(9, 0, 0, 0);
        checkBoxSelectAll = new QCheckBox(frameOptionHeader);
        checkBoxSelectAll->setObjectName(QStringLiteral("checkBoxSelectAll"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBoxSelectAll->sizePolicy().hasHeightForWidth());
        checkBoxSelectAll->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(checkBoxSelectAll);

        toolButtonCanel = new QToolButton(frameOptionHeader);
        toolButtonCanel->setObjectName(QStringLiteral("toolButtonCanel"));
        sizePolicy.setHeightForWidth(toolButtonCanel->sizePolicy().hasHeightForWidth());
        toolButtonCanel->setSizePolicy(sizePolicy);
        toolButtonCanel->setMinimumSize(QSize(140, 0));
        toolButtonCanel->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButtonCanel);

        toolButtonOk = new QToolButton(frameOptionHeader);
        toolButtonOk->setObjectName(QStringLiteral("toolButtonOk"));
        sizePolicy.setHeightForWidth(toolButtonOk->sizePolicy().hasHeightForWidth());
        toolButtonOk->setSizePolicy(sizePolicy);
        toolButtonOk->setMinimumSize(QSize(140, 0));
        toolButtonOk->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButtonOk);

        horizontalLayout_4->setStretch(0, 1);

        horizontalLayout_2->addWidget(frameOptionHeader);

        stackedWidget->addWidget(pageOption);

        verticalLayout->addWidget(stackedWidget);

        frameTable = new QFrame(ORecordTableWidget);
        frameTable->setObjectName(QStringLiteral("frameTable"));
        frameTable->setFrameShape(QFrame::NoFrame);
        frameTable->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frameTable);

        verticalLayout->setStretch(1, 1);

        retranslateUi(ORecordTableWidget);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ORecordTableWidget);
    } // setupUi

    void retranslateUi(QFrame *ORecordTableWidget)
    {
        ORecordTableWidget->setWindowTitle(QApplication::translate("ORecordTableWidget", "Frame", 0));
        labelTitle->setText(QApplication::translate("ORecordTableWidget", "TextLabel", 0));
        toolButtonExport->setText(QApplication::translate("ORecordTableWidget", "Export", 0));
        toolButtonRemove->setText(QApplication::translate("ORecordTableWidget", "Remove", 0));
        checkBoxSelectAll->setText(QApplication::translate("ORecordTableWidget", "Select All", 0));
        toolButtonCanel->setText(QApplication::translate("ORecordTableWidget", "Cancel", 0));
        toolButtonOk->setText(QApplication::translate("ORecordTableWidget", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class ORecordTableWidget: public Ui_ORecordTableWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORECORDTABLEWIDGET_H
