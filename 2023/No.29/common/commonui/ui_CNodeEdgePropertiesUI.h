/********************************************************************************
** Form generated from reading UI file 'CNodeEdgePropertiesUI.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CNODEEDGEPROPERTIESUI_H
#define UI_CNODEEDGEPROPERTIESUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "CAttributesEditorUI.h"
#include "colorbutton.h"
#include "doublespincombobox.h"
#include "qfontbutton.h"
#include "qpenbutton.h"
#include "qsplitbutton.h"
#include "spincombobox.h"

QT_BEGIN_NAMESPACE

class Ui_CNodeEdgePropertiesUI
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *NodesBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QSint::ColorButton *NodeColor;
    QSint::QSplitButton *NodeShape;
    QSint::SpinComboBox *NodeSizeX;
    QToolButton *NodeSizeSwitch;
    QSint::SpinComboBox *NodeSizeY;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QSint::ColorButton *StrokeColor;
    QSint::QPenButton *StrokeStyle;
    QSint::DoubleSpinComboBox *StrokeSize;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QGroupBox *NodeAttrBox;
    QVBoxLayout *verticalLayout_3;
    CAttributesEditorUI *NodeAttrEditor;
    QGroupBox *EdgesBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSint::ColorButton *EdgeColor;
    QSint::QPenButton *EdgeStyle;
    QSint::DoubleSpinComboBox *EdgeWeight;
    QSint::QSplitButton *EdgeDirection;
    QSpacerItem *horizontalSpacer_2;
    QSint::QSplitButton *EdgeType;
    QGroupBox *EdgeAttrBox;
    QVBoxLayout *verticalLayout_4;
    CAttributesEditorUI *EdgeAttrEditor;
    QGroupBox *LablesBox;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSint::ColorButton *LabelColor;
    QToolButton *LabelFontBold;
    QToolButton *LabelFontItalic;
    QToolButton *LabelFontUnderline;
    QSint::SpinComboBox *LabelFontSize;
    QSint::QFontButton *LabelFont;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *CNodeEdgePropertiesUI)
    {
        if (CNodeEdgePropertiesUI->objectName().isEmpty())
            CNodeEdgePropertiesUI->setObjectName(QString::fromUtf8("CNodeEdgePropertiesUI"));
        CNodeEdgePropertiesUI->resize(419, 430);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CNodeEdgePropertiesUI->sizePolicy().hasHeightForWidth());
        CNodeEdgePropertiesUI->setSizePolicy(sizePolicy);
        CNodeEdgePropertiesUI->setStyleSheet(QString::fromUtf8("/*\n"
"QDoubleSpinBox, QSpinBox, QComboBox\n"
"{\n"
"border: 1px solid #aaa;\n"
"background: white;\n"
"}\n"
"\n"
"QSpinBox:hover, QDoubleSpinBox:hover, QComboBox:hover\n"
"{\n"
"border: 1px solid #00a;\n"
"background: white;\n"
"}\n"
"\n"
"\n"
"QToolButton\n"
"{\n"
"border: 1px none;\n"
"background: transparent;\n"
"}\n"
"\n"
"QToolButton::menu-button \n"
"{\n"
"background: transparent;\n"
"}\n"
"\n"
"QToolButton:on\n"
"{\n"
"border: 1px solid #00a;\n"
"background: #bbb;\n"
"}\n"
"\n"
"QToolButton:hover:!on\n"
"{\n"
"border: 1px solid #00a;\n"
"background: #eee;\n"
"}\n"
"*/\n"
""));
        verticalLayout_2 = new QVBoxLayout(CNodeEdgePropertiesUI);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        NodesBox = new QGroupBox(CNodeEdgePropertiesUI);
        NodesBox->setObjectName(QString::fromUtf8("NodesBox"));
        NodesBox->setAlignment(Qt::AlignCenter);
        verticalLayout_5 = new QVBoxLayout(NodesBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        NodeColor = new QSint::ColorButton(NodesBox);
        NodeColor->setObjectName(QString::fromUtf8("NodeColor"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(NodeColor->sizePolicy().hasHeightForWidth());
        NodeColor->setSizePolicy(sizePolicy1);
        NodeColor->setMinimumSize(QSize(44, 28));
        NodeColor->setIconSize(QSize(18, 18));
        NodeColor->setPopupMode(QToolButton::MenuButtonPopup);

        horizontalLayout_3->addWidget(NodeColor);

        NodeShape = new QSint::QSplitButton(NodesBox);
        NodeShape->setObjectName(QString::fromUtf8("NodeShape"));
        NodeShape->setMinimumSize(QSize(44, 28));
        NodeShape->setMaximumSize(QSize(16777215, 28));
        NodeShape->setIconSize(QSize(18, 18));
        NodeShape->setPopupMode(QToolButton::MenuButtonPopup);

        horizontalLayout_3->addWidget(NodeShape);

        NodeSizeX = new QSint::SpinComboBox(NodesBox);
        NodeSizeX->setObjectName(QString::fromUtf8("NodeSizeX"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(NodeSizeX->sizePolicy().hasHeightForWidth());
        NodeSizeX->setSizePolicy(sizePolicy2);
        NodeSizeX->setMinimumSize(QSize(60, 28));
        NodeSizeX->setMaximumSize(QSize(60, 28));
        NodeSizeX->setStyleSheet(QString::fromUtf8(""));
        NodeSizeX->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        NodeSizeX->setMinimum(1);
        NodeSizeX->setMaximum(1000);

        horizontalLayout_3->addWidget(NodeSizeX);

        NodeSizeSwitch = new QToolButton(NodesBox);
        NodeSizeSwitch->setObjectName(QString::fromUtf8("NodeSizeSwitch"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(NodeSizeSwitch->sizePolicy().hasHeightForWidth());
        NodeSizeSwitch->setSizePolicy(sizePolicy3);
        NodeSizeSwitch->setCheckable(true);
        NodeSizeSwitch->setChecked(false);

        horizontalLayout_3->addWidget(NodeSizeSwitch);

        NodeSizeY = new QSint::SpinComboBox(NodesBox);
        NodeSizeY->setObjectName(QString::fromUtf8("NodeSizeY"));
        sizePolicy2.setHeightForWidth(NodeSizeY->sizePolicy().hasHeightForWidth());
        NodeSizeY->setSizePolicy(sizePolicy2);
        NodeSizeY->setMinimumSize(QSize(60, 28));
        NodeSizeY->setMaximumSize(QSize(60, 28));
        NodeSizeY->setStyleSheet(QString::fromUtf8(""));
        NodeSizeY->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        NodeSizeY->setMinimum(1);
        NodeSizeY->setMaximum(1000);

        horizontalLayout_3->addWidget(NodeSizeY);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label_2 = new QLabel(NodesBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setFrameShadow(QFrame::Sunken);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);


        verticalLayout_5->addLayout(horizontalLayout_3);

        line = new QFrame(NodesBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        StrokeColor = new QSint::ColorButton(NodesBox);
        StrokeColor->setObjectName(QString::fromUtf8("StrokeColor"));
        sizePolicy1.setHeightForWidth(StrokeColor->sizePolicy().hasHeightForWidth());
        StrokeColor->setSizePolicy(sizePolicy1);
        StrokeColor->setMinimumSize(QSize(44, 28));
        StrokeColor->setIconSize(QSize(18, 18));
        StrokeColor->setPopupMode(QToolButton::MenuButtonPopup);

        horizontalLayout_5->addWidget(StrokeColor);

        StrokeStyle = new QSint::QPenButton(NodesBox);
        StrokeStyle->setObjectName(QString::fromUtf8("StrokeStyle"));
        StrokeStyle->setMinimumSize(QSize(44, 28));
        StrokeStyle->setIconSize(QSize(18, 18));
        StrokeStyle->setPopupMode(QToolButton::MenuButtonPopup);

        horizontalLayout_5->addWidget(StrokeStyle);

        StrokeSize = new QSint::DoubleSpinComboBox(NodesBox);
        StrokeSize->setObjectName(QString::fromUtf8("StrokeSize"));
        sizePolicy1.setHeightForWidth(StrokeSize->sizePolicy().hasHeightForWidth());
        StrokeSize->setSizePolicy(sizePolicy1);
        StrokeSize->setMinimumSize(QSize(60, 28));
        StrokeSize->setMaximumSize(QSize(60, 28));
        StrokeSize->setStyleSheet(QString::fromUtf8(""));
        StrokeSize->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        StrokeSize->setDecimals(1);
        StrokeSize->setMinimum(0.100000000000000);
        StrokeSize->setSingleStep(0.100000000000000);

        horizontalLayout_5->addWidget(StrokeSize);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        label = new QLabel(NodesBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Sunken);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label);


        verticalLayout_5->addLayout(horizontalLayout_5);

        NodeAttrBox = new QGroupBox(NodesBox);
        NodeAttrBox->setObjectName(QString::fromUtf8("NodeAttrBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(NodeAttrBox->sizePolicy().hasHeightForWidth());
        NodeAttrBox->setSizePolicy(sizePolicy4);
        NodeAttrBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        NodeAttrBox->setFlat(true);
        NodeAttrBox->setCheckable(true);
        verticalLayout_3 = new QVBoxLayout(NodeAttrBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        NodeAttrEditor = new CAttributesEditorUI(NodeAttrBox);
        NodeAttrEditor->setObjectName(QString::fromUtf8("NodeAttrEditor"));

        verticalLayout_3->addWidget(NodeAttrEditor);


        verticalLayout_5->addWidget(NodeAttrBox);


        verticalLayout_2->addWidget(NodesBox);

        EdgesBox = new QGroupBox(CNodeEdgePropertiesUI);
        EdgesBox->setObjectName(QString::fromUtf8("EdgesBox"));
        EdgesBox->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(EdgesBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        EdgeColor = new QSint::ColorButton(EdgesBox);
        EdgeColor->setObjectName(QString::fromUtf8("EdgeColor"));
        sizePolicy1.setHeightForWidth(EdgeColor->sizePolicy().hasHeightForWidth());
        EdgeColor->setSizePolicy(sizePolicy1);
        EdgeColor->setMinimumSize(QSize(44, 28));
        EdgeColor->setIconSize(QSize(18, 18));
        EdgeColor->setPopupMode(QToolButton::MenuButtonPopup);

        horizontalLayout_2->addWidget(EdgeColor);

        EdgeStyle = new QSint::QPenButton(EdgesBox);
        EdgeStyle->setObjectName(QString::fromUtf8("EdgeStyle"));
        EdgeStyle->setMinimumSize(QSize(44, 28));
        EdgeStyle->setIconSize(QSize(18, 18));
        EdgeStyle->setPopupMode(QToolButton::MenuButtonPopup);

        horizontalLayout_2->addWidget(EdgeStyle);

        EdgeWeight = new QSint::DoubleSpinComboBox(EdgesBox);
        EdgeWeight->setObjectName(QString::fromUtf8("EdgeWeight"));
        sizePolicy1.setHeightForWidth(EdgeWeight->sizePolicy().hasHeightForWidth());
        EdgeWeight->setSizePolicy(sizePolicy1);
        EdgeWeight->setMinimumSize(QSize(60, 28));
        EdgeWeight->setMaximumSize(QSize(60, 28));
        EdgeWeight->setStyleSheet(QString::fromUtf8(""));
        EdgeWeight->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        EdgeWeight->setDecimals(1);
        EdgeWeight->setMinimum(0.100000000000000);
        EdgeWeight->setSingleStep(0.100000000000000);

        horizontalLayout_2->addWidget(EdgeWeight);

        EdgeDirection = new QSint::QSplitButton(EdgesBox);
        EdgeDirection->setObjectName(QString::fromUtf8("EdgeDirection"));
        EdgeDirection->setMinimumSize(QSize(44, 28));
        EdgeDirection->setIconSize(QSize(18, 18));
        EdgeDirection->setPopupMode(QToolButton::MenuButtonPopup);

        horizontalLayout_2->addWidget(EdgeDirection);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        EdgeType = new QSint::QSplitButton(EdgesBox);
        EdgeType->setObjectName(QString::fromUtf8("EdgeType"));
        EdgeType->setMinimumSize(QSize(44, 28));
        EdgeType->setIconSize(QSize(18, 18));
        EdgeType->setPopupMode(QToolButton::MenuButtonPopup);

        horizontalLayout_2->addWidget(EdgeType);


        verticalLayout->addLayout(horizontalLayout_2);

        EdgeAttrBox = new QGroupBox(EdgesBox);
        EdgeAttrBox->setObjectName(QString::fromUtf8("EdgeAttrBox"));
        sizePolicy4.setHeightForWidth(EdgeAttrBox->sizePolicy().hasHeightForWidth());
        EdgeAttrBox->setSizePolicy(sizePolicy4);
        EdgeAttrBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        EdgeAttrBox->setFlat(true);
        EdgeAttrBox->setCheckable(true);
        verticalLayout_4 = new QVBoxLayout(EdgeAttrBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        EdgeAttrEditor = new CAttributesEditorUI(EdgeAttrBox);
        EdgeAttrEditor->setObjectName(QString::fromUtf8("EdgeAttrEditor"));

        verticalLayout_4->addWidget(EdgeAttrEditor);


        verticalLayout->addWidget(EdgeAttrBox);


        verticalLayout_2->addWidget(EdgesBox);

        LablesBox = new QGroupBox(CNodeEdgePropertiesUI);
        LablesBox->setObjectName(QString::fromUtf8("LablesBox"));
        LablesBox->setAlignment(Qt::AlignCenter);
        horizontalLayout = new QHBoxLayout(LablesBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        LabelColor = new QSint::ColorButton(LablesBox);
        LabelColor->setObjectName(QString::fromUtf8("LabelColor"));
        sizePolicy1.setHeightForWidth(LabelColor->sizePolicy().hasHeightForWidth());
        LabelColor->setSizePolicy(sizePolicy1);
        LabelColor->setMinimumSize(QSize(44, 28));
        LabelColor->setMaximumSize(QSize(16777215, 28));
        LabelColor->setIconSize(QSize(18, 18));
        LabelColor->setPopupMode(QToolButton::MenuButtonPopup);

        horizontalLayout_4->addWidget(LabelColor);

        LabelFontBold = new QToolButton(LablesBox);
        LabelFontBold->setObjectName(QString::fromUtf8("LabelFontBold"));
        sizePolicy1.setHeightForWidth(LabelFontBold->sizePolicy().hasHeightForWidth());
        LabelFontBold->setSizePolicy(sizePolicy1);
        LabelFontBold->setMinimumSize(QSize(0, 28));
        LabelFontBold->setMaximumSize(QSize(28, 28));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        LabelFontBold->setFont(font);
        LabelFontBold->setCheckable(true);

        horizontalLayout_4->addWidget(LabelFontBold);

        LabelFontItalic = new QToolButton(LablesBox);
        LabelFontItalic->setObjectName(QString::fromUtf8("LabelFontItalic"));
        sizePolicy1.setHeightForWidth(LabelFontItalic->sizePolicy().hasHeightForWidth());
        LabelFontItalic->setSizePolicy(sizePolicy1);
        LabelFontItalic->setMinimumSize(QSize(0, 28));
        LabelFontItalic->setMaximumSize(QSize(28, 28));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        LabelFontItalic->setFont(font1);
        LabelFontItalic->setCheckable(true);

        horizontalLayout_4->addWidget(LabelFontItalic);

        LabelFontUnderline = new QToolButton(LablesBox);
        LabelFontUnderline->setObjectName(QString::fromUtf8("LabelFontUnderline"));
        sizePolicy1.setHeightForWidth(LabelFontUnderline->sizePolicy().hasHeightForWidth());
        LabelFontUnderline->setSizePolicy(sizePolicy1);
        LabelFontUnderline->setMinimumSize(QSize(0, 28));
        LabelFontUnderline->setMaximumSize(QSize(28, 28));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(true);
        font2.setWeight(50);
        LabelFontUnderline->setFont(font2);
        LabelFontUnderline->setCheckable(true);

        horizontalLayout_4->addWidget(LabelFontUnderline);

        LabelFontSize = new QSint::SpinComboBox(LablesBox);
        LabelFontSize->setObjectName(QString::fromUtf8("LabelFontSize"));
        sizePolicy2.setHeightForWidth(LabelFontSize->sizePolicy().hasHeightForWidth());
        LabelFontSize->setSizePolicy(sizePolicy2);
        LabelFontSize->setMinimumSize(QSize(60, 28));
        LabelFontSize->setMaximumSize(QSize(60, 28));
        LabelFontSize->setStyleSheet(QString::fromUtf8(""));
        LabelFontSize->setCorrectionMode(QAbstractSpinBox::CorrectToNearestValue);
        LabelFontSize->setMinimum(1);
        LabelFontSize->setMaximum(1000);

        horizontalLayout_4->addWidget(LabelFontSize);

        LabelFont = new QSint::QFontButton(LablesBox);
        LabelFont->setObjectName(QString::fromUtf8("LabelFont"));
        sizePolicy1.setHeightForWidth(LabelFont->sizePolicy().hasHeightForWidth());
        LabelFont->setSizePolicy(sizePolicy1);
        LabelFont->setMinimumSize(QSize(70, 28));
        LabelFont->setMaximumSize(QSize(16777215, 28));
        LabelFont->setPopupMode(QToolButton::MenuButtonPopup);
        LabelFont->setToolButtonStyle(Qt::ToolButtonTextOnly);

        horizontalLayout_4->addWidget(LabelFont);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        horizontalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(LablesBox);

        QWidget::setTabOrder(NodeColor, NodeShape);
        QWidget::setTabOrder(NodeShape, NodeSizeX);
        QWidget::setTabOrder(NodeSizeX, NodeSizeSwitch);
        QWidget::setTabOrder(NodeSizeSwitch, NodeSizeY);
        QWidget::setTabOrder(NodeSizeY, StrokeColor);
        QWidget::setTabOrder(StrokeColor, StrokeStyle);
        QWidget::setTabOrder(StrokeStyle, StrokeSize);
        QWidget::setTabOrder(StrokeSize, NodeAttrBox);
        QWidget::setTabOrder(NodeAttrBox, EdgeColor);
        QWidget::setTabOrder(EdgeColor, EdgeStyle);
        QWidget::setTabOrder(EdgeStyle, EdgeWeight);
        QWidget::setTabOrder(EdgeWeight, EdgeDirection);
        QWidget::setTabOrder(EdgeDirection, EdgeAttrBox);
        QWidget::setTabOrder(EdgeAttrBox, LabelColor);
        QWidget::setTabOrder(LabelColor, LabelFont);

        retranslateUi(CNodeEdgePropertiesUI);
        QObject::connect(NodeAttrBox, SIGNAL(toggled(bool)), NodeAttrEditor, SLOT(setVisible(bool)));
        QObject::connect(EdgeAttrBox, SIGNAL(toggled(bool)), EdgeAttrEditor, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(CNodeEdgePropertiesUI);
    } // setupUi

    void retranslateUi(QWidget *CNodeEdgePropertiesUI)
    {
        CNodeEdgePropertiesUI->setWindowTitle(QCoreApplication::translate("CNodeEdgePropertiesUI", "Form", nullptr));
        NodesBox->setTitle(QCoreApplication::translate("CNodeEdgePropertiesUI", "\350\212\202\347\202\271", nullptr));
#if QT_CONFIG(statustip)
        NodeColor->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set fill color of the selected nodes", nullptr));
#endif // QT_CONFIG(statustip)
        NodeColor->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "...", nullptr));
#if QT_CONFIG(statustip)
        NodeShape->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set shape of the selected nodes", nullptr));
#endif // QT_CONFIG(statustip)
        NodeShape->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "...", nullptr));
#if QT_CONFIG(statustip)
        NodeSizeX->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set width of the selected nodes", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        NodeSizeSwitch->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Uniform nodes size editing if checked", nullptr));
#endif // QT_CONFIG(statustip)
        NodeSizeSwitch->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "#", nullptr));
#if QT_CONFIG(statustip)
        NodeSizeY->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set height of the selected nodes", nullptr));
#endif // QT_CONFIG(statustip)
        label_2->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "\345\275\242\347\212\266", nullptr));
#if QT_CONFIG(statustip)
        StrokeColor->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set stroke color of the selected nodes", nullptr));
#endif // QT_CONFIG(statustip)
        StrokeColor->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "...", nullptr));
#if QT_CONFIG(statustip)
        StrokeStyle->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set stroke style of the selected nodes", nullptr));
#endif // QT_CONFIG(statustip)
        StrokeStyle->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "...", nullptr));
#if QT_CONFIG(statustip)
        StrokeSize->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set stroke width of the selected nodes", nullptr));
#endif // QT_CONFIG(statustip)
        label->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "\350\275\256\345\273\223", nullptr));
        NodeAttrBox->setTitle(QCoreApplication::translate("CNodeEdgePropertiesUI", "\350\207\252\345\256\232\344\271\211\345\261\236\346\200\247", nullptr));
        EdgesBox->setTitle(QCoreApplication::translate("CNodeEdgePropertiesUI", "\350\276\271", nullptr));
#if QT_CONFIG(statustip)
        EdgeColor->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set color of the selected edges", nullptr));
#endif // QT_CONFIG(statustip)
        EdgeColor->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "...", nullptr));
#if QT_CONFIG(statustip)
        EdgeStyle->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set pen style of the selected edges", nullptr));
#endif // QT_CONFIG(statustip)
        EdgeStyle->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "...", nullptr));
#if QT_CONFIG(statustip)
        EdgeWeight->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set weight of the selected edges", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        EdgeDirection->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set direction of the selected edges", nullptr));
#endif // QT_CONFIG(statustip)
        EdgeDirection->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "...", nullptr));
#if QT_CONFIG(statustip)
        EdgeType->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set type of the selected edges", nullptr));
#endif // QT_CONFIG(statustip)
        EdgeType->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "...", nullptr));
        EdgeAttrBox->setTitle(QCoreApplication::translate("CNodeEdgePropertiesUI", "\350\207\252\345\256\232\344\271\211\345\261\236\346\200\247", nullptr));
        LablesBox->setTitle(QCoreApplication::translate("CNodeEdgePropertiesUI", "\346\240\207\347\255\276", nullptr));
#if QT_CONFIG(statustip)
        LabelColor->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set color of the selected labels", nullptr));
#endif // QT_CONFIG(statustip)
        LabelColor->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "...", nullptr));
#if QT_CONFIG(statustip)
        LabelFontBold->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Bold font look of the selected labels", nullptr));
#endif // QT_CONFIG(statustip)
        LabelFontBold->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "B", nullptr));
#if QT_CONFIG(statustip)
        LabelFontItalic->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Italic font look of the selected labels", nullptr));
#endif // QT_CONFIG(statustip)
        LabelFontItalic->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "I", nullptr));
#if QT_CONFIG(statustip)
        LabelFontUnderline->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Underlined font look of the selected labels", nullptr));
#endif // QT_CONFIG(statustip)
        LabelFontUnderline->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "U", nullptr));
#if QT_CONFIG(statustip)
        LabelFontSize->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set font size of the selected labels", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(statustip)
        LabelFont->setStatusTip(QCoreApplication::translate("CNodeEdgePropertiesUI", "Set font of the selected labels", nullptr));
#endif // QT_CONFIG(statustip)
        LabelFont->setText(QCoreApplication::translate("CNodeEdgePropertiesUI", "Aa1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CNodeEdgePropertiesUI: public Ui_CNodeEdgePropertiesUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CNODEEDGEPROPERTIESUI_H
