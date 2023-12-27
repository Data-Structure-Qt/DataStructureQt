#pragma once
#include "CNodeEditorScene.h"
#include "CQuickHelpUI.h"
#include <QtWidgets/QWidget>
#include "LinklistNode.h"
class CEditorScene;
namespace Ui {
	class LinklistUI;
}
typedef struct Animation {
	//����Ƭ��
	int x;
	//λ��
	int data; //����
	int flag;
	int codeid;
};
class LinklistUI : public QWidget
{
	Q_OBJECT
public:
	LinklistUI(QWidget* parent = 0);//���캯��
	~LinklistUI();//��������
	void setScene(CNodeEditorScene* scene);
	//���ݻ��ƴ���ָ��
	void setCQuickHelpUI(CQuickHelpUI* scene);
	//���ݴ���׷�ٴ���ָ��
	void goToBeginButton();
	void stepBackButton();
	void playButton();
	void suspendButton();
	void stepForwardButton();
	void goToEndButton();
signals:
	void SearchBtn_SendText();
private slots:
	//������ť�ۺ���
	void on_create_btn_clicked();

	//��հ�ť�ۺ���
	void on_clean_btn_clicked();

	//ͷ�����밴ť�ۺ���
	void on_headinsert_btn_clicked();

	//β�����밴ť�ۺ���
	void on_tailinsert_btn_clicked();

	//���밴ť�ۺ���
	void on_locationinsert_btn_clicked();

	//ͷ��ɾ����ť�ۺ���
	void on_headdelete_btn_clicked();

	//β��ɾ����ť�ۺ���
	void on_taildelete_btn_clicked();

	//ɾ����ť�ۺ���
	void on_locationdelete_btn_clicked();

	//������ť�ۺ���
	void on_search_btn_clicked();

	void reverseList();//��������
	void on_Invert_btn_clicked();



	//������ͣʱ�� time ͣ��ʱ�� ����
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
	Ui::LinklistUI* ui;
	//������崰��ָ��
	CNodeEditorScene* m_scene;
	//�������򴰿�ָ��
	CNode* m_nodeFactory;
	//�ڵ㹤����ָ��
	CEdge* m_edgeFactory;
	CQuickHelpUI* m_quickHelp;
	QList<LinklistNode> QLinkList;
	//����ڵ�����
	Animation animation[200][200];
	//����/�ڼ�֡/ÿ֡���岽��
	Animation animationSearch[200][200];
	//����/�ڼ�֡/ÿ֡���岽��
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime;
	//����������
	int onlytotaltime = 0;
	//������
	int timestamp = 0;
	//���ȿ���ʱ���
	int endplaybuttonflag = 0;
	//ֹͣ���ű�־λ
	int createflag = 0;
	int deleteflag = 0;
	int searchflag = 0;


	//LinklistNode* m_Head; // ˫�������ͷ�ڵ�
	//LinklistNode* m_Tail; // ˫�������β�ڵ�



};
