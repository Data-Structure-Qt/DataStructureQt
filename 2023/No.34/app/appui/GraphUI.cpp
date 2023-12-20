#include "GraphUI.h"
#include "CNodeEditorScene.h"
#include "Graph.h"
#include "ui_GraphUI.h"
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
    edge->setLabelText(edge->getId());
    edge->showLabel(true);
    edge->setAttribute("direction", "directed");
  }

  // 标记节点的文字
  for (auto node : nodes) {
    //获取 ID 作为节点标签文字
    //设置文字显示到中央
    node->setSize(70, 70);
    node->setLabelText(node->getId());
    node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
    node->showLabel(true);
    //显示标签
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
  for (auto edge : edges) {
    qDebug() << "frist node: " + edge->firstNode()->getId() +
                    "last node: " + edge->lastNode()->getId();
    edge->setLabelText(edge->getId());
    edge->showLabel(true);
    //显示标签
    // edge->setAttribute("direction", "directed");
  }
  for (auto node : nodes) {
    qDebug() << " node: " + node->getId();
    //获取 ID 作文节点标签文字
    //设置文字显示到中央
    node->setSize(70, 70);
    node->setLabelText(node->getId());
    node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
    node->showLabel(true);
    //显示标签
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
