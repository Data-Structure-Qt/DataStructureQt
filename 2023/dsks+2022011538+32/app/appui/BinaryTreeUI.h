#pragma once

#include "CNodeEditorScene.h"
#include "CQuickHelpUI.h"
#include "CEditorView.h"
#include <QWidget>
#include "CBiTree.h"
#include "ui_BinaryTreeUI.h"
#include "CNodeEditorScene.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTime>
#include <cmath>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 
class CEditorScene;
namespace Ui {
	class BinaryTreeUI;
}
struct Linklist
{
	int data;
	struct Linklist *next;
};
//B_树
typedef int KeyType;
typedef struct node {
	int keynum; //结点关键字个数
	KeyType key[10]; //关键字，0 遗弃
	struct node *parent; //双亲指针
	struct node *ptr[10]; //孩子指针数组
}BTNode, *BTree;
typedef struct { //查找返回类型
	BTNode *pt;
	int i; //关键字位置; 
	int fag; //查找成功与否标志
}Result;
typedef struct LNode { //链表和链表结点类型
	BTree data;
	struct LNode *next;
}LNode, *LinkList;
typedef struct Animation { //动画片段
	int x;
	int y;
	int data1;
	int data2;
	int p_x;
	int p_y;
	int flag;
	int codeid;
};
typedef enum status { //枚举类型
	TRUE,
	FALSE,
	OK,
	ERROR,
	OVERFLOW1,
	EMPTY
}Status;
class BinaryTreeUI : public QWidget
{
	Q_OBJECT
public:
	BinaryTreeUI(QWidget *parent = 0);
	~BinaryTreeUI();
	void setScene(CNodeEditorScene* scene);
	void setCQuickHelpUI(CQuickHelpUI* scene);
	void setCEditorView(CEditorView* editorView);
	void goToBeginButton();
	void stepBackButton();
	void playButton();
	void suspendButton();
	void stepForwardButton();
	void goToEndButton();
signals:
	void SearchBtn_SendText();
private slots:
	//平衡二叉树创建函数
	void on_binarytree_create_btn_clicked();
	//仿真二叉树创建函数
	void on_binarytree_SimulationTree_creat_btn_clicked();
	//平衡二叉树删除函数
	void on_binarytree_delete_btn_clicked();
	//平衡二叉树节点删除函数
	void on_binarytree_node_delete_btn_clicked();
	//平衡二叉树节点查找函数
	void on_binarytree_node_search_btn_clicked();
	//平衡二叉树递归展示函数
	void inOrderPrint(CBiTreeNode * root, double x, double y,
		double wideSize, double highSize, double p_x, double p_y, int frame);
	//用于搜索的平衡二叉树递归展示函数
	void inOrderPrint_search(CBiTreeNode * root, double x, double y,
		double wideSize, double highSize, double p_x, double p_y, int data, int frame);
	//仿真二叉树递归展示函数
	void inOrderPrint_SimulationTree(CBiTreeNode* root, double x,
		double y, double Branch_length, double Branch_angle,
		double Change_angle, double p_x, double p_y);
	//先序遍历
	void PreOrderBiTree(CBiTreeNode* root, string &In);
	//中序遍历
	void InOrderBiTree(CBiTreeNode* root, string &In);
	//后序遍历
	void PostOrderBiTree(CBiTreeNode* root, string &In);
	//获取树的高度
	void DepthOfBiTree(CBiTreeNode* root, int &In);
	//程序暂停时间 time 停留时间 毫秒
	void sleepTime(int time);
	void animationRecord(int totaltime, int frame, int x, int y,
		int data1, int data2, int p_x, int p_y);
	void animationSearchRecord(int totaltime, int frame, int x,
		int y, int data1, int data2, int p_x, int p_y, int flag, int codeid);
	void animationClean();
	void animationPrint(int totaltime, int frametime);
	void animationDraw(int totaltime, int frametime);
	void animationDrawSearch(int totaltime, int frametime, int x);
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::BinaryTreeUI *ui;
	Linklist *listshow;
	CNodeEditorScene *m_scene;
	CEditorView *m_editorView;
	CNode *m_nodeFactory;
	CEdge *m_edgeFactory;
	CQuickHelpUI *m_quickHelp;
	QStringList list; //节点列表
	int list_array[1010]; //树数组
	CBiTree* avlTree;//新建树
	CBiTreeNode* root;//新建节点
	const int m = 3; //设定 B 树的阶数
	const int Max = m - 1; //结点的最大关键字数量
	const int Min = (m - 1) / 2; //结点的最小关键字数量
	BTree t = NULL;
	Result s; //设定查找结果
	int history_list_array[1010];
	int history_length = 0;
	Animation animation[200][200]; //动画 /第几帧/每帧具体步骤
	Animation animationSearch[200][200]; //动画 /第几帧/每帧具体步骤
	int history_wideSize[200], history_highSize[200];
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime;
	int onlytotaltime = 0;
	int timestamp = 0; //进度控制时间戳
	int endplaybuttonflag = 0;//停止播放标志位
};
