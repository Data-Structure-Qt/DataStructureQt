#pragma once
#include<QString>
#include<QChar>
#include<QPoint>
#include<QLine>
#include<QColor>

typedef struct BNode {
	QChar data;//结点名称
	QPoint point;//存储位置坐标
	bool sign;//是否需要被标记
	int level;//存储层数
	struct BNode *left, *right;//左右孩子结点
	BNode() {
		left = NULL; right = NULL;
		point = QPoint(0, 0);
		sign = 0;
		level = 0;
	}
	void setpoint(QPoint p) { point = p; }
}BNode;
class BTree
{
public:
	BTree() { root = nullptr; Mylines = nullptr; Mypoints = nullptr; Treesize = 0; }
	~BTree() { }

	void clear();//重置数据
	void createBTree(BNode* &T, int &i);//先序创建二叉树
	void leveltravl();//层序遍历，并存到levelStr里
	int size() { return Treesize; }//返回树结点数
	int height(BNode *Node);  //得到树的高度
	BNode  *getRoot() { return root; }//获得根节点
	QPoint *getPoints() { return Mypoints; }//得到坐标
	QLine *getLines() { return Mylines; }//得到线段
	QString getpreStr() { return preStr; }
	QString getlevelStr() { return levelStr; }
	void setpreStr(QString s) { preStr = s; }
	void setmypoints();//设置结点坐标
	void setroot(BNode* roott) { root = roott; }
private:
	BNode *root;
	QString preStr;//前序遍历的字符串
	QString levelStr;//层序遍历字符串
	int Treesize;//树节点数
	QPoint *Mypoints;//树各个结点坐标的集合
	QLine *Mylines;//线的条数

};

