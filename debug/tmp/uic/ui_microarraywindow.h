/********************************************************************************
** Form generated from reading UI file 'microarraywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MICROARRAYWINDOW_H
#define UI_MICROARRAYWINDOW_H

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

class Ui_MicroArrayWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageTesting;
    QWidget *pageSetting;

    void setupUi(QFrame *MicroArrayWindow)
    {
        if (MicroArrayWindow->objectName().isEmpty())
            MicroArrayWindow->setObjectName(QStringLiteral("MicroArrayWindow"));
        MicroArrayWindow->resize(942, 678);
        MicroArrayWindow->setFrameShape(QFrame::StyledPanel);
        MicroArrayWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(MicroArrayWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(MicroArrayWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageTesting = new QWidget();
        pageTesting->setObjectName(QStringLiteral("pageTesting"));
        stackedWidget->addWidget(pageTesting);
        pageSetting = new QWidget();
        pageSetting->setObjectName(QStringLiteral("pageSetting"));
        stackedWidget->addWidget(pageSetting);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(MicroArrayWindow);

        QMetaObject::connectSlotsByName(MicroArrayWindow);
    } // setupUi

    void retranslateUi(QFrame *MicroArrayWindow)
    {
        MicroArrayWindow->setWindowTitle(QApplication::translate("MicroArrayWindow", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class MicroArrayWindow: public Ui_MicroArrayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MICROARRAYWINDOW_H
