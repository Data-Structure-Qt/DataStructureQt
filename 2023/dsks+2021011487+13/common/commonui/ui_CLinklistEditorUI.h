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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CircleQueueUI
{
public:
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *dataEdit;
    QPushButton *createButton;
    QPushButton *cleanButton;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *insert_Edit1;
    QPushButton *headinsertButton;
    QPushButton *tailinsertButton;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *insert_Edit2;
    QSpinBox *insert_spinBox;
    QPushButton *insertButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *delete_spinBox;
    QPushButton *headdeleteButton;
    QPushButton *taildeleteButton;
    QPushButton *deleteButton;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *search_Edit;
    QSpinBox *spinBox;
    QPushButton *searchButton;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *CircleQueueUI)
    {
        if (CircleQueueUI->objectName().isEmpty())
            CircleQueueUI->setObjectName(QString::fromUtf8("CircleQueueUI"));
        CircleQueueUI->resize(765, 732);
        horizontalLayout_12 = new QHBoxLayout(CircleQueueUI);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox = new QGroupBox(CircleQueueUI);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_6 = new QHBoxLayout(groupBox);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dataEdit = new QLineEdit(groupBox);
        dataEdit->setObjectName(QString::fromUtf8("dataEdit"));

        horizontalLayout->addWidget(dataEdit);

        createButton = new QPushButton(groupBox);
        createButton->setObjectName(QString::fromUtf8("createButton"));

        horizontalLayout->addWidget(createButton);

        cleanButton = new QPushButton(groupBox);
        cleanButton->setObjectName(QString::fromUtf8("cleanButton"));

        horizontalLayout->addWidget(cleanButton);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout);


        verticalLayout_5->addWidget(groupBox);

        groupBox_2 = new QGroupBox(CircleQueueUI);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_8 = new QHBoxLayout(groupBox_2);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        insert_Edit1 = new QLineEdit(groupBox_2);
        insert_Edit1->setObjectName(QString::fromUtf8("insert_Edit1"));

        horizontalLayout_2->addWidget(insert_Edit1);

        headinsertButton = new QPushButton(groupBox_2);
        headinsertButton->setObjectName(QString::fromUtf8("headinsertButton"));

        horizontalLayout_2->addWidget(headinsertButton);

        tailinsertButton = new QPushButton(groupBox_2);
        tailinsertButton->setObjectName(QString::fromUtf8("tailinsertButton"));

        horizontalLayout_2->addWidget(tailinsertButton);

        horizontalLayout_2->setStretch(0, 3);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        insert_Edit2 = new QLineEdit(groupBox_2);
        insert_Edit2->setObjectName(QString::fromUtf8("insert_Edit2"));

        horizontalLayout_3->addWidget(insert_Edit2);

        insert_spinBox = new QSpinBox(groupBox_2);
        insert_spinBox->setObjectName(QString::fromUtf8("insert_spinBox"));

        horizontalLayout_3->addWidget(insert_spinBox);

        insertButton = new QPushButton(groupBox_2);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));

        horizontalLayout_3->addWidget(insertButton);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 2);
        horizontalLayout_3->setStretch(2, 2);

        verticalLayout_2->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_8->addLayout(verticalLayout_2);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(CircleQueueUI);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_9 = new QHBoxLayout(groupBox_3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        delete_spinBox = new QSpinBox(groupBox_3);
        delete_spinBox->setObjectName(QString::fromUtf8("delete_spinBox"));

        horizontalLayout_4->addWidget(delete_spinBox);

        headdeleteButton = new QPushButton(groupBox_3);
        headdeleteButton->setObjectName(QString::fromUtf8("headdeleteButton"));

        horizontalLayout_4->addWidget(headdeleteButton);

        taildeleteButton = new QPushButton(groupBox_3);
        taildeleteButton->setObjectName(QString::fromUtf8("taildeleteButton"));

        horizontalLayout_4->addWidget(taildeleteButton);

        deleteButton = new QPushButton(groupBox_3);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout_4->addWidget(deleteButton);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 2);
        horizontalLayout_4->setStretch(3, 2);

        verticalLayout_3->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_9->addLayout(verticalLayout_3);


        verticalLayout_5->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(CircleQueueUI);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_4);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_10->addWidget(label_6);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_10->addWidget(label_7);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        search_Edit = new QLineEdit(groupBox_4);
        search_Edit->setObjectName(QString::fromUtf8("search_Edit"));

        horizontalLayout_5->addWidget(search_Edit);

        spinBox = new QSpinBox(groupBox_4);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_5->addWidget(spinBox);

        searchButton = new QPushButton(groupBox_4);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        horizontalLayout_5->addWidget(searchButton);

        horizontalLayout_5->setStretch(0, 3);
        horizontalLayout_5->setStretch(1, 2);
        horizontalLayout_5->setStretch(2, 2);

        verticalLayout_4->addLayout(horizontalLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);


        horizontalLayout_11->addLayout(verticalLayout_4);


        verticalLayout_5->addWidget(groupBox_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);


        horizontalLayout_12->addLayout(verticalLayout_5);


        retranslateUi(CircleQueueUI);
        QObject::connect(createButton, SIGNAL(clicked()), CircleQueueUI, SLOT(on_create_btn_clicked()));
        QObject::connect(cleanButton, SIGNAL(clicked()), CircleQueueUI, SLOT(on_clean_btn_clicked()));
        QObject::connect(headinsertButton, SIGNAL(clicked()), CircleQueueUI, SLOT(on_headinsert_btn_clicked()));
        QObject::connect(tailinsertButton, SIGNAL(clicked()), CircleQueueUI, SLOT(on_tailinsert_btn_clicked()));
        QObject::connect(insertButton, SIGNAL(clicked()), CircleQueueUI, SLOT(on_locationinsert_btn_clicked()));
        QObject::connect(headdeleteButton, SIGNAL(clicked()), CircleQueueUI, SLOT(on_headdelete_btn_clicked()));
        QObject::connect(taildeleteButton, SIGNAL(clicked()), CircleQueueUI, SLOT(on_taildelete_btn_clicked()));
        QObject::connect(deleteButton, SIGNAL(clicked()), CircleQueueUI, SLOT(on_locationdelete_btn_clicked()));
        QObject::connect(searchButton, SIGNAL(clicked()), CircleQueueUI, SLOT(on_search_btn_clicked()));

        QMetaObject::connectSlotsByName(CircleQueueUI);
    } // setupUi

    void retranslateUi(QWidget *CircleQueueUI)
    {
        CircleQueueUI->setWindowTitle(QCoreApplication::translate("CircleQueueUI", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CircleQueueUI", "\345\210\233\345\273\272", nullptr));
        label->setText(QCoreApplication::translate("CircleQueueUI", "\350\257\267\350\276\223\345\205\245\346\225\260\346\215\256\357\274\214\347\224\250\342\200\234\357\274\214\342\200\235\351\232\224\345\274\200", nullptr));
        createButton->setText(QCoreApplication::translate("CircleQueueUI", "\345\210\233\345\273\272", nullptr));
        cleanButton->setText(QCoreApplication::translate("CircleQueueUI", "\346\270\205\347\251\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CircleQueueUI", "\346\217\222\345\205\245", nullptr));
        label_2->setText(QCoreApplication::translate("CircleQueueUI", "\346\225\260\346\215\256", nullptr));
        headinsertButton->setText(QCoreApplication::translate("CircleQueueUI", "\345\244\264\351\203\250\346\217\222\345\205\245", nullptr));
        tailinsertButton->setText(QCoreApplication::translate("CircleQueueUI", "\345\260\276\351\203\250\346\217\222\345\205\245", nullptr));
        label_3->setText(QCoreApplication::translate("CircleQueueUI", "\346\225\260\346\215\256", nullptr));
        label_4->setText(QCoreApplication::translate("CircleQueueUI", "\344\275\215\347\275\256", nullptr));
        insertButton->setText(QCoreApplication::translate("CircleQueueUI", "\346\217\222\345\205\245", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("CircleQueueUI", "\347\247\273\351\231\244", nullptr));
        label_5->setText(QCoreApplication::translate("CircleQueueUI", "\344\275\215\347\275\256", nullptr));
        headdeleteButton->setText(QCoreApplication::translate("CircleQueueUI", "\345\244\264\351\203\250\347\247\273\351\231\244", nullptr));
        taildeleteButton->setText(QCoreApplication::translate("CircleQueueUI", "\345\260\276\351\203\250\347\247\273\351\231\244", nullptr));
        deleteButton->setText(QCoreApplication::translate("CircleQueueUI", "\347\247\273\351\231\244", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("CircleQueueUI", "\346\220\234\347\264\242", nullptr));
        label_6->setText(QCoreApplication::translate("CircleQueueUI", "\346\225\260\346\215\256", nullptr));
        label_7->setText(QCoreApplication::translate("CircleQueueUI", "\344\275\215\347\275\256", nullptr));
        searchButton->setText(QCoreApplication::translate("CircleQueueUI", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CircleQueueUI: public Ui_CircleQueueUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLINKLISTEDITORUI_H
