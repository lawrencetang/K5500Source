/********************************************************************************
** Form generated from reading UI file 'proteinwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROTEINWINDOW_H
#define UI_PROTEINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProteinWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageTesting;
    QWidget *pageSetting;

    void setupUi(QFrame *ProteinWindow)
    {
        if (ProteinWindow->objectName().isEmpty())
            ProteinWindow->setObjectName(QStringLiteral("ProteinWindow"));
        ProteinWindow->resize(942, 678);
        ProteinWindow->setFrameShape(QFrame::StyledPanel);
        ProteinWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(ProteinWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(ProteinWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageTesting = new QWidget();
        pageTesting->setObjectName(QStringLiteral("pageTesting"));
        stackedWidget->addWidget(pageTesting);
        pageSetting = new QWidget();
        pageSetting->setObjectName(QStringLiteral("pageSetting"));
        stackedWidget->addWidget(pageSetting);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(ProteinWindow);

        QMetaObject::connectSlotsByName(ProteinWindow);
    } // setupUi

    void retranslateUi(QFrame *ProteinWindow)
    {
        ProteinWindow->setWindowTitle(QApplication::translate("ProteinWindow", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class ProteinWindow: public Ui_ProteinWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROTEINWINDOW_H
