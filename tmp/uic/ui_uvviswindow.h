/********************************************************************************
** Form generated from reading UI file 'uvviswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UVVISWINDOW_H
#define UI_UVVISWINDOW_H

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

class Ui_UvVisWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageTesting;
    QWidget *pageSetting;

    void setupUi(QFrame *UvVisWindow)
    {
        if (UvVisWindow->objectName().isEmpty())
            UvVisWindow->setObjectName(QStringLiteral("UvVisWindow"));
        UvVisWindow->resize(942, 678);
        UvVisWindow->setFrameShape(QFrame::StyledPanel);
        UvVisWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(UvVisWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(UvVisWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageTesting = new QWidget();
        pageTesting->setObjectName(QStringLiteral("pageTesting"));
        stackedWidget->addWidget(pageTesting);
        pageSetting = new QWidget();
        pageSetting->setObjectName(QStringLiteral("pageSetting"));
        stackedWidget->addWidget(pageSetting);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(UvVisWindow);

        QMetaObject::connectSlotsByName(UvVisWindow);
    } // setupUi

    void retranslateUi(QFrame *UvVisWindow)
    {
        UvVisWindow->setWindowTitle(QApplication::translate("UvVisWindow", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class UvVisWindow: public Ui_UvVisWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UVVISWINDOW_H
