/********************************************************************************
** Form generated from reading UI file 'cellculturewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CELLCULTUREWINDOW_H
#define UI_CELLCULTUREWINDOW_H

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

class Ui_CellCultureWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageTesting;
    QWidget *pageSetting;

    void setupUi(QFrame *CellCultureWindow)
    {
        if (CellCultureWindow->objectName().isEmpty())
            CellCultureWindow->setObjectName(QStringLiteral("CellCultureWindow"));
        CellCultureWindow->resize(942, 678);
        CellCultureWindow->setFrameShape(QFrame::StyledPanel);
        CellCultureWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(CellCultureWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(CellCultureWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageTesting = new QWidget();
        pageTesting->setObjectName(QStringLiteral("pageTesting"));
        stackedWidget->addWidget(pageTesting);
        pageSetting = new QWidget();
        pageSetting->setObjectName(QStringLiteral("pageSetting"));
        stackedWidget->addWidget(pageSetting);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(CellCultureWindow);

        QMetaObject::connectSlotsByName(CellCultureWindow);
    } // setupUi

    void retranslateUi(QFrame *CellCultureWindow)
    {
        CellCultureWindow->setWindowTitle(QApplication::translate("CellCultureWindow", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class CellCultureWindow: public Ui_CellCultureWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CELLCULTUREWINDOW_H
