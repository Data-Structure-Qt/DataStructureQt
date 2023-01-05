#include "CBinarySortTreeEditorUI.h"
CBinarySortTreeEditorUI::CBinarySortTreeEditorUI(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::CBinarySortTreeEditorUI),
	m_scene(NULL)
{
	ui->setupUi(this);
	listshow = nullptr;
}
void CBinarySortTreeEditorUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);
}
void CBinarySortTreeEditorUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);
	m_scene = scene;
	setEnabled(m_scene);
	if (m_scene)
		onSceneAttached(m_scene);
}
void CBinarySortTreeEditorUI::onSceneAttached(CEditorScene* scene)
{
}
void CBinarySortTreeEditorUI::setCQuickHelpUI(CQuickHelpUI* quickHelp)
{
	m_quickHelp = quickHelp;
	setEnabled(m_quickHelp);
}
void CBinarySortTreeEditorUI::setCEditorView(CEditorView* editorView)
{
	m_editorView = editorView;
	setEnabled(m_editorView);
}
CBinarySortTreeEditorUI::~CBinarySortTreeEditorUI()
{
}
//�����Ǵ������������
void
CBinarySortTreeEditorUI::on_binarytree_SimulationTree_creat_btn_clicked()
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
		inOrderPrint_SimulationTree(root, 0, 400, (i + 1) * 10, 90, 1 + i * 1.5, 0,
			400);//(i+1)*10 �����س���90 �Ƕ�,�����Ƕ� 10-30
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
//������ɾ������
void CBinarySortTreeEditorUI::on_binarytree_delete_btn_clicked()
{
	list.clear();
	for (int i = 0; i < 1010; ++i)
	{
		list_array[i] = 0;
	}
	avlTree->destroy(root);
	m_scene->clearScreen();//����
}
void CBinarySortTreeEditorUI::goToBeginButton()
{
	endplaybuttonflag = 1;
	timestamp = 0;
	m_scene->clearScreen();//����
	for (int j = 0; j <= frametime[0]; j++)
	{
		animationDraw(0, j);
	}
	m_quickHelp->btree_create_code(insertIdCode[timestamp]);
	//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
}
void CBinarySortTreeEditorUI::stepBackButton()
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
		//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
	}
}
void CBinarySortTreeEditorUI::playButton()
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
		//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
		sleepTime(500);
	}
}
void CBinarySortTreeEditorUI::suspendButton()
{
	endplaybuttonflag = 1;
}
void CBinarySortTreeEditorUI::stepForwardButton()
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
		//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
	}
}
void CBinarySortTreeEditorUI::goToEndButton()
{
	endplaybuttonflag = 1;
	m_scene->clearScreen();//����
	timestamp = onlytotaltime;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	m_quickHelp->btree_create_code(insertIdCode[timestamp]);
	//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
}
void CBinarySortTreeEditorUI::inOrderPrint(CBiTreeNode* root, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame)//�ݹ�չʾ����
{
	if (root == NULL)
		return;
	wideSize = wideSize / 2;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (root->left != NULL)
	{
		frametime[frame]++;
		insertIdCode[frametime[frame]] = 2;
		animationRecord(onlytotaltime, frametime[frame], x, y, -2, -1, p_x, p_y);
		inOrderPrint(root->left, x - wideSize, y + highSize, wideSize, highSize, x, y,
			frame);//��������
	}
	if (root->right != NULL)
	{
		frametime[frame]++;
		insertIdCode[frametime[frame]] = 3;
		animationRecord(onlytotaltime, frametime[frame], x, y, -2, -1, p_x, p_y);
		inOrderPrint(root->right, x + wideSize, y + highSize, wideSize, highSize, x,
			y, frame);//�����Һ���
	}
	if (root != NULL)
	{
		frametime[frame]++;
		animationRecord(onlytotaltime, frametime[frame], x, y, root->key, -1, p_x,
			p_y);
		insertIdCode[frametime[frame]] = 1;
	}
}
void CBinarySortTreeEditorUI::inOrderPrint_search(CBiTreeNode* root,
	double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int data, int
	frame) {
	if (root == NULL)
		return;
	wideSize = wideSize / 2;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (root != NULL)
	{
		if (root->key == data)//�ҹ�
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x,
				p_y, 1, 2);//��¼ �ҵ� 2
			animationPrint(0, framesearchtime);
			return;
		}
		else if (data < root->key)//�ҹ�
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x,
				p_y, 1, 3);//��¼ 3
			animationPrint(0, framesearchtime);
		}
		else if (data > root->key)//�ҹ�
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x,
				p_y, 1, 5);//��¼ 5
			animationPrint(0, framesearchtime);
		}
	}
	if (root->left != NULL && data < root->key)
	{
		inOrderPrint_search(root->left, x - wideSize, y + highSize, wideSize,
			highSize, x, y, data, 1);//����
	}
	if (root->right != NULL && data > root->key)
	{
		inOrderPrint_search(root->right, x + wideSize, y + highSize, wideSize,
			highSize, x, y, data, 2);//�Һ���
	}
}
void CBinarySortTreeEditorUI::inOrderPrint_SimulationTree(CBiTreeNode*
	root, double x,
	double y, double Branch_length, double Branch_angle, double Change_angle,
	double p_x, double p_y)//�ݹ�չʾ����
{
	if (root == NULL)
		return;
	if (root->left != NULL)
	{
		double angle = Branch_angle + Change_angle;//��ʱ��Ƕ�
		double radian = angle * 3.14159265 / 180; //���㻡��
		double Branch_length_x = Branch_length * cos(radian);//x λ��
		double Branch_length_y = Branch_length * sin(radian);//y λ��
		inOrderPrint_SimulationTree(root->left, x + Branch_length_x, y -
			Branch_length_y, Branch_length * 0.8, angle, Change_angle, x, y);//����
	}
	if (root->right != NULL)
	{
		double angle = Branch_angle - Change_angle + 2;//˳ʱ��Ƕ�
		double radian = angle * 3.14159265 / 180; //���㻡��
		double Branch_length_x = Branch_length * cos(radian);//x λ��
		double Branch_length_y = Branch_length * sin(radian);//y λ��
		inOrderPrint_SimulationTree(root->right, x + Branch_length_x, y -
			Branch_length_y, Branch_length * 0.8, angle, Change_angle, x, y);//�Һ���
	}
	//���Ƶ�ǰ�ڵ�
	if (root != NULL)
		m_scene->drawCircle_simulate(x, y, root->key, p_x, p_y);
}
void CBinarySortTreeEditorUI::PreOrder(CBiTreeNode* root, string& In)
{
	if (root)
	{
		In += root->data;
		PreOrder(root->left, In);
		PreOrder(root->mid, In);
		PreOrder(root->right, In);
	}
}
void CBinarySortTreeEditorUI::PreOrderPractice(CBiTreeNode* root)
{
	if (root)
	{
		
		CBiTreeNode* parent=root->parent;
		if (parent != NULL)
		{
			m_scene->NewLine(parent->data, parent->x_way, parent->y_way, root->data, root->x_way, root->y_way);
			sleepTime(1000);
		}
		top++;
		next[top] = root;
		if (top > MaX)
		{
			int i;
			for (i = 1; i <= MaX; i++)
				m_scene->NewLine(nextMAX[i]->parent->data, nextMAX[i]->parent->x_way, nextMAX[i]->parent->y_way, nextMAX[i]->data, nextMAX[i]->x_way, nextMAX[i]->y_way);
			for ( i = 1; i <= top; i++)
				nextMAX[i] = next[i];
			for (i = 1; i <= top; i++)
				m_scene->BlackLine(nextMAX[i]->parent->data, nextMAX[i]->parent->x_way, nextMAX[i]->parent->y_way, nextMAX[i]->data, nextMAX[i]->x_way, nextMAX[i]->y_way);
			sleepTime(1000);
			MaX = top;
		}
		PreOrderPractice(root->left);
		PreOrderPractice(root->mid);
		PreOrderPractice(root->right);
		top--;
	}
	
	
}
void CBinarySortTreeEditorUI::PreOrderBiTree(CBiTreeNode* root, string& In)//�������
{
	if (root) {
		char inStr[10];
		itoa(root->key, inStr, 10);
		In += inStr;
		PreOrderBiTree(root->left, In);
		PreOrderBiTree(root->right, In);
	}
}
void CBinarySortTreeEditorUI::InOrderBiTree(CBiTreeNode* root, string& In)
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
void CBinarySortTreeEditorUI::PostOrderBiTree(CBiTreeNode* root, string
	& In) //�������
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
void CBinarySortTreeEditorUI::DepthOfBiTree(CBiTreeNode* root, int& In)
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
//��������в���Ԫ��
bool CBinarySortTreeEditorUI::insertBigRootTree(int val, BigRoot* bigrootTree)
{
	return bigrootTree->insert(val);
}
//�Ӷ������ɾ��Ԫ��
bool CBinarySortTreeEditorUI::removeBigRootTree(int val, BigRoot*
	bigrootTree)
{
	return bigrootTree->remove(val);
}
//��ӡ�����
void CBinarySortTreeEditorUI::printBigRootTree(BigRoot* bigrootTree)
{
	bigrootTree->print();
}
//��ȡ�Ѷ�Ԫ��
int CBinarySortTreeEditorUI::getTopBigRootTree(BigRoot* bigrootTree)
{
	return bigrootTree->getTop();
}
//����ָ�����鴴���󶥶�
bool CBinarySortTreeEditorUI::creatBigRootTree(int a[], int size, BigRoot*
	bigrootTree)
{
	return bigrootTree->creatMaxHeap(a, size);
}
void CBinarySortTreeEditorUI::Print_BigRootTree(int index, BigRoot*
	bigrootTree, double x,
	double y, double wideSize, double highSize, double p_x, double p_y)
{
	if (index >= bigrootTree->getSize())
		return;
	wideSize = wideSize / 2;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (2 * index + 1 < bigrootTree->getSize())
		Print_BigRootTree(2 * index + 1, bigrootTree, x - wideSize, y + highSize,
			wideSize, highSize, x, y);//����
	if (2 * index + 2 < bigrootTree->getSize())
		Print_BigRootTree(2 * index + 2, bigrootTree, x + wideSize, y + highSize,
			wideSize, highSize, x, y);//�Һ���
	if (index < bigrootTree->getSize())
		m_scene->drawCircle(x, y, bigrootTree->getIndexNum(index), p_x, p_y);
}
void CBinarySortTreeEditorUI::on_bigroottree_create_btn_clicked()
{
	m_scene->clearScreen();//����
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
	bigrootTree = new BigRoot(1010);
	//���Ԫ�ش����󶥶�
	for (int i = 0; i < list.size(); i++)
		bigrootTree->insert(list_array[i]);
	qDebug() << "top is:" << bigrootTree->getTop() << endl;
	bigrootTree->print();
	//������������
	int depth = 0;
	depth = int(log2(bigrootTree->getSize())) + 1;
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
	//��ӡ�����
	Print_BigRootTree(0, bigrootTree, 0, 0, wideSize, highSize, 0, 0);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
}
void CBinarySortTreeEditorUI::on_bigroottree_insert_btn_clicked()
{
	m_scene->clearScreen();//����
	QString data = ui->BinaryTreeDataEdit_2->text();
	list = data.split(",");
	int list_temp[1010];
	for (int i = 0; i < list.size(); ++i)
	{
		QString tmp = list.at(i);
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		list_temp[i] = x;//����Ϊ����
	}
	bigrootTree->insert(list_temp[0]);
	bigrootTree->print();
	//������������
	int depth = 0;
	depth = int(log2(bigrootTree->getSize())) + 1;
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
	//��ӡ�����
	Print_BigRootTree(0, bigrootTree, 0, 0, wideSize, highSize, 0, 0);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
}
void CBinarySortTreeEditorUI::on_bigroottree_remove_btn_clicked()
{
	m_scene->clearScreen();//����
	QString data = ui->BinaryTreeDataEdit_2->text();
	list = data.split(",");
	int list_temp[1010];
	for (int i = 0; i < list.size(); ++i)
	{
		QString tmp = list.at(i);
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		list_temp[i] = x;//����
	}
	//bigrootTree->insert(list_temp[0]);
	bigrootTree->remove(list_temp[0]);
	bigrootTree->print();
	//������������
	int depth = 0;
	depth = int(log2(bigrootTree->getSize())) + 1;
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
	//��ӡ�����
	Print_BigRootTree(0, bigrootTree, 0, 0, wideSize, highSize, 0, 0);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
}
//B ��
///////////////////////////
//��ʼ�� B ��
Status CBinarySortTreeEditorUI::InitBTree(BTree& t) {
	t = NULL;
	return OK;
}
//����в��ҹؼ��� k ����λ�� i 
int CBinarySortTreeEditorUI::SearchBTNode(BTNode* p, KeyType k) {
	int i = 0;
	for (i = 0; i < p->keynum && p->key[i + 1] <= k; i++);
	return i;
}
//���� t �ϲ��ҹؼ���
Result CBinarySortTreeEditorUI::SearchBTree(BTree t, KeyType k) {
	BTNode* p = t, * q = NULL; //������ָ�� p,p ��˫��ָ�� q
		int flag = 0, i = 0; //flag 1 �ɹ���2 ʧ��
	Result r;
	while (p != NULL && flag == 0) {
		i = SearchBTNode(p, k); //�ڽ�� p �в��ҹؼ��� k,ʹ�� p->key[i] <= k < p->key[i + 1]
			if (i > 0 && p->key[i] == k) //�ҵ�����ؼ���
				flag = 1;
			else {
				q = p;
				p = p->ptr[i];
			}
	}
	if (flag == 1) {
		r.pt = p;
		r.i = i;
		r.fag = 1;
	}
	else {
		r.pt = q;
		r.i = i;
		r.fag = 0;
	}
	return r; //���عؼ��� k ��λ��
}
void CBinarySortTreeEditorUI::InsertBTNode(BTNode*& p, int i, KeyType k,
	BTNode* q) {
	//���ؼ��� k �ͽ�� q �ֱ���뵽 p->key[i+1]�� p->ptr[i+1]��
	int j;
	for (j = p->keynum; j > i; j--) { //������ƿճ�һ��λ��
			p->key[j + 1] = p->key[j];
		p->ptr[j + 1] = p->ptr[j];
	}
	p->key[i + 1] = k;
	p->ptr[i + 1] = q;
	if (q != NULL)
		q->parent = p;
	p->keynum++;
}
//����� p ���ѳ��������,ǰһ�뱣��,��һ�������� q
void CBinarySortTreeEditorUI::SplitBTNode(BTNode*& p, BTNode*& q) {
	int i, s = (m + 1) / 2;
	q = (BTNode*)malloc(sizeof(BTNode)); //����� q ����ռ�
	q->ptr[0] = p->ptr[s]; //��һ�������� q
	for (i = s + 1; i <= m; i++) {
		q->key[i - s] = p->key[i];
		q->ptr[i - s] = p->ptr[i];
	}
	q->keynum = p->keynum - s;
	q->parent = p->parent;
	for (i = 0; i <= p->keynum - s; i++) //�޸�˫��ָ��
		if (q->ptr[i] != NULL)
			q->ptr[i]->parent = q;
	p->keynum = s - 1; //��� p ��ǰһ�뱣��, �޸Ľ�� p �� keynum
}
//�����µĸ���� t,ԭ p �� q Ϊ����ָ��
void CBinarySortTreeEditorUI::NewRoot(BTNode*& t, KeyType k, BTNode* p,
	BTNode* q) {
	t = (BTNode*)malloc(sizeof(BTNode)); //����ռ�
	t->keynum = 1;
	t->ptr[0] = p;
	t->ptr[1] = q;
	t->key[1] = k;
	if (p != NULL) //������� p �ͽ��q ��˫��ָ��
		p->parent = t;
	if (q != NULL)
		q->parent = t;
	t->parent = NULL;
}
//����ؼ��� k�������������
void CBinarySortTreeEditorUI::InsertBTree(BTree& t, int i, KeyType k, BTNode
	* p) {
	BTNode* q;
	int endflag, newflag, s; //�趨��Ҫ�½���־�Ͳ�����ɱ�־
		KeyType x;
	if (p == NULL) //t �ǿ���
		NewRoot(t, k, NULL, NULL); //���ɽ����ؼ��� k�ĸ���� t
	else {
		x = k;
		q = NULL;
		endflag = 0;
		newflag = 0;
		while (endflag == 0 && newflag == 0) {
			InsertBTNode(p, i, x, q); //���ؼ��� x �ͽ�� q�ֱ���뵽 p->key[i + 1]�� p->ptr[i + 1]
				if (p->keynum <= Max)
					endflag = 1; //�������
				else {
					s = (m + 1) / 2;
					SplitBTNode(p, q); //���ѽ��
					x = p->key[s];
					if (p->parent) { //���� x �Ĳ���λ��
						p = p->parent;
						i = SearchBTNode(p, x);
					}
					else //û�ҵ� x����Ҫ�½��
						newflag = 1;
				}
		}
		if (newflag == 1) //������ѷ���Ϊ��� p ��q
			NewRoot(t, x, p, q); //�����¸���� t,p �� q Ϊ����ָ��
	}
}
void CBinarySortTreeEditorUI::Remove(BTNode* p, int i) {
	int j;
	for (j = i + 1; j <= p->keynum; j++) { //ǰ��ɾ�� key[i]�� ptr[i]
		p->key[j - 1] = p->key[j];
		p->ptr[j - 1] = p->ptr[j];
	}
	p->keynum--;
}
//���ұ�ɾ�ؼ��� p->key[i](�ڷ�Ҷ�ӽ����)�����Ҷ�ӽ��(��������ֵ��С�Ĺؼ���)
void CBinarySortTreeEditorUI::Substitution(BTNode* p, int i) {
	BTNode* q;
	for (q = p->ptr[i]; q->ptr[0] != NULL; q = q->ptr[0]);
	p->key[i] = q->key[1]; //���ƹؼ���ֵ
}
/*��˫�׽�� p �е����һ���ؼ��������ҽ�� q ��
������ aq �е����һ���ؼ�������˫�׽�� p ��*/
void CBinarySortTreeEditorUI::MoveRight(BTNode* p, int i) {
	int j;
	BTNode* q = p->ptr[i];
	BTNode* aq = p->ptr[i - 1];
	for (j = q->keynum; j > 0; j--) { //�����ֵ� q �����йؼ�������ƶ�һλ
			q->key[j + 1] = q->key[j];
		q->ptr[j + 1] = q->ptr[j];
	}
	q->ptr[1] = q->ptr[0]; //��˫�׽�� p �ƶ��ؼ��ֵ����ֵ� q ��
		q->key[1] = p->key[i];
	q->keynum++;
	p->key[i] = aq->key[aq->keynum]; //�����ֵ� aq �����һ���ؼ����ƶ���˫�׽�� p ��
		p->ptr[i]->ptr[0] = aq->ptr[aq->keynum];
	aq->keynum--;
}
void CBinarySortTreeEditorUI::MoveLeft(BTNode* p, int i) {
	/*��˫�׽�� p �еĵ�һ���ؼ����������� aq �У�
	���ҽ�� q �еĵ�һ���ؼ�������˫�׽�� p ��*/
	int j;
	BTNode* aq = p->ptr[i - 1];
	BTNode* q = p->ptr[i];
	aq->keynum++; //˫�׽��ؼ����ƶ������ֵ� aq ��
		aq->key[aq->keynum] = p->key[i];
	aq->ptr[aq->keynum] = p->ptr[i]->ptr[0];
	p->key[i] = q->key[1]; //�����ֵ� q �еĹؼ����ƶ���˫�׽ڵ� p ��
		q->ptr[0] = q->ptr[1];
	q->keynum--;
	for (j = 1; j <= aq->keynum; j++) { //�����ֵ� q �����йؼ�����ǰ�ƶ�һλ
			aq->key[j] = aq->key[j + 1];
		aq->ptr[j] = aq->ptr[j + 1];
	}
}
void CBinarySortTreeEditorUI::Combine(BTNode* p, int i) {
	/*��˫�׽�� p���ҽ�� q �ϲ������� aq��
	������˫�׽�� p �е�ʣ��ؼ��ֵ�λ��*/
	int j;
	BTNode* q = p->ptr[i];
	BTNode* aq = p->ptr[i - 1];
	aq->keynum++; //��˫�׽��Ĺؼ���p->key[i]���뵽���� aq
		aq->key[aq->keynum] = p->key[i];
	aq->ptr[aq->keynum] = q->ptr[0];
	for (j = 1; j <= q->keynum; j++) { //���ҽ�� q �е����йؼ��ֲ��뵽���� aq
			aq->keynum++;
		aq->key[aq->keynum] = q->key[j];
		aq->ptr[aq->keynum] = q->ptr[j];
	}
	for (j = i; j < p->keynum; j++) { //��˫�׽�� p �е�p->key[i]������йؼ�����ǰ�ƶ�һλ
			p->key[j] = p->key[j + 1];
		p->ptr[j] = p->ptr[j + 1];
	}
	p->keynum--; //�޸�˫�׽�� p ��keynum ֵ
		free(q); //�ͷſ��ҽ�� q �Ŀռ�
}
void CBinarySortTreeEditorUI::AdjustBTree(BTNode* p, int i) {
	//ɾ����� p �еĵ� i ���ؼ��ֺ�,���� B ��
	if (i == 0) //ɾ����������߹ؼ���
		if (p->ptr[1]->keynum > Min) //�ҽ����Խ�
			MoveLeft(p, 1);
		else //���ֵܲ�����
			Combine(p, 1);
	else if (i == p->keynum) //ɾ���������ұ߹ؼ���
		if (p->ptr[i - 1]->keynum > Min) //������Խ�
			MoveRight(p, i);
		else //���㲻����
			Combine(p, i);
	else if (p->ptr[i - 1]->keynum > Min) //ɾ���ؼ������в������㹻��
		MoveRight(p, i);
	else if (p->ptr[i + 1]->keynum > Min) //ɾ���ؼ������в����ҽ�㹻��
		MoveLeft(p, i + 1);
	else //ɾ���ؼ������в������ҽ�㶼������
		Combine(p, i);
}
int CBinarySortTreeEditorUI::FindBTNode(BTNode* p, KeyType k, int& i) {
	//��ӳ�Ƿ��ڽ�� p ���Ƿ���ҵ��ؼ��� k 
	if (k < p->key[1]) { //��� p �в��ҹؼ���k ʧ��
			i = 0;
		return 0;
	}
	else { //�� p ����в���
		i = p->keynum;
		while (k < p->key[i] && i>1)
			i--;
		if (k == p->key[i]) //��� p �в��ҹؼ���k �ɹ�
			return 1;
	}
}
int CBinarySortTreeEditorUI::BTNodeDelete(BTNode* p, KeyType k) {
	//�ڽ�� p �в��Ҳ�ɾ���ؼ��� k
	int i;
	int found_tag; //���ұ�־
	if (p == NULL)
		return 0;
	else {
		found_tag = FindBTNode(p, k, i); //���ز��ҽ��
		if (found_tag == 1) { //���ҳɹ�
			if (p->ptr[i - 1] != NULL) { //ɾ�����Ƿ�Ҷ�ӽ��
					Substitution(p, i); //Ѱ�����ڹؼ���(����������С�Ĺؼ���)
				BTNodeDelete(p->ptr[i], p->key[i]); //ִ��ɾ������
			}
			else
				Remove(p, i); //�ӽ�� p ��λ�� i ��ɾ���ؼ���
		}
		else
			found_tag = BTNodeDelete(p->ptr[i], k); //�غ��ӽ��ݹ���Ҳ�ɾ���ؼ��� k
			if (p->ptr[i] != NULL)
				if (p->ptr[i]->keynum < Min) //ɾ����ؼ��ָ���С�� MIN
					AdjustBTree(p, i); //���� B ��
		return found_tag;
	}
}
void CBinarySortTreeEditorUI::BTreeDelete(BTree& t, KeyType k) {
	//����ɾ����ܣ�ִ��ɾ������ 
	BTNode* p;
	int a = BTNodeDelete(t, k); //ɾ���ؼ��� k 
	if (a == 0) //����ʧ��
		printf(" �ؼ���%d ���� B ����\n", k);
	else if (t->keynum == 0) { //����
		p = t;
		t = t->ptr[0];
		free(p);
	}
}
void CBinarySortTreeEditorUI::DestroyBTree(BTree& t) {
	//�ݹ��ͷ� B ��
	int i;
	BTNode* p = t;
	if (p != NULL) { //B ����Ϊ�� 
		for (i = 0; i <= p->keynum; i++) { //�ݹ��ͷ�ÿһ�����
				DestroyBTree(*&p->ptr[i]);
		}
		free(p);
	}
	t = NULL;
}
Status CBinarySortTreeEditorUI::InitQueue(LinkList& L) {
	//��ʼ������
	L = (LNode*)malloc(sizeof(LNode)); //������ռ�
	if (L == NULL) //����ʧ�� 
		return OVERFLOW1;
	L->next = NULL;
	return OK;
}
LNode* CBinarySortTreeEditorUI::CreateNode1(BTNode* p) {
	//�½�һ�����
	LNode* q;
	q = (LNode*)malloc(sizeof(LNode)); //������ռ�
	if (q != NULL) { //����ɹ�
		q->data = p;
		q->next = NULL;
	}
	return q;
}
Status CBinarySortTreeEditorUI::Enqueue1(LNode* p, BTNode* q) {
	//Ԫ�� q �����
	if (p == NULL)
		return ERROR;
	while (p->next != NULL) //�����������
		p = p->next;
	p->next = CreateNode1(q); //���ɽ���� q �������
		return OK;
}
Status CBinarySortTreeEditorUI::Dequeue(LNode* p, BTNode*& q) {
	//�����У����� q ����ֵ
	LNode* aq;
	if (p == NULL || p->next == NULL) //ɾ��λ�ò�����
		return ERROR;
	aq = p->next; //�޸ı�ɾ��� aq ��ָ����
		p->next = aq->next;
	q = aq->data;
	free(aq); //�ͷŽ�� aq
	return OK;
}
Status CBinarySortTreeEditorUI::IfEmpty(LinkList L) {
	//�����п�
	if (L == NULL) //���в�����
		return ERROR;
	if (L->next == NULL) //����Ϊ��
		return TRUE;
	return FALSE; //���зǿ�
}
void CBinarySortTreeEditorUI::DestroyQueue(LinkList L) {
	//���ٶ���
	LinkList p;
	if (L != NULL) {
		p = L;
		L = L->next;
		free(p); //��һ�ͷ�
		DestroyQueue(L);
	}
}
Status CBinarySortTreeEditorUI::Traverse(BTree t, LinkList L, int newline, int
	sum) {
	//�ö��б������ B ��
	int i;
	BTree p;
	if (t != NULL) {
		//qDebug() << " [ ";
		Enqueue1(L, t->ptr[0]); //��� 
		for (i = 1; i <= t->keynum; i++) //ͬһ���ڵ���� �ڵ�ؼ��ָ���keynum
		{
		qDebug() << t->key[i]; //�ڵ�ؼ������� key[i]
		Enqueue1(L, t->ptr[i]); //�ӽ�����
		}
		sum += t->keynum + 1;
		//qDebug() << "]";
		if (newline == 0) { //��Ҫ����һ��
			qDebug() << "\n";
			newline = sum - 1;
			sum = 0;
		}
		else
			newline--;
	}
	if (IfEmpty(L) == FALSE) { //l ��Ϊ��
		Dequeue(L, p); //���ӣ��� p ����
		Traverse(p, L, newline, sum); //�������ӽ��
	}
	return OK;
}
Status CBinarySortTreeEditorUI::PrintBTree(BTree t) {
	//��� B ��
	LinkList L;
	if (t == NULL) {
		qDebug() << "BTree is empty";
		return OK;
	}
	InitQueue(L); //��ʼ������
	Traverse(t, L, 0, 0); //���ö������
	DestroyQueue(L); //���ٶ���
	return OK;
}
void CBinarySortTreeEditorUI::on_Btree_create_btn_clicked() {
	int i, k;
	DestroyBTree(t);//����� B ��
	m_scene->clearScreen();//����
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
	{
		k = list_array[i];
		s = SearchBTree(t, k);
		InsertBTree(t, s.i, k, s.pt); //����Ԫ��
	}
	qDebug() << "Now BTree is\n";
	PrintBTree(t);
	//������������
	int depth = 0;
	BTree pt;
	pt = t;
	for (i = 1; ; i++)
	{
		pt = pt->ptr[0];
		if (pt == NULL)
		{
			depth = i;
			break;
		}
	}
	qDebug() << depth;
	//������ÿ���׼�߶�
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75)
	{
		highSize = 75;
	}
	//���������һ��������
	double wide = pow(3, depth) - 1;
	//���������һ�������
	double wideSize = 9 * wide;
	//��ӡ B_��
	Print_BTree(t, 0, 0, wideSize, highSize, 0, 0);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
}
//B ����ӽڵ㹦��
void CBinarySortTreeEditorUI::on_Btree_insert_btn_clicked()
{
	m_scene->clearScreen();
	QString data = ui->BinaryTreeDataEdit_2->text();
	list = data.split(",");
	int list_temp[1010];
	for (int i = 0; i < list.size(); ++i)
	{
		QString tmp = list.at(i);
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		list_temp[i] = x;
	}
	int k = list_temp[0];
	s = SearchBTree(t, k);
	InsertBTree(t, s.i, k, s.pt);
	PrintBTree(t);
	//������������
	int depth = 0;
	BTree pt;
	pt = t;
	for (int i = 1; ; i++) {
		pt = pt->ptr[0];
		if (pt == NULL) {
			depth = i;
			break;
		}
	}
	//������ÿ���׼�߶�
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75)
	{
		highSize = 75;
	}
	//���������һ��������
	double wide = pow(3, depth) - 1;
	//���������һ�������
	double wideSize = 9 * wide;
	//��ӡ�����
	Print_BTree(t, 0, 0, wideSize, highSize, 0, 0);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
}
//B ��ɾ��
void CBinarySortTreeEditorUI::on_Btree_remove_btn_clicked() {
	m_scene->clearScreen(); //����
	QString data = ui->BinaryTreeDataEdit_2->text();
	list = data.split(",");
	int list_temp[1010];
	for (int i = 0; i < list.size(); ++i) {
		QString tmp = list.at(i);
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		list_temp[i] = x;
	}
	int k = list_temp[0];
	BTreeDelete(t, k); //ɾ��Ԫ��
	PrintBTree(t);
	int depth = 0;
	BTree pt;
	pt = t;
	for (int i = 1; ; i++) {
		pt = pt->ptr[0];
		if (pt == NULL) {
			depth = i;
			break;
		}
	}
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75) {
		highSize = 75;
	}
	//���������һ��������
	double wide = pow(3, depth) - 1;
	//���������һ�������
	double wideSize = 9 * wide;
	//��ӡ�����
	Print_BTree(t, 0, 0, wideSize, highSize, 0, 0);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
}
//B ������
void CBinarySortTreeEditorUI::on_Btree_destroy_btn_clicked()
{
	DestroyBTree(t);
	PrintBTree(t);
	m_scene->clearScreen();//����
}
void CBinarySortTreeEditorUI::Print_BTree(BTree bTree, double x,
	double y, double wideSize, double highSize, double p_x, double p_y)
{
	if (bTree == NULL)
		return;
	wideSize = wideSize / 3;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (bTree->keynum == 1)
	{
		if (bTree->ptr[0] != NULL)
			Print_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y);//����
		else
		{
			m_scene->drawCircle(x, y + highSize, -1, x, y);
		}
		if (bTree->ptr[1] != NULL)
			Print_BTree(bTree->ptr[1], x + wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y);//�Һ���
		else
		{
			m_scene->drawCircle(x, y + highSize, -1, x, y);
		}
		if (bTree != NULL)
			m_scene->drawCircle(x, y, bTree->key[1], p_x, p_y);
	}
	if (bTree->keynum == 2)
	{
		if (bTree->ptr[0] != NULL)
			Print_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y);//����
		else
		{
			m_scene->drawCircle(x, y + highSize, -1, x, y);
		}
		if (bTree->ptr[2] != NULL)
			Print_BTree(bTree->ptr[2], x + wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y);//�Һ���
		else
		{
			m_scene->drawCircle(x, y + highSize, -1, x, y);
		}
		if (bTree->ptr[1] != NULL)
			Print_BTree(bTree->ptr[1], x, y + highSize, wideSize, highSize, x, y);//�к���
		else
		{
			m_scene->drawCircle(x, y + highSize, -1, x, y);
		}
		if (bTree != NULL)
			m_scene->drawCircle2(x, y, bTree->key[1], bTree->key[2], p_x, p_y);
	}
}
void CBinarySortTreeEditorUI::Print_BTree(BTree bTree, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame)
{
	if (bTree == NULL)
		return;
	wideSize = wideSize / 3;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (bTree != NULL)
	{
		frametime[frame]++;
		animationRecord(onlytotaltime, frametime[frame], x, y, bTree->key[1], -1,
			p_x, p_y);
		animationPrint(onlytotaltime, frametime[frame]);
	}
	if (bTree->keynum == 1)
	{
		if (bTree->ptr[0] != NULL)
			Print_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y, frame);//����
		else
		{
			//m_scene->drawCircle(x, y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1,
				-1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);
		}
		if (bTree->ptr[1] != NULL)
			Print_BTree(bTree->ptr[1], x + wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y, frame);//�Һ���
		else
		{
			//m_scene->drawCircle(x, y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1,
				-1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);
		}
	}
	if (bTree->keynum == 2)
	{
		if (bTree != NULL)
		{
			//m_scene->drawCircle2(x, y, bTree->key[1], bTree->key[2], p_x, p_y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y,
				bTree->key[1], bTree->key[2], p_x, p_y);
			animationPrint(onlytotaltime, frametime[frame]);
		}
		if (bTree->ptr[0] != NULL)
			Print_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y, frame);//����
		else
		{
			//m_scene->drawCircle(x , y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1,
				-1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);
		}
		if (bTree->ptr[1] != NULL)
			Print_BTree(bTree->ptr[1], x, y + highSize, wideSize, highSize, x, y,
				frame);//�к���
		else
		{
			//m_scene->drawCircle(x, y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1,
				-1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);
		}
		if (bTree->ptr[2] != NULL)
			Print_BTree(bTree->ptr[2], x + wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y, frame);//�Һ���
		else
		{
			//m_scene->drawCircle(x, y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1,
				-1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);
		}
	}
}
void CBinarySortTreeEditorUI::Print_Search_BTree(BTree bTree, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame,
	int key)
{
	if (bTree == NULL)
		return;//δ�ҵ�
	wideSize = wideSize / 3;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������
	if (bTree != NULL)
	{
		if (bTree->keynum == 1)
		{
			if (bTree->key[1] == key)//�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					-1, p_x, p_y, 1, 2);//��¼ �ҵ� 2
				animationPrint(0, framesearchtime);
			}
			else if (key < bTree->key[1])//�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					-1, p_x, p_y, 1, 3);//��¼ 3
				animationPrint(0, framesearchtime);
			}
			else if (key > bTree->key[2])//�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					-1, p_x, p_y, 1, 5);//��¼ 5
				animationPrint(0, framesearchtime);
			}
		}
		if (bTree->keynum == 2)
		{
			if (bTree->key[1] == key || bTree->key[2] == key)//�ҵ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 2);//��¼ 2
				animationPrint(0, framesearchtime);
			}
			else if (key < bTree->key[1]) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 3);//��¼ 3
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[1] < key && key < bTree->key[2]) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 4);//��¼ 4
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[2] < key) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 5);//��¼ 5
				animationPrint(0, framesearchtime);
			}
		}
	}
	if (bTree->keynum == 1)
	{
		if (key < bTree->key[1])
		{
			if (bTree->ptr[0] != NULL)
			{
				Print_Search_BTree(bTree->ptr[0], x - wideSize * 1.5, y +
					highSize, wideSize, highSize, x, y, frame, key);//����
			}
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -
					1, x, y, 1, 6);//��¼ 6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[1])
		{
			if (bTree->ptr[1] != NULL)
				Print_Search_BTree(bTree->ptr[1], x + wideSize * 1.5, y +
					highSize, wideSize, highSize, x, y, frame, key);//�Һ���
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -
					1, x, y, 1, 6);//��¼ 6
				animationPrint(0, framesearchtime);
			}
		}
	}
	if (bTree->keynum == 2)
	{
		if (bTree != NULL)
		{
			if (bTree->key[1] == key || bTree->key[2] == key)//�ҵ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 2);//��¼ 2
				animationPrint(0, framesearchtime);
			}
			else if (key < bTree->key[1]) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 3);//��¼ 3
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[1] < key && key < bTree->key[2]) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 4);//��¼ 4
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[2] < key) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 5);//��¼ 5
				animationPrint(0, framesearchtime);
			}
		}
		if (key < bTree->key[1])//�ҵ�
		{
			if (bTree->ptr[0] != NULL)
				Print_Search_BTree(bTree->ptr[0], x - wideSize * 1.5, y +
					highSize, wideSize, highSize, x, y, frame, key);//����
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -
					1, x, y, 1, 6);//��¼ 6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[1] && key < bTree->key[2])//�ҵ�
		{
			if (bTree->ptr[1] != NULL)
				Print_Search_BTree(bTree->ptr[1], x, y + highSize, wideSize,
					highSize, x, y, frame, key);//�к���
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -
					1, x, y, 1, 6);//��¼ 6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[2])//�ҵ�
		{
			if (bTree->ptr[2] != NULL)
				Print_Search_BTree(bTree->ptr[2], x + wideSize * 1.5, y +
					highSize, wideSize, highSize, x, y, frame, key);//�Һ���
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -
					1, x, y, 1, 6);//��¼ 6
				animationPrint(0, framesearchtime);
			}
		}
	}
}
void CBinarySortTreeEditorUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//��ȡ�Զ�������ʱ��
		while (QTime::currentTime() < dieTime)
		{
			QCoreApplication::processEvents(QEventLoop::AllEvents, 100);// �� �����̣߳����� qt �����¼�
		}
}
void CBinarySortTreeEditorUI::animationRecord(int totaltime, int frame, int x,
	int y, int data1, int data2, int p_x, int p_y)
{
	animation[totaltime][frame].x = x;
	animation[totaltime][frame].y = y;
	animation[totaltime][frame].data1 = data1;
	animation[totaltime][frame].data2 = data2;
	animation[totaltime][frame].p_x = p_x;
	animation[totaltime][frame].p_y = p_y;
}
void CBinarySortTreeEditorUI::animationSearchRecord(int totaltime, int frame,
	int x, int y, int data1, int data2, int p_x, int p_y, int flag, int codeid)
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
void CBinarySortTreeEditorUI::animationClean()
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
void CBinarySortTreeEditorUI::animationPrint(int totaltime, int frametime)
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
void CBinarySortTreeEditorUI::animationDraw(int totaltime, int frametime)
{
	for (int i = 0; i < frametime; i++) //������������
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
				animation[totaltime][frametime].data1,
				animation[totaltime][frametime].data2, animation[totaltime][frametime].p_x,
				animation[totaltime][frametime].p_y);
		}
	}
}
void CBinarySortTreeEditorUI::animation3Draw(CBiTreeNode* root)
{
	m_scene->drawCircle3(0, 0, root->data, 0,0);//a
	m_scene->drawCircle3(-150, 50, root->left->data, -150, 50);//b
	m_scene->drawCircle3(0, 50, root->mid->data, 0, 50);//c
	m_scene->drawCircle3(150, 50, root->right->data, 150, 50);//d
	m_scene->drawCircle3(-200, 100, root->left->left->data, -200, 100);//e
	m_scene->drawCircle3(-150, 100, root->left->mid->data, -150, 100);//f
	m_scene->drawCircle3(-100, 100, root->left->right->data, -100, 100);//g
	m_scene->drawCircle3(0, 100, root->mid->left->data, 0, 100);//h
	m_scene->drawCircle3(100, 100, root->right->left->data, 100, 100);//i
	m_scene->drawCircle3(150, 100, root->right->mid->data, 150, 100);//j
	m_scene->drawCircle3(200, 100, root->right->right->data, 200, 100);//k
	m_scene->drawCircle3(-25, 150, root->mid->left->left->data, -25, 150);//l
	m_scene->drawCircle3(25, 150, root->mid->left->mid->data, 25, 150);//m
	m_scene->drawCircle3(75, 150, root->right->left->left->data, 75, 150);//n
	m_scene->drawCircle3(125, 150, root->right->left->mid->data, 125, 150);//o
}
void CBinarySortTreeEditorUI::animationDrawSearch(int totaltime, int
	frametime, int x)
{
	for (int i = 0; i < frametime; i++) //������������
	{
		if (animationSearch[totaltime][frametime].data2 == -1)
		{
			m_scene->drawCircle_search(animationSearch[totaltime][frametime].x,
				animationSearch[totaltime][frametime].y, animationSearch[totaltime][frametime].data1,
				animationSearch[totaltime][frametime].p_x,
				animationSearch[totaltime][frametime].p_y, x);
			//m_quickHelp->btree_search_code(animationSearch[totaltime][frametime].codeid);
		}
		else if (animation[totaltime][frametime].data1 != -1)
		{
			m_scene->drawCircle_search(animationSearch[totaltime][frametime].x,
				animationSearch[totaltime][frametime].y, animationSearch[totaltime][frametime].data1,
				animationSearch[totaltime][frametime].p_x,
				animationSearch[totaltime][frametime].p_y, x);
			//m_quickHelp->btree_search_code(animationSearch[totaltime][frametime].codeid);
		}
	}
}
//�����Ǵ���ƽ�������
void CBinarySortTreeEditorUI::on_binarytree_create_btn_clicked()
{
	int depth;
	
	m_scene->clearScreen();//����
	avlTree = new CBiTree();//�½���
	root = avlTree->getRoot();//�½��ڵ�
	root = avlTree->creatThreeBitree(root);
	DepthOfBiTree(root, depth);
	animation3Draw(root);
	m_editorView->fitToView();
	/*QString data = ui->BinaryTreeDataEdit->text();
	list = data.split(",");
	list_array[1010];
	for (int i = 0; i < list.size(); ++i) {
		QString tmp = list.at(i);
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		list_array[i] = x;//��Ϊ����
	}
	for (int i = 0; i < list.size(); i++)
	{
		root = avlTree->insert(root, list_array[i]);
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
		frametime[i] = 0;
		onlytotaltime = i;
		history_wideSize[i] = wideSize;
		history_highSize[i] = highSize;
		//insertIdCode[i] = codeid;
		//�ݹ�չʾ������ ��λ���Ϊ 15 ������
		inOrderPrint(root, 0, 0, wideSize, highSize, 0, 0, i);
	}
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
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}*/
	
	
	//string InOrd;
	//PreOrder(root, InOrd);
	//QString temp = "DLR:" + QString::fromStdString(InOrd);
	//m_scene->printInOrd(100, -200, temp);

	//m_scene->clearScreen();//����

	/*m_quickHelp->btree_create_code(insertIdCode[frametime[onlytotaltime]]);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
	timestamp = 0;*/
	
}
//�������ڵ�ɾ������
void CBinarySortTreeEditorUI::on_binarytree_node_delete_btn_clicked()
{
	top = -1;
	MaX = -1;
	PreOrderPractice(root);
	/*QString data = ui->BinaryTreeDataEdit_2->text();
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
	m_scene->addUndoState();*/
	
}
//ƽ��������ڵ���Һ���
void CBinarySortTreeEditorUI::on_binarytree_node_search_btn_clicked()
{
	QString data = ui->BinaryTreeDataEdit_2->text();
	bool flag;
	int x = data.toUInt(&flag);
	if (!flag)
		return;
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
	//��LineEdit�����
	QString a=QString::number(depth, 10);
	ui->BinaryTreeDataEdit->insert(a);
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
	inOrderPrint_search(root, 0, 0, wideSize, highSize, 0, 0, x, 0);
	m_scene->clearScreen();//����
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
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
	
}