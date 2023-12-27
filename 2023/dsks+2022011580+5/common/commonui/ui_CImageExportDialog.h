/********************************************************************************
** Form generated from reading UI file 'CImageExportDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIMAGEEXPORTDIALOG_H
#define UI_CIMAGEEXPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CImageExportDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *ButtonBox;
    QSpacerItem *verticalSpacer;
    QLabel *ImageSize;
    QComboBox *Resolution;
    QFrame *line;
    QLabel *label_2;
    QCheckBox *CutToContent;

    void setupUi(QDialog *CImageExportDialog)
    {
        if (CImageExportDialog->objectName().isEmpty())
            CImageExportDialog->setObjectName(QString::fromUtf8("CImageExportDialog"));
        CImageExportDialog->resize(293, 144);
        gridLayout = new QGridLayout(CImageExportDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(CImageExportDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        ButtonBox = new QDialogButtonBox(CImageExportDialog);
        ButtonBox->setObjectName(QString::fromUtf8("ButtonBox"));
        ButtonBox->setOrientation(Qt::Horizontal);
        ButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(ButtonBox, 10, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        ImageSize = new QLabel(CImageExportDialog);
        ImageSize->setObjectName(QString::fromUtf8("ImageSize"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageSize->sizePolicy().hasHeightForWidth());
        ImageSize->setSizePolicy(sizePolicy);
        ImageSize->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(ImageSize, 1, 1, 1, 1);

        Resolution = new QComboBox(CImageExportDialog);
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->addItem(QString());
        Resolution->setObjectName(QString::fromUtf8("Resolution"));
        Resolution->setEditable(true);

        gridLayout->addWidget(Resolution, 1, 0, 1, 1);

        line = new QFrame(CImageExportDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 9, 0, 1, 2);

        label_2 = new QLabel(CImageExportDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        CutToContent = new QCheckBox(CImageExportDialog);
        CutToContent->setObjectName(QString::fromUtf8("CutToContent"));
        CutToContent->setChecked(true);

        gridLayout->addWidget(CutToContent, 2, 0, 1, 1);


        retranslateUi(CImageExportDialog);
        QObject::connect(ButtonBox, SIGNAL(accepted()), CImageExportDialog, SLOT(accept()));
        QObject::connect(ButtonBox, SIGNAL(rejected()), CImageExportDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CImageExportDialog);
    } // setupUi

    void retranslateUi(QDialog *CImageExportDialog)
    {
        CImageExportDialog->setWindowTitle(QCoreApplication::translate("CImageExportDialog", "Export to Image", nullptr));
        label->setText(QCoreApplication::translate("CImageExportDialog", "Resolution (DPI)", nullptr));
        ImageSize->setText(QCoreApplication::translate("CImageExportDialog", "0 x 0", nullptr));
        Resolution->setItemText(0, QCoreApplication::translate("CImageExportDialog", "Auto", nullptr));
        Resolution->setItemText(1, QCoreApplication::translate("CImageExportDialog", "75", nullptr));
        Resolution->setItemText(2, QCoreApplication::translate("CImageExportDialog", "96", nullptr));
        Resolution->setItemText(3, QCoreApplication::translate("CImageExportDialog", "150", nullptr));
        Resolution->setItemText(4, QCoreApplication::translate("CImageExportDialog", "300", nullptr));
        Resolution->setItemText(5, QCoreApplication::translate("CImageExportDialog", "600", nullptr));
        Resolution->setItemText(6, QCoreApplication::translate("CImageExportDialog", "1200", nullptr));

        label_2->setText(QCoreApplication::translate("CImageExportDialog", "Image size (px)", nullptr));
        CutToContent->setText(QCoreApplication::translate("CImageExportDialog", "Cut to content", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CImageExportDialog: public Ui_CImageExportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIMAGEEXPORTDIALOG_H
