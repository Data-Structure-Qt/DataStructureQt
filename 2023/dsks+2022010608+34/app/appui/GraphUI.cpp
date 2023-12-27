#include "GraphUI.h"
#include "ui_GraphUI.h"
#include "CNodeEditorScene.h"
#include <CEdge.h>
#include <CNode.h>
#include <CNodeEditorScene.h>
#include <QColor>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QString>
#include <QTextStream>
#include <QTime>
#include "Graph.h"

GraphUI::GraphUI(QWidget *parent)
    : QWidget(parent), ui(new Ui::GraphUI), m_scene(NULL) {
  ui->setupUi(this);
}

void GraphUI::onSceneDetached(CEditorScene *scene) { scene->disconnect(this); }

void GraphUI::setScene(CNodeEditorScene *scene) {
  if (m_scene)
    onSceneDetached(m_scene);
  m_scene = scene;
  setEnabled(m_scene);
  if (m_scene)
    onSceneAttached(m_scene);
}

void GraphUI::setCQuickHelpUI(CQuickHelpUI *scene) {
  m_quickHelp = scene;
  setEnabled(m_quickHelp);
}

void GraphUI::onSceneAttached(CEditorScene *scene) {}

GraphUI::~GraphUI() {}

void GraphUI::setCNodeEditorUIController(

    CNodeEditorUIController *nodeEditorUIController) {
  m_nodeEditorUIController = nodeEditorUIController;
  setEnabled(m_nodeEditorUIController);
}

// 	在 Graph.ui 中预定义好的槽位 on_leafNode_btn_clicked()
//  这个函数定义了点击"获取叶子节点按钮"后的行为
void GraphUI::on_leafNode_btn_clicked() {
  // 将按钮设置成不可点击
  m_nodeEditorUIController->clickButtonDisabled();

  // 在画板中获取所有边和顶点
  QList<CNode *> nodes = m_scene->getItems<CNode>();
  QList<CEdge *> edges = m_scene->getItems<CEdge>();

  // 标记边的属性
  for (auto edge : edges) {
    edge->setLabelText(QString::fromStdString(std::string("")));
    edge->showLabel(true);
    edge->setAttribute("direction", "directed");
  }

  {
    char count = 'A';
    // 标记节点的文字
    for (auto node : nodes) {
      //获取 ID 作为节点标签文字
      //设置文字显示到中央
      node->setSize(70, 70);
      node->setLabelText(QString::fromStdString(std::string(1, count)));
      node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
      node->showLabel(true);
      //显示标签

			count = (count + 1 > 'Z') ? 'A' : count + 1; 
    }
  }

  // 创建图
  MGraph g;
  createGraph(g);

  // 判断图 graph 是否为树
  auto isTree = [](const MGraph &graph) {
    // 统计每个顶点的入度
    std::vector<int> indegreeCount(graph.numVertex, 0);
    for (const auto &vertex : graph.adjointList) {
      CGraphVertexNode *edge = vertex.firstEdage;
      while (edge) {
        // 统计被指向顶点的入度
        indegreeCount[edge->adjointVertex]++;
        edge = edge->next;
      }
    }

    // 统计入度为 0 的顶点数量
    int zeroIndegreeNodeCount = 0;
    for (const int count : indegreeCount) {
      // 任何一个顶点入度不能大于等于 2
      if (count >= 2) {
        return false;
      }
      // 统计入度为0的顶点数量
      zeroIndegreeNodeCount += (count == 0) ? 1 : 0;
    }
    // 入度为 0 的点只能有一个
    return zeroIndegreeNodeCount == 1;
  };

  // 如果不是树，则无法获取叶子节点
  if (!isTree(g)) {
    // 由于当在画板中未选择结点的情况下，无法建立图，因此提示需要至少选中一个节点，然后返回
    if (m_scene->getSelectedNodes().isEmpty()) {
      QMessageBox::warning(
          this, QString::fromLocal8Bit("错误"),
          QString::fromLocal8Bit("请至少在画板中选中一个节点!"),
          QMessageBox::Ok);
      destroyGraph(g);
      m_scene->deselectAll(); // 取消全选
      m_nodeEditorUIController->clickButtonEnabled();
      return;
    }

    // 如果不是因为未选择节点引起，则判定是画板中的图不符合要求，可能有以下两种原因：
    // 1. 不存在树
    // 2. 树有多棵
    QMessageBox::warning(
        this, QString::fromLocal8Bit("错误"),
        QString::fromLocal8Bit(
            "画板中的树有多棵，或者不存在树，无法获取叶子节点"),
        QMessageBox::Ok);
    destroyGraph(g);
    m_scene->deselectAll(); // 取消全选
    m_nodeEditorUIController->clickButtonEnabled();
    return;
  }

  // 获取并标记叶子节点
  getLeafNode(g);
  // 销毁当前图
  destroyGraph(g);
  //取消全选
  m_scene->deselectAll();
  // 将按钮设置为可点击
  m_nodeEditorUIController->clickButtonEnabled();
}

// 获取叶子节点
void GraphUI::getLeafNode(MGraph g) {
  for (const CGraphAdjointList &vertex : g.adjointList) {
    // 如果该节点有孩子节点则跳过
    if (vertex.firstEdage != NULL) {
      continue;
    }
    // 如果没有孩子节点（出度为0），判定为叶子节点，标记为红色
    qDebug() << QString::fromStdString(vertex.data) << " ";
    NodeChangeColor(QString::fromStdString(vertex.data));
  }
}

void GraphUI::on_reset_btn_clicked() {
  QList<CNode *> nodes = m_scene->getItems<CNode>();
  QList<CEdge *> edges = m_scene->getItems<CEdge>();
  qDebug("Node number:%d", nodes.count());
  qDebug("Edges number:%d", edges.count());
  // 标记边的属性
  for (auto edge : edges) {
    edge->setLabelText(QString::fromStdString(std::string("")));
    edge->showLabel(true);
    edge->setAttribute("direction", "directed");
  }

  {
    char count = 'A';
    // 标记节点的文字
    for (auto node : nodes) {
      //获取 ID 作为节点标签文字
      //设置文字显示到中央
      node->setSize(70, 70);
      node->setLabelText(QString::fromStdString(std::string(1, count)));
      node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
      node->showLabel(true);
      //显示标签

      count = (count + 1 > 'Z') ? 'A' : count + 1;
    }
  }
  for (auto node : nodes) {
    node->setAttribute("color", "#3399ff");
  }
  for (auto edge : edges) {
    edge->setAttribute("color", "#a0a0a4");
  }
}

void GraphUI::createGraph(MGraph &g) {
  QList<CNode *> nodes = m_scene->getItems<CNode>();
  QList<CEdge *> edges = m_scene->getItems<CEdge>();
  g.numVertex = nodes.count(); //传入点数量
  g.numEdge = edges.count();   //传入边数量
  int nodei = 0;               //计数器
  QList<CNode *> selectedNodes = m_scene->getSelectedNodes();
  if (selectedNodes.isEmpty() == false) {
    g.adjointList[nodei].data = selectedNodes.at(0)->getId().toStdString();
    g.adjointList[nodei].firstEdage = NULL;
    nodei++;
  } else //未选择节点就返回
  {
    return;
  }
  for (auto node : nodes) //其余进入数组
  {
    if (node->getId().toStdString() !=
        selectedNodes.at(0)->getId().toStdString()) {
      g.adjointList[nodei].data = node->getId().toStdString();
      g.adjointList[nodei].firstEdage = NULL;
      nodei++;
    }
  }
  int pos1, pos2;
  string data1, data2;
  CGraphVertexNode *node;
  CGraphVertexNode *temp;
  for (auto edge : edges) {
    data1 = edge->firstNode()->getId().toStdString();
    data2 = edge->lastNode()->getId().toStdString();
    pos1 = getPosition(g, data1);
    pos2 = getPosition(g, data2);
    if (g.adjointList[pos1].firstEdage == NULL) {
      node = new CGraphVertexNode(pos2, NULL);
      g.adjointList[pos1].firstEdage = node;
    } else {
      temp = g.adjointList[pos1].firstEdage;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      node = new CGraphVertexNode(pos2, NULL);
      temp->next = node;
    }
  }
}

int GraphUI::getPosition(MGraph g, string value) {
  for (int i = 0; i < g.numVertex; i++) {
    if (g.adjointList[i].data == value) {
      return i;
    }
  }
  return -1;
}

//void GraphUI::on_bfs_btn_clicked()
//{
//	m_nodeEditorUIController->clickButtonDisabled();
//	QList<CNode*> nodes = m_scene->getItems<CNode>();
//	QList<CEdge*> edges = m_scene->getItems<CEdge>();
//	for (auto edge : edges)
//	{
//		qDebug() << "frist node: " + edge->firstNode()->getId() + "last node: " +
//			edge->lastNode()->getId();
//		edge->setLabelText(edge->getId());
//		edge->showLabel(true);
//		edge->setAttribute("direction", "directed");
//	}
//	for (auto node : nodes)
//	{
//		qDebug() << " node: " + node->getId();
//		//获取 ID 作为节点标签文字
//		//设置文字显示到中央
//		node->setSize(70, 70);
//		node->setLabelText(node->getId());
//		node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
//		node->showLabel(true);
//		//显示标签
//	}
//	onlytotaltime = 0;
//	MGraph g;
//	createGraph(g);
//	//print(g);
//	qDebug() << "*********** BFSTraverse *************";
//	BFSTraverse(g);
//	qDebug() << "*********** destroyGraph *************";
//	destroyGraph(g);
//	m_scene->deselectAll();//取消全选
//	for (int i = 1; i <= onlytotaltime; i++)
//	{
//		animationview(i);
//	}
//	m_nodeEditorUIController->clickButtonEnabled();
//}
//
//void GraphUI::on_dfs_btn_clicked()
//{
//	m_nodeEditorUIController->clickButtonDisabled();
//	//获取屏幕目前的边和点
//	QList<CNode*> nodes = m_scene->getItems<CNode>();
//	QList<CEdge*> edges = m_scene->getItems<CEdge>();
//	for (auto edge : edges)//显示边标签
//	{
//		edge->setLabelText(edge->getId());
//		edge->showLabel(true);
//		edge->setAttribute("direction", "directed");
//	}
//	for (auto node : nodes)//显示节点标签
//	{
//		node->setSize(70, 70);
//		node->setLabelText(node->getId());
//		node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
//		node->showLabel(true);//显示标签
//	}
//	onlytotaltime = 0;
//	MGraph g; //新建图
//	createGraph(g); //依据屏幕边与节点创建图
//	DFSTraverse(g); //深度优先遍历图
//	destroyGraph(g); //销毁图
//	m_scene->deselectAll();//取消节点全选
//	m_nodeEditorUIController->clickButtonEnabled();
//}
//
//void GraphUI::BFSTraverse(MGraph g) {
//	CGraphVertexNode *node;
//	queue<int> bfsQueue;
//	vector<bool> Mvisited(g.numVertex);
//	for (int i = 0; i < g.numVertex; i++) {
//		Mvisited[i] = false;
//	}
//	for (int i = 0; i < g.numVertex; i++) {
//		if (!Mvisited[i]) {
//			Mvisited[i] = true;
//			qDebug() << QString::fromStdString(g.adjointList[i].data) << " ";
//			//节点改变颜色
//			NodeChangeColor(QString::fromStdString(g.adjointList[i].data));
//			animationRecord(1,
//				QString::fromStdString(g.adjointList[i].data), NULL);
//			bfsQueue.push(i);
//			while (!bfsQueue.empty()) {
//				int queueValue;
//				queueValue = bfsQueue.front();
//				bfsQueue.pop();
//				node = g.adjointList[queueValue].firstEdage;
//				while (node) {
//					if (!Mvisited[node->adjointVertex]) {
//						Mvisited[node->adjointVertex] = true;
//						bfsQueue.push(node->adjointVertex);
//						EdgeChangeColor(QString::fromStdString(g.adjointList[queueValue].data),
//							QString::fromStdString(g.adjointList[node->adjointVertex].data));
//						animationRecord(2, QString::fromStdString(g.adjointList[queueValue].data),
//							QString::fromStdString(g.adjointList[node->adjointVertex].data));
//						NodeChangeColor(QString::fromStdString(g.adjointList[node->adjointVertex
//						].data));
//						animationRecord(1,
//							QString::fromStdString(g.adjointList[node->adjointVertex].data), NULL);
//						qDebug() <<
//							QString::fromStdString(g.adjointList[node->adjointVertex].data) << " ";
//					}
//					node = node->next;
//				}
//			}
//		}
//	}
//}

//改变节点的颜色

void GraphUI::NodeChangeColor(QString nodeID) {
  QList<CNode *> nodes = m_scene->getItems<CNode>();
  for (auto node : nodes) {
    if (node->getId() == nodeID) {
      for (int i = 0; i < 2; i++) //闪烁
      {
        node->setAttribute("color", "#3399ff");
        QTime time;
        time.start();
        while (time.elapsed() < 300)
          continue;                        //等待时间
        QCoreApplication::processEvents(); //处理事件
        node->setAttribute("color", "#FF0000");
        time.start();
        while (time.elapsed() < 300)
          continue;                        //等待时间
        QCoreApplication::processEvents(); //处理事件
      }
    }
  }
}

void GraphUI::NodeChangeColorWithoutSuspand(QString nodeID) {
  QList<CNode *> nodes = m_scene->getItems<CNode>();
  for (auto m_node : nodes) {
    if (m_node->getId() == nodeID) {
      m_node->setAttribute("color", "#FF0000");
    }
  }
}

//改变线段的颜色

void GraphUI::EdgeChangeColor(QString firstNodeID, QString lastNodeID) {
  QList<CEdge *> edges = m_scene->getItems<CEdge>();
  for (auto edge : edges) { //前后节点连接的边
    if (QString(edge->firstNode()->getId()) == firstNodeID &&
        QString(edge->lastNode()->getId()) == lastNodeID) {
      for (int i = 0; i < 2; i++) //闪烁
      {
        edge->setAttribute("color", "#a0a0a4");
        QTime time;
        time.start();
        while (time.elapsed() < 300)
          ;                                //等待时间
        QCoreApplication::processEvents(); //处理事件
        edge->setAttribute("color", "#FF0000");
        time.start();
        while (time.elapsed() < 300)
          ;                                //等待时间
        QCoreApplication::processEvents(); //处理事件
      }
    }
  }
}

//改变线段的颜色

void GraphUI::EdgeChangeColorWithoutSuspand(QString firstNodeID,
                                            QString lastNodeID) {
  QList<CEdge *> edges = m_scene->getItems<CEdge>();
  for (auto m_edge : edges) { //前后节点连接的边
    if (QString(m_edge->firstNode()->getId()) == firstNodeID &&
        QString(m_edge->lastNode()->getId()) == lastNodeID) {
      m_edge->setAttribute("color", "#FF0000");
    }
  }
}

void GraphUI::destroyGraph(MGraph &g) {
  CGraphVertexNode *temp = NULL;
  for (int i = 0; i < g.numVertex; i++) {
    temp = g.adjointList[i].firstEdage;
    while (temp) {
      CGraphVertexNode *node = temp;
      temp = temp->next;
      delete node;
    }
    g.adjointList[i].firstEdage = NULL;
  }
}

//void GraphUI::DFSTraverse(MGraph g) {
//	//节点初始化 未访问
//	for (int i = 0; i < g.numVertex; i++) {
//		Mvisited[i] = false;
//	}
//	//对未访问的节点进行遍历
//	for (int i = 0; i < g.numVertex; i++) {
//		if (!Mvisited[i]) {
//			DFS(g, i);
//		}
//		else {
//			m_quickHelp->dfs_code(3);
//			animationRecord(NULL, NULL, NULL, 1, 3);
//		}
//	}
//}
//
//void GraphUI::on_dijkstra_btn_clicked()
//{
//	m_nodeEditorUIController->clickButtonDisabled();
//	// 数组都从下标 1 开始
//	int dist[maxnum]; // 当前点到源点的最短路径长度
//	int prev[maxnum]; //当前点的前一个结点
//	int c[maxnum][maxnum]; // 记录图的两点间路径长度
//	int n, line; // 定义图的结点数和路径数
//	QList<CNode*> nodes = m_scene->getItems<CNode>();
//	QList<CEdge*> edges = m_scene->getItems<CEdge>();
//	for (auto edge : edges)//显示边标签
//	{
//		edge->setLabelText(edge->getId());
//		edge->showLabel(true);
//		edge->setAttribute("direction", "directed");
//	}
//	for (auto node : nodes)//显示点标签
//	{
//		node->setSize(70, 70);
//		node->setLabelText(node->getId());
//		node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
//		node->showLabel(true);
//	}
//	onlytotaltime = 0;
//	n = nodes.count();//传入节点数量
//	line = edges.count();//传入边的数量
//	int p, q, len; // 输入 p, q 两点及其路径长度
//	for (int i = 1; i <= n; ++i)
//		for (int j = 1; j <= n; ++j)
//			c[i][j] = maxint;
//	for (auto edge : edges)
//	{
//		QByteArray u_byte = edge->firstNode()->getId().toUtf8();
//		p = int(u_byte.at(0)) - 64;
//		QByteArray v_byte = edge->lastNode()->getId().toUtf8();
//		q = int(v_byte.at(0)) - 64;
//		len = edge->getId().toInt();
//		if (len < c[p][q]) // 有重边
//		{
//			c[p][q] = len; // p 指向 q
//			c[q][p] = len; // q 指向 p
//		}
//	}
//	for (int i = 1; i <= n; ++i)
//		dist[i] = maxint;
//	MDijkstra(n, 1, dist, prev, c);
//	for (int i = 2; i <= n; i++)//暂时只能从标记为 A 的节点开始
//	{
//		searchPath(prev, 1, follow[i]);
//	}
//	m_nodeEditorUIController->clickButtonEnabled();
//}
//void GraphUI::MDijkstra(int n, int v, int *dist, int *prev, int
//	c[maxnum][maxnum])
//{
//	bool s[maxnum]; // 判断是否在集合中
//	for (int i = 1; i <= n; ++i)
//	{
//		dist[i] = c[v][i];
//		s[i] = 0; // 初始未使用点
//		if (dist[i] == maxint)
//			prev[i] = 0;
//		else
//			prev[i] = v;
//	}
//	dist[v] = 0;// 记录从源点到其他顶点最短路径长度
//	s[v] = 1;
//	for (int i = 2; i <= n; ++i)// 取最小值结点，放入集合
//	{
//		int tmp = maxint;
//		int u = v;
//		// 找出当前距离最近的未使用点
//		for (int j = 1; j <= n; ++j)
//			if ((!s[j]) && dist[j] < tmp)
//			{
//				u = j; // u 保存当前邻接点中距离最小的点
//				tmp = dist[j];
//			}
//		s[u] = 1; // 表示 u 点已存入集合中
//		follow[i] = u;
//		for (int j = 1; j <= n; ++j)
//			if ((!s[j]) && c[u][j] < maxint) {
//				int newdist = dist[u] + c[u][j];
//				if (newdist < dist[j]) {
//					dist[j] = newdist;
//					prev[j] = u;
//				}
//			}
//	}
//}

void GraphUI::goToBeginButton() {
  on_reset_btn_clicked();
  endplaybuttonflag = 1;
  timestamp = 1;
  animationDraw(timestamp);
  /*m_quickHelp->btree_insert_code(insertIdCode[timestamp]);*/
}

void GraphUI::stepBackButton() {
  endplaybuttonflag = 1;
  on_reset_btn_clicked();
  if (timestamp > 1) {
    timestamp--;
    for (int i = 1; i < timestamp; i++) {
      animationDrawWithoutSuspand(i);
    }
    // m_scene->clearScreen();//清屏
    animationDraw(timestamp);
    // m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
  }
}

void GraphUI::playButton() {
  endplaybuttonflag = 0;
  for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1;
       timestamp++) {
    // m_scene->clearScreen();//清屏
    animationDraw(timestamp);
    // m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
    // sleepTime(500);
  }
}

void GraphUI::suspendButton() { endplaybuttonflag = 1; }

void GraphUI::stepForwardButton() {
  endplaybuttonflag = 1;
  if (timestamp < onlytotaltime) {
    timestamp++;
    // m_scene->clearScreen();//清屏
    animationDraw(timestamp);
    // m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
  }
}

void GraphUI::goToEndButton() {
  endplaybuttonflag = 1;
  // m_scene->clearScreen();//清屏
  for (timestamp; timestamp <= onlytotaltime; timestamp++) {
    animationDrawWithoutSuspand(timestamp);
  }
  // m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
}

void GraphUI::animationDraw(int totaltime) {
  if (animation[totaltime].functionid == 1) {
    NodeChangeColor(animation[totaltime].para1);
  } else if (animation[totaltime].functionid == 2) {
    EdgeChangeColor(animation[totaltime].para1, animation[totaltime].para2);
  }
  // dfs 代码
  if (animation[totaltime].codefunctionid == 1) {
    m_quickHelp->dfs_code(animation[totaltime].codefunctionlineid);
  }
}

void GraphUI::animationDrawWithoutSuspand(int totaltime) {
  if (animation[totaltime].functionid == 1) {
    NodeChangeColorWithoutSuspand(animation[totaltime].para1);
  } else if (animation[totaltime].functionid == 2) {
    EdgeChangeColorWithoutSuspand(animation[totaltime].para1,
                                  animation[totaltime].para2);
  }
  // dfs 代码
  if (animation[totaltime].codefunctionid == 1) {
    m_quickHelp->dfs_code(animation[totaltime].codefunctionlineid);
  }
}

void GraphUI::sleepTime(int time) {
  QTime dieTime = QTime::currentTime().addMSecs(time); //获取自定义休眠时间
  while (QTime::currentTime() < dieTime) {
    QCoreApplication::processEvents(QEventLoop::AllEvents,
                                    100); // 开启新线程，处理 qt 界面事件
  }
}

void GraphUI::setCEditorView(CEditorView *editorView) {
  m_editorView = editorView;
  setEnabled(m_editorView);
}

// totaltime 总运行时间 functionid 1 节点，2 边

void GraphUI::animationRecord(int functionid, QString para1, QString para2,
                              int codefunctionid, int codefunctionlineid) {
  onlytotaltime++;
  int totaltime = onlytotaltime;
  animation[totaltime].totaltime = totaltime;
  animation[totaltime].functionid = functionid;
  animation[totaltime].para1 = para1;
  animation[totaltime].para2 = para2;
  animation[totaltime].codefunctionid = codefunctionid;
  animation[totaltime].codefunctionlineid = codefunctionlineid;
}

void GraphUI::animationRecord(int functionid, QString para1, QString para2) {
  onlytotaltime++;
  int totaltime = onlytotaltime;
  animation[totaltime].totaltime = totaltime;
  animation[totaltime].functionid = functionid;
  animation[totaltime].para1 = para1;
  animation[totaltime].para2 = para2;
  animation[totaltime].codefunctionid = NULL;
  animation[totaltime].codefunctionlineid = NULL;
}

void GraphUI::animationviewDebug(int currenttime) {
  qDebug() << "animation[currenttime].totaltime"
           << animation[currenttime].totaltime;
  qDebug() << "animation[currenttime].functionid"
           << animation[currenttime].functionid;
  qDebug() << "animation[currenttime].para1" << animation[currenttime].para1;
  qDebug() << "animation[currenttime].para2" << animation[currenttime].para2;
}