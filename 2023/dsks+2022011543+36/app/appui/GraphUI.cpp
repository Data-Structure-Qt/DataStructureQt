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
	// 获取屏幕目前的边和点
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	// 显示边标签
	for (auto edge : edges)
	{
		edge->setLabelText(edge->getId());
		edge->showLabel(true);
		edge->setAttribute("direction", "directed");
	}
	// 显示节点标签
	for (auto node : nodes)
	{
		node->setSize(70, 70);
		node->setLabelText(node->getId());
		node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
		node->showLabel(true); // 显示标签
	}
	MGraph g; // 新建图
	createGraph(g); // 依据屏幕边与节点创建图
	DFSTraverse(g);

	// 逐步设置最长路径上的点和边为红色，并记录动画
	for (int i = 0; i < maxnodes.length(); i++) {
		// 设置当前节点为红色
		for (auto node : nodes) {
			if (node->getId() == maxnodes[i]) {
				node->setAttribute("color", "#FF0000");
				break;
			}
		}
		if (i < maxnodes.length() - 1) {
			// 设置当前边为红色
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
	// 将当前节点添加到当前路径
	currentPath.append(QString::fromStdString(g.adjointList[index].data));

	node = g.adjointList[index].firstEdage;
	while (node) {
		m_quickHelp->dfs_code(1);
		animationRecord(NULL, NULL, NULL, 1, 1);
		if (!Mvisited[node->adjointVertex]) {

			// 递归调用DFS时传入更新后的路径信息
			DFS(g, node->adjointVertex, currentPath, currentPathLength + 1);
		}
		node = node->next;
	}
	// 在回溯时，检查当前路径是否为最长路径
	if (currentPathLength > maxlength) {
		maxlength = currentPathLength;
		maxnodes = currentPath;
	}
}

void GraphUI::DFSTraverse(MGraph g) {
	// 节点初始化 未访问
	for (int i = 0; i < g.numVertex; i++) {
		Mvisited[i] = false;
	}

	// 对未访问的节点进行遍历
	for (int i = 0; i < g.numVertex; i++) {
		if (!Mvisited[i]) {
			QList<QString> currentPath;  // 用于记录当前路径
			DFS(g, i, currentPath, 1);

			// 输出或使用最长路径信息
			qDebug() << "Longest Path: " << maxnodes;

		}
		else {
			m_quickHelp->dfs_code(3);
			animationRecord(NULL, NULL, NULL, 1, 3);
		}
	}
}
//改变节点的颜色
void GraphUI::NodeChangeColor(QString nodeID)
{
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	for (auto m_node : nodes) {
		if (m_node->getId() == nodeID) {
			for (int i = 0; i < 2; i++)//闪烁
			{
				m_node->setAttribute("color", "#3399ff");
				QTime time;
				time.start();
				while (time.elapsed() < 300); //等待时间
				QCoreApplication::processEvents(); //处理事件
				m_node->setAttribute("color", "#FF0000");
				time.start();
				while (time.elapsed() < 300); //等待时间
				QCoreApplication::processEvents(); //处理事件
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
//改变线段的颜色
void GraphUI::EdgeChangeColor(QString firstNodeID, QString lastNodeID) {
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	for (auto m_edge : edges)
	{//前后节点连接的边
		if (QString(m_edge->firstNode()->getId()) == firstNodeID &&
			QString(m_edge->lastNode()->getId()) == lastNodeID)
		{
			for (int i = 0; i < 2; i++)//闪烁
			{
				m_edge->setAttribute("color", "#a0a0a4");
				QTime time;
				time.start();
				while (time.elapsed() < 300); //等待时间
				QCoreApplication::processEvents(); //处理事件
				m_edge->setAttribute("color", "#FF0000");
				time.start();
				while (time.elapsed() < 300); //等待时间
				QCoreApplication::processEvents(); //处理事件
			}
		}
	}
}
//改变线段的颜色
void GraphUI::EdgeChangeColorWithoutSuspand(QString firstNodeID, QString lastNodeID)
{
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	for (auto m_edge : edges)
	{//前后节点连接的边
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
		//显示标签
		//edge->setAttribute("direction", "directed");
	}
	for (auto node : nodes)
	{
		qDebug() << " node: " + node->getId();
		//获取 ID 作文节点标签文字
		//设置文字显示到中央
		node->setSize(70, 70);
		node->setLabelText(node->getId());
		node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
		node->showLabel(true);
		//显示标签
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
	g.numVertex = nodes.count();//传入点数量
	g.numEdge = edges.count();//传入边数量
	int nodei = 0; //计数器
	QList<CNode*> selectedNodes = m_scene->getSelectedNodes();//第一个节点存入数组
	if (selectedNodes.isEmpty() == false) {
		g.adjointList[nodei].data = selectedNodes.at(0)->getId().toStdString();//转为 string 类型
		g.adjointList[nodei].firstEdage = NULL;
		nodei++;
	}
	else //未选择节点就返回
	{
		return;
	}
	for (auto node : nodes)//其余进入数组
	{
		if (node->getId().toStdString() !=
			selectedNodes.at(0)->getId().toStdString()) {
			g.adjointList[nodei].data = node->getId().toStdString();//转为 string 类型
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
		//m_scene->clearScreen();//清屏
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
	//dfs 代码
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
	//dfs 代码
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



