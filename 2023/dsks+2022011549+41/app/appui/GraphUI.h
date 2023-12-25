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
	int getPosition(MGraph g, string value);
	void NodeChangeColor(QString nodeID);
	void NodeChangeColorWithoutSuspand(QString nodeID);
	void EdgeChangeColor(QString firstNodeID, QString lastNodeID);
	void EdgeChangeColorWithoutSuspand(QString firstNodeID,
		QString lastNodeID);
	void MDijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum]);
	void searchPath(int *prev, int v, int u);
	void PrintGraph(AMLGraph G);
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
	void on_reset_btn_clicked();
	void on_dijkstra_btn_clicked();
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
	bool Mvisited[5000];//�ߵ����ֵ
	int follow[50];//��¼ Dijkstra ˳��
	stack<int>mystack;//��������
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