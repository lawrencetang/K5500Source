/********************************************************************************
** Form generated from reading UI file 'oligocalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OLIGOCALCULATOR_H
#define UI_OLIGOCALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OligoCalculator
{
public:
    QVBoxLayout *verticalLayout_2;
    QFrame *frameHeader;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButtonBack;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_7;
    QTextEdit *inputTextEdit;
    QHBoxLayout *horizontalLayout;
    QFrame *frameBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_10;
    QTextEdit *textEdit_17;
    QLabel *label_8;
    QLineEdit *nbLineEdit;
    QTextEdit *textEdit_18;
    QHBoxLayout *horizontalLayout_12;
    QTextEdit *textEdit_21;
    QLabel *label_10;
    QLineEdit *gcLineEdit;
    QTextEdit *textEdit_22;
    QHBoxLayout *horizontalLayout_11;
    QTextEdit *textEdit_19;
    QLabel *label_9;
    QLineEdit *tmLineEdit;
    QTextEdit *textEdit_20;
    QHBoxLayout *horizontalLayout_8;
    QTextEdit *textEdit_13;
    QLabel *label_6;
    QLineEdit *mwLineEdit;
    QTextEdit *textEdit_14;
    QHBoxLayout *horizontalLayout_9;
    QTextEdit *textEdit_15;
    QLabel *label_7;
    QLineEdit *odLineEdit;
    QTextEdit *textEdit_16;
    QFrame *frameKeyboard;

    void setupUi(QFrame *OligoCalculator)
    {
        if (OligoCalculator->objectName().isEmpty())
            OligoCalculator->setObjectName(QStringLiteral("OligoCalculator"));
        OligoCalculator->resize(995, 700);
        OligoCalculator->setStyleSheet(QLatin1String("QFrame {\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        OligoCalculator->setFrameShape(QFrame::NoFrame);
        OligoCalculator->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(OligoCalculator);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        frameHeader = new QFrame(OligoCalculator);
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
        horizontalLayout_2 = new QHBoxLayout(frameHeader);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButtonBack = new QToolButton(frameHeader);
        toolButtonBack->setObjectName(QStringLiteral("toolButtonBack"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButtonBack->sizePolicy().hasHeightForWidth());
        toolButtonBack->setSizePolicy(sizePolicy);
        toolButtonBack->setMinimumSize(QSize(180, 0));
        toolButtonBack->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonBack);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addWidget(frameHeader);

        groupBox = new QGroupBox(OligoCalculator);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(true);
        horizontalLayout_7 = new QHBoxLayout(groupBox);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, -1, 0, -1);
        inputTextEdit = new QTextEdit(groupBox);
        inputTextEdit->setObjectName(QStringLiteral("inputTextEdit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(12);
        inputTextEdit->setFont(font1);
        inputTextEdit->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(inputTextEdit);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frameBox = new QFrame(OligoCalculator);
        frameBox->setObjectName(QStringLiteral("frameBox"));
        frameBox->setFrameShape(QFrame::StyledPanel);
        frameBox->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frameBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        textEdit_17 = new QTextEdit(frameBox);
        textEdit_17->setObjectName(QStringLiteral("textEdit_17"));
        textEdit_17->setMinimumSize(QSize(152, 32));
        textEdit_17->setMaximumSize(QSize(152, 32));
        textEdit_17->setFrameShape(QFrame::NoFrame);
        textEdit_17->setFrameShadow(QFrame::Plain);
        textEdit_17->setReadOnly(true);

        horizontalLayout_10->addWidget(textEdit_17);

        label_8 = new QLabel(frameBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(9, 32));
        label_8->setMaximumSize(QSize(9, 32));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_8->setFont(font2);

        horizontalLayout_10->addWidget(label_8);

        nbLineEdit = new QLineEdit(frameBox);
        nbLineEdit->setObjectName(QStringLiteral("nbLineEdit"));
        nbLineEdit->setMinimumSize(QSize(0, 32));
        nbLineEdit->setReadOnly(true);

        horizontalLayout_10->addWidget(nbLineEdit);

        textEdit_18 = new QTextEdit(frameBox);
        textEdit_18->setObjectName(QStringLiteral("textEdit_18"));
        textEdit_18->setMinimumSize(QSize(110, 32));
        textEdit_18->setMaximumSize(QSize(110, 32));
        textEdit_18->setFrameShape(QFrame::NoFrame);
        textEdit_18->setFrameShadow(QFrame::Plain);
        textEdit_18->setReadOnly(true);

        horizontalLayout_10->addWidget(textEdit_18);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        textEdit_21 = new QTextEdit(frameBox);
        textEdit_21->setObjectName(QStringLiteral("textEdit_21"));
        textEdit_21->setMinimumSize(QSize(152, 32));
        textEdit_21->setMaximumSize(QSize(152, 32));
        textEdit_21->setFrameShape(QFrame::NoFrame);
        textEdit_21->setFrameShadow(QFrame::Plain);
        textEdit_21->setReadOnly(true);

        horizontalLayout_12->addWidget(textEdit_21);

        label_10 = new QLabel(frameBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(9, 32));
        label_10->setMaximumSize(QSize(9, 32));
        label_10->setFont(font2);

        horizontalLayout_12->addWidget(label_10);

        gcLineEdit = new QLineEdit(frameBox);
        gcLineEdit->setObjectName(QStringLiteral("gcLineEdit"));
        gcLineEdit->setMinimumSize(QSize(0, 32));
        gcLineEdit->setReadOnly(true);

        horizontalLayout_12->addWidget(gcLineEdit);

        textEdit_22 = new QTextEdit(frameBox);
        textEdit_22->setObjectName(QStringLiteral("textEdit_22"));
        textEdit_22->setMinimumSize(QSize(110, 32));
        textEdit_22->setMaximumSize(QSize(110, 32));
        textEdit_22->setAutoFillBackground(false);
        textEdit_22->setFrameShape(QFrame::NoFrame);
        textEdit_22->setFrameShadow(QFrame::Plain);
        textEdit_22->setReadOnly(true);

        horizontalLayout_12->addWidget(textEdit_22);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        textEdit_19 = new QTextEdit(frameBox);
        textEdit_19->setObjectName(QStringLiteral("textEdit_19"));
        textEdit_19->setMinimumSize(QSize(152, 32));
        textEdit_19->setMaximumSize(QSize(152, 32));
        textEdit_19->setFrameShape(QFrame::NoFrame);
        textEdit_19->setFrameShadow(QFrame::Plain);
        textEdit_19->setReadOnly(true);

        horizontalLayout_11->addWidget(textEdit_19);

        label_9 = new QLabel(frameBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(9, 32));
        label_9->setMaximumSize(QSize(9, 32));
        label_9->setFont(font2);

        horizontalLayout_11->addWidget(label_9);

        tmLineEdit = new QLineEdit(frameBox);
        tmLineEdit->setObjectName(QStringLiteral("tmLineEdit"));
        tmLineEdit->setMinimumSize(QSize(0, 32));
        tmLineEdit->setReadOnly(true);

        horizontalLayout_11->addWidget(tmLineEdit);

        textEdit_20 = new QTextEdit(frameBox);
        textEdit_20->setObjectName(QStringLiteral("textEdit_20"));
        textEdit_20->setMinimumSize(QSize(110, 32));
        textEdit_20->setMaximumSize(QSize(110, 32));
        textEdit_20->setFrameShape(QFrame::NoFrame);
        textEdit_20->setFrameShadow(QFrame::Plain);
        textEdit_20->setReadOnly(true);

        horizontalLayout_11->addWidget(textEdit_20);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        textEdit_13 = new QTextEdit(frameBox);
        textEdit_13->setObjectName(QStringLiteral("textEdit_13"));
        textEdit_13->setMinimumSize(QSize(152, 32));
        textEdit_13->setMaximumSize(QSize(152, 32));
        textEdit_13->setStyleSheet(QStringLiteral(""));
        textEdit_13->setFrameShape(QFrame::NoFrame);
        textEdit_13->setFrameShadow(QFrame::Plain);
        textEdit_13->setReadOnly(true);

        horizontalLayout_8->addWidget(textEdit_13);

        label_6 = new QLabel(frameBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(9, 32));
        label_6->setMaximumSize(QSize(9, 32));
        label_6->setFont(font2);

        horizontalLayout_8->addWidget(label_6);

        mwLineEdit = new QLineEdit(frameBox);
        mwLineEdit->setObjectName(QStringLiteral("mwLineEdit"));
        mwLineEdit->setMinimumSize(QSize(0, 32));
        mwLineEdit->setReadOnly(true);

        horizontalLayout_8->addWidget(mwLineEdit);

        textEdit_14 = new QTextEdit(frameBox);
        textEdit_14->setObjectName(QStringLiteral("textEdit_14"));
        textEdit_14->setMinimumSize(QSize(110, 32));
        textEdit_14->setMaximumSize(QSize(110, 32));
        textEdit_14->setFrameShape(QFrame::NoFrame);
        textEdit_14->setFrameShadow(QFrame::Plain);
        textEdit_14->setReadOnly(true);

        horizontalLayout_8->addWidget(textEdit_14);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        textEdit_15 = new QTextEdit(frameBox);
        textEdit_15->setObjectName(QStringLiteral("textEdit_15"));
        textEdit_15->setMinimumSize(QSize(152, 32));
        textEdit_15->setMaximumSize(QSize(152, 32));
        textEdit_15->setFrameShape(QFrame::NoFrame);
        textEdit_15->setFrameShadow(QFrame::Plain);
        textEdit_15->setReadOnly(true);

        horizontalLayout_9->addWidget(textEdit_15);

        label_7 = new QLabel(frameBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(9, 32));
        label_7->setMaximumSize(QSize(9, 32));
        label_7->setFont(font2);

        horizontalLayout_9->addWidget(label_7);

        odLineEdit = new QLineEdit(frameBox);
        odLineEdit->setObjectName(QStringLiteral("odLineEdit"));
        odLineEdit->setMinimumSize(QSize(0, 32));
        odLineEdit->setReadOnly(true);

        horizontalLayout_9->addWidget(odLineEdit);

        textEdit_16 = new QTextEdit(frameBox);
        textEdit_16->setObjectName(QStringLiteral("textEdit_16"));
        textEdit_16->setMinimumSize(QSize(110, 32));
        textEdit_16->setMaximumSize(QSize(110, 32));
        textEdit_16->setFrameShape(QFrame::NoFrame);
        textEdit_16->setFrameShadow(QFrame::Plain);
        textEdit_16->setReadOnly(true);

        horizontalLayout_9->addWidget(textEdit_16);


        verticalLayout->addLayout(horizontalLayout_9);


        horizontalLayout->addWidget(frameBox);

        frameKeyboard = new QFrame(OligoCalculator);
        frameKeyboard->setObjectName(QStringLiteral("frameKeyboard"));
        frameKeyboard->setFrameShape(QFrame::StyledPanel);
        frameKeyboard->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frameKeyboard);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(OligoCalculator);

        QMetaObject::connectSlotsByName(OligoCalculator);
    } // setupUi

    void retranslateUi(QFrame *OligoCalculator)
    {
        OligoCalculator->setWindowTitle(QApplication::translate("OligoCalculator", "Frame", 0));
        toolButtonBack->setText(QApplication::translate("OligoCalculator", "Back", 0));
        groupBox->setTitle(QApplication::translate("OligoCalculator", "Please enter a base sequence", 0));
        textEdit_17->setHtml(QApplication::translate("OligoCalculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\351\273\221\344\275\223'; font-size:12pt; font-weight:600;\">Number</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("OligoCalculator", "=", 0));
        textEdit_18->setHtml(QApplication::translate("OligoCalculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\351\273\221\344\275\223'; font-size:12pt; font-weight:600;\">nt</span></p></body></html>", 0));
        textEdit_21->setHtml(QApplication::translate("OligoCalculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\351\273\221\344\275\223'; font-size:12pt; font-weight:600;\">%GC</span></p></body></html>", 0));
        label_10->setText(QApplication::translate("OligoCalculator", "=", 0));
        textEdit_22->setHtml(QApplication::translate("OligoCalculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\351\273\221\344\275\223'; font-size:12pt; font-weight:600;\">%</span></p></body></html>", 0));
        textEdit_19->setHtml(QApplication::translate("OligoCalculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman,serif'; font-size:12pt; font-weight:600;\">Melting temp.(Tm)</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("OligoCalculator", "=", 0));
        textEdit_20->setHtml(QApplication::translate("OligoCalculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\351\273\221\344\275\223'; font-size:12pt; font-weight:600;\">\342\204\203</span></p></body></html>", 0));
        textEdit_13->setHtml(QApplication::translate("OligoCalculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Times New Roman,serif'; font-size:12pt; font-weight:600;\">Molecular</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("OligoCalculator", "=", 0));
        textEdit_14->setHtml(QApplication::translate("OligoCalculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\351\273\221\344\275\223'; font-size:12pt; font-weight:600;\">Dalton(g/M)</span></p></body></html>", 0));
        textEdit_15->setHtml(QApplication::translate("OligoCalculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\351\273\221\344\275\223'; font-size:12pt; font-weight:600;\">1OD</span><span style=\" font-family:'\351\273\221\344\275\223'; font-size:12pt; font-weight:600; vertical-align:sub;\">260</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("OligoCalculator", "=", 0));
        textEdit_16->setHtml(QApplication::translate("OligoCalculator", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'\351\273\221\344\275\223'; font-size:12pt; font-weight:600;\">Pmol</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class OligoCalculator: public Ui_OligoCalculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OLIGOCALCULATOR_H
