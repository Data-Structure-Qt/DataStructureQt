/********************************************************************************
** Form generated from reading UI file 'CGraphEditorUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CGRAPHEDITORUI_H
#define UI_CGRAPHEDITORUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGraphEditorUI
{
public:
    QPushButton *ResetpushButton;
    QPushButton *NoTopopushButton;

    void setupUi(QWidget *CGraphEditorUI)
    {
        if (CGraphEditorUI->objectName().isEmpty())
            CGraphEditorUI->setObjectName(QString::fromUtf8("CGraphEditorUI"));
        CGraphEditorUI->resize(400, 300);
        ResetpushButton = new QPushButton(CGraphEditorUI);
        ResetpushButton->setObjectName(QString::fromUtf8("ResetpushButton"));
        ResetpushButton->setGeometry(QRect(130, 210, 112, 34));
        NoTopopushButton = new QPushButton(CGraphEditorUI);
        NoTopopushButton->setObjectName(QString::fromUtf8("NoTopopushButton"));
        NoTopopushButton->setGeometry(QRect(130, 120, 112, 34));

        retranslateUi(CGraphEditorUI);
        QObject::connect(ResetpushButton, SIGNAL(clicked()), CGraphEditorUI, SLOT(on_reset_btn_clicked()));
        QObject::connect(NoTopopushButton, SIGNAL(clicked()), CGraphEditorUI, SLOT(on_Non_topologicalSorting_btn_clicked()));

        QMetaObject::connectSlotsByName(CGraphEditorUI);
    } // setupUi

    void retranslateUi(QWidget *CGraphEditorUI)
    {
        CGraphEditorUI->setWindowTitle(QCoreApplication::translate("CGraphEditorUI", "Form", nullptr));
        ResetpushButton->setText(QCoreApplication::translate("CGraphEditorUI", "\351\207\215\347\275\256", nullptr));
        NoTopopushButton->setText(QCoreApplication::translate("CGraphEditorUI", "No_Topo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGraphEditorUI: public Ui_CGraphEditorUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGRAPHEDITORUI_H
