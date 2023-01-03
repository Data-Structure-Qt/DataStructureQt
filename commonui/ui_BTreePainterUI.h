/********************************************************************************
** Form generated from reading UI file 'BTreePainterUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTREEPAINTERUI_H
#define UI_BTREEPAINTERUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BTreePainterUI
{
public:
    QGroupBox *groupBox;
    QPushButton *onelevel_Btn;
    QPushButton *create_Btn;
    QLineEdit *data_Edit;
    QSpinBox *data_spin;
    QLabel *label;

    void setupUi(QWidget *BTreePainterUI)
    {
        if (BTreePainterUI->objectName().isEmpty())
            BTreePainterUI->setObjectName(QString::fromUtf8("BTreePainterUI"));
        BTreePainterUI->resize(375, 403);
        groupBox = new QGroupBox(BTreePainterUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 351, 131));
        onelevel_Btn = new QPushButton(groupBox);
        onelevel_Btn->setObjectName(QString::fromUtf8("onelevel_Btn"));
        onelevel_Btn->setGeometry(QRect(240, 80, 93, 31));
        create_Btn = new QPushButton(groupBox);
        create_Btn->setObjectName(QString::fromUtf8("create_Btn"));
        create_Btn->setGeometry(QRect(240, 30, 93, 31));
        data_Edit = new QLineEdit(groupBox);
        data_Edit->setObjectName(QString::fromUtf8("data_Edit"));
        data_Edit->setGeometry(QRect(20, 30, 201, 31));
        data_spin = new QSpinBox(groupBox);
        data_spin->setObjectName(QString::fromUtf8("data_spin"));
        data_spin->setGeometry(QRect(170, 80, 51, 31));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 85, 141, 21));

        retranslateUi(BTreePainterUI);
        QObject::connect(create_Btn, SIGNAL(clicked()), BTreePainterUI, SLOT(on_create_Btn_clicked()));
        QObject::connect(onelevel_Btn, SIGNAL(clicked()), BTreePainterUI, SLOT(on_onelevel_Btn_clicked()));

        QMetaObject::connectSlotsByName(BTreePainterUI);
    } // setupUi

    void retranslateUi(QWidget *BTreePainterUI)
    {
        BTreePainterUI->setWindowTitle(QCoreApplication::translate("BTreePainterUI", "BTreePainterUI", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BTreePainterUI", "\344\272\214\345\217\211\346\240\221", nullptr));
        onelevel_Btn->setText(QCoreApplication::translate("BTreePainterUI", "\346\230\276\347\244\272", nullptr));
        create_Btn->setText(QCoreApplication::translate("BTreePainterUI", "\345\210\233\345\273\272\344\272\214\345\217\211\346\240\221", nullptr));
        label->setText(QCoreApplication::translate("BTreePainterUI", "\351\200\211\346\213\251\350\246\201\346\230\276\347\244\272\347\232\204\345\261\202\346\225\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BTreePainterUI: public Ui_BTreePainterUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTREEPAINTERUI_H
