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
	//动画片段
	int x;
	//位置
	int data; //数据
	int flag;
	int codeid;
};
class LinklistUI : public QWidget
{
	Q_OBJECT
public:
	LinklistUI(QWidget* parent = 0);//构造函数
	~LinklistUI();//析构函数
	void setScene(CNodeEditorScene* scene);
	//传递绘制窗口指针
	void setCQuickHelpUI(CQuickHelpUI* scene);
	//传递代码追踪窗口指针
	void goToBeginButton();
	void stepBackButton();
	void playButton();
	void suspendButton();
	void stepForwardButton();
	void goToEndButton();
signals:
	void SearchBtn_SendText();
private slots:
	//创建按钮槽函数
	void on_create_btn_clicked();

	//清空按钮槽函数
	void on_clean_btn_clicked();

	//头部插入按钮槽函数
	void on_headinsert_btn_clicked();

	//尾部插入按钮槽函数
	void on_tailinsert_btn_clicked();

	//插入按钮槽函数
	void on_locationinsert_btn_clicked();

	//头部删除按钮槽函数
	void on_headdelete_btn_clicked();

	//尾部删除按钮槽函数
	void on_taildelete_btn_clicked();

	//删除按钮槽函数
	void on_locationdelete_btn_clicked();

	//搜索按钮槽函数
	void on_search_btn_clicked();

	void reverseList();//逆置链表
	void on_Invert_btn_clicked();



	//程序暂停时间 time 停留时间 毫秒
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
	//控制面板窗口指针
	CNodeEditorScene* m_scene;
	//绘制区域窗口指针
	CNode* m_nodeFactory;
	//节点工厂类指针
	CEdge* m_edgeFactory;
	CQuickHelpUI* m_quickHelp;
	QList<LinklistNode> QLinkList;
	//链表节点容器
	Animation animation[200][200];
	//动画/第几帧/每帧具体步骤
	Animation animationSearch[200][200];
	//动画/第几帧/每帧具体步骤
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime;
	//搜索结点个数
	int onlytotaltime = 0;
	//结点个数
	int timestamp = 0;
	//进度控制时间戳
	int endplaybuttonflag = 0;
	//停止播放标志位
	int createflag = 0;
	int deleteflag = 0;
	int searchflag = 0;


	//LinklistNode* m_Head; // 双向链表的头节点
	//LinklistNode* m_Tail; // 双向链表的尾节点



};
