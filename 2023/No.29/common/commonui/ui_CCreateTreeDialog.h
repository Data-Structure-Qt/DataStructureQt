/********************************************************************************
** Form generated from reading UI file 'CCreateTreeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCREATETREEDIALOG_H
#define UI_CCREATETREEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CCreateTreeDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *treestrEdit;
    QLabel *label;

    void setupUi(QDialog *CCreateTreeDialog)
    {
        if (CCreateTreeDialog->objectName().isEmpty())
            CCreateTreeDialog->setObjectName(QString::fromUtf8("CCreateTreeDialog"));
        CCreateTreeDialog->resize(429, 130);
        buttonBox = new QDialogButtonBox(CCreateTreeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(20, 80, 381, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        treestrEdit = new QLineEdit(CCreateTreeDialog);
        treestrEdit->setObjectName(QString::fromUtf8("treestrEdit"));
        treestrEdit->setGeometry(QRect(20, 40, 391, 31));
        label = new QLabel(CCreateTreeDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 371, 16));

        retranslateUi(CCreateTreeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CCreateTreeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CCreateTreeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CCreateTreeDialog);
    } // setupUi

    void retranslateUi(QDialog *CCreateTreeDialog)
    {
        CCreateTreeDialog->setWindowTitle(QCoreApplication::translate("CCreateTreeDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CCreateTreeDialog", "Please input the pre_order with \"#\" of the tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CCreateTreeDialog: public Ui_CCreateTreeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCREATETREEDIALOG_H
