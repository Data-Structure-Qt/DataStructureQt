/********************************************************************************
** Form generated from reading UI file 'BTreePainterUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTREEPAINTERUI_H
#define UI_BTREEPAINTERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BTreePainterUI
{
public:
    QGroupBox *groupBox;
    QPushButton *onelevel_Btn;
    QPushButton *create_Btn;
    QLineEdit *data_Edit;
    QLabel *label;
    QLineEdit *data_Edit_2;
    QLabel *label_2;

    void setupUi(QWidget *BTreePainterUI)
    {
        if (BTreePainterUI->objectName().isEmpty())
            BTreePainterUI->setObjectName(QString::fromUtf8("BTreePainterUI"));
        BTreePainterUI->resize(375, 403);
        groupBox = new QGroupBox(BTreePainterUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 351, 201));
        onelevel_Btn = new QPushButton(groupBox);
        onelevel_Btn->setObjectName(QString::fromUtf8("onelevel_Btn"));
        onelevel_Btn->setGeometry(QRect(240, 130, 93, 31));
        create_Btn = new QPushButton(groupBox);
        create_Btn->setObjectName(QString::fromUtf8("create_Btn"));
        create_Btn->setGeometry(QRect(240, 30, 93, 31));
        data_Edit = new QLineEdit(groupBox);
        data_Edit->setObjectName(QString::fromUtf8("data_Edit"));
        data_Edit->setGeometry(QRect(20, 30, 201, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 140, 141, 21));
        data_Edit_2 = new QLineEdit(groupBox);
        data_Edit_2->setObjectName(QString::fromUtf8("data_Edit_2"));
        data_Edit_2->setGeometry(QRect(20, 90, 201, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 70, 221, 21));

        retranslateUi(BTreePainterUI);
        QObject::connect(create_Btn, SIGNAL(clicked()), BTreePainterUI, SLOT(on_create_Btn_clicked()));
        QObject::connect(onelevel_Btn, SIGNAL(clicked()), BTreePainterUI, SLOT(on_onelevel_Btn_clicked()));

        QMetaObject::connectSlotsByName(BTreePainterUI);
    } // setupUi

    void retranslateUi(QWidget *BTreePainterUI)
    {
        BTreePainterUI->setWindowTitle(QCoreApplication::translate("BTreePainterUI", "BTreePainterUI", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BTreePainterUI", "\344\272\214\345\217\211\346\240\221", nullptr));
        onelevel_Btn->setText(QCoreApplication::translate("BTreePainterUI", "\346\230\276\347\244\272", nullptr));
        create_Btn->setText(QCoreApplication::translate("BTreePainterUI", "\345\210\233\345\273\272\344\272\214\345\217\211\346\240\221", nullptr));
        label->setText(QCoreApplication::translate("BTreePainterUI", "\346\230\276\347\244\272\344\272\244\346\215\242\345\220\216\347\232\204\344\272\214\345\217\211\346\240\221", nullptr));
        label_2->setText(QCoreApplication::translate("BTreePainterUI", "\344\272\214\345\217\211\346\240\221\347\232\204\345\211\215\345\272\217\351\201\215\345\216\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BTreePainterUI: public Ui_BTreePainterUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTREEPAINTERUI_H
