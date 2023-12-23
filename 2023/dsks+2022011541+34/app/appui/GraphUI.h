#include "CEditorView.h"
#include "CNodeEditorScene.h"
#include "CNodeEditorUIController.h"
#include "CQuickHelpUI.h"
#include "Graph.h"
#include <QWidget>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
class CEditorScene;
constexpr int maxnum = 100;
constexpr int maxint = 999999;

namespace Ui {
class GraphUI;
}

class GraphUI : public QWidget {
  Q_OBJECT
public:
  GraphUI(QWidget *parent = 0);
  ~GraphUI();
  void
  setCNodeEditorUIController(CNodeEditorUIController *nodeEditorUIControlle);
  void setScene(CNodeEditorScene *scene);
  void setCQuickHelpUI(CQuickHelpUI *scene);
  void createGraph(MGraph &g);
  int getPosition(MGraph g, string value);
  void destroyGraph(MGraph &g);
  void NodeChangeColor(QString nodeID);
  void NodeChangeColorWithoutSuspand(QString nodeID);
  void EdgeChangeColor(QString firstNodeID, QString lastNodeID);
  void EdgeChangeColorWithoutSuspand(QString firstNodeID, QString lastNodeID);


  void goToBeginButton();
  void stepBackButton();
  void suspendButton();
  void stepForwardButton();
  void goToEndButton();
  void animationDraw(int totaltime);
  void animationDrawWithoutSuspand(int totaltime);
  void sleepTime(int time);
  void setCEditorView(CEditorView *editorView);
  void animationRecord(int functionid, QString para1, QString para2,
                       int codefunctionid, int codefunctionlineid);
  void animationRecord(int functionid, QString para1, QString para2);
  void animationviewDebug(int currenttime);
  void playButton();

  // leaf node
  void getLeafNode(MGraph g);

private slots:
  void on_leafNode_btn_clicked();
  void on_reset_btn_clicked();

protected:
  void onSceneAttached(CEditorScene *scene);
  void onSceneDetached(CEditorScene *scene);

private:
  Ui::GraphUI *ui;
  CNodeEditorScene *m_scene;
  CEditorView *m_editorView;
  CNodeEditorUIController *m_nodeEditorUIController;
  CNode *m_nodeFactory;
  CEdge *m_edgeFactory;
  bool Mvisited[5000];    //边的最大值
  int follow[50];         //记录 Dijkstra 顺序
  stack<int> mystack;     //拓扑排序
  int indegree[9999];     //拓扑排序
  topoNode topoadj[9999]; //拓扑排序
  CQuickHelpUI *m_quickHelp;
  int history_list_array[1010];
  int history_length = 0;
  Animation animation[200];       //动画 /第几帧/每帧具体步骤
  Animation animationSearch[200]; //动画 /第几帧/每帧具体步骤
  int history_wideSize[200], history_highSize[200];
  int frametime[200];
  int insertIdCode[200];
  int framesearchtime;
  int onlytotaltime = 0;
  int timestamp = 0;         //进度控制时间戳
  int endplaybuttonflag = 0; //停止播放标志位
};