#include "GraphUI.h"
#include "ui_GraphUI.h"
#include "CNodeEditorScene.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <CNodeEditorScene.h>
#include <CEdge.h>
#include <CNode.h>
#include <QString>
#include <QDebug>
#include <QColor>
#include <QTime>
#include <QTextCodec>

GraphUI::GraphUI(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::GraphUI),
	m_scene(NULL)
{
	ui->setupUi(this);
}
void GraphUI::onSceneDetached(CEditorScene* scene) {
	scene->disconnect(this);
}
void GraphUI::setScene(CNodeEditorScene* scene) {
	if (m_scene)
		onSceneDetached(m_scene);
	m_scene = scene;
	setEnabled(m_scene);
	if (m_scene)
		onSceneAttached(m_scene);
}
void GraphUI::setCQuickHelpUI(CQuickHelpUI * scene)
{
	m_quickHelp = scene;
	setEnabled(m_quickHelp);
}
void GraphUI::onSceneAttached(CEditorScene* scene) {}
GraphUI::~GraphUI() {}
void GraphUI::setCNodeEditorUIController(CNodeEditorUIController*
	nodeEditorUIController)
{
	m_nodeEditorUIController = nodeEditorUIController;
	setEnabled(m_nodeEditorUIController);
}
void GraphUI::on_leveltraversal_btn_clicked()
{
	m_nodeEditorUIController->clickButtonDisabled();
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	for (auto edge : edges)
	{
		qDebug() << "frist node: " + edge->firstNode()->getId() + "last node: " +
			edge->lastNode()->getId();
		edge->setLabelText(edge->getId());
		edge->setAttribute("direction", "directed");
	}
	for (auto node : nodes)
	{
		//��ȡ ID ��Ϊ�ڵ��ǩ����
		//����������ʾ������
		node->setSize(70, 70);
		node->setLabelText(node->getId());
		node->setLabelPosition(node->x() / 4096 - 5, node->y() / 4096 - 10);
		node->showLabel(true);
		//��ʾ��ǩ
	}
	onlytotaltime = 0;
	MGraph g;
	createGraph(g);
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
			// ͳ�����Ϊ 0 �Ķ�������
			zeroIndegreeNodeCount += (count == 0) ? 1 : 0;
		}
		// ���Ϊ 0 �ĵ�ֻ����һ��
		return zeroIndegreeNodeCount == 1;
	};
	// ��������������޷����в��������
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
			QMessageBox::warning(
				this, QString::fromLocal8Bit("����"),
				QString::fromLocal8Bit(
					"�����в���������"),
				QMessageBox::Ok);
			destroyGraph(g);
			m_scene->deselectAll(); // ȡ��ȫѡ
			m_nodeEditorUIController->clickButtonEnabled();
			return;
	}
	//print(g);
	qDebug() << "*********** BFSTraverse *************";
	levelTraverse(g);
	qDebug() << "*********** destroyGraph *************";
	destroyGraph(g);
	m_scene->deselectAll();//ȡ��ȫѡ
	for (int i = 1; i <= onlytotaltime; i++)
	{
		animationview(i);
	}
	m_nodeEditorUIController->clickButtonEnabled();
}
void GraphUI::on_reset_btn_clicked()
{
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	qDebug("Node number:%d", nodes.count());
	qDebug("Edges number:%d", edges.count());
	for (auto edge : edges)
	{
		qDebug() << "frist node: " + edge->firstNode()->getId() + "last node: " +
			edge->lastNode()->getId();
		edge->setLabelText(edge->getId());;
		//��ʾ��ǩ
		//edge->setAttribute("direction", "directed");
	}
	for (auto node : nodes)
	{
		//��ȡ ID ���Ľڵ��ǩ����
		//����������ʾ������
		node->setSize(70, 70);
		node->setLabelText(node->getId());
		node->setLabelPosition(node->x() / 4096 - 5, node->y() / 4096 - 10);
		node->showLabel(true);
		//��ʾ��ǩ
	}
	for (auto node : nodes)
	{
		node->setAttribute("color", "#3399ff");
	}
	for (auto edge : edges)
	{
		edge->setAttribute("color", "#a0a0a4");
	}
}
void GraphUI::createGraph(MGraph &g) {
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	g.numVertex = nodes.count(); //���������
	g.numEdge = edges.count(); //���������
	int nodei = 0; //������
	QList<CNode*> selectedNodes = m_scene->getSelectedNodes();
	if (selectedNodes.isEmpty() == false) {
		g.adjointList[nodei].data = selectedNodes.at(0)->getId().toStdString();
		g.adjointList[nodei].firstEdage = NULL;
		nodei++;
	}
	else //δѡ��ڵ�ͷ���
	{
		return;
	}
	for (auto node : nodes)//�����������
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
	for (auto edge : edges)
	{
		data1 = edge->firstNode()->getId().toStdString();
		data2 = edge->lastNode()->getId().toStdString();
		pos1 = getPosition(g, data1);
		pos2 = getPosition(g, data2);
		if (g.adjointList[pos1].firstEdage == NULL) {
			node = new CGraphVertexNode(pos2, NULL);
			g.adjointList[pos1].firstEdage = node;
		}
		else {
			temp = g.adjointList[pos1].firstEdage;
			while (temp->next != NULL) {
				temp = temp->next; 
			}
			node = new CGraphVertexNode(pos2, NULL);
			temp->next = node;
		}
	}
}
int GraphUI::getPosition(MGraph g, string value)
{
	for (int i = 0; i < g.numVertex; i++) {
		if (g.adjointList[i].data == value) {
			return i;
		}
	}
	return -1;
}


void GraphUI::levelTraverse(MGraph g) {
	CGraphVertexNode *node;  // ����ͼ�ڵ�ָ�����
	queue<int> bfsQueue;  // ����洢�ڵ������Ķ���
	vector<bool> Mvisited(g.numVertex);  // �����������������ڼ�¼�ڵ��Ƿ񱻷��ʹ�
	vector<QString> visitedLabels;  // ��¼���ʹ��Ľڵ��ǩ�Ķ���

	for (int i = 0; i < g.numVertex; i++) {  // ��ʼ��Mvisited����Ϊfalse
		Mvisited[i] = false;
	}

	for (int i = 0; i < g.numVertex; i++) {  // ����ͼ�е�ÿ���ڵ�
		if (!Mvisited[i]) {  // ���ýڵ�δ�����ʹ�
			Mvisited[i] = true;  // ��ǽڵ�Ϊ�ѷ���
			visitedLabels.push_back(QString::fromStdString(g.adjointList[i].data));  // ��¼���ʹ��Ľڵ��ǩ
			qDebug() << QString::fromStdString(g.adjointList[i].data) << " ";  // ��ӡ�ڵ��ǩ
			NodeChangeColor(QString::fromStdString(g.adjointList[i].data));  // �ı�ڵ���ɫ
			animationRecord(1, QString::fromStdString(g.adjointList[i].data), NULL);  // ��¼����
			m_quickHelp->level_code(1);
			bfsQueue.push(i);  // ���ڵ����
			while (!bfsQueue.empty()) {  // �����зǿ�ʱ��ִ�����²���
				int queueValue;  // �������ͷ���Ľڵ�����
				queueValue = bfsQueue.front();  // ȡ�����׵�ֵ
				bfsQueue.pop();  // ����Ԫ�س���
				node = g.adjointList[queueValue].firstEdage;  // ��ȡ���׽ڵ���ڽӽڵ�
				while (node) {  // �������׽ڵ���ڽӽڵ�
					if (!Mvisited[node->adjointVertex]) {  // ���ڽӽڵ�δ�����ʹ�
						Mvisited[node->adjointVertex] = true;  // ����ڽӽڵ�Ϊ�ѷ���
						visitedLabels.push_back(QString::fromStdString(g.adjointList[node->adjointVertex].data));  // ��¼���ʹ��Ľڵ��ǩ
						m_quickHelp->level_code(2);
						bfsQueue.push(node->adjointVertex);  // ���ڽӽڵ����
						EdgeChangeColor(QString::fromStdString(g.adjointList[queueValue].data),  // �ı����ɫ
							QString::fromStdString(g.adjointList[node->adjointVertex].data));
						animationRecord(2,  // ��¼����
							QString::fromStdString(g.adjointList[queueValue].data),
							QString::fromStdString(g.adjointList[node->adjointVertex].data));
						m_quickHelp->level_code(3);
						NodeChangeColor(QString::fromStdString(g.adjointList[node->adjointVertex].data));  // �ı�ڵ���ɫ
						animationRecord(1,  // ��¼����
							QString::fromStdString(g.adjointList[node->adjointVertex].data), NULL);
						qDebug() <<  // ��ӡ�ڵ��ǩ
							QString::fromStdString(g.adjointList[node->adjointVertex].data) << " ";
					}
					node = node->next;  // ������һ���ڽӽڵ�
				}
			}
		}
	}

	// ʹ��QMessageBox������ʹ��Ľڵ��ǩ
	QString visitedNodeLabelString = QString::fromLocal8Bit("����������Ϊ: ");
	for (const QString& label : visitedLabels) {
		visitedNodeLabelString += label + " ";
	}
	QMessageBox::information(this, QString::fromLocal8Bit("���"), visitedNodeLabelString);
}
//�ı�ڵ����ɫ
void GraphUI::NodeChangeColor(QString nodeID)
{
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	for (auto node : nodes) {
		if (node->getId() == nodeID) {
			for (int i = 0; i < 2; i++)//��˸
			{
				node->setAttribute("color", "#3399ff");
				QTime time;
				time.start();
				while (time.elapsed() < 300); //�ȴ�ʱ��
				QCoreApplication::processEvents(); //�����¼�
				node->setAttribute("color", "#FF0000");
				time.start();
				while (time.elapsed() < 300); //�ȴ�ʱ��
				QCoreApplication::processEvents(); //�����¼�
			}
		}
	}
}
void GraphUI::NodeChangeColorWithoutSuspand(QString nodeID)
{
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	for (auto m_node : nodes) {
		if (m_node->getId() == nodeID) {
			m_node->setAttribute("color", "#FF0000");
		}
	}
}
//�ı��߶ε���ɫ
void GraphUI::EdgeChangeColor(QString firstNodeID, QString
	lastNodeID)
{
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	for (auto edge : edges)
	{//ǰ��ڵ����ӵı�
		if (QString(edge->firstNode()->getId()) == firstNodeID &&
			QString(edge->lastNode()->getId()) == lastNodeID)
		{
			for (int i = 0; i < 2; i++)//��˸
			{
				edge->setAttribute("color", "#a0a0a4");
				QTime time;
				time.start();
				while (time.elapsed() < 300); //�ȴ�ʱ��
				QCoreApplication::processEvents(); //�����¼�
				edge->setAttribute("color", "#FF0000");
				time.start();
				while (time.elapsed() < 300); //�ȴ�ʱ��
				QCoreApplication::processEvents(); //�����¼�
			}
		}
	}
}
//�ı��߶ε���ɫ
void GraphUI::EdgeChangeColorWithoutSuspand(QString firstNodeID,
	QString
	lastNodeID)
{
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	for (auto m_edge : edges)
	{//ǰ��ڵ����ӵı�
		if (QString(m_edge->firstNode()->getId()) == firstNodeID &&
			QString(m_edge->lastNode()->getId()) == lastNodeID)
		{
			m_edge->setAttribute("color", "#FF0000");
		}
	}
}
void GraphUI::DFS(MGraph g, int index) {
	CGraphVertexNode *node;
	Mvisited[index] = true;
	//����ڵ�
	qDebug() << QString::fromStdString(g.adjointList[index].data);
	NodeChangeColor(QString::fromStdString(g.adjointList[index].data));
	animationRecord(1, QString::fromStdString(g.adjointList[index].data),
		NULL);
	node = g.adjointList[index].firstEdage;
	while (node) {
		m_quickHelp->dfs_code(1);
		animationRecord(NULL, NULL, NULL, 1, 1);
		if (!Mvisited[node->adjointVertex]) {
			EdgeChangeColor(QString::fromStdString(g.adjointList[index].data),
				QString::fromStdString(g.adjointList[node->adjointVertex].data));
			m_quickHelp->dfs_code(2);
			animationRecord(2, QString::fromStdString(g.adjointList[index].data),
				QString::fromStdString(g.adjointList[node->adjointVertex].data), 1, 2);
			DFS(g, node->adjointVertex);
		}
		node = node->next;
	}
}
void GraphUI::DFSTraverse(MGraph g) {
	//�ڵ��ʼ�� δ����
	for (int i = 0; i < g.numVertex; i++) {
		Mvisited[i] = false;
	}
	//��δ���ʵĽڵ���б���
	for (int i = 0; i < g.numVertex; i++) {
		if (!Mvisited[i]) {
			DFS(g, i);
		}
		else {
			m_quickHelp->dfs_code(3);
			animationRecord(NULL, NULL, NULL, 1, 3);
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
void GraphUI::MDijkstra(int n, int v, int *dist, int *prev, int
	c[maxnum][maxnum])
{
	bool s[maxnum]; // �ж��Ƿ��ڼ�����
	for (int i = 1; i <= n; ++i)
	{
		dist[i] = c[v][i];
		s[i] = 0; // ��ʼδʹ�õ�
		if (dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;// ��¼��Դ�㵽�����������·������
	s[v] = 1;
	for (int i = 2; i <= n; ++i)// ȡ��Сֵ��㣬���뼯��
	{
		int tmp = maxint;
		int u = v;
		// �ҳ���ǰ���������δʹ�õ�
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && dist[j] < tmp)
			{
				u = j; // u ���浱ǰ�ڽӵ��о�����С�ĵ�
				tmp = dist[j];
			}
		s[u] = 1; // ��ʾ u ���Ѵ��뼯����
		follow[i] = u;
		for (int j = 1; j <= n; ++j)
			if ((!s[j]) && c[u][j] < maxint) {
				int newdist = dist[u] + c[u][j];
				if (newdist < dist[j]) {
					dist[j] = newdist;
					prev[j] = u;
				}
			}
	}
}
void GraphUI::searchPath(int *prev, int v, int u)
{
	int que[maxnum];
	int tot = 1;
	que[tot] = u;
	tot++;
	int tmp = prev[u];
	while (tmp != v) {
		que[tot] = tmp;
		tot++;
		tmp = prev[tmp];
	}
	que[tot] = v;
	int previousNode = 1;
	for (int i = tot; i >= 1; --i) {
		if (i != 1) {
			if (i != tot) {
				int nodeID1 = previousNode + 64;
				QByteArray a1;
				a1.resize(1);
				a1[0] = nodeID1;
				QString q1;
				q1 = a1.data();
				int nodeID2 = que[i] + 64;
				QByteArray a2;
				a2.resize(1);
				a2[0] = nodeID2;
				QString q2;
				q2 = a2.data();
				EdgeChangeColor(q1, q2);//�ı����ɫ
				animationRecord(2, q1, q2);
			}
			int nodeID = que[i] + 64;//����ת��
			QByteArray a;
			a.resize(1);
			a[0] = nodeID;
			QString q;
			q = a.data();
			NodeChangeColor(q);//�ı�ڵ���ɫ
			animationRecord(1, q, NULL);
			previousNode = que[i];
		}
		else {
			if (i != tot) {
				int nodeID1 = previousNode + 64;
				QByteArray a1;
				a1.resize(1);
				a1[0] = nodeID1;
				QString q1;
				q1 = a1.data();
				int nodeID2 = que[i] + 64;
				QByteArray a2;
				a2.resize(1);
				a2[0] = nodeID2;
				QString q2;
				q2 = a2.data();
				EdgeChangeColor(q1, q2);//�ı����ɫ
				animationRecord(2, q1, q2);
			}
			int nodeID = que[i] + 64; //����ת��
			QByteArray a;
			a.resize(1);
			a[0] = nodeID;
			QString q;
			q = a.data();
			NodeChangeColor(q);//�ı�ڵ���ɫ
			animationRecord(1, q, NULL);
			previousNode = que[i];//��¼֮ǰ�ڵ�
		}
	}
}
//prim �㷨
int GraphUI::LocateVex(VexBox adj[], int num, string v) {
	for (int i = 0; i < num; i++) {
		if (adj[i].data == v) {
			return i;
		}
	}
}
void GraphUI::CreateGraph(AMLGraph *G) {
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	G->vexnum = nodes.count();//����ڵ�����
	G->edgenum = edges.count();//����ߵ�����
	for (auto edge : edges)
	{
		qDebug() << "frist node: " + edge->firstNode()->getId() + "last node: " +
			edge->lastNode()->getId();
		edge->setLabelText(edge->getId());
		edge->showLabel(true);
		//��ʾ��ǩ
		//����û�м�ͷ
		edge->setAttribute("direction", "undirected");
	}
	for (auto node : nodes)
	{
		qDebug() << " node: " + node->getId();
		//��ȡ ID ��Ϊ�ڵ��ǩ����
		//����������ʾ������
		node->setSize(70, 70);
		node->setLabelText(node->getId());
		node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
		node->showLabel(true);
		//��ʾ��ǩ
	}
	int nodei = 0;
	for (auto node : nodes)
	{
		//תΪ string ����
		G->adjmulist[nodei].data = node->getId().toStdString();
		G->adjmulist[nodei].mark = unvisited;
		G->adjmulist[nodei].firstedge = NULL;
		nodei++;
	}
	for (auto edge : edges)
	{
		string v1, v2;
		int vw;
		v1 = edge->firstNode()->getId().toStdString();
		v2 = edge->lastNode()->getId().toStdString();
		vw = edge->getId().toInt(); //�ߵ�Ȩ����Ҫ������
		int i1 = LocateVex(G->adjmulist, G->vexnum, v1);
		int i2 = LocateVex(G->adjmulist, G->vexnum, v2);
		EBox *p = new EBox;
		p->ivex = i1;
		p->jvex = i2;
		p->weight = vw;
		p->ilink = G->adjmulist[i1].firstedge;
		p->jlink = G->adjmulist[i2].firstedge;
		G->adjmulist[i1].firstedge = p;
		G->adjmulist[i2].firstedge = p;
	}
}
int GraphUI::FirstAdjVex(AMLGraph G, int v, int &wei) {
	int i = v;
	if (G.adjmulist[i].firstedge) {
		if (G.adjmulist[i].firstedge->ivex == i) {
			wei = G.adjmulist[i].firstedge->weight;
			return G.adjmulist[i].firstedge->jvex;
		}
		else {
			wei = G.adjmulist[i].firstedge->weight;
			return G.adjmulist[i].firstedge->ivex;
		}
	}
	else
		return -1;
}
//v �� G �е�ĳ�����㣬w �� v ���ڽӶ���
//���� v ��(����� w ��)��һ���ڽӶ��㡣�� w �� v �����һ���ڽӵ㣬�򷵻ؿ�
int GraphUI::NextAdjVex(AMLGraph G, int v, int w, int &wei) {
	int i1 = v;
	int i2 = w;
	EBox *p = G.adjmulist[i1].firstedge;
	while (p) {
		if (p->ivex == i1 && p->jvex != i2) {
			p = p->ilink;
		}
		else {
			if (p->ivex != i2 && p->jvex == i1) {
				p = p->jlink;
			}
			else {
				break;
			}
		}
	}
	if (p && p->ivex == i1 && p->jvex == i2) {
		p = p->ilink;
		if (p&&p->ivex == i1) {
			wei = p->weight;
			return p->jvex;
		}
		else if (p&&p->jvex == i1) {
			wei = p->weight;
			return p->ivex;
		}
	}
	if (p && p->ivex == i2 && p->jvex == i1) {
		p = p->jlink;
		if (p&&p->ivex == i1) {
			wei = p->weight;
			return p->jvex;
		}
		else if (p&&p->jvex == i1) {
			wei = p->weight;
			return p->ivex;
		}
	}
	return -1;
}
void GraphUI::PrintGraph(AMLGraph G)
{
	EBox *p;
	for (int i = 0; i < G.vexnum; ++i)
	{
		p = G.adjmulist[i].firstedge;
		while (p != NULL)
		{
			if (p->ivex == i) //�ж���Ȳ���֪�������ϵ��� ivex ���� jvex;
			{
				//cout << G.adjmulist[p->ivex].data << "---" << p->weight << "---" << G.adjmulist[p->jvex].data << endl;
					p = p->ilink;
			}
			else
			{
				//cout << G.adjmulist[p->jvex].data << "---" << p->weight << "-				--" << G.adjmulist[p->ivex].data << endl;
					p = p->jlink;
			}
		}
	}
}
void GraphUI::MiniSpanTree_PRIM(AMLGraph G) {
	struct {
		int adjvex;
		int lowcost;
	}close[1010];
	string v0;
	QList<CNode*> selectedNodes = m_scene->getSelectedNodes();
	//��ѡ��ĵ�һ���ڵ��������
	if (selectedNodes.isEmpty() == false)
	{
		v0 = selectedNodes.at(0)->getId().toStdString();//תΪ string ����
	}
	else //δѡ��ڵ�ͷ���
	{
		return;
	}
	int i0 = LocateVex(G.adjmulist, G.vexnum, v0);
	for (int i = 0; i < G.vexnum; i++) {
		if (i != i0) {
			close[i].adjvex = i0;
			close[i].lowcost = INT_MAX;
		}
	}
	int wei = 0;
	for (int w = FirstAdjVex(G, i0, wei); w >= 0; w = NextAdjVex(G, i0, w, wei)) {
		close[w].lowcost = wei;
	}
	close[i0].lowcost = 0;
	string predata = v0;//ǰһ���ڵ�
	NodeChangeColor(QString::fromStdString(predata));
	animationRecord(1, QString::fromStdString(predata), NULL);
	for (int i = 0; i < G.vexnum - 1; i++)
	{
		int min = INT_MAX;
		int minadj = -1;
		for (int j = 0; j < G.vexnum; j++)//�����ڵ�
		{
			if (close[j].lowcost != 0 && close[j].lowcost < min) {
				minadj = j;
				min = close[j].lowcost;
			}
		}
		//����ڵ�
		NodeChangeColor(QString::fromStdString(G.adjmulist[minadj].data));
		animationRecord(1,
			QString::fromStdString(G.adjmulist[minadj].data), NULL);
		//�����
		QList<CEdge*> edges = m_scene->getItems<CEdge>();
		for (auto edge : edges)
		{
			if (edge->getId() == QString::number(min) &&
				edge->getAttribute("color") != "#FF0000")
			{
				EdgeChangeColor(edge->firstNode()->getId(),
					edge->lastNode()->getId());
				animationRecord(2, edge->firstNode()->getId(),
					edge->lastNode()->getId());
			}
		}
		close[minadj].lowcost = 0;
		for (int w = FirstAdjVex(G, minadj, wei); w >= 0; w = NextAdjVex(G,
			minadj, w, wei)) {
			if (close[w].lowcost > wei) {
				close[w].adjvex = minadj;
				close[w].lowcost = wei;
			}
		}
	}
}
int GraphUI::FindSet(vector<int> uset, int i) {
	return uset[i] == i ? i : FindSet(uset, uset[i]);
}
void GraphUI::MiniSpanTree_Kruskal(AMLGraph G) {
	vector<Edge_Kruskal> edg;
	EBox *p;
	for (int i = 0; i < G.vexnum; i++) {
		p = G.adjmulist[i].firstedge;
		while (p != NULL)
		{
			if (p->ivex == i) //�ж���Ȳ���֪�������ϵ��� ivex ���� jvex;
			{
				int i1 = LocateVex(G.adjmulist, G.vexnum,
					G.adjmulist[p->ivex].data);
				int i2 = LocateVex(G.adjmulist, G.vexnum,
					G.adjmulist[p->jvex].data);
				//cout << i1 << i2 << p->weight << endl;
				if (i1 < i2) {
					edg.push_back(Edge_Kruskal(i1, i2, p->weight));
				}
				p = p->ilink;
			}
			else
			{
				int i1 = LocateVex(G.adjmulist, G.vexnum,
					G.adjmulist[p->jvex].data);
				int i2 = LocateVex(G.adjmulist, G.vexnum,
					G.adjmulist[p->ivex].data);
				//cout << i1 << i2 << p->weight << endl;
				if (i1 < i2) {
					edg.push_back(Edge_Kruskal(i1, i2, p->weight));
				}
				p = p->jlink;
			}
		}
	}
	sort(edg.begin(), edg.end());
	vector<int> uset;
	uset.assign(G.vexnum, 0);
	for (int i = 0; i < G.vexnum; i++) {
		uset[i] = i;
	}
	//string visitedNode[1010];
	for (int i = 0; i < edg.size(); i++) {
		int e1 = FindSet(uset, edg[i].u);
		int e2 = FindSet(uset, edg[i].v);
		if (e1 != e2) {
			//cout << G.adjmulist[edg[i].u].data << "---" << edg[i].weight << "---" << G.adjmulist[edg[i].v].data << endl;
				//�����
				QList<CEdge*> edges = m_scene->getItems<CEdge>();
			for (auto edge : edges)
			{ //
				if (edge->getId() == QString::number(edg[i].weight) &&
					edge->getAttribute("color") != "#FF0000")
				{
					EdgeChangeColor(edge->firstNode()->getId(),
						edge->lastNode()->getId());
					animationRecord(2, edge->firstNode()->getId(),
						edge->lastNode()->getId());
				}
			}
			if (G.adjmulist[edg[i].u].mark == unvisited)
			{
				NodeChangeColor(QString::fromStdString(G.adjmulist[edg[i].u].data));
				animationRecord(1,
					QString::fromStdString(G.adjmulist[edg[i].u].data), NULL);
				G.adjmulist[edg[i].u].mark = visited;
			}
			if (G.adjmulist[edg[i].v].mark == unvisited)
			{
				NodeChangeColor(QString::fromStdString(G.adjmulist[edg[i].v].data));
				animationRecord(1,
					QString::fromStdString(G.adjmulist[edg[i].v].data), NULL);
				G.adjmulist[edg[i].v].mark = visited;
			}
			uset[e2] = e1;
		}
	}
}
int GraphUI::topoCreate(topoNode topoadj[], int n, int m)//�ڽӱ�������n����������m �������
{
	topoNode *p;
	for (int i = 1; i <= n; i++)
	{
		topoadj[i].adjvex = i;
		topoadj[i].next = NULL;
	}
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	int i = 1;
	for (auto edge : edges)
	{
		//cout << "�������" << i << "����:";
		int u, v;
		QByteArray u_byte = edge->firstNode()->getId().toUtf8();
		u = int(u_byte.at(0)) - 64;
		qDebug() << "fristnode ascll" << p;
		QByteArray v_byte = edge->lastNode()->getId().toUtf8();
		v = int(v_byte.at(0)) - 64;
		//cin >> u >> v;
		p = new topoNode;
		p->adjvex = v;
		p->next = topoadj[u].next;
		topoadj[u].next = p;
		i++;
	}
	return 1;
}
void GraphUI::topoPrint(int n)//�ڽӱ��ӡ����
{
	int i;
	topoNode *p;
	for (i = 1; i <= n; i++)
	{
		p = &topoadj[i];
		while (p != NULL)
		{
			qDebug() << p->adjvex << ' ';
			p = p->next;
		}
		qDebug() << endl;
	}
}
void GraphUI::topoSort(topoNode topoadj[], int n)
{
	int toponode;
	topoNode *p;
	memset(indegree, 0, sizeof(indegree));
	for (int i = 1; i <= n; i++)
	{
		p = topoadj[i].next;
		while (p != NULL)
		{
			indegree[p->adjvex]++;
			p = p->next;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (indegree[i] == 0)
			mystack.push(i);
	}
	int count = 0;
	int pirNode = -1;
	while (mystack.size() != 0)
	{
		toponode = mystack.top();
		mystack.pop();
		qDebug() << toponode << ' ';
		QByteArray toponodeID;
		toponodeID.resize(1);
		toponodeID[0] = toponode + 64;
		QByteArray pirnodeID;
		pirnodeID.resize(1);
		pirnodeID[0] = pirNode + 64;
		//�����
		QList<CEdge*> edges = m_scene->getItems<CEdge>();
		for (auto edge : edges)
		{
			if (edge->firstNode()->getId() == pirnodeID.data()
				&& edge->lastNode()->getId() == toponodeID.data())
			{
				EdgeChangeColor(edge->firstNode()->getId(),
					edge->lastNode()->getId());
				animationRecord(2, edge->firstNode()->getId(),
					edge->lastNode()->getId());
			}
		}
		NodeChangeColor(toponodeID.data());
		animationRecord(1, toponodeID.data(), NULL);
		pirNode = toponode;
		/////////////////////
		count++;
		for (p = topoadj[toponode].next; p != NULL; p = p->next)
		{
			int k = p->adjvex;
			indegree[k]--;
			if (indegree[k] == 0)
				mystack.push(k);
		}
	}
	qDebug() << endl;
	if (count < n)qDebug() << "have circle" << endl;
}
void GraphUI::goToBeginButton()
{
	on_reset_btn_clicked();
	endplaybuttonflag = 1;
	timestamp = 1;
	animationDraw(timestamp);
	/*m_quickHelp->btree_insert_code(insertIdCode[timestamp]);*/
}
void GraphUI::stepBackButton()
{
	endplaybuttonflag = 1;
	on_reset_btn_clicked();
	if (timestamp > 1)
	{
		timestamp--;
		for (int i = 1; i < timestamp; i++)
		{
			animationDrawWithoutSuspand(i);
		}
		//m_scene->clearScreen();//����
		animationDraw(timestamp);
		//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
	}
}
void GraphUI::playButton()
{
	endplaybuttonflag = 0;
	for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1;
		timestamp++)
	{
		//m_scene->clearScreen();//����
		animationDraw(timestamp);
		//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
		//sleepTime(500);
	}
}
void GraphUI::suspendButton()
{
	endplaybuttonflag = 1;
}
void GraphUI::stepForwardButton()
{
	endplaybuttonflag = 1;
	if (timestamp < onlytotaltime)
	{
		timestamp++;
		//m_scene->clearScreen();//����
		animationDraw(timestamp);
		//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
	}
}
void GraphUI::goToEndButton()
{
	endplaybuttonflag = 1;
	//m_scene->clearScreen();//����
	for (timestamp; timestamp <= onlytotaltime; timestamp++)
	{
		animationDrawWithoutSuspand(timestamp);
	}
	//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
}
void GraphUI::animationDraw(int totaltime)
{
	if (animation[totaltime].functionid == 1) {
		NodeChangeColor(animation[totaltime].para1);
	}
	else if (animation[totaltime].functionid == 2) {
		EdgeChangeColor(animation[totaltime].para1,
			animation[totaltime].para2);
	}
	//dfs ����
	if (animation[totaltime].codefunctionid == 1) {
		m_quickHelp->dfs_code(animation[totaltime].codefunctionlineid);
	}
}
void GraphUI::animationDrawWithoutSuspand(int totaltime)
{
	if (animation[totaltime].functionid == 1) {
		NodeChangeColorWithoutSuspand(animation[totaltime].para1);
	}
	else if (animation[totaltime].functionid == 2) {
		EdgeChangeColorWithoutSuspand(animation[totaltime].para1,
			animation[totaltime].para2);
	}
	//dfs ����
	if (animation[totaltime].codefunctionid == 1) {
		m_quickHelp->dfs_code(animation[totaltime].codefunctionlineid);
	}
}
void GraphUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//��ȡ�Զ�������ʱ��
		while (QTime::currentTime() < dieTime)
		{
			QCoreApplication::processEvents(QEventLoop::AllEvents, 100);// �������̣߳����� qt �����¼�
		}
}
void GraphUI::setCEditorView(CEditorView* editorView)
{
	m_editorView = editorView;
	setEnabled(m_editorView);
}
//totaltime ������ʱ�� functionid 1 �ڵ㣬2 ��
void GraphUI::animationRecord(int functionid, QString para1, QString
	para2, int codefunctionid, int codefunctionlineid)
{
	onlytotaltime++;
	int totaltime = onlytotaltime;
	animation[totaltime].totaltime = totaltime;
	animation[totaltime].functionid = functionid;
	animation[totaltime].para1 = para1;
	animation[totaltime].para2 = para2;
	animation[totaltime].codefunctionid = codefunctionid;
	animation[totaltime].codefunctionlineid = codefunctionlineid;
}
void GraphUI::animationRecord(int functionid, QString para1, QString para2)
{
	onlytotaltime++;
	int totaltime = onlytotaltime;
	animation[totaltime].totaltime = totaltime;
	animation[totaltime].functionid = functionid;
	animation[totaltime].para1 = para1;
	animation[totaltime].para2 = para2;
	animation[totaltime].codefunctionid = NULL;
	animation[totaltime].codefunctionlineid = NULL;
}
void GraphUI::animationview(int currenttime)
{
	qDebug() << "animation[currenttime].totaltime" << animation[currenttime].totaltime;
	qDebug() << "animation[currenttime].functionid" <<animation[currenttime].functionid;
	qDebug() << "animation[currenttime].para1" <<animation[currenttime].para1;
	qDebug() << "animation[currenttime].para2" <<animation[currenttime].para2;
}
