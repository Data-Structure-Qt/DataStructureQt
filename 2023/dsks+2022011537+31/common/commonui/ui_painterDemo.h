/********************************************************************************
** Form generated from reading UI file 'painterDemo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTERDEMO_H
#define UI_PAINTERDEMO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_painterDemo
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QSpinBox *spinBox;
    QPushButton *btn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *painterDemo)
    {
        if (painterDemo->objectName().isEmpty())
            painterDemo->setObjectName(QString::fromUtf8("painterDemo"));
        painterDemo->resize(563, 125);
        horizontalLayout_2 = new QHBoxLayout(painterDemo);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn1 = new QPushButton(painterDemo);
        btn1->setObjectName(QString::fromUtf8("btn1"));

        horizontalLayout->addWidget(btn1);

        btn2 = new QPushButton(painterDemo);
        btn2->setObjectName(QString::fromUtf8("btn2"));

        horizontalLayout->addWidget(btn2);

        btn3 = new QPushButton(painterDemo);
        btn3->setObjectName(QString::fromUtf8("btn3"));

        horizontalLayout->addWidget(btn3);

        spinBox = new QSpinBox(painterDemo);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(5);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        btn = new QPushButton(painterDemo);
        btn->setObjectName(QString::fromUtf8("btn"));

        verticalLayout->addWidget(btn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(painterDemo);
        QObject::connect(btn1, SIGNAL(clicked()), painterDemo, SLOT(showMes()));
        QObject::connect(btn2, SIGNAL(clicked()), painterDemo, SLOT(say_mes()));
        QObject::connect(btn3, SIGNAL(clicked()), painterDemo, SLOT(chg_pen()));
        QObject::connect(btn, SIGNAL(clicked()), painterDemo, SLOT(cleanPix()));

        QMetaObject::connectSlotsByName(painterDemo);
    } // setupUi

    void retranslateUi(QWidget *painterDemo)
    {
        painterDemo->setWindowTitle(QCoreApplication::translate("painterDemo", "Form", nullptr));
        btn1->setText(QCoreApplication::translate("painterDemo", "\346\233\264\346\224\271\347\224\273\347\254\224\351\242\234\350\211\262", nullptr));
        btn2->setText(QCoreApplication::translate("painterDemo", "\345\205\263\351\227\255\347\224\273\346\235\277", nullptr));
        btn3->setText(QCoreApplication::translate("painterDemo", "\346\224\271\345\217\230\347\262\227\347\273\206", nullptr));
        btn->setText(QCoreApplication::translate("painterDemo", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class painterDemo: public Ui_painterDemo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTERDEMO_H
