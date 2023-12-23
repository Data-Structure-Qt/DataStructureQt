#pragma once

#include <QtWidgets/QWidget>
#include "bplustree.h"
#include <QMap>

using BTreeNode = bnode<int, std::string>;

class BTreeWidget : public QWidget
{
	Q_OBJECT

public:
	BTreeWidget(QWidget* parent = nullptr);
	void drawNode(QPainter* painter, BTreeNode* node, int x, int y, int width, bool& needResize);
	~BTreeWidget();

	void createBPlusTree();

	void paintEvent(QPaintEvent* event);

	void insert(int key);

	void deleteKey(int key);

private:
	bplustree<int, std::string, 4>* tree;

	QMap<int, std::string> _map;

	QVector<QVector<int>> _leafs;
};
