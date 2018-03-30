/********************************************************************************
** Form generated from reading UI file 'kmtestingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KMTESTINGWIDGET_H
#define UI_KMTESTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_KMTestingWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QFrame *frameLeft;
    QVBoxLayout *verticalLayout_2;
    QFrame *frameMain;
    QVBoxLayout *verticalLayout;
    QFrame *frameHeader;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButtonBack;
    QToolButton *toolButtonBlank;
    QToolButton *toolButtonMeasure;
    QToolButton *toolButtonSetting;
    QToolButton *toolButtonCapture;
    QToolButton *toolButtonClear;
    QHBoxLayout *horizontalLayout;
    QFrame *framePlot;
    QFrame *frameFit;
    QFrame *frameBottom;

    void setupUi(QFrame *KMTestingWidget)
    {
        if (KMTestingWidget->objectName().isEmpty())
            KMTestingWidget->setObjectName(QStringLiteral("KMTestingWidget"));
        KMTestingWidget->resize(1076, 688);
        KMTestingWidget->setFrameShape(QFrame::NoFrame);
        KMTestingWidget->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(KMTestingWidget);
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frameLeft = new QFrame(KMTestingWidget);
        frameLeft->setObjectName(QStringLiteral("frameLeft"));
        frameLeft->setStyleSheet(QLatin1String("QFrame#frameLeft{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        frameLeft->setFrameShape(QFrame::NoFrame);
        frameLeft->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(frameLeft);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frameMain = new QFrame(KMTestingWidget);
        frameMain->setObjectName(QStringLiteral("frameMain"));
        frameMain->setFrameShape(QFrame::NoFrame);
        frameMain->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameMain);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameHeader = new QFrame(frameMain);
        frameHeader->setObjectName(QStringLiteral("frameHeader"));
        frameHeader->setMinimumSize(QSize(0, 125));
        frameHeader->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color:blue;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QToolButton::disabled{\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QFrame#frameHeader {\n"
"	background-color: white;\n"
"}"));
        frameHeader->setFrameShape(QFrame::NoFrame);
        frameHeader->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameHeader);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButtonBack = new QToolButton(frameHeader);
        toolButtonBack->setObjectName(QStringLiteral("toolButtonBack"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonBack->sizePolicy().hasHeightForWidth());
        toolButtonBack->setSizePolicy(sizePolicy);
        toolButtonBack->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonBack);

        toolButtonBlank = new QToolButton(frameHeader);
        toolButtonBlank->setObjectName(QStringLiteral("toolButtonBlank"));
        sizePolicy.setHeightForWidth(toolButtonBlank->sizePolicy().hasHeightForWidth());
        toolButtonBlank->setSizePolicy(sizePolicy);
        toolButtonBlank->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonBlank);

        toolButtonMeasure = new QToolButton(frameHeader);
        toolButtonMeasure->setObjectName(QStringLiteral("toolButtonMeasure"));
        sizePolicy.setHeightForWidth(toolButtonMeasure->sizePolicy().hasHeightForWidth());
        toolButtonMeasure->setSizePolicy(sizePolicy);
        toolButtonMeasure->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonMeasure);

        toolButtonSetting = new QToolButton(frameHeader);
        toolButtonSetting->setObjectName(QStringLiteral("toolButtonSetting"));
        sizePolicy.setHeightForWidth(toolButtonSetting->sizePolicy().hasHeightForWidth());
        toolButtonSetting->setSizePolicy(sizePolicy);
        toolButtonSetting->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonSetting);

        toolButtonCapture = new QToolButton(frameHeader);
        toolButtonCapture->setObjectName(QStringLiteral("toolButtonCapture"));
        sizePolicy.setHeightForWidth(toolButtonCapture->sizePolicy().hasHeightForWidth());
        toolButtonCapture->setSizePolicy(sizePolicy);
        toolButtonCapture->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonCapture);

        toolButtonClear = new QToolButton(frameHeader);
        toolButtonClear->setObjectName(QStringLiteral("toolButtonClear"));
        sizePolicy.setHeightForWidth(toolButtonClear->sizePolicy().hasHeightForWidth());
        toolButtonClear->setSizePolicy(sizePolicy);
        toolButtonClear->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonClear);


        verticalLayout->addWidget(frameHeader);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(1);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        framePlot = new QFrame(frameMain);
        framePlot->setObjectName(QStringLiteral("framePlot"));
        framePlot->setFrameShape(QFrame::NoFrame);
        framePlot->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(framePlot);

        frameFit = new QFrame(frameMain);
        frameFit->setObjectName(QStringLiteral("frameFit"));
        frameFit->setFrameShape(QFrame::NoFrame);
        frameFit->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frameFit);

        horizontalLayout->setStretch(0, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(1, 1);

        verticalLayout_2->addWidget(frameMain);

        frameBottom = new QFrame(KMTestingWidget);
        frameBottom->setObjectName(QStringLiteral("frameBottom"));
        frameBottom->setFrameShape(QFrame::NoFrame);
        frameBottom->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frameBottom);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 4);

        retranslateUi(KMTestingWidget);

        QMetaObject::connectSlotsByName(KMTestingWidget);
    } // setupUi

    void retranslateUi(QFrame *KMTestingWidget)
    {
        KMTestingWidget->setWindowTitle(QApplication::translate("KMTestingWidget", "Frame", 0));
        toolButtonBack->setText(QApplication::translate("KMTestingWidget", "Back", 0));
        toolButtonBlank->setText(QApplication::translate("KMTestingWidget", "Blank", 0));
        toolButtonMeasure->setText(QApplication::translate("KMTestingWidget", "Measure", 0));
        toolButtonSetting->setText(QApplication::translate("KMTestingWidget", "Setting", 0));
        toolButtonCapture->setText(QApplication::translate("KMTestingWidget", "Capture", 0));
        toolButtonClear->setText(QApplication::translate("KMTestingWidget", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class KMTestingWidget: public Ui_KMTestingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KMTESTINGWIDGET_H
