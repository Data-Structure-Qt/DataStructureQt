#include "BinaryTreeUI.h"
void BinaryTreeUI::on_RBTree_delete_btn_clicked()
{
	list.clear();
	for (int i = 0; i < 1010; ++i)
	{
		list_array[i] = 0;
	}
	rbTree->~RBTree();
	m_scene->clearScreen();//����
	ui->BinaryTreeDataEdit->clear();
	ui->BinaryTreeDataEdit_2->clear();
}

void BinaryTreeUI::on_RBTree_create_btn_clicked()
{
	m_scene->clearScreen();//����
	rbTree = new RBTree();//�½������
	rbTree->m_scene_copy = m_scene;//����һ��m_scene�������
	Root = rbTree->getRoot();//�õ���������ڵ�
	QString data = ui->BinaryTreeDataEdit->text();
	list = data.split(",");
	list_array[1010];
	for (int i = 0; i < list.size(); ++i) {
		QString tmp = list.at(i);
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag) {
			QMessageBox::information(this,"Error", "Worng input format! Please type again");
			ui->BinaryTreeDataEdit->clear();
			return;//��������������ݵ������������Υ���ͷ���
		}
		list_array[i] = x;//��Ϊ����
	}
	for (int i = 0; i < list.size(); i++) {
		rbTree->Insert(list_array[i],i);
		Root = rbTree->getRoot();
		//������������
		int depth = 0;
		depth = rbTree->getHeight();
		//������ÿ���׼�߶�
		double highSize = 2400 * 0.618 / (double)depth;
		if (highSize > 75) {
			highSize = 75;
		}
		//���������һ��������
		double wide = pow(2, depth) - 1;
		//���������һ�������
		double wideSize = 9 * wide;
		frametime[i] = 0;
		onlytotaltime = i;
		history_wideSize[i] = wideSize;
		history_highSize[i] = highSize;
		//insertIdCode[i]=codeid;
		//�ݹ�չʾ������ ��λ���Ϊ15������
		RBTNode* Nil = rbTree->getNil();
		inOrderPrint(Root, Nil, 0, 0, wideSize, highSize, 0, 0, i);
	}
	/*QString str=QString::number(Root->right->right->key);
	m_scene->printInOrd(100, -200, str); *///��ӡframetime���Ը��ٹ۲�
	//��ʼ��ʾ
	int i = 0;
	int k = 0;
	rbTree->cnt = 0;
	for (int j = 0; j <= onlytotaltime; j++) {
		//��Ϊonlytotaltime��counttime��ͬ���Կ���ֱ��ʹ��
		m_scene->clearScreen();//����
		animationDraw_RBT_insert(j, frametime[j]);
		QString str = "Insert new node";
		m_scene->printInOrd(100, -200, str);
		sleepTime(2000);
		/*for (; k <= rbTree->number; k++) {
			m_scene->printInOrd(100, -200, rbTree->str[k]);
			sleepTime(2000);
			m_scene->clearScreen();
			if (k == rbTree->number) {
				break;
			}
			if (k == rbTree->countnumber[rbTree->cnt]) {
				break;
			}
		}*/
		for (; i <= rbTree->countfixup; i++) {
			if (i == rbTree->countnumber[rbTree->cnt]) {
				m_scene->clearScreen();//����
				animationDraw_RBT_insertfixup(i, rbTree->fixuptime[i]);
				break;
			}
			if (i == rbTree->countfixup) {
				break;
			}
		}
		for (; k <= rbTree->countfixup; k++) {
			m_scene->printInOrd(100, -200, rbTree->str[k]);
			sleepTime(1000);
			m_scene->clearTextItems();
			if (k == rbTree->countnumber[rbTree->cnt]) {
				rbTree->cnt++;
				break;
			}
			if (k == rbTree->countfixup) {
				break;
			}
		}
		//m_scene->clearScreen();//����
		//animationDraw_RBT(j, frametime[j]);
		//sleepTime(2000);
	}
	m_quickHelp->btree_create_code(insertIdCode[frametime[onlytotaltime]]);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
	timestamp = 0;
}

void BinaryTreeUI::on_RBTree_node_search_btn_clicked()
{
	QString data = ui->BinaryTreeDataEdit_2->text();
	bool flag;
	int x = data.toUInt(&flag);
	if (!flag) {
		QMessageBox::information(this, "Error", "Input Number More Than One");
		return;
	}
	m_scene->clearScreen();//����
	//��ʼ��ʾ����
	/*string InOrd;
	PreOrderBiTree(Root, InOrd);
	QString temp = "DLR:" + QString::fromStdString(InOrd);
	m_scene->printInOrd(100, -200, temp);
	string MidOrd;
	InOrderBiTree(root, MidOrd);
	temp = "LDR:" + QString::fromStdString(MidOrd);
	m_scene->printInOrd(100, -170, temp);
	string LasOrd;
	PostOrderBiTree(root, LasOrd);
	temp = "LRD:" + QString::fromStdString(LasOrd);
	m_scene->printInOrd(100, -140, temp);*/
	//������������
	int depth = 0;
	depth=rbTree->getHeight();
	//������ÿ���׼�߶�
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75) {
		highSize = 75;
	}
	//���������һ��������
	double wide = pow(2, depth) - 1;
	//���������һ�������
	double wideSize = 9 * wide;
	framesearchtime = 0;
	//onlytotaltime = 0;
	history_wideSize[0] = wideSize;
	history_highSize[0] = highSize;
	//�ݹ�չʾ������ ��λ���Ϊ 15 ������
	RBTNode* Nil = rbTree->getNil();
	inOrderPrint_search(Root, Nil, 0, 0, wideSize, highSize, 0, 0, x, 0);
	m_scene->clearScreen();//����
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw_RBT(onlytotaltime, j);
	}
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
	for (int j = 0; j <= framesearchtime; j++)
	{
		animationDrawSearch(0, j, x);
		sleepTime(500);
	}
	timestamp = 0;
	RBTNode* node = rbTree->Search(x);
	if (node == Nil) {
		QMessageBox::information(this, "Notation", "Data Not Find!");
		return;
	}
}

void BinaryTreeUI::on_RBTree_node_delete_btn_clicked()
{
	QString data = ui->BinaryTreeDataEdit_2->text();
	bool flag;
	int x = data.toUInt(&flag);
	if (!flag){
		QMessageBox::information(this, "Error", "Worng input format! Please type again");
		return;
	}
	RBTNode* node = rbTree->Search(x);
	RBTNode* Nil = rbTree->getNil();
	if (node != Nil)
		 rbTree->Remove(x);
	if (node == Nil) {
		QMessageBox::warning(this, "Error", "Data Not Find!");
		return;
	}
	//m_scene->clearScreen();//����
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
	//������������
	int depth = 0;
	depth = rbTree->getHeight();
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
	onlytotaltime++;
	frametime[onlytotaltime] = 0;
	history_wideSize[onlytotaltime] = wideSize;
	history_highSize[onlytotaltime] = highSize;
	Root = rbTree->getRoot();
	inOrderPrint(Root, Nil, 0, 0, wideSize, highSize, 0, 0, onlytotaltime);
	QString q = "Already Is A Red Black Tree";
	if (rbTree->Dnumber == 0) {
		m_scene->clearTextItems();
		m_scene->printInOrd(90, -200, q);
	}
	for (int i = 0; i <= rbTree->Dnumber; i++) {
		m_scene->clearScreen();
		animationDraw_RBT_removefixup(i, rbTree->removetime[i]);
		m_scene->printInOrd(90, -200, rbTree->str1[i]);
		sleepTime(2000);
	}
	animationDraw_RBT(onlytotaltime, frametime[onlytotaltime]);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
}

void BinaryTreeUI::inOrderPrint(RBTNode* root, RBTNode* Nil, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame)
{
	if (root == Nil)
		return;
	wideSize = wideSize / 2;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (root->left != Nil) 
	{
		int color;
		if (root->left->color == BLACK)
			color = 0;
		else
			color = 1;
		frametime[frame]++;
		insertIdCode[frametime[frame]] = 2;
		animationRecord(onlytotaltime, frametime[frame], x, y, root->left->key, -1, p_x, p_y, color);
		//��������
		inOrderPrint(root->left, Nil, x - wideSize, y + highSize, wideSize, highSize, x, y, frame);
	}
	if (root->right != Nil)
	{
		int color;
		if (root->right->color == BLACK)
			color = 0;
		else
			color = 1;
		frametime[frame]++;
		insertIdCode[frametime[frame]] = 3;
		animationRecord(onlytotaltime, frametime[frame], x, y, root->right->key, -1, p_x, p_y, color);
		//�����Һ���
		inOrderPrint(root->right, Nil, x + wideSize, y + highSize, wideSize, highSize, x, y,
			frame);
	}
	if (root != Nil)
	{
		int color;
		if (root->color == BLACK)
			color = 0;
		else
			color = 1;
		frametime[frame]++;
		animationRecord(onlytotaltime, frametime[frame], x, y, root->key, -1, p_x, p_y,color);
		insertIdCode[frametime[frame]] = 1;
	}
}


void BinaryTreeUI::inOrderPrint_search(RBTNode* root, RBTNode* Nil, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int data,
	int frame) {
	if (root == Nil)
		return;
	wideSize = wideSize / 2;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (root != Nil)
	{
		if (root->key == data)//��¼�ҵ�
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y, 1, 2);
			animationPrint(0, framesearchtime);
			return;
		}
		else if (data < root->key)//��¼�ҹ�
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y, 1, 3);
			animationPrint(0, framesearchtime);
		}
		else if (data > root->key)//��¼�ҹ�
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x, p_y, 1, 5);
			animationPrint(0, framesearchtime);
		}
	}
	if (root->left != Nil && data < root->key)
	{
		inOrderPrint_search(root->left, Nil, x - wideSize, y + highSize, wideSize, highSize, x,
			y, data, 1);
	}
	if (root->right != Nil && data > root->key)
	{
		inOrderPrint_search(root->right, Nil, x + wideSize, y + highSize, wideSize, highSize,
			x, y, data, 2);
	}
}


void BinaryTreeUI::animationDraw_RBT(int totaltime, int frametime)
{
	for (int i = 1; i <= frametime; i++) //������������
	{
		if (animation[totaltime][i].data2 == -1) {
			m_scene->drawCircle(animation[totaltime][i].x,
				animation[totaltime][i].y,
				animation[totaltime][i].data1,
				animation[totaltime][i].p_x, animation[totaltime][i].p_y, animation[totaltime][i].color);
		}
		else if (animation[totaltime][i].data1 != -1) {
			m_scene->drawCircle2(animation[totaltime][i].x,
				animation[totaltime][i].y,
				animation[totaltime][i].data1, animation[totaltime][i].data2,
				animation[totaltime][i].p_x, animation[totaltime][i].p_y, animation[totaltime][i].color);
		}
	}
}


void BinaryTreeUI::animationRecord(int totaltime, int frame, int x, int y, int
	data1, int data2, int p_x, int p_y, int color)
{
	animation[totaltime][frame].x = x;
	animation[totaltime][frame].y = y;
	animation[totaltime][frame].data1 = data1;
	animation[totaltime][frame].data2 = data2;
	animation[totaltime][frame].p_x = p_x;
	animation[totaltime][frame].p_y = p_y;
	animation[totaltime][frame].color=color;
}

void BinaryTreeUI::animationDraw_RBT_insert(int totaltime, int frametime)
{
	for (int i = 1; i <= frametime; i++) //������������
	{
		if (rbTree->animationInsert[totaltime][i].data2 == -1) {
			m_scene->drawCircle(rbTree->animationInsert[totaltime][i].x,
				rbTree->animationInsert[totaltime][i].y,
				rbTree->animationInsert[totaltime][i].data1,
				rbTree->animationInsert[totaltime][i].p_x, rbTree->animationInsert[totaltime][i].p_y, rbTree->animationInsert[totaltime][i].color);
		}
		else if (rbTree->animationInsert[totaltime][i].data1 != -1) {
			m_scene->drawCircle2(rbTree->animationInsert[totaltime][i].x,
				rbTree->animationInsert[totaltime][i].y,
				rbTree->animationInsert[totaltime][i].data1, rbTree->animationInsert[totaltime][i].data2,
				rbTree->animationInsert[totaltime][i].p_x, rbTree->animationInsert[totaltime][i].p_y, rbTree->animationInsert[totaltime][i].color);
		}
	}
}


void BinaryTreeUI::animationDraw_RBT_insertfixup(int totaltime, int frametime)
{
	for (int i = 1; i <= frametime; i++) //������������
	{
		if (rbTree->animation1[totaltime][i].data2 == -1) {
			m_scene->drawCircle(rbTree->animation1[totaltime][i].x,
				rbTree->animation1[totaltime][i].y,
				rbTree->animation1[totaltime][i].data1,
				rbTree->animation1[totaltime][i].p_x, rbTree->animation1[totaltime][i].p_y, rbTree->animation1[totaltime][i].color);
		}
		else if (rbTree->animation1[totaltime][i].data1 != -1) {
			m_scene->drawCircle2(rbTree->animation1[totaltime][i].x,
				rbTree->animation1[totaltime][i].y,
				rbTree->animation1[totaltime][i].data1, rbTree->animation1[totaltime][i].data2,
				rbTree->animation1[totaltime][i].p_x, rbTree->animation1[totaltime][i].p_y, rbTree->animation1[totaltime][i].color);
		}
	}
}


void BinaryTreeUI::animationDraw_RBT_removefixup(int totaltime, int frametime)
{
	for (int i = 1; i <= frametime; i++) //������������
	{
		if (rbTree->animation2[totaltime][i].data2 == -1) {
			m_scene->drawCircle(rbTree->animation2[totaltime][i].x,
				rbTree->animation2[totaltime][i].y,
				rbTree->animation2[totaltime][i].data1,
				rbTree->animation2[totaltime][i].p_x, rbTree->animation2[totaltime][i].p_y, rbTree->animation2[totaltime][i].color);
		}
		else if (rbTree->animation2[totaltime][i].data1 != -1) {
			m_scene->drawCircle2(rbTree->animation2[totaltime][i].x,
				rbTree->animation2[totaltime][i].y,
				rbTree->animation2[totaltime][i].data1, rbTree->animation2[totaltime][i].data2,
				rbTree->animation2[totaltime][i].p_x, rbTree->animation2[totaltime][i].p_y, rbTree->animation2[totaltime][i].color);
		}
	}
}
