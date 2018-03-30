/********************************************************************************
** Form generated from reading UI file 'uvparameterwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UVPARAMETERWIDGET_H
#define UI_UVPARAMETERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UVParameterWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelDetectionMothed;
    QComboBox *comboBoxDetectionMothed;
    QLabel *labelSampleName;
    QLineEdit *lineEditSampleName;
    QLabel *labelBwl;
    QSpinBox *spinBoxBwl;
    QLabel *labelMwl1;
    QSpinBox *spinBoxMwl1;
    QLabel *labelCoef1;
    QDoubleSpinBox *doubleSpinBoxCoef1;
    QLabel *labelMwl2;
    QSpinBox *spinBoxMwl2;
    QLabel *labelCoef2;
    QDoubleSpinBox *doubleSpinBoxCoef2;
    QLabel *labelMwl3;
    QSpinBox *spinBoxMwl3;
    QLabel *labelCoef3;
    QDoubleSpinBox *doubleSpinBoxCoef3;
    QLabel *labelMwl4;
    QSpinBox *spinBoxMwl4;
    QLabel *labelCoef4;
    QDoubleSpinBox *doubleSpinBoxCoef4;
    QLabel *labelMwl5;
    QSpinBox *spinBoxMwl5;
    QLabel *labelCoef5;
    QDoubleSpinBox *doubleSpinBoxCoef5;
    QLabel *labelMixingLevel;
    QComboBox *comboBoxMixingLevel;
    QLabel *labelMixingTime;
    QSpinBox *spinBoxMixingTime;
    QLabel *labelStaticTime;
    QSpinBox *spinBoxStaticTime;
    QLabel *labelChannelNumber;
    QSpinBox *spinBoxChannelNumber;
    QLabel *labelMeasureOptical;
    QComboBox *comboBoxMeasureOptical;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *UVParameterWidget)
    {
        if (UVParameterWidget->objectName().isEmpty())
            UVParameterWidget->setObjectName(QStringLiteral("UVParameterWidget"));
        UVParameterWidget->resize(496, 1462);
        UVParameterWidget->setStyleSheet(QString::fromUtf8("QFrame#UVParameterWidget{\n"
"	background:transparent;\n"
"}\n"
"\n"
"QLabel{\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"	background: transparent;\n"
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
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"	background: transparent;\n"
"}\n"
"\n"
"QSpinBox::up-button, QDoubleSpinBox::up-button, QDateTimeEdit::up-button {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:right;\n"
"	padding-left: 10px;\n"
"	image: url(:/uvvis_icons/arr"
                        "ow_right.png);\n"
"	width: 24px;height: 28px; right:5px;\n"
"}\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button, QDateTimeEdit::down-button {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:left;\n"
"	padding-right: 10px;\n"
"	image: url(:/uvvis_icons/arrow_left.png);\n"
"	width: 24px;height: 28px; left:5px;\n"
"}\n"
"QSpinBox::up-button:pressed, QDoubleSpinBox::up-button:pressed, QDateTimeEdit::up-button:pressed {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:right;\n"
"	image: url(:/uvvis_icons/arrow_right.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::down-button:pressed, QDoubleSpinBox::down-button:pressed, QDateTimeEdit::down-button:pressed {\n"
"	subcontrol-position:left;\n"
"	image: url(:/uvvis_icons/arrow_left.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::disabled, QDoubleSpinBox::disabled, QDateTimeEdit::disabled {\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QComboBox {\n"
"	border: 1px solid white;\n"
"	padding: 1px 18px 1px 3px;\n"
"	min-width: 6em;\n"
"	font: 12"
                        "pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color:white;\n"
"}\n"
"\n"
"QComboBox::hover{\n"
"	padding-top: 3px;\n"
"	padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox:editable {\n"
"	background: white;\n"
"}\n"
"\n"
"QComboBox:!editable, QComboBox::drop-down:editable {\n"
"	background: transparent;\n"
"}\n"
"\n"
"QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"	background: transparent;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	padding-top: 3px;padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	subcontrol-origin: padding;\n"
"	subcontrol-position: right;\n"
"	border: 0px solid white;\n"
"	width:40px;height:40px;\n"
"	border-top-right-radius: 3px;\n"
"	border-bottom-right-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/uvvis_icons/arrow_down.png);\n"
"	width: 24px;height: 28px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { \n"
"	top: 1px;left: 1px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	color: white;\n"
"	border:0px solid white;\n"
"	selection-backgrou"
                        "nd-color: rgba(255, 255, 255, 50);\n"
"	background: blue;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item { \n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	min-height: 48px;\n"
"	min-width: 60px;\n"
"}\n"
"QGroupBox {\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"	color: white;\n"
"}"));
        UVParameterWidget->setFrameShape(QFrame::StyledPanel);
        UVParameterWidget->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(UVParameterWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setVerticalSpacing(30);
        labelDetectionMothed = new QLabel(UVParameterWidget);
        labelDetectionMothed->setObjectName(QStringLiteral("labelDetectionMothed"));
        labelDetectionMothed->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelDetectionMothed);

        comboBoxDetectionMothed = new QComboBox(UVParameterWidget);
        comboBoxDetectionMothed->setObjectName(QStringLiteral("comboBoxDetectionMothed"));
        comboBoxDetectionMothed->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxDetectionMothed);

        labelSampleName = new QLabel(UVParameterWidget);
        labelSampleName->setObjectName(QStringLiteral("labelSampleName"));
        labelSampleName->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelSampleName);

        lineEditSampleName = new QLineEdit(UVParameterWidget);
        lineEditSampleName->setObjectName(QStringLiteral("lineEditSampleName"));
        lineEditSampleName->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditSampleName);

        labelBwl = new QLabel(UVParameterWidget);
        labelBwl->setObjectName(QStringLiteral("labelBwl"));
        labelBwl->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelBwl);

        spinBoxBwl = new QSpinBox(UVParameterWidget);
        spinBoxBwl->setObjectName(QStringLiteral("spinBoxBwl"));
        spinBoxBwl->setMinimumSize(QSize(0, 48));
        spinBoxBwl->setAlignment(Qt::AlignCenter);
        spinBoxBwl->setMinimum(190);
        spinBoxBwl->setMaximum(850);
        spinBoxBwl->setValue(340);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxBwl);

        labelMwl1 = new QLabel(UVParameterWidget);
        labelMwl1->setObjectName(QStringLiteral("labelMwl1"));
        labelMwl1->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelMwl1);

        spinBoxMwl1 = new QSpinBox(UVParameterWidget);
        spinBoxMwl1->setObjectName(QStringLiteral("spinBoxMwl1"));
        spinBoxMwl1->setMinimumSize(QSize(0, 48));
        spinBoxMwl1->setAlignment(Qt::AlignCenter);
        spinBoxMwl1->setMinimum(200);
        spinBoxMwl1->setMaximum(850);
        spinBoxMwl1->setValue(200);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxMwl1);

        labelCoef1 = new QLabel(UVParameterWidget);
        labelCoef1->setObjectName(QStringLiteral("labelCoef1"));
        labelCoef1->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(6, QFormLayout::LabelRole, labelCoef1);

        doubleSpinBoxCoef1 = new QDoubleSpinBox(UVParameterWidget);
        doubleSpinBoxCoef1->setObjectName(QStringLiteral("doubleSpinBoxCoef1"));
        doubleSpinBoxCoef1->setMinimumSize(QSize(0, 48));
        doubleSpinBoxCoef1->setAlignment(Qt::AlignCenter);
        doubleSpinBoxCoef1->setMinimum(1);
        doubleSpinBoxCoef1->setMaximum(1.67772e+7);

        formLayout->setWidget(6, QFormLayout::FieldRole, doubleSpinBoxCoef1);

        labelMwl2 = new QLabel(UVParameterWidget);
        labelMwl2->setObjectName(QStringLiteral("labelMwl2"));
        labelMwl2->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelMwl2);

        spinBoxMwl2 = new QSpinBox(UVParameterWidget);
        spinBoxMwl2->setObjectName(QStringLiteral("spinBoxMwl2"));
        spinBoxMwl2->setMinimumSize(QSize(0, 48));
        spinBoxMwl2->setAlignment(Qt::AlignCenter);
        spinBoxMwl2->setMinimum(200);
        spinBoxMwl2->setMaximum(850);
        spinBoxMwl2->setValue(200);

        formLayout->setWidget(7, QFormLayout::FieldRole, spinBoxMwl2);

        labelCoef2 = new QLabel(UVParameterWidget);
        labelCoef2->setObjectName(QStringLiteral("labelCoef2"));
        labelCoef2->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(8, QFormLayout::LabelRole, labelCoef2);

        doubleSpinBoxCoef2 = new QDoubleSpinBox(UVParameterWidget);
        doubleSpinBoxCoef2->setObjectName(QStringLiteral("doubleSpinBoxCoef2"));
        doubleSpinBoxCoef2->setMinimumSize(QSize(0, 48));
        doubleSpinBoxCoef2->setAlignment(Qt::AlignCenter);
        doubleSpinBoxCoef2->setMinimum(1);
        doubleSpinBoxCoef2->setMaximum(1.67772e+7);

        formLayout->setWidget(8, QFormLayout::FieldRole, doubleSpinBoxCoef2);

        labelMwl3 = new QLabel(UVParameterWidget);
        labelMwl3->setObjectName(QStringLiteral("labelMwl3"));
        labelMwl3->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(9, QFormLayout::LabelRole, labelMwl3);

        spinBoxMwl3 = new QSpinBox(UVParameterWidget);
        spinBoxMwl3->setObjectName(QStringLiteral("spinBoxMwl3"));
        spinBoxMwl3->setMinimumSize(QSize(0, 48));
        spinBoxMwl3->setAlignment(Qt::AlignCenter);
        spinBoxMwl3->setMinimum(200);
        spinBoxMwl3->setMaximum(850);
        spinBoxMwl3->setValue(200);

        formLayout->setWidget(9, QFormLayout::FieldRole, spinBoxMwl3);

        labelCoef3 = new QLabel(UVParameterWidget);
        labelCoef3->setObjectName(QStringLiteral("labelCoef3"));
        labelCoef3->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(10, QFormLayout::LabelRole, labelCoef3);

        doubleSpinBoxCoef3 = new QDoubleSpinBox(UVParameterWidget);
        doubleSpinBoxCoef3->setObjectName(QStringLiteral("doubleSpinBoxCoef3"));
        doubleSpinBoxCoef3->setMinimumSize(QSize(0, 48));
        doubleSpinBoxCoef3->setAlignment(Qt::AlignCenter);
        doubleSpinBoxCoef3->setMinimum(1);
        doubleSpinBoxCoef3->setMaximum(1.67772e+7);

        formLayout->setWidget(10, QFormLayout::FieldRole, doubleSpinBoxCoef3);

        labelMwl4 = new QLabel(UVParameterWidget);
        labelMwl4->setObjectName(QStringLiteral("labelMwl4"));
        labelMwl4->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(11, QFormLayout::LabelRole, labelMwl4);

        spinBoxMwl4 = new QSpinBox(UVParameterWidget);
        spinBoxMwl4->setObjectName(QStringLiteral("spinBoxMwl4"));
        spinBoxMwl4->setMinimumSize(QSize(0, 48));
        spinBoxMwl4->setAlignment(Qt::AlignCenter);
        spinBoxMwl4->setMinimum(200);
        spinBoxMwl4->setMaximum(850);
        spinBoxMwl4->setValue(200);

        formLayout->setWidget(11, QFormLayout::FieldRole, spinBoxMwl4);

        labelCoef4 = new QLabel(UVParameterWidget);
        labelCoef4->setObjectName(QStringLiteral("labelCoef4"));
        labelCoef4->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(12, QFormLayout::LabelRole, labelCoef4);

        doubleSpinBoxCoef4 = new QDoubleSpinBox(UVParameterWidget);
        doubleSpinBoxCoef4->setObjectName(QStringLiteral("doubleSpinBoxCoef4"));
        doubleSpinBoxCoef4->setMinimumSize(QSize(0, 48));
        doubleSpinBoxCoef4->setAlignment(Qt::AlignCenter);
        doubleSpinBoxCoef4->setMinimum(1);
        doubleSpinBoxCoef4->setMaximum(1.67772e+7);

        formLayout->setWidget(12, QFormLayout::FieldRole, doubleSpinBoxCoef4);

        labelMwl5 = new QLabel(UVParameterWidget);
        labelMwl5->setObjectName(QStringLiteral("labelMwl5"));
        labelMwl5->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(13, QFormLayout::LabelRole, labelMwl5);

        spinBoxMwl5 = new QSpinBox(UVParameterWidget);
        spinBoxMwl5->setObjectName(QStringLiteral("spinBoxMwl5"));
        spinBoxMwl5->setMinimumSize(QSize(0, 48));
        spinBoxMwl5->setAlignment(Qt::AlignCenter);
        spinBoxMwl5->setMinimum(200);
        spinBoxMwl5->setMaximum(850);
        spinBoxMwl5->setValue(200);

        formLayout->setWidget(13, QFormLayout::FieldRole, spinBoxMwl5);

        labelCoef5 = new QLabel(UVParameterWidget);
        labelCoef5->setObjectName(QStringLiteral("labelCoef5"));
        labelCoef5->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(14, QFormLayout::LabelRole, labelCoef5);

        doubleSpinBoxCoef5 = new QDoubleSpinBox(UVParameterWidget);
        doubleSpinBoxCoef5->setObjectName(QStringLiteral("doubleSpinBoxCoef5"));
        doubleSpinBoxCoef5->setMinimumSize(QSize(0, 48));
        doubleSpinBoxCoef5->setAlignment(Qt::AlignCenter);
        doubleSpinBoxCoef5->setMinimum(1);
        doubleSpinBoxCoef5->setMaximum(1.67772e+7);

        formLayout->setWidget(14, QFormLayout::FieldRole, doubleSpinBoxCoef5);

        labelMixingLevel = new QLabel(UVParameterWidget);
        labelMixingLevel->setObjectName(QStringLiteral("labelMixingLevel"));
        labelMixingLevel->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(17, QFormLayout::LabelRole, labelMixingLevel);

        comboBoxMixingLevel = new QComboBox(UVParameterWidget);
        comboBoxMixingLevel->setObjectName(QStringLiteral("comboBoxMixingLevel"));
        comboBoxMixingLevel->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(17, QFormLayout::FieldRole, comboBoxMixingLevel);

        labelMixingTime = new QLabel(UVParameterWidget);
        labelMixingTime->setObjectName(QStringLiteral("labelMixingTime"));
        labelMixingTime->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(18, QFormLayout::LabelRole, labelMixingTime);

        spinBoxMixingTime = new QSpinBox(UVParameterWidget);
        spinBoxMixingTime->setObjectName(QStringLiteral("spinBoxMixingTime"));
        spinBoxMixingTime->setMinimumSize(QSize(0, 48));
        spinBoxMixingTime->setAlignment(Qt::AlignCenter);
        spinBoxMixingTime->setMaximum(16777215);

        formLayout->setWidget(18, QFormLayout::FieldRole, spinBoxMixingTime);

        labelStaticTime = new QLabel(UVParameterWidget);
        labelStaticTime->setObjectName(QStringLiteral("labelStaticTime"));
        labelStaticTime->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(19, QFormLayout::LabelRole, labelStaticTime);

        spinBoxStaticTime = new QSpinBox(UVParameterWidget);
        spinBoxStaticTime->setObjectName(QStringLiteral("spinBoxStaticTime"));
        spinBoxStaticTime->setMinimumSize(QSize(0, 48));
        spinBoxStaticTime->setAlignment(Qt::AlignCenter);
        spinBoxStaticTime->setMaximum(16777215);

        formLayout->setWidget(19, QFormLayout::FieldRole, spinBoxStaticTime);

        labelChannelNumber = new QLabel(UVParameterWidget);
        labelChannelNumber->setObjectName(QStringLiteral("labelChannelNumber"));
        labelChannelNumber->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelChannelNumber);

        spinBoxChannelNumber = new QSpinBox(UVParameterWidget);
        spinBoxChannelNumber->setObjectName(QStringLiteral("spinBoxChannelNumber"));
        spinBoxChannelNumber->setMinimumSize(QSize(0, 48));
        spinBoxChannelNumber->setAlignment(Qt::AlignCenter);
        spinBoxChannelNumber->setMinimum(1);
        spinBoxChannelNumber->setMaximum(1);
        spinBoxChannelNumber->setValue(1);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxChannelNumber);

        labelMeasureOptical = new QLabel(UVParameterWidget);
        labelMeasureOptical->setObjectName(QStringLiteral("labelMeasureOptical"));
        labelMeasureOptical->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelMeasureOptical);

        comboBoxMeasureOptical = new QComboBox(UVParameterWidget);
        comboBoxMeasureOptical->setObjectName(QStringLiteral("comboBoxMeasureOptical"));
        comboBoxMeasureOptical->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxMeasureOptical);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 113, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(UVParameterWidget);

        QMetaObject::connectSlotsByName(UVParameterWidget);
    } // setupUi

    void retranslateUi(QFrame *UVParameterWidget)
    {
        UVParameterWidget->setWindowTitle(QApplication::translate("UVParameterWidget", "Frame", 0));
        labelDetectionMothed->setText(QApplication::translate("UVParameterWidget", "Detection Method:", 0));
        labelSampleName->setText(QApplication::translate("UVParameterWidget", "Sample Name:", 0));
        lineEditSampleName->setText(QApplication::translate("UVParameterWidget", "Sample", 0));
        labelBwl->setText(QApplication::translate("UVParameterWidget", "Base Wave Length:", 0));
        spinBoxBwl->setSuffix(QApplication::translate("UVParameterWidget", " nm", 0));
        labelMwl1->setText(QApplication::translate("UVParameterWidget", "Measure Wave Length1:", 0));
        spinBoxMwl1->setSuffix(QApplication::translate("UVParameterWidget", " nm", 0));
        labelCoef1->setText(QApplication::translate("UVParameterWidget", "Coefficient1:", 0));
        labelMwl2->setText(QApplication::translate("UVParameterWidget", "Measure Wave Length2:", 0));
        spinBoxMwl2->setSuffix(QApplication::translate("UVParameterWidget", " nm", 0));
        labelCoef2->setText(QApplication::translate("UVParameterWidget", "Coefficient2:", 0));
        labelMwl3->setText(QApplication::translate("UVParameterWidget", "Measure Wave Length3:", 0));
        spinBoxMwl3->setSuffix(QApplication::translate("UVParameterWidget", " nm", 0));
        labelCoef3->setText(QApplication::translate("UVParameterWidget", "Coefficient3:", 0));
        labelMwl4->setText(QApplication::translate("UVParameterWidget", "Measure Wave Length4:", 0));
        spinBoxMwl4->setSuffix(QApplication::translate("UVParameterWidget", " nm", 0));
        labelCoef4->setText(QApplication::translate("UVParameterWidget", "Coefficient4:", 0));
        labelMwl5->setText(QApplication::translate("UVParameterWidget", "Measure Wave Length5:", 0));
        spinBoxMwl5->setSuffix(QApplication::translate("UVParameterWidget", " nm", 0));
        labelCoef5->setText(QApplication::translate("UVParameterWidget", "Coefficient5:", 0));
        labelMixingLevel->setText(QApplication::translate("UVParameterWidget", "Mixing Level:", 0));
        labelMixingTime->setText(QApplication::translate("UVParameterWidget", "Mixing Time:", 0));
        spinBoxMixingTime->setSuffix(QApplication::translate("UVParameterWidget", " s", 0));
        labelStaticTime->setText(QApplication::translate("UVParameterWidget", "Static Time:", 0));
        spinBoxStaticTime->setSuffix(QApplication::translate("UVParameterWidget", " s", 0));
        labelChannelNumber->setText(QApplication::translate("UVParameterWidget", "Channel Number:", 0));
        labelMeasureOptical->setText(QApplication::translate("UVParameterWidget", "Measure Optical:", 0));
    } // retranslateUi

};

namespace Ui {
    class UVParameterWidget: public Ui_UVParameterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UVPARAMETERWIDGET_H
