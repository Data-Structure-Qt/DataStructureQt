/********************************************************************************
** Form generated from reading UI file 'paintui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTUI_H
#define UI_PAINTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paintuiClass
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *Add;
    QPushButton *mid_num;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox;
    QHBoxLayout *paintf;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *paintuiClass)
    {
        if (paintuiClass->objectName().isEmpty())
            paintuiClass->setObjectName(QString::fromUtf8("paintuiClass"));
        paintuiClass->resize(904, 674);
        horizontalLayout = new QHBoxLayout(paintuiClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(paintuiClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        Add = new QPushButton(groupBox);
        Add->setObjectName(QString::fromUtf8("Add"));

        gridLayout->addWidget(Add, 1, 1, 1, 1);

        mid_num = new QPushButton(groupBox);
        mid_num->setObjectName(QString::fromUtf8("mid_num"));

        gridLayout->addWidget(mid_num, 5, 1, 1, 1);

        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        gridLayout->addWidget(spinBox_2, 5, 0, 1, 1);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(21);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMinimumSize(QSize(46, 0));
        QFont font;
        font.setStrikeOut(false);
        spinBox->setFont(font);

        gridLayout->addWidget(spinBox, 2, 0, 1, 1);

        paintf = new QHBoxLayout();
        paintf->setSpacing(6);
        paintf->setObjectName(QString::fromUtf8("paintf"));

        gridLayout->addLayout(paintf, 3, 0, 1, 2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 0, 1, 1);

        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 4, 1, 1, 1);

        pushButton->raise();
        label->raise();
        spinBox->raise();
        Add->raise();
        spinBox_2->raise();
        mid_num->raise();
        pushButton_3->raise();
        label_2->raise();

        horizontalLayout->addWidget(groupBox);


        retranslateUi(paintuiClass);
        QObject::connect(Add, SIGNAL(clicked()), paintuiClass, SLOT(add_point()));
        QObject::connect(pushButton, SIGNAL(clicked()), paintuiClass, SLOT(delete_point()));
        QObject::connect(mid_num, SIGNAL(clicked()), paintuiClass, SLOT(change()));

        QMetaObject::connectSlotsByName(paintuiClass);
    } // setupUi

    void retranslateUi(QWidget *paintuiClass)
    {
        paintuiClass->setWindowTitle(QCoreApplication::translate("paintuiClass", "paintui", nullptr));
        groupBox->setTitle(QCoreApplication::translate("paintuiClass", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("paintuiClass", "\346\267\273\345\212\240\350\212\202\347\202\271\347\232\204\345\200\274", nullptr));
        Add->setText(QCoreApplication::translate("paintuiClass", "\346\267\273\345\212\240\350\212\202\347\202\271", nullptr));
        mid_num->setText(QCoreApplication::translate("paintuiClass", "\351\200\211\346\213\251n\347\232\204\345\200\274", nullptr));
        pushButton->setText(QCoreApplication::translate("paintuiClass", "\345\210\240\351\231\244\350\212\202\347\202\271\357\274\210\346\234\200\345\220\216\347\232\204\357\274\211", nullptr));
        label_2->setText(QCoreApplication::translate("paintuiClass", "\351\200\211\346\213\251n\347\232\204\345\200\274", nullptr));
        pushButton_3->setText(QCoreApplication::translate("paintuiClass", "\346\227\240\347\224\250\346\214\211\351\222\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paintuiClass: public Ui_paintuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTUI_H
