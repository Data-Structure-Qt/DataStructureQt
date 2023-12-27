/********************************************************************************
** Form generated from reading UI file 'CQuickHelpUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CQUICKHELPUI_H
#define UI_CQUICKHELPUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CQuickHelpUI
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *Viewer;

    void setupUi(QWidget *CQuickHelpUI)
    {
        if (CQuickHelpUI->objectName().isEmpty())
            CQuickHelpUI->setObjectName(QString::fromUtf8("CQuickHelpUI"));
        CQuickHelpUI->resize(411, 300);
        verticalLayout = new QVBoxLayout(CQuickHelpUI);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Viewer = new QTextBrowser(CQuickHelpUI);
        Viewer->setObjectName(QString::fromUtf8("Viewer"));

        verticalLayout->addWidget(Viewer);


        retranslateUi(CQuickHelpUI);

        QMetaObject::connectSlotsByName(CQuickHelpUI);
    } // setupUi

    void retranslateUi(QWidget *CQuickHelpUI)
    {
        CQuickHelpUI->setWindowTitle(QCoreApplication::translate("CQuickHelpUI", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CQuickHelpUI: public Ui_CQuickHelpUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CQUICKHELPUI_H
