/********************************************************************************
** Form generated from reading UI file 'CNewAttributeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CNEWATTRIBUTEDIALOG_H
#define UI_CNEWATTRIBUTEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CNewAttributeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *Id;
    QLabel *label_2;
    QComboBox *Type;
    QFrame *line;
    QDialogButtonBox *ButtonBox;

    void setupUi(QDialog *CNewAttributeDialog)
    {
        if (CNewAttributeDialog->objectName().isEmpty())
            CNewAttributeDialog->setObjectName(QString::fromUtf8("CNewAttributeDialog"));
        CNewAttributeDialog->resize(349, 107);
        verticalLayout = new QVBoxLayout(CNewAttributeDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(CNewAttributeDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(100, 0));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        Id = new QLineEdit(CNewAttributeDialog);
        Id->setObjectName(QString::fromUtf8("Id"));

        formLayout->setWidget(0, QFormLayout::FieldRole, Id);

        label_2 = new QLabel(CNewAttributeDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(100, 0));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        Type = new QComboBox(CNewAttributeDialog);
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->setObjectName(QString::fromUtf8("Type"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Type);


        verticalLayout->addLayout(formLayout);

        line = new QFrame(CNewAttributeDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        ButtonBox = new QDialogButtonBox(CNewAttributeDialog);
        ButtonBox->setObjectName(QString::fromUtf8("ButtonBox"));
        ButtonBox->setOrientation(Qt::Horizontal);
        ButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(ButtonBox);


        retranslateUi(CNewAttributeDialog);
        QObject::connect(ButtonBox, SIGNAL(accepted()), CNewAttributeDialog, SLOT(accept()));
        QObject::connect(ButtonBox, SIGNAL(rejected()), CNewAttributeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CNewAttributeDialog);
    } // setupUi

    void retranslateUi(QDialog *CNewAttributeDialog)
    {
        CNewAttributeDialog->setWindowTitle(QCoreApplication::translate("CNewAttributeDialog", "Add New Attribute", nullptr));
        label->setText(QCoreApplication::translate("CNewAttributeDialog", "Id", nullptr));
        Id->setPlaceholderText(QCoreApplication::translate("CNewAttributeDialog", "Id of the attribute (cannot be empty)", nullptr));
        label_2->setText(QCoreApplication::translate("CNewAttributeDialog", "Type", nullptr));
        Type->setItemText(0, QCoreApplication::translate("CNewAttributeDialog", "Integer", nullptr));
        Type->setItemText(1, QCoreApplication::translate("CNewAttributeDialog", "Real", nullptr));
        Type->setItemText(2, QCoreApplication::translate("CNewAttributeDialog", "Boolean", nullptr));
        Type->setItemText(3, QCoreApplication::translate("CNewAttributeDialog", "Color", nullptr));
        Type->setItemText(4, QCoreApplication::translate("CNewAttributeDialog", "Font", nullptr));
        Type->setItemText(5, QCoreApplication::translate("CNewAttributeDialog", "String", nullptr));

    } // retranslateUi

};

namespace Ui {
    class CNewAttributeDialog: public Ui_CNewAttributeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CNEWATTRIBUTEDIALOG_H
