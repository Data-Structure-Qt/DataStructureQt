/********************************************************************************
** Form generated from reading UI file 'CClassAttributesEditorUI.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCLASSATTRIBUTESEDITORUI_H
#define UI_CCLASSATTRIBUTESEDITORUI_H

#include <CPropertyEditorUIBase.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CClassAttributesEditorUI
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *GraphButton;
    QToolButton *NodeButton;
    QToolButton *EdgeButton;
    QSpacerItem *horizontalSpacer_2;
    CPropertyEditorUIBase *Editor;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *AddButton;
    QPushButton *ChangeButton;
    QPushButton *RemoveButton;

    void setupUi(QWidget *CClassAttributesEditorUI)
    {
        if (CClassAttributesEditorUI->objectName().isEmpty())
            CClassAttributesEditorUI->setObjectName(QString::fromUtf8("CClassAttributesEditorUI"));
        CClassAttributesEditorUI->resize(384, 300);
        verticalLayout = new QVBoxLayout(CClassAttributesEditorUI);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        GraphButton = new QToolButton(CClassAttributesEditorUI);
        GraphButton->setObjectName(QString::fromUtf8("GraphButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GraphButton->sizePolicy().hasHeightForWidth());
        GraphButton->setSizePolicy(sizePolicy);
        GraphButton->setMinimumSize(QSize(60, 23));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/Graph"), QSize(), QIcon::Normal, QIcon::Off);
        GraphButton->setIcon(icon);
        GraphButton->setIconSize(QSize(20, 20));
        GraphButton->setCheckable(true);
        GraphButton->setChecked(true);
        GraphButton->setAutoExclusive(true);
        GraphButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(GraphButton);

        NodeButton = new QToolButton(CClassAttributesEditorUI);
        NodeButton->setObjectName(QString::fromUtf8("NodeButton"));
        sizePolicy.setHeightForWidth(NodeButton->sizePolicy().hasHeightForWidth());
        NodeButton->setSizePolicy(sizePolicy);
        NodeButton->setMinimumSize(QSize(60, 23));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/Node-Disc"), QSize(), QIcon::Normal, QIcon::Off);
        NodeButton->setIcon(icon1);
        NodeButton->setIconSize(QSize(20, 20));
        NodeButton->setCheckable(true);
        NodeButton->setAutoExclusive(true);
        NodeButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(NodeButton);

        EdgeButton = new QToolButton(CClassAttributesEditorUI);
        EdgeButton->setObjectName(QString::fromUtf8("EdgeButton"));
        sizePolicy.setHeightForWidth(EdgeButton->sizePolicy().hasHeightForWidth());
        EdgeButton->setSizePolicy(sizePolicy);
        EdgeButton->setMinimumSize(QSize(60, 23));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/Edge-Undirected"), QSize(), QIcon::Normal, QIcon::Off);
        EdgeButton->setIcon(icon2);
        EdgeButton->setIconSize(QSize(20, 20));
        EdgeButton->setCheckable(true);
        EdgeButton->setAutoExclusive(true);
        EdgeButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(EdgeButton);

        horizontalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        Editor = new CPropertyEditorUIBase(CClassAttributesEditorUI);
        Editor->setObjectName(QString::fromUtf8("Editor"));

        verticalLayout->addWidget(Editor);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        AddButton = new QPushButton(CClassAttributesEditorUI);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));

        horizontalLayout->addWidget(AddButton);

        ChangeButton = new QPushButton(CClassAttributesEditorUI);
        ChangeButton->setObjectName(QString::fromUtf8("ChangeButton"));

        horizontalLayout->addWidget(ChangeButton);

        RemoveButton = new QPushButton(CClassAttributesEditorUI);
        RemoveButton->setObjectName(QString::fromUtf8("RemoveButton"));

        horizontalLayout->addWidget(RemoveButton);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(GraphButton, NodeButton);
        QWidget::setTabOrder(NodeButton, EdgeButton);
        QWidget::setTabOrder(EdgeButton, Editor);
        QWidget::setTabOrder(Editor, AddButton);
        QWidget::setTabOrder(AddButton, ChangeButton);
        QWidget::setTabOrder(ChangeButton, RemoveButton);

        retranslateUi(CClassAttributesEditorUI);

        QMetaObject::connectSlotsByName(CClassAttributesEditorUI);
    } // setupUi

    void retranslateUi(QWidget *CClassAttributesEditorUI)
    {
        CClassAttributesEditorUI->setWindowTitle(QCoreApplication::translate("CClassAttributesEditorUI", "Custom Attributes", nullptr));
#if QT_CONFIG(statustip)
        GraphButton->setStatusTip(QCoreApplication::translate("CClassAttributesEditorUI", "Edit graph attributes", nullptr));
#endif // QT_CONFIG(statustip)
        GraphButton->setText(QCoreApplication::translate("CClassAttributesEditorUI", "\351\223\276\350\241\250", nullptr));
#if QT_CONFIG(statustip)
        NodeButton->setStatusTip(QCoreApplication::translate("CClassAttributesEditorUI", "Edit default node attributes", nullptr));
#endif // QT_CONFIG(statustip)
        NodeButton->setText(QCoreApplication::translate("CClassAttributesEditorUI", "\350\212\202\347\202\271", nullptr));
#if QT_CONFIG(statustip)
        EdgeButton->setStatusTip(QCoreApplication::translate("CClassAttributesEditorUI", "Edit default edge attributes", nullptr));
#endif // QT_CONFIG(statustip)
        EdgeButton->setText(QCoreApplication::translate("CClassAttributesEditorUI", "\351\223\276", nullptr));
#if QT_CONFIG(statustip)
        AddButton->setStatusTip(QCoreApplication::translate("CClassAttributesEditorUI", "Add new custom attribute for the selected items", nullptr));
#endif // QT_CONFIG(statustip)
        AddButton->setText(QCoreApplication::translate("CClassAttributesEditorUI", "\346\267\273\345\212\240...", nullptr));
#if QT_CONFIG(statustip)
        ChangeButton->setStatusTip(QCoreApplication::translate("CClassAttributesEditorUI", "Change selected attribute's id and type", nullptr));
#endif // QT_CONFIG(statustip)
        ChangeButton->setText(QCoreApplication::translate("CClassAttributesEditorUI", "\345\217\230\346\233\264...", nullptr));
#if QT_CONFIG(statustip)
        RemoveButton->setStatusTip(QCoreApplication::translate("CClassAttributesEditorUI", "Remove the attribute from the selected items", nullptr));
#endif // QT_CONFIG(statustip)
        RemoveButton->setText(QCoreApplication::translate("CClassAttributesEditorUI", "\345\216\273\351\231\244...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CClassAttributesEditorUI: public Ui_CClassAttributesEditorUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCLASSATTRIBUTESEDITORUI_H
