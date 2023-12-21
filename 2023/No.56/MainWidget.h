#pragma once

// 用于防止头文件重复包含

#include <QWidget>
#include "ui_MainWidget.h"

// 命名空间声明
QT_BEGIN_NAMESPACE
namespace Ui { class MainWidgetClass; };
QT_END_NAMESPACE

// MainWidget 类的声明
class MainWidget : public QWidget
{
	Q_OBJECT

public:
	// 构造函数
	MainWidget(QWidget* parent = nullptr);

	// 析构函数
	~MainWidget();

private:
	Ui::MainWidgetClass* ui; // 用户界面类指针
};