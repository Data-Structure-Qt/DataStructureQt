/********************************************************************************
** Form generated from reading UI file 'CSearchDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSEARCHDIALOG_H
#define UI_CSEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CSearchDialog
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *NamesScope;
    QCheckBox *AttrNamesScope;
    QCheckBox *AttrValuesScope;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *AnyObject;
    QRadioButton *EdgesOnly;
    QRadioButton *NodesOnly;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *CaseSense;
    QCheckBox *WholeWords;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *Text;
    QPushButton *Find;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QTreeWidget *Results;

    void setupUi(QDialog *CSearchDialog)
    {
        if (CSearchDialog->objectName().isEmpty())
            CSearchDialog->setObjectName(QString::fromUtf8("CSearchDialog"));
        CSearchDialog->resize(470, 407);
        CSearchDialog->setMinimumSize(QSize(427, 0));
        gridLayout = new QGridLayout(CSearchDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_3 = new QGroupBox(CSearchDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        NamesScope = new QCheckBox(groupBox_3);
        NamesScope->setObjectName(QString::fromUtf8("NamesScope"));
        NamesScope->setChecked(true);

        verticalLayout->addWidget(NamesScope);

        AttrNamesScope = new QCheckBox(groupBox_3);
        AttrNamesScope->setObjectName(QString::fromUtf8("AttrNamesScope"));
        AttrNamesScope->setChecked(true);

        verticalLayout->addWidget(AttrNamesScope);

        AttrValuesScope = new QCheckBox(groupBox_3);
        AttrValuesScope->setObjectName(QString::fromUtf8("AttrValuesScope"));
        AttrValuesScope->setChecked(true);

        verticalLayout->addWidget(AttrValuesScope);


        gridLayout->addWidget(groupBox_3, 1, 1, 1, 1);

        groupBox = new QGroupBox(CSearchDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        AnyObject = new QRadioButton(groupBox);
        AnyObject->setObjectName(QString::fromUtf8("AnyObject"));
        AnyObject->setChecked(true);

        verticalLayout_2->addWidget(AnyObject);

        EdgesOnly = new QRadioButton(groupBox);
        EdgesOnly->setObjectName(QString::fromUtf8("EdgesOnly"));

        verticalLayout_2->addWidget(EdgesOnly);

        NodesOnly = new QRadioButton(groupBox);
        NodesOnly->setObjectName(QString::fromUtf8("NodesOnly"));

        verticalLayout_2->addWidget(NodesOnly);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        groupBox_5 = new QGroupBox(CSearchDialog);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        sizePolicy.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy);
        groupBox_5->setFlat(true);
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        CaseSense = new QCheckBox(groupBox_5);
        CaseSense->setObjectName(QString::fromUtf8("CaseSense"));

        verticalLayout_4->addWidget(CaseSense);

        WholeWords = new QCheckBox(groupBox_5);
        WholeWords->setObjectName(QString::fromUtf8("WholeWords"));

        verticalLayout_4->addWidget(WholeWords);

        verticalSpacer = new QSpacerItem(20, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox_5, 1, 2, 1, 1);

        groupBox_2 = new QGroupBox(CSearchDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(true);
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Text = new QLineEdit(groupBox_2);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setClearButtonEnabled(true);

        horizontalLayout->addWidget(Text);

        Find = new QPushButton(groupBox_2);
        Find->setObjectName(QString::fromUtf8("Find"));

        horizontalLayout->addWidget(Find);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 3);

        groupBox_4 = new QGroupBox(CSearchDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setFlat(true);
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        Results = new QTreeWidget(groupBox_4);
        Results->setObjectName(QString::fromUtf8("Results"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Results->sizePolicy().hasHeightForWidth());
        Results->setSizePolicy(sizePolicy2);
        Results->setProperty("showDropIndicator", QVariant(false));
        Results->setAlternatingRowColors(true);
        Results->setSelectionMode(QAbstractItemView::ExtendedSelection);
        Results->setUniformRowHeights(true);
        Results->setSortingEnabled(true);
        Results->setAllColumnsShowFocus(true);
        Results->header()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_3->addWidget(Results);


        gridLayout->addWidget(groupBox_4, 2, 0, 1, 3);

        QWidget::setTabOrder(Text, Find);
        QWidget::setTabOrder(Find, AnyObject);
        QWidget::setTabOrder(AnyObject, EdgesOnly);
        QWidget::setTabOrder(EdgesOnly, NodesOnly);
        QWidget::setTabOrder(NodesOnly, NamesScope);
        QWidget::setTabOrder(NamesScope, AttrNamesScope);
        QWidget::setTabOrder(AttrNamesScope, AttrValuesScope);
        QWidget::setTabOrder(AttrValuesScope, CaseSense);
        QWidget::setTabOrder(CaseSense, WholeWords);
        QWidget::setTabOrder(WholeWords, Results);

        retranslateUi(CSearchDialog);
        QObject::connect(Text, SIGNAL(returnPressed()), Find, SLOT(click()));

        Find->setDefault(true);


        QMetaObject::connectSlotsByName(CSearchDialog);
    } // setupUi

    void retranslateUi(QDialog *CSearchDialog)
    {
        CSearchDialog->setWindowTitle(QCoreApplication::translate("CSearchDialog", "Search Items", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("CSearchDialog", "Scope", nullptr));
        NamesScope->setText(QCoreApplication::translate("CSearchDialog", "Object names", nullptr));
        AttrNamesScope->setText(QCoreApplication::translate("CSearchDialog", "Attribute names", nullptr));
        AttrValuesScope->setText(QCoreApplication::translate("CSearchDialog", "Attribute values", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CSearchDialog", "Objects to search", nullptr));
        AnyObject->setText(QCoreApplication::translate("CSearchDialog", "Any", nullptr));
        EdgesOnly->setText(QCoreApplication::translate("CSearchDialog", "Edges only", nullptr));
        NodesOnly->setText(QCoreApplication::translate("CSearchDialog", "Nodes only", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("CSearchDialog", "Search flags", nullptr));
        CaseSense->setText(QCoreApplication::translate("CSearchDialog", "Case sensitive", nullptr));
        WholeWords->setText(QCoreApplication::translate("CSearchDialog", "Whole words only", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("CSearchDialog", "Text to search", nullptr));
        Text->setPlaceholderText(QCoreApplication::translate("CSearchDialog", "Input text to find...", nullptr));
        Find->setText(QCoreApplication::translate("CSearchDialog", "Find...", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("CSearchDialog", "Results", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = Results->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("CSearchDialog", "Result", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("CSearchDialog", "ID", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("CSearchDialog", "Type", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSearchDialog: public Ui_CSearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSEARCHDIALOG_H
