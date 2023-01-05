#pragma once
#include "../base/CNodeEditorScene.h"
#include "CQuickHelpUI.h"
#include "../base/CEditorView.h"
#include <QWidget>
#include "avltree.h"
#include "BigRoot.h"
#include "ui_CBinarySortTreeEditorUI.h"
#include "../base/CNodeEditorScene.h"
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
	class CBinarySortTreeEditorUI;
}
struct Linklist
{
	int data;
	struct Linklist* next;
};
//B_树
typedef int KeyType;
typedef struct node {
	int keynum; //结点关键字个数
	KeyType key[10]; //关键字，0 遗弃
	struct node* parent; //双亲指针
	struct node* ptr[10]; //孩子指针数组
}BTNode, * BTree;
typedef struct { //查找返回类型
	BTNode* pt;
	int i; //关键字位置; 
	int fag; //查找成功与否标志
}Result;
typedef struct LNode { //链表和链表结点类型
	BTree data;
	struct LNode* next;
}LNode, * LinkList;
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
class CBinarySortTreeEditorUI : public QWidget
{
	Q_OBJECT
public:
	CBinarySortTreeEditorUI(QWidget* parent = 0);
	~CBinarySortTreeEditorUI();
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
	//大根堆创建函数
	void on_bigroottree_create_btn_clicked();
	//大根堆插入
	void on_bigroottree_insert_btn_clicked();
	//大根堆删除
	void on_bigroottree_remove_btn_clicked();
	//B 树创建函数
	void on_Btree_create_btn_clicked();
	//B 树插入
	void on_Btree_insert_btn_clicked();
	//B 树删除
	void on_Btree_remove_btn_clicked();
	//B 树销毁
	void on_Btree_destroy_btn_clicked();
	//平衡二叉树递归展示函数
	void inOrderPrint(CBiTreeNode* root, double x, double y, double wideSize,
		double highSize, double p_x, double p_y, int frame);
	//用于搜索的平衡二叉树递归展示函数
	void inOrderPrint_search(CBiTreeNode* root, double x, double y, double
		wideSize, double highSize, double p_x, double p_y, int data, int frame);
	//仿真二叉树递归展示函数
	void inOrderPrint_SimulationTree(CBiTreeNode* root, double x,
		double y, double Branch_length, double Branch_angle, double
		Change_angle, double p_x, double p_y);
	//三叉树先根遍历
	void PreOrder(CBiTreeNode* root, string& In);

	//先序遍历
	void PreOrderBiTree(CBiTreeNode* root, string& In);
	//中序遍历
	void InOrderBiTree(CBiTreeNode* root, string& In);
	//后序遍历
	void PostOrderBiTree(CBiTreeNode* root, string& In);
	//获取树的高度
	void DepthOfBiTree(CBiTreeNode* root, int& In);
	//往大根堆中插入元素
	bool insertBigRootTree(int val, BigRoot* bigrootTree);
	//从大根堆中删除元素
	bool removeBigRootTree(int val, BigRoot* bigrootTree);
	//打印大根堆
	void printBigRootTree(BigRoot* bigrootTree);
	//获取堆顶元素
	int getTopBigRootTree(BigRoot* bigrootTree);
	//根据指定数组创建大根堆
	bool creatBigRootTree(int a[], int size, BigRoot* bigrootTree);
	//根据数组打印大根堆
	void Print_BigRootTree(int index, BigRoot* bigrootTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y);
	//B 树
	Status InitBTree(BTree& t); //初始化
	int SearchBTNode(BTNode* p, KeyType k); //查找插入位置 i
	Result SearchBTree(BTree t, KeyType k); //查找关键字 k
	void InsertBTNode(BTNode*& p, int i, KeyType k, BTNode* q); //插入
	void SplitBTNode(BTNode*& p, BTNode*& q); //分裂
	void NewRoot(BTNode*& t, KeyType k, BTNode* p, BTNode* q); //生成新根结点
	void InsertBTree(BTree& t, int i, KeyType k, BTNode* p); //若结点过大, 则分裂调整
	void Remove(BTNode* p, int i); //结点删除 key[i]和孩子指针
	void Substitution(BTNode* p, int i); //查找被删关键字的替代叶子结点
	void MoveRight(BTNode* p, int i); //将双亲结点 p 中的最后一个关键字移入右结点 q 中将左结点 aq 中的最后一个关键字移入双亲结点 p 中* /
	void MoveLeft(BTNode* p, int i); /*将双
	亲结点 p 中的第一个关键字移入结点 aq 中，
	将
	结点 q 中的第一个关键字移入双亲结点 p 中*/
	void Combine(BTNode* p, int i); /*将
	双亲结点 p、右结点 q 合并入左结点 aq，
	并
	调整双亲结点 p 中的剩余关键字的位置*/
	void AdjustBTree(BTNode* p, int i); //删除结点 p 中的第 i 个关键字后, 调整 B 树
	int FindBTNode(BTNode* p, KeyType k, int& i); //反映是否在结点 p 中是否查找到关键字 k
	int BTNodeDelete(BTNode* p, KeyType k); //在结点 p 中查找并删除关键字 k
	void BTreeDelete(BTree& t, KeyType k); //构建删除框架，执行删除操作
	void DestroyBTree(BTree& t); //递归释放 B 树
	Status InitQueue(LinkList& L); //初始化队列
	LNode* CreateNode1(BTree t); //新建一个结点
	Status Enqueue1(LNode* p, BTree t); //元素 q 入队列
	Status Dequeue(LNode* p, BTNode*& q); //出队列，并以 q 返回值
	Status IfEmpty(LinkList L); //队列判空
	void DestroyQueue(LinkList L); //销毁队列
	Status Traverse(BTree t, LinkList L, int newline, int sum); //用队列遍历输出 B 树
	Status PrintBTree(BTree t); //输出B 树
	void Print_BTree(BTree bTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y);//输出B 树
	void Print_BTree(BTree bTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y, int
		frame);//输出 B 树
	void Print_Search_BTree(BTree bTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y, int
		frame, int key);//输出 B 树搜索
	//程序暂停时间 time 停留时间 毫秒
	void sleepTime(int time);
	void animationRecord(int totaltime, int frame, int x, int y, int data1, int data2,
		int p_x, int p_y);
	void animationSearchRecord(int totaltime, int frame, int x, int y, int data1, int
		data2, int p_x, int p_y, int flag, int codeid);
	void animationClean();
	void animationPrint(int totaltime, int frametime);
	void animationDraw(int totaltime, int frametime);
	//三叉树先根遍历演示
	void PreOrderPractice(CBiTreeNode* root);
	//三叉树的绘图：
	void animation3Draw(CBiTreeNode* root);
	void animationDrawSearch(int totaltime, int frametime, int x);
	//void animationDrawSearch(int totaltime, int frametime);
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::CBinarySortTreeEditorUI* ui;
	Linklist* listshow;
	CNodeEditorScene* m_scene;
	CEditorView* m_editorView;
	CNode* m_nodeFactory;
	CEdge* m_edgeFactory;
	CQuickHelpUI* m_quickHelp;
	QStringList list; //节点列表
	int list_array[1010]; //树数组
	CBiTree* avlTree;//新建树
	CBiTreeNode* root;//新建节点
	CBiTreeNode* next[8];
	CBiTreeNode* nextMAX[8];
	int top;
	int MaX;
	BigRoot* bigrootTree;//新建大根堆
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