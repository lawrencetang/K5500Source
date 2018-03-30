/********************************************************************************
** Form generated from reading UI file 'nanogoldwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NANOGOLDWINDOW_H
#define UI_NANOGOLDWINDOW_H

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

class Ui_NanoGoldWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageTesting;
    QWidget *pageSetting;

    void setupUi(QFrame *NanoGoldWindow)
    {
        if (NanoGoldWindow->objectName().isEmpty())
            NanoGoldWindow->setObjectName(QStringLiteral("NanoGoldWindow"));
        NanoGoldWindow->resize(942, 678);
        NanoGoldWindow->setFrameShape(QFrame::StyledPanel);
        NanoGoldWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(NanoGoldWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(NanoGoldWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageTesting = new QWidget();
        pageTesting->setObjectName(QStringLiteral("pageTesting"));
        stackedWidget->addWidget(pageTesting);
        pageSetting = new QWidget();
        pageSetting->setObjectName(QStringLiteral("pageSetting"));
        stackedWidget->addWidget(pageSetting);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(NanoGoldWindow);

        QMetaObject::connectSlotsByName(NanoGoldWindow);
    } // setupUi

    void retranslateUi(QFrame *NanoGoldWindow)
    {
        NanoGoldWindow->setWindowTitle(QApplication::translate("NanoGoldWindow", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class NanoGoldWindow: public Ui_NanoGoldWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NANOGOLDWINDOW_H
