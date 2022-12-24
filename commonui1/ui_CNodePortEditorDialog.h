/********************************************************************************
** Form generated from reading UI file 'CNodePortEditorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CNODEPORTEDITORDIALOG_H
#define UI_CNODEPORTEDITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "colorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_CNodePortEditorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *Anchor;
    QLabel *label;
    QLineEdit *PortId;
    QLabel *label_4;
    QSpinBox *OffsetY;
    QLabel *label_3;
    QLabel *label_5;
    QSpinBox *OffsetX;
    QSint::ColorButton *Color;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CNodePortEditorDialog)
    {
        if (CNodePortEditorDialog->objectName().isEmpty())
            CNodePortEditorDialog->setObjectName(QString::fromUtf8("CNodePortEditorDialog"));
        CNodePortEditorDialog->resize(319, 132);
        CNodePortEditorDialog->setModal(true);
        verticalLayout = new QVBoxLayout(CNodePortEditorDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(CNodePortEditorDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        Anchor = new QComboBox(CNodePortEditorDialog);
        Anchor->setObjectName(QString::fromUtf8("Anchor"));

        gridLayout->addWidget(Anchor, 1, 2, 1, 1);

        label = new QLabel(CNodePortEditorDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        PortId = new QLineEdit(CNodePortEditorDialog);
        PortId->setObjectName(QString::fromUtf8("PortId"));

        gridLayout->addWidget(PortId, 0, 2, 1, 3);

        label_4 = new QLabel(CNodePortEditorDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 3, 1, 1);

        OffsetY = new QSpinBox(CNodePortEditorDialog);
        OffsetY->setObjectName(QString::fromUtf8("OffsetY"));
        OffsetY->setMinimum(-1000);
        OffsetY->setMaximum(1000);
        OffsetY->setSingleStep(10);

        gridLayout->addWidget(OffsetY, 2, 4, 1, 1);

        label_3 = new QLabel(CNodePortEditorDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 3, 1, 1);

        label_5 = new QLabel(CNodePortEditorDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        OffsetX = new QSpinBox(CNodePortEditorDialog);
        OffsetX->setObjectName(QString::fromUtf8("OffsetX"));
        OffsetX->setMinimum(-1000);
        OffsetX->setMaximum(1000);
        OffsetX->setSingleStep(10);

        gridLayout->addWidget(OffsetX, 1, 4, 1, 1);

        Color = new QSint::ColorButton(CNodePortEditorDialog);
        Color->setObjectName(QString::fromUtf8("Color"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Color->sizePolicy().hasHeightForWidth());
        Color->setSizePolicy(sizePolicy);
        Color->setPopupMode(QToolButton::InstantPopup);
        Color->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(Color, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line = new QFrame(CNodePortEditorDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonBox = new QDialogButtonBox(CNodePortEditorDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(PortId, Anchor);
        QWidget::setTabOrder(Anchor, Color);
        QWidget::setTabOrder(Color, OffsetX);
        QWidget::setTabOrder(OffsetX, OffsetY);

        retranslateUi(CNodePortEditorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CNodePortEditorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CNodePortEditorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CNodePortEditorDialog);
    } // setupUi

    void retranslateUi(QDialog *CNodePortEditorDialog)
    {
        CNodePortEditorDialog->setWindowTitle(QCoreApplication::translate("CNodePortEditorDialog", "Edit Node Port", nullptr));
        label_2->setText(QCoreApplication::translate("CNodePortEditorDialog", "Anchor", nullptr));
        label->setText(QCoreApplication::translate("CNodePortEditorDialog", "Id", nullptr));
        label_4->setText(QCoreApplication::translate("CNodePortEditorDialog", "Y-offset", nullptr));
        label_3->setText(QCoreApplication::translate("CNodePortEditorDialog", "X-offset", nullptr));
        label_5->setText(QCoreApplication::translate("CNodePortEditorDialog", "Color", nullptr));
        Color->setText(QCoreApplication::translate("CNodePortEditorDialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CNodePortEditorDialog: public Ui_CNodePortEditorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CNODEPORTEDITORDIALOG_H
