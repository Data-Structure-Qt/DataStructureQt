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
//B_��
typedef int KeyType;
typedef struct node {
	int keynum; //���ؼ��ָ���
	KeyType key[10]; //�ؼ��֣�0 ����
	struct node *parent; //˫��ָ��
	struct node *ptr[10]; //����ָ������
}BTNode, *BTree;
typedef struct { //���ҷ�������
	BTNode *pt;
	int i; //�ؼ���λ��; 
	int fag; //���ҳɹ�����־
}Result;
typedef struct LNode { //���������������
	BTree data;
	struct LNode *next;
}LNode, *LinkList;
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
	//ƽ��������ݹ�չʾ����
	void inOrderPrint(CBiTreeNode * root, double x, double y,
		double wideSize, double highSize, double p_x, double p_y, int frame);
	//����������ƽ��������ݹ�չʾ����
	void inOrderPrint_search(CBiTreeNode * root, double x, double y,
		double wideSize, double highSize, double p_x, double p_y, int data, int frame);
	//����������ݹ�չʾ����
	void inOrderPrint_SimulationTree(CBiTreeNode* root, double x,
		double y, double Branch_length, double Branch_angle,
		double Change_angle, double p_x, double p_y);
	//�������
	void PreOrderBiTree(CBiTreeNode* root, string &In);
	//�������
	void InOrderBiTree(CBiTreeNode* root, string &In);
	//�������
	void PostOrderBiTree(CBiTreeNode* root, string &In);
	//��ȡ���ĸ߶�
	void DepthOfBiTree(CBiTreeNode* root, int &In);
	//������ͣʱ�� time ͣ��ʱ�� ����
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
	QStringList list; //�ڵ��б�
	int list_array[1010]; //������
	CBiTree* avlTree;//�½���
	CBiTreeNode* root;//�½��ڵ�
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
