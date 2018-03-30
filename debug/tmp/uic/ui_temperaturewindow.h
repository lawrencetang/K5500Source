/********************************************************************************
** Form generated from reading UI file 'temperaturewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPERATUREWINDOW_H
#define UI_TEMPERATUREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TemperatureWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frameHeader;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButtonBack;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QFrame *frameController;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelTarget;
    QDoubleSpinBox *doubleSpinBoxTarget;
    QToolButton *toolButtonRun;
    QFrame *frameKeyboard;
    QFrame *frameShow;
    QVBoxLayout *verticalLayout_3;
    QFrame *frameDial;
    QFrame *frameTemperarture;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelTemperature;
    QLabel *labelShowTemperature;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QFrame *TemperatureWindow)
    {
        if (TemperatureWindow->objectName().isEmpty())
            TemperatureWindow->setObjectName(QStringLiteral("TemperatureWindow"));
        TemperatureWindow->resize(968, 656);
        TemperatureWindow->setFrameShape(QFrame::StyledPanel);
        TemperatureWindow->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(TemperatureWindow);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frameHeader = new QFrame(TemperatureWindow);
        frameHeader->setObjectName(QStringLiteral("frameHeader"));
        frameHeader->setMinimumSize(QSize(0, 55));
        frameHeader->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	color:white;\n"
"	font: 75 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QToolButton::disabled{\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QFrame#frameHeader {\n"
"	background-color: rgb(85, 0, 127);\n"
"}"));
        frameHeader->setFrameShape(QFrame::NoFrame);
        frameHeader->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameHeader);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButtonBack = new QToolButton(frameHeader);
        toolButtonBack->setObjectName(QStringLiteral("toolButtonBack"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonBack->sizePolicy().hasHeightForWidth());
        toolButtonBack->setSizePolicy(sizePolicy);
        toolButtonBack->setMinimumSize(QSize(180, 0));
        toolButtonBack->setAutoRaise(true);

        horizontalLayout->addWidget(toolButtonBack);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addWidget(frameHeader);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frameController = new QFrame(TemperatureWindow);
        frameController->setObjectName(QStringLiteral("frameController"));
        frameController->setMinimumSize(QSize(0, 55));
        frameController->setStyleSheet(QString::fromUtf8("QSpinBox, QDoubleSpinBox, QDateTimeEdit {\n"
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
"	image: url(:/temperature_icons/arrow_right.png);\n"
"	width: 24px;height: 28px; right:5px;\n"
"}\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button, QDateTimeEdit::down-button {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:left;\n"
"	padding-right: 10px;\n"
"	image: url(:/temperature_icons/arrow_left.png);\n"
"	width: 24px;height: 28px; left:5px;\n"
"}\n"
"QSpinBox::up-button:pressed, QDoubleSpinBox::up-button:pressed, QDateTimeEdit::up-button:pressed {\n"
"	subcontrol-origin:border;\n"
"	subcontrol-position:right;\n"
"	image: url(:/temperature_icons/arrow_right.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::down-button"
                        ":pressed, QDoubleSpinBox::down-button:pressed, QDateTimeEdit::down-button:pressed {\n"
"	subcontrol-position:left;\n"
"	image: url(:/temperature_icons/arrow_left.png);\n"
"	width: 23px;height: 27px;\n"
"}\n"
"QSpinBox::disabled, QDoubleSpinBox::disabled, QDateTimeEdit::disabled {\n"
"	color:darkgray;\n"
"}\n"
"\n"
"QLabel {\n"
"	color:white;\n"
"	font: 12pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameController->setFrameShape(QFrame::NoFrame);
        frameController->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameController);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 100, 0, 9);
        labelTarget = new QLabel(frameController);
        labelTarget->setObjectName(QStringLiteral("labelTarget"));
        labelTarget->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(labelTarget);

        doubleSpinBoxTarget = new QDoubleSpinBox(frameController);
        doubleSpinBoxTarget->setObjectName(QStringLiteral("doubleSpinBoxTarget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBoxTarget->sizePolicy().hasHeightForWidth());
        doubleSpinBoxTarget->setSizePolicy(sizePolicy1);
        doubleSpinBoxTarget->setMinimumSize(QSize(200, 0));
        doubleSpinBoxTarget->setMaximumSize(QSize(16777215, 51));
        doubleSpinBoxTarget->setAlignment(Qt::AlignCenter);
        doubleSpinBoxTarget->setDecimals(1);
        doubleSpinBoxTarget->setMinimum(10);
        doubleSpinBoxTarget->setMaximum(120);

        horizontalLayout_2->addWidget(doubleSpinBoxTarget);

        toolButtonRun = new QToolButton(frameController);
        toolButtonRun->setObjectName(QStringLiteral("toolButtonRun"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/temperature_icons/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonRun->setIcon(icon);
        toolButtonRun->setIconSize(QSize(48, 48));
        toolButtonRun->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonRun);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addWidget(frameController);

        frameKeyboard = new QFrame(TemperatureWindow);
        frameKeyboard->setObjectName(QStringLiteral("frameKeyboard"));
        frameKeyboard->setFrameShape(QFrame::NoFrame);
        frameKeyboard->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frameKeyboard);

        verticalLayout->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayout);

        frameShow = new QFrame(TemperatureWindow);
        frameShow->setObjectName(QStringLiteral("frameShow"));
        frameShow->setFrameShape(QFrame::NoFrame);
        frameShow->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frameShow);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, 30, -1, -1);
        frameDial = new QFrame(frameShow);
        frameDial->setObjectName(QStringLiteral("frameDial"));
        frameDial->setFrameShape(QFrame::StyledPanel);
        frameDial->setFrameShadow(QFrame::Raised);

        verticalLayout_3->addWidget(frameDial);

        frameTemperarture = new QFrame(frameShow);
        frameTemperarture->setObjectName(QStringLiteral("frameTemperarture"));
        frameTemperarture->setMinimumSize(QSize(0, 55));
        frameTemperarture->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color:white;\n"
"	font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        frameTemperarture->setFrameShape(QFrame::StyledPanel);
        frameTemperarture->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frameTemperarture);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(183, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        labelTemperature = new QLabel(frameTemperarture);
        labelTemperature->setObjectName(QStringLiteral("labelTemperature"));

        horizontalLayout_4->addWidget(labelTemperature);

        labelShowTemperature = new QLabel(frameTemperarture);
        labelShowTemperature->setObjectName(QStringLiteral("labelShowTemperature"));
        labelShowTemperature->setStyleSheet(QStringLiteral(""));
        labelShowTemperature->setFrameShape(QFrame::NoFrame);

        horizontalLayout_4->addWidget(labelShowTemperature);

        horizontalSpacer_3 = new QSpacerItem(183, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(frameTemperarture);

        verticalLayout_3->setStretch(0, 1);

        horizontalLayout_3->addWidget(frameShow);

        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalLayout_2->setStretch(1, 1);

        retranslateUi(TemperatureWindow);

        QMetaObject::connectSlotsByName(TemperatureWindow);
    } // setupUi

    void retranslateUi(QFrame *TemperatureWindow)
    {
        TemperatureWindow->setWindowTitle(QApplication::translate("TemperatureWindow", "Frame", 0));
        toolButtonBack->setText(QApplication::translate("TemperatureWindow", "Back", 0));
        labelTarget->setText(QApplication::translate("TemperatureWindow", "  Target Value:", 0));
        doubleSpinBoxTarget->setSuffix(QApplication::translate("TemperatureWindow", " \342\204\203", 0));
        toolButtonRun->setText(QApplication::translate("TemperatureWindow", "Start", 0));
        labelTemperature->setText(QApplication::translate("TemperatureWindow", "Temperature:", 0));
        labelShowTemperature->setText(QApplication::translate("TemperatureWindow", "0 \342\204\203", 0));
    } // retranslateUi

};

namespace Ui {
    class TemperatureWindow: public Ui_TemperatureWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPERATUREWINDOW_H
