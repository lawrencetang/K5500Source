/********************************************************************************
** Form generated from reading UI file 'dyparameterwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DYPARAMETERWIDGET_H
#define UI_DYPARAMETERWIDGET_H

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

class Ui_DYParameterWidget
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
    QLabel *labelMwl;
    QSpinBox *spinBoxMwl;
    QLabel *labelTarget;
    QDoubleSpinBox *doubleSpinBoxTarget;
    QSpinBox *spinBoxIncubationCount;
    QLabel *labelSubWaveLength1;
    QSpinBox *spinBoxSubWaveLength1;
    QLabel *labelSubWaveLength2;
    QLabel *labelSubWaveLength3;
    QLabel *labelSubWaveLength4;
    QLabel *labelMeasureOptical;
    QComboBox *comboBoxMeasureOptical;
    QLabel *labelMixingLevel;
    QComboBox *comboBoxMixingLevel;
    QLabel *labelMixingTime;
    QSpinBox *spinBoxMixingTime;
    QLabel *labelStaticTime;
    QSpinBox *spinBoxStaticTime;
    QSpinBox *spinBoxSubWaveLength2;
    QSpinBox *spinBoxSubWaveLength3;
    QSpinBox *spinBoxSubWaveLength4;
    QLabel *labelIncubationCount;
    QSpacerItem *verticalSpacer;

    void setupUi(QFrame *DYParameterWidget)
    {
        if (DYParameterWidget->objectName().isEmpty())
            DYParameterWidget->setObjectName(QStringLiteral("DYParameterWidget"));
        DYParameterWidget->resize(511, 1090);
        DYParameterWidget->setStyleSheet(QString::fromUtf8("QFrame#DYParameterWidget{\n"
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
"	image: url(:/protein_icons/a"
                        "rrow_right.png);\n"
"	width: 24px;height: 28px; right:5px;\n"
"}\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button, QDateTimeEdit::down-button {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:left;\n"
"	padding-right: 10px;\n"
"	image: url(:/protein_icons/arrow_left.png);\n"
"	width: 24px;height: 28px; left:5px;\n"
"}\n"
"QSpinBox::up-button:pressed, QDoubleSpinBox::up-button:pressed, QDateTimeEdit::up-button:pressed {\n"
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
"\n"
"QComboBox {\n"
"	border: 1px solid white;\n"
"	padding: 1px 18px 1px 3px;\n"
"	min-width: 6em;\n"
"	"
                        "font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
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
"	image: url(:/protein_icons/arrow_down.png);\n"
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
"	selectio"
                        "n-background-color: rgba(255, 255, 255, 50);\n"
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
        DYParameterWidget->setFrameShape(QFrame::StyledPanel);
        DYParameterWidget->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(DYParameterWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setVerticalSpacing(30);
        labelDetectionMothed = new QLabel(DYParameterWidget);
        labelDetectionMothed->setObjectName(QStringLiteral("labelDetectionMothed"));
        labelDetectionMothed->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelDetectionMothed);

        comboBoxDetectionMothed = new QComboBox(DYParameterWidget);
        comboBoxDetectionMothed->setObjectName(QStringLiteral("comboBoxDetectionMothed"));
        comboBoxDetectionMothed->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxDetectionMothed);

        labelSampleName = new QLabel(DYParameterWidget);
        labelSampleName->setObjectName(QStringLiteral("labelSampleName"));
        labelSampleName->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelSampleName);

        lineEditSampleName = new QLineEdit(DYParameterWidget);
        lineEditSampleName->setObjectName(QStringLiteral("lineEditSampleName"));
        lineEditSampleName->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditSampleName);

        labelBwl = new QLabel(DYParameterWidget);
        labelBwl->setObjectName(QStringLiteral("labelBwl"));
        labelBwl->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelBwl);

        spinBoxBwl = new QSpinBox(DYParameterWidget);
        spinBoxBwl->setObjectName(QStringLiteral("spinBoxBwl"));
        spinBoxBwl->setMinimumSize(QSize(0, 48));
        spinBoxBwl->setAlignment(Qt::AlignCenter);
        spinBoxBwl->setMinimum(190);
        spinBoxBwl->setMaximum(850);
        spinBoxBwl->setValue(340);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxBwl);

        labelMwl = new QLabel(DYParameterWidget);
        labelMwl->setObjectName(QStringLiteral("labelMwl"));
        labelMwl->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelMwl);

        spinBoxMwl = new QSpinBox(DYParameterWidget);
        spinBoxMwl->setObjectName(QStringLiteral("spinBoxMwl"));
        spinBoxMwl->setMinimumSize(QSize(0, 48));
        spinBoxMwl->setAlignment(Qt::AlignCenter);
        spinBoxMwl->setMinimum(190);
        spinBoxMwl->setMaximum(850);
        spinBoxMwl->setValue(260);

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBoxMwl);

        labelTarget = new QLabel(DYParameterWidget);
        labelTarget->setObjectName(QStringLiteral("labelTarget"));
        labelTarget->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelTarget);

        doubleSpinBoxTarget = new QDoubleSpinBox(DYParameterWidget);
        doubleSpinBoxTarget->setObjectName(QStringLiteral("doubleSpinBoxTarget"));
        doubleSpinBoxTarget->setMinimumSize(QSize(0, 48));
        doubleSpinBoxTarget->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(4, QFormLayout::FieldRole, doubleSpinBoxTarget);

        spinBoxIncubationCount = new QSpinBox(DYParameterWidget);
        spinBoxIncubationCount->setObjectName(QStringLiteral("spinBoxIncubationCount"));
        spinBoxIncubationCount->setMinimumSize(QSize(0, 48));
        spinBoxIncubationCount->setAlignment(Qt::AlignCenter);
        spinBoxIncubationCount->setMinimum(1);
        spinBoxIncubationCount->setMaximum(16777215);

        formLayout->setWidget(5, QFormLayout::FieldRole, spinBoxIncubationCount);

        labelSubWaveLength1 = new QLabel(DYParameterWidget);
        labelSubWaveLength1->setObjectName(QStringLiteral("labelSubWaveLength1"));
        labelSubWaveLength1->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(6, QFormLayout::LabelRole, labelSubWaveLength1);

        spinBoxSubWaveLength1 = new QSpinBox(DYParameterWidget);
        spinBoxSubWaveLength1->setObjectName(QStringLiteral("spinBoxSubWaveLength1"));
        spinBoxSubWaveLength1->setMinimumSize(QSize(0, 48));
        spinBoxSubWaveLength1->setAlignment(Qt::AlignCenter);
        spinBoxSubWaveLength1->setMinimum(190);
        spinBoxSubWaveLength1->setMaximum(850);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBoxSubWaveLength1);

        labelSubWaveLength2 = new QLabel(DYParameterWidget);
        labelSubWaveLength2->setObjectName(QStringLiteral("labelSubWaveLength2"));
        labelSubWaveLength2->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(7, QFormLayout::LabelRole, labelSubWaveLength2);

        labelSubWaveLength3 = new QLabel(DYParameterWidget);
        labelSubWaveLength3->setObjectName(QStringLiteral("labelSubWaveLength3"));
        labelSubWaveLength3->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(8, QFormLayout::LabelRole, labelSubWaveLength3);

        labelSubWaveLength4 = new QLabel(DYParameterWidget);
        labelSubWaveLength4->setObjectName(QStringLiteral("labelSubWaveLength4"));
        labelSubWaveLength4->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(9, QFormLayout::LabelRole, labelSubWaveLength4);

        labelMeasureOptical = new QLabel(DYParameterWidget);
        labelMeasureOptical->setObjectName(QStringLiteral("labelMeasureOptical"));
        labelMeasureOptical->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(10, QFormLayout::LabelRole, labelMeasureOptical);

        comboBoxMeasureOptical = new QComboBox(DYParameterWidget);
        comboBoxMeasureOptical->setObjectName(QStringLiteral("comboBoxMeasureOptical"));
        comboBoxMeasureOptical->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(10, QFormLayout::FieldRole, comboBoxMeasureOptical);

        labelMixingLevel = new QLabel(DYParameterWidget);
        labelMixingLevel->setObjectName(QStringLiteral("labelMixingLevel"));
        labelMixingLevel->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(11, QFormLayout::LabelRole, labelMixingLevel);

        comboBoxMixingLevel = new QComboBox(DYParameterWidget);
        comboBoxMixingLevel->setObjectName(QStringLiteral("comboBoxMixingLevel"));
        comboBoxMixingLevel->setMinimumSize(QSize(149, 48));

        formLayout->setWidget(11, QFormLayout::FieldRole, comboBoxMixingLevel);

        labelMixingTime = new QLabel(DYParameterWidget);
        labelMixingTime->setObjectName(QStringLiteral("labelMixingTime"));
        labelMixingTime->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(12, QFormLayout::LabelRole, labelMixingTime);

        spinBoxMixingTime = new QSpinBox(DYParameterWidget);
        spinBoxMixingTime->setObjectName(QStringLiteral("spinBoxMixingTime"));
        spinBoxMixingTime->setMinimumSize(QSize(0, 48));
        spinBoxMixingTime->setAlignment(Qt::AlignCenter);
        spinBoxMixingTime->setMaximum(16777215);

        formLayout->setWidget(12, QFormLayout::FieldRole, spinBoxMixingTime);

        labelStaticTime = new QLabel(DYParameterWidget);
        labelStaticTime->setObjectName(QStringLiteral("labelStaticTime"));
        labelStaticTime->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(13, QFormLayout::LabelRole, labelStaticTime);

        spinBoxStaticTime = new QSpinBox(DYParameterWidget);
        spinBoxStaticTime->setObjectName(QStringLiteral("spinBoxStaticTime"));
        spinBoxStaticTime->setMinimumSize(QSize(0, 48));
        spinBoxStaticTime->setAlignment(Qt::AlignCenter);
        spinBoxStaticTime->setMaximum(16777215);

        formLayout->setWidget(13, QFormLayout::FieldRole, spinBoxStaticTime);

        spinBoxSubWaveLength2 = new QSpinBox(DYParameterWidget);
        spinBoxSubWaveLength2->setObjectName(QStringLiteral("spinBoxSubWaveLength2"));
        spinBoxSubWaveLength2->setMinimumSize(QSize(0, 48));
        spinBoxSubWaveLength2->setAlignment(Qt::AlignCenter);
        spinBoxSubWaveLength2->setMinimum(190);
        spinBoxSubWaveLength2->setMaximum(850);

        formLayout->setWidget(7, QFormLayout::FieldRole, spinBoxSubWaveLength2);

        spinBoxSubWaveLength3 = new QSpinBox(DYParameterWidget);
        spinBoxSubWaveLength3->setObjectName(QStringLiteral("spinBoxSubWaveLength3"));
        spinBoxSubWaveLength3->setMinimumSize(QSize(0, 48));
        spinBoxSubWaveLength3->setAlignment(Qt::AlignCenter);
        spinBoxSubWaveLength3->setMinimum(190);
        spinBoxSubWaveLength3->setMaximum(850);

        formLayout->setWidget(8, QFormLayout::FieldRole, spinBoxSubWaveLength3);

        spinBoxSubWaveLength4 = new QSpinBox(DYParameterWidget);
        spinBoxSubWaveLength4->setObjectName(QStringLiteral("spinBoxSubWaveLength4"));
        spinBoxSubWaveLength4->setMinimumSize(QSize(0, 48));
        spinBoxSubWaveLength4->setAlignment(Qt::AlignCenter);
        spinBoxSubWaveLength4->setMinimum(190);
        spinBoxSubWaveLength4->setMaximum(850);

        formLayout->setWidget(9, QFormLayout::FieldRole, spinBoxSubWaveLength4);

        labelIncubationCount = new QLabel(DYParameterWidget);
        labelIncubationCount->setObjectName(QStringLiteral("labelIncubationCount"));
        labelIncubationCount->setMinimumSize(QSize(0, 48));

        formLayout->setWidget(5, QFormLayout::LabelRole, labelIncubationCount);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 113, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(DYParameterWidget);

        QMetaObject::connectSlotsByName(DYParameterWidget);
    } // setupUi

    void retranslateUi(QFrame *DYParameterWidget)
    {
        DYParameterWidget->setWindowTitle(QApplication::translate("DYParameterWidget", "Frame", 0));
        labelDetectionMothed->setText(QApplication::translate("DYParameterWidget", "Detection Method:", 0));
        labelSampleName->setText(QApplication::translate("DYParameterWidget", "Sample Name:", 0));
        lineEditSampleName->setText(QApplication::translate("DYParameterWidget", "Sample", 0));
        labelBwl->setText(QApplication::translate("DYParameterWidget", "Base Wave Length:", 0));
        spinBoxBwl->setSuffix(QApplication::translate("DYParameterWidget", " nm", 0));
        labelMwl->setText(QApplication::translate("DYParameterWidget", "Main Wave Length:", 0));
        spinBoxMwl->setSuffix(QApplication::translate("DYParameterWidget", " nm", 0));
        labelTarget->setText(QApplication::translate("DYParameterWidget", "Target Value:", 0));
        labelSubWaveLength1->setText(QApplication::translate("DYParameterWidget", "Sub Wave Length1:", 0));
        spinBoxSubWaveLength1->setSuffix(QApplication::translate("DYParameterWidget", " nm", 0));
        labelSubWaveLength2->setText(QApplication::translate("DYParameterWidget", "Sub Wave Length2:", 0));
        labelSubWaveLength3->setText(QApplication::translate("DYParameterWidget", "Sub Wave Length3:", 0));
        labelSubWaveLength4->setText(QApplication::translate("DYParameterWidget", "Sub Wave Length4:", 0));
        labelMeasureOptical->setText(QApplication::translate("DYParameterWidget", "Measure Optical:", 0));
        labelMixingLevel->setText(QApplication::translate("DYParameterWidget", "Mixing Level:", 0));
        labelMixingTime->setText(QApplication::translate("DYParameterWidget", "Mixing Time:", 0));
        spinBoxMixingTime->setSuffix(QApplication::translate("DYParameterWidget", " s", 0));
        labelStaticTime->setText(QApplication::translate("DYParameterWidget", "Static Time:", 0));
        spinBoxStaticTime->setSuffix(QApplication::translate("DYParameterWidget", " s", 0));
        spinBoxSubWaveLength2->setSuffix(QApplication::translate("DYParameterWidget", " nm", 0));
        spinBoxSubWaveLength3->setSuffix(QApplication::translate("DYParameterWidget", " nm", 0));
        spinBoxSubWaveLength4->setSuffix(QApplication::translate("DYParameterWidget", " nm", 0));
        labelIncubationCount->setText(QApplication::translate("DYParameterWidget", "Incubation Count:", 0));
    } // retranslateUi

};

namespace Ui {
    class DYParameterWidget: public Ui_DYParameterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DYPARAMETERWIDGET_H
