/********************************************************************************
** Form generated from reading UI file 'CLinklistEditorUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLINKLISTEDITORUI_H
#define UI_CLINKLISTEDITORUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLinklistEditorUI
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *CLinklistEditorUI)
    {
        if (CLinklistEditorUI->objectName().isEmpty())
            CLinklistEditorUI->setObjectName(QString::fromUtf8("CLinklistEditorUI"));
        CLinklistEditorUI->resize(371, 288);
        pushButton = new QPushButton(CLinklistEditorUI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 20, 93, 28));
        pushButton_2 = new QPushButton(CLinklistEditorUI);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 60, 93, 28));
        pushButton_3 = new QPushButton(CLinklistEditorUI);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 140, 93, 28));
        pushButton_4 = new QPushButton(CLinklistEditorUI);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(120, 100, 101, 28));

        retranslateUi(CLinklistEditorUI);
        QObject::connect(pushButton, SIGNAL(clicked()), CLinklistEditorUI, SLOT(on_bfs_btn_clicked()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), CLinklistEditorUI, SLOT(on_dfs_btn_clicked()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), CLinklistEditorUI, SLOT(on_reset_btn_clicked()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), CLinklistEditorUI, SLOT(on_dijkstra_btn_clicked()));

        QMetaObject::connectSlotsByName(CLinklistEditorUI);
    } // setupUi

    void retranslateUi(QWidget *CLinklistEditorUI)
    {
        CLinklistEditorUI->setWindowTitle(QCoreApplication::translate("CLinklistEditorUI", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("CLinklistEditorUI", "BFS\351\201\215\345\216\206", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CLinklistEditorUI", "DFS\351\201\215\345\216\206", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CLinklistEditorUI", "\351\207\215\347\275\256", nullptr));
        pushButton_4->setText(QCoreApplication::translate("CLinklistEditorUI", "Dijkstra\350\267\257\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CLinklistEditorUI: public Ui_CLinklistEditorUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLINKLISTEDITORUI_H
