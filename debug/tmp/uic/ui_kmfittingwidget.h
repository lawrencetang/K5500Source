/********************************************************************************
** Form generated from reading UI file 'kmfittingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KMFITTINGWIDGET_H
#define UI_KMFITTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KMFittingWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageFitting;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidgetFitting;
    QWidget *pageMain;
    QVBoxLayout *verticalLayout_2;
    QFrame *frameTable_m;
    QFrame *frameBtnBox_m;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButtonAdd;
    QToolButton *toolButtonRemove;
    QToolButton *toolButtonFit;
    QToolButton *toolButtonSwitch;
    QWidget *pageAdd;
    QVBoxLayout *verticalLayout_3;
    QFrame *frameHeader;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelConcentration;
    QDoubleSpinBox *doubleSpinBoxConcentration;
    QFrame *frameKeyboard;
    QFrame *frameBtnBox_a;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButtonCancel_a;
    QToolButton *toolButtonOk_a;
    QWidget *pageRemove;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButtonCheckAll;
    QFrame *frameTable_r;
    QFrame *frameBtnBox_r;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButtonCancel_r;
    QToolButton *toolButtonOk_r;
    QWidget *pageMeasure;
    QVBoxLayout *verticalLayout_6;
    QFrame *frameTableMeasure;
    QFrame *frameBtnBoxMeasure;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *toolButtonBack;
    QToolButton *toolButtonClear;

    void setupUi(QFrame *KMFittingWidget)
    {
        if (KMFittingWidget->objectName().isEmpty())
            KMFittingWidget->setObjectName(QStringLiteral("KMFittingWidget"));
        KMFittingWidget->resize(347, 553);
        KMFittingWidget->setStyleSheet(QLatin1String("QFrame#KMFittingWidget{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        KMFittingWidget->setFrameShape(QFrame::NoFrame);
        KMFittingWidget->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(KMFittingWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(KMFittingWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageFitting = new QWidget();
        pageFitting->setObjectName(QStringLiteral("pageFitting"));
        verticalLayout = new QVBoxLayout(pageFitting);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidgetFitting = new QStackedWidget(pageFitting);
        stackedWidgetFitting->setObjectName(QStringLiteral("stackedWidgetFitting"));
        pageMain = new QWidget();
        pageMain->setObjectName(QStringLiteral("pageMain"));
        verticalLayout_2 = new QVBoxLayout(pageMain);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frameTable_m = new QFrame(pageMain);
        frameTable_m->setObjectName(QStringLiteral("frameTable_m"));
        frameTable_m->setFrameShape(QFrame::NoFrame);
        frameTable_m->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frameTable_m);

        frameBtnBox_m = new QFrame(pageMain);
        frameBtnBox_m->setObjectName(QStringLiteral("frameBtnBox_m"));
        frameBtnBox_m->setMinimumSize(QSize(256, 64));
        frameBtnBox_m->setStyleSheet(QString::fromUtf8("QFrame#frameBtnBox_m {\n"
"	background-color: rgb(160, 160, 160);\n"
"}\n"
"\n"
"QToolButton {\n"
"	color:white;\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameBtnBox_m->setFrameShape(QFrame::NoFrame);
        frameBtnBox_m->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameBtnBox_m);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButtonAdd = new QToolButton(frameBtnBox_m);
        toolButtonAdd->setObjectName(QStringLiteral("toolButtonAdd"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonAdd->sizePolicy().hasHeightForWidth());
        toolButtonAdd->setSizePolicy(sizePolicy);
        toolButtonAdd->setMinimumSize(QSize(91, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/kitmethod_icons/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonAdd->setIcon(icon);
        toolButtonAdd->setIconSize(QSize(64, 64));
        toolButtonAdd->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButtonAdd->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonAdd);

        toolButtonRemove = new QToolButton(frameBtnBox_m);
        toolButtonRemove->setObjectName(QStringLiteral("toolButtonRemove"));
        toolButtonRemove->setMinimumSize(QSize(91, 0));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/kitmethod_icons/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonRemove->setIcon(icon1);
        toolButtonRemove->setIconSize(QSize(64, 64));
        toolButtonRemove->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButtonRemove->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonRemove);

        toolButtonFit = new QToolButton(frameBtnBox_m);
        toolButtonFit->setObjectName(QStringLiteral("toolButtonFit"));
        toolButtonFit->setMinimumSize(QSize(91, 0));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/kitmethod_icons/fit.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonFit->setIcon(icon2);
        toolButtonFit->setIconSize(QSize(64, 64));
        toolButtonFit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButtonFit->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonFit);

        toolButtonSwitch = new QToolButton(frameBtnBox_m);
        toolButtonSwitch->setObjectName(QStringLiteral("toolButtonSwitch"));
        toolButtonSwitch->setMinimumSize(QSize(91, 0));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/kitmethod_icons/change.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonSwitch->setIcon(icon3);
        toolButtonSwitch->setIconSize(QSize(64, 64));
        toolButtonSwitch->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolButtonSwitch->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonSwitch);


        verticalLayout_2->addWidget(frameBtnBox_m);

        verticalLayout_2->setStretch(0, 1);
        stackedWidgetFitting->addWidget(pageMain);
        pageAdd = new QWidget();
        pageAdd->setObjectName(QStringLiteral("pageAdd"));
        verticalLayout_3 = new QVBoxLayout(pageAdd);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frameHeader = new QFrame(pageAdd);
        frameHeader->setObjectName(QStringLiteral("frameHeader"));
        frameHeader->setStyleSheet(QString::fromUtf8("QFrame#frameHeader{\n"
"	background-color: rgb(160, 160, 160);\n"
"}\n"
"\n"
"QLabel{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"	background: transparent;\n"
"}\n"
"\n"
"QSpinBox, QDoubleSpinBox, QDateTimeEdit {\n"
"	border: 1px solid white;\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"	background: transparent;\n"
"}\n"
"\n"
"QSpinBox::up-button, QDoubleSpinBox::up-button, QDateTimeEdit::up-button {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:right;\n"
"	padding-left: 10px;\n"
"	image: url(:/protein_icons/arrow_right.png);\n"
"	width: 24px;height: 28px; right:5px;\n"
"}\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button, QDateTimeEdit::down-button {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:left;\n"
"	padding-right: 10px;\n"
"	image: url(:/protein_icons/arrow_left.png);\n"
"	width: 24px;height: 28px; left:5px;\n"
"}\n"
"QSpinBox::up-button:pressed, QDoubleSpinBox::up-button:pressed, QDa"
                        "teTimeEdit::up-button:pressed {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:right;\n"
"	image: url(:/protein_icons/arrow_right.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::down-button:pressed, QDoubleSpinBox::down-button:pressed, QDateTimeEdit::down-button:pressed {\n"
"	subcontrol-position:left;\n"
"	image: url(:/protein_icons/arrow_left.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::disabled, QDoubleSpinBox::disabled, QDateTimeEdit::disabled {\n"
"	color:darkgray;\n"
"}\n"
""));
        frameHeader->setFrameShape(QFrame::NoFrame);
        frameHeader->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frameHeader);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(9, 9, 9, 9);
        labelConcentration = new QLabel(frameHeader);
        labelConcentration->setObjectName(QStringLiteral("labelConcentration"));
        labelConcentration->setMinimumSize(QSize(0, 48));

        verticalLayout_4->addWidget(labelConcentration);

        doubleSpinBoxConcentration = new QDoubleSpinBox(frameHeader);
        doubleSpinBoxConcentration->setObjectName(QStringLiteral("doubleSpinBoxConcentration"));
        doubleSpinBoxConcentration->setMinimumSize(QSize(0, 48));
        doubleSpinBoxConcentration->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(doubleSpinBoxConcentration);


        verticalLayout_3->addWidget(frameHeader);

        frameKeyboard = new QFrame(pageAdd);
        frameKeyboard->setObjectName(QStringLiteral("frameKeyboard"));
        frameKeyboard->setFrameShape(QFrame::NoFrame);
        frameKeyboard->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(frameKeyboard);

        frameBtnBox_a = new QFrame(pageAdd);
        frameBtnBox_a->setObjectName(QStringLiteral("frameBtnBox_a"));
        frameBtnBox_a->setMinimumSize(QSize(0, 55));
        frameBtnBox_a->setStyleSheet(QString::fromUtf8("QFrame#frameBtnBox_a{\n"
"	background-color: rgb(160,160,160);\n"
"}\n"
"\n"
"QToolButton {\n"
"	color:white;\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameBtnBox_a->setFrameShape(QFrame::NoFrame);
        frameBtnBox_a->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frameBtnBox_a);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        toolButtonCancel_a = new QToolButton(frameBtnBox_a);
        toolButtonCancel_a->setObjectName(QStringLiteral("toolButtonCancel_a"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButtonCancel_a->sizePolicy().hasHeightForWidth());
        toolButtonCancel_a->setSizePolicy(sizePolicy1);
        toolButtonCancel_a->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButtonCancel_a);

        toolButtonOk_a = new QToolButton(frameBtnBox_a);
        toolButtonOk_a->setObjectName(QStringLiteral("toolButtonOk_a"));
        sizePolicy1.setHeightForWidth(toolButtonOk_a->sizePolicy().hasHeightForWidth());
        toolButtonOk_a->setSizePolicy(sizePolicy1);
        toolButtonOk_a->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButtonOk_a);


        verticalLayout_3->addWidget(frameBtnBox_a);

        verticalLayout_3->setStretch(1, 1);
        stackedWidgetFitting->addWidget(pageAdd);
        pageRemove = new QWidget();
        pageRemove->setObjectName(QStringLiteral("pageRemove"));
        verticalLayout_5 = new QVBoxLayout(pageRemove);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        radioButtonCheckAll = new QRadioButton(pageRemove);
        radioButtonCheckAll->setObjectName(QStringLiteral("radioButtonCheckAll"));
        radioButtonCheckAll->setMinimumSize(QSize(0, 48));
        radioButtonCheckAll->setStyleSheet(QString::fromUtf8("QRadioButton{\n"
"	color: Blue;\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	background-color: rgb(160, 160, 160);\n"
"}"));

        verticalLayout_5->addWidget(radioButtonCheckAll);

        frameTable_r = new QFrame(pageRemove);
        frameTable_r->setObjectName(QStringLiteral("frameTable_r"));
        frameTable_r->setFrameShape(QFrame::StyledPanel);
        frameTable_r->setFrameShadow(QFrame::Raised);

        verticalLayout_5->addWidget(frameTable_r);

        frameBtnBox_r = new QFrame(pageRemove);
        frameBtnBox_r->setObjectName(QStringLiteral("frameBtnBox_r"));
        frameBtnBox_r->setMinimumSize(QSize(0, 55));
        frameBtnBox_r->setStyleSheet(QString::fromUtf8("QFrame#frameBtnBox_r{\n"
"	background-color: rgb(160,160,160);\n"
"}\n"
"\n"
"QToolButton {\n"
"	color:white;\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameBtnBox_r->setFrameShape(QFrame::NoFrame);
        frameBtnBox_r->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frameBtnBox_r);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        toolButtonCancel_r = new QToolButton(frameBtnBox_r);
        toolButtonCancel_r->setObjectName(QStringLiteral("toolButtonCancel_r"));
        sizePolicy1.setHeightForWidth(toolButtonCancel_r->sizePolicy().hasHeightForWidth());
        toolButtonCancel_r->setSizePolicy(sizePolicy1);
        toolButtonCancel_r->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButtonCancel_r);

        toolButtonOk_r = new QToolButton(frameBtnBox_r);
        toolButtonOk_r->setObjectName(QStringLiteral("toolButtonOk_r"));
        sizePolicy1.setHeightForWidth(toolButtonOk_r->sizePolicy().hasHeightForWidth());
        toolButtonOk_r->setSizePolicy(sizePolicy1);
        toolButtonOk_r->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButtonOk_r);


        verticalLayout_5->addWidget(frameBtnBox_r);

        verticalLayout_5->setStretch(1, 1);
        stackedWidgetFitting->addWidget(pageRemove);

        verticalLayout->addWidget(stackedWidgetFitting);

        stackedWidget->addWidget(pageFitting);
        pageMeasure = new QWidget();
        pageMeasure->setObjectName(QStringLiteral("pageMeasure"));
        verticalLayout_6 = new QVBoxLayout(pageMeasure);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        frameTableMeasure = new QFrame(pageMeasure);
        frameTableMeasure->setObjectName(QStringLiteral("frameTableMeasure"));
        frameTableMeasure->setFrameShape(QFrame::NoFrame);
        frameTableMeasure->setFrameShadow(QFrame::Raised);

        verticalLayout_6->addWidget(frameTableMeasure);

        frameBtnBoxMeasure = new QFrame(pageMeasure);
        frameBtnBoxMeasure->setObjectName(QStringLiteral("frameBtnBoxMeasure"));
        frameBtnBoxMeasure->setMinimumSize(QSize(0, 55));
        frameBtnBoxMeasure->setStyleSheet(QString::fromUtf8("QFrame#frameBtnBoxMeasure{\n"
"	background-color: rgb(160,160,160);\n"
"}\n"
"\n"
"QToolButton {\n"
"	color:white;\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameBtnBoxMeasure->setFrameShape(QFrame::NoFrame);
        frameBtnBoxMeasure->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frameBtnBoxMeasure);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        toolButtonBack = new QToolButton(frameBtnBoxMeasure);
        toolButtonBack->setObjectName(QStringLiteral("toolButtonBack"));
        sizePolicy1.setHeightForWidth(toolButtonBack->sizePolicy().hasHeightForWidth());
        toolButtonBack->setSizePolicy(sizePolicy1);
        toolButtonBack->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButtonBack);

        toolButtonClear = new QToolButton(frameBtnBoxMeasure);
        toolButtonClear->setObjectName(QStringLiteral("toolButtonClear"));
        sizePolicy1.setHeightForWidth(toolButtonClear->sizePolicy().hasHeightForWidth());
        toolButtonClear->setSizePolicy(sizePolicy1);
        toolButtonClear->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButtonClear);


        verticalLayout_6->addWidget(frameBtnBoxMeasure);

        verticalLayout_6->setStretch(0, 1);
        stackedWidget->addWidget(pageMeasure);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(KMFittingWidget);

        QMetaObject::connectSlotsByName(KMFittingWidget);
    } // setupUi

    void retranslateUi(QFrame *KMFittingWidget)
    {
        KMFittingWidget->setWindowTitle(QApplication::translate("KMFittingWidget", "Frame", 0));
        toolButtonAdd->setText(QApplication::translate("KMFittingWidget", "Add", 0));
        toolButtonRemove->setText(QApplication::translate("KMFittingWidget", "Del", 0));
        toolButtonFit->setText(QApplication::translate("KMFittingWidget", "Fit", 0));
        toolButtonSwitch->setText(QApplication::translate("KMFittingWidget", "Switch", 0));
        labelConcentration->setText(QApplication::translate("KMFittingWidget", "Sample Concentration:", 0));
        doubleSpinBoxConcentration->setSuffix(QApplication::translate("KMFittingWidget", " mg/ml", 0));
        toolButtonCancel_a->setText(QApplication::translate("KMFittingWidget", "Cancel", 0));
        toolButtonOk_a->setText(QApplication::translate("KMFittingWidget", "Ok", 0));
        radioButtonCheckAll->setText(QApplication::translate("KMFittingWidget", "Check All", 0));
        toolButtonCancel_r->setText(QApplication::translate("KMFittingWidget", "Cancel", 0));
        toolButtonOk_r->setText(QApplication::translate("KMFittingWidget", "Ok", 0));
        toolButtonBack->setText(QApplication::translate("KMFittingWidget", "Back", 0));
        toolButtonClear->setText(QApplication::translate("KMFittingWidget", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class KMFittingWidget: public Ui_KMFittingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KMFITTINGWIDGET_H
