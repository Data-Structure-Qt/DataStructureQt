/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QPushButton *concatenateButton;
    QPushButton *reverseButton;
    QPushButton *compareButton;
    QPushButton *substringButton;
    QSpinBox *startSpinBox;
    QSpinBox *lengthSpinBox;
    QLabel *resultLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(857, 436);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit1 = new QLineEdit(centralwidget);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));

        verticalLayout->addWidget(lineEdit1);

        lineEdit2 = new QLineEdit(centralwidget);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));

        verticalLayout->addWidget(lineEdit2);

        concatenateButton = new QPushButton(centralwidget);
        concatenateButton->setObjectName(QString::fromUtf8("concatenateButton"));

        verticalLayout->addWidget(concatenateButton);

        reverseButton = new QPushButton(centralwidget);
        reverseButton->setObjectName(QString::fromUtf8("reverseButton"));

        verticalLayout->addWidget(reverseButton);

        compareButton = new QPushButton(centralwidget);
        compareButton->setObjectName(QString::fromUtf8("compareButton"));

        verticalLayout->addWidget(compareButton);

        substringButton = new QPushButton(centralwidget);
        substringButton->setObjectName(QString::fromUtf8("substringButton"));

        verticalLayout->addWidget(substringButton);

        startSpinBox = new QSpinBox(centralwidget);
        startSpinBox->setObjectName(QString::fromUtf8("startSpinBox"));
        startSpinBox->setMaximum(1000);

        verticalLayout->addWidget(startSpinBox);

        lengthSpinBox = new QSpinBox(centralwidget);
        lengthSpinBox->setObjectName(QString::fromUtf8("lengthSpinBox"));
        lengthSpinBox->setMaximum(1000);

        verticalLayout->addWidget(lengthSpinBox);

        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));

        verticalLayout->addWidget(resultLabel);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);
        QObject::connect(concatenateButton, SIGNAL(clicked()), MainWindow, SLOT(on_concatenateButton_clicked()));
        QObject::connect(reverseButton, SIGNAL(clicked()), MainWindow, SLOT(on_reverseButton_clicked()));
        QObject::connect(compareButton, SIGNAL(clicked()), MainWindow, SLOT(on_compareButton_clicked()));
        QObject::connect(substringButton, SIGNAL(clicked()), MainWindow, SLOT(on_substringButton_clicked()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        concatenateButton->setText(QCoreApplication::translate("MainWindow", "\346\213\274\346\216\245", nullptr));
        reverseButton->setText(QCoreApplication::translate("MainWindow", "\351\200\206\347\275\256", nullptr));
        compareButton->setText(QCoreApplication::translate("MainWindow", "\346\257\224\350\276\203\345\244\247\345\260\217", nullptr));
        substringButton->setText(QCoreApplication::translate("MainWindow", "\346\261\202\345\255\220\344\270\262", nullptr));
        resultLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
