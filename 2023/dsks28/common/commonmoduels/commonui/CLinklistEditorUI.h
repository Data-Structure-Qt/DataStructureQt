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

// 我的修改
typedef struct Animation {			//动画片段
	int x;  // 位置
	int data; // 数据
	int flag;
	int codeid;
};

class CLinklistEditorUI : public QWidget
{
	Q_OBJECT
public:
	CLinklistEditorUI(QWidget* parent = 0);//构造函数 
	~CLinklistEditorUI();//析构函数 
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

	//我的修改
	//程序暂停时间  time 停留时间 毫秒
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
	QList<QListNode> QLinkList; //链表节点容器 

	// 我的修改
	Animation animation[200][200];					//动画 /第几帧/每帧具体步骤
	Animation animationSearch[200][200];					//动画 /第几帧/每帧具体步骤
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime;		// 搜索结点个数
	int onlytotaltime = 0;	// 结点个数
	int timestamp = 0;		//进度控制时间戳
	int endplaybuttonflag = 0;//停止播放标志位
	int createflag = 0;
	int deleteflag = 0;
	int searchflag = 0;
};
