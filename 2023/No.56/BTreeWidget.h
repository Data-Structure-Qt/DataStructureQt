#pragma once

// 用于防止头文件重复包含

#include <QtWidgets/QWidget>
#include "ui_BTreeWidget.h"
#include "bplustree.h"

// 命名空间声明
QT_BEGIN_NAMESPACE
namespace Ui { class BTreeWidgetClass; };
QT_END_NAMESPACE

// 使用别名简化类型名称
using BTreeNode = bnode<int, std::string>;

// BTreeWidget 类的声明
class BTreeWidget : public QWidget
{
	Q_OBJECT

public:
	// 构造函数
	BTreeWidget(QWidget* parent = nullptr);

	// 绘制节点
	void drawNode(QPainter* painter, BTreeNode* node, int x, int y, int width);

	// 析构函数
	~BTreeWidget();

	// 创建 B+ 树
	void createBPlusTree();

	// 绘制事件处理函数
	void paintEvent(QPaintEvent* event);

	// 插入键值
	void insert(int key);

	// 删除键值
	void deleteKey(int key);

private:
	Ui::BTreeWidgetClass* ui; // 用户界面类指针

	bplustree<int, std::string, 4>* tree; // B+ 树指针

	QMap<int, std::string> _map; // 键值映射

	QVector<QVector<int>> _leafs; // 叶子节点容器
};