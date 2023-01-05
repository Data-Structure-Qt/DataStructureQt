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
//以下是创建仿真二叉树
void
CBinarySortTreeEditorUI::on_binarytree_SimulationTree_creat_btn_clicked()
{
	m_scene->clearScreen();//清屏
	avlTree = new CBiTree();//新建树
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
		inOrderPrint_SimulationTree(root, 0, 400, (i + 1) * 10, 90, 1 + i * 1.5, 0,
			400);//(i+1)*10 个像素长，90 角度,增量角度 10-30
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
//二叉树删除函数
void CBinarySortTreeEditorUI::on_binarytree_delete_btn_clicked()
{
	list.clear();
	for (int i = 0; i < 1010; ++i)
	{
		list_array[i] = 0;
	}
	avlTree->destroy(root);
	m_scene->clearScreen();//清屏
}
void CBinarySortTreeEditorUI::goToBeginButton()
{
	endplaybuttonflag = 1;
	timestamp = 0;
	m_scene->clearScreen();//清屏
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
		m_scene->clearScreen();//清屏
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
		m_scene->clearScreen();//清屏
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
		m_scene->clearScreen();//清屏
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
	m_scene->clearScreen();//清屏
	timestamp = onlytotaltime;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	m_quickHelp->btree_create_code(insertIdCode[timestamp]);
	//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
}
void CBinarySortTreeEditorUI::inOrderPrint(CBiTreeNode* root, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame)//递归展示函数
{
	if (root == NULL)
		return;
	wideSize = wideSize / 2;//每次将单位值除以二，绘制在根节点的左右
	if (root->left != NULL)
	{
		frametime[frame]++;
		insertIdCode[frametime[frame]] = 2;
		animationRecord(onlytotaltime, frametime[frame], x, y, -2, -1, p_x, p_y);
		inOrderPrint(root->left, x - wideSize, y + highSize, wideSize, highSize, x, y,
			frame);//访问左孩子
	}
	if (root->right != NULL)
	{
		frametime[frame]++;
		insertIdCode[frametime[frame]] = 3;
		animationRecord(onlytotaltime, frametime[frame], x, y, -2, -1, p_x, p_y);
		inOrderPrint(root->right, x + wideSize, y + highSize, wideSize, highSize, x,
			y, frame);//访问右孩子
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
	wideSize = wideSize / 2;//每次将单位值除以二，绘制在根节点的左右
	if (root != NULL)
	{
		if (root->key == data)//找过
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x,
				p_y, 1, 2);//记录 找到 2
			animationPrint(0, framesearchtime);
			return;
		}
		else if (data < root->key)//找过
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x,
				p_y, 1, 3);//记录 3
			animationPrint(0, framesearchtime);
		}
		else if (data > root->key)//找过
		{
			framesearchtime++;
			animationSearchRecord(0, framesearchtime, x, y, root->key, -1, p_x,
				p_y, 1, 5);//记录 5
			animationPrint(0, framesearchtime);
		}
	}
	if (root->left != NULL && data < root->key)
	{
		inOrderPrint_search(root->left, x - wideSize, y + highSize, wideSize,
			highSize, x, y, data, 1);//左孩子
	}
	if (root->right != NULL && data > root->key)
	{
		inOrderPrint_search(root->right, x + wideSize, y + highSize, wideSize,
			highSize, x, y, data, 2);//右孩子
	}
}
void CBinarySortTreeEditorUI::inOrderPrint_SimulationTree(CBiTreeNode*
	root, double x,
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
		inOrderPrint_SimulationTree(root->left, x + Branch_length_x, y -
			Branch_length_y, Branch_length * 0.8, angle, Change_angle, x, y);//左孩子
	}
	if (root->right != NULL)
	{
		double angle = Branch_angle - Change_angle + 2;//顺时针角度
		double radian = angle * 3.14159265 / 180; //计算弧度
		double Branch_length_x = Branch_length * cos(radian);//x 位移
		double Branch_length_y = Branch_length * sin(radian);//y 位移
		inOrderPrint_SimulationTree(root->right, x + Branch_length_x, y -
			Branch_length_y, Branch_length * 0.8, angle, Change_angle, x, y);//右孩子
	}
	//绘制当前节点
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
void CBinarySortTreeEditorUI::PreOrderBiTree(CBiTreeNode* root, string& In)//先序遍历
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
void CBinarySortTreeEditorUI::PostOrderBiTree(CBiTreeNode* root, string
	& In) //后序遍历
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
//往二叉堆中插入元素
bool CBinarySortTreeEditorUI::insertBigRootTree(int val, BigRoot* bigrootTree)
{
	return bigrootTree->insert(val);
}
//从二叉堆中删除元素
bool CBinarySortTreeEditorUI::removeBigRootTree(int val, BigRoot*
	bigrootTree)
{
	return bigrootTree->remove(val);
}
//打印二叉堆
void CBinarySortTreeEditorUI::printBigRootTree(BigRoot* bigrootTree)
{
	bigrootTree->print();
}
//获取堆顶元素
int CBinarySortTreeEditorUI::getTopBigRootTree(BigRoot* bigrootTree)
{
	return bigrootTree->getTop();
}
//根据指定数组创建大顶堆
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
	wideSize = wideSize / 2;//每次将单位值除以二，绘制在根节点的左右
	if (2 * index + 1 < bigrootTree->getSize())
		Print_BigRootTree(2 * index + 1, bigrootTree, x - wideSize, y + highSize,
			wideSize, highSize, x, y);//左孩子
	if (2 * index + 2 < bigrootTree->getSize())
		Print_BigRootTree(2 * index + 2, bigrootTree, x + wideSize, y + highSize,
			wideSize, highSize, x, y);//右孩子
	if (index < bigrootTree->getSize())
		m_scene->drawCircle(x, y, bigrootTree->getIndexNum(index), p_x, p_y);
}
void CBinarySortTreeEditorUI::on_bigroottree_create_btn_clicked()
{
	m_scene->clearScreen();//清屏
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
	bigrootTree = new BigRoot(1010);
	//逐个元素创建大顶堆
	for (int i = 0; i < list.size(); i++)
		bigrootTree->insert(list_array[i]);
	qDebug() << "top is:" << bigrootTree->getTop() << endl;
	bigrootTree->print();
	//求二叉树的深度
	int depth = 0;
	depth = int(log2(bigrootTree->getSize())) + 1;
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
	//打印大根堆
	Print_BigRootTree(0, bigrootTree, 0, 0, wideSize, highSize, 0, 0);
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
}
void CBinarySortTreeEditorUI::on_bigroottree_insert_btn_clicked()
{
	m_scene->clearScreen();//清屏
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
		list_temp[i] = x;//将存为数组
	}
	bigrootTree->insert(list_temp[0]);
	bigrootTree->print();
	//求二叉树的深度
	int depth = 0;
	depth = int(log2(bigrootTree->getSize())) + 1;
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
	//打印大根堆
	Print_BigRootTree(0, bigrootTree, 0, 0, wideSize, highSize, 0, 0);
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
}
void CBinarySortTreeEditorUI::on_bigroottree_remove_btn_clicked()
{
	m_scene->clearScreen();//清屏
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
		list_temp[i] = x;//将存
	}
	//bigrootTree->insert(list_temp[0]);
	bigrootTree->remove(list_temp[0]);
	bigrootTree->print();
	//求二叉树的深度
	int depth = 0;
	depth = int(log2(bigrootTree->getSize())) + 1;
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
	//打印大根堆
	Print_BigRootTree(0, bigrootTree, 0, 0, wideSize, highSize, 0, 0);
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
}
//B 树
///////////////////////////
//初始化 B 树
Status CBinarySortTreeEditorUI::InitBTree(BTree& t) {
	t = NULL;
	return OK;
}
//结点中查找关键字 k 插入位置 i 
int CBinarySortTreeEditorUI::SearchBTNode(BTNode* p, KeyType k) {
	int i = 0;
	for (i = 0; i < p->keynum && p->key[i + 1] <= k; i++);
	return i;
}
//在树 t 上查找关键字
Result CBinarySortTreeEditorUI::SearchBTree(BTree t, KeyType k) {
	BTNode* p = t, * q = NULL; //待查结点指针 p,p 的双亲指针 q
		int flag = 0, i = 0; //flag 1 成功，2 失败
	Result r;
	while (p != NULL && flag == 0) {
		i = SearchBTNode(p, k); //在结点 p 中查找关键字 k,使得 p->key[i] <= k < p->key[i + 1]
			if (i > 0 && p->key[i] == k) //找到待查关键字
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
	return r; //返回关键字 k 的位置
}
void CBinarySortTreeEditorUI::InsertBTNode(BTNode*& p, int i, KeyType k,
	BTNode* q) {
	//将关键字 k 和结点 q 分别插入到 p->key[i+1]和 p->ptr[i+1]中
	int j;
	for (j = p->keynum; j > i; j--) { //整体后移空出一个位置
			p->key[j + 1] = p->key[j];
		p->ptr[j + 1] = p->ptr[j];
	}
	p->key[i + 1] = k;
	p->ptr[i + 1] = q;
	if (q != NULL)
		q->parent = p;
	p->keynum++;
}
//将结点 p 分裂成两个结点,前一半保留,后一半移入结点 q
void CBinarySortTreeEditorUI::SplitBTNode(BTNode*& p, BTNode*& q) {
	int i, s = (m + 1) / 2;
	q = (BTNode*)malloc(sizeof(BTNode)); //给结点 q 分配空间
	q->ptr[0] = p->ptr[s]; //后一半移入结点 q
	for (i = s + 1; i <= m; i++) {
		q->key[i - s] = p->key[i];
		q->ptr[i - s] = p->ptr[i];
	}
	q->keynum = p->keynum - s;
	q->parent = p->parent;
	for (i = 0; i <= p->keynum - s; i++) //修改双亲指针
		if (q->ptr[i] != NULL)
			q->ptr[i]->parent = q;
	p->keynum = s - 1; //结点 p 的前一半保留, 修改结点 p 的 keynum
}
//生成新的根结点 t,原 p 和 q 为子树指针
void CBinarySortTreeEditorUI::NewRoot(BTNode*& t, KeyType k, BTNode* p,
	BTNode* q) {
	t = (BTNode*)malloc(sizeof(BTNode)); //分配空间
	t->keynum = 1;
	t->ptr[0] = p;
	t->ptr[1] = q;
	t->key[1] = k;
	if (p != NULL) //调整结点 p 和结点q 的双亲指针
		p->parent = t;
	if (q != NULL)
		q->parent = t;
	t->parent = NULL;
}
//插入关键字 k，若过大则分裂
void CBinarySortTreeEditorUI::InsertBTree(BTree& t, int i, KeyType k, BTNode
	* p) {
	BTNode* q;
	int endflag, newflag, s; //设定需要新结点标志和插入完成标志
		KeyType x;
	if (p == NULL) //t 是空树
		NewRoot(t, k, NULL, NULL); //生成仅含关键字 k的根结点 t
	else {
		x = k;
		q = NULL;
		endflag = 0;
		newflag = 0;
		while (endflag == 0 && newflag == 0) {
			InsertBTNode(p, i, x, q); //将关键字 x 和结点 q分别插入到 p->key[i + 1]和 p->ptr[i + 1]
				if (p->keynum <= Max)
					endflag = 1; //插入完成
				else {
					s = (m + 1) / 2;
					SplitBTNode(p, q); //分裂结点
					x = p->key[s];
					if (p->parent) { //查找 x 的插入位置
						p = p->parent;
						i = SearchBTNode(p, x);
					}
					else //没找到 x，需要新结点
						newflag = 1;
				}
		}
		if (newflag == 1) //根结点已分裂为结点 p 和q
			NewRoot(t, x, p, q); //生成新根结点 t,p 和 q 为子树指针
	}
}
void CBinarySortTreeEditorUI::Remove(BTNode* p, int i) {
	int j;
	for (j = i + 1; j <= p->keynum; j++) { //前移删除 key[i]和 ptr[i]
		p->key[j - 1] = p->key[j];
		p->ptr[j - 1] = p->ptr[j];
	}
	p->keynum--;
}
//查找被删关键字 p->key[i](在非叶子结点中)的替代叶子结点(右子树中值最小的关键字)
void CBinarySortTreeEditorUI::Substitution(BTNode* p, int i) {
	BTNode* q;
	for (q = p->ptr[i]; q->ptr[0] != NULL; q = q->ptr[0]);
	p->key[i] = q->key[1]; //复制关键字值
}
/*将双亲结点 p 中的最后一个关键字移入右结点 q 中
将左结点 aq 中的最后一个关键字移入双亲结点 p 中*/
void CBinarySortTreeEditorUI::MoveRight(BTNode* p, int i) {
	int j;
	BTNode* q = p->ptr[i];
	BTNode* aq = p->ptr[i - 1];
	for (j = q->keynum; j > 0; j--) { //将右兄弟 q 中所有关键字向后移动一位
			q->key[j + 1] = q->key[j];
		q->ptr[j + 1] = q->ptr[j];
	}
	q->ptr[1] = q->ptr[0]; //从双亲结点 p 移动关键字到右兄弟 q 中
		q->key[1] = p->key[i];
	q->keynum++;
	p->key[i] = aq->key[aq->keynum]; //将左兄弟 aq 中最后一个关键字移动到双亲结点 p 中
		p->ptr[i]->ptr[0] = aq->ptr[aq->keynum];
	aq->keynum--;
}
void CBinarySortTreeEditorUI::MoveLeft(BTNode* p, int i) {
	/*将双亲结点 p 中的第一个关键字移入左结点 aq 中，
	将右结点 q 中的第一个关键字移入双亲结点 p 中*/
	int j;
	BTNode* aq = p->ptr[i - 1];
	BTNode* q = p->ptr[i];
	aq->keynum++; //双亲结点关键字移动到左兄弟 aq 中
		aq->key[aq->keynum] = p->key[i];
	aq->ptr[aq->keynum] = p->ptr[i]->ptr[0];
	p->key[i] = q->key[1]; //把右兄弟 q 中的关键字移动到双亲节点 p 中
		q->ptr[0] = q->ptr[1];
	q->keynum--;
	for (j = 1; j <= aq->keynum; j++) { //将右兄弟 q 中所有关键字向前移动一位
			aq->key[j] = aq->key[j + 1];
		aq->ptr[j] = aq->ptr[j + 1];
	}
}
void CBinarySortTreeEditorUI::Combine(BTNode* p, int i) {
	/*将双亲结点 p、右结点 q 合并入左结点 aq，
	并调整双亲结点 p 中的剩余关键字的位置*/
	int j;
	BTNode* q = p->ptr[i];
	BTNode* aq = p->ptr[i - 1];
	aq->keynum++; //将双亲结点的关键字p->key[i]插入到左结点 aq
		aq->key[aq->keynum] = p->key[i];
	aq->ptr[aq->keynum] = q->ptr[0];
	for (j = 1; j <= q->keynum; j++) { //将右结点 q 中的所有关键字插入到左结点 aq
			aq->keynum++;
		aq->key[aq->keynum] = q->key[j];
		aq->ptr[aq->keynum] = q->ptr[j];
	}
	for (j = i; j < p->keynum; j++) { //将双亲结点 p 中的p->key[i]后的所有关键字向前移动一位
			p->key[j] = p->key[j + 1];
		p->ptr[j] = p->ptr[j + 1];
	}
	p->keynum--; //修改双亲结点 p 的keynum 值
		free(q); //释放空右结点 q 的空间
}
void CBinarySortTreeEditorUI::AdjustBTree(BTNode* p, int i) {
	//删除结点 p 中的第 i 个关键字后,调整 B 树
	if (i == 0) //删除的是最左边关键字
		if (p->ptr[1]->keynum > Min) //右结点可以借
			MoveLeft(p, 1);
		else //右兄弟不够借
			Combine(p, 1);
	else if (i == p->keynum) //删除的是最右边关键字
		if (p->ptr[i - 1]->keynum > Min) //左结点可以借
			MoveRight(p, i);
		else //左结点不够借
			Combine(p, i);
	else if (p->ptr[i - 1]->keynum > Min) //删除关键字在中部且左结点够借
		MoveRight(p, i);
	else if (p->ptr[i + 1]->keynum > Min) //删除关键字在中部且右结点够借
		MoveLeft(p, i + 1);
	else //删除关键字在中部且左右结点都不够借
		Combine(p, i);
}
int CBinarySortTreeEditorUI::FindBTNode(BTNode* p, KeyType k, int& i) {
	//反映是否在结点 p 中是否查找到关键字 k 
	if (k < p->key[1]) { //结点 p 中查找关键字k 失败
			i = 0;
		return 0;
	}
	else { //在 p 结点中查找
		i = p->keynum;
		while (k < p->key[i] && i>1)
			i--;
		if (k == p->key[i]) //结点 p 中查找关键字k 成功
			return 1;
	}
}
int CBinarySortTreeEditorUI::BTNodeDelete(BTNode* p, KeyType k) {
	//在结点 p 中查找并删除关键字 k
	int i;
	int found_tag; //查找标志
	if (p == NULL)
		return 0;
	else {
		found_tag = FindBTNode(p, k, i); //返回查找结果
		if (found_tag == 1) { //查找成功
			if (p->ptr[i - 1] != NULL) { //删除的是非叶子结点
					Substitution(p, i); //寻找相邻关键字(右子树中最小的关键字)
				BTNodeDelete(p->ptr[i], p->key[i]); //执行删除操作
			}
			else
				Remove(p, i); //从结点 p 中位置 i 处删除关键字
		}
		else
			found_tag = BTNodeDelete(p->ptr[i], k); //沿孩子结点递归查找并删除关键字 k
			if (p->ptr[i] != NULL)
				if (p->ptr[i]->keynum < Min) //删除后关键字个数小于 MIN
					AdjustBTree(p, i); //调整 B 树
		return found_tag;
	}
}
void CBinarySortTreeEditorUI::BTreeDelete(BTree& t, KeyType k) {
	//构建删除框架，执行删除操作 
	BTNode* p;
	int a = BTNodeDelete(t, k); //删除关键字 k 
	if (a == 0) //查找失败
		printf(" 关键字%d 不在 B 树中\n", k);
	else if (t->keynum == 0) { //调整
		p = t;
		t = t->ptr[0];
		free(p);
	}
}
void CBinarySortTreeEditorUI::DestroyBTree(BTree& t) {
	//递归释放 B 树
	int i;
	BTNode* p = t;
	if (p != NULL) { //B 树不为空 
		for (i = 0; i <= p->keynum; i++) { //递归释放每一个结点
				DestroyBTree(*&p->ptr[i]);
		}
		free(p);
	}
	t = NULL;
}
Status CBinarySortTreeEditorUI::InitQueue(LinkList& L) {
	//初始化队列
	L = (LNode*)malloc(sizeof(LNode)); //分配结点空间
	if (L == NULL) //分配失败 
		return OVERFLOW1;
	L->next = NULL;
	return OK;
}
LNode* CBinarySortTreeEditorUI::CreateNode1(BTNode* p) {
	//新建一个结点
	LNode* q;
	q = (LNode*)malloc(sizeof(LNode)); //分配结点空间
	if (q != NULL) { //分配成功
		q->data = p;
		q->next = NULL;
	}
	return q;
}
Status CBinarySortTreeEditorUI::Enqueue1(LNode* p, BTNode* q) {
	//元素 q 入队列
	if (p == NULL)
		return ERROR;
	while (p->next != NULL) //调至队列最后
		p = p->next;
	p->next = CreateNode1(q); //生成结点让 q 进入队列
		return OK;
}
Status CBinarySortTreeEditorUI::Dequeue(LNode* p, BTNode*& q) {
	//出队列，并以 q 返回值
	LNode* aq;
	if (p == NULL || p->next == NULL) //删除位置不合理
		return ERROR;
	aq = p->next; //修改被删结点 aq 的指针域
		p->next = aq->next;
	q = aq->data;
	free(aq); //释放结点 aq
	return OK;
}
Status CBinarySortTreeEditorUI::IfEmpty(LinkList L) {
	//队列判空
	if (L == NULL) //队列不存在
		return ERROR;
	if (L->next == NULL) //队列为空
		return TRUE;
	return FALSE; //队列非空
}
void CBinarySortTreeEditorUI::DestroyQueue(LinkList L) {
	//销毁队列
	LinkList p;
	if (L != NULL) {
		p = L;
		L = L->next;
		free(p); //逐一释放
		DestroyQueue(L);
	}
}
Status CBinarySortTreeEditorUI::Traverse(BTree t, LinkList L, int newline, int
	sum) {
	//用队列遍历输出 B 树
	int i;
	BTree p;
	if (t != NULL) {
		//qDebug() << " [ ";
		Enqueue1(L, t->ptr[0]); //入队 
		for (i = 1; i <= t->keynum; i++) //同一个节点输出 节点关键字个数keynum
		{
		qDebug() << t->key[i]; //节点关键字数组 key[i]
		Enqueue1(L, t->ptr[i]); //子结点入队
		}
		sum += t->keynum + 1;
		//qDebug() << "]";
		if (newline == 0) { //需要另起一行
			qDebug() << "\n";
			newline = sum - 1;
			sum = 0;
		}
		else
			newline--;
	}
	if (IfEmpty(L) == FALSE) { //l 不为空
		Dequeue(L, p); //出队，以 p 返回
		Traverse(p, L, newline, sum); //遍历出队结点
	}
	return OK;
}
Status CBinarySortTreeEditorUI::PrintBTree(BTree t) {
	//输出 B 树
	LinkList L;
	if (t == NULL) {
		qDebug() << "BTree is empty";
		return OK;
	}
	InitQueue(L); //初始化队列
	Traverse(t, L, 0, 0); //利用队列输出
	DestroyQueue(L); //销毁队列
	return OK;
}
void CBinarySortTreeEditorUI::on_Btree_create_btn_clicked() {
	int i, k;
	DestroyBTree(t);//先清空 B 树
	m_scene->clearScreen();//清屏
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
	{
		k = list_array[i];
		s = SearchBTree(t, k);
		InsertBTree(t, s.i, k, s.pt); //插入元素
	}
	qDebug() << "Now BTree is\n";
	PrintBTree(t);
	//求二叉树的深度
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
	//求树的每层标准高度
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75)
	{
		highSize = 75;
	}
	//求树的最后一层间隔数量
	double wide = pow(3, depth) - 1;
	//求树的最后一层间隔宽度
	double wideSize = 9 * wide;
	//打印 B_树
	Print_BTree(t, 0, 0, wideSize, highSize, 0, 0);
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
}
//B 树添加节点功能
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
	//求二叉树的深度
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
	//求树的每层标准高度
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75)
	{
		highSize = 75;
	}
	//求树的最后一层间隔数量
	double wide = pow(3, depth) - 1;
	//求树的最后一层间隔宽度
	double wideSize = 9 * wide;
	//打印大根堆
	Print_BTree(t, 0, 0, wideSize, highSize, 0, 0);
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
}
//B 树删除
void CBinarySortTreeEditorUI::on_Btree_remove_btn_clicked() {
	m_scene->clearScreen(); //清屏
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
	BTreeDelete(t, k); //删除元素
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
	//求树的最后一层间隔数量
	double wide = pow(3, depth) - 1;
	//求树的最后一层间隔宽度
	double wideSize = 9 * wide;
	//打印大根堆
	Print_BTree(t, 0, 0, wideSize, highSize, 0, 0);
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
}
//B 树销毁
void CBinarySortTreeEditorUI::on_Btree_destroy_btn_clicked()
{
	DestroyBTree(t);
	PrintBTree(t);
	m_scene->clearScreen();//清屏
}
void CBinarySortTreeEditorUI::Print_BTree(BTree bTree, double x,
	double y, double wideSize, double highSize, double p_x, double p_y)
{
	if (bTree == NULL)
		return;
	wideSize = wideSize / 3;//每次将单位值除以二，绘制在根节点的左右
	if (bTree->keynum == 1)
	{
		if (bTree->ptr[0] != NULL)
			Print_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y);//左孩子
		else
		{
			m_scene->drawCircle(x, y + highSize, -1, x, y);
		}
		if (bTree->ptr[1] != NULL)
			Print_BTree(bTree->ptr[1], x + wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y);//右孩子
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
				highSize, x, y);//左孩子
		else
		{
			m_scene->drawCircle(x, y + highSize, -1, x, y);
		}
		if (bTree->ptr[2] != NULL)
			Print_BTree(bTree->ptr[2], x + wideSize * 1.5, y + highSize, wideSize,
				highSize, x, y);//右孩子
		else
		{
			m_scene->drawCircle(x, y + highSize, -1, x, y);
		}
		if (bTree->ptr[1] != NULL)
			Print_BTree(bTree->ptr[1], x, y + highSize, wideSize, highSize, x, y);//中孩子
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
	wideSize = wideSize / 3;//每次将单位值除以二，绘制在根节点的左右
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
				highSize, x, y, frame);//左孩子
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
				highSize, x, y, frame);//右孩子
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
				highSize, x, y, frame);//左孩子
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
				frame);//中孩子
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
				highSize, x, y, frame);//右孩子
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
		return;//未找到
	wideSize = wideSize / 3;//每次将单位值除以二，绘制在根节点的左右
	if (bTree != NULL)
	{
		if (bTree->keynum == 1)
		{
			if (bTree->key[1] == key)//找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					-1, p_x, p_y, 1, 2);//记录 找到 2
				animationPrint(0, framesearchtime);
			}
			else if (key < bTree->key[1])//找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					-1, p_x, p_y, 1, 3);//记录 3
				animationPrint(0, framesearchtime);
			}
			else if (key > bTree->key[2])//找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					-1, p_x, p_y, 1, 5);//记录 5
				animationPrint(0, framesearchtime);
			}
		}
		if (bTree->keynum == 2)
		{
			if (bTree->key[1] == key || bTree->key[2] == key)//找到
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 2);//记录 2
				animationPrint(0, framesearchtime);
			}
			else if (key < bTree->key[1]) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 3);//记录 3
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[1] < key && key < bTree->key[2]) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 4);//记录 4
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[2] < key) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 5);//记录 5
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
					highSize, wideSize, highSize, x, y, frame, key);//左孩子
			}
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -
					1, x, y, 1, 6);//记录 6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[1])
		{
			if (bTree->ptr[1] != NULL)
				Print_Search_BTree(bTree->ptr[1], x + wideSize * 1.5, y +
					highSize, wideSize, highSize, x, y, frame, key);//右孩子
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -
					1, x, y, 1, 6);//记录 6
				animationPrint(0, framesearchtime);
			}
		}
	}
	if (bTree->keynum == 2)
	{
		if (bTree != NULL)
		{
			if (bTree->key[1] == key || bTree->key[2] == key)//找到
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 2);//记录 2
				animationPrint(0, framesearchtime);
			}
			else if (key < bTree->key[1]) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 3);//记录 3
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[1] < key && key < bTree->key[2]) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 4);//记录 4
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[2] < key) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1],
					bTree->key[2], p_x, p_y, 1, 5);//记录 5
				animationPrint(0, framesearchtime);
			}
		}
		if (key < bTree->key[1])//找到
		{
			if (bTree->ptr[0] != NULL)
				Print_Search_BTree(bTree->ptr[0], x - wideSize * 1.5, y +
					highSize, wideSize, highSize, x, y, frame, key);//左孩子
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -
					1, x, y, 1, 6);//记录 6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[1] && key < bTree->key[2])//找到
		{
			if (bTree->ptr[1] != NULL)
				Print_Search_BTree(bTree->ptr[1], x, y + highSize, wideSize,
					highSize, x, y, frame, key);//中孩子
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -
					1, x, y, 1, 6);//记录 6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[2])//找到
		{
			if (bTree->ptr[2] != NULL)
				Print_Search_BTree(bTree->ptr[2], x + wideSize * 1.5, y +
					highSize, wideSize, highSize, x, y, frame, key);//右孩子
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -
					1, x, y, 1, 6);//记录 6
				animationPrint(0, framesearchtime);
			}
		}
	}
}
void CBinarySortTreeEditorUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//获取自定义休眠时间
		while (QTime::currentTime() < dieTime)
		{
			QCoreApplication::processEvents(QEventLoop::AllEvents, 100);// 开 启新线程，处理 qt 界面事件
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
	for (int i = 0; i < frametime; i++) //遍历整个动画
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
//以下是创建平衡二叉树
void CBinarySortTreeEditorUI::on_binarytree_create_btn_clicked()
{
	int depth;
	
	m_scene->clearScreen();//清屏
	avlTree = new CBiTree();//新建树
	root = avlTree->getRoot();//新建节点
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
		list_array[i] = x;//存为数组
	}
	for (int i = 0; i < list.size(); i++)
	{
		root = avlTree->insert(root, list_array[i]);
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
		frametime[i] = 0;
		onlytotaltime = i;
		history_wideSize[i] = wideSize;
		history_highSize[i] = highSize;
		//insertIdCode[i] = codeid;
		//递归展示二叉树 单位宽度为 15 个像素
		inOrderPrint(root, 0, 0, wideSize, highSize, 0, 0, i);
	}
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
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}*/
	
	
	//string InOrd;
	//PreOrder(root, InOrd);
	//QString temp = "DLR:" + QString::fromStdString(InOrd);
	//m_scene->printInOrd(100, -200, temp);

	//m_scene->clearScreen();//清屏

	/*m_quickHelp->btree_create_code(insertIdCode[frametime[onlytotaltime]]);
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
	timestamp = 0;*/
	
}
//二叉树节点删除函数
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
	m_scene->addUndoState();*/
	
}
//平衡二叉树节点查找函数
void CBinarySortTreeEditorUI::on_binarytree_node_search_btn_clicked()
{
	QString data = ui->BinaryTreeDataEdit_2->text();
	bool flag;
	int x = data.toUInt(&flag);
	if (!flag)
		return;
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
	//在LineEdit中输出
	QString a=QString::number(depth, 10);
	ui->BinaryTreeDataEdit->insert(a);
	//求树的每层标准高度
	double highSize = 2400 * 0.618 / (double)depth;
	if (highSize > 75) {
		highSize = 75;
	}
	//求树的最后一层间隔数量
	double wide = pow(2, depth) - 1;
	//求树的最后一层间隔宽度
	double wideSize = 9 * wide;
	framesearchtime = 0;
	//onlytotaltime = 0;
	history_wideSize[0] = wideSize;
	history_highSize[0] = highSize;
	//递归展示二叉树 单位宽度为 15 个像素
	inOrderPrint_search(root, 0, 0, wideSize, highSize, 0, 0, x, 0);
	m_scene->clearScreen();//清屏
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}	
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
	for (int j = 0; j <= framesearchtime; j++)
	{
		animationDrawSearch(0, j, x);
		sleepTime(500);
	}
	timestamp = 0;
	
}