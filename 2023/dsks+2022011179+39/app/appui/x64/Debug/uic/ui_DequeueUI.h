/********************************************************************************
** Form generated from reading UI file 'DequeueUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEQUEUEUI_H
#define UI_DEQUEUEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DequeueUI
{
public:
    QGroupBox *groupBox;
    QLabel *label_3;
    QPushButton *cleanButton;
    QPushButton *createButton;
    QLineEdit *dataEdit;
    QLabel *label_6;
    QLineEdit *insert_Edit1;
    QPushButton *headinsertButton;
    QPushButton *tailinsertButton;
    QPushButton *taildeleteButton;
    QPushButton *headdeleteButton;

    void setupUi(QWidget *DequeueUI)
    {
        if (DequeueUI->objectName().isEmpty())
            DequeueUI->setObjectName(QString::fromUtf8("DequeueUI"));
        DequeueUI->resize(733, 538);
        groupBox = new QGroupBox(DequeueUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 9, 311, 191));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 15, 291, 20));
        label_3->setLayoutDirection(Qt::LeftToRight);
        cleanButton = new QPushButton(groupBox);
        cleanButton->setObjectName(QString::fromUtf8("cleanButton"));
        cleanButton->setGeometry(QRect(156, 68, 146, 32));
        createButton = new QPushButton(groupBox);
        createButton->setObjectName(QString::fromUtf8("createButton"));
        createButton->setGeometry(QRect(9, 68, 146, 32));
        dataEdit = new QLineEdit(groupBox);
        dataEdit->setObjectName(QString::fromUtf8("dataEdit"));
        dataEdit->setGeometry(QRect(10, 33, 291, 31));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 100, 291, 20));
        label_6->setLayoutDirection(Qt::LeftToRight);
        insert_Edit1 = new QLineEdit(groupBox);
        insert_Edit1->setObjectName(QString::fromUtf8("insert_Edit1"));
        insert_Edit1->setGeometry(QRect(10, 116, 291, 31));
        headinsertButton = new QPushButton(groupBox);
        headinsertButton->setObjectName(QString::fromUtf8("headinsertButton"));
        headinsertButton->setGeometry(QRect(9, 150, 72, 32));
        tailinsertButton = new QPushButton(groupBox);
        tailinsertButton->setObjectName(QString::fromUtf8("tailinsertButton"));
        tailinsertButton->setGeometry(QRect(156, 150, 72, 32));
        taildeleteButton = new QPushButton(groupBox);
        taildeleteButton->setObjectName(QString::fromUtf8("taildeleteButton"));
        taildeleteButton->setGeometry(QRect(230, 150, 72, 32));
        headdeleteButton = new QPushButton(groupBox);
        headdeleteButton->setObjectName(QString::fromUtf8("headdeleteButton"));
        headdeleteButton->setGeometry(QRect(82, 150, 72, 32));
        QWidget::setTabOrder(cleanButton, dataEdit);
        QWidget::setTabOrder(dataEdit, createButton);
        QWidget::setTabOrder(createButton, headdeleteButton);
        QWidget::setTabOrder(headdeleteButton, taildeleteButton);
        QWidget::setTabOrder(taildeleteButton, insert_Edit1);
        QWidget::setTabOrder(insert_Edit1, headinsertButton);
        QWidget::setTabOrder(headinsertButton, tailinsertButton);

        retranslateUi(DequeueUI);
        QObject::connect(cleanButton, SIGNAL(clicked()), DequeueUI, SLOT(on_clean_btn_clicked()));
        QObject::connect(headinsertButton, SIGNAL(clicked()), DequeueUI, SLOT(on_headinsert_btn_clicked()));
        QObject::connect(tailinsertButton, SIGNAL(clicked()), DequeueUI, SLOT(on_tailinsert_btn_clicked()));
        QObject::connect(headdeleteButton, SIGNAL(clicked()), DequeueUI, SLOT(on_headdelete_btn_clicked()));
        QObject::connect(taildeleteButton, SIGNAL(clicked()), DequeueUI, SLOT(on_taildelete_btn_clicked()));
        QObject::connect(createButton, SIGNAL(clicked()), DequeueUI, SLOT(on_create_btn_clicked()));

        QMetaObject::connectSlotsByName(DequeueUI);
    } // setupUi

    void retranslateUi(QWidget *DequeueUI)
    {
        DequeueUI->setWindowTitle(QCoreApplication::translate("DequeueUI", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DequeueUI", "\345\217\214\347\253\257\351\230\237\345\210\227", nullptr));
        label_3->setText(QCoreApplication::translate("DequeueUI", "<html><head/><body><p align=\"center\">\350\257\267\350\276\223\345\205\245\346\225\260\346\215\256\357\274\214\347\224\250\342\200\234,\342\200\235\351\232\224\345\274\200</p></body></html>", nullptr));
        cleanButton->setText(QCoreApplication::translate("DequeueUI", "\346\270\205\347\251\272", nullptr));
        createButton->setText(QCoreApplication::translate("DequeueUI", "\345\210\233\345\273\272", nullptr));
        label_6->setText(QCoreApplication::translate("DequeueUI", "<html><head/><body><p align=\"center\">\346\225\260\346\215\256</p></body></html>", nullptr));
        headinsertButton->setText(QCoreApplication::translate("DequeueUI", "\345\211\215\347\253\257\345\205\245\351\230\237", nullptr));
        tailinsertButton->setText(QCoreApplication::translate("DequeueUI", "\345\260\276\347\253\257\345\205\245\351\230\237", nullptr));
        taildeleteButton->setText(QCoreApplication::translate("DequeueUI", "\345\260\276\347\253\257\345\207\272\351\230\237", nullptr));
        headdeleteButton->setText(QCoreApplication::translate("DequeueUI", "\345\211\215\347\253\257\345\207\272\351\230\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DequeueUI: public Ui_DequeueUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEQUEUEUI_H
