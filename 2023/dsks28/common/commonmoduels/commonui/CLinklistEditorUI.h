#pragma once
#include "../commonmoduels/CNodeEditorScene.h" 
#include "CQuickHelpUI.h" 
#include <QWidget> 
#include <QLinkedList> 
#include "QListNode.h" 
class CEditorScene;
namespace Ui {
	class CLinklistEditorUI;
}

// �ҵ��޸�
typedef struct Animation {			//����Ƭ��
	int x;  // λ��
	int data; // ����
	int flag;
	int codeid;
};

class CLinklistEditorUI : public QWidget
{
	Q_OBJECT
public:
	CLinklistEditorUI(QWidget* parent = 0);//���캯�� 
	~CLinklistEditorUI();//�������� 
	void setScene(CNodeEditorScene* scene);
	void setCQuickHelpUI(CQuickHelpUI* scene);

	void goToBeginButton();
	void stepBackButton();
	void playButton();
	void suspendButton();
	void stepForwardButton();
	void goToEndButton();
signals:
	void SearchBtn_SendText();
private slots:
	void on_search_btn_clicked();
	void on_create_btn_clicked();
	void on_clean_btn_clicked();
	void on_headinsert_btn_clicked();
	void on_tailinsert_btn_clicked();
	void on_locationinsert_btn_clicked();
	void on_headdelete_btn_clicked();
	void on_taildelete_btn_clicked();
	void on_locationdelete_btn_clicked();

	//�ҵ��޸�
	//������ͣʱ��  time ͣ��ʱ�� ����
	void sleepTime(int time);
	void animationRecord(int totaltime, int frame, int x, int data);
	void animationSearchRecord(int totaltime, int frame, int x, int data, int flag, int codeid);
	void animationClean();
	void animationPrint(int totaltime, int frametime);
	void animationDraw(int totaltime, int frametime);
	void animationDrawSearch(int totaltime, int frametime, int x);

protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::CLinklistEditorUI* ui;
	CNodeEditorScene* m_scene;
	CNode* m_nodeFactory;
	CEdge* m_edgeFactory;
	CQuickHelpUI* m_quickHelp;
	QList<QListNode> QLinkList; //����ڵ����� 

	// �ҵ��޸�
	Animation animation[200][200];					//���� /�ڼ�֡/ÿ֡���岽��
	Animation animationSearch[200][200];					//���� /�ڼ�֡/ÿ֡���岽��
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime;		// ����������
	int onlytotaltime = 0;	// ������
	int timestamp = 0;		//���ȿ���ʱ���
	int endplaybuttonflag = 0;//ֹͣ���ű�־λ
	int createflag = 0;
	int deleteflag = 0;
	int searchflag = 0;
};
