#include "GraphUI.h"
#include "GraphUI.h"
#include "ui_GraphUI.h"
#include "CNodeEditorScene.h"
#include <QFile>
#include <QTextStream>
#include <CNodeEditorScene.h>
#include <CEdge.h>
#include <CNode.h>
#include <QString>
#include <QDebug>
#include <QColor>
#include <QTime>
#include <QMessageBox>
GraphUI::GraphUI(QWidget* parent) :QWidget(parent),
	ui(new Ui::GraphUI),
	m_scene(NULL)
{
	ui->setupUi(this);
}
void GraphUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);
}
void GraphUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);
	m_scene = scene;
	setEnabled(m_scene);
	if (m_scene)
		onSceneAttached(m_scene);
}
void GraphUI::setCQuickHelpUI(CQuickHelpUI* scene)
{
	m_quickHelp = scene;
	setEnabled(m_quickHelp);
}
void GraphUI::onSceneAttached(CEditorScene* scene) {} GraphUI::~GraphUI() {}
void GraphUI::setCNodeEditorUIController(CNodeEditorUIController*nodeEditorUIController)
{
	m_nodeEditorUIController = nodeEditorUIController;
	setEnabled(m_nodeEditorUIController);
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
		edge->setLabelText(edge->getId());
		edge->showLabel(true);
		//��ʾ��ǩ
		//edge->setAttribute("direction", "directed");
	}
	for (auto node : nodes)
	{
		qDebug() << " node: " + node->getId();
		//��ȡ ID ���Ľڵ��ǩ����
		//����������ʾ������
		node->setSize(70, 70);
		node->setLabelText(node->getId());
		node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
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
int GraphUI::getPosition(MGraph g, string value)
{
	for (int i = 0; i < g.numVertex; i++) {
		if (g.adjointList[i].data == value) {
			return i;
		}
	}
	return -1;
}
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
void GraphUI::EdgeChangeColor(QString firstNodeID, QString lastNodeID)
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
void GraphUI::EdgeChangeColorWithoutSuspand(QString firstNodeID,QString lastNodeID)
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
void GraphUI::PrintGraph(AMLGraph G)
{
	EBox* p;
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
				//cout << G.adjmulist[p->jvex].data << "---" << p->weight << "---" << G.adjmulist[p->ivex].data << endl;
				p = p->jlink;
			}
		}
	}
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
	for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1;timestamp++)
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
			QCoreApplication::processEvents(QEventLoop::AllEvents, 100);// �� �����̣߳����� qt �����¼�
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
	qDebug() << "animation[currenttime].functionid" <<
		animation[currenttime].functionid;
	qDebug() << "animation[currenttime].para1" <<
		animation[currenttime].para1;
	qDebug() << "animation[currenttime].para2" <<
		animation[currenttime].para2;
}

void GraphUI::on_findCenterPoints_btn_clicked()
{
	m_nodeEditorUIController->clickButtonDisabled();

	QList<CNode*> nodes = m_scene->getItems<CNode>();
	int n = nodes.count();
	std::vector<std::vector<int>> dist = initializeDistanceMatrix(nodes, n);

	// ʹ�ø��������㷨Ѱ���������·��
	calculateShortestPaths(dist, n);

	// ����ÿ���ڵ��ƫ�ĶȲ��ҳ����ĵ�
	findAndMarkCenterPoints(nodes, dist, n);

	m_nodeEditorUIController->clickButtonEnabled();
}

std::vector<std::vector<int>> GraphUI::initializeDistanceMatrix(const QList<CNode*>& nodes, int n)
{
	std::vector<std::vector<int>> dist(n, std::vector<int>(n, maxint));
	for (int i = 0; i < n; ++i) {
		dist[i][i] = 0;
	}

	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	for (auto edge : edges) {
		int u = getNodeIndex(edge->firstNode());
		int v = getNodeIndex(edge->lastNode());
		int len = edge->getId().toInt();
		dist[u][v] = len;
	}

	return dist;
}

void GraphUI::calculateShortestPaths(std::vector<std::vector<int>>& dist, int n)
{
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][k] < maxint && dist[k][j] < maxint &&
					dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void GraphUI::findAndMarkCenterPoints(const QList<CNode*>& nodes, const std::vector<std::vector<int>>& dist, int n)
{
	std::vector<int> eccentricity(n, 0);
	int minEccentricity = maxint;
	for (int i = 0; i < n; ++i) {
		eccentricity[i] = calculateEccentricity(dist, i, n);
		if (eccentricity[i] > 0) {
			minEccentricity = std::min(minEccentricity, eccentricity[i]);
		}
	}

	bool centerExists = false;
	for (int i = 0; i < n; ++i) {
		if (eccentricity[i] == minEccentricity && eccentricity[i] != 0) {
			centerExists = true;
			nodes[i]->setAttribute("color", "#FF0000"); // �����Ľڵ���Ϊ��ɫ
		}
	}

	if (!centerExists) {
		QMessageBox::information(this, QString::fromLocal8Bit("���ĵ�"), QString::fromLocal8Bit("δ�ҵ����ĵ㣡"));
	}
}

int GraphUI::calculateEccentricity(const std::vector<std::vector<int>>& dist, int nodeIndex, int n)
{
	int maxDist = 0;
	for (int j = 0; j < n; ++j) {
		if (nodeIndex != j && dist[j][nodeIndex] < maxint) {
			maxDist = std::max(maxDist, dist[j][nodeIndex]);
		}
	}
	return maxDist;
}

//���ڻ�ȡ�ڵ��������ڵ���Ψһ��ID��
int GraphUI::getNodeIndex(CNode* node) {
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	for (int i = 0; i < nodes.count(); ++i) {
		if (nodes[i]->getId() == node->getId()) {
			return i;
		}
	}
	return -1; // ���δ�ҵ��ڵ㣬���� -1
}
