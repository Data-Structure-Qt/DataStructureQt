#pragma once
#include "../base/CNodeEditorScene.h"
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
#include "../base/CEditorView.h"
#include "CNodeEditorUIController.h"
using namespace std;
class CEditorScene;
const int maxnum = 100;
const int maxint = 999999;
namespace Ui {
	class CGraphEditorUI;
}
struct CGraphVertexNode //ͼ�ı���
{
	int adjointVertex;
	CGraphVertexNode *next;
	CGraphVertexNode(int a = 0, CGraphVertexNode *n =
		NULL) :adjointVertex(a), next(n) {};
};
struct CGraphAdjointList {
	string data; //����
	CGraphVertexNode *firstEdage; //��һ����
};
struct MGraph {
	int numVertex; //�ڵ�����
	int numEdge; //������
	vector<CGraphAdjointList> adjointList; //����
	MGraph(int n = 10010) :adjointList(n) {};
};
typedef struct Animation { //����Ƭ��
	int totaltime;
	int functionid;
	QString para1;
	QString para2;
	int codefunctionid;
	int codefunctionlineid;
};
//Prim �㷨��Ҫ����
enum VisitIf { unvisited, visited };
class EBox {
public:
	int ivex, jvex; //�ñ���������������λ��
	EBox *ilink, *jlink; //�ֱ�ָ�������������������һ����
	int weight;
};
class VexBox {
public:
	string data;
	EBox *firstedge; //ָ���һ�������ö���ı�
	VisitIf mark; //���ʱ��
};
class AMLGraph {
public:
	VexBox adjmulist[1010];
	int vexnum, edgenum; //����ͼ�ĵ�ǰ�������ͱ���
};
//Kruskal
struct Edge_Kruskal {
	int u;
	int v;
	int weight;
	Edge_Kruskal() : u(0), v(0), weight(0) {}
	Edge_Kruskal(int _u, int _v, int _weight) {
		u = _u;
		v = _v;
		weight = _weight;
	}
	bool operator < (const Edge_Kruskal e) const {
		return this->weight < e.weight;
	}
};
//��������
struct topoNode
{
	int adjvex;
	topoNode* next;
};
class CGraphEditorUI : public QWidget
{
	Q_OBJECT
public:
	CGraphEditorUI(QWidget *parent = 0);
	~CGraphEditorUI();
	void setCNodeEditorUIController(CNodeEditorUIController *
		nodeEditorUIControlle);
	void setScene(CNodeEditorScene* scene);
	void setCQuickHelpUI(CQuickHelpUI* scene);
	void createGraph(MGraph &g);
	int getPosition(MGraph g, string value);
	void BFSTraverse(MGraph g);
	void DFS(MGraph g, int index);
	void DFSTraverse(MGraph g);
	void destroyGraph(MGraph &g);
	void NodeChangeColor(QString nodeID);
	void NodeChangeColorWithoutSuspand(QString nodeID);
	void EdgeChangeColor(QString firstNodeID, QString lastNodeID);
	void EdgeChangeColorWithoutSuspand(QString firstNodeID, QString
		lastNodeID);
	void MDijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum]);
	void searchPath(int *prev, int v, int u);
	//Ӧ���� Prim �ĳ�Ա����
	int LocateVex(VexBox adj[], int num, string v);
	void CreateGraph(AMLGraph *G);
	int FirstAdjVex(AMLGraph G, int v, int &wei);
	int NextAdjVex(AMLGraph G, int v, int w, int &wei);
	void PrintGraph(AMLGraph G);
	void MiniSpanTree_PRIM(AMLGraph G);
	//Ӧ���� Kruskal �ĳ�Ա����
	int FindSet(vector<int> uset, int i);
	void MiniSpanTree_Kruskal(AMLGraph G);
	//������������ĳ�Ա����
	int topoCreate(topoNode adj[], int n, int m);
	void topoPrint(int n);
	void topoSort(topoNode adj[], int n);
	//����������
	void DFSNonRecursive(MGraph g, int index);
	void DFSNonRecursiveTraverse(MGraph g);
	//
	void goToBeginButton();
	void stepBackButton();
	void suspendButton();
	void stepForwardButton();
	void goToEndButton();
	void animationDraw(int totaltime);
	void animationDrawWithoutSuspand(int totaltime);
	void sleepTime(int time);
	void setCEditorView(CEditorView * editorView);
	void animationRecord(int functionid, QString para1, QString para2, int
		codefunctionid, int codefunctionlineid);
	void animationRecord(int functionid, QString para1, QString para2);
	void animationview(int currenttime);
	void playButton();
private slots:
	void on_bfs_btn_clicked();
	void on_dfs_btn_clicked();
	void on_reset_btn_clicked();
	void on_dijkstra_btn_clicked();
	void on_prim_btn_clicked();
	void on_kruskal_btn_clicked();
	void on_topologicalSorting_btn_clicked();
	void on_Non_topologicalSorting_btn_clicked();
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::CGraphEditorUI *ui;
	CNodeEditorScene *m_scene;
	CEditorView *m_editorView;
	CNodeEditorUIController *m_nodeEditorUIController;
	CNode *m_nodeFactory;
	CEdge *m_edgeFactory;
	bool Mvisited[5000];//�ߵ����ֵ
	int follow[50];//��¼ Dijkstra ˳��
	//stack <int> mystack;
	stack<int> stack;
	std::stack<int> mystack2;
	std::stack<int> mystack;//��������
	int indegree[9999];//��������
	topoNode topoadj[9999];//��������
	CQuickHelpUI *m_quickHelp;
	int history_list_array[1010];
	int history_length = 0;
	Animation animation[200]; //���� /�ڼ�֡/ÿ֡���岽��
	Animation animationSearch[200]; //���� /�ڼ�֡/ÿ֡���岽��
		int history_wideSize[200], history_highSize[200];
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime;
	int onlytotaltime = 0;
	int timestamp = 0; //���ȿ���ʱ���
	int endplaybuttonflag = 0;//ֹͣ���ű�־λ
};