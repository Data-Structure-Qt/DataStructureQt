#pragma once

#include "CNodeEditorScene.h"
#include <QWidget>
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include <stack>
#include <list>
#include <limits.h>
#include <set>
#include <map>
#include <algorithm>
#include<cmath>
#include<cstdio>
#include "CQuickHelpUI.h"
#include "CEditorView.h"
#include "CNodeEditorUIController.h"
#include "Graph.h"
using namespace std;
class CEditorScene;
const int maxnum = 100;
const int maxint = INT_MAX;
namespace Ui {
	class GraphUI;
}
class GraphUI : public QWidget
{
	Q_OBJECT
public:
	GraphUI(QWidget* parent = 0);
	~GraphUI();
	int getNodeIndex(CNode* node);
	void setCNodeEditorUIController(CNodeEditorUIController* nodeEditorUIControlle);
	void setScene(CNodeEditorScene* scene);
	void setCQuickHelpUI(CQuickHelpUI* scene);
	int getPosition(MGraph g, string value);
	void NodeChangeColor(QString nodeID);
	void NodeChangeColorWithoutSuspand(QString nodeID);
	void EdgeChangeColor(QString firstNodeID, QString lastNodeID);
	void EdgeChangeColorWithoutSuspand(QString firstNodeID,QString lastNodeID);
	void PrintGraph(AMLGraph G);
	void goToBeginButton();
	void stepBackButton();
	void suspendButton();
	void stepForwardButton();
	void goToEndButton();
	void animationDraw(int totaltime);
	void animationDrawWithoutSuspand(int totaltime);
	void sleepTime(int time);
	void setCEditorView(CEditorView* editorView);
	void animationRecord(int functionid, QString para1, QString para2,int codefunctionid, int codefunctionlineid);
	void animationRecord(int functionid, QString para1, QString para2);
	void animationview(int currenttime);
	void playButton();
	//求中心点的函数
	std::vector<std::vector<int>> initializeDistanceMatrix(const QList<CNode*>& nodes, int n);
	void calculateShortestPaths(std::vector<std::vector<int>>& dist, int n);
	void findAndMarkCenterPoints(const QList<CNode*>& nodes, const std::vector<std::vector<int>>& dist, int n);
	int calculateEccentricity(const std::vector<std::vector<int>>& dist, int nodeIndex, int n);
private slots:
	void on_reset_btn_clicked();
	void on_findCenterPoints_btn_clicked();
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::GraphUI* ui;
	CNodeEditorScene* m_scene;
	CEditorView* m_editorView;
	CNodeEditorUIController* m_nodeEditorUIController;
	CNode* m_nodeFactory;
	CEdge* m_edgeFactory;
	bool Mvisited[5000];//边的最大值
	int follow[50];//记录 Dijkstra 顺序
	stack<int>mystack;//拓扑排序
	int indegree[9999];//拓扑排序
	topoNode topoadj[9999];//拓扑排序
	CQuickHelpUI* m_quickHelp;
	int history_list_array[1010];
	int history_length = 0;
	Animation animation[200]; //动画 /第几帧/每帧具体步骤
	Animation animationSearch[200]; //动画 /第几帧/每帧具体步骤
	int history_wideSize[200], history_highSize[200];
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime;
	int onlytotaltime = 0;
	int timestamp = 0; //进度控制时间戳
	int endplaybuttonflag = 0;//停止播放标志位
};