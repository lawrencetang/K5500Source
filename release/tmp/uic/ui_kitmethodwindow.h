/********************************************************************************
** Form generated from reading UI file 'kitmethodwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KITMETHODWINDOW_H
#define UI_KITMETHODWINDOW_H

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

class Ui_KitMethodWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageTesting;
    QWidget *pageSetting;

    void setupUi(QFrame *KitMethodWindow)
    {
        if (KitMethodWindow->objectName().isEmpty())
            KitMethodWindow->setObjectName(QStringLiteral("KitMethodWindow"));
        KitMethodWindow->resize(942, 678);
        KitMethodWindow->setFrameShape(QFrame::StyledPanel);
        KitMethodWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(KitMethodWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(KitMethodWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageTesting = new QWidget();
        pageTesting->setObjectName(QStringLiteral("pageTesting"));
        stackedWidget->addWidget(pageTesting);
        pageSetting = new QWidget();
        pageSetting->setObjectName(QStringLiteral("pageSetting"));
        stackedWidget->addWidget(pageSetting);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(KitMethodWindow);

        QMetaObject::connectSlotsByName(KitMethodWindow);
    } // setupUi

    void retranslateUi(QFrame *KitMethodWindow)
    {
        KitMethodWindow->setWindowTitle(QApplication::translate("KitMethodWindow", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class KitMethodWindow: public Ui_KitMethodWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KITMETHODWINDOW_H
