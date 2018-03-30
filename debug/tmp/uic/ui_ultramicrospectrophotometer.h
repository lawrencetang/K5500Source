/********************************************************************************
** Form generated from reading UI file 'ultramicrospectrophotometer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ULTRAMICROSPECTROPHOTOMETER_H
#define UI_ULTRAMICROSPECTROPHOTOMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UltramicroSpectrophotometer
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageMain;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UltramicroSpectrophotometer)
    {
        if (UltramicroSpectrophotometer->objectName().isEmpty())
            UltramicroSpectrophotometer->setObjectName(QStringLiteral("UltramicroSpectrophotometer"));
        UltramicroSpectrophotometer->resize(988, 650);
        centralWidget = new QWidget(UltramicroSpectrophotometer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageMain = new QWidget();
        pageMain->setObjectName(QStringLiteral("pageMain"));
        stackedWidget->addWidget(pageMain);

        verticalLayout->addWidget(stackedWidget);

        UltramicroSpectrophotometer->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(UltramicroSpectrophotometer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setStyleSheet(QString::fromUtf8("QStatusBar#statusBar{\n"
"font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: yellow;\n"
"}"));
        UltramicroSpectrophotometer->setStatusBar(statusBar);

        retranslateUi(UltramicroSpectrophotometer);

        QMetaObject::connectSlotsByName(UltramicroSpectrophotometer);
    } // setupUi

    void retranslateUi(QMainWindow *UltramicroSpectrophotometer)
    {
        UltramicroSpectrophotometer->setWindowTitle(QApplication::translate("UltramicroSpectrophotometer", "UltramicroSpectrophotometer", 0));
    } // retranslateUi

};

namespace Ui {
    class UltramicroSpectrophotometer: public Ui_UltramicroSpectrophotometer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ULTRAMICROSPECTROPHOTOMETER_H
