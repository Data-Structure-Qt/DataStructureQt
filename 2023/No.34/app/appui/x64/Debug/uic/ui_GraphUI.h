/********************************************************************************
** Form generated from reading UI file 'GraphUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHUI_H
#define UI_GRAPHUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphUI
{
public:
    QSplitter *splitter;
    QPushButton *leafNodeButton;
    QPushButton *ResetpushButton;

    void setupUi(QWidget *GraphUI)
    {
        if (GraphUI->objectName().isEmpty())
            GraphUI->setObjectName(QString::fromUtf8("GraphUI"));
        GraphUI->resize(335, 210);
        splitter = new QSplitter(GraphUI);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(21, 22, 291, 161));
        splitter->setOrientation(Qt::Vertical);
        leafNodeButton = new QPushButton(splitter);
        leafNodeButton->setObjectName(QString::fromUtf8("leafNodeButton"));
        splitter->addWidget(leafNodeButton);
        ResetpushButton = new QPushButton(splitter);
        ResetpushButton->setObjectName(QString::fromUtf8("ResetpushButton"));
        splitter->addWidget(ResetpushButton);

        retranslateUi(GraphUI);
        QObject::connect(ResetpushButton, SIGNAL(clicked()), GraphUI, SLOT(on_reset_btn_clicked()));
        QObject::connect(leafNodeButton, SIGNAL(clicked()), GraphUI, SLOT(on_leafNode_btn_clicked()));

        QMetaObject::connectSlotsByName(GraphUI);
    } // setupUi

    void retranslateUi(QWidget *GraphUI)
    {
        GraphUI->setWindowTitle(QCoreApplication::translate("GraphUI", "GraphUI", nullptr));
        leafNodeButton->setText(QCoreApplication::translate("GraphUI", "\350\216\267\345\217\226\345\217\266\345\255\220\350\212\202\347\202\271", nullptr));
        ResetpushButton->setText(QCoreApplication::translate("GraphUI", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphUI: public Ui_GraphUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHUI_H
