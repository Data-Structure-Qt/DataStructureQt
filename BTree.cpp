#include "BTree.h"
#include <QQueue>
#include <QColor>
#include<qdebug>
#include<math.h>

int BTree::height(BNode * Node)
{
	if (Node == nullptr)
		return 0;
	else
	{
		int i = height(Node->left);
		int j = height(Node->right);
		return (i < j) ? j + 1 : i + 1;
	}
}

void BTree::clear()
{
	root = nullptr;
	Mylines = nullptr;
	Mypoints = nullptr;
	Treesize = 0;
	preStr = "";
	levelStr = "";
}

void BTree::createBTree(BNode* &T, int & i)
{
	if (preStr[i] != '#') {
		T = new BNode;
		T->data = preStr[i];
		Treesize++;
		i++;
		this->createBTree(T->left, i);
		this->createBTree(T->right, i);
	}
	else {
		T = nullptr;
		i++;
	}

}

void BTree::leveltravl()
{
	if (root == nullptr)
		return;
	int count = 1;
	QQueue<BNode*> q;
	BNode* cur = root;
	q.enqueue(cur);
	while (!q.empty()) {
		int size = q.size();
		while (size-- > 0) {
			cur = q.dequeue();
			cur->level = count;
			//qDebug() << count << endl;
			levelStr.append(cur->data);
			if (cur->left)
				q.enqueue(cur->left);
			if (cur->right)
				q.enqueue(cur->right);
		}
		count++;
	}
}

void BTree::setmypoints()
{
	int i = 0;
	//    int H=height();
	Mypoints = new QPoint[Treesize];  //动态分配空间
	Mylines = new QLine[Treesize - 1];
	QQueue<BNode*>Q;         //调用队列
	BNode *p = root;
	root->setpoint(QPoint(0,-300));  //为根节点设置坐标
	Q.enqueue(root);
	Mypoints[i] = root->point;

	//通过层次遍历，完成各个坐标的匹配
	while (!Q.isEmpty())
	{
		p = Q.dequeue();
		if (p->left != nullptr)
		{
			i++;
			int h = height(p);
			//p->left->setpoint(p->point - QPoint(50 * h, -100));
			p->left->setpoint(p->point - QPoint(10 * (pow(h,2)), -100));
			Mypoints[i] = p->left->point;
			Mylines[i - 1].setP1(p->point + QPoint(0, 0));
			Mylines[i - 1].setP2(p->left->point - QPoint(0, 15));
			Q.enqueue(p->left);
		}

		if (p->right != nullptr)
		{
			i++;
			int h = height(p);
			p->right->setpoint(p->point + QPoint(10 * (pow(h, 2)), 100));
			Mypoints[i] = p->right->point;
			Mylines[i - 1].setP1(p->point + QPoint(0, 0));
			Mylines[i - 1].setP2(p->right->point - QPoint(0, 15));
			Q.enqueue(p->right);
			h--;
		}

	}
}
