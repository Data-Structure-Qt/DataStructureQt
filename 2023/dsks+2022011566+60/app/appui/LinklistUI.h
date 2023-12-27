#pragma once
#include "CNodeEditorScene.h" 
#include "CQuickHelpUI.h" 
#include <QWidget> 
#include "LinklistNode.h" 
#include<vector>
class CEditorScene;
namespace Ui {
	 class LinklistUI;
}
typedef struct Animation { //����Ƭ��
	int x; // λ��
	int data; // ����
	int flag;
	int codeid;
};
class LinklistUI : public QWidget
{
	Q_OBJECT
public:
	LinklistUI(QWidget* parent = 0);//���캯��
	~LinklistUI();//��������
	void setScene(CNodeEditorScene* scene); //���ݻ��ƴ���ָ��
	void setCQuickHelpUI(CQuickHelpUI* scene); //���ݴ���׷�ٴ���ָ��
	void goToBeginButton();
	void stepBackButton();
	void playButton();
	void suspendButton();
	void stepForwardButton();
	void goToEndButton();
	void merge_3(std::vector<int>& arr, int l, int m1, int m2, int r);
signals:
	void SearchBtn_SendText();
private slots:
	void on_create_btn_clicked(); //������ť�ۺ���
	void on_clean_btn_clicked(); //��հ�ť�ۺ���
	void LinklistUI::merge_sort_3(std::vector<int>& arr, int l, int r, int needcen,int nowcen);
	void LinklistUI::merge_3_sort(std::vector<int>& arr, int l, int r, int needcen,int nowcen);
	void sleepTime(int time);
	void animationRecord(int totaltime, int frame, int x, int data);
	void animationSearchRecord(int totaltime, int frame, int x, int data, int flag, int codeid);
	void animationClean();
	void animationPrint(int totaltime, int frametime);
	void animationDraw(int totaltime, int frametime);
	void animationDrawSearch(int totaltime, int frametime, int x);
	void on_three_way_merge_sort();
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::LinklistUI* ui; //������崰��ָ��
	CNodeEditorScene* m_scene; //�������򴰿�ָ��
	CNode* m_nodeFactory; //�ڵ㹤����ָ��
	CEdge* m_edgeFactory;
	CQuickHelpUI* m_quickHelp;
	QList<LinklistNode> QLinkList; //����ڵ�����
	Animation animation[200][200]; //���� /�ڼ�֡/ÿ֡���岽��
	Animation animationSearch[200][200]; //���� /�ڼ�֡/ÿ֡���岽��
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime; // ����������
	int onlytotaltime = 0; // ������
	int timestamp = 0; //���ȿ���ʱ���
	int endplaybuttonflag = 0; //ֹͣ���ű�־λ
	int createflag = 0;
	int deleteflag = 0;
	int searchflag = 0;
};