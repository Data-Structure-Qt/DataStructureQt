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

// 	�� Graph.ui ��Ԥ����õĲ�λ on_leafNode_btn_clicked()
//  ������������˵��"��ȡҶ�ӽڵ㰴ť"�����Ϊ
void GraphUI::on_leafNode_btn_clicked() {
  // ����ť���óɲ��ɵ��
  m_nodeEditorUIController->clickButtonDisabled();

  // �ڻ����л�ȡ���бߺͶ���
  QList<CNode *> nodes = m_scene->getItems<CNode>();
  QList<CEdge *> edges = m_scene->getItems<CEdge>();

  // ��Ǳߵ�����
  for (auto edge : edges) {
    edge->setLabelText(edge->getId());
    edge->showLabel(true);
    edge->setAttribute("direction", "directed");
  }

  // ��ǽڵ������
  for (auto node : nodes) {
    //��ȡ ID ��Ϊ�ڵ��ǩ����
    //����������ʾ������
    node->setSize(70, 70);
    node->setLabelText(node->getId());
    node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
    node->showLabel(true);
    //��ʾ��ǩ
  }

  // ����ͼ
  MGraph g;
  createGraph(g);

  // �ж�ͼ graph �Ƿ�Ϊ��
  auto isTree = [](const MGraph &graph) {
    // ͳ��ÿ����������
    std::vector<int> indegreeCount(graph.numVertex, 0);
    for (const auto &vertex : graph.adjointList) {
      CGraphVertexNode *edge = vertex.firstEdage;
      while (edge) {
        // ͳ�Ʊ�ָ�򶥵�����
        indegreeCount[edge->adjointVertex]++;
        edge = edge->next;
      }
    }

    // ͳ�����Ϊ 0 �Ķ�������
    int zeroIndegreeNodeCount = 0;
    for (const int count : indegreeCount) {
      // �κ�һ��������Ȳ��ܴ��ڵ��� 2
      if (count >= 2) {
        return false;
      }
      // ͳ�����Ϊ0�Ķ�������
      zeroIndegreeNodeCount += (count == 0) ? 1 : 0;
    }
    // ���Ϊ 0 �ĵ�ֻ����һ��
    return zeroIndegreeNodeCount == 1;
  };

  // ��������������޷���ȡҶ�ӽڵ�
  if (!isTree(g)) {
    // ���ڵ��ڻ�����δѡ���������£��޷�����ͼ�������ʾ��Ҫ����ѡ��һ���ڵ㣬Ȼ�󷵻�
    if (m_scene->getSelectedNodes().isEmpty()) {
      QMessageBox::warning(
          this, QString::fromLocal8Bit("����"),
          QString::fromLocal8Bit("�������ڻ�����ѡ��һ���ڵ�!"),
          QMessageBox::Ok);
      destroyGraph(g);
      m_scene->deselectAll(); // ȡ��ȫѡ
      m_nodeEditorUIController->clickButtonEnabled();
      return;
    }

    // ���������Ϊδѡ��ڵ��������ж��ǻ����е�ͼ������Ҫ�󣬿�������������ԭ��
    // 1. ��������
    // 2. ���ж��
    QMessageBox::warning(
        this, QString::fromLocal8Bit("����"),
        QString::fromLocal8Bit(
            "�����е����ж�ã����߲����������޷���ȡҶ�ӽڵ�"),
        QMessageBox::Ok);
    destroyGraph(g);
    m_scene->deselectAll(); // ȡ��ȫѡ
    m_nodeEditorUIController->clickButtonEnabled();
    return;
  }

  // ��ȡ�����Ҷ�ӽڵ�
  getLeafNode(g);
  // ���ٵ�ǰͼ
  destroyGraph(g);
  //ȡ��ȫѡ
  m_scene->deselectAll();
  // ����ť����Ϊ�ɵ��
  m_nodeEditorUIController->clickButtonEnabled();
}

// ��ȡҶ�ӽڵ�
void GraphUI::getLeafNode(MGraph g) {
  for (const CGraphAdjointList &vertex : g.adjointList) {
		// ����ýڵ��к��ӽڵ�������
    if (vertex.firstEdage != NULL) {
      continue;
    }
		// ���û�к��ӽڵ㣨����Ϊ0�����ж�ΪҶ�ӽڵ㣬���Ϊ��ɫ
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
    //��ʾ��ǩ
    // edge->setAttribute("direction", "directed");
  }
  for (auto node : nodes) {
    qDebug() << " node: " + node->getId();
    //��ȡ ID ���Ľڵ��ǩ����
    //����������ʾ������
    node->setSize(70, 70);
    node->setLabelText(node->getId());
    node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
    node->showLabel(true);
    //��ʾ��ǩ
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
  g.numVertex = nodes.count(); //���������
  g.numEdge = edges.count();   //���������
  int nodei = 0;               //������
  QList<CNode *> selectedNodes = m_scene->getSelectedNodes();
  if (selectedNodes.isEmpty() == false) {
    g.adjointList[nodei].data = selectedNodes.at(0)->getId().toStdString();
    g.adjointList[nodei].firstEdage = NULL;
    nodei++;
  } else //δѡ��ڵ�ͷ���
  {
    return;
  }
  for (auto node : nodes) //�����������
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

//�ı�ڵ����ɫ

void GraphUI::NodeChangeColor(QString nodeID) {
  QList<CNode *> nodes = m_scene->getItems<CNode>();
  for (auto node : nodes) {
    if (node->getId() == nodeID) {
      for (int i = 0; i < 2; i++) //��˸
      {
        node->setAttribute("color", "#3399ff");
        QTime time;
        time.start();
        while (time.elapsed() < 300)
          continue;                        //�ȴ�ʱ��
        QCoreApplication::processEvents(); //�����¼�
        node->setAttribute("color", "#FF0000");
        time.start();
        while (time.elapsed() < 300)
          continue;                        //�ȴ�ʱ��
        QCoreApplication::processEvents(); //�����¼�
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

//�ı��߶ε���ɫ

void GraphUI::EdgeChangeColor(QString firstNodeID, QString lastNodeID) {
  QList<CEdge *> edges = m_scene->getItems<CEdge>();
  for (auto edge : edges) { //ǰ��ڵ����ӵı�
    if (QString(edge->firstNode()->getId()) == firstNodeID &&
        QString(edge->lastNode()->getId()) == lastNodeID) {
      for (int i = 0; i < 2; i++) //��˸
      {
        edge->setAttribute("color", "#a0a0a4");
        QTime time;
        time.start();
        while (time.elapsed() < 300)
          ;                                //�ȴ�ʱ��
        QCoreApplication::processEvents(); //�����¼�
        edge->setAttribute("color", "#FF0000");
        time.start();
        while (time.elapsed() < 300)
          ;                                //�ȴ�ʱ��
        QCoreApplication::processEvents(); //�����¼�
      }
    }
  }
}

//�ı��߶ε���ɫ

void GraphUI::EdgeChangeColorWithoutSuspand(QString firstNodeID,
                                            QString lastNodeID) {
  QList<CEdge *> edges = m_scene->getItems<CEdge>();
  for (auto m_edge : edges) { //ǰ��ڵ����ӵı�
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
    // m_scene->clearScreen();//����
    animationDraw(timestamp);
    // m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
  }
}

void GraphUI::playButton() {
  endplaybuttonflag = 0;
  for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1;
       timestamp++) {
    // m_scene->clearScreen();//����
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
    // m_scene->clearScreen();//����
    animationDraw(timestamp);
    // m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
  }
}

void GraphUI::goToEndButton() {
  endplaybuttonflag = 1;
  // m_scene->clearScreen();//����
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
  // dfs ����
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
  // dfs ����
  if (animation[totaltime].codefunctionid == 1) {
    m_quickHelp->dfs_code(animation[totaltime].codefunctionlineid);
  }
}

void GraphUI::sleepTime(int time) {
  QTime dieTime = QTime::currentTime().addMSecs(time); //��ȡ�Զ�������ʱ��
  while (QTime::currentTime() < dieTime) {
    QCoreApplication::processEvents(QEventLoop::AllEvents,
                                    100); // �������̣߳����� qt �����¼�
  }
}

void GraphUI::setCEditorView(CEditorView *editorView) {
  m_editorView = editorView;
  setEnabled(m_editorView);
}

// totaltime ������ʱ�� functionid 1 �ڵ㣬2 ��

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
