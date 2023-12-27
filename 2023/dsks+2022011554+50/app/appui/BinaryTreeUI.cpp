#include "BinaryTreeUI.h"
#include <QMessageBox>
BinaryTreeUI::BinaryTreeUI(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::BinaryTreeUI),
	m_scene(NULL)
{
	ui->setupUi(this);
	listshow = nullptr;
}
void BinaryTreeUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);
}
void BinaryTreeUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);
	m_scene = scene;
	setEnabled(m_scene);
	if (m_scene)
		onSceneAttached(m_scene);
}
void BinaryTreeUI::onSceneAttached(CEditorScene* scene)
{
}
void BinaryTreeUI::setCQuickHelpUI(CQuickHelpUI* quickHelp)
{
	m_quickHelp = quickHelp;
	setEnabled(m_quickHelp);
}
void BinaryTreeUI::setCEditorView(CEditorView* editorView)
{
	m_editorView = editorView;
	setEnabled(m_editorView);
}
BinaryTreeUI::~BinaryTreeUI()
{
}

void BinaryTreeUI::on_binarytree_create_btn_clicked()
{
	m_scene->clearScreen();//清屏
	//平衡二叉树
	//avlTree = new CBiTree();//新建树
	//斐波那契二叉树
	avlTree = new CFibonacciTree();//新建树

	QString data = ui->BinaryTreeDataEdit->text();
	avlTree->makeTree(data);
	root = avlTree->getRoot();//新建节点

	//开始显示序列
	string InOrd;
	PreOrderBiTree(root, InOrd);
	QString temp = "DLR:" + QString::fromStdString(InOrd);
	m_scene->printInOrd(100, -200, temp);
	string MidOrd;
	InOrderBiTree(root, MidOrd);
	temp = "LDR:" + QString::fromStdString(MidOrd);
	m_scene->printInOrd(100, -170, temp);
	string LasOrd;
	PostOrderBiTree(root, LasOrd);
	temp = "LRD:" + QString::fromStdString(LasOrd);
	m_scene->printInOrd(100, -140, temp);
	m_scene->clearScreen();//清屏
	drawNode(root, 0, 0, 1);
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
	timestamp = 0;
}

//以下是创建仿真二叉树
void BinaryTreeUI::on_binarytree_SimulationTree_creat_btn_clicked()
{
	m_scene->clearScreen();//清屏
	//avlTree = new CBiTree();//新建平衡二叉树
	avlTree = new CFibonacciTree();//新建斐波那契二叉树
	root = avlTree->getRoot();//新建节点
	QString data = ui->BinaryTreeDataEdit->text();
	list = data.split(",");
	list_array[1010];
	for (int i = 0; i < list.size(); ++i)
	{
		QString tmp = list.at(i);
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		list_array[i] = x;//将存为数组
	}
	for (int i = 0; i < list.size(); i++)
		root = avlTree->insert(root, list_array[i]);
	//开始显示序列
	string InOrd;
	PreOrderBiTree(root, InOrd);
	QString temp = "DLR:" + QString::fromStdString(InOrd);
	m_scene->printInOrd(100, -200, temp);
	string MidOrd;
	InOrderBiTree(root, MidOrd);
	temp = "LDR:" + QString::fromStdString(MidOrd);
	m_scene->printInOrd(100, -170, temp);
	string LasOrd;
	PostOrderBiTree(root, LasOrd);
	temp = "LRD:" + QString::fromStdString(LasOrd);
	m_scene->printInOrd(100, -140, temp);
	for (double i = 0; i <= 20; i = i + 0.1)
	{
		m_scene->clearScreen();//清屏
		inOrderPrint_SimulationTree(root, 0, 400, (i + 1) * 10, 90, 1 + i * 1.5, 0, 400);
		QTime time;
		time.start();
		while (time.elapsed() < 0.00005); //等待时间
		QCoreApplication::processEvents(); //处理事件
		//适应窗口
		m_editorView->fitToView();
		//适应网格
		m_scene->addUndoState();
	}
}
//二叉树节点删除函数
void BinaryTreeUI::on_binarytree_node_delete_btn_clicked()
{
	QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("不支持删除功能！"));
	return;

	QString data = ui->BinaryTreeDataEdit_2->text();
	bool flag;
	int x = data.toUInt(&flag);
	if (!flag)
		return;
	CBiTreeNode* node = avlTree->search(root, x);
	if (node != NULL)
		CBiTreeNode* dnode = avlTree->deleteNode(root, node);
	m_scene->clearScreen();//清屏
	//开始显示序列
	string InOrd;
	PreOrderBiTree(root, InOrd);
	QString temp = "DLR:" + QString::fromStdString(InOrd);
	m_scene->printInOrd(100, -200, temp);
	string MidOrd;
	InOrderBiTree(root, MidOrd);
	temp = "LDR:" + QString::fromStdString(MidOrd);
	m_scene->printInOrd(100, -170, temp);
	string LasOrd;
	PostOrderBiTree(root, LasOrd);
	temp = "LRD:" + QString::fromStdString(LasOrd);
	m_scene->printInOrd(100, -140, temp);
	//求二叉树的深度
	int depth = 0;
	DepthOfBiTree(root, depth);
	//求树的每层标准高度
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75)
	{
		highSize = 75;
	}
	//求树的最后一层间隔数量
	double wide = pow(2, depth) - 1;
	//求树的最后一层间隔宽度
	double wideSize = 9 * wide;
	onlytotaltime--;
	frametime[onlytotaltime] = 0;
	history_wideSize[onlytotaltime] = wideSize;
	history_highSize[onlytotaltime] = highSize;
	inOrderPrint(root, 0, 0, wideSize, highSize, 0, 0, onlytotaltime);
	m_scene->clearScreen();//清屏
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
}
//二叉树删除函数
void BinaryTreeUI::on_binarytree_delete_btn_clicked()
{
	list.clear();
	for (int i = 0; i < 1010; ++i)
	{
		list_array[i] = 0;
	}
	avlTree->destroy(root);
	m_scene->clearScreen();//清屏
}
//平衡二叉树节点查找函数
void BinaryTreeUI::on_binarytree_node_search_btn_clicked()
{
	QString data = ui->BinaryTreeDataEdit_2->text();
	bool flag;
	int x = data.toUInt(&flag);
	if (!flag)
		return;

	CBiTreeNode* node = avlTree->search(root, x);
	if (node == NULL)
		return;

	drawSearchNode(root, 0, 0, 1, node);
}

//平衡二叉树节点查找公共父节点函数
void BinaryTreeUI::on_binarytree_public_parentnode_search_btn_clicked()
{
	m_scene->clearScreen();//清屏
	//平衡二叉树
	//avlTree = new CBiTree();//新建树
	//斐波那契二叉树
	avlTree = new CFibonacciTree();//新建树

	QString data = ui->BinaryTreeDataEdit->text();
	QString dataInsert = ui->BinaryTreeDataEdit_2->text();
	avlTree->makeTree(data+","+ dataInsert);
	root = avlTree->getRoot();//新建节点

	//开始显示序列
	string InOrd;
	PreOrderBiTree(root, InOrd);
	QString temp = "DLR:" + QString::fromStdString(InOrd);
	m_scene->printInOrd(100, -200, temp);
	string MidOrd;
	InOrderBiTree(root, MidOrd);
	temp = "LDR:" + QString::fromStdString(MidOrd);
	m_scene->printInOrd(100, -170, temp);
	string LasOrd;
	PostOrderBiTree(root, LasOrd);
	temp = "LRD:" + QString::fromStdString(LasOrd);
	m_scene->printInOrd(100, -140, temp);
	m_scene->clearScreen();//清屏
	drawNode(root, 0, 0, 1);
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
	timestamp = 0;
}

void BinaryTreeUI::goToBeginButton()
{
	endplaybuttonflag = 1;
	timestamp = 0;
	m_scene->clearScreen();//清屏
	for (int j = 0; j <= frametime[0]; j++)
	{
		animationDraw(0, j);
	}
	m_quickHelp->btree_create_code(insertIdCode[timestamp]);
}
void BinaryTreeUI::stepBackButton()
{
	endplaybuttonflag = 1;
	if (timestamp > 0)
	{
		timestamp--;
		m_scene->clearScreen();//清屏
		for (int j = 0; j <= frametime[timestamp]; j++)
		{
			animationDraw(timestamp, j);
			m_quickHelp->btree_create_code(insertIdCode[j]);
		}
		m_quickHelp->btree_create_code(insertIdCode[timestamp]);
	}
}
void BinaryTreeUI::playButton()
{
	endplaybuttonflag = 0;
	for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1;
		timestamp++)
	{
		m_scene->clearScreen();//清屏
		for (int j = 0; j <= frametime[timestamp]; j++)
		{
			animationDraw(timestamp, j);
		}
		m_quickHelp->btree_create_code(insertIdCode[timestamp]);
		sleepTime(500);
	}
}
void BinaryTreeUI::suspendButton()
{
	endplaybuttonflag = 1;
}
void BinaryTreeUI::stepForwardButton()
{
	endplaybuttonflag = 1;
	if (timestamp < onlytotaltime)
	{
		timestamp++;
		m_scene->clearScreen();//清屏
		for (int j = 0; j <= frametime[timestamp]; j++)
		{
			animationDraw(timestamp, j);
		}
		m_quickHelp->btree_create_code(insertIdCode[timestamp]);
	}
}
void BinaryTreeUI::goToEndButton()
{
	endplaybuttonflag = 1;
	m_scene->clearScreen();//清屏
	timestamp = onlytotaltime;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	m_quickHelp->btree_create_code(insertIdCode[timestamp]);
}
void BinaryTreeUI::inOrderPrint(CBiTreeNode* root, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame)
{
	if (root == NULL)
		return;
	wideSize = wideSize / 2;//每次将单位值除以二，绘制在根节点的左右
	if (root->left != NULL)
	{
		frametime[frame]++;
		insertIdCode[frametime[frame]] = 2;
		animationRecord(onlytotaltime, frametime[frame], x, y, -2, -1, p_x, p_y);
		//访问左孩子
		inOrderPrint(root->left, x - wideSize, y + highSize, wideSize, highSize, x, y, frame);
	}
	if (root->right != NULL)
	{
		frametime[frame]++;
		insertIdCode[frametime[frame]] = 3;
		animationRecord(onlytotaltime, frametime[frame], x, y, -2, -1, p_x, p_y);
		//访问右孩子
		inOrderPrint(root->right, x + wideSize, y + highSize, wideSize, highSize, x, y,
			frame);
	}
	if (root != NULL)
	{
		frametime[frame]++;
		animationRecord(onlytotaltime, frametime[frame], x, y, root->key, -1, p_x, p_y);
		insertIdCode[frametime[frame]] = 1;
	}
}
void BinaryTreeUI::inOrderPrint_search(CBiTreeNode* root, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int data,
	int frame) {
	if (root == NULL)
		return;
	wideSize = wideSize / 2;//每次将单位值除以二，绘制在根节点的左右
	if (root != NULL)
	{
		if (root->key == data)//找过
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y, 1, 2);
			animationPrint(0, framesearchtime);
			return;
		}
		else if (data < root->key)//找过
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y, 1, 3);
			animationPrint(0, framesearchtime);
		}
		else if (data > root->key)//找过
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y, 1, 5);
			animationPrint(0, framesearchtime);
		}
	}
	if (root->left != NULL && data < root->key)
	{
		inOrderPrint_search(root->left, x - wideSize, y + highSize, wideSize, highSize, x,
			y, data, 1);
	}
	if (root->right != NULL && data > root->key)
	{
		inOrderPrint_search(root->right, x + wideSize, y + highSize, wideSize, highSize,
			x, y, data, 2);
	}
}
void BinaryTreeUI::inOrderPrint_SimulationTree(CBiTreeNode* root, double x,
	double y, double Branch_length, double Branch_angle, double Change_angle,
	double p_x, double p_y)//递归展示函数
{
	if (root == NULL)
		return;
	if (root->left != NULL)
	{
		double angle = Branch_angle + Change_angle;//逆时针角度
		double radian = angle * 3.14159265 / 180; //计算弧度
		double Branch_length_x = Branch_length * cos(radian);//x 位移
		double Branch_length_y = Branch_length * sin(radian);//y 位移
		inOrderPrint_SimulationTree(root->left, x + Branch_length_x,
			y - Branch_length_y, Branch_length * 0.8, angle, Change_angle, x, y);//左孩子
	}
	if (root->right != NULL)
	{
		double angle = Branch_angle - Change_angle + 2;//顺时针角度
		double radian = angle * 3.14159265 / 180; //计算弧度
		double Branch_length_x = Branch_length * cos(radian);//x 位移
		double Branch_length_y = Branch_length * sin(radian);//y 位移
		inOrderPrint_SimulationTree(root->right, x + Branch_length_x,
			y - Branch_length_y, Branch_length * 0.8, angle, Change_angle, x, y);//右孩子
	}
	//绘制当前节点
	if (root != NULL)
		m_scene->drawCircle_simulate(x, y, root->key, p_x, p_y);
}
void BinaryTreeUI::PreOrderBiTree(CBiTreeNode* root, string
	&In)//先序遍历
{
	if (root) {
		char inStr[10];
		itoa(root->key, inStr, 10);
		In += inStr;
		PreOrderBiTree(root->left, In);
		PreOrderBiTree(root->right, In);
	}
}
void BinaryTreeUI::InOrderBiTree(CBiTreeNode* root, string &In)
//中序遍历
{
	if (root) {
		InOrderBiTree(root->left, In);
		char inStr[10];
		itoa(root->key, inStr, 10);
		In += inStr;
		InOrderBiTree(root->right, In);
	}
}
void BinaryTreeUI::PostOrderBiTree(CBiTreeNode* root, string &In)
{
	if (root) {
		PostOrderBiTree(root->left, In);
		PostOrderBiTree(root->right, In);
		char inStr[10];
		itoa(root->key, inStr, 10);
		In += inStr;
	}
}
//获取树的高度
void BinaryTreeUI::DepthOfBiTree(CBiTreeNode* root, int &In)
{
	if (root) {
		DepthOfBiTree(root->left, In);
		DepthOfBiTree(root->right, In);
		if (root->height >= 0)
		{
			if (root->height >= In)
			{
				In = root->height;
			}
		}
	}
}
void BinaryTreeUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
}
void BinaryTreeUI::animationRecord(int totaltime, int frame, int x, int y, int
	data1, int data2, int p_x, int p_y)
{
	animation[totaltime][frame].x = x;
	animation[totaltime][frame].y = y;
	animation[totaltime][frame].data1 = data1;
	animation[totaltime][frame].data2 = data2;
	animation[totaltime][frame].p_x = p_x;
	animation[totaltime][frame].p_y = p_y;
}
void BinaryTreeUI::animationSearchRecord(int totaltime, int frame, int x, int y,
	int data1, int data2, int p_x, int p_y, int flag, int codeid)
{
	animationSearch[totaltime][frame].x = x;
	animationSearch[totaltime][frame].y = y;
	animationSearch[totaltime][frame].data1 = data1;
	animationSearch[totaltime][frame].data2 = data2;
	animationSearch[totaltime][frame].p_x = p_x;
	animationSearch[totaltime][frame].p_y = p_y;
	animationSearch[totaltime][frame].flag = flag;
	animationSearch[totaltime][frame].codeid = codeid;
}
void BinaryTreeUI::animationClean()
{
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			animation[i][j].x = 0;
			animation[i][j].y = 0;
			animation[i][j].data1 = 0;
			animation[i][j].data2 = 0;
			animation[i][j].p_x = 0;
			animation[i][j].p_y = 0;
		}
	}
}
void BinaryTreeUI::animationPrint(int totaltime, int frametime)
{
	qDebug() << "totaltime" << totaltime;
	qDebug() << "frametime" << frametime;
	int i = totaltime;
	int j = frametime;
	qDebug() << "animation[i].x " << animation[i][j].x;
	qDebug() << "animation[i].y " << animation[i][j].y;
	qDebug() << " animation[i].data1 " << animation[i][j].data1;
	qDebug() << " animation[i].data2 " << animation[i][j].data2;
	qDebug() << " animation[i].p_x " << animation[i][j].p_x;
	qDebug() << " animation[i].p_y " << animation[i][j].p_y;
}
void BinaryTreeUI::animationDraw(int totaltime, int frametime)
{
	for (int i = 0; i < frametime; i++) //遍历整个动画
	{
		if (animation[totaltime][frametime].data2 == -1) {
			m_scene->drawCircle(animation[totaltime][frametime].x,
				animation[totaltime][frametime].y,
				animation[totaltime][frametime].data1,
				animation[totaltime][frametime].p_x, animation[totaltime][frametime].p_y);
		}
		else if (animation[totaltime][frametime].data1 != -1) {
			m_scene->drawCircle2(animation[totaltime][frametime].x,
				animation[totaltime][frametime].y,
				animation[totaltime][frametime].data1, animation[totaltime][frametime].data2,
				animation[totaltime][frametime].p_x, animation[totaltime][frametime].p_y);
		}
	}
}
void BinaryTreeUI::animationDrawSearch(int totaltime, int frametime, int x)
{
	for (int i = 0; i < frametime; i++) //遍历整个动画
	{
		if (animationSearch[totaltime][frametime].data2 == -1)
		{
			m_scene->drawCircle_search(animationSearch[totaltime][frametime].x,
				animationSearch[totaltime][frametime].y, animationSearch[totaltime][frametime].data1,
				animationSearch[totaltime][frametime].p_x,
				animationSearch[totaltime][frametime].p_y, x);
		}
		else if (animation[totaltime][frametime].data1 != -1)
		{
			m_scene->drawCircle_search(animationSearch[totaltime][frametime].x,
				animationSearch[totaltime][frametime].y, animationSearch[totaltime][frametime].data1,
				animationSearch[totaltime][frametime].p_x,
				animationSearch[totaltime][frametime].p_y, x);
		}
	}
}

void BinaryTreeUI::drawActive(int totaltime, int frametime, int x)
{
	for (int i = 0; i < frametime; i++) //遍历整个动画
	{
		if (animationSearch[totaltime][frametime].data2 == -1)
		{
			m_scene->drawCircle_search2(animationSearch[totaltime][frametime].x,
				animationSearch[totaltime][frametime].y, animationSearch[totaltime][frametime].data1,
				animationSearch[totaltime][frametime].p_x,
				animationSearch[totaltime][frametime].p_y, x);
		}
		else if (animation[totaltime][frametime].data1 != -1)
		{
			m_scene->drawCircle_search2(animationSearch[totaltime][frametime].x,
				animationSearch[totaltime][frametime].y, animationSearch[totaltime][frametime].data1,
				animationSearch[totaltime][frametime].p_x,
				animationSearch[totaltime][frametime].p_y, x);
		}
	}
}

void BinaryTreeUI::drawNode(CBiTreeNode* root, int x, int y, int depth)
{
	const int height = 100;
	const int width = 200;
	if (root == nullptr)
		return;

	int w = width / (depth + 1);
	int h = height / depth * 0.8;	
	if (root->left != nullptr) {
		int x1 = x;
		int y1 = y;
		int x2 = x - w;
		int y2 = y + h;
		m_scene->drawLine(x1, y1, x2, y2);
		drawNode(root->left, x2, y2, depth + 1);
	}

	if (root->right != nullptr) {
		int x1 = x;
		int y1 = y;
		int x2 = x + w;
		int y2 = y + h;
		m_scene->drawLine(x1, y1, x2, y2);
		drawNode(root->right, x2, y2, depth + 1);
	}

	m_scene->drawCircle(x - 15, y - 15, root->key);
}

bool BinaryTreeUI::isParent(CBiTreeNode* root, CBiTreeNode* searchNode)
{
	if (root == searchNode)
		return true;

	CBiTreeNode* parent = searchNode->parent;
	while (parent) {
		if (parent == root) {
			return true;			
		}
		else {
			parent = parent->parent;
		}
	}

	return false;
}

void BinaryTreeUI::drawSearchNode(CBiTreeNode* root, int x, int y, int depth, CBiTreeNode* searchNode)
{
	const int height = 100;
	const int width = 200;
	if (root == nullptr)
		return;

	int w = width / (depth + 1);
	int h = height / depth * 0.8;
	if (root->left != nullptr) {
		int x1 = x;
		int y1 = y;
		int x2 = x - w;
		int y2 = y + h;
		if (isParent(root->left, searchNode))
			m_scene->drawLine(x1, y1, x2, y2, QColor(255, 69, 0));
		else
			m_scene->drawLine(x1, y1, x2, y2, QColor(100, 149, 237));
		drawSearchNode(root->left, x2, y2, depth + 1, searchNode);
	}

	if (root->right != nullptr) {
		int x1 = x;
		int y1 = y;
		int x2 = x + w;
		int y2 = y + h;
		if (isParent(root->right, searchNode))
			m_scene->drawLine(x1, y1, x2, y2, QColor(255, 69, 0));
		else
			m_scene->drawLine(x1, y1, x2, y2, QColor(100, 149, 237));
		drawSearchNode(root->right, x2, y2, depth + 1, searchNode);
	}

	if (isParent(root, searchNode))
		m_scene->drawCircle(x - 15, y - 15, root->key, QColor(255, 69, 0));
	else
		m_scene->drawCircle(x - 15, y - 15, root->key, QColor(100, 149, 237));
}