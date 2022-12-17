/********************************************************************************
** Form generated from reading UI file 'CSceneOptionsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSCENEOPTIONSDIALOG_H
#define UI_CSCENEOPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <colorbutton.h>
#include <pathpicker.h>
#include <spinslider.h>

QT_BEGIN_NAMESPACE

class Ui_CSceneOptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *SceneSection;
    QFormLayout *formLayout;
    QLabel *label_4;
    QSint::ColorButton *BackgroundColor;
    QGroupBox *GridSection;
    QFormLayout *formLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpinBox *GridSize;
    QLabel *label_2;
    QLabel *label_3;
    QSint::ColorButton *GridColor;
    QCheckBox *GridSnap;
    QCheckBox *GridVisible;
    QGroupBox *PerformanceSection;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QCheckBox *Antialiasing;
    QLabel *label_6;
    QSint::SpinSlider *CacheSlider;
    QGroupBox *DataSection;
    QGridLayout *gridLayout_2;
    QCheckBox *EnableBackups;
    QLabel *label_7;
    QSpinBox *BackupPeriod;
    QLabel *label_8;
    QGroupBox *ExtraSection;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QComboBox *GraphvizDefaultEngine;
    QLabel *label_10;
    QSint::PathPicker *GraphvizPath;
    QPushButton *GraphvizTest;
    QLabel *label_11;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CSceneOptionsDialog)
    {
        if (CSceneOptionsDialog->objectName().isEmpty())
            CSceneOptionsDialog->setObjectName(QString::fromUtf8("CSceneOptionsDialog"));
        CSceneOptionsDialog->resize(423, 546);
        verticalLayout = new QVBoxLayout(CSceneOptionsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        SceneSection = new QGroupBox(CSceneOptionsDialog);
        SceneSection->setObjectName(QString::fromUtf8("SceneSection"));
        SceneSection->setFlat(true);
        formLayout = new QFormLayout(SceneSection);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        label_4 = new QLabel(SceneSection);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(120, 0));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        BackgroundColor = new QSint::ColorButton(SceneSection);
        BackgroundColor->setObjectName(QString::fromUtf8("BackgroundColor"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BackgroundColor->sizePolicy().hasHeightForWidth());
        BackgroundColor->setSizePolicy(sizePolicy);
        BackgroundColor->setMinimumSize(QSize(100, 0));
        BackgroundColor->setPopupMode(QToolButton::InstantPopup);
        BackgroundColor->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        BackgroundColor->setArrowType(Qt::NoArrow);

        formLayout->setWidget(0, QFormLayout::FieldRole, BackgroundColor);


        verticalLayout->addWidget(SceneSection);

        GridSection = new QGroupBox(CSceneOptionsDialog);
        GridSection->setObjectName(QString::fromUtf8("GridSection"));
        GridSection->setFlat(true);
        formLayout_2 = new QFormLayout(GridSection);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
        label = new QLabel(GridSection);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(120, 0));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        GridSize = new QSpinBox(GridSection);
        GridSize->setObjectName(QString::fromUtf8("GridSize"));
        sizePolicy.setHeightForWidth(GridSize->sizePolicy().hasHeightForWidth());
        GridSize->setSizePolicy(sizePolicy);
        GridSize->setMinimumSize(QSize(100, 0));
        GridSize->setMinimum(1);
        GridSize->setMaximum(40);

        horizontalLayout->addWidget(GridSize);

        label_2 = new QLabel(GridSection);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        label_3 = new QLabel(GridSection);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(120, 0));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        GridColor = new QSint::ColorButton(GridSection);
        GridColor->setObjectName(QString::fromUtf8("GridColor"));
        sizePolicy.setHeightForWidth(GridColor->sizePolicy().hasHeightForWidth());
        GridColor->setSizePolicy(sizePolicy);
        GridColor->setMinimumSize(QSize(100, 0));
        GridColor->setPopupMode(QToolButton::InstantPopup);
        GridColor->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        GridColor->setArrowType(Qt::NoArrow);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, GridColor);

        GridSnap = new QCheckBox(GridSection);
        GridSnap->setObjectName(QString::fromUtf8("GridSnap"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, GridSnap);

        GridVisible = new QCheckBox(GridSection);
        GridVisible->setObjectName(QString::fromUtf8("GridVisible"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, GridVisible);


        verticalLayout->addWidget(GridSection);

        PerformanceSection = new QGroupBox(CSceneOptionsDialog);
        PerformanceSection->setObjectName(QString::fromUtf8("PerformanceSection"));
        PerformanceSection->setFlat(true);
        gridLayout = new QGridLayout(PerformanceSection);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(PerformanceSection);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(120, 0));
        label_5->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        Antialiasing = new QCheckBox(PerformanceSection);
        Antialiasing->setObjectName(QString::fromUtf8("Antialiasing"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Antialiasing->sizePolicy().hasHeightForWidth());
        Antialiasing->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(Antialiasing, 0, 1, 1, 1);

        label_6 = new QLabel(PerformanceSection);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(120, 0));
        label_6->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        CacheSlider = new QSint::SpinSlider(PerformanceSection);
        CacheSlider->setObjectName(QString::fromUtf8("CacheSlider"));
        CacheSlider->setMaximum(1000);
        CacheSlider->setSingleStep(10);
        CacheSlider->setPageStep(10);
        CacheSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(CacheSlider, 1, 1, 1, 1);


        verticalLayout->addWidget(PerformanceSection);

        DataSection = new QGroupBox(CSceneOptionsDialog);
        DataSection->setObjectName(QString::fromUtf8("DataSection"));
        DataSection->setFlat(true);
        gridLayout_2 = new QGridLayout(DataSection);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        EnableBackups = new QCheckBox(DataSection);
        EnableBackups->setObjectName(QString::fromUtf8("EnableBackups"));
        EnableBackups->setChecked(true);

        gridLayout_2->addWidget(EnableBackups, 1, 1, 1, 1);

        label_7 = new QLabel(DataSection);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(label_7, 1, 3, 1, 1);

        BackupPeriod = new QSpinBox(DataSection);
        BackupPeriod->setObjectName(QString::fromUtf8("BackupPeriod"));
        BackupPeriod->setMinimum(5);
        BackupPeriod->setMaximum(200);
        BackupPeriod->setSingleStep(5);

        gridLayout_2->addWidget(BackupPeriod, 1, 2, 1, 1);

        label_8 = new QLabel(DataSection);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(120, 0));
        label_8->setMaximumSize(QSize(100, 16777215));

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);


        verticalLayout->addWidget(DataSection);

        ExtraSection = new QGroupBox(CSceneOptionsDialog);
        ExtraSection->setObjectName(QString::fromUtf8("ExtraSection"));
        ExtraSection->setFlat(true);
        gridLayout_3 = new QGridLayout(ExtraSection);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_9 = new QLabel(ExtraSection);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(120, 0));

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        GraphvizDefaultEngine = new QComboBox(ExtraSection);
        GraphvizDefaultEngine->addItem(QString());
        GraphvizDefaultEngine->addItem(QString());
        GraphvizDefaultEngine->addItem(QString());
        GraphvizDefaultEngine->addItem(QString());
        GraphvizDefaultEngine->addItem(QString());
        GraphvizDefaultEngine->addItem(QString());
        GraphvizDefaultEngine->setObjectName(QString::fromUtf8("GraphvizDefaultEngine"));
        GraphvizDefaultEngine->setEditable(false);

        gridLayout_3->addWidget(GraphvizDefaultEngine, 2, 1, 1, 1);

        label_10 = new QLabel(ExtraSection);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(120, 0));

        gridLayout_3->addWidget(label_10, 2, 0, 1, 1);

        GraphvizPath = new QSint::PathPicker(ExtraSection);
        GraphvizPath->setObjectName(QString::fromUtf8("GraphvizPath"));

        gridLayout_3->addWidget(GraphvizPath, 0, 1, 1, 2);

        GraphvizTest = new QPushButton(ExtraSection);
        GraphvizTest->setObjectName(QString::fromUtf8("GraphvizTest"));

        gridLayout_3->addWidget(GraphvizTest, 1, 1, 1, 1);

        label_11 = new QLabel(ExtraSection);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(120, 0));

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);


        verticalLayout->addWidget(ExtraSection);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        line = new QFrame(CSceneOptionsDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        buttonBox = new QDialogButtonBox(CSceneOptionsDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(BackgroundColor, GridSize);
        QWidget::setTabOrder(GridSize, GridColor);
        QWidget::setTabOrder(GridColor, GridVisible);
        QWidget::setTabOrder(GridVisible, GridSnap);
        QWidget::setTabOrder(GridSnap, Antialiasing);
        QWidget::setTabOrder(Antialiasing, CacheSlider);
        QWidget::setTabOrder(CacheSlider, EnableBackups);
        QWidget::setTabOrder(EnableBackups, BackupPeriod);
        QWidget::setTabOrder(BackupPeriod, GraphvizPath);
        QWidget::setTabOrder(GraphvizPath, GraphvizDefaultEngine);

        retranslateUi(CSceneOptionsDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CSceneOptionsDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CSceneOptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CSceneOptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *CSceneOptionsDialog)
    {
        CSceneOptionsDialog->setWindowTitle(QCoreApplication::translate("CSceneOptionsDialog", "Scene Options", nullptr));
        SceneSection->setTitle(QCoreApplication::translate("CSceneOptionsDialog", "Scene", nullptr));
        label_4->setText(QCoreApplication::translate("CSceneOptionsDialog", "Background color", nullptr));
        BackgroundColor->setText(QCoreApplication::translate("CSceneOptionsDialog", "...", nullptr));
        GridSection->setTitle(QCoreApplication::translate("CSceneOptionsDialog", "Grid", nullptr));
        label->setText(QCoreApplication::translate("CSceneOptionsDialog", "Size", nullptr));
        label_2->setText(QCoreApplication::translate("CSceneOptionsDialog", "px", nullptr));
        label_3->setText(QCoreApplication::translate("CSceneOptionsDialog", "Color", nullptr));
        GridColor->setText(QCoreApplication::translate("CSceneOptionsDialog", "...", nullptr));
        GridSnap->setText(QCoreApplication::translate("CSceneOptionsDialog", "Snap to grid", nullptr));
        GridVisible->setText(QCoreApplication::translate("CSceneOptionsDialog", "Show grid", nullptr));
        PerformanceSection->setTitle(QCoreApplication::translate("CSceneOptionsDialog", "Performance", nullptr));
        label_5->setText(QCoreApplication::translate("CSceneOptionsDialog", "Painting", nullptr));
        Antialiasing->setText(QCoreApplication::translate("CSceneOptionsDialog", "Enable antialiasing", nullptr));
        label_6->setText(QCoreApplication::translate("CSceneOptionsDialog", "Cache", nullptr));
        DataSection->setTitle(QCoreApplication::translate("CSceneOptionsDialog", "Data security", nullptr));
        EnableBackups->setText(QCoreApplication::translate("CSceneOptionsDialog", "Back up the data every", nullptr));
        label_7->setText(QCoreApplication::translate("CSceneOptionsDialog", "min", nullptr));
        label_8->setText(QString());
        ExtraSection->setTitle(QCoreApplication::translate("CSceneOptionsDialog", "Extra tools", nullptr));
        label_9->setText(QCoreApplication::translate("CSceneOptionsDialog", "Path to GraphViz binaries", nullptr));
        GraphvizDefaultEngine->setItemText(0, QCoreApplication::translate("CSceneOptionsDialog", "dot", nullptr));
        GraphvizDefaultEngine->setItemText(1, QCoreApplication::translate("CSceneOptionsDialog", "neato", nullptr));
        GraphvizDefaultEngine->setItemText(2, QCoreApplication::translate("CSceneOptionsDialog", "fdp", nullptr));
        GraphvizDefaultEngine->setItemText(3, QCoreApplication::translate("CSceneOptionsDialog", "sfdp", nullptr));
        GraphvizDefaultEngine->setItemText(4, QCoreApplication::translate("CSceneOptionsDialog", "twopi", nullptr));
        GraphvizDefaultEngine->setItemText(5, QCoreApplication::translate("CSceneOptionsDialog", "circo", nullptr));

        label_10->setText(QCoreApplication::translate("CSceneOptionsDialog", "Default layout engine", nullptr));
        GraphvizTest->setText(QCoreApplication::translate("CSceneOptionsDialog", "Run dot...", nullptr));
        label_11->setText(QCoreApplication::translate("CSceneOptionsDialog", "Test GraphViz execution", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSceneOptionsDialog: public Ui_CSceneOptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSCENEOPTIONSDIALOG_H
