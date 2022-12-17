/********************************************************************************
** Form generated from reading UI file 'CGraphEditorUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
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
    QPushButton *BFSpushButton;
    QPushButton *DFSpushButton;
    QPushButton *DjpushButton;
    QPushButton *ResetpushButton;
    QPushButton *PrimpushButton;
    QPushButton *pushButton;
    QPushButton *TopoButton;

    void setupUi(QWidget *CGraphEditorUI)
    {
        if (CGraphEditorUI->objectName().isEmpty())
            CGraphEditorUI->setObjectName(QString::fromUtf8("CGraphEditorUI"));
        CGraphEditorUI->resize(335, 194);
        BFSpushButton = new QPushButton(CGraphEditorUI);
        BFSpushButton->setObjectName(QString::fromUtf8("BFSpushButton"));
        BFSpushButton->setGeometry(QRect(20, 10, 101, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        BFSpushButton->setFont(font);
        DFSpushButton = new QPushButton(CGraphEditorUI);
        DFSpushButton->setObjectName(QString::fromUtf8("DFSpushButton"));
        DFSpushButton->setGeometry(QRect(132, 10, 101, 31));
        DFSpushButton->setFont(font);
        DjpushButton = new QPushButton(CGraphEditorUI);
        DjpushButton->setObjectName(QString::fromUtf8("DjpushButton"));
        DjpushButton->setGeometry(QRect(20, 80, 101, 31));
        DjpushButton->setFont(font);
        ResetpushButton = new QPushButton(CGraphEditorUI);
        ResetpushButton->setObjectName(QString::fromUtf8("ResetpushButton"));
        ResetpushButton->setGeometry(QRect(20, 119, 213, 31));
        ResetpushButton->setFont(font);
        PrimpushButton = new QPushButton(CGraphEditorUI);
        PrimpushButton->setObjectName(QString::fromUtf8("PrimpushButton"));
        PrimpushButton->setGeometry(QRect(20, 45, 101, 31));
        PrimpushButton->setFont(font);
        pushButton = new QPushButton(CGraphEditorUI);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(132, 45, 101, 31));
        pushButton->setFont(font);
        TopoButton = new QPushButton(CGraphEditorUI);
        TopoButton->setObjectName(QString::fromUtf8("TopoButton"));
        TopoButton->setGeometry(QRect(132, 80, 101, 31));
        TopoButton->setFont(font);

        retranslateUi(CGraphEditorUI);
        QObject::connect(DFSpushButton, SIGNAL(clicked()), CGraphEditorUI, SLOT(on_dfs_btn_clicked()));
        QObject::connect(BFSpushButton, SIGNAL(clicked()), CGraphEditorUI, SLOT(on_bfs_btn_clicked()));
        QObject::connect(PrimpushButton, SIGNAL(clicked()), CGraphEditorUI, SLOT(on_prim_btn_clicked()));
        QObject::connect(pushButton, SIGNAL(clicked()), CGraphEditorUI, SLOT(on_kruskal_btn_clicked()));
        QObject::connect(DjpushButton, SIGNAL(clicked()), CGraphEditorUI, SLOT(on_dijkstra_btn_clicked()));
        QObject::connect(TopoButton, SIGNAL(clicked()), CGraphEditorUI, SLOT(on_topologicalSorting_btn_clicked()));
        QObject::connect(ResetpushButton, SIGNAL(clicked()), CGraphEditorUI, SLOT(on_reset_btn_clicked()));

        QMetaObject::connectSlotsByName(CGraphEditorUI);
    } // setupUi

    void retranslateUi(QWidget *CGraphEditorUI)
    {
        CGraphEditorUI->setWindowTitle(QCoreApplication::translate("CGraphEditorUI", "Form", nullptr));
        BFSpushButton->setText(QCoreApplication::translate("CGraphEditorUI", "BFS", nullptr));
        DFSpushButton->setText(QCoreApplication::translate("CGraphEditorUI", "DFS", nullptr));
        DjpushButton->setText(QCoreApplication::translate("CGraphEditorUI", "Dijkstra", nullptr));
        ResetpushButton->setText(QCoreApplication::translate("CGraphEditorUI", "\351\207\215\347\275\256", nullptr));
        PrimpushButton->setText(QCoreApplication::translate("CGraphEditorUI", "Prim", nullptr));
        pushButton->setText(QCoreApplication::translate("CGraphEditorUI", "Kruskal", nullptr));
        TopoButton->setText(QCoreApplication::translate("CGraphEditorUI", "Topo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CGraphEditorUI: public Ui_CGraphEditorUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CGRAPHEDITORUI_H
