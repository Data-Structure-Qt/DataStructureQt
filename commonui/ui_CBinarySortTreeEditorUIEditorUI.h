/********************************************************************************
** Form generated from reading UI file 'CBinarySortTreeEditorUIEditorUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CBINARYSORTTREEEDITORUIEDITORUI_H
#define UI_CBINARYSORTTREEEDITORUIEDITORUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CBinarySortTreeEditorUI
{
public:
    QGroupBox *groupBox;
    QPushButton *BT_creatBT;
    QPushButton *nodeDeleteButton;

    void setupUi(QWidget *CBinarySortTreeEditorUI)
    {
        if (CBinarySortTreeEditorUI->objectName().isEmpty())
            CBinarySortTreeEditorUI->setObjectName(QString::fromUtf8("CBinarySortTreeEditorUI"));
        CBinarySortTreeEditorUI->resize(320, 321);
        groupBox = new QGroupBox(CBinarySortTreeEditorUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(-10, 10, 341, 301));
        BT_creatBT = new QPushButton(groupBox);
        BT_creatBT->setObjectName(QString::fromUtf8("BT_creatBT"));
        BT_creatBT->setGeometry(QRect(40, 80, 93, 28));
        nodeDeleteButton = new QPushButton(groupBox);
        nodeDeleteButton->setObjectName(QString::fromUtf8("nodeDeleteButton"));
        nodeDeleteButton->setGeometry(QRect(160, 80, 151, 28));

        retranslateUi(CBinarySortTreeEditorUI);
        QObject::connect(BT_creatBT, SIGNAL(clicked()), CBinarySortTreeEditorUI, SLOT(on_binarytree_create_btn_clicked()));
        QObject::connect(nodeDeleteButton, SIGNAL(clicked()), CBinarySortTreeEditorUI, SLOT(on_binarytree_node_delete_btn_clicked()));

        QMetaObject::connectSlotsByName(CBinarySortTreeEditorUI);
    } // setupUi

    void retranslateUi(QWidget *CBinarySortTreeEditorUI)
    {
        CBinarySortTreeEditorUI->setWindowTitle(QCoreApplication::translate("CBinarySortTreeEditorUI", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CBinarySortTreeEditorUI", "\345\271\263\350\241\241\344\272\214\345\217\211\346\240\221", nullptr));
        BT_creatBT->setText(QCoreApplication::translate("CBinarySortTreeEditorUI", "\345\210\233\345\273\272\344\270\211\345\217\211\346\240\221", nullptr));
        nodeDeleteButton->setText(QCoreApplication::translate("CBinarySortTreeEditorUI", "\351\201\215\345\216\206\345\257\273\346\211\276\346\234\200\351\225\277\350\267\257\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CBinarySortTreeEditorUI: public Ui_CBinarySortTreeEditorUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CBINARYSORTTREEEDITORUIEDITORUI_H
