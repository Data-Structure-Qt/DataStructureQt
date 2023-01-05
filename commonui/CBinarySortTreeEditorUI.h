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
//B_��
typedef int KeyType;
typedef struct node {
	int keynum; //���ؼ��ָ���
	KeyType key[10]; //�ؼ��֣�0 ����
	struct node* parent; //˫��ָ��
	struct node* ptr[10]; //����ָ������
}BTNode, * BTree;
typedef struct { //���ҷ�������
	BTNode* pt;
	int i; //�ؼ���λ��; 
	int fag; //���ҳɹ�����־
}Result;
typedef struct LNode { //���������������
	BTree data;
	struct LNode* next;
}LNode, * LinkList;
typedef struct Animation { //����Ƭ��
	int x;
	int y;
	int data1;
	int data2;
	int p_x;
	int p_y;
	int flag;
	int codeid;
};
typedef enum status { //ö������
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
	//ƽ���������������
	void on_binarytree_create_btn_clicked();
	//�����������������
	void on_binarytree_SimulationTree_creat_btn_clicked();
	//ƽ�������ɾ������
	void on_binarytree_delete_btn_clicked();
	//ƽ��������ڵ�ɾ������
	void on_binarytree_node_delete_btn_clicked();
	//ƽ��������ڵ���Һ���
	void on_binarytree_node_search_btn_clicked();
	//����Ѵ�������
	void on_bigroottree_create_btn_clicked();
	//����Ѳ���
	void on_bigroottree_insert_btn_clicked();
	//�����ɾ��
	void on_bigroottree_remove_btn_clicked();
	//B ����������
	void on_Btree_create_btn_clicked();
	//B ������
	void on_Btree_insert_btn_clicked();
	//B ��ɾ��
	void on_Btree_remove_btn_clicked();
	//B ������
	void on_Btree_destroy_btn_clicked();
	//ƽ��������ݹ�չʾ����
	void inOrderPrint(CBiTreeNode* root, double x, double y, double wideSize,
		double highSize, double p_x, double p_y, int frame);
	//����������ƽ��������ݹ�չʾ����
	void inOrderPrint_search(CBiTreeNode* root, double x, double y, double
		wideSize, double highSize, double p_x, double p_y, int data, int frame);
	//����������ݹ�չʾ����
	void inOrderPrint_SimulationTree(CBiTreeNode* root, double x,
		double y, double Branch_length, double Branch_angle, double
		Change_angle, double p_x, double p_y);
	//�������ȸ�����
	void PreOrder(CBiTreeNode* root, string& In);

	//�������
	void PreOrderBiTree(CBiTreeNode* root, string& In);
	//�������
	void InOrderBiTree(CBiTreeNode* root, string& In);
	//�������
	void PostOrderBiTree(CBiTreeNode* root, string& In);
	//��ȡ���ĸ߶�
	void DepthOfBiTree(CBiTreeNode* root, int& In);
	//��������в���Ԫ��
	bool insertBigRootTree(int val, BigRoot* bigrootTree);
	//�Ӵ������ɾ��Ԫ��
	bool removeBigRootTree(int val, BigRoot* bigrootTree);
	//��ӡ�����
	void printBigRootTree(BigRoot* bigrootTree);
	//��ȡ�Ѷ�Ԫ��
	int getTopBigRootTree(BigRoot* bigrootTree);
	//����ָ�����鴴�������
	bool creatBigRootTree(int a[], int size, BigRoot* bigrootTree);
	//���������ӡ�����
	void Print_BigRootTree(int index, BigRoot* bigrootTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y);
	//B ��
	Status InitBTree(BTree& t); //��ʼ��
	int SearchBTNode(BTNode* p, KeyType k); //���Ҳ���λ�� i
	Result SearchBTree(BTree t, KeyType k); //���ҹؼ��� k
	void InsertBTNode(BTNode*& p, int i, KeyType k, BTNode* q); //����
	void SplitBTNode(BTNode*& p, BTNode*& q); //����
	void NewRoot(BTNode*& t, KeyType k, BTNode* p, BTNode* q); //�����¸����
	void InsertBTree(BTree& t, int i, KeyType k, BTNode* p); //��������, ����ѵ���
	void Remove(BTNode* p, int i); //���ɾ�� key[i]�ͺ���ָ��
	void Substitution(BTNode* p, int i); //���ұ�ɾ�ؼ��ֵ����Ҷ�ӽ��
	void MoveRight(BTNode* p, int i); //��˫�׽�� p �е����һ���ؼ��������ҽ�� q �н����� aq �е����һ���ؼ�������˫�׽�� p ��* /
	void MoveLeft(BTNode* p, int i); /*��˫
	�׽�� p �еĵ�һ���ؼ��������� aq �У�
	��
	��� q �еĵ�һ���ؼ�������˫�׽�� p ��*/
	void Combine(BTNode* p, int i); /*��
	˫�׽�� p���ҽ�� q �ϲ������� aq��
	��
	����˫�׽�� p �е�ʣ��ؼ��ֵ�λ��*/
	void AdjustBTree(BTNode* p, int i); //ɾ����� p �еĵ� i ���ؼ��ֺ�, ���� B ��
	int FindBTNode(BTNode* p, KeyType k, int& i); //��ӳ�Ƿ��ڽ�� p ���Ƿ���ҵ��ؼ��� k
	int BTNodeDelete(BTNode* p, KeyType k); //�ڽ�� p �в��Ҳ�ɾ���ؼ��� k
	void BTreeDelete(BTree& t, KeyType k); //����ɾ����ܣ�ִ��ɾ������
	void DestroyBTree(BTree& t); //�ݹ��ͷ� B ��
	Status InitQueue(LinkList& L); //��ʼ������
	LNode* CreateNode1(BTree t); //�½�һ�����
	Status Enqueue1(LNode* p, BTree t); //Ԫ�� q �����
	Status Dequeue(LNode* p, BTNode*& q); //�����У����� q ����ֵ
	Status IfEmpty(LinkList L); //�����п�
	void DestroyQueue(LinkList L); //���ٶ���
	Status Traverse(BTree t, LinkList L, int newline, int sum); //�ö��б������ B ��
	Status PrintBTree(BTree t); //���B ��
	void Print_BTree(BTree bTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y);//���B ��
	void Print_BTree(BTree bTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y, int
		frame);//��� B ��
	void Print_Search_BTree(BTree bTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y, int
		frame, int key);//��� B ������
	//������ͣʱ�� time ͣ��ʱ�� ����
	void sleepTime(int time);
	void animationRecord(int totaltime, int frame, int x, int y, int data1, int data2,
		int p_x, int p_y);
	void animationSearchRecord(int totaltime, int frame, int x, int y, int data1, int
		data2, int p_x, int p_y, int flag, int codeid);
	void animationClean();
	void animationPrint(int totaltime, int frametime);
	void animationDraw(int totaltime, int frametime);
	//�������ȸ�������ʾ
	void PreOrderPractice(CBiTreeNode* root);
	//�������Ļ�ͼ��
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
	QStringList list; //�ڵ��б�
	int list_array[1010]; //������
	CBiTree* avlTree;//�½���
	CBiTreeNode* root;//�½��ڵ�
	CBiTreeNode* next[8];
	CBiTreeNode* nextMAX[8];
	int top;
	int MaX;
	BigRoot* bigrootTree;//�½������
	const int m = 3; //�趨 B ���Ľ���
	const int Max = m - 1; //�������ؼ�������
	const int Min = (m - 1) / 2; //������С�ؼ�������
	BTree t = NULL;
	Result s; //�趨���ҽ��
	int history_list_array[1010];
	int history_length = 0;
	Animation animation[200][200]; //���� /�ڼ�֡/ÿ֡���岽��
	Animation animationSearch[200][200]; //���� /�ڼ�֡/ÿ֡���岽��
	int history_wideSize[200], history_highSize[200];
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime;
	int onlytotaltime = 0;
	int timestamp = 0; //���ȿ���ʱ���
	int endplaybuttonflag = 0;//ֹͣ���ű�־λ

};