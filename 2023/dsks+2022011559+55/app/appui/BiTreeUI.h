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
	
	//B����������
	void on_Btree_create_btn_clicked();
	//B������
	void on_Btree_insert_btn_clicked();
	//B������
	void on_Btree_search_btn_clicked();
	//B��ɾ��
	void on_Btree_remove_btn_clicked();
	//B������
	void on_Btree_destroy_btn_clicked();
	//B��
	Status InitBTree(BTree &t);                                     //��ʼ��
	int SearchBTNode(BTNode *p, KeyType k);                         //���Ҳ���λ��i 
	Result SearchBTree(BTree t, KeyType k);                         //���ҹؼ���k
	void InsertBTNode(BTNode *&p, int i, KeyType k, BTNode *q);     //����
	void SplitBTNode(BTNode *&p, BTNode *&q);                       //����
	void NewRoot(BTNode *&t, KeyType k, BTNode *p, BTNode *q);      //�����¸����
	int InsertBTree(BTree &t, int i, KeyType k, BTNode *p);        //��������,����ѵ���
	void Remove(BTNode *p, int i);                                  //���ɾ��key[i]�ͺ���ָ��
	void Substitution(BTNode *p, int i);                            //���ұ�ɾ�ؼ��ֵ����Ҷ�ӽ��
	void MoveRight(BTNode *p, int i);                               //��˫�׽��p�е����һ���ؼ��������ҽ��q�н�����aq�е����һ���ؼ�������˫�׽��p��*/
	void MoveLeft(BTNode *p, int i);                                 /*��˫�׽��p�еĵ�һ���ؼ���������aq�У�
																	 �����q�еĵ�һ���ؼ�������˫�׽��p��*/
	void Combine(BTNode *p, int i);                                  /*��˫�׽��p���ҽ��q�ϲ�������aq��
																	������˫�׽��p�е�ʣ��ؼ��ֵ�λ��*/
	void AdjustBTree(BTNode *p, int i);                              //ɾ�����p�еĵ�i���ؼ��ֺ�,����B��                                                                
	int FindBTNode(BTNode *p, KeyType k, int &i);                     //��ӳ�Ƿ��ڽ��p���Ƿ���ҵ��ؼ���k 
	int BTNodeDelete(BTNode *p, KeyType k);                          //�ڽ��p�в��Ҳ�ɾ���ؼ���k
	void BTreeDelete(BTree &t, KeyType k);                           //����ɾ����ܣ�ִ��ɾ������ 
	void DestroyBTree(BTree &t);                                    //�ݹ��ͷ�B��
	Status InitQueue(LinkList &L);                                  //��ʼ������ 
	Status Dequeue(LNode *p, BTNode *&q);                            //�����У�����q����ֵ
	Status IfEmpty(LinkList L);                                     //�����п� 
	void DestroyQueue(LinkList L);                                  //���ٶ��� 
	Status Traverse(BTree t, LinkList L, int newline, int sum);        //�ö��б������B�� 
	Status PrintBTree(BTree t);                                     //���B�� 
	LNode* CreateNode1(BTree t);                                     //�½�һ����� 
	Status Enqueue1(LNode *p, BTree t);                               //Ԫ��q�����


	void Print_BTree(BTree bTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y, int frame);//���B��
	void Print_Search_BTree(BTree bTree, double x,
		double y, double wideSize, double highSize, double p_x, double p_y, int frame, int key);//���B������



	//������ͣʱ��  time ͣ��ʱ�� ����
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
	QStringList list; //�ڵ��б�
	int list_array[1010]; //������

	const int m = 3;                      //�趨B���Ľ��� 
	const int Max = m - 1;                //�������ؼ������� 
	const int Min = (m - 1) / 2;          //������С�ؼ������� 
	BTree t = NULL;
	Result s;                             //�趨���ҽ�� 


	int history_list_array[1010];
	int history_length = 0;
	Animation animation[200][200];					//���� /�ڼ�֡/ÿ֡���岽��
	Animation animationSearch[200][200];					//���� /�ڼ�֡/ÿ֡���岽��
	int history_wideSize[200], history_highSize[200];
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime;
	int onlytotaltime = 0;
	int timestamp = 0;		//���ȿ���ʱ���
	int endplaybuttonflag = 0;//ֹͣ���ű�־λ
};