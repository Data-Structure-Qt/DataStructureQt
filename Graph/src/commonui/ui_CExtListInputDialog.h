/********************************************************************************
** Form generated from reading UI file 'CExtListInputDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CEXTLISTINPUTDIALOG_H
#define UI_CEXTLISTINPUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CExtListInputDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CExtListInputDialog)
    {
        if (CExtListInputDialog->objectName().isEmpty())
            CExtListInputDialog->setObjectName(QString::fromUtf8("CExtListInputDialog"));
        CExtListInputDialog->resize(330, 86);
        verticalLayout = new QVBoxLayout(CExtListInputDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(CExtListInputDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(CExtListInputDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        buttonBox = new QDialogButtonBox(CExtListInputDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CExtListInputDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CExtListInputDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CExtListInputDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CExtListInputDialog);
    } // setupUi

    void retranslateUi(QDialog *CExtListInputDialog)
    {
        CExtListInputDialog->setWindowTitle(QCoreApplication::translate("CExtListInputDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("CExtListInputDialog", "Select an item:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CExtListInputDialog: public Ui_CExtListInputDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CEXTLISTINPUTDIALOG_H
