/********************************************************************************
** Form generated from reading UI file 'naparameterwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAPARAMETERWIDGET_H
#define UI_NAPARAMETERWIDGET_H

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

class Ui_NAParameterWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *labelMwl;
    QSpinBox *spinBoxMwl;
    QLabel *labelChannelNumber;
    QSpinBox *spinBoxChannelNumber;
    QLabel *labelMeasureOptical;
    QComboBox *comboBoxMeasureOptical;
    QLabel *labelUnit;
    QComboBox *comboBoxUnit;
    QLabel *labelMethod;
    QComboBox *comboBoxMethod;
    QLabel *labelCoefficient;
    QDoubleSpinBox *doubleSpinBoxCoefficient;
    QLabel *labelMixingLevel;
    QComboBox *comboBoxMixingLevel;
    QLabel *labelMixingTime;
    QSpinBox *spinBoxMixingTime;
    QLabel *labelStaticTime;
    QSpinBox *spinBoxStaticTime;
    QLabel *labelBwl;
    QSpinBox *spinBoxBwl;
    QLabel *labelSampleName;
    QLineEdit *lineEditSampleName;
    QLabel *labelDetectionMothed;
    QComboBox *comboBoxDetectionMothed;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *NAParameterWidget)
    {
        if (NAParameterWidget->objectName().isEmpty())
            NAParameterWidget->setObjectName(QStringLiteral("NAParameterWidget"));
        NAParameterWidget->resize(511, 1050);
        NAParameterWidget->setStyleSheet(QString::fromUtf8("QFrame#NAParameterWidget{\n"
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
"	image: url(:/nucleicacidwind"
                        "ow_icons/arrow_right.png);\n"
"	width: 24px;height: 28px; right:5px;\n"
"}\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button, QDateTimeEdit::down-button {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:left;\n"
"	padding-right: 10px;\n"
"	image: url(:/nucleicacidwindow_icons/arrow_left.png);\n"
"	width: 24px;height: 28px; left:5px;\n"
"}\n"
"QSpinBox::up-button:pressed, QDoubleSpinBox::up-button:pressed, QDateTimeEdit::up-button:pressed {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:right;\n"
"	image: url(:/nucleicacidwindow_icons/arrow_right.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::down-button:pressed, QDoubleSpinBox::down-button:pressed, QDateTimeEdit::down-button:pressed {\n"
"	subcontrol-position:left;\n"
"	image: url(:/nucleicacidwindow_icons/arrow_left.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::disabled, QDoubleSpinBox::disabled, QDateTimeEdit::disabled {\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QComboBox {\n"
"	border: 1px solid white;\n"
"	padding: 1px "
                        "18px 1px 3px;\n"
"	min-width: 6em;\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
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
"	image: url(:/nucleicacidwindow_icons/arrow_down.png);\n"
"	width: 24px;height: 28px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { \n"
"	top: 1px;left: 1px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	color:"
                        " white;\n"
"	border:0px solid white;\n"
"	selection-background-color: rgba(255, 255, 255, 50);\n"
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
        NAParameterWidget->setFrameShape(QFrame::StyledPanel);
        NAParameterWidget->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(NAParameterWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setVerticalSpacing(30);
        labelMwl = new QLabel(NAParameterWidget);
        labelMwl->setObjectName(QStringLiteral("labelMwl"));
        labelMwl->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelMwl);

        spinBoxMwl = new QSpinBox(NAParameterWidget);
        spinBoxMwl->setObjectName(QStringLiteral("spinBoxMwl"));
        spinBoxMwl->setMinimumSize(QSize(0, 48));
        spinBoxMwl->setAlignment(Qt::AlignCenter);
        spinBoxMwl->setMinimum(190);
        spinBoxMwl->setMaximum(850);
        spinBoxMwl->setValue(260);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxMwl);

        labelChannelNumber = new QLabel(NAParameterWidget);
        labelChannelNumber->setObjectName(QStringLiteral("labelChannelNumber"));
        labelChannelNumber->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelChannelNumber);

        spinBoxChannelNumber = new QSpinBox(NAParameterWidget);
        spinBoxChannelNumber->setObjectName(QStringLiteral("spinBoxChannelNumber"));
        spinBoxChannelNumber->setMinimumSize(QSize(0, 48));
        spinBoxChannelNumber->setAlignment(Qt::AlignCenter);
        spinBoxChannelNumber->setMinimum(1);
        spinBoxChannelNumber->setMaximum(1);
        spinBoxChannelNumber->setValue(1);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBoxChannelNumber);

        labelMeasureOptical = new QLabel(NAParameterWidget);
        labelMeasureOptical->setObjectName(QStringLiteral("labelMeasureOptical"));
        labelMeasureOptical->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelMeasureOptical);

        comboBoxMeasureOptical = new QComboBox(NAParameterWidget);
        comboBoxMeasureOptical->setObjectName(QStringLiteral("comboBoxMeasureOptical"));
        comboBoxMeasureOptical->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBoxMeasureOptical);

        labelUnit = new QLabel(NAParameterWidget);
        labelUnit->setObjectName(QStringLiteral("labelUnit"));
        labelUnit->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(6, QFormLayout::LabelRole, labelUnit);

        comboBoxUnit = new QComboBox(NAParameterWidget);
        comboBoxUnit->setObjectName(QStringLiteral("comboBoxUnit"));
        comboBoxUnit->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBoxUnit);

        labelMethod = new QLabel(NAParameterWidget);
        labelMethod->setObjectName(QStringLiteral("labelMethod"));
        labelMethod->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelMethod);

        comboBoxMethod = new QComboBox(NAParameterWidget);
        comboBoxMethod->setObjectName(QStringLiteral("comboBoxMethod"));
        comboBoxMethod->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(7, QFormLayout::FieldRole, comboBoxMethod);

        labelCoefficient = new QLabel(NAParameterWidget);
        labelCoefficient->setObjectName(QStringLiteral("labelCoefficient"));
        labelCoefficient->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(8, QFormLayout::LabelRole, labelCoefficient);

        doubleSpinBoxCoefficient = new QDoubleSpinBox(NAParameterWidget);
        doubleSpinBoxCoefficient->setObjectName(QStringLiteral("doubleSpinBoxCoefficient"));
        doubleSpinBoxCoefficient->setMinimumSize(QSize(0, 48));
        doubleSpinBoxCoefficient->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(8, QFormLayout::FieldRole, doubleSpinBoxCoefficient);

        labelMixingLevel = new QLabel(NAParameterWidget);
        labelMixingLevel->setObjectName(QStringLiteral("labelMixingLevel"));
        labelMixingLevel->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(9, QFormLayout::LabelRole, labelMixingLevel);

        comboBoxMixingLevel = new QComboBox(NAParameterWidget);
        comboBoxMixingLevel->setObjectName(QStringLiteral("comboBoxMixingLevel"));
        comboBoxMixingLevel->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(9, QFormLayout::FieldRole, comboBoxMixingLevel);

        labelMixingTime = new QLabel(NAParameterWidget);
        labelMixingTime->setObjectName(QStringLiteral("labelMixingTime"));
        labelMixingTime->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(10, QFormLayout::LabelRole, labelMixingTime);

        spinBoxMixingTime = new QSpinBox(NAParameterWidget);
        spinBoxMixingTime->setObjectName(QStringLiteral("spinBoxMixingTime"));
        spinBoxMixingTime->setMinimumSize(QSize(0, 48));
        spinBoxMixingTime->setAlignment(Qt::AlignCenter);
        spinBoxMixingTime->setMaximum(16777215);

        formLayout->setWidget(10, QFormLayout::FieldRole, spinBoxMixingTime);

        labelStaticTime = new QLabel(NAParameterWidget);
        labelStaticTime->setObjectName(QStringLiteral("labelStaticTime"));
        labelStaticTime->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(11, QFormLayout::LabelRole, labelStaticTime);

        spinBoxStaticTime = new QSpinBox(NAParameterWidget);
        spinBoxStaticTime->setObjectName(QStringLiteral("spinBoxStaticTime"));
        spinBoxStaticTime->setMinimumSize(QSize(0, 48));
        spinBoxStaticTime->setAlignment(Qt::AlignCenter);
        spinBoxStaticTime->setMaximum(16777215);

        formLayout->setWidget(11, QFormLayout::FieldRole, spinBoxStaticTime);

        labelBwl = new QLabel(NAParameterWidget);
        labelBwl->setObjectName(QStringLiteral("labelBwl"));
        labelBwl->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelBwl);

        spinBoxBwl = new QSpinBox(NAParameterWidget);
        spinBoxBwl->setObjectName(QStringLiteral("spinBoxBwl"));
        spinBoxBwl->setMinimumSize(QSize(0, 48));
        spinBoxBwl->setAlignment(Qt::AlignCenter);
        spinBoxBwl->setMinimum(190);
        spinBoxBwl->setMaximum(850);
        spinBoxBwl->setValue(340);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxBwl);

        labelSampleName = new QLabel(NAParameterWidget);
        labelSampleName->setObjectName(QStringLiteral("labelSampleName"));
        labelSampleName->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelSampleName);

        lineEditSampleName = new QLineEdit(NAParameterWidget);
        lineEditSampleName->setObjectName(QStringLiteral("lineEditSampleName"));
        lineEditSampleName->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditSampleName);

        labelDetectionMothed = new QLabel(NAParameterWidget);
        labelDetectionMothed->setObjectName(QStringLiteral("labelDetectionMothed"));
        labelDetectionMothed->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelDetectionMothed);

        comboBoxDetectionMothed = new QComboBox(NAParameterWidget);
        comboBoxDetectionMothed->setObjectName(QStringLiteral("comboBoxDetectionMothed"));
        comboBoxDetectionMothed->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxDetectionMothed);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 113, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(NAParameterWidget);

        QMetaObject::connectSlotsByName(NAParameterWidget);
    } // setupUi

    void retranslateUi(QFrame *NAParameterWidget)
    {
        NAParameterWidget->setWindowTitle(QApplication::translate("NAParameterWidget", "Frame", 0));
        labelMwl->setText(QApplication::translate("NAParameterWidget", "Measure Wave Length:", 0));
        spinBoxMwl->setSuffix(QApplication::translate("NAParameterWidget", " nm", 0));
        labelChannelNumber->setText(QApplication::translate("NAParameterWidget", "Channel Number:", 0));
        labelMeasureOptical->setText(QApplication::translate("NAParameterWidget", "Measure Optical:", 0));
        labelUnit->setText(QApplication::translate("NAParameterWidget", "Used Unit:", 0));
        labelMethod->setText(QApplication::translate("NAParameterWidget", "Method:", 0));
        labelCoefficient->setText(QApplication::translate("NAParameterWidget", "Coefficient:", 0));
        labelMixingLevel->setText(QApplication::translate("NAParameterWidget", "Mixing Level:", 0));
        labelMixingTime->setText(QApplication::translate("NAParameterWidget", "Mixing Time:", 0));
        spinBoxMixingTime->setSuffix(QApplication::translate("NAParameterWidget", " s", 0));
        labelStaticTime->setText(QApplication::translate("NAParameterWidget", "Static Time:", 0));
        spinBoxStaticTime->setSuffix(QApplication::translate("NAParameterWidget", " s", 0));
        labelBwl->setText(QApplication::translate("NAParameterWidget", "Base Wave Length:", 0));
        spinBoxBwl->setSuffix(QApplication::translate("NAParameterWidget", " nm", 0));
        labelSampleName->setText(QApplication::translate("NAParameterWidget", "Sample Name:", 0));
        lineEditSampleName->setText(QApplication::translate("NAParameterWidget", "Sample", 0));
        labelDetectionMothed->setText(QApplication::translate("NAParameterWidget", "Detection Method:", 0));
    } // retranslateUi

};

namespace Ui {
    class NAParameterWidget: public Ui_NAParameterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAPARAMETERWIDGET_H
