/********************************************************************************
** Form generated from reading UI file 'omessagebox.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OMESSAGEBOX_H
#define UI_OMESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OMessageBox
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelTitleImage;
    QLabel *labelTitle;
    QToolButton *toolButtonClose;
    QFrame *frameText;
    QHBoxLayout *horizontalLayout;
    QLabel *labelImage;
    QLabel *labelText;
    QFrame *frameBtnBox;
    QHBoxLayout *horizontalLayout_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *OMessageBox)
    {
        if (OMessageBox->objectName().isEmpty())
            OMessageBox->setObjectName(QStringLiteral("OMessageBox"));
        OMessageBox->resize(514, 348);
        verticalLayout = new QVBoxLayout(OMessageBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameTitle = new QFrame(OMessageBox);
        frameTitle->setObjectName(QStringLiteral("frameTitle"));
        frameTitle->setMinimumSize(QSize(0, 55));
        frameTitle->setFrameShape(QFrame::StyledPanel);
        frameTitle->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frameTitle);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
        labelTitleImage = new QLabel(frameTitle);
        labelTitleImage->setObjectName(QStringLiteral("labelTitleImage"));
        labelTitleImage->setMaximumSize(QSize(24, 24));
        labelTitleImage->setPixmap(QPixmap(QString::fromUtf8(":/images/info.png")));
        labelTitleImage->setScaledContents(true);
        labelTitleImage->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labelTitleImage);

        labelTitle = new QLabel(frameTitle);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));

        horizontalLayout_2->addWidget(labelTitle);

        toolButtonClose = new QToolButton(frameTitle);
        toolButtonClose->setObjectName(QStringLiteral("toolButtonClose"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonClose->setIcon(icon);
        toolButtonClose->setIconSize(QSize(16, 16));
        toolButtonClose->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButtonClose);

        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addWidget(frameTitle);

        frameText = new QFrame(OMessageBox);
        frameText->setObjectName(QStringLiteral("frameText"));
        frameText->setFrameShape(QFrame::StyledPanel);
        frameText->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frameText);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        labelImage = new QLabel(frameText);
        labelImage->setObjectName(QStringLiteral("labelImage"));

        horizontalLayout->addWidget(labelImage);

        labelText = new QLabel(frameText);
        labelText->setObjectName(QStringLiteral("labelText"));
        labelText->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelText);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addWidget(frameText);

        frameBtnBox = new QFrame(OMessageBox);
        frameBtnBox->setObjectName(QStringLiteral("frameBtnBox"));
        frameBtnBox->setFrameShape(QFrame::StyledPanel);
        frameBtnBox->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frameBtnBox);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(3, 3, 3, 3);
        buttonBox = new QDialogButtonBox(frameBtnBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::NoButton);

        horizontalLayout_3->addWidget(buttonBox);


        verticalLayout->addWidget(frameBtnBox);

        verticalLayout->setStretch(1, 1);

        retranslateUi(OMessageBox);

        QMetaObject::connectSlotsByName(OMessageBox);
    } // setupUi

    void retranslateUi(QDialog *OMessageBox)
    {
        OMessageBox->setWindowTitle(QApplication::translate("OMessageBox", "OAbstractMessageBox", 0));
        labelTitleImage->setText(QString());
        labelTitle->setText(QApplication::translate("OMessageBox", "Notice", 0));
        toolButtonClose->setText(QString());
        labelImage->setText(QString());
        labelText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OMessageBox: public Ui_OMessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OMESSAGEBOX_H
