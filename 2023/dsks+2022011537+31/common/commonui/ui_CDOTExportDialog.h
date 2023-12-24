/********************************************************************************
** Form generated from reading UI file 'CDOTExportDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDOTEXPORTDIALOG_H
#define UI_CDOTEXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CDOTExportDialog
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *WriteBackground;
    QCheckBox *WriteAttributes;
    QCheckBox *WriteDefaults;
    QFrame *line;
    QDialogButtonBox *ButtonBox;

    void setupUi(QDialog *CDOTExportDialog)
    {
        if (CDOTExportDialog->objectName().isEmpty())
            CDOTExportDialog->setObjectName(QString::fromUtf8("CDOTExportDialog"));
        CDOTExportDialog->resize(293, 119);
        verticalLayout = new QVBoxLayout(CDOTExportDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        WriteBackground = new QCheckBox(CDOTExportDialog);
        WriteBackground->setObjectName(QString::fromUtf8("WriteBackground"));
        WriteBackground->setChecked(true);

        verticalLayout->addWidget(WriteBackground);

        WriteAttributes = new QCheckBox(CDOTExportDialog);
        WriteAttributes->setObjectName(QString::fromUtf8("WriteAttributes"));
        WriteAttributes->setChecked(true);

        verticalLayout->addWidget(WriteAttributes);

        WriteDefaults = new QCheckBox(CDOTExportDialog);
        WriteDefaults->setObjectName(QString::fromUtf8("WriteDefaults"));
        WriteDefaults->setEnabled(false);
        WriteDefaults->setCheckable(true);
        WriteDefaults->setChecked(true);

        verticalLayout->addWidget(WriteDefaults);

        line = new QFrame(CDOTExportDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        ButtonBox = new QDialogButtonBox(CDOTExportDialog);
        ButtonBox->setObjectName(QString::fromUtf8("ButtonBox"));
        ButtonBox->setOrientation(Qt::Horizontal);
        ButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(ButtonBox);


        retranslateUi(CDOTExportDialog);
        QObject::connect(ButtonBox, SIGNAL(accepted()), CDOTExportDialog, SLOT(accept()));
        QObject::connect(ButtonBox, SIGNAL(rejected()), CDOTExportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CDOTExportDialog);
    } // setupUi

    void retranslateUi(QDialog *CDOTExportDialog)
    {
        CDOTExportDialog->setWindowTitle(QCoreApplication::translate("CDOTExportDialog", "Export to DOT", nullptr));
        WriteBackground->setText(QCoreApplication::translate("CDOTExportDialog", "Write background", nullptr));
        WriteAttributes->setText(QCoreApplication::translate("CDOTExportDialog", "Write node && edge attributes", nullptr));
        WriteDefaults->setText(QCoreApplication::translate("CDOTExportDialog", "Write IDs && topology", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDOTExportDialog: public Ui_CDOTExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDOTEXPORTDIALOG_H
