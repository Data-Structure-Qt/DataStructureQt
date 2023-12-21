#include "BTreeWidget.h"
#include <QPainter>
#include <QDebug>
#include <algorithm>
#include <QTimer>
BTreeWidget::BTreeWidget(QWidget* parent)
	: QWidget(parent)  // 初始化 QWidget 基类的构造函数，将父对象指针传递给它
	, ui(new Ui::BTreeWidgetClass())  // 创建一个新的 Ui::BTreeWidgetClass 对象的实例
{
	ui->setupUi(this);  // 设置 UI，将当前的 BTreeWidget 实例作为参数传递给它
	createBPlusTree();  // 创建 B+ 树
}


void BTreeWidget::drawNode(QPainter* painter, BTreeNode* node, int x, int y, int width) {
	int nodeHeight = 50;  // 节点的高度

	if (node == nullptr)
		return;  // 如果节点为空，返回

	QPen pen;
	QBrush brush;

	if (node->leaf)  // 如果节点为叶子节点
	{
		// 设置字体
		QFont font = painter->font();
		font.setFamily("Arial");
		font.setPointSize(8);
		painter->setFont(font);

		int nodeWidth = width / (double)node->keys.size();  // 计算节点的宽度
		pen.setColor(Qt::black);  // 设置画笔颜色为黑色
		brush.setColor(Qt::yellow);  // 设置画刷颜色为黄色
		brush.setStyle(Qt::SolidPattern);  // 设置画刷样式为实心

		painter->setPen(pen);
		painter->setBrush(brush);

		QVector<int> last;  // 存储最后一个节点的位置
		for (int i = 0; i < node->keys.size(); i++)
		{
			// 绘制圆角矩形节点
			painter->drawRoundedRect(x + i * nodeWidth, y, nodeWidth, nodeHeight * 2, 20, 20);
			// 绘制水平线
			painter->drawLine(x + i * nodeWidth, y + nodeHeight, x + (i + 1) * nodeWidth, y + nodeHeight);
			QFontMetrics fontMetrics(painter->font());
			int textWidth = fontMetrics.width(QString::number(node->keys[i]));  // 计算文本的宽度
			int textHeight = fontMetrics.height();  // 计算文本的高度

			int textX = x + i * nodeWidth + (nodeWidth - textWidth) / 2;  // 计算文本的 X 坐标
			int textY = y + nodeHeight / 2 + (nodeHeight - textHeight) / 2;  // 计算文本的 Y 坐标

			painter->drawText(textX, textY, QString::number(node->keys[i]));  // 绘制键值的文本

			textWidth = fontMetrics.width(QString::fromStdString(node->getValue(i)));  // 计算值的文本宽度
			textHeight = fontMetrics.height();  // 计算值的文本高度

			textX = x + i * nodeWidth + (nodeWidth - textWidth) / 2;  // 计算值的文本 X 坐标
			textY = y + nodeHeight + nodeHeight / 2 + (nodeHeight - textHeight) / 2;  // 计算值的文本 Y 坐标

			painter->drawText(textX, textY, QString::fromStdString(node->getValue(i)));  // 绘制值的文本

			if (last.empty())
				last = { x + i * nodeWidth, y + nodeHeight };
		}

		if (!last.isEmpty())
			_leafs.push_back(last);  // 将最后一个节点的位置添加到 _leafs 容器中
		return;
	}
	else
	{
		int space = 10;
		int nodeWidth = width / (double)node->children.size() - 10;  // 计算子节点的宽度

		int keySize = node->children.size();

		pen.setColor(Qt::black);  // 设置画笔颜色为黑色
		brush.setColor(Qt::red);  // 设置画刷颜色为红色
		brush.setStyle(Qt::SolidPattern);  // 设置画刷样式为实心
		painter->setPen(pen);
		painter->setBrush(brush);
		painter->drawRect(x, y, width, nodeHeight);  // 绘制矩形节点

		QVector<int> vecs;
		for (int i = 0; i < keySize; i++)
		{
			auto son = (BTreeNode*)(node->children[i]);
			// 递归调用绘制子节点
			drawNode(painter, son, x + i * (nodeWidth + 10), y + nodeHeight + 30, nodeWidth);
			// 绘制垂直线
			painter->drawLine((x + i * (nodeWidth + 10)) + nodeWidth / 2, y + nodeHeight, (x + i * (nodeWidth + 10)) + nodeWidth / 2, y + nodeHeight + 30);
			vecs.push_back(x + i * (nodeWidth + 10) + nodeWidth / 2);
		}

		int keyWidth = width / (double)node->keys.size();
		for (int i = 0; i < node->keys.size(); i++)
		{
			// 设置字体
			QFont font = painter->font();
			font.setFamily("Arial");
			font.setPointSize(16);
			painter->setFont(font);
			// 在节点中心绘制键的文本
			painter->drawText((vecs[i] + vecs[i + 1]) / 2, y + nodeHeight / 2 + 12, QString::number(node->keys[i]));
		}
	}
}


BTreeWidget::~BTreeWidget()
{
	delete ui;
}


void BTreeWidget::createBPlusTree()
{
	tree = new bplustree<int, std::string, 4>();  // 创建一个 B+ 树对象，键类型为 int，值类型为 std::string，每个节点最大键值对数为 4
}

void BTreeWidget::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);  // 设置渲染提示以实现抗锯齿效果

	if (tree != nullptr) {
		_leafs.clear();  // 清空 _leafs 容器
		drawNode(&painter, tree->getRoot(), 10, 30, width() - 20);  // 绘制 B+ 树的节点

		for (int i = 0; i < _leafs.size() - 1; i++)
		{
			auto left = _leafs[i];
			auto right = _leafs[i + 1];
			// 定义起点 a 和终点 b
			QPointF a(left[0], left[1]);
			QPointF b(right[0], right[1]);

			// 计算箭头的长度和角度
			qreal arrowLength = 20;
			qreal arrowAngle = 3.1415926 / 6; // 30度

			// 计算箭头的两个点坐标
			qreal dx = b.x() - a.x();
			qreal dy = b.y() - a.y();
			qreal angle = atan2(dy, dx);
			QPointF arrowP1 = b - QPointF(arrowLength * cos(angle + arrowAngle), arrowLength * sin(angle + arrowAngle));
			QPointF arrowP2 = b - QPointF(arrowLength * cos(angle - arrowAngle), arrowLength * sin(angle - arrowAngle));

			// 绘制线条和箭头
			painter.drawLine(a, b);
			painter.drawLine(b, arrowP1);
			painter.drawLine(b, arrowP2);
		}
	}
}

void BTreeWidget::insert(int key)
{
	// 在 B+ 树中插入键值对
	tree->insert(key, new std::string(std::to_string(key) + "_data"));

	// 在映射表中插入键值对
	_map.insert(key, std::string(std::to_string(key) + "_data"));

	update();  // 更新绘图
}

void BTreeWidget::deleteKey(int key)
{
	delete tree;  // 删除旧的 B+ 树对象

	createBPlusTree();  // 创建新的 B+ 树对象

	_map.remove(key);  // 从映射表中删除键值对

	// 重新插入映射表中的键值对到 B+ 树中
	for (int key : _map.keys())
	{
		tree->insert(key, new std::string(_map[key]));
	}

	update();  // 更新绘图
}