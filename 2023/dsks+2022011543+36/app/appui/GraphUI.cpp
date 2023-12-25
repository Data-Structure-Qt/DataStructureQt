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
#include <QThread>
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
GraphUI::~GraphUI() { maxlength = 0; }
void GraphUI::setCNodeEditorUIController(CNodeEditorUIController*
	nodeEditorUIController)
{
	m_nodeEditorUIController = nodeEditorUIController;
	setEnabled(m_nodeEditorUIController);
}

void GraphUI::on_thelongestroad_btn_clicked()
{
	// ��ȡ��ĻĿǰ�ıߺ͵�
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	// ��ʾ�߱�ǩ
	for (auto edge : edges)
	{
		edge->setLabelText(edge->getId());
		edge->showLabel(true);
		edge->setAttribute("direction", "directed");
	}
	// ��ʾ�ڵ��ǩ
	for (auto node : nodes)
	{
		node->setSize(70, 70);
		node->setLabelText(node->getId());
		node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
		node->showLabel(true); // ��ʾ��ǩ
	}
	MGraph g; // �½�ͼ
	createGraph(g); // ������Ļ����ڵ㴴��ͼ
	DFSTraverse(g);

	// �������·���ϵĵ�ͱ�Ϊ��ɫ������¼����
	for (int i = 0; i < maxnodes.length(); i++) {
		// ���õ�ǰ�ڵ�Ϊ��ɫ
		for (auto node : nodes) {
			if (node->getId() == maxnodes[i]) {
				node->setAttribute("color", "#FF0000");
				break;
			}
		}
		if (i < maxnodes.length() - 1) {
			// ���õ�ǰ��Ϊ��ɫ
			for (auto edge : edges) {
				if (edge->firstNode()->getId() == maxnodes[i] && edge->lastNode()->getId() == maxnodes[i + 1]) {
					edge->setAttribute("color", "#FF0000");
					break;
				}
			}
		}
	}
}

void GraphUI::DFS(MGraph g, int index, QList<QString> currentPath, int currentPathLength) {
	CGraphVertexNode *node;
	Mvisited[index] = true;
	// ����ǰ�ڵ���ӵ���ǰ·��
	currentPath.append(QString::fromStdString(g.adjointList[index].data));

	node = g.adjointList[index].firstEdage;
	while (node) {
		m_quickHelp->dfs_code(1);
		animationRecord(NULL, NULL, NULL, 1, 1);
		if (!Mvisited[node->adjointVertex]) {

			// �ݹ����DFSʱ������º��·����Ϣ
			DFS(g, node->adjointVertex, currentPath, currentPathLength + 1);
		}
		node = node->next;
	}
	// �ڻ���ʱ����鵱ǰ·���Ƿ�Ϊ�·��
	if (currentPathLength > maxlength) {
		maxlength = currentPathLength;
		maxnodes = currentPath;
	}
}

void GraphUI::DFSTraverse(MGraph g) {
	// �ڵ��ʼ�� δ����
	for (int i = 0; i < g.numVertex; i++) {
		Mvisited[i] = false;
	}

	// ��δ���ʵĽڵ���б���
	for (int i = 0; i < g.numVertex; i++) {
		if (!Mvisited[i]) {
			QList<QString> currentPath;  // ���ڼ�¼��ǰ·��
			DFS(g, i, currentPath, 1);

			// �����ʹ���·����Ϣ
			qDebug() << "Longest Path: " << maxnodes;

		}
		else {
			m_quickHelp->dfs_code(3);
			animationRecord(NULL, NULL, NULL, 1, 3);
		}
	}
}
//�ı�ڵ����ɫ
void GraphUI::NodeChangeColor(QString nodeID)
{
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	for (auto m_node : nodes) {
		if (m_node->getId() == nodeID) {
			for (int i = 0; i < 2; i++)//��˸
			{
				m_node->setAttribute("color", "#3399ff");
				QTime time;
				time.start();
				while (time.elapsed() < 300); //�ȴ�ʱ��
				QCoreApplication::processEvents(); //�����¼�
				m_node->setAttribute("color", "#FF0000");
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
void GraphUI::EdgeChangeColor(QString firstNodeID, QString lastNodeID) {
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	for (auto m_edge : edges)
	{//ǰ��ڵ����ӵı�
		if (QString(m_edge->firstNode()->getId()) == firstNodeID &&
			QString(m_edge->lastNode()->getId()) == lastNodeID)
		{
			for (int i = 0; i < 2; i++)//��˸
			{
				m_edge->setAttribute("color", "#a0a0a4");
				QTime time;
				time.start();
				while (time.elapsed() < 300); //�ȴ�ʱ��
				QCoreApplication::processEvents(); //�����¼�
				m_edge->setAttribute("color", "#FF0000");
				time.start();
				while (time.elapsed() < 300); //�ȴ�ʱ��
				QCoreApplication::processEvents(); //�����¼�
			}
		}
	}
}
//�ı��߶ε���ɫ
void GraphUI::EdgeChangeColorWithoutSuspand(QString firstNodeID, QString lastNodeID)
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
void GraphUI::createGraph(MGraph &g) {
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	g.numVertex = nodes.count();//���������
	g.numEdge = edges.count();//���������
	int nodei = 0; //������
	QList<CNode*> selectedNodes = m_scene->getSelectedNodes();//��һ���ڵ��������
	if (selectedNodes.isEmpty() == false) {
		g.adjointList[nodei].data = selectedNodes.at(0)->getId().toStdString();//תΪ string ����
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
			g.adjointList[nodei].data = node->getId().toStdString();//תΪ string ����
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
void GraphUI::goToBeginButton()
{
	on_reset_btn_clicked();
	endplaybuttonflag = 1;
	timestamp = 1;
	animationDraw(timestamp);
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
	}
}
void GraphUI::playButton()
{
	endplaybuttonflag = 0;
	for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1;
		timestamp++)
	{
		animationDraw(timestamp);
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
		animationDraw(timestamp);
	}
}
void GraphUI::goToEndButton()
{
	endplaybuttonflag = 1;
	for (timestamp; timestamp <= onlytotaltime; timestamp++)
	{
		animationDrawWithoutSuspand(timestamp);
	}
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

void GraphUI::setCEditorView(CEditorView* editorView)
{
	m_editorView = editorView;
	setEnabled(m_editorView);
}
void GraphUI::animationRecord(int functionid, QString para1, QString para2, int codefunctionid, int codefunctionlineid)
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



