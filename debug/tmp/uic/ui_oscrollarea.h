/********************************************************************************
** Form generated from reading UI file 'oscrollarea.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSCROLLAREA_H
#define UI_OSCROLLAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OScrollArea
{
public:
    QWidget *scrollAreaWidgetContents;

    void setupUi(QScrollArea *OScrollArea)
    {
        if (OScrollArea->objectName().isEmpty())
            OScrollArea->setObjectName(QStringLiteral("OScrollArea"));
        OScrollArea->resize(784, 693);
        OScrollArea->setStyleSheet(QStringLiteral("background-color:transparent;"));
        OScrollArea->setFrameShape(QFrame::NoFrame);
        OScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        OScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        OScrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        OScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 784, 693));
        OScrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(OScrollArea);

        QMetaObject::connectSlotsByName(OScrollArea);
    } // setupUi

    void retranslateUi(QScrollArea *OScrollArea)
    {
        OScrollArea->setWindowTitle(QApplication::translate("OScrollArea", "ScrollArea", 0));
    } // retranslateUi

};

namespace Ui {
    class OScrollArea: public Ui_OScrollArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSCROLLAREA_H
