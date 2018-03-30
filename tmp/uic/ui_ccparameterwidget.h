/********************************************************************************
** Form generated from reading UI file 'ccparameterwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCPARAMETERWIDGET_H
#define UI_CCPARAMETERWIDGET_H

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

class Ui_CCParameterWidget
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
    QLabel *labelChannelNumber;
    QSpinBox *spinBoxChannelNumber;
    QLabel *labelMeasureOptical;
    QComboBox *comboBoxMeasureOptical;
    QLabel *labelMethod;
    QComboBox *comboBoxMethod;
    QLabel *labelMwl;
    QSpinBox *spinBoxMwl;
    QLabel *labelCoefficient;
    QDoubleSpinBox *doubleSpinBoxCoefficient;
    QLabel *labelMixingLevel;
    QComboBox *comboBoxMixingLevel;
    QLabel *labelMixingTime;
    QSpinBox *spinBoxMixingTime;
    QLabel *labelStaticTime;
    QSpinBox *spinBoxStaticTime;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *CCParameterWidget)
    {
        if (CCParameterWidget->objectName().isEmpty())
            CCParameterWidget->setObjectName(QStringLiteral("CCParameterWidget"));
        CCParameterWidget->resize(511, 1050);
        CCParameterWidget->setStyleSheet(QString::fromUtf8("QFrame#CCParameterWidget{\n"
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
"	image: url(:/cellculture_ico"
                        "ns/arrow_right.png);\n"
"	width: 24px;height: 28px; right:5px;\n"
"}\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button, QDateTimeEdit::down-button {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:left;\n"
"	padding-right: 10px;\n"
"	image: url(:/cellculture_icons/arrow_left.png);\n"
"	width: 24px;height: 28px; left:5px;\n"
"}\n"
"QSpinBox::up-button:pressed, QDoubleSpinBox::up-button:pressed, QDateTimeEdit::up-button:pressed {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:right;\n"
"	image: url(:/cellculture_icons/arrow_right.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::down-button:pressed, QDoubleSpinBox::down-button:pressed, QDateTimeEdit::down-button:pressed {\n"
"	subcontrol-position:left;\n"
"	image: url(:/cellculture_icons/arrow_left.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::disabled, QDoubleSpinBox::disabled, QDateTimeEdit::disabled {\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QComboBox {\n"
"	border: 1px solid white;\n"
"	padding: 1px 18px 1px 3px;\n"
"	min-w"
                        "idth: 6em;\n"
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
"	image: url(:/cellculture_icons/arrow_down.png);\n"
"	width: 24px;height: 28px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { \n"
"	top: 1px;left: 1px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	color: white;\n"
"	border:0px solid "
                        "white;\n"
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
        CCParameterWidget->setFrameShape(QFrame::StyledPanel);
        CCParameterWidget->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(CCParameterWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setVerticalSpacing(30);
        labelDetectionMothed = new QLabel(CCParameterWidget);
        labelDetectionMothed->setObjectName(QStringLiteral("labelDetectionMothed"));
        labelDetectionMothed->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelDetectionMothed);

        comboBoxDetectionMothed = new QComboBox(CCParameterWidget);
        comboBoxDetectionMothed->setObjectName(QStringLiteral("comboBoxDetectionMothed"));
        comboBoxDetectionMothed->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxDetectionMothed);

        labelSampleName = new QLabel(CCParameterWidget);
        labelSampleName->setObjectName(QStringLiteral("labelSampleName"));
        labelSampleName->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelSampleName);

        lineEditSampleName = new QLineEdit(CCParameterWidget);
        lineEditSampleName->setObjectName(QStringLiteral("lineEditSampleName"));
        lineEditSampleName->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditSampleName);

        labelBwl = new QLabel(CCParameterWidget);
        labelBwl->setObjectName(QStringLiteral("labelBwl"));
        labelBwl->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelBwl);

        spinBoxBwl = new QSpinBox(CCParameterWidget);
        spinBoxBwl->setObjectName(QStringLiteral("spinBoxBwl"));
        spinBoxBwl->setMinimumSize(QSize(0, 48));
        spinBoxBwl->setAlignment(Qt::AlignCenter);
        spinBoxBwl->setMinimum(190);
        spinBoxBwl->setMaximum(850);
        spinBoxBwl->setValue(340);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxBwl);

        labelChannelNumber = new QLabel(CCParameterWidget);
        labelChannelNumber->setObjectName(QStringLiteral("labelChannelNumber"));
        labelChannelNumber->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelChannelNumber);

        spinBoxChannelNumber = new QSpinBox(CCParameterWidget);
        spinBoxChannelNumber->setObjectName(QStringLiteral("spinBoxChannelNumber"));
        spinBoxChannelNumber->setMinimumSize(QSize(0, 48));
        spinBoxChannelNumber->setAlignment(Qt::AlignCenter);
        spinBoxChannelNumber->setMinimum(1);
        spinBoxChannelNumber->setMaximum(1);
        spinBoxChannelNumber->setValue(1);

        formLayout->setWidget(4, QFormLayout::FieldRole, spinBoxChannelNumber);

        labelMeasureOptical = new QLabel(CCParameterWidget);
        labelMeasureOptical->setObjectName(QStringLiteral("labelMeasureOptical"));
        labelMeasureOptical->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelMeasureOptical);

        comboBoxMeasureOptical = new QComboBox(CCParameterWidget);
        comboBoxMeasureOptical->setObjectName(QStringLiteral("comboBoxMeasureOptical"));
        comboBoxMeasureOptical->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBoxMeasureOptical);

        labelMethod = new QLabel(CCParameterWidget);
        labelMethod->setObjectName(QStringLiteral("labelMethod"));
        labelMethod->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(6, QFormLayout::LabelRole, labelMethod);

        comboBoxMethod = new QComboBox(CCParameterWidget);
        comboBoxMethod->setObjectName(QStringLiteral("comboBoxMethod"));
        comboBoxMethod->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(6, QFormLayout::FieldRole, comboBoxMethod);

        labelMwl = new QLabel(CCParameterWidget);
        labelMwl->setObjectName(QStringLiteral("labelMwl"));
        labelMwl->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelMwl);

        spinBoxMwl = new QSpinBox(CCParameterWidget);
        spinBoxMwl->setObjectName(QStringLiteral("spinBoxMwl"));
        spinBoxMwl->setMinimumSize(QSize(0, 48));
        spinBoxMwl->setAlignment(Qt::AlignCenter);
        spinBoxMwl->setMinimum(190);
        spinBoxMwl->setMaximum(850);
        spinBoxMwl->setValue(260);

        formLayout->setWidget(7, QFormLayout::FieldRole, spinBoxMwl);

        labelCoefficient = new QLabel(CCParameterWidget);
        labelCoefficient->setObjectName(QStringLiteral("labelCoefficient"));
        labelCoefficient->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(8, QFormLayout::LabelRole, labelCoefficient);

        doubleSpinBoxCoefficient = new QDoubleSpinBox(CCParameterWidget);
        doubleSpinBoxCoefficient->setObjectName(QStringLiteral("doubleSpinBoxCoefficient"));
        doubleSpinBoxCoefficient->setMinimumSize(QSize(0, 48));
        doubleSpinBoxCoefficient->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(8, QFormLayout::FieldRole, doubleSpinBoxCoefficient);

        labelMixingLevel = new QLabel(CCParameterWidget);
        labelMixingLevel->setObjectName(QStringLiteral("labelMixingLevel"));
        labelMixingLevel->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(9, QFormLayout::LabelRole, labelMixingLevel);

        comboBoxMixingLevel = new QComboBox(CCParameterWidget);
        comboBoxMixingLevel->setObjectName(QStringLiteral("comboBoxMixingLevel"));
        comboBoxMixingLevel->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(9, QFormLayout::FieldRole, comboBoxMixingLevel);

        labelMixingTime = new QLabel(CCParameterWidget);
        labelMixingTime->setObjectName(QStringLiteral("labelMixingTime"));
        labelMixingTime->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(10, QFormLayout::LabelRole, labelMixingTime);

        spinBoxMixingTime = new QSpinBox(CCParameterWidget);
        spinBoxMixingTime->setObjectName(QStringLiteral("spinBoxMixingTime"));
        spinBoxMixingTime->setMinimumSize(QSize(0, 48));
        spinBoxMixingTime->setAlignment(Qt::AlignCenter);
        spinBoxMixingTime->setMaximum(16777215);

        formLayout->setWidget(10, QFormLayout::FieldRole, spinBoxMixingTime);

        labelStaticTime = new QLabel(CCParameterWidget);
        labelStaticTime->setObjectName(QStringLiteral("labelStaticTime"));
        labelStaticTime->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(11, QFormLayout::LabelRole, labelStaticTime);

        spinBoxStaticTime = new QSpinBox(CCParameterWidget);
        spinBoxStaticTime->setObjectName(QStringLiteral("spinBoxStaticTime"));
        spinBoxStaticTime->setMinimumSize(QSize(0, 48));
        spinBoxStaticTime->setAlignment(Qt::AlignCenter);
        spinBoxStaticTime->setMaximum(16777215);

        formLayout->setWidget(11, QFormLayout::FieldRole, spinBoxStaticTime);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 113, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(CCParameterWidget);

        QMetaObject::connectSlotsByName(CCParameterWidget);
    } // setupUi

    void retranslateUi(QFrame *CCParameterWidget)
    {
        CCParameterWidget->setWindowTitle(QApplication::translate("CCParameterWidget", "Frame", 0));
        labelDetectionMothed->setText(QApplication::translate("CCParameterWidget", "Detection Method:", 0));
        labelSampleName->setText(QApplication::translate("CCParameterWidget", "Sample Name:", 0));
        lineEditSampleName->setText(QApplication::translate("CCParameterWidget", "Sample", 0));
        labelBwl->setText(QApplication::translate("CCParameterWidget", "Base Wave Length:", 0));
        spinBoxBwl->setSuffix(QApplication::translate("CCParameterWidget", " nm", 0));
        labelChannelNumber->setText(QApplication::translate("CCParameterWidget", "Channel Number:", 0));
        labelMeasureOptical->setText(QApplication::translate("CCParameterWidget", "Measure Optical:", 0));
        labelMethod->setText(QApplication::translate("CCParameterWidget", "Method:", 0));
        labelMwl->setText(QApplication::translate("CCParameterWidget", "Measure Wave Length:", 0));
        spinBoxMwl->setSuffix(QApplication::translate("CCParameterWidget", " nm", 0));
        labelCoefficient->setText(QApplication::translate("CCParameterWidget", "Coefficient:", 0));
        labelMixingLevel->setText(QApplication::translate("CCParameterWidget", "Mixing Level:", 0));
        labelMixingTime->setText(QApplication::translate("CCParameterWidget", "Mixing Time:", 0));
        spinBoxMixingTime->setSuffix(QApplication::translate("CCParameterWidget", " s", 0));
        labelStaticTime->setText(QApplication::translate("CCParameterWidget", "Static Time:", 0));
        spinBoxStaticTime->setSuffix(QApplication::translate("CCParameterWidget", " s", 0));
    } // retranslateUi

};

namespace Ui {
    class CCParameterWidget: public Ui_CCParameterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCPARAMETERWIDGET_H
