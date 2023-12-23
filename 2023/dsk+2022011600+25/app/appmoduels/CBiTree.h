#pragma once
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <QDebug>
#include <QColor>
using namespace std;
class CBiTreeNode
{
public:
	int key; //结点的值
	int height; //结点的高度，根结点为0
	CBiTreeNode* left; //左孩子
	CBiTreeNode* right; //右孩子
	QPoint m_Point;//二叉树结点坐标位置
	QColor m_Color; //二叉树结点颜色
	QString m_StrName; //二叉树结点名称
	int m_Value;//二叉树结点值
	bool m_Visit;//二叉树结点是否访问
	QPoint m_DisplayPoint;//二叉树新的显示位置
	//二叉树结点左右孩子指针和父结点指针
	CBiTreeNode *m_PLChild, *m_PRChild, *m_PParent;
	int m_Leftwidth;//二叉树左子树宽度
/*构造函数*/
	CBiTreeNode(int k, CBiTreeNode* left, CBiTreeNode* right) :key(k), height(0),
	left(left), right(right) {}
};
class CBiTree
{
private:
	CBiTreeNode* root; //根节点
public:
	CBiTree() :root(NULL) {};//构造函数
	CBiTreeNode* getRoot() { return root; }//返回根节点
	void preOrder(CBiTreeNode* root);//先序遍历
	void inOrder(CBiTreeNode* root);//中序遍历
	void postOrder(CBiTreeNode* root);//后序遍历
	//在平衡二叉树树root中查找值为key的结点并返回该结点
	CBiTreeNode* search(CBiTreeNode* root, int key);
	//在平衡二叉树树中查找最小值结点并返回
	CBiTreeNode* minimus(CBiTreeNode* node);
	//在平衡二叉树树中查找最大值结点并返回
	CBiTreeNode* maximus(CBiTreeNode* node);
	//返回结点的高度
	int height(CBiTreeNode* node);
	//LL旋转
	CBiTreeNode* leftLeftRotate(CBiTreeNode* root);
	//RR旋转
	CBiTreeNode* rightRightRotate(CBiTreeNode* root);
	//LR旋转
	CBiTreeNode* leftRightRotate(CBiTreeNode* root);
	//RL旋转
	CBiTreeNode* rightLeftRotate(CBiTreeNode* root);
	//插入结点
	CBiTreeNode* insert(CBiTreeNode* root, int key);
	//删除结点node
	CBiTreeNode* deleteNode(CBiTreeNode* root, CBiTreeNode* node);
	//销毁平衡二叉树树
	void destroy(CBiTreeNode* root);
	//打印二叉树
	void TreePrint(CBiTreeNode* root);
	//层序遍历
	void InOrder(CBiTreeNode* root, string &In);
}
;