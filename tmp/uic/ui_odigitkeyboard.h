/********************************************************************************
** Form generated from reading UI file 'odigitkeyboard.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ODIGITKEYBOARD_H
#define UI_ODIGITKEYBOARD_H

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

class Ui_ODigitKeyboard
{
public:
    QHBoxLayout *horizontalLayout_5;
    QFrame *frameBorder;
    QVBoxLayout *verticalLayoutBorder;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton1;
    QToolButton *toolButton2;
    QToolButton *toolButton3;
    QToolButton *toolButtonLeft;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton4;
    QToolButton *toolButton5;
    QToolButton *toolButton6;
    QToolButton *toolButtonRight;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton7;
    QToolButton *toolButton8;
    QToolButton *toolButton9;
    QToolButton *toolButtonDelete;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButtonMinus;
    QToolButton *toolButton0;
    QToolButton *toolButtonPeriod;
    QToolButton *toolButtonEsc;

    void setupUi(QFrame *ODigitKeyboard)
    {
        if (ODigitKeyboard->objectName().isEmpty())
            ODigitKeyboard->setObjectName(QStringLiteral("ODigitKeyboard"));
        ODigitKeyboard->resize(602, 509);
        ODigitKeyboard->setFrameShape(QFrame::StyledPanel);
        ODigitKeyboard->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(ODigitKeyboard);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        frameBorder = new QFrame(ODigitKeyboard);
        frameBorder->setObjectName(QStringLiteral("frameBorder"));
        frameBorder->setFrameShape(QFrame::StyledPanel);
        frameBorder->setFrameShadow(QFrame::Raised);
        verticalLayoutBorder = new QVBoxLayout(frameBorder);
        verticalLayoutBorder->setSpacing(0);
        verticalLayoutBorder->setObjectName(QStringLiteral("verticalLayoutBorder"));
        verticalLayoutBorder->setContentsMargins(-1, 20, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        toolButton1 = new QToolButton(frameBorder);
        toolButton1->setObjectName(QStringLiteral("toolButton1"));

        horizontalLayout->addWidget(toolButton1);

        toolButton2 = new QToolButton(frameBorder);
        toolButton2->setObjectName(QStringLiteral("toolButton2"));

        horizontalLayout->addWidget(toolButton2);

        toolButton3 = new QToolButton(frameBorder);
        toolButton3->setObjectName(QStringLiteral("toolButton3"));

        horizontalLayout->addWidget(toolButton3);

        toolButtonLeft = new QToolButton(frameBorder);
        toolButtonLeft->setObjectName(QStringLiteral("toolButtonLeft"));

        horizontalLayout->addWidget(toolButtonLeft);


        verticalLayoutBorder->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolButton4 = new QToolButton(frameBorder);
        toolButton4->setObjectName(QStringLiteral("toolButton4"));

        horizontalLayout_2->addWidget(toolButton4);

        toolButton5 = new QToolButton(frameBorder);
        toolButton5->setObjectName(QStringLiteral("toolButton5"));

        horizontalLayout_2->addWidget(toolButton5);

        toolButton6 = new QToolButton(frameBorder);
        toolButton6->setObjectName(QStringLiteral("toolButton6"));

        horizontalLayout_2->addWidget(toolButton6);

        toolButtonRight = new QToolButton(frameBorder);
        toolButtonRight->setObjectName(QStringLiteral("toolButtonRight"));

        horizontalLayout_2->addWidget(toolButtonRight);


        verticalLayoutBorder->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        toolButton7 = new QToolButton(frameBorder);
        toolButton7->setObjectName(QStringLiteral("toolButton7"));

        horizontalLayout_3->addWidget(toolButton7);

        toolButton8 = new QToolButton(frameBorder);
        toolButton8->setObjectName(QStringLiteral("toolButton8"));

        horizontalLayout_3->addWidget(toolButton8);

        toolButton9 = new QToolButton(frameBorder);
        toolButton9->setObjectName(QStringLiteral("toolButton9"));

        horizontalLayout_3->addWidget(toolButton9);

        toolButtonDelete = new QToolButton(frameBorder);
        toolButtonDelete->setObjectName(QStringLiteral("toolButtonDelete"));

        horizontalLayout_3->addWidget(toolButtonDelete);


        verticalLayoutBorder->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        toolButtonMinus = new QToolButton(frameBorder);
        toolButtonMinus->setObjectName(QStringLiteral("toolButtonMinus"));

        horizontalLayout_4->addWidget(toolButtonMinus);

        toolButton0 = new QToolButton(frameBorder);
        toolButton0->setObjectName(QStringLiteral("toolButton0"));

        horizontalLayout_4->addWidget(toolButton0);

        toolButtonPeriod = new QToolButton(frameBorder);
        toolButtonPeriod->setObjectName(QStringLiteral("toolButtonPeriod"));

        horizontalLayout_4->addWidget(toolButtonPeriod);

        toolButtonEsc = new QToolButton(frameBorder);
        toolButtonEsc->setObjectName(QStringLiteral("toolButtonEsc"));

        horizontalLayout_4->addWidget(toolButtonEsc);


        verticalLayoutBorder->addLayout(horizontalLayout_4);


        horizontalLayout_5->addWidget(frameBorder);


        retranslateUi(ODigitKeyboard);

        QMetaObject::connectSlotsByName(ODigitKeyboard);
    } // setupUi

    void retranslateUi(QFrame *ODigitKeyboard)
    {
        ODigitKeyboard->setWindowTitle(QApplication::translate("ODigitKeyboard", "Frame", 0));
        toolButton1->setText(QApplication::translate("ODigitKeyboard", "1", 0));
        toolButton2->setText(QApplication::translate("ODigitKeyboard", "2", 0));
        toolButton3->setText(QApplication::translate("ODigitKeyboard", "3", 0));
        toolButtonLeft->setText(QApplication::translate("ODigitKeyboard", "<-", 0));
        toolButton4->setText(QApplication::translate("ODigitKeyboard", "4", 0));
        toolButton5->setText(QApplication::translate("ODigitKeyboard", "5", 0));
        toolButton6->setText(QApplication::translate("ODigitKeyboard", "6", 0));
        toolButtonRight->setText(QApplication::translate("ODigitKeyboard", "->", 0));
        toolButton7->setText(QApplication::translate("ODigitKeyboard", "7", 0));
        toolButton8->setText(QApplication::translate("ODigitKeyboard", "8", 0));
        toolButton9->setText(QApplication::translate("ODigitKeyboard", "9", 0));
        toolButtonDelete->setText(QApplication::translate("ODigitKeyboard", "Del", 0));
        toolButtonMinus->setText(QApplication::translate("ODigitKeyboard", "-", 0));
        toolButton0->setText(QApplication::translate("ODigitKeyboard", "0", 0));
        toolButtonPeriod->setText(QApplication::translate("ODigitKeyboard", ".", 0));
        toolButtonEsc->setText(QApplication::translate("ODigitKeyboard", "Esc", 0));
    } // retranslateUi

};

namespace Ui {
    class ODigitKeyboard: public Ui_ODigitKeyboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ODIGITKEYBOARD_H
