/********************************************************************************
** Form generated from reading UI file 'dynamicswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DYNAMICSWINDOW_H
#define UI_DYNAMICSWINDOW_H

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

class Ui_DynamicsWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageTesting;
    QWidget *pageSetting;

    void setupUi(QFrame *DynamicsWindow)
    {
        if (DynamicsWindow->objectName().isEmpty())
            DynamicsWindow->setObjectName(QStringLiteral("DynamicsWindow"));
        DynamicsWindow->resize(942, 678);
        DynamicsWindow->setFrameShape(QFrame::StyledPanel);
        DynamicsWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(DynamicsWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(DynamicsWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageTesting = new QWidget();
        pageTesting->setObjectName(QStringLiteral("pageTesting"));
        stackedWidget->addWidget(pageTesting);
        pageSetting = new QWidget();
        pageSetting->setObjectName(QStringLiteral("pageSetting"));
        stackedWidget->addWidget(pageSetting);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(DynamicsWindow);

        QMetaObject::connectSlotsByName(DynamicsWindow);
    } // setupUi

    void retranslateUi(QFrame *DynamicsWindow)
    {
        DynamicsWindow->setWindowTitle(QApplication::translate("DynamicsWindow", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class DynamicsWindow: public Ui_DynamicsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DYNAMICSWINDOW_H
