/********************************************************************************
** Form generated from reading UI file 'madyewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MADYEWIDGET_H
#define UI_MADYEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MADyeWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageList;
    QVBoxLayout *verticalLayout_3;
    QFrame *frameTable_l;
    QFrame *frameBtnBox_l;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButtonCheckAll_l;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButtonAdd;
    QToolButton *toolButtonRemove;
    QWidget *pageAdd;
    QVBoxLayout *verticalLayout;
    QFrame *frameOption;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelDyeName;
    QLineEdit *lineEditDyeName;
    QHBoxLayout *horizontalLayout_6;
    QFormLayout *formLayout_2;
    QLabel *labelWaveLength;
    QSpinBox *spinBoxWaveLength;
    QLabel *labelMcm;
    QDoubleSpinBox *doubleSpinBoxMcm;
    QFormLayout *formLayout;
    QLabel *label260;
    QDoubleSpinBox *doubleSpinBox260;
    QLabel *label280;
    QDoubleSpinBox *doubleSpinBox280;
    QFrame *frameBtnBox_a;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButtonCancel_a;
    QToolButton *toolButtonOk_a;
    QWidget *pageRemove;
    QVBoxLayout *verticalLayout_2;
    QFrame *frameTable_r;
    QFrame *frameBtnBox_r;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButtonCheckAll_r;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButtonCancel_r;
    QToolButton *toolButtonOk_r;

    void setupUi(QFrame *MADyeWidget)
    {
        if (MADyeWidget->objectName().isEmpty())
            MADyeWidget->setObjectName(QStringLiteral("MADyeWidget"));
        MADyeWidget->resize(965, 611);
        MADyeWidget->setStyleSheet(QStringLiteral(""));
        MADyeWidget->setFrameShape(QFrame::NoFrame);
        MADyeWidget->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(MADyeWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(MADyeWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"	spacing: 5px;\n"
"}\n"
"\n"
"QRadioButton::indicator {\n"
"	left:5px; \n"
"	width: 24px;height: 24px;\n"
"}\n"
"\n"
"QRadioButton::indicator::unchecked {\n"
"	image: url(:/microarray_icons/unchecked.png);\n"
"}\n"
"\n"
"QRadioButton::indicator::checked {\n"
"	image: url(:/microarray_icons/checked.png);\n"
"}\n"
"\n"
"QRadioButton::disabled {\n"
"	color:darkgray;\n"
"}"));
        pageList = new QWidget();
        pageList->setObjectName(QStringLiteral("pageList"));
        verticalLayout_3 = new QVBoxLayout(pageList);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        frameTable_l = new QFrame(pageList);
        frameTable_l->setObjectName(QStringLiteral("frameTable_l"));
        frameTable_l->setFrameShape(QFrame::NoFrame);
        frameTable_l->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(frameTable_l);

        frameBtnBox_l = new QFrame(pageList);
        frameBtnBox_l->setObjectName(QStringLiteral("frameBtnBox_l"));
        frameBtnBox_l->setMinimumSize(QSize(0, 55));
        frameBtnBox_l->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QToolButton::disabled{\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QFrame#frameBtnBox_l {\n"
"	background-color: rgb(85, 0, 127);\n"
"}\n"
"\n"
"QLabel{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameBtnBox_l->setFrameShape(QFrame::NoFrame);
        frameBtnBox_l->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frameBtnBox_l);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        radioButtonCheckAll_l = new QRadioButton(frameBtnBox_l);
        radioButtonCheckAll_l->setObjectName(QStringLiteral("radioButtonCheckAll_l"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(radioButtonCheckAll_l->sizePolicy().hasHeightForWidth());
        radioButtonCheckAll_l->setSizePolicy(sizePolicy);
        radioButtonCheckAll_l->setMinimumSize(QSize(180, 0));

        horizontalLayout_4->addWidget(radioButtonCheckAll_l);

        horizontalSpacer_3 = new QSpacerItem(388, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        toolButtonAdd = new QToolButton(frameBtnBox_l);
        toolButtonAdd->setObjectName(QStringLiteral("toolButtonAdd"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButtonAdd->sizePolicy().hasHeightForWidth());
        toolButtonAdd->setSizePolicy(sizePolicy1);
        toolButtonAdd->setMinimumSize(QSize(180, 0));
        toolButtonAdd->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButtonAdd);

        toolButtonRemove = new QToolButton(frameBtnBox_l);
        toolButtonRemove->setObjectName(QStringLiteral("toolButtonRemove"));
        sizePolicy1.setHeightForWidth(toolButtonRemove->sizePolicy().hasHeightForWidth());
        toolButtonRemove->setSizePolicy(sizePolicy1);
        toolButtonRemove->setMinimumSize(QSize(180, 0));
        toolButtonRemove->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButtonRemove);


        verticalLayout_3->addWidget(frameBtnBox_l);

        verticalLayout_3->setStretch(0, 1);
        stackedWidget->addWidget(pageList);
        pageAdd = new QWidget();
        pageAdd->setObjectName(QStringLiteral("pageAdd"));
        verticalLayout = new QVBoxLayout(pageAdd);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameOption = new QFrame(pageAdd);
        frameOption->setObjectName(QStringLiteral("frameOption"));
        frameOption->setStyleSheet(QString::fromUtf8("QFrame#frameOption{\n"
"	background:qlineargradient(spread:reflect, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(200, 200, 200, 255), stop:1 rgba(164, 164, 164, 255));\n"
"}\n"
"\n"
"QLabel{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit {   \n"
"	border: 1px solid white;\n"
"	selection-background-color: #0A246A;\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"	background: transparent;\n"
"}   \n"
"\n"
"QLineEdit[echoMode=\"3\"] {   \n"
"    lineedit-password-character: 9679;   \n"
"}\n"
"   \n"
"QLineEdit:read-only { \n"
"	color: darkgray;\n"
"    background:transparent;   \n"
"}\n"
"\n"
"QSpinBox, QDoubleSpinBox, QDateTimeEdit {\n"
"	border: 1px solid white;\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"	background: transparent;\n"
"}\n"
"\n"
"QSpinBox::up-button, QDoubleSpinBox::up-button, QDateTimeEdit::up-button {\n"
"	subcontrol-origin:border;\n"
"	subcontr"
                        "ol-position:right;\n"
"	padding-left: 10px;\n"
"	image: url(:/microarray_icons/arrow_right.png);\n"
"	width: 24px;height: 28px; right:5px;\n"
"}\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button, QDateTimeEdit::down-button {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:left;\n"
"	padding-right: 10px;\n"
"	image: url(:/microarray_icons/arrow_left.png);\n"
"	width: 24px;height: 28px; left:5px;\n"
"}\n"
"QSpinBox::up-button:pressed, QDoubleSpinBox::up-button:pressed, QDateTimeEdit::up-button:pressed {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:right;\n"
"	image: url(:/microarray_icons/arrow_right.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::down-button:pressed, QDoubleSpinBox::down-button:pressed, QDateTimeEdit::down-button:pressed {\n"
"	subcontrol-position:left;\n"
"	image: url(:/microarray_icons/arrow_left.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::disabled, QDoubleSpinBox::disabled, QDateTimeEdit::disabled {\n"
"	color:darkgray;\n"
"}"));
        frameOption->setFrameShape(QFrame::NoFrame);
        frameOption->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frameOption);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 40, -1, -1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelDyeName = new QLabel(frameOption);
        labelDyeName->setObjectName(QStringLiteral("labelDyeName"));
        labelDyeName->setMinimumSize(QSize(0, 48));

        horizontalLayout_5->addWidget(labelDyeName);

        lineEditDyeName = new QLineEdit(frameOption);
        lineEditDyeName->setObjectName(QStringLiteral("lineEditDyeName"));
        lineEditDyeName->setMinimumSize(QSize(0, 48));

        horizontalLayout_5->addWidget(lineEditDyeName);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(20);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setVerticalSpacing(30);
        labelWaveLength = new QLabel(frameOption);
        labelWaveLength->setObjectName(QStringLiteral("labelWaveLength"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelWaveLength);

        spinBoxWaveLength = new QSpinBox(frameOption);
        spinBoxWaveLength->setObjectName(QStringLiteral("spinBoxWaveLength"));
        spinBoxWaveLength->setMinimumSize(QSize(0, 48));
        spinBoxWaveLength->setAlignment(Qt::AlignCenter);
        spinBoxWaveLength->setMinimum(190);
        spinBoxWaveLength->setMaximum(850);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBoxWaveLength);

        labelMcm = new QLabel(frameOption);
        labelMcm->setObjectName(QStringLiteral("labelMcm"));
        labelMcm->setMinimumSize(QSize(0, 48));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelMcm);

        doubleSpinBoxMcm = new QDoubleSpinBox(frameOption);
        doubleSpinBoxMcm->setObjectName(QStringLiteral("doubleSpinBoxMcm"));
        doubleSpinBoxMcm->setMinimumSize(QSize(0, 48));
        doubleSpinBoxMcm->setAlignment(Qt::AlignCenter);
        doubleSpinBoxMcm->setMaximum(1.67772e+7);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, doubleSpinBoxMcm);


        horizontalLayout_6->addLayout(formLayout_2);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setVerticalSpacing(30);
        formLayout->setContentsMargins(0, 0, 0, -1);
        label260 = new QLabel(frameOption);
        label260->setObjectName(QStringLiteral("label260"));
        label260->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(1, QFormLayout::LabelRole, label260);

        doubleSpinBox260 = new QDoubleSpinBox(frameOption);
        doubleSpinBox260->setObjectName(QStringLiteral("doubleSpinBox260"));
        doubleSpinBox260->setMinimumSize(QSize(0, 48));
        doubleSpinBox260->setAlignment(Qt::AlignCenter);
        doubleSpinBox260->setMaximum(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, doubleSpinBox260);

        label280 = new QLabel(frameOption);
        label280->setObjectName(QStringLiteral("label280"));
        label280->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(2, QFormLayout::LabelRole, label280);

        doubleSpinBox280 = new QDoubleSpinBox(frameOption);
        doubleSpinBox280->setObjectName(QStringLiteral("doubleSpinBox280"));
        doubleSpinBox280->setMinimumSize(QSize(0, 48));
        doubleSpinBox280->setAlignment(Qt::AlignCenter);
        doubleSpinBox280->setMaximum(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, doubleSpinBox280);


        horizontalLayout_6->addLayout(formLayout);

        horizontalLayout_6->setStretch(0, 4);
        horizontalLayout_6->setStretch(1, 3);

        verticalLayout_4->addLayout(horizontalLayout_6);


        verticalLayout->addWidget(frameOption);

        frameBtnBox_a = new QFrame(pageAdd);
        frameBtnBox_a->setObjectName(QStringLiteral("frameBtnBox_a"));
        frameBtnBox_a->setMinimumSize(QSize(0, 55));
        frameBtnBox_a->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QToolButton::disabled{\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QFrame#frameBtnBox_a {\n"
"	background-color: rgb(85, 0, 127);\n"
"}\n"
"\n"
"QLabel{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameBtnBox_a->setFrameShape(QFrame::NoFrame);
        frameBtnBox_a->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameBtnBox_a);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(277, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButtonCancel_a = new QToolButton(frameBtnBox_a);
        toolButtonCancel_a->setObjectName(QStringLiteral("toolButtonCancel_a"));
        sizePolicy1.setHeightForWidth(toolButtonCancel_a->sizePolicy().hasHeightForWidth());
        toolButtonCancel_a->setSizePolicy(sizePolicy1);
        toolButtonCancel_a->setMinimumSize(QSize(180, 0));
        toolButtonCancel_a->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonCancel_a);

        toolButtonOk_a = new QToolButton(frameBtnBox_a);
        toolButtonOk_a->setObjectName(QStringLiteral("toolButtonOk_a"));
        sizePolicy1.setHeightForWidth(toolButtonOk_a->sizePolicy().hasHeightForWidth());
        toolButtonOk_a->setSizePolicy(sizePolicy1);
        toolButtonOk_a->setMinimumSize(QSize(180, 0));
        toolButtonOk_a->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonOk_a);


        verticalLayout->addWidget(frameBtnBox_a);

        verticalLayout->setStretch(0, 1);
        stackedWidget->addWidget(pageAdd);
        pageRemove = new QWidget();
        pageRemove->setObjectName(QStringLiteral("pageRemove"));
        verticalLayout_2 = new QVBoxLayout(pageRemove);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frameTable_r = new QFrame(pageRemove);
        frameTable_r->setObjectName(QStringLiteral("frameTable_r"));
        frameTable_r->setFrameShape(QFrame::NoFrame);
        frameTable_r->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frameTable_r);

        frameBtnBox_r = new QFrame(pageRemove);
        frameBtnBox_r->setObjectName(QStringLiteral("frameBtnBox_r"));
        frameBtnBox_r->setMinimumSize(QSize(0, 55));
        frameBtnBox_r->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QToolButton::disabled{\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QFrame#frameBtnBox_r {\n"
"	background-color: rgb(85, 0, 127);\n"
"}\n"
"\n"
"QLabel{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameBtnBox_r->setFrameShape(QFrame::NoFrame);
        frameBtnBox_r->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frameBtnBox_r);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButtonCheckAll_r = new QRadioButton(frameBtnBox_r);
        radioButtonCheckAll_r->setObjectName(QStringLiteral("radioButtonCheckAll_r"));
        sizePolicy.setHeightForWidth(radioButtonCheckAll_r->sizePolicy().hasHeightForWidth());
        radioButtonCheckAll_r->setSizePolicy(sizePolicy);
        radioButtonCheckAll_r->setMinimumSize(QSize(180, 0));

        horizontalLayout_3->addWidget(radioButtonCheckAll_r);

        horizontalSpacer_2 = new QSpacerItem(388, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        toolButtonCancel_r = new QToolButton(frameBtnBox_r);
        toolButtonCancel_r->setObjectName(QStringLiteral("toolButtonCancel_r"));
        sizePolicy1.setHeightForWidth(toolButtonCancel_r->sizePolicy().hasHeightForWidth());
        toolButtonCancel_r->setSizePolicy(sizePolicy1);
        toolButtonCancel_r->setMinimumSize(QSize(180, 0));
        toolButtonCancel_r->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButtonCancel_r);

        toolButtonOk_r = new QToolButton(frameBtnBox_r);
        toolButtonOk_r->setObjectName(QStringLiteral("toolButtonOk_r"));
        sizePolicy1.setHeightForWidth(toolButtonOk_r->sizePolicy().hasHeightForWidth());
        toolButtonOk_r->setSizePolicy(sizePolicy1);
        toolButtonOk_r->setMinimumSize(QSize(180, 0));
        toolButtonOk_r->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButtonOk_r);


        verticalLayout_2->addWidget(frameBtnBox_r);

        verticalLayout_2->setStretch(0, 1);
        stackedWidget->addWidget(pageRemove);

        horizontalLayout->addWidget(stackedWidget);


        retranslateUi(MADyeWidget);

        QMetaObject::connectSlotsByName(MADyeWidget);
    } // setupUi

    void retranslateUi(QFrame *MADyeWidget)
    {
        MADyeWidget->setWindowTitle(QApplication::translate("MADyeWidget", "Frame", 0));
        radioButtonCheckAll_l->setText(QApplication::translate("MADyeWidget", "Check All", 0));
        toolButtonAdd->setText(QApplication::translate("MADyeWidget", "Add", 0));
        toolButtonRemove->setText(QApplication::translate("MADyeWidget", "Remove", 0));
        labelDyeName->setText(QApplication::translate("MADyeWidget", "Dye Name:", 0));
        labelWaveLength->setText(QApplication::translate("MADyeWidget", "Wave Length:", 0));
        spinBoxWaveLength->setSuffix(QApplication::translate("MADyeWidget", " nm", 0));
        labelMcm->setText(QApplication::translate("MADyeWidget", "1/M*cm:", 0));
        label260->setText(QApplication::translate("MADyeWidget", "260n%:", 0));
        label280->setText(QApplication::translate("MADyeWidget", "280n%:", 0));
        toolButtonCancel_a->setText(QApplication::translate("MADyeWidget", "Cancel", 0));
        toolButtonOk_a->setText(QApplication::translate("MADyeWidget", "Add", 0));
        radioButtonCheckAll_r->setText(QApplication::translate("MADyeWidget", "Check All", 0));
        toolButtonCancel_r->setText(QApplication::translate("MADyeWidget", "Cancel", 0));
        toolButtonOk_r->setText(QApplication::translate("MADyeWidget", "Remove", 0));
    } // retranslateUi

};

namespace Ui {
    class MADyeWidget: public Ui_MADyeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MADYEWIDGET_H
