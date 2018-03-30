/********************************************************************************
** Form generated from reading UI file 'otableview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTABLEVIEW_H
#define UI_OTABLEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OTableView
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameHeader;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTitle;
    QToolButton *toolButtonClose;
    QTableWidget *tableWidget;

    void setupUi(QDialog *OTableView)
    {
        if (OTableView->objectName().isEmpty())
            OTableView->setObjectName(QStringLiteral("OTableView"));
        OTableView->resize(992, 583);
        verticalLayout = new QVBoxLayout(OTableView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameHeader = new QFrame(OTableView);
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

        tableWidget = new QTableWidget(OTableView);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->horizontalHeader()->setDefaultSectionSize(160);
        tableWidget->verticalHeader()->setDefaultSectionSize(40);

        verticalLayout->addWidget(tableWidget);

        verticalLayout->setStretch(1, 1);

        retranslateUi(OTableView);

        QMetaObject::connectSlotsByName(OTableView);
    } // setupUi

    void retranslateUi(QDialog *OTableView)
    {
        OTableView->setWindowTitle(QApplication::translate("OTableView", "Dialog", 0));
        labelTitle->setText(QString());
        toolButtonClose->setText(QApplication::translate("OTableView", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class OTableView: public Ui_OTableView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTABLEVIEW_H
