#pragma once
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
CBiTreeNode* CBiTree::search(CBiTreeNode* root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	if (key < root->key)
		search(root->left, key);
	else search(root->right, key);
}
CBiTreeNode* CBiTree::insert(CBiTreeNode* root, int key)
{
	if (root == NULL)
		root = new CBiTreeNode(key, NULL, NULL);
	else if (key < root->key) //����������  
	{
		root->left = insert(root->left, key);
		if (height(root->left) - height(root->right) == 2) //�������������ʧ��  
		{
			if (key < root->left->key)
				root = leftLeftRotate(root);
			else root = leftRightRotate(root);
		}
	}
	else if (key > root->key) //����������  
	{
		root->right = insert(root->right, key);
		if (height(root->right) - height(root->left) == 2) //���뵼�¶�����ʧ��  
		{
			if (key > root->right->key)
				root = rightRightRotate(root);
			else root = rightLeftRotate(root);
		}
	}
	root->height = max(height(root->left), height(root->right)) + 1;
	return root;
}
CBiTreeNode* CBiTree::deleteNode(CBiTreeNode* root, CBiTreeNode* node)
{
	if (root == NULL)
		return NULL;
	if (node->key < root->key) //Ҫɾ���Ľ����������  
	{
		root->left = deleteNode(root->left, node);
		if (height(root->right) - height(root->left) == 2) //ɾ�����¶�����ʧ��  
		{
			CBiTreeNode* rightNode = root->right;
			if (height(rightNode->left) > height(rightNode->right))
				root = rightLeftRotate(root);
			else root = rightRightRotate(root);
		}
	}
	else if (node->key > root->key) //Ҫɾ���Ľ����������  
	{
		root->right = deleteNode(root->right, node);
		if (height(root->left) - height(root->right) == 2) //ɾ�����¶�����ʧ��  
		{
			CBiTreeNode* leftNode = root->left;
			if (height(leftNode->left) > height(leftNode->right))
				root = leftLeftRotate(root);
			else root = leftRightRotate(root);
		}
	}
	else //�ҵ���Ҫɾ���Ľ��  
	{ //����������������Ϊ��
		if (root->left != NULL && root->right != NULL)
		{
			if (height(root->left) > height(root->right))
			{
				CBiTreeNode* maxNode = maximus(root->left);
				root->key = maxNode->key;
				root->left = deleteNode(root->left, maxNode);
			}
			else
			{
				CBiTreeNode* minNode = minimus(root->right);
				root->key = minNode->key;
				root->right = deleteNode(root->right, minNode);
			}
		}
		else
		{
			CBiTreeNode* tmp = root;
			root = (root->left != NULL) ? root->left : root->right;
			delete tmp;
		}
	}
	return root;
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

//�����Ǵ������������ 
void BinaryTreeUI::on_binarytree_SimulationTree_creat_btn_clicked()
{
	m_scene->clearScreen();//���� 
	avlTree = new CBiTree();//�½��� 
	root = avlTree->getRoot();//�½��ڵ� 
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
		list_array[i] = x;//����Ϊ���� 
	}
	for (int i = 0; i < list.size(); i++)
		root = avlTree->insert(root, list_array[i]);
	//��ʼ��ʾ���� 
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
		m_scene->clearScreen();//���� 
		inOrderPrint_SimulationTree(root, 0, 400, (i + 1) * 10, 90, 1 + i * 1.5, 0, 400);

		QTime time;
		time.start();
		while (time.elapsed() < 0.00005); //�ȴ�ʱ�� 
		QCoreApplication::processEvents(); //�����¼� 
		//��Ӧ���� 
		m_editorView->fitToView();
		//��Ӧ���� 
		m_scene->addUndoState();
	}
}

void BinaryTreeUI::on_binarytree_delete_btn_clicked()
{
	list.clear();
	for (int i = 0; i < 1010; ++i)
	{
		list_array[i] = 0;
	}
	avlTree->destroy(root);
	m_scene->clearScreen();//���� 
}

void BinaryTreeUI::goToBeginButton()
{
	endplaybuttonflag = 1;
	timestamp = 0;
	m_scene->clearScreen();//���� 
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
		m_scene->clearScreen();//���� 
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
		m_scene->clearScreen();//���� 

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
		m_scene->clearScreen();//���� 
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
	m_scene->clearScreen();//���� 
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
	wideSize = wideSize / 2;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������ 
	if (root->left != NULL)
	{
		frametime[frame]++;
		insertIdCode[frametime[frame]] = 2;
		animationRecord(onlytotaltime, frametime[frame], x, y, -2, -1, p_x, p_y);
		//�������� 
		inOrderPrint(root->left, x - wideSize, y + highSize, wideSize, highSize, x, y, frame);
	}
	if (root->right != NULL)
	{
		frametime[frame]++;
		insertIdCode[frametime[frame]] = 3;
		animationRecord(onlytotaltime, frametime[frame], x, y, -2, -1, p_x, p_y);
		//�����Һ��� 
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

bool BinaryTreeUI::inOrderPrint_search(CBiTreeNode* root, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int data, int
	frame) {
	if (root == NULL)
		return false;
	wideSize = wideSize / 2;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������ 
	if (root != NULL)
	{

		if (root->key == data)//�ҹ� 
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y, 1, 2);
			animationPrint(0, framesearchtime);
			return true;
		}
		else if (data < root->key)//�ҹ� 
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y, 1, 3);
			animationPrint(0, framesearchtime);
		}
		else if (data > root->key)//�ҹ� 
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y, 1, 5);
			animationPrint(0, framesearchtime);
		}
	}
	if (root->left != NULL && data < root->key)
	{
		return inOrderPrint_search(root->left, x - wideSize, y + highSize, wideSize, highSize, x,
			y, data, 1);
	}
	if (root->right != NULL && data > root->key)
	{
		return inOrderPrint_search(root->right, x + wideSize, y + highSize, wideSize, highSize,
			x, y, data, 2);
	}

	return false;
}

void BinaryTreeUI::inOrderPrint_SimulationTree(CBiTreeNode* root, double x,
	double y, double Branch_length, double Branch_angle, double Change_angle,
	double p_x, double p_y)//�ݹ�չʾ���� 
{
	if (root == NULL)
		return;
	if (root->left != NULL)
	{
		double angle = Branch_angle + Change_angle;//��ʱ��Ƕ� 

		double radian = angle * 3.14159265 / 180; //���㻡�� 
		double Branch_length_x = Branch_length * cos(radian);//xλ�� 
		double Branch_length_y = Branch_length * sin(radian);//yλ��
		inOrderPrint_SimulationTree(root->left, x + Branch_length_x,
			y - Branch_length_y, Branch_length * 0.8, angle, Change_angle, x, y);//���� 
	}
	if (root->right != NULL)
	{
		double angle = Branch_angle - Change_angle + 2;//˳ʱ��Ƕ� 

		double radian = angle * 3.14159265 / 180; //���㻡�� 
		double Branch_length_x = Branch_length * cos(radian);//xλ�� 
		double Branch_length_y = Branch_length * sin(radian);//yλ�� 
		inOrderPrint_SimulationTree(root->right, x + Branch_length_x,
			y - Branch_length_y, Branch_length * 0.8, angle, Change_angle, x, y);//�Һ��� 
	}
	//���Ƶ�ǰ�ڵ� 
	if (root != NULL)
		m_scene->drawCircle_simulate(x, y, root->key, p_x, p_y);
}
void BinaryTreeUI::PreOrderBiTree(CBiTreeNode* root, string
	&In)//������� 
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
//������� 
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
//��ȡ���ĸ߶� 
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
	for (int i = 0; i < frametime; i++)  //������������ 
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
	for (int i = 0; i < frametime; i++)  //������������ 
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

void BinaryTreeUI::on_binarytree_create_btn_clicked()
{
	m_scene->clearScreen();//����
	//ƽ�������
	avlTree = new CBiTree();//�½���

	QString data = ui->BinaryTreeDataEdit->text();
	avlTree->makeTree(data);
	root = avlTree->getRoot();//�½��ڵ�

	//��ʼ��ʾ����
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
	m_scene->clearScreen();//����
	drawNode(root, 0, 0, 1);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
	timestamp = 0;

	//m_scene->clearScreen();//���� 
	//avlTree = new CBiTree();//�½��� 
	//root = avlTree->getRoot();//�½��ڵ� 
	//QString data = ui->BinaryTreeDataEdit->text();
	//list = data.split(",");
	//list_array[1010];
	//for (int i = 0; i < list.size(); ++i) {
	//	QString tmp = list.at(i);
	//	bool flag;
	//	int x = tmp.toUInt(&flag);
	//	if (!flag)
	//		return;
	//	list_array[i] = x;//��Ϊ���� 
	//}
	//for (int i = 0; i < list.size(); i++)
	//{
	//	root = avlTree->insert(root, list_array[i]);

	//	//������������ 
	//	int depth = 0;
	//	DepthOfBiTree(root, depth);
	//	//������ÿ���׼�߶� 
	//	double highSize = 2400 * 0.618 / (double)depth;
	//	if (highSize > 75)
	//	{
	//		highSize = 75;
	//	}
	//	//���������һ�������� 
	//	double wide = pow(2, depth) - 1;
	//	//���������һ������� 
	//	double wideSize = 9 * wide;

	//	frametime[i] = 0;
	//	onlytotaltime = i;
	//	history_wideSize[i] = wideSize;
	//	history_highSize[i] = highSize;

	//	//insertIdCode[i] = codeid; 
	//	//�ݹ�չʾ������ ��λ���Ϊ 15 ������ 
	//	inOrderPrint(root, 0, 0, wideSize, highSize, 0, 0, i);
	//}

	////��ʼ��ʾ���� 
	//string InOrd;
	//PreOrderBiTree(root, InOrd);
	//QString temp = "DLR:" + QString::fromStdString(InOrd);
	//m_scene->printInOrd(100, -200, temp);
	//string MidOrd;
	//InOrderBiTree(root, MidOrd);
	//temp = "LDR:" + QString::fromStdString(MidOrd);
	//m_scene->printInOrd(100, -170, temp);
	//string LasOrd;
	//PostOrderBiTree(root, LasOrd);
	//temp = "LRD:" + QString::fromStdString(LasOrd);
	//m_scene->printInOrd(100, -140, temp);
	//m_scene->clearScreen();//���� 
	//for (int j = 0; j <= frametime[onlytotaltime]; j++)
	//{
	//	animationDraw(onlytotaltime, j);
	//}
	//m_quickHelp->btree_create_code(insertIdCode[frametime[onlytotaltime]]);
	////��Ӧ���� 
	//m_editorView->fitToView();
	////��Ӧ����
	//m_scene->addUndoState();
	//timestamp = 0;
}

void BinaryTreeUI::drawNode(CBiTreeNode* root, int x, int y, int depth)
{
	const int height = 100;
	const int width = 200;
	if (root == nullptr)
		return;

	//�Ȼ����ҽڵ㣬�ٻ��Լ�
	int w = qMax(30, width - depth * 50);// tw / (2 * depth + 1);
	int h = height * depth * 0.8;
	if (root->left != nullptr) {
		int x1 = x;
		int y1 = y;
		int x2 = x - w;
		int y2 = y + h;
		m_scene->drawLine(x1, y1, x2, y2);
		drawNode(root->left, x2, y2, depth + 1);
	}

	//���ҽڵ�
	if (root->right != nullptr) {
		int x1 = x;
		int y1 = y;
		int x2 = x + w;
		int y2 = y + h;
		m_scene->drawLine(x1, y1, x2, y2);
		drawNode(root->right, x2, y2, depth + 1);
	}

	//���Լ�
	m_scene->drawCircle(x - 15, y - 15, root->key);

	//const int height = 100;
	//const int width = 200;
	//if (root == nullptr)
	//	return;

	////�Ȼ����ҽڵ㣬�ٻ��Լ�
	//int w = width / (depth + 1);
	//int h = height / depth * 0.8;
	//if (root->left != nullptr) {
	//	int x1 = x;
	//	int y1 = y;
	//	int x2 = x - w;
	//	int y2 = y + h;
	//	m_scene->drawLine(x1, y1, x2, y2);
	//	drawNode(root->left, x2, y2, depth + 1);
	//}

	////���ҽڵ�
	//if (root->right != nullptr) {
	//	int x1 = x;
	//	int y1 = y;
	//	int x2 = x + w;
	//	int y2 = y + h;
	//	m_scene->drawLine(x1, y1, x2, y2);
	//	drawNode(root->right, x2, y2, depth + 1);
	//}

	////���Լ�
	//m_scene->drawCircle(x - 15, y - 15, root->key);
}

void BinaryTreeUI::on_binarytree_node_delete_btn_clicked()
{
	QString data = ui->BinaryTreeDataEdit_2->text();
	bool flag;
	int x = data.toUInt(&flag);
	if (!flag)
		return;
	CBiTreeNode* node = avlTree->search(root, x);
	if (node != NULL)
		CBiTreeNode* dnode = avlTree->deleteNode(root, node);
	m_scene->clearScreen();//���� 
	//��ʼ��ʾ���� 
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
	//������������ 
	int depth = 0;
	DepthOfBiTree(root, depth);
	//������ÿ���׼�߶� 
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75)
	{
		highSize = 75;
	}
	//���������һ�������� 
	double wide = pow(2, depth) - 1;
	//���������һ������� 
	double wideSize = 9 * wide;

	onlytotaltime--;
	frametime[onlytotaltime] = 0;
	history_wideSize[onlytotaltime] = wideSize;
	history_highSize[onlytotaltime] = highSize;

	inOrderPrint(root, 0, 0, wideSize, highSize, 0, 0, onlytotaltime);
	m_scene->clearScreen();//���� 
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	//��Ӧ���� 
	m_editorView->fitToView();
	//��Ӧ���� 
	m_scene->addUndoState();
}

void BinaryTreeUI::searchChild(std::vector<CBiTreeNode*> parents) 
{
	std::vector<CBiTreeNode*> nodes;	

	for (auto parent : parents) {
		if (parent->left)
			nodes.push_back(parent->left);
		if (parent->right)
			nodes.push_back(parent->right);
	}
	
	if (nodes.size() > 0) {
		nodesLevel.push_back(nodes);
		searchChild(nodes);
	}
}

void BinaryTreeUI::on_binarytree_node_search_btn_clicked()
{
	//if (0) {
	//	QString data = ui->BinaryTreeDataEdit_2->text();
	//	bool flag;
	//	int x = data.toUInt(&flag);
	//	if (!flag)
	//		return;
	//	m_scene->clearScreen();//���� 
	//	//��ʼ��ʾ���� 
	//	string InOrd;
	//	PreOrderBiTree(root, InOrd);
	//	QString temp = "DLR:" + QString::fromStdString(InOrd);
	//	m_scene->printInOrd(100, -200, temp);
	//	string MidOrd;
	//	InOrderBiTree(root, MidOrd);
	//	temp = "LDR:" + QString::fromStdString(MidOrd);
	//	m_scene->printInOrd(100, -170, temp);
	//	string LasOrd;
	//	PostOrderBiTree(root, LasOrd);
	//	temp = "LRD:" + QString::fromStdString(LasOrd);
	//	m_scene->printInOrd(100, -140, temp);
	//	//������������ 
	//	int depth = 0;
	//	DepthOfBiTree(root, depth);
	//	//������ÿ���׼�߶� 
	//	double highSize = 2400 * 0.618 / (double)depth;
	//	if (highSize > 75) {
	//		highSize = 75;
	//	}
	//	//���������һ�������� 
	//	double wide = pow(2, depth) - 1;
	//	//���������һ������� 
	//	double wideSize = 9 * wide;
	//	framesearchtime = 0;
	//	//onlytotaltime = 0; 
	//	history_wideSize[0] = wideSize;
	//	history_highSize[0] = highSize;
	//	//�ݹ�չʾ������ ��λ���Ϊ 15 ������ 
	//	bool find = inOrderPrint_search(root, 0, 0, wideSize, highSize, 0, 0, x, 0);
	//	m_scene->clearScreen();//���� 
	//	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	//	{
	//		animationDraw(onlytotaltime, j);
	//	}
	//	//��Ӧ���� 
	//	m_editorView->fitToView();
	//	//��Ӧ���� 
	//	m_scene->addUndoState();

	//	for (int j = 0; j <= framesearchtime; j++)
	//	{
	//		animationDrawSearch(0, j, x);
	//		sleepTime(500);
	//	}
	//	timestamp = 0;
	//	return;
	//}

	QString data = ui->BinaryTreeDataEdit_2->text();
	bool flag;
	int key = data.toUInt(&flag);
	if (!flag)
		return;

	CBiTreeNode* node = avlTree->search(root, key);
	if (node == NULL)
		return;

	m_scene->clearScreen();
	drawSearchNode(root, 0, 0, 1, node);
	m_editorView->fitToView();
	m_scene->addUndoState();

	nodeLevelValie.clear();
	nodeLevelInvalid.clear();
	nodesLevel.clear();//��¼ÿһ��ڵ�
	CBiTreeNode* nodeSearch = root;
	if (nodeSearch) {
		std::vector<CBiTreeNode*> nodes;
		nodes.push_back(nodeSearch);
		nodesLevel.push_back(nodes);

		searchChild(nodes);
	}

	//����ÿһ����Ч�ڵ����
	int nodes_count = 0;
	int null_nodes_count = 0;
	int current_null_nodes_count = 0;
	float search_success_length = 0;
	float search_fail_length = 0;
	int parent_node_count = 0;
	for (int i=0; i<nodesLevel.size(); i++){
		std::vector<CBiTreeNode*> nodes = nodesLevel[i];
		nodes_count += nodes.size();

		search_success_length += (i + 1) * nodes.size();
		
		if (i > 0) {
			parent_node_count = nodesLevel[i - 1].size();
			current_null_nodes_count = 2 * parent_node_count - nodes.size();
			search_fail_length += (i * current_null_nodes_count);
			null_nodes_count += current_null_nodes_count;
		}
	}

	int i = nodesLevel.size() - 1;
	if (i > 0)
	{
		parent_node_count = nodesLevel[i].size();
		std::vector<CBiTreeNode*> nodes = nodesLevel[i];
		current_null_nodes_count = 2 * parent_node_count;
		search_fail_length += (i+1) * current_null_nodes_count;
		null_nodes_count += current_null_nodes_count;
	}

	search_success_length = search_success_length / nodes_count;
	search_fail_length = search_fail_length / null_nodes_count;
	if (find)
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("���ҳɹ���ƽ�����ҳ��ȣ�%1").arg(search_success_length));
	else
		QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("����ʧ��"));
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

	int w = qMax(30, width - depth * 50);// tw / (2 * depth + 1);
	int h = height * depth * 0.8;
	if (root->key == searchNode->key) {

	}
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