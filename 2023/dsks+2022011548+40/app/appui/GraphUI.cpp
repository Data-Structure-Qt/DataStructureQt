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
		node->setAttribute("color", "#00FFFF");
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

void GraphUI::NodeChangeColor(QString nodeID)
{
	QList<CNode*> nodes = m_scene->getItems<CNode>();
	for (auto node : nodes) {
		if (node->getId() == nodeID) {
			for (int i = 0; i < 2; i++)//闪烁
			{
				node->setAttribute("color", "#00FFFF");
				QTime time;
				time.start();
				while (time.elapsed() < 300); //等待时间
				QCoreApplication::processEvents(); //处理事件
				node->setAttribute("color", "#FF0000");
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
void GraphUI::EdgeChangeColor(QString firstNodeID, QString lastNodeID)
{
	QList<CEdge*> edges = m_scene->getItems<CEdge>();
	for (auto edge : edges)
	{//前后节点连接的边
		if (QString(edge->firstNode()->getId()) == firstNodeID &&
			QString(edge->lastNode()->getId()) == lastNodeID)
		{
			for (int i = 0; i < 2; i++)//闪烁
			{
				edge->setAttribute("color", "#a0a0a4");
				QTime time;
				time.start();
				while (time.elapsed() < 300); //等待时间
				QCoreApplication::processEvents(); //处理事件
				edge->setAttribute("color", "#FF0000");
				time.start();
				while (time.elapsed() < 300); //等待时间
				QCoreApplication::processEvents(); //处理事件
			}
		}
	}
}

//改变线段的颜色
void GraphUI::EdgeChangeColorWithoutSuspand(QString firstNodeID,QString lastNodeID)
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
				EdgeChangeColor(q1, q2);//改变边颜色
				animationRecord(2, q1, q2);
			}
			int nodeID = que[i] + 64;//码制转换
			QByteArray a;
			a.resize(1);
			a[0] = nodeID;
			QString q;
			q = a.data();
			NodeChangeColor(q);//改变节点颜色
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
				EdgeChangeColor(q1, q2);//改变边颜色
				animationRecord(2, q1, q2);
			}
			int nodeID = que[i] + 64; //码制转换
			QByteArray a;
			a.resize(1);
			a[0] = nodeID;
			QString q;
			q = a.data();
			NodeChangeColor(q);//改变节点颜色
			animationRecord(1, q, NULL);
			previousNode = que[i];//记录之前节点
		}
	}
}
//prim 算法
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
	G->vexnum = nodes.count();//传入节点数量
	G->edgenum = edges.count();//传入边的数量
	for (auto edge : edges)
	{
		qDebug() << "frist node: " + edge->firstNode()->getId() + "last node: " +
			edge->lastNode()->getId();
		edge->setLabelText(edge->getId());
		edge->showLabel(true);

	}
	for (auto node : nodes)
	{
		qDebug() << " node: " + node->getId();
		//获取 ID 作为节点标签文字
		//设置文字显示到中央
		node->setSize(70, 70);
		node->setLabelText(node->getId());
		node->setLabelPosition(node->x() / 4096 - 10, node->y() / 4096 - 10);
		node->showLabel(true);
		//显示标签
	}
	int nodei = 0;
	for (auto node : nodes)
	{
		//转为 string 类型
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
		vw = edge->getId().toInt(); //边的权重需要是数字
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
			if (p->ivex == i) //判断相等才能知道连接上的是 ivex 还是 jvex;
			{
				cout << G.adjmulist[p->ivex].data << "---" << p->weight << "---" << G.adjmulist[p->jvex].data << endl;
					p = p->ilink;
			}
			else
			{
				cout << G.adjmulist[p->jvex].data << "---" << p->weight << "---" << G.adjmulist[p->ivex].data << endl;
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
	//将选择的第一个节点进入数组
	if (selectedNodes.isEmpty() == false)
	{
		v0 = selectedNodes.at(0)->getId().toStdString();//转为 string 类型
	}
	else //未选择节点就返回
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
	string predata = v0;//前一个节点
	NodeChangeColor(QString::fromStdString(predata));
	animationRecord(1, QString::fromStdString(predata), NULL);
	for (int i = 0; i < G.vexnum - 1; i++)
	{
		int min = INT_MAX;
		int minadj = -1;

		for (int j = 0; j < G.vexnum; j++)//遍历节点
		{
			if (close[j].lowcost != 0 && close[j].lowcost < min) {
				minadj = j;
				min = close[j].lowcost;
			}
		}
		//输出节点

		//输出边
		QList<CEdge*> edges = m_scene->getItems<CEdge>();
		for (auto edge : edges)
		{
			if (edge->getId() == QString::number(min) && edge->getAttribute("color") !=
				"#FF0000")
			{
				m_quickHelp->prim_code(1);
				EdgeChangeColor(edge->firstNode()->getId(),
					edge->lastNode()->getId());
				animationRecord(2, edge->firstNode()->getId(),
					edge->lastNode()->getId());
			}
		}
		m_quickHelp->prim_code(3);
		NodeChangeColor(QString::fromStdString(G.adjmulist[minadj].data));
		animationRecord(1, QString::fromStdString(G.adjmulist[minadj].data), NULL);
		close[minadj].lowcost = 0;
		for (int w = FirstAdjVex(G, minadj, wei); w >= 0; w = NextAdjVex(G, minadj, w, wei))
		{
			if (close[w].lowcost > wei) 
			{
				close[w].adjvex = minadj;
				close[w].lowcost = wei;
			}
		}
	}
}
void GraphUI::on_prim_btn_clicked() //注意：prim 算法需要设置边的权值
{
	m_nodeEditorUIController->clickButtonDisabled();
	AMLGraph g;
	CreateGraph(&g);
	PrintGraph(g);
	onlytotaltime = 0;
	MiniSpanTree_PRIM(g);
	m_nodeEditorUIController->clickButtonEnabled();
}
//Kruskal 算法
int GraphUI::FindSet(vector<int> uset, int i) {
	return uset[i] == i ? i : FindSet(uset, uset[i]);
}
void GraphUI::MiniSpanTree_Kruskal(AMLGraph G) {
	vector<Edge_Kruskal> edg;
	EBox *p;
	for (int i = 0; i < G.vexnum; i++)
	{
		p = G.adjmulist[i].firstedge;
		while (p != NULL)
		{
			if (p->ivex == i)
			{
				int i1 = LocateVex(G.adjmulist, G.vexnum, G.adjmulist[p->ivex].data);
				int i2 = LocateVex(G.adjmulist, G.vexnum, G.adjmulist[p->jvex].data);
				if (i1 < i2) {
					edg.push_back(Edge_Kruskal(i1, i2, p->weight));
				}
				p = p->ilink;
			}
			else
			{
				int i1 = LocateVex(G.adjmulist, G.vexnum, G.adjmulist[p->jvex].data);
				int i2 = LocateVex(G.adjmulist, G.vexnum, G.adjmulist[p->ivex].data);
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
		if (e1 != e2) 
		{
			m_quickHelp->Kruskal_code(4);
			//输出边
			QList<CEdge*> edges = m_scene->getItems<CEdge>();
			for (auto edge : edges)
			{ //
				if (edge->getId() == QString::number(edg[i].weight) &&
					edge->getAttribute("color") != "#FF0000")
				{
					m_quickHelp->Kruskal_code(1);
					EdgeChangeColor(edge->firstNode()->getId(),
						edge->lastNode()->getId());
					animationRecord(2, edge->firstNode()->getId(),
						edge->lastNode()->getId());
				}
			}
			if (G.adjmulist[edg[i].u].mark == unvisited)
			{
				m_quickHelp->Kruskal_code(4);
				NodeChangeColor(QString::fromStdString(G.adjmulist[edg[i].u].data));
				animationRecord(1, QString::fromStdString(G.adjmulist[edg[i].u].data), NULL);
				G.adjmulist[edg[i].u].mark = visited;
				m_quickHelp->Kruskal_code(3);
				NodeChangeColor(QString::fromStdString(G.adjmulist[edg[i].u].data));
				animationRecord(1, QString::fromStdString(G.adjmulist[edg[i].u].data), NULL);
				G.adjmulist[edg[i].u].mark = visited;
			}
			if (G.adjmulist[edg[i].v].mark == unvisited)
			{
				m_quickHelp->Kruskal_code(4);
				NodeChangeColor(QString::fromStdString(G.adjmulist[edg[i].v].data));
				animationRecord(1, QString::fromStdString(G.adjmulist[edg[i].v].data), NULL);
				G.adjmulist[edg[i].v].mark = visited;
				m_quickHelp->Kruskal_code(3);
				NodeChangeColor(QString::fromStdString(G.adjmulist[edg[i].v].data));
				animationRecord(1, QString::fromStdString(G.adjmulist[edg[i].v].data), NULL);
				G.adjmulist[edg[i].v].mark = visited;
			}
			uset[e2] = e1;
		}
	}
}
void GraphUI::on_kruskal_btn_clicked()
{
	m_nodeEditorUIController->clickButtonDisabled();
	AMLGraph g;
	CreateGraph(&g);
	onlytotaltime = 0;
	MiniSpanTree_Kruskal(g);
	m_nodeEditorUIController->clickButtonEnabled();
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
}
void GraphUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
}
void GraphUI::setCEditorView(CEditorView* editorView)
{
	m_editorView = editorView;
	setEnabled(m_editorView);
}
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
void GraphUI::on_outPut_btn_clicked()
{
	qDebug() << "OutPut Button had clicked";
}
