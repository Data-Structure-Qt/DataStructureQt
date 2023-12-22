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
const int maxint = 999999;
namespace Ui {
	class GraphUI;
}
class GraphUI : public QWidget
{
	Q_OBJECT
public:
	GraphUI(QWidget *parent = 0);
	~GraphUI();
	void setCNodeEditorUIController(CNodeEditorUIController
		* nodeEditorUIControlle);
	void setScene(CNodeEditorScene* scene);
	void setCQuickHelpUI(CQuickHelpUI* scene);
	void createGraph(MGraph &g);
	int getPosition(MGraph g, string value);
	void levelTraverse(MGraph g);
	void DFS(MGraph g, int index);
	void DFSTraverse(MGraph g);
	void destroyGraph(MGraph &g);
	void NodeChangeColor(QString nodeID);
	void NodeChangeColorWithoutSuspand(QString nodeID);
	void EdgeChangeColor(QString firstNodeID, QString lastNodeID);
	void EdgeChangeColorWithoutSuspand(QString firstNodeID,
		QString lastNodeID);
	void MDijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum]);
	void searchPath(int *prev, int v, int u);
	//应用于 Prim 的成员函数
	int LocateVex(VexBox adj[], int num, string v);
	void CreateGraph(AMLGraph *G);
	int FirstAdjVex(AMLGraph G, int v, int &wei);
	int NextAdjVex(AMLGraph G, int v, int w, int &wei);
	void PrintGraph(AMLGraph G);
	void MiniSpanTree_PRIM(AMLGraph G);
	//应用于 Kruskal 的成员函数
	int FindSet(vector<int> uset, int i);
	void MiniSpanTree_Kruskal(AMLGraph G);
	//用于拓扑排序的成员函数
	int topoCreate(topoNode adj[], int n, int m);
	void topoPrint(int n);
	void topoSort(topoNode adj[], int n);
	void goToBeginButton();
	void stepBackButton();
	void suspendButton();
	void stepForwardButton();
	void goToEndButton();
	void animationDraw(int totaltime);
	void animationDrawWithoutSuspand(int totaltime);
	void sleepTime(int time);
	void setCEditorView(CEditorView * editorView);
	void animationRecord(int functionid, QString para1, QString para2,
		int codefunctionid, int codefunctionlineid);
	void animationRecord(int functionid, QString para1, QString para2);
	void animationview(int currenttime);
	void playButton();
private slots:
	void on_leveltraversal_btn_clicked();
	void on_reset_btn_clicked();
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::GraphUI *ui;
	CNodeEditorScene *m_scene;
	CEditorView *m_editorView;
	CNodeEditorUIController *m_nodeEditorUIController;
	CNode *m_nodeFactory;
	CEdge *m_edgeFactory;
	bool Mvisited[5000];//边的最大值
	int follow[50];//记录 Dijkstra 顺序
	stack<int>mystack;//拓扑排序
	int indegree[9999];//拓扑排序
	topoNode topoadj[9999];//拓扑排序
	CQuickHelpUI *m_quickHelp;
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