/********************************************************************************
** Form generated from reading UI file 'CStartPage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSTARTPAGE_H
#define UI_CSTARTPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CStartPage
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QWidget *LeftWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *CleanRecentButton;
    QSpacerItem *verticalSpacer_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QWidget *RightWidget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *CStartPage)
    {
        if (CStartPage->objectName().isEmpty())
            CStartPage->setObjectName(QString::fromUtf8("CStartPage"));
        CStartPage->resize(658, 424);
        horizontalLayout_2 = new QHBoxLayout(CStartPage);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        LeftWidget = new QWidget(CStartPage);
        LeftWidget->setObjectName(QString::fromUtf8("LeftWidget"));
        LeftWidget->setMinimumSize(QSize(0, 100));
        verticalLayout = new QVBoxLayout(LeftWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        verticalLayout_3->addWidget(LeftWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_3);

        line = new QFrame(CStartPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CStartPage);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        CleanRecentButton = new QToolButton(CStartPage);
        CleanRecentButton->setObjectName(QString::fromUtf8("CleanRecentButton"));
        QFont font1;
        font1.setPointSize(10);
        font1.setUnderline(true);
        CleanRecentButton->setFont(font1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Delete"), QSize(), QIcon::Normal, QIcon::Off);
        CleanRecentButton->setIcon(icon);
        CleanRecentButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        CleanRecentButton->setAutoRaise(true);

        horizontalLayout->addWidget(CleanRecentButton);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        scrollArea = new QScrollArea(CStartPage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setLayoutDirection(Qt::LeftToRight);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 310, 343));
        verticalLayout_5 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        RightWidget = new QWidget(scrollAreaWidgetContents);
        RightWidget->setObjectName(QString::fromUtf8("RightWidget"));
        RightWidget->setMinimumSize(QSize(0, 100));
        verticalLayout_2 = new QVBoxLayout(RightWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout_5->addWidget(RightWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(2, 1);

        retranslateUi(CStartPage);

        QMetaObject::connectSlotsByName(CStartPage);
    } // setupUi

    void retranslateUi(QWidget *CStartPage)
    {
        CStartPage->setWindowTitle(QCoreApplication::translate("CStartPage", "Start Page", nullptr));
        label->setText(QCoreApplication::translate("CStartPage", "\346\234\200\350\277\221\346\211\223\345\274\200\347\232\204\346\226\207\346\241\243", nullptr));
#if QT_CONFIG(tooltip)
        CleanRecentButton->setToolTip(QCoreApplication::translate("CStartPage", "Clear the list", nullptr));
#endif // QT_CONFIG(tooltip)
        CleanRecentButton->setText(QCoreApplication::translate("CStartPage", "Clean...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CStartPage: public Ui_CStartPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSTARTPAGE_H
