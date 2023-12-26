/********************************************************************************
** Form generated from reading UI file 'CCSVImportDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCSVIMPORTDIALOG_H
#define UI_CCSVIMPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include "CEasyTableWidget.h"

QT_BEGIN_NAMESPACE

class Ui_CCSVImportDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *CommaDelim;
    QRadioButton *PointCommaDelim;
    QRadioButton *TabDelim;
    QRadioButton *CustomDelim;
    QLineEdit *CustomDelimEdit;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    CEasyTableWidget *PreviewTable;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *RawPreview;
    QFrame *line;
    QDialogButtonBox *ButtonBox;

    void setupUi(QDialog *CCSVImportDialog)
    {
        if (CCSVImportDialog->objectName().isEmpty())
            CCSVImportDialog->setObjectName(QString::fromUtf8("CCSVImportDialog"));
        CCSVImportDialog->resize(933, 610);
        verticalLayout = new QVBoxLayout(CCSVImportDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(CCSVImportDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setFlat(true);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CommaDelim = new QRadioButton(groupBox);
        CommaDelim->setObjectName(QString::fromUtf8("CommaDelim"));
        CommaDelim->setChecked(true);

        horizontalLayout->addWidget(CommaDelim);

        PointCommaDelim = new QRadioButton(groupBox);
        PointCommaDelim->setObjectName(QString::fromUtf8("PointCommaDelim"));

        horizontalLayout->addWidget(PointCommaDelim);

        TabDelim = new QRadioButton(groupBox);
        TabDelim->setObjectName(QString::fromUtf8("TabDelim"));

        horizontalLayout->addWidget(TabDelim);

        CustomDelim = new QRadioButton(groupBox);
        CustomDelim->setObjectName(QString::fromUtf8("CustomDelim"));

        horizontalLayout->addWidget(CustomDelim);

        CustomDelimEdit = new QLineEdit(groupBox);
        CustomDelimEdit->setObjectName(QString::fromUtf8("CustomDelimEdit"));
        CustomDelimEdit->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(CustomDelimEdit->sizePolicy().hasHeightForWidth());
        CustomDelimEdit->setSizePolicy(sizePolicy1);
        CustomDelimEdit->setMaxLength(10);

        horizontalLayout->addWidget(CustomDelimEdit);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(CCSVImportDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(true);
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        PreviewTable = new CEasyTableWidget(groupBox_2);
        PreviewTable->setObjectName(QString::fromUtf8("PreviewTable"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(PreviewTable->sizePolicy().hasHeightForWidth());
        PreviewTable->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(PreviewTable);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(CCSVImportDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setFlat(true);
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        RawPreview = new QTextBrowser(groupBox_3);
        RawPreview->setObjectName(QString::fromUtf8("RawPreview"));

        horizontalLayout_3->addWidget(RawPreview);


        verticalLayout->addWidget(groupBox_3);

        line = new QFrame(CCSVImportDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        ButtonBox = new QDialogButtonBox(CCSVImportDialog);
        ButtonBox->setObjectName(QString::fromUtf8("ButtonBox"));
        ButtonBox->setOrientation(Qt::Horizontal);
        ButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(ButtonBox);

        QWidget::setTabOrder(CommaDelim, PointCommaDelim);
        QWidget::setTabOrder(PointCommaDelim, TabDelim);
        QWidget::setTabOrder(TabDelim, PreviewTable);

        retranslateUi(CCSVImportDialog);
        QObject::connect(ButtonBox, SIGNAL(accepted()), CCSVImportDialog, SLOT(accept()));
        QObject::connect(ButtonBox, SIGNAL(rejected()), CCSVImportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CCSVImportDialog);
    } // setupUi

    void retranslateUi(QDialog *CCSVImportDialog)
    {
        CCSVImportDialog->setWindowTitle(QCoreApplication::translate("CCSVImportDialog", "Import from CSV", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CCSVImportDialog", "Columns separator", nullptr));
        CommaDelim->setText(QCoreApplication::translate("CCSVImportDialog", ",", nullptr));
        PointCommaDelim->setText(QCoreApplication::translate("CCSVImportDialog", ";", nullptr));
        TabDelim->setText(QCoreApplication::translate("CCSVImportDialog", "Tab", nullptr));
        CustomDelim->setText(QCoreApplication::translate("CCSVImportDialog", "Custom", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CCSVImportDialog", "Columns preview", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("CCSVImportDialog", "Raw preview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CCSVImportDialog: public Ui_CCSVImportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCSVIMPORTDIALOG_H
