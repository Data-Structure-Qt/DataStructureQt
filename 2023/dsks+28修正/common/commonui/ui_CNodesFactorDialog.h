/********************************************************************************
** Form generated from reading UI file 'CNodesFactorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CNODESFACTORDIALOG_H
#define UI_CNODESFACTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CNodesFactorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_3;
    QSpinBox *FactorY;
    QSpinBox *FactorX;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CNodesFactorDialog)
    {
        if (CNodesFactorDialog->objectName().isEmpty())
            CNodesFactorDialog->setObjectName(QString::fromUtf8("CNodesFactorDialog"));
        CNodesFactorDialog->resize(241, 106);
        CNodesFactorDialog->setModal(true);
        verticalLayout = new QVBoxLayout(CNodesFactorDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(CNodesFactorDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(CNodesFactorDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        FactorY = new QSpinBox(CNodesFactorDialog);
        FactorY->setObjectName(QString::fromUtf8("FactorY"));
        FactorY->setMinimum(1);
        FactorY->setMaximum(10000);
        FactorY->setSingleStep(10);
        FactorY->setValue(100);

        gridLayout->addWidget(FactorY, 1, 1, 1, 1);

        FactorX = new QSpinBox(CNodesFactorDialog);
        FactorX->setObjectName(QString::fromUtf8("FactorX"));
        FactorX->setMinimum(1);
        FactorX->setMaximum(10000);
        FactorX->setSingleStep(10);
        FactorX->setValue(100);

        gridLayout->addWidget(FactorX, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line = new QFrame(CNodesFactorDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonBox = new QDialogButtonBox(CNodesFactorDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CNodesFactorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CNodesFactorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CNodesFactorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CNodesFactorDialog);
    } // setupUi

    void retranslateUi(QDialog *CNodesFactorDialog)
    {
        CNodesFactorDialog->setWindowTitle(QCoreApplication::translate("CNodesFactorDialog", "Factor Nodes", nullptr));
        label_4->setText(QCoreApplication::translate("CNodesFactorDialog", "Y-factor:", nullptr));
        label_3->setText(QCoreApplication::translate("CNodesFactorDialog", "X-factor:", nullptr));
        FactorY->setSuffix(QCoreApplication::translate("CNodesFactorDialog", " %", nullptr));
        FactorX->setSuffix(QCoreApplication::translate("CNodesFactorDialog", " %", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CNodesFactorDialog: public Ui_CNodesFactorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CNODESFACTORDIALOG_H
