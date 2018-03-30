/********************************************************************************
** Form generated from reading UI file 'devicecheckwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICECHECKWINDOW_H
#define UI_DEVICECHECKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DeviceCheckWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frameLeft;
    QVBoxLayout *verticalLayout;
    QLabel *labelMethod;
    QComboBox *comboBoxMethod;
    QLabel *labelOptical;
    QComboBox *comboBoxOptical;
    QLabel *labelChannel;
    QComboBox *comboBoxChannel;
    QLabel *labelIntergralTime;
    QSpinBox *spinBoxIntergralTime;
    QSpacerItem *verticalSpacer;
    QFrame *frameKeyboard;
    QVBoxLayout *verticalLayout_2;
    QFrame *framePlot;
    QFrame *frameBottom;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButtonBack;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButtonCheck;
    QToolButton *toolButtonClear;

    void setupUi(QFrame *DeviceCheckWindow)
    {
        if (DeviceCheckWindow->objectName().isEmpty())
            DeviceCheckWindow->setObjectName(QStringLiteral("DeviceCheckWindow"));
        DeviceCheckWindow->resize(1208, 787);
        DeviceCheckWindow->setFrameShape(QFrame::NoFrame);
        DeviceCheckWindow->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(DeviceCheckWindow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frameLeft = new QFrame(DeviceCheckWindow);
        frameLeft->setObjectName(QStringLiteral("frameLeft"));
        frameLeft->setStyleSheet(QString::fromUtf8("QFrame#frameLeft{\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(61, 252, 64, 230), stop:1 rgba(0, 0, 0, 255));\n"
"}\n"
"\n"
"QLabel{\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
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
"	subcontrol-origin:b"
                        "order;\n"
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
"QCo"
                        "mboBox {\n"
"	border: 1px solid white;\n"
"	padding: 1px 18px 1px 3px;\n"
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
"	image: url(:/protein_icons/arrow_down.png);\n"
"	width: 24px;height: 28px;\n"
"}\n"
"\n"
"QComboBox::down-arrow:on { \n"
"	top: 1px;left: 1px;\n"
"}\n"
""
                        "\n"
"QComboBox QAbstractItemView {\n"
"	color: white;\n"
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
"}\n"
""));
        frameLeft->setFrameShape(QFrame::NoFrame);
        frameLeft->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameLeft);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelMethod = new QLabel(frameLeft);
        labelMethod->setObjectName(QStringLiteral("labelMethod"));
        labelMethod->setMinimumSize(QSize(0, 48));

        verticalLayout->addWidget(labelMethod);

        comboBoxMethod = new QComboBox(frameLeft);
        comboBoxMethod->setObjectName(QStringLiteral("comboBoxMethod"));
        comboBoxMethod->setMinimumSize(QSize(149, 48));

        verticalLayout->addWidget(comboBoxMethod);

        labelOptical = new QLabel(frameLeft);
        labelOptical->setObjectName(QStringLiteral("labelOptical"));
        labelOptical->setMinimumSize(QSize(0, 48));

        verticalLayout->addWidget(labelOptical);

        comboBoxOptical = new QComboBox(frameLeft);
        comboBoxOptical->setObjectName(QStringLiteral("comboBoxOptical"));
        comboBoxOptical->setMinimumSize(QSize(149, 48));

        verticalLayout->addWidget(comboBoxOptical);

        labelChannel = new QLabel(frameLeft);
        labelChannel->setObjectName(QStringLiteral("labelChannel"));
        labelChannel->setMinimumSize(QSize(0, 48));

        verticalLayout->addWidget(labelChannel);

        comboBoxChannel = new QComboBox(frameLeft);
        comboBoxChannel->setObjectName(QStringLiteral("comboBoxChannel"));
        comboBoxChannel->setMinimumSize(QSize(149, 48));

        verticalLayout->addWidget(comboBoxChannel);

        labelIntergralTime = new QLabel(frameLeft);
        labelIntergralTime->setObjectName(QStringLiteral("labelIntergralTime"));
        labelIntergralTime->setMinimumSize(QSize(0, 48));

        verticalLayout->addWidget(labelIntergralTime);

        spinBoxIntergralTime = new QSpinBox(frameLeft);
        spinBoxIntergralTime->setObjectName(QStringLiteral("spinBoxIntergralTime"));
        spinBoxIntergralTime->setMinimumSize(QSize(0, 48));
        spinBoxIntergralTime->setAlignment(Qt::AlignCenter);
        spinBoxIntergralTime->setMinimum(10);
        spinBoxIntergralTime->setMaximum(200000);
        spinBoxIntergralTime->setValue(30000);

        verticalLayout->addWidget(spinBoxIntergralTime);

        verticalSpacer = new QSpacerItem(20, 96, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        frameKeyboard = new QFrame(frameLeft);
        frameKeyboard->setObjectName(QStringLiteral("frameKeyboard"));
        frameKeyboard->setFrameShape(QFrame::NoFrame);
        frameKeyboard->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frameKeyboard);

        verticalLayout->setStretch(8, 1);

        horizontalLayout->addWidget(frameLeft);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        framePlot = new QFrame(DeviceCheckWindow);
        framePlot->setObjectName(QStringLiteral("framePlot"));
        framePlot->setFrameShape(QFrame::NoFrame);
        framePlot->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(framePlot);

        frameBottom = new QFrame(DeviceCheckWindow);
        frameBottom->setObjectName(QStringLiteral("frameBottom"));
        frameBottom->setMinimumSize(QSize(0, 55));
        frameBottom->setAutoFillBackground(false);
        frameBottom->setStyleSheet(QString::fromUtf8("QFrame#frameBottom{\n"
"	background-color: rgb(85, 0, 127);\n"
"}\n"
"\n"
"QToolButton{\n"
"	color:white;\n"
"	font: 18pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameBottom->setFrameShape(QFrame::NoFrame);
        frameBottom->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameBottom);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButtonBack = new QToolButton(frameBottom);
        toolButtonBack->setObjectName(QStringLiteral("toolButtonBack"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonBack->sizePolicy().hasHeightForWidth());
        toolButtonBack->setSizePolicy(sizePolicy);
        toolButtonBack->setMinimumSize(QSize(180, 0));
        toolButtonBack->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonBack);

        horizontalSpacer = new QSpacerItem(403, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButtonCheck = new QToolButton(frameBottom);
        toolButtonCheck->setObjectName(QStringLiteral("toolButtonCheck"));
        sizePolicy.setHeightForWidth(toolButtonCheck->sizePolicy().hasHeightForWidth());
        toolButtonCheck->setSizePolicy(sizePolicy);
        toolButtonCheck->setMinimumSize(QSize(180, 0));
        toolButtonCheck->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonCheck);

        toolButtonClear = new QToolButton(frameBottom);
        toolButtonClear->setObjectName(QStringLiteral("toolButtonClear"));
        sizePolicy.setHeightForWidth(toolButtonClear->sizePolicy().hasHeightForWidth());
        toolButtonClear->setSizePolicy(sizePolicy);
        toolButtonClear->setMinimumSize(QSize(180, 0));
        toolButtonClear->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonClear);


        verticalLayout_2->addWidget(frameBottom);

        verticalLayout_2->setStretch(0, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 4);

        retranslateUi(DeviceCheckWindow);

        QMetaObject::connectSlotsByName(DeviceCheckWindow);
    } // setupUi

    void retranslateUi(QFrame *DeviceCheckWindow)
    {
        DeviceCheckWindow->setWindowTitle(QApplication::translate("DeviceCheckWindow", "Frame", 0));
        labelMethod->setText(QApplication::translate("DeviceCheckWindow", "Method:", 0));
        labelOptical->setText(QApplication::translate("DeviceCheckWindow", "Optical:", 0));
        labelChannel->setText(QApplication::translate("DeviceCheckWindow", "Channel:", 0));
        labelIntergralTime->setText(QApplication::translate("DeviceCheckWindow", "Integral Time:", 0));
        spinBoxIntergralTime->setSuffix(QApplication::translate("DeviceCheckWindow", " us", 0));
        spinBoxIntergralTime->setPrefix(QString());
        toolButtonBack->setText(QApplication::translate("DeviceCheckWindow", "Back", 0));
        toolButtonCheck->setText(QApplication::translate("DeviceCheckWindow", "Check", 0));
        toolButtonClear->setText(QApplication::translate("DeviceCheckWindow", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class DeviceCheckWindow: public Ui_DeviceCheckWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICECHECKWINDOW_H
