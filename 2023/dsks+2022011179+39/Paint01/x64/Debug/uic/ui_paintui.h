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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_paintuiClass
{
public:
    QGroupBox *groupBox;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;

    void setupUi(QWidget *paintuiClass)
    {
        if (paintuiClass->objectName().isEmpty())
            paintuiClass->setObjectName(QString::fromUtf8("paintuiClass"));
        paintuiClass->resize(812, 752);
        groupBox = new QGroupBox(paintuiClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(140, 10, 551, 561));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(50, 100, 181, 51));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(340, 110, 191, 51));

        retranslateUi(paintuiClass);
        QObject::connect(lineEdit, SIGNAL(returnPressed()), paintuiClass, SLOT(inter_point()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), paintuiClass, SLOT(inter_point()));

        QMetaObject::connectSlotsByName(paintuiClass);
    } // setupUi

    void retranslateUi(QWidget *paintuiClass)
    {
        paintuiClass->setWindowTitle(QCoreApplication::translate("paintuiClass", "paintui", nullptr));
        groupBox->setTitle(QCoreApplication::translate("paintuiClass", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class paintuiClass: public Ui_paintuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTUI_H
