/********************************************************************************
** Form generated from reading UI file 'CCommutationTable.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCOMMUTATIONTABLE_H
#define UI_CCOMMUTATIONTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CCommutationTable
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *Table;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddColumnButton;
    QPushButton *RestoreButton;

    void setupUi(QWidget *CCommutationTable)
    {
        if (CCommutationTable->objectName().isEmpty())
            CCommutationTable->setObjectName(QString::fromUtf8("CCommutationTable"));
        CCommutationTable->resize(400, 300);
        verticalLayout = new QVBoxLayout(CCommutationTable);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Table = new QTreeWidget(CCommutationTable);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("Start Node"));
        Table->setHeaderItem(__qtreewidgetitem);
        Table->setObjectName(QString::fromUtf8("Table"));
        Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Table->setAlternatingRowColors(true);
        Table->setSelectionMode(QAbstractItemView::ExtendedSelection);
        Table->setRootIsDecorated(true);
        Table->setSortingEnabled(true);
        Table->setAllColumnsShowFocus(true);
        Table->header()->setCascadingSectionResizes(true);

        verticalLayout->addWidget(Table);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(134, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        AddColumnButton = new QPushButton(CCommutationTable);
        AddColumnButton->setObjectName(QString::fromUtf8("AddColumnButton"));

        horizontalLayout->addWidget(AddColumnButton);

        RestoreButton = new QPushButton(CCommutationTable);
        RestoreButton->setObjectName(QString::fromUtf8("RestoreButton"));

        horizontalLayout->addWidget(RestoreButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CCommutationTable);

        QMetaObject::connectSlotsByName(CCommutationTable);
    } // setupUi

    void retranslateUi(QWidget *CCommutationTable)
    {
        CCommutationTable->setWindowTitle(QCoreApplication::translate("CCommutationTable", "Form", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = Table->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("CCommutationTable", "Edge", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("CCommutationTable", "End Node", nullptr));
#if QT_CONFIG(statustip)
        AddColumnButton->setStatusTip(QCoreApplication::translate("CCommutationTable", "Append new edge attribute column  | Right-click on a column's header - insert/delete a column at exact position", nullptr));
#endif // QT_CONFIG(statustip)
        AddColumnButton->setText(QCoreApplication::translate("CCommutationTable", "New Column...", nullptr));
#if QT_CONFIG(statustip)
        RestoreButton->setStatusTip(QCoreApplication::translate("CCommutationTable", "Restore default columns (remove custom ones)", nullptr));
#endif // QT_CONFIG(statustip)
        RestoreButton->setText(QCoreApplication::translate("CCommutationTable", "Restore Defaults...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CCommutationTable: public Ui_CCommutationTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCOMMUTATIONTABLE_H
