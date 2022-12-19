/********************************************************************************
** Form generated from reading UI file 'BTreeMain.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTREEMAIN_H
#define UI_BTREEMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BTreeMainClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *exitNode;
    QPushButton *insertNode;
    QLineEdit *data;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *BTreeMainClass)
    {
        if (BTreeMainClass->objectName().isEmpty())
            BTreeMainClass->setObjectName(QString::fromUtf8("BTreeMainClass"));
        BTreeMainClass->resize(1064, 724);
        centralWidget = new QWidget(BTreeMainClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(430, 330, 95, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        exitNode = new QPushButton(gridLayoutWidget);
        exitNode->setObjectName(QString::fromUtf8("exitNode"));

        gridLayout->addWidget(exitNode, 3, 0, 1, 1);

        insertNode = new QPushButton(gridLayoutWidget);
        insertNode->setObjectName(QString::fromUtf8("insertNode"));

        gridLayout->addWidget(insertNode, 2, 0, 1, 1);

        data = new QLineEdit(gridLayoutWidget);
        data->setObjectName(QString::fromUtf8("data"));

        gridLayout->addWidget(data, 1, 0, 1, 1);

        BTreeMainClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(BTreeMainClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1064, 26));
        BTreeMainClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(BTreeMainClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        BTreeMainClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(BTreeMainClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        BTreeMainClass->setStatusBar(statusBar);

        retranslateUi(BTreeMainClass);

        QMetaObject::connectSlotsByName(BTreeMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *BTreeMainClass)
    {
        BTreeMainClass->setWindowTitle(QCoreApplication::translate("BTreeMainClass", "BTreeMain", nullptr));
        exitNode->setText(QCoreApplication::translate("BTreeMainClass", "\351\200\200\345\207\272", nullptr));
        insertNode->setText(QCoreApplication::translate("BTreeMainClass", "\346\217\222\345\205\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BTreeMainClass: public Ui_BTreeMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTREEMAIN_H
