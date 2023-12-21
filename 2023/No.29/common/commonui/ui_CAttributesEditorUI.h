/********************************************************************************
** Form generated from reading UI file 'CAttributesEditorUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATTRIBUTESEDITORUI_H
#define UI_CATTRIBUTESEDITORUI_H

#include <CPropertyEditorUIBase.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CAttributesEditorUI
{
public:
    QVBoxLayout *verticalLayout;
    CPropertyEditorUIBase *Editor;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddButton;
    QPushButton *ChangeButton;
    QPushButton *RemoveButton;

    void setupUi(QWidget *CAttributesEditorUI)
    {
        if (CAttributesEditorUI->objectName().isEmpty())
            CAttributesEditorUI->setObjectName(QString::fromUtf8("CAttributesEditorUI"));
        CAttributesEditorUI->resize(400, 300);
        verticalLayout = new QVBoxLayout(CAttributesEditorUI);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Editor = new CPropertyEditorUIBase(CAttributesEditorUI);
        Editor->setObjectName(QString::fromUtf8("Editor"));

        verticalLayout->addWidget(Editor);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        AddButton = new QPushButton(CAttributesEditorUI);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));

        horizontalLayout->addWidget(AddButton);

        ChangeButton = new QPushButton(CAttributesEditorUI);
        ChangeButton->setObjectName(QString::fromUtf8("ChangeButton"));

        horizontalLayout->addWidget(ChangeButton);

        RemoveButton = new QPushButton(CAttributesEditorUI);
        RemoveButton->setObjectName(QString::fromUtf8("RemoveButton"));

        horizontalLayout->addWidget(RemoveButton);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(Editor, AddButton);
        QWidget::setTabOrder(AddButton, ChangeButton);
        QWidget::setTabOrder(ChangeButton, RemoveButton);

        retranslateUi(CAttributesEditorUI);

        QMetaObject::connectSlotsByName(CAttributesEditorUI);
    } // setupUi

    void retranslateUi(QWidget *CAttributesEditorUI)
    {
        CAttributesEditorUI->setWindowTitle(QCoreApplication::translate("CAttributesEditorUI", "Custom Attributes", nullptr));
#if QT_CONFIG(statustip)
        AddButton->setStatusTip(QCoreApplication::translate("CAttributesEditorUI", "Add new custom attribute for the selected items", nullptr));
#endif // QT_CONFIG(statustip)
        AddButton->setText(QCoreApplication::translate("CAttributesEditorUI", "\345\242\236\345\212\240...", nullptr));
#if QT_CONFIG(tooltip)
        ChangeButton->setToolTip(QCoreApplication::translate("CAttributesEditorUI", "Change selected attribute's id and type", nullptr));
#endif // QT_CONFIG(tooltip)
        ChangeButton->setText(QCoreApplication::translate("CAttributesEditorUI", "\346\224\271\345\217\230...", nullptr));
#if QT_CONFIG(statustip)
        RemoveButton->setStatusTip(QCoreApplication::translate("CAttributesEditorUI", "Remove the attribute from the selected items", nullptr));
#endif // QT_CONFIG(statustip)
        RemoveButton->setText(QCoreApplication::translate("CAttributesEditorUI", "\345\216\273\351\231\244...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CAttributesEditorUI: public Ui_CAttributesEditorUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATTRIBUTESEDITORUI_H
