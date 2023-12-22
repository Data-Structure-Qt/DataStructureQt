#include "BTreeWidget.h"
#include <QPainter>
#include <QDebug>
#include <algorithm>
#include <QTimer>
BTreeWidget::BTreeWidget(QWidget* parent)
	: QWidget(parent)
{
	QPalette palette;
	palette.setColor(QPalette::Background, Qt::white);
	setPalette(palette);
	createBPlusTree();
}



BTreeWidget::~BTreeWidget()
{
}


void BTreeWidget::createBPlusTree()
{
	tree = new bplustree<int, std::string, 4>();
}

//递归绘制节点 x ，y  width 拥有的宽度
//int nodeWidth = 30;
void BTreeWidget::drawNode(QPainter* painter, BTreeNode* node, int x, int y, int width, bool& needResize) {
	int nodeHeight = 50;
	if (node == nullptr)
		return;
	QPen pen;
	QBrush brush;

	if (node->leaf)
	{
		QFont font = painter->font();
		font.setFamily("Arial");
		font.setPointSize(8);
		painter->setFont(font);

		int nodeWidth = width / (double)node->keys.size();
		pen.setColor(Qt::black);
		brush.setColor(Qt::yellow);
		brush.setStyle(Qt::SolidPattern);

		painter->setPen(pen);
		painter->setBrush(brush);
		if (width < 100)
		{
			needResize = true;
		}

		QVector<int> last;
		for (int i = 0; i < node->keys.size(); i++)
		{
			painter->drawRoundedRect(x + i * nodeWidth, y, nodeWidth, nodeHeight * 2, 20, 20);
			painter->drawLine(x + i * nodeWidth, y + nodeHeight, x + (i + 1) * nodeWidth, y + nodeHeight);
			QFontMetrics fontMetrics(painter->font());
			int textWidth = fontMetrics.width(QString::number(node->keys[i]));
			int textHeight = fontMetrics.height();

			int textX = x + i * nodeWidth + (nodeWidth - textWidth) / 2;
			int textY = y + nodeHeight / 2 + (nodeHeight - textHeight) / 2;

			painter->drawText(textX, textY, QString::number(node->keys[i]));

			textWidth = fontMetrics.width(QString::fromStdString(node->getValue(i)));
			textHeight = fontMetrics.height();

			textX = x + i * nodeWidth + (nodeWidth - textWidth) / 2;
			textY = y + nodeHeight + nodeHeight / 2 + (nodeHeight - textHeight) / 2;

			painter->drawText(textX, textY, QString::fromStdString(node->getValue(i)));
			if (last.empty())
				last = { x + i * nodeWidth, y + nodeHeight };
		}
		if (!last.isEmpty())
			_leafs.push_back(last);
		return;
	}
	else
	{
		int space = 10;
		int nodeWidth = width / (double)node->children.size() - 10;

		int keySize = node->children.size();

		pen.setColor(Qt::black);
		brush.setColor(Qt::red);
		brush.setStyle(Qt::SolidPattern);
		painter->setPen(pen);
		painter->setBrush(brush);
		painter->drawRect(x, y, width, nodeHeight);



		QVector<int> vecs;
		for (int i = 0; i < keySize; i++)
		{
			auto son = (BTreeNode*)(node->children[i]);
			drawNode(painter, son, x + i * (nodeWidth + 10), y + nodeHeight + 30, nodeWidth, needResize);
			painter->drawLine((x + i * (nodeWidth + 10)) + nodeWidth / 2, y + nodeHeight, (x + i * (nodeWidth + 10)) + nodeWidth / 2, y + nodeHeight + 30);
			vecs.push_back(x + i * (nodeWidth + 10) + nodeWidth / 2);
		}

		int keyWidth = width / (double)node->keys.size();
		for (int i = 0; i < node->keys.size(); i++)
		{
			QFont font = painter->font();
			font.setFamily("Arial");
			font.setPointSize(16);
			painter->setFont(font);
			painter->drawText((vecs[i] + vecs[i + 1]) / 2, y + nodeHeight / 2 + 12, QString::number(node->keys[i]));
		}

	}
}


void BTreeWidget::paintEvent(QPaintEvent* event) {
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	if (tree != nullptr) {
		_leafs.clear();
		bool needResize = false;
		drawNode(&painter, tree->getRoot(), 10, 30, width() - 20, needResize);
		if (needResize)
		{
			int currentWidth = width();
			int currentHeight = height();

			int newWidth = currentWidth * 2;
			int newHeight = currentHeight * 2;

			resize(newWidth, newHeight);
			update();
		}

		for (int i = 0; i < _leafs.size() - 1; i++)
		{
			auto left = _leafs[i];
			auto right = _leafs[i + 1];
			// 定义起点a和终点b
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
	tree->insert(key, new std::string(std::to_string(key) + "_data"));
	_map.insert(key, std::string(std::to_string(key) + "_data"));
	update();

}

void BTreeWidget::deleteKey(int key)
{
	delete tree;
	createBPlusTree();
	_map.remove(key);
	for (int key : _map.keys())
	{
		tree->insert(key, new std::string(_map[key]));
	}
	update();
}

