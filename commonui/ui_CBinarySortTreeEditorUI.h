/********************************************************************************
** Form generated from reading UI file 'CBinarySortTreeEditorUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CBINARYSORTTREEEDITORUI_H
#define UI_CBINARYSORTTREEEDITORUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CBinarySortTreeEditorUI
{
public:
    QGroupBox* groupBox;
    QLabel* label;
    QLineEdit* BinaryTreeDataEdit;
    QPushButton* nodeDeleteButton;
    QPushButton* BT_createBT;
    //QPushButton *clean_Button;
    QLineEdit* BinaryTreeDataEdit_2;
    QPushButton* pushButton_5;
    QLabel* label_2;

    void setupUi(QWidget* CBinarySortTreeEditorUI)
    {
        if (CBinarySortTreeEditorUI->objectName().isEmpty())
            CBinarySortTreeEditorUI->setObjectName(QString::fromUtf8("CBinarySortTreeEditorUI"));
        CBinarySortTreeEditorUI->resize(638, 768);
        groupBox = new QGroupBox(CBinarySortTreeEditorUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 541, 291));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 200, 200, 200));
        //BinaryTreeDataEdit = new QLineEdit(groupBox);
        //BinaryTreeDataEdit->setObjectName(QString::fromUtf8("BinaryTreeDataEdit"));
        //BinaryTreeDataEdit->setGeometry(QRect(90, 60, 281, 31));
        nodeDeleteButton = new QPushButton(groupBox);
        nodeDeleteButton->setText("±éÀú");
        nodeDeleteButton->setObjectName(QString::fromUtf8("nodeDeleteButton"));

        nodeDeleteButton->setGeometry(QRect(240, 110, 112, 34));
        BT_createBT = new QPushButton(groupBox);
        BT_createBT->setObjectName(QString::fromUtf8("BT_createBT"));
        BT_createBT->setGeometry(QRect(110, 110, 112, 34));
        //clean_Button = new QPushButton(groupBox);
        //clean_Button->setObjectName(QString::fromUtf8("clean_Button"));
        //clean_Button->setGeometry(QRect(240, 110, 112, 34));
        //BinaryTreeDataEdit_2 = new QLineEdit(groupBox);
        //BinaryTreeDataEdit_2->setObjectName(QString::fromUtf8("BinaryTreeDataEdit_2"));
        //BinaryTreeDataEdit_2->setGeometry(QRect(90, 180, 281, 25));
        pushButton_5 = new QPushButton(groupBox);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(110, 110, 0, 0));
        //label_2 = new QLabel(groupBox);
        //label_2->setObjectName(QString::fromUtf8("label_2"));
        //label_2->setGeometry(QRect(220, 160, 81, 18));

        retranslateUi(CBinarySortTreeEditorUI);
        QObject::connect(BT_createBT, SIGNAL(clicked()), CBinarySortTreeEditorUI, SLOT(on_binarytree_create_btn_clicked()));
        //QObject::connect(clean_Button, SIGNAL(clicked()), CBinarySortTreeEditorUI, SLOT(on_binarytree_delete_btn_clicked()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), CBinarySortTreeEditorUI, SLOT(on_binarytree_node_search_btn_clicked()));
        QObject::connect(nodeDeleteButton, SIGNAL(clicked()), CBinarySortTreeEditorUI, SLOT(on_binarytree_node_delete_btn_clicked()));

        QMetaObject::connectSlotsByName(CBinarySortTreeEditorUI);
    } // setupUi

    void retranslateUi(QWidget* CBinarySortTreeEditorUI)
    {
        CBinarySortTreeEditorUI->setWindowTitle(QCoreApplication::translate("CBinarySortTreeEditorUI", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CBinarySortTreeEditorUI", "\345\271\263\350\241\241\344\272\214\345\217\211\346\240\221", nullptr));
        label->setText(QCoreApplication::translate("CBinarySortTreeEditorUI", "\350\257\267\350\276\223\345\205\245\346\225\260\346\215\256\357\274\214\347\224\250\342\200\234\357\274\214\342\200\235\351\232\224\345\274\200", nullptr));
        //nodeDeleteButton->setText(QCoreApplication::translate("CBinarySortTreeEditorUI", "\345\210\240\351\231\244", nullptr));
        //nodeDeleteButton->setText("±éÀú");
        nodeDeleteButton->setText(QCoreApplication::translate("CBinarySortTreeEditorUI", "\345\257\273\346\211\276\346\234\200\351\225\277\350\267\257\345\276\204", nullptr));
        BT_createBT->setText(QCoreApplication::translate("CBinarySortTreeEditorUI", "\345\210\233\345\273\272", nullptr));
        //clean_Button->setText(QCoreApplication::translate("CBinarySortTreeEditorUI", "\346\270\205\347\251\272", nullptr));
        pushButton_5->setText(QCoreApplication::translate("CBinarySortTreeEditorUI", "\346\220\234\347\264\242", nullptr));
        //label_2->setText(QCoreApplication::translate("CBinarySortTreeEditorUI", "\350\212\202\347\202\271\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CBinarySortTreeEditorUI: public Ui_CBinarySortTreeEditorUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CBINARYSORTTREEEDITORUI_H
