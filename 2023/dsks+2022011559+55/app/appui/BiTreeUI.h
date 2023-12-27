#include "CNodeEditorScene.h"
#include "CQuickHelpUI.h"
#include "CEditorView.h"
#include <QWidget>
#include "BiTree.h"
#include "ui_BiTreeUI.h"
#include "CNodeEditorScene.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include <cmath>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 
class CEditorScene;
namespace Ui {
	class BiTreeUI;
}

class BiTreeUI : public QWidget
{
	Q_OBJECT
public:
	BiTreeUI(QWidget *parent = 0);
	~BiTreeUI();
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
	
	//B树创建函数
	void on_Btree_create_btn_clicked();
	//B树插入
	void on_Btree_insert_btn_clicked();
	//B树查找
	void on_Btree_search_btn_clicked();
	//B树删除
	void on_Btree_remove_btn_clicked();
	//B树销毁
	void on_Btree_destroy_btn_clicked();
	//B树
	Status InitBTree(BTree &t);                                     //初始化
	int SearchBTNode(BTNode *p, KeyType k);                         //查找插入位置i 
	Result SearchBTree(BTree t, KeyType k);                         //查找关键字k
	void InsertBTNode(BTNode *&p, int i, KeyType k, BTNode *q);     //插入
	void SplitBTNode(BTNode *&p, BTNode *&q);                       //分裂
	void NewRoot(BTNode *&t, KeyType k, BTNode *p, BTNode *q);      //生成新根结点
	int InsertBTree(BTree &t, int i, KeyType k, BTNode *p);        //若结点过大,则分裂调整
	void Remove(BTNode *p, int i);                                  //结点删除key[i]和孩子指针
	void Substitution(BTNode *p, int i);                            //查找被删关键字的替代叶子结点
	void MoveRight(BTNode *p, int i);                               //将双亲结点p中的最后一个关键字移入右结点q中将左结点aq中的最后一个关键字移入双亲结点p中*/
	void MoveLeft(BTNode *p, int i);                                 /*将双亲结点p中的第一个关键字移入结点aq中，
																	 将结点q中的第一个关键字移入双亲结点p中*/
	void Combine(BTNode *p, int i);                                  /*将双亲结点p、右结点q合并入左结点aq，
																	并调整双亲结点p中的剩余关键字的位置*/
	void AdjustBTree(BTNode *p, int i);                              //删除结点p中的第i个关键字后,调整B树                                                                
	int FindBTNode(BTNode *p, KeyType k, int &i);                     //反映是否在结点p中是否查找到关键字k 
	int BTNodeDelete(BTNode *p, KeyType k);                          //在结点p中查找并删除关键字k
	void BTreeDelete(BTree &t, KeyType k);                           //构建删除框架，执行删除操作 
	void DestroyBTree(BTree &t);                                    //递归释放B树
	Status InitQueue(LinkList &L);                                  //初始化队列 
	Status Dequeue(LNode *p, BTNode *&q);                            //出队列，并以q返回值
	Status IfEmpty(LinkList L);                                     //队列判空 
	void DestroyQueue(LinkList L);                                  //销毁队列 
	Status Traverse(BTree t, LinkList L, int newline, int sum);        //用队列遍历输出B树 
	Status PrintBTree(BTree t);                                     //输出B树 
	LNode* CreateNode1(BTree t);                                     //新建一个结点 
	Status Enqueue1(LNode *p, BTree t);                               //元素q入队列


	void Print_BTree(BTree bTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y, int frame);//输出B树
	void Print_Search_BTree(BTree bTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y, int frame, int key);//输出B树搜索



	//程序暂停时间  time 停留时间 毫秒
	void sleepTime(int time);
	void animationRecord(int totaltime, int frame, int x, int y, int data1, int data2, int p_x, int p_y);
	void animationSearchRecord(int totaltime, int frame, int x, int y, int data1, int data2, int p_x, int p_y, int flag, int codeid);
	void animationClean();
	void animationPrint(int totaltime, int frametime);
	void animationDraw(int totaltime, int frametime);
	void animationDrawSearch(int totaltime, int frametime);



protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::BiTreeUI *ui;
	CNodeEditorScene *m_scene;
	CEditorView *m_editorView;
	CNode *m_nodeFactory;
	CEdge *m_edgeFactory;
	CQuickHelpUI *m_quickHelp;
	QStringList list; //节点列表
	int list_array[1010]; //树数组

	const int m = 3;                      //设定B树的阶数 
	const int Max = m - 1;                //结点的最大关键字数量 
	const int Min = (m - 1) / 2;          //结点的最小关键字数量 
	BTree t = NULL;
	Result s;                             //设定查找结果 


	int history_list_array[1010];
	int history_length = 0;
	Animation animation[200][200];					//动画 /第几帧/每帧具体步骤
	Animation animationSearch[200][200];					//动画 /第几帧/每帧具体步骤
	int history_wideSize[200], history_highSize[200];
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime;
	int onlytotaltime = 0;
	int timestamp = 0;		//进度控制时间戳
	int endplaybuttonflag = 0;//停止播放标志位
};