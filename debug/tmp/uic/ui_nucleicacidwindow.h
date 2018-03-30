/********************************************************************************
** Form generated from reading UI file 'nucleicacidwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUCLEICACIDWINDOW_H
#define UI_NUCLEICACIDWINDOW_H

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

class Ui_NucleicAcidWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageTesting;
    QWidget *pageSetting;

    void setupUi(QFrame *NucleicAcidWindow)
    {
        if (NucleicAcidWindow->objectName().isEmpty())
            NucleicAcidWindow->setObjectName(QStringLiteral("NucleicAcidWindow"));
        NucleicAcidWindow->resize(942, 678);
        NucleicAcidWindow->setFrameShape(QFrame::StyledPanel);
        NucleicAcidWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(NucleicAcidWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(NucleicAcidWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageTesting = new QWidget();
        pageTesting->setObjectName(QStringLiteral("pageTesting"));
        stackedWidget->addWidget(pageTesting);
        pageSetting = new QWidget();
        pageSetting->setObjectName(QStringLiteral("pageSetting"));
        stackedWidget->addWidget(pageSetting);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(NucleicAcidWindow);

        QMetaObject::connectSlotsByName(NucleicAcidWindow);
    } // setupUi

    void retranslateUi(QFrame *NucleicAcidWindow)
    {
        NucleicAcidWindow->setWindowTitle(QApplication::translate("NucleicAcidWindow", "Frame", 0));
    } // retranslateUi

};

namespace Ui {
    class NucleicAcidWindow: public Ui_NucleicAcidWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUCLEICACIDWINDOW_H
