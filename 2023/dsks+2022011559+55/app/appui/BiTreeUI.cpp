#include "BiTreeUI.h"


BiTreeUI::BiTreeUI(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::BiTreeUI),
	m_scene(NULL)
{
	ui->setupUi(this);
}
void BiTreeUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);
}
void BiTreeUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);
	m_scene = scene;
	setEnabled(m_scene);
	if (m_scene)
		onSceneAttached(m_scene);
}

void BiTreeUI::onSceneAttached(CEditorScene* scene)
{
}
void BiTreeUI::setCQuickHelpUI(CQuickHelpUI* quickHelp)
{
	m_quickHelp = quickHelp;
	setEnabled(m_quickHelp);
}

void BiTreeUI::setCEditorView(CEditorView* editorView)
{
	m_editorView = editorView;
	setEnabled(m_editorView);
}



BiTreeUI::~BiTreeUI()
{
}

void BiTreeUI::goToBeginButton()
{
	endplaybuttonflag = 1;
	timestamp = 0;
	m_scene->clearScreen();//清屏
	for (int j = 0; j <= frametime[0]; j++)
	{
		animationDraw(0, j);
	}
	m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
}

void BiTreeUI::stepBackButton()
{
	endplaybuttonflag = 1;
	if (timestamp > 0)
	{
		timestamp--;
		m_scene->clearScreen();//清屏
		for (int j = 0; j <= frametime[timestamp]; j++)
		{
			animationDraw(timestamp, j);
		}
		m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
	}
}

void BiTreeUI::playButton()
{
	endplaybuttonflag = 0;
	for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1; timestamp++)
	{
		m_scene->clearScreen();//清屏


		for (int j = 0; j <= frametime[timestamp]; j++)
		{
			animationDraw(timestamp, j);
		}

		m_quickHelp->btree_insert_code(insertIdCode[timestamp]);

		sleepTime(500);


	}
}

void BiTreeUI::suspendButton()
{
	endplaybuttonflag = 1;
}

void BiTreeUI::stepForwardButton()
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
		m_quickHelp->btree_insert_code(insertIdCode[timestamp]);
	}
}

void BiTreeUI::goToEndButton()
{
	endplaybuttonflag = 1;
	m_scene->clearScreen();//清屏
	timestamp = onlytotaltime;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	m_quickHelp->btree_insert_code(insertIdCode[timestamp]);

}

void BiTreeUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//获取自定义休眠时间
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);	//开启新线程，处理qt界面事件
	}
}
void BiTreeUI::animationRecord(int totaltime, int frame, int x, int y, int data1, int data2, int p_x, int p_y)
{
	animation[totaltime][frame].x = x;
	animation[totaltime][frame].y = y;
	animation[totaltime][frame].data1 = data1;
	animation[totaltime][frame].data2 = data2;
	animation[totaltime][frame].p_x = p_x;
	animation[totaltime][frame].p_y = p_y;
}
void BiTreeUI::animationSearchRecord(int totaltime, int frame, int x, int y, int data1, int data2, int p_x, int p_y, int flag, int codeid)
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
void BiTreeUI::animationClean()
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
void BiTreeUI::animationPrint(int totaltime, int frametime)
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
void BiTreeUI::animationDraw(int totaltime, int frametime)
{
	for (int i = 0; i < frametime; i++)		//遍历整个动画
	{
		if (animation[totaltime][frametime].data2 == -1) {
			m_scene->drawCircle(animation[totaltime][frametime].x, animation[totaltime][frametime].y,
				animation[totaltime][frametime].data1, animation[totaltime][frametime].p_x, animation[totaltime][frametime].p_y);
		}
		else if (animation[totaltime][frametime].data1 != -1) {
			m_scene->drawCircle2(animation[totaltime][frametime].x, animation[totaltime][frametime].y,
				animation[totaltime][frametime].data1, animation[totaltime][frametime].data2, animation[totaltime][frametime].p_x, animation[totaltime][frametime].p_y);
		}
	}
}
void BiTreeUI::animationDrawSearch(int totaltime, int frametime)
{
	for (int i = 0; i < frametime; i++)		//遍历整个动画
	{
		if (animationSearch[totaltime][frametime].data2 == -1)
		{
			m_scene->drawCircleSearch(animationSearch[totaltime][frametime].x, animationSearch[totaltime][frametime].y, animationSearch[totaltime][frametime].data1,
				animationSearch[totaltime][frametime].p_x, animationSearch[totaltime][frametime].p_y);
			m_quickHelp->btree_search_code(animationSearch[totaltime][frametime].codeid);
		}
		else
		{
			m_scene->drawCircleSearch2(animationSearch[totaltime][frametime].x, animationSearch[totaltime][frametime].y, animationSearch[totaltime][frametime].data1,
				animationSearch[totaltime][frametime].data2, animationSearch[totaltime][frametime].p_x, animationSearch[totaltime][frametime].p_y);
			m_quickHelp->btree_search_code(animationSearch[totaltime][frametime].codeid);
		}
	}
}
//判别语句是否为数字和,
bool IsNumber_(QString qstrSrc)
{
	QByteArray ba = qstrSrc.toLatin1();
	const char *s = ba.data();
	bool bret = true;
	while (*s)
	{
		if (*s<'0' || *s>'9')
		{
			if (*s != ',')
			{
				bret = false;
				break;
			}
		}
		s++;
	}
	return bret;
}
//判别语句是否为数字
bool IsNumber(QString qstrSrc)
{
	QByteArray ba = qstrSrc.toLatin1();
	const char *s = ba.data();
	bool bret = true;
	while (*s)
	{
		if (*s<'0' || *s>'9') {
			bret = false;
			break;
		}
		s++;
	}
	return bret;
}
//B树添加节点功能
void BiTreeUI::on_Btree_insert_btn_clicked()
{
	QString data = ui->BinaryTreeDataEdit_2->text();
	if (!IsNumber(data)) QMessageBox::critical(this, QString::fromLocal8Bit("输入错误"), QString::fromLocal8Bit("节点数据输入必须为数字"));
	else
	{
		m_scene->clearScreen();
		list = data.split(",");
		int list_temp[1010];
		int codeid;
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

		codeid = InsertBTree(t, s.i, k, s.pt);
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
		onlytotaltime++;
		frametime[onlytotaltime] = 0;
		history_wideSize[onlytotaltime] = wideSize;
		history_highSize[onlytotaltime] = highSize;
		insertIdCode[onlytotaltime] = codeid;
		Print_BTree(t, 0, 0, wideSize, highSize, 0, 0, onlytotaltime);

		m_scene->clearScreen();//清屏
		for (int j = 0; j <= frametime[onlytotaltime]; j++)
		{
			animationDraw(onlytotaltime, j);
		}
		m_quickHelp->btree_insert_code(insertIdCode[onlytotaltime]);
		//适应窗口
		m_editorView->fitToView();
		//适应网格
		m_scene->addUndoState();
	}
}

//B树查找
void BiTreeUI::on_Btree_search_btn_clicked()
{
	//m_scene->clearScreen();
	QString data = ui->BinaryTreeDataEdit_2->text();
	if (!IsNumber(data)) QMessageBox::critical(this, QString::fromLocal8Bit("输入错误"), QString::fromLocal8Bit("节点数据输入必须为数字"));
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

	//m_scene->clearScreen();


	int depth = 0;
	BTree pt;
	pt = t;
	for (int i = 1; ; i++)
	{
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
	//打印B_树
	framesearchtime = 0;
	//onlytotaltime = 0;
	history_wideSize[0] = wideSize;
	history_highSize[0] = highSize;

	Print_Search_BTree(t, 0, 0, wideSize, highSize, 0, 0, 0, k);//一次就完成搜索，主要看j的变化

	///////////////
	m_scene->clearScreen();//清屏
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
	///////////////////////

	for (int j = 0; j <= framesearchtime; j++)
	{
		animationDrawSearch(0, j);
		sleepTime(500);
	}

	timestamp = 0;
}

//B树删除
void BiTreeUI::on_Btree_remove_btn_clicked() {
	QString data = ui->BinaryTreeDataEdit_2->text();
	if (!IsNumber(data)) QMessageBox::critical(this, QString::fromLocal8Bit("输入错误"), QString::fromLocal8Bit("节点数据输入必须为数字"));
	else {
		m_scene->clearScreen();		//清屏
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
		BTreeDelete(t, k);			//删除元素 
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
		onlytotaltime--;
		frametime[onlytotaltime] = 0;
		history_wideSize[onlytotaltime] = wideSize;
		history_highSize[onlytotaltime] = highSize;

		Print_BTree(t, 0, 0, wideSize, highSize, 0, 0, onlytotaltime);
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
}


//B树销毁
void BiTreeUI::on_Btree_destroy_btn_clicked()
{
	DestroyBTree(t);
	PrintBTree(t);
	m_scene->clearScreen();//清屏
}

void BiTreeUI::Print_Search_BTree(BTree bTree, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame, int key)
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
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], -1, p_x, p_y, 1, 2);//记录  找到  2
				animationPrint(0, framesearchtime);
			}
			else if (key < bTree->key[1])//找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], -1, p_x, p_y, 1, 3);//记录			3
				animationPrint(0, framesearchtime);
			}
			else if (key > bTree->key[2])//找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], -1, p_x, p_y, 1, 5);//记录			5
				animationPrint(0, framesearchtime);
			}
		}
		if (bTree->keynum == 2)
		{
			if (bTree->key[1] == key || bTree->key[2] == key)//找到
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 2);//记录	2
				animationPrint(0, framesearchtime);

			}
			else if (key < bTree->key[1]) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 3);//记录	3
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[1] < key && key < bTree->key[2]) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 4);//记录	4
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[2] < key) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 5);//记录	5
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
				Print_Search_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame, key);//左孩子
			}
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -1, x, y, 1, 6);//记录			6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[1])
		{
			if (bTree->ptr[1] != NULL)
				Print_Search_BTree(bTree->ptr[1], x + wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame, key);//右孩子
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -1, x, y, 1, 6);//记录			6
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
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 2);//记录		2
				animationPrint(0, framesearchtime);
			}
			else if (key < bTree->key[1]) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 3);//记录	3
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[1] < key && key < bTree->key[2]) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 4);//记录	4
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[2] < key) //找过
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 5);//记录	5
				animationPrint(0, framesearchtime);
			}
		}


		if (key < bTree->key[1])//找到
		{
			if (bTree->ptr[0] != NULL)
				Print_Search_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame, key);//左孩子
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -1, x, y, 1, 6);//记录				6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[1] && key < bTree->key[2])//找到
		{
			if (bTree->ptr[1] != NULL)
				Print_Search_BTree(bTree->ptr[1], x, y + highSize, wideSize, highSize, x, y, frame, key);//中孩子
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -1, x, y, 1, 6);//记录				6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[2])//找到
		{
			if (bTree->ptr[2] != NULL)
				Print_Search_BTree(bTree->ptr[2], x + wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame, key);//右孩子
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -1, x, y, 1, 6);//记录				6
				animationPrint(0, framesearchtime);
			}
		}
	}
}



//B树
///////////////////////////

//初始化B树 
Status BiTreeUI::InitBTree(BTree &t) {
	t = NULL;
	return OK;
}

//结点中查找关键字k插入位置i 
int BiTreeUI::SearchBTNode(BTNode *p, KeyType k) {
	int i = 0;
	for (i = 0; i < p->keynum&&p->key[i + 1] <= k; i++);
	return i;
}

//在树t上查找关键字
Result BiTreeUI::SearchBTree(BTree t, KeyType k) {
	BTNode *p = t, *q = NULL;                  //待查结点指针p,p的双亲指针q

	int flag = 0, i = 0;                        //flag 1 成功，2 失败 
	Result r;
	while (p != NULL && flag == 0) {
		i = SearchBTNode(p, k);                //在结点p中查找关键字k,使得p->key[i]<=k<p->key[i+1]
		if (i > 0 && p->key[i] == k)           //找到待查关键字
		{
			qDebug() << "p->key[i]" << p->key[i];
			flag = 1;
		}
		else {
			q = p;								//查找孩子指针数组
			p = p->ptr[i];
			if (p != NULL)
			{
				qDebug() << "p->key[i]" << p->key[i];
			}
			else {
				qDebug() << "NULL";
			}
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
	return r;                                       //返回关键字k的位置
}


void BiTreeUI::InsertBTNode(BTNode *&p, int i, KeyType k, BTNode *q) {
	//将关键字k和结点q分别插入到p->key[i+1]和p->ptr[i+1]中
	int j;
	for (j = p->keynum; j > i; j--) {                       //整体后移空出一个位置
		p->key[j + 1] = p->key[j];
		p->ptr[j + 1] = p->ptr[j];
	}
	p->key[i + 1] = k;
	p->ptr[i + 1] = q;
	if (q != NULL)
		q->parent = p;
	p->keynum++;
}

//将结点p分裂成两个结点,前一半保留,后一半移入结点q
void BiTreeUI::SplitBTNode(BTNode *&p, BTNode *&q) {
	int i, s = (m + 1) / 2;
	q = (BTNode *)malloc(sizeof(BTNode));             //给结点q分配空间
	q->ptr[0] = p->ptr[s];                            //后一半移入结点q
	for (i = s + 1; i <= m; i++) {
		q->key[i - s] = p->key[i];
		q->ptr[i - s] = p->ptr[i];
	}
	q->keynum = p->keynum - s;
	q->parent = p->parent;
	for (i = 0; i <= p->keynum - s; i++)               //修改双亲指针 
		if (q->ptr[i] != NULL)
			q->ptr[i]->parent = q;
	p->keynum = s - 1;                                  //结点p的前一半保留,修改结点p的keynum
}

//生成新的根结点t,原p和q为子树指针
void BiTreeUI::NewRoot(BTNode *&t, KeyType k, BTNode *p, BTNode *q) {
	t = (BTNode *)malloc(sizeof(BTNode));             //分配空间 
	t->keynum = 1;
	t->ptr[0] = p;
	t->ptr[1] = q;
	t->key[1] = k;
	if (p != NULL)                                     //调整结点p和结点q的双亲指针 
		p->parent = t;
	if (q != NULL)
		q->parent = t;
	t->parent = NULL;
}

//插入关键字k，若过大则分裂
int BiTreeUI::InsertBTree(BTree &t, int i, KeyType k, BTNode *p) {

	BTNode *q;
	int endflag, newflag, s;                   //设定需要新结点标志和插入完成标志 
	KeyType x;
	int codeid;
	if (p == NULL)                                     //t是空树
	{
		NewRoot(t, k, NULL, NULL);                     //生成仅含关键字k的根结点t
		codeid = 1;//生成根节点
		return codeid;
	}
	else {
		x = k;
		q = NULL;
		endflag = 0;
		newflag = 0;
		while (endflag == 0 && newflag == 0)
		{
			InsertBTNode(p, i, x, q);                  //将关键字x和结点q分别插入到p->key[i+1]和p->ptr[i+1]
			if (p->keynum <= Max)
			{
				endflag = 2;							//若p->keynum <= Max  插入完成
				return codeid;
			}
			else
			{
				s = (m + 1) / 2;
				SplitBTNode(p, q);                   //分裂结点 
				x = p->key[s];
				if (p->parent) {                      //查找x的插入位置
					p = p->parent;
					i = SearchBTNode(p, x);
				}
				else                                //没找到x，需要新结点 
				{
					newflag = 1;
				}
			}
		}

		if (newflag == 1)							 //根结点已分裂为结点p和q 
		{
			NewRoot(t, x, p, q);					//生成新根结点t,p和q为子树指针

			codeid = 3;								//根结点已分裂为结点p和q			 //生成新根结点t,p和q为子树指针
			return codeid;
		}
	}
}


void BiTreeUI::Remove(BTNode *p, int i) {
	int j;
	for (j = i + 1; j <= p->keynum; j++) {           //前移删除key[i]和ptr[i]
		p->key[j - 1] = p->key[j];
		p->ptr[j - 1] = p->ptr[j];
	}
	p->keynum--;
}

//查找被删关键字p->key[i](在非叶子结点中)的替代叶子结点(右子树中值最小的关键字) 
void BiTreeUI::Substitution(BTNode *p, int i) {
	BTNode *q;
	for (q = p->ptr[i]; q->ptr[0] != NULL; q = q->ptr[0]);
	p->key[i] = q->key[1];                            //复制关键字值
}

/*将双亲结点p中的最后一个关键字移入右结点q中
将左结点aq中的最后一个关键字移入双亲结点p中*/
void BiTreeUI::MoveRight(BTNode *p, int i) {

	int j;
	BTNode *q = p->ptr[i];
	BTNode *aq = p->ptr[i - 1];

	for (j = q->keynum; j > 0; j--) {                 //将右兄弟q中所有关键字向后移动一位
		q->key[j + 1] = q->key[j];
		q->ptr[j + 1] = q->ptr[j];
	}

	q->ptr[1] = q->ptr[0];                            //从双亲结点p移动关键字到右兄弟q中
	q->key[1] = p->key[i];
	q->keynum++;

	p->key[i] = aq->key[aq->keynum];                  //将左兄弟aq中最后一个关键字移动到双亲结点p中
	p->ptr[i]->ptr[0] = aq->ptr[aq->keynum];
	aq->keynum--;
}

void BiTreeUI::MoveLeft(BTNode *p, int i) {
	/*将双亲结点p中的第一个关键字移入左结点aq中，
	将右结点q中的第一个关键字移入双亲结点p中*/
	int j;
	BTNode *aq = p->ptr[i - 1];
	BTNode *q = p->ptr[i];

	aq->keynum++;                                   //双亲结点关键字移动到左兄弟aq中
	aq->key[aq->keynum] = p->key[i];
	aq->ptr[aq->keynum] = p->ptr[i]->ptr[0];

	p->key[i] = q->key[1];                            //把右兄弟q中的关键字移动到双亲节点p中
	q->ptr[0] = q->ptr[1];
	q->keynum--;

	for (j = 1; j <= aq->keynum; j++) {                     //将右兄弟q中所有关键字向前移动一位
		aq->key[j] = aq->key[j + 1];
		aq->ptr[j] = aq->ptr[j + 1];
	}
}


void BiTreeUI::Combine(BTNode *p, int i) {
	/*将双亲结点p、右结点q合并入左结点aq，
	并调整双亲结点p中的剩余关键字的位置*/
	int j;
	BTNode *q = p->ptr[i];
	BTNode *aq = p->ptr[i - 1];

	aq->keynum++;                                  //将双亲结点的关键字p->key[i]插入到左结点aq     
	aq->key[aq->keynum] = p->key[i];
	aq->ptr[aq->keynum] = q->ptr[0];

	for (j = 1; j <= q->keynum; j++) {                      //将右结点q中的所有关键字插入到左结点aq 
		aq->keynum++;
		aq->key[aq->keynum] = q->key[j];
		aq->ptr[aq->keynum] = q->ptr[j];
	}

	for (j = i; j < p->keynum; j++) {                       //将双亲结点p中的p->key[i]后的所有关键字向前移动一位 
		p->key[j] = p->key[j + 1];
		p->ptr[j] = p->ptr[j + 1];
	}
	p->keynum--;                                    //修改双亲结点p的keynum值 
	free(q);                                        //释放空右结点q的空间
}


void BiTreeUI::AdjustBTree(BTNode *p, int i) {
	//删除结点p中的第i个关键字后,调整B树
	if (i == 0)                                        //删除的是最左边关键字
		if (p->ptr[1]->keynum > Min)                   //右结点可以借
			MoveLeft(p, 1);
		else                                        //右兄弟不够借 
			Combine(p, 1);
	else if (i == p->keynum)                           //删除的是最右边关键字
		if (p->ptr[i - 1]->keynum > Min)                 //左结点可以借 
			MoveRight(p, i);
		else                                        //左结点不够借 
			Combine(p, i);
	else if (p->ptr[i - 1]->keynum > Min)                //删除关键字在中部且左结点够借 
		MoveRight(p, i);
	else if (p->ptr[i + 1]->keynum > Min)                //删除关键字在中部且右结点够借 
		MoveLeft(p, i + 1);
	else                                            //删除关键字在中部且左右结点都不够借
		Combine(p, i);
}


int BiTreeUI::FindBTNode(BTNode *p, KeyType k, int &i) {
	//反映是否在结点p中是否查找到关键字k 
	if (k < p->key[1]) {                                //结点p中查找关键字k失败 
		i = 0;
		return 0;
	}
	else {                                           //在p结点中查找
		i = p->keynum;
		while (k < p->key[i] && i>1)
			i--;
		if (k == p->key[i])                            //结点p中查找关键字k成功 
			return 1;
	}
}


int BiTreeUI::BTNodeDelete(BTNode *p, KeyType k) {
	//在结点p中查找并删除关键字k
	int i;
	int found_tag;                                  //查找标志 
	if (p == NULL)
		return 0;
	else {
		found_tag = FindBTNode(p, k, i);                //返回查找结果 
		if (found_tag == 1) {                           //查找成功 
			if (p->ptr[i - 1] != NULL) {                  //删除的是非叶子结点
				Substitution(p, i);                  //寻找相邻关键字(右子树中最小的关键字) 
				BTNodeDelete(p->ptr[i], p->key[i]);  //执行删除操作 
			}
			else
				Remove(p, i);                        //从结点p中位置i处删除关键字
		}
		else
			found_tag = BTNodeDelete(p->ptr[i], k);    //沿孩子结点递归查找并删除关键字k
		if (p->ptr[i] != NULL)
			if (p->ptr[i]->keynum < Min)               //删除后关键字个数小于MIN
				AdjustBTree(p, i);                   //调整B树 
		return found_tag;
	}
}


void BiTreeUI::BTreeDelete(BTree &t, KeyType k) {
	//构建删除框架，执行删除操作  
	BTNode *p;
	int a = BTNodeDelete(t, k);                        //删除关键字k 
	if (a == 0)                                        //查找失败 
		printf("   关键字%d不在B树中\n", k);
	else if (t->keynum == 0) {                          //调整 
		p = t;
		t = t->ptr[0];
		free(p);
	}
}


void BiTreeUI::DestroyBTree(BTree &t) {
	//递归释放B树 
	int i;
	BTNode* p = t;
	if (p != NULL) {                                    //B树不为空  
		for (i = 0; i <= p->keynum; i++) {                  //递归释放每一个结点 
			DestroyBTree(*&p->ptr[i]);
		}
		free(p);
	}
	t = NULL;
}

Status BiTreeUI::InitQueue(LinkList &L) {
	//初始化队列 
	L = (LNode*)malloc(sizeof(LNode));                //分配结点空间 
	if (L == NULL)                                     //分配失败              
		return OVERFLOW1;
	L->next = NULL;
	return OK;
}


LNode* BiTreeUI::CreateNode1(BTNode *p) {
	//新建一个结点 
	LNode *q;
	q = (LNode*)malloc(sizeof(LNode));                //分配结点空间
	if (q != NULL) {                                    //分配成功 
		q->data = p;
		q->next = NULL;
	}
	return q;
}


Status BiTreeUI::Enqueue1(LNode *p, BTNode *q) {
	//元素q入队列
	if (p == NULL)
		return ERROR;
	while (p->next != NULL)                            //调至队列最后 
		p = p->next;
	p->next = CreateNode1(q);                          //生成结点让q进入队列 
	return OK;
}


Status BiTreeUI::Dequeue(LNode *p, BTNode *&q) {
	//出队列，并以q返回值 
	LNode *aq;
	if (p == NULL || p->next == NULL)                      //删除位置不合理 
		return ERROR;
	aq = p->next;                                     //修改被删结点aq的指针域
	p->next = aq->next;
	q = aq->data;
	free(aq);                                       //释放结点aq
	return OK;
}


Status BiTreeUI::IfEmpty(LinkList L) {
	//队列判空 
	if (L == NULL)                                     //队列不存在 
		return ERROR;
	if (L->next == NULL)                               //队列为空 
		return TRUE;
	return FALSE;                                   //队列非空 
}

void BiTreeUI::DestroyQueue(LinkList L) {
	//销毁队列 
	LinkList p;
	if (L != NULL) {
		p = L;
		L = L->next;
		free(p);                                    //逐一释放 
		DestroyQueue(L);
	}
}

Status BiTreeUI::Traverse(BTree t, LinkList L, int newline, int sum) {
	//用队列遍历输出B树 
	int i;
	BTree p;
	if (t != NULL) {

		Enqueue1(L, t->ptr[0]);                       //入队  

		for (i = 1; i <= t->keynum; i++) //同一个节点输出 节点关键字个数keynum
		{
			Enqueue1(L, t->ptr[i]);                   //子结点入队 
		}
		sum += t->keynum + 1;
		if (newline == 0) {                             //需要另起一行 

			newline = sum - 1;
			sum = 0;
		}
		else
			newline--;
	}

	if (IfEmpty(L) == FALSE) {                         //l不为空 
		Dequeue(L, p);                              //出队，以p返回 
		Traverse(p, L, newline, sum);                 //遍历出队结点 
	}
	return OK;
}

Status BiTreeUI::PrintBTree(BTree t) {
	//输出B树 
	LinkList L;
	if (t == NULL) {
		return OK;
	}
	InitQueue(L);                                   //初始化队列 
	Traverse(t, L, 0, 0);                              //利用队列输出 
	DestroyQueue(L);                                //销毁队列 
	return OK;
}
void BiTreeUI::Print_BTree(BTree bTree, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame) {
	if (bTree == NULL)
		return;
	wideSize = wideSize / 3;//每次将单位值除以二，绘制在根节点的左右

	if (bTree != NULL)
	{
		frametime[frame]++;
		animationRecord(onlytotaltime, frametime[frame], x, y, bTree->key[1], -1, p_x, p_y);
		animationPrint(onlytotaltime, frametime[frame]);
	}
	if (bTree->keynum == 1)
	{
		if (bTree->ptr[0] != NULL)
			Print_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame);//左孩子
		else
		{
			//m_scene->drawCircle(x, y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1, -1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);
		}
		if (bTree->ptr[1] != NULL)
			Print_BTree(bTree->ptr[1], x + wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame);//右孩子
		else
		{
			//m_scene->drawCircle(x, y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1, -1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);
		}
	}
	if (bTree->keynum == 2)
	{

		if (bTree != NULL)
		{
			//m_scene->drawCircle2(x, y, bTree->key[1], bTree->key[2], p_x, p_y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y, bTree->key[1], bTree->key[2], p_x, p_y);
			animationPrint(onlytotaltime, frametime[frame]);

		}
		if (bTree->ptr[0] != NULL)
			Print_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame);//左孩子
		else
		{
			//m_scene->drawCircle(x , y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1, -1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);

		}
		if (bTree->ptr[1] != NULL)
			Print_BTree(bTree->ptr[1], x, y + highSize, wideSize, highSize, x, y, frame);//中孩子
		else
		{
			//m_scene->drawCircle(x, y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1, -1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);

		}
		if (bTree->ptr[2] != NULL)
			Print_BTree(bTree->ptr[2], x + wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame);//右孩子
		else
		{
			m_scene->drawCircle(x, y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1, -1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);

		}

	}
}

void BiTreeUI::on_Btree_create_btn_clicked() {
	int i, k;
	DestroyBTree(t);//先清空B树
	m_scene->clearScreen();//清屏
	QString data = ui->BinaryTreeDataEdit->text();
	if (!IsNumber_(data)) QMessageBox::critical(this, QString::fromLocal8Bit("输入错误"), QString::fromLocal8Bit("输入格式必须为数字和英文字符"));
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
		history_list_array[i] = x;//将存为数组
	}
	history_length = list.size();
	int codeid;
	for (int i = 0; i < list.size(); i++)
	{
		k = list_array[i];
		s = SearchBTree(t, k);
		codeid = InsertBTree(t, s.i, k, s.pt);             //插入元素

		m_scene->clearScreen();
		int depth = 0;
		BTree pt;
		pt = t;
		for (int i = 1; ; i++)
		{
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

		frametime[i] = 0;
		onlytotaltime = i;
		history_wideSize[i] = wideSize;
		history_highSize[i] = highSize;
		insertIdCode[i] = codeid;
		//打印B_树
		Print_BTree(t, 0, 0, wideSize, highSize, 0, 0, i);
	}


	m_scene->clearScreen();//清屏
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	m_quickHelp->btree_insert_code(insertIdCode[onlytotaltime]);
	//适应窗口
	m_editorView->fitToView();
	//适应网格
	m_scene->addUndoState();
	timestamp = 0;
}