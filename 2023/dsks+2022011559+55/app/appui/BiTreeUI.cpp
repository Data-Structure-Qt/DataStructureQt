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
	m_scene->clearScreen();//����
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
		m_scene->clearScreen();//����
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
		m_scene->clearScreen();//����


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
		m_scene->clearScreen();//����
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
	m_scene->clearScreen();//����
	timestamp = onlytotaltime;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	m_quickHelp->btree_insert_code(insertIdCode[timestamp]);

}

void BiTreeUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//��ȡ�Զ�������ʱ��
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);	//�������̣߳�����qt�����¼�
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
	for (int i = 0; i < frametime; i++)		//������������
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
	for (int i = 0; i < frametime; i++)		//������������
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
//�б�����Ƿ�Ϊ���ֺ�,
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
//�б�����Ƿ�Ϊ����
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
//B����ӽڵ㹦��
void BiTreeUI::on_Btree_insert_btn_clicked()
{
	QString data = ui->BinaryTreeDataEdit_2->text();
	if (!IsNumber(data)) QMessageBox::critical(this, QString::fromLocal8Bit("�������"), QString::fromLocal8Bit("�ڵ������������Ϊ����"));
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
		onlytotaltime++;
		frametime[onlytotaltime] = 0;
		history_wideSize[onlytotaltime] = wideSize;
		history_highSize[onlytotaltime] = highSize;
		insertIdCode[onlytotaltime] = codeid;
		Print_BTree(t, 0, 0, wideSize, highSize, 0, 0, onlytotaltime);

		m_scene->clearScreen();//����
		for (int j = 0; j <= frametime[onlytotaltime]; j++)
		{
			animationDraw(onlytotaltime, j);
		}
		m_quickHelp->btree_insert_code(insertIdCode[onlytotaltime]);
		//��Ӧ����
		m_editorView->fitToView();
		//��Ӧ����
		m_scene->addUndoState();
	}
}

//B������
void BiTreeUI::on_Btree_search_btn_clicked()
{
	//m_scene->clearScreen();
	QString data = ui->BinaryTreeDataEdit_2->text();
	if (!IsNumber(data)) QMessageBox::critical(this, QString::fromLocal8Bit("�������"), QString::fromLocal8Bit("�ڵ������������Ϊ����"));
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
	//��ӡB_��
	framesearchtime = 0;
	//onlytotaltime = 0;
	history_wideSize[0] = wideSize;
	history_highSize[0] = highSize;

	Print_Search_BTree(t, 0, 0, wideSize, highSize, 0, 0, 0, k);//һ�ξ������������Ҫ��j�ı仯

	///////////////
	m_scene->clearScreen();//����
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
	///////////////////////

	for (int j = 0; j <= framesearchtime; j++)
	{
		animationDrawSearch(0, j);
		sleepTime(500);
	}

	timestamp = 0;
}

//B��ɾ��
void BiTreeUI::on_Btree_remove_btn_clicked() {
	QString data = ui->BinaryTreeDataEdit_2->text();
	if (!IsNumber(data)) QMessageBox::critical(this, QString::fromLocal8Bit("�������"), QString::fromLocal8Bit("�ڵ������������Ϊ����"));
	else {
		m_scene->clearScreen();		//����
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
		BTreeDelete(t, k);			//ɾ��Ԫ�� 
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
		onlytotaltime--;
		frametime[onlytotaltime] = 0;
		history_wideSize[onlytotaltime] = wideSize;
		history_highSize[onlytotaltime] = highSize;

		Print_BTree(t, 0, 0, wideSize, highSize, 0, 0, onlytotaltime);
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
}


//B������
void BiTreeUI::on_Btree_destroy_btn_clicked()
{
	DestroyBTree(t);
	PrintBTree(t);
	m_scene->clearScreen();//����
}

void BiTreeUI::Print_Search_BTree(BTree bTree, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame, int key)
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
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], -1, p_x, p_y, 1, 2);//��¼  �ҵ�  2
				animationPrint(0, framesearchtime);
			}
			else if (key < bTree->key[1])//�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], -1, p_x, p_y, 1, 3);//��¼			3
				animationPrint(0, framesearchtime);
			}
			else if (key > bTree->key[2])//�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], -1, p_x, p_y, 1, 5);//��¼			5
				animationPrint(0, framesearchtime);
			}
		}
		if (bTree->keynum == 2)
		{
			if (bTree->key[1] == key || bTree->key[2] == key)//�ҵ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 2);//��¼	2
				animationPrint(0, framesearchtime);

			}
			else if (key < bTree->key[1]) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 3);//��¼	3
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[1] < key && key < bTree->key[2]) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 4);//��¼	4
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[2] < key) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 5);//��¼	5
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
				Print_Search_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame, key);//����
			}
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -1, x, y, 1, 6);//��¼			6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[1])
		{
			if (bTree->ptr[1] != NULL)
				Print_Search_BTree(bTree->ptr[1], x + wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame, key);//�Һ���
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -1, x, y, 1, 6);//��¼			6
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
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 2);//��¼		2
				animationPrint(0, framesearchtime);
			}
			else if (key < bTree->key[1]) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 3);//��¼	3
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[1] < key && key < bTree->key[2]) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 4);//��¼	4
				animationPrint(0, framesearchtime);
			}
			else if (bTree->key[2] < key) //�ҹ�
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y, bTree->key[1], bTree->key[2], p_x, p_y, 1, 5);//��¼	5
				animationPrint(0, framesearchtime);
			}
		}


		if (key < bTree->key[1])//�ҵ�
		{
			if (bTree->ptr[0] != NULL)
				Print_Search_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame, key);//����
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -1, x, y, 1, 6);//��¼				6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[1] && key < bTree->key[2])//�ҵ�
		{
			if (bTree->ptr[1] != NULL)
				Print_Search_BTree(bTree->ptr[1], x, y + highSize, wideSize, highSize, x, y, frame, key);//�к���
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -1, x, y, 1, 6);//��¼				6
				animationPrint(0, framesearchtime);
			}
		}
		if (key > bTree->key[2])//�ҵ�
		{
			if (bTree->ptr[2] != NULL)
				Print_Search_BTree(bTree->ptr[2], x + wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame, key);//�Һ���
			else
			{
				framesearchtime++;
				animationSearchRecord(0, framesearchtime, x, y + highSize, -1, -1, x, y, 1, 6);//��¼				6
				animationPrint(0, framesearchtime);
			}
		}
	}
}



//B��
///////////////////////////

//��ʼ��B�� 
Status BiTreeUI::InitBTree(BTree &t) {
	t = NULL;
	return OK;
}

//����в��ҹؼ���k����λ��i 
int BiTreeUI::SearchBTNode(BTNode *p, KeyType k) {
	int i = 0;
	for (i = 0; i < p->keynum&&p->key[i + 1] <= k; i++);
	return i;
}

//����t�ϲ��ҹؼ���
Result BiTreeUI::SearchBTree(BTree t, KeyType k) {
	BTNode *p = t, *q = NULL;                  //������ָ��p,p��˫��ָ��q

	int flag = 0, i = 0;                        //flag 1 �ɹ���2 ʧ�� 
	Result r;
	while (p != NULL && flag == 0) {
		i = SearchBTNode(p, k);                //�ڽ��p�в��ҹؼ���k,ʹ��p->key[i]<=k<p->key[i+1]
		if (i > 0 && p->key[i] == k)           //�ҵ�����ؼ���
		{
			qDebug() << "p->key[i]" << p->key[i];
			flag = 1;
		}
		else {
			q = p;								//���Һ���ָ������
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
	return r;                                       //���عؼ���k��λ��
}


void BiTreeUI::InsertBTNode(BTNode *&p, int i, KeyType k, BTNode *q) {
	//���ؼ���k�ͽ��q�ֱ���뵽p->key[i+1]��p->ptr[i+1]��
	int j;
	for (j = p->keynum; j > i; j--) {                       //������ƿճ�һ��λ��
		p->key[j + 1] = p->key[j];
		p->ptr[j + 1] = p->ptr[j];
	}
	p->key[i + 1] = k;
	p->ptr[i + 1] = q;
	if (q != NULL)
		q->parent = p;
	p->keynum++;
}

//�����p���ѳ��������,ǰһ�뱣��,��һ��������q
void BiTreeUI::SplitBTNode(BTNode *&p, BTNode *&q) {
	int i, s = (m + 1) / 2;
	q = (BTNode *)malloc(sizeof(BTNode));             //�����q����ռ�
	q->ptr[0] = p->ptr[s];                            //��һ��������q
	for (i = s + 1; i <= m; i++) {
		q->key[i - s] = p->key[i];
		q->ptr[i - s] = p->ptr[i];
	}
	q->keynum = p->keynum - s;
	q->parent = p->parent;
	for (i = 0; i <= p->keynum - s; i++)               //�޸�˫��ָ�� 
		if (q->ptr[i] != NULL)
			q->ptr[i]->parent = q;
	p->keynum = s - 1;                                  //���p��ǰһ�뱣��,�޸Ľ��p��keynum
}

//�����µĸ����t,ԭp��qΪ����ָ��
void BiTreeUI::NewRoot(BTNode *&t, KeyType k, BTNode *p, BTNode *q) {
	t = (BTNode *)malloc(sizeof(BTNode));             //����ռ� 
	t->keynum = 1;
	t->ptr[0] = p;
	t->ptr[1] = q;
	t->key[1] = k;
	if (p != NULL)                                     //�������p�ͽ��q��˫��ָ�� 
		p->parent = t;
	if (q != NULL)
		q->parent = t;
	t->parent = NULL;
}

//����ؼ���k�������������
int BiTreeUI::InsertBTree(BTree &t, int i, KeyType k, BTNode *p) {

	BTNode *q;
	int endflag, newflag, s;                   //�趨��Ҫ�½���־�Ͳ�����ɱ�־ 
	KeyType x;
	int codeid;
	if (p == NULL)                                     //t�ǿ���
	{
		NewRoot(t, k, NULL, NULL);                     //���ɽ����ؼ���k�ĸ����t
		codeid = 1;//���ɸ��ڵ�
		return codeid;
	}
	else {
		x = k;
		q = NULL;
		endflag = 0;
		newflag = 0;
		while (endflag == 0 && newflag == 0)
		{
			InsertBTNode(p, i, x, q);                  //���ؼ���x�ͽ��q�ֱ���뵽p->key[i+1]��p->ptr[i+1]
			if (p->keynum <= Max)
			{
				endflag = 2;							//��p->keynum <= Max  �������
				return codeid;
			}
			else
			{
				s = (m + 1) / 2;
				SplitBTNode(p, q);                   //���ѽ�� 
				x = p->key[s];
				if (p->parent) {                      //����x�Ĳ���λ��
					p = p->parent;
					i = SearchBTNode(p, x);
				}
				else                                //û�ҵ�x����Ҫ�½�� 
				{
					newflag = 1;
				}
			}
		}

		if (newflag == 1)							 //������ѷ���Ϊ���p��q 
		{
			NewRoot(t, x, p, q);					//�����¸����t,p��qΪ����ָ��

			codeid = 3;								//������ѷ���Ϊ���p��q			 //�����¸����t,p��qΪ����ָ��
			return codeid;
		}
	}
}


void BiTreeUI::Remove(BTNode *p, int i) {
	int j;
	for (j = i + 1; j <= p->keynum; j++) {           //ǰ��ɾ��key[i]��ptr[i]
		p->key[j - 1] = p->key[j];
		p->ptr[j - 1] = p->ptr[j];
	}
	p->keynum--;
}

//���ұ�ɾ�ؼ���p->key[i](�ڷ�Ҷ�ӽ����)�����Ҷ�ӽ��(��������ֵ��С�Ĺؼ���) 
void BiTreeUI::Substitution(BTNode *p, int i) {
	BTNode *q;
	for (q = p->ptr[i]; q->ptr[0] != NULL; q = q->ptr[0]);
	p->key[i] = q->key[1];                            //���ƹؼ���ֵ
}

/*��˫�׽��p�е����һ���ؼ��������ҽ��q��
������aq�е����һ���ؼ�������˫�׽��p��*/
void BiTreeUI::MoveRight(BTNode *p, int i) {

	int j;
	BTNode *q = p->ptr[i];
	BTNode *aq = p->ptr[i - 1];

	for (j = q->keynum; j > 0; j--) {                 //�����ֵ�q�����йؼ�������ƶ�һλ
		q->key[j + 1] = q->key[j];
		q->ptr[j + 1] = q->ptr[j];
	}

	q->ptr[1] = q->ptr[0];                            //��˫�׽��p�ƶ��ؼ��ֵ����ֵ�q��
	q->key[1] = p->key[i];
	q->keynum++;

	p->key[i] = aq->key[aq->keynum];                  //�����ֵ�aq�����һ���ؼ����ƶ���˫�׽��p��
	p->ptr[i]->ptr[0] = aq->ptr[aq->keynum];
	aq->keynum--;
}

void BiTreeUI::MoveLeft(BTNode *p, int i) {
	/*��˫�׽��p�еĵ�һ���ؼ�����������aq�У�
	���ҽ��q�еĵ�һ���ؼ�������˫�׽��p��*/
	int j;
	BTNode *aq = p->ptr[i - 1];
	BTNode *q = p->ptr[i];

	aq->keynum++;                                   //˫�׽��ؼ����ƶ������ֵ�aq��
	aq->key[aq->keynum] = p->key[i];
	aq->ptr[aq->keynum] = p->ptr[i]->ptr[0];

	p->key[i] = q->key[1];                            //�����ֵ�q�еĹؼ����ƶ���˫�׽ڵ�p��
	q->ptr[0] = q->ptr[1];
	q->keynum--;

	for (j = 1; j <= aq->keynum; j++) {                     //�����ֵ�q�����йؼ�����ǰ�ƶ�һλ
		aq->key[j] = aq->key[j + 1];
		aq->ptr[j] = aq->ptr[j + 1];
	}
}


void BiTreeUI::Combine(BTNode *p, int i) {
	/*��˫�׽��p���ҽ��q�ϲ�������aq��
	������˫�׽��p�е�ʣ��ؼ��ֵ�λ��*/
	int j;
	BTNode *q = p->ptr[i];
	BTNode *aq = p->ptr[i - 1];

	aq->keynum++;                                  //��˫�׽��Ĺؼ���p->key[i]���뵽����aq     
	aq->key[aq->keynum] = p->key[i];
	aq->ptr[aq->keynum] = q->ptr[0];

	for (j = 1; j <= q->keynum; j++) {                      //���ҽ��q�е����йؼ��ֲ��뵽����aq 
		aq->keynum++;
		aq->key[aq->keynum] = q->key[j];
		aq->ptr[aq->keynum] = q->ptr[j];
	}

	for (j = i; j < p->keynum; j++) {                       //��˫�׽��p�е�p->key[i]������йؼ�����ǰ�ƶ�һλ 
		p->key[j] = p->key[j + 1];
		p->ptr[j] = p->ptr[j + 1];
	}
	p->keynum--;                                    //�޸�˫�׽��p��keynumֵ 
	free(q);                                        //�ͷſ��ҽ��q�Ŀռ�
}


void BiTreeUI::AdjustBTree(BTNode *p, int i) {
	//ɾ�����p�еĵ�i���ؼ��ֺ�,����B��
	if (i == 0)                                        //ɾ����������߹ؼ���
		if (p->ptr[1]->keynum > Min)                   //�ҽ����Խ�
			MoveLeft(p, 1);
		else                                        //���ֵܲ����� 
			Combine(p, 1);
	else if (i == p->keynum)                           //ɾ���������ұ߹ؼ���
		if (p->ptr[i - 1]->keynum > Min)                 //������Խ� 
			MoveRight(p, i);
		else                                        //���㲻���� 
			Combine(p, i);
	else if (p->ptr[i - 1]->keynum > Min)                //ɾ���ؼ������в������㹻�� 
		MoveRight(p, i);
	else if (p->ptr[i + 1]->keynum > Min)                //ɾ���ؼ������в����ҽ�㹻�� 
		MoveLeft(p, i + 1);
	else                                            //ɾ���ؼ������в������ҽ�㶼������
		Combine(p, i);
}


int BiTreeUI::FindBTNode(BTNode *p, KeyType k, int &i) {
	//��ӳ�Ƿ��ڽ��p���Ƿ���ҵ��ؼ���k 
	if (k < p->key[1]) {                                //���p�в��ҹؼ���kʧ�� 
		i = 0;
		return 0;
	}
	else {                                           //��p����в���
		i = p->keynum;
		while (k < p->key[i] && i>1)
			i--;
		if (k == p->key[i])                            //���p�в��ҹؼ���k�ɹ� 
			return 1;
	}
}


int BiTreeUI::BTNodeDelete(BTNode *p, KeyType k) {
	//�ڽ��p�в��Ҳ�ɾ���ؼ���k
	int i;
	int found_tag;                                  //���ұ�־ 
	if (p == NULL)
		return 0;
	else {
		found_tag = FindBTNode(p, k, i);                //���ز��ҽ�� 
		if (found_tag == 1) {                           //���ҳɹ� 
			if (p->ptr[i - 1] != NULL) {                  //ɾ�����Ƿ�Ҷ�ӽ��
				Substitution(p, i);                  //Ѱ�����ڹؼ���(����������С�Ĺؼ���) 
				BTNodeDelete(p->ptr[i], p->key[i]);  //ִ��ɾ������ 
			}
			else
				Remove(p, i);                        //�ӽ��p��λ��i��ɾ���ؼ���
		}
		else
			found_tag = BTNodeDelete(p->ptr[i], k);    //�غ��ӽ��ݹ���Ҳ�ɾ���ؼ���k
		if (p->ptr[i] != NULL)
			if (p->ptr[i]->keynum < Min)               //ɾ����ؼ��ָ���С��MIN
				AdjustBTree(p, i);                   //����B�� 
		return found_tag;
	}
}


void BiTreeUI::BTreeDelete(BTree &t, KeyType k) {
	//����ɾ����ܣ�ִ��ɾ������  
	BTNode *p;
	int a = BTNodeDelete(t, k);                        //ɾ���ؼ���k 
	if (a == 0)                                        //����ʧ�� 
		printf("   �ؼ���%d����B����\n", k);
	else if (t->keynum == 0) {                          //���� 
		p = t;
		t = t->ptr[0];
		free(p);
	}
}


void BiTreeUI::DestroyBTree(BTree &t) {
	//�ݹ��ͷ�B�� 
	int i;
	BTNode* p = t;
	if (p != NULL) {                                    //B����Ϊ��  
		for (i = 0; i <= p->keynum; i++) {                  //�ݹ��ͷ�ÿһ����� 
			DestroyBTree(*&p->ptr[i]);
		}
		free(p);
	}
	t = NULL;
}

Status BiTreeUI::InitQueue(LinkList &L) {
	//��ʼ������ 
	L = (LNode*)malloc(sizeof(LNode));                //������ռ� 
	if (L == NULL)                                     //����ʧ��              
		return OVERFLOW1;
	L->next = NULL;
	return OK;
}


LNode* BiTreeUI::CreateNode1(BTNode *p) {
	//�½�һ����� 
	LNode *q;
	q = (LNode*)malloc(sizeof(LNode));                //������ռ�
	if (q != NULL) {                                    //����ɹ� 
		q->data = p;
		q->next = NULL;
	}
	return q;
}


Status BiTreeUI::Enqueue1(LNode *p, BTNode *q) {
	//Ԫ��q�����
	if (p == NULL)
		return ERROR;
	while (p->next != NULL)                            //����������� 
		p = p->next;
	p->next = CreateNode1(q);                          //���ɽ����q������� 
	return OK;
}


Status BiTreeUI::Dequeue(LNode *p, BTNode *&q) {
	//�����У�����q����ֵ 
	LNode *aq;
	if (p == NULL || p->next == NULL)                      //ɾ��λ�ò����� 
		return ERROR;
	aq = p->next;                                     //�޸ı�ɾ���aq��ָ����
	p->next = aq->next;
	q = aq->data;
	free(aq);                                       //�ͷŽ��aq
	return OK;
}


Status BiTreeUI::IfEmpty(LinkList L) {
	//�����п� 
	if (L == NULL)                                     //���в����� 
		return ERROR;
	if (L->next == NULL)                               //����Ϊ�� 
		return TRUE;
	return FALSE;                                   //���зǿ� 
}

void BiTreeUI::DestroyQueue(LinkList L) {
	//���ٶ��� 
	LinkList p;
	if (L != NULL) {
		p = L;
		L = L->next;
		free(p);                                    //��һ�ͷ� 
		DestroyQueue(L);
	}
}

Status BiTreeUI::Traverse(BTree t, LinkList L, int newline, int sum) {
	//�ö��б������B�� 
	int i;
	BTree p;
	if (t != NULL) {

		Enqueue1(L, t->ptr[0]);                       //���  

		for (i = 1; i <= t->keynum; i++) //ͬһ���ڵ���� �ڵ�ؼ��ָ���keynum
		{
			Enqueue1(L, t->ptr[i]);                   //�ӽ����� 
		}
		sum += t->keynum + 1;
		if (newline == 0) {                             //��Ҫ����һ�� 

			newline = sum - 1;
			sum = 0;
		}
		else
			newline--;
	}

	if (IfEmpty(L) == FALSE) {                         //l��Ϊ�� 
		Dequeue(L, p);                              //���ӣ���p���� 
		Traverse(p, L, newline, sum);                 //�������ӽ�� 
	}
	return OK;
}

Status BiTreeUI::PrintBTree(BTree t) {
	//���B�� 
	LinkList L;
	if (t == NULL) {
		return OK;
	}
	InitQueue(L);                                   //��ʼ������ 
	Traverse(t, L, 0, 0);                              //���ö������ 
	DestroyQueue(L);                                //���ٶ��� 
	return OK;
}
void BiTreeUI::Print_BTree(BTree bTree, double x,
	double y, double wideSize, double highSize, double p_x, double p_y, int frame) {
	if (bTree == NULL)
		return;
	wideSize = wideSize / 3;//ÿ�ν���λֵ���Զ��������ڸ��ڵ������

	if (bTree != NULL)
	{
		frametime[frame]++;
		animationRecord(onlytotaltime, frametime[frame], x, y, bTree->key[1], -1, p_x, p_y);
		animationPrint(onlytotaltime, frametime[frame]);
	}
	if (bTree->keynum == 1)
	{
		if (bTree->ptr[0] != NULL)
			Print_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame);//����
		else
		{
			//m_scene->drawCircle(x, y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1, -1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);
		}
		if (bTree->ptr[1] != NULL)
			Print_BTree(bTree->ptr[1], x + wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame);//�Һ���
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
			Print_BTree(bTree->ptr[0], x - wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame);//����
		else
		{
			//m_scene->drawCircle(x , y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1, -1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);

		}
		if (bTree->ptr[1] != NULL)
			Print_BTree(bTree->ptr[1], x, y + highSize, wideSize, highSize, x, y, frame);//�к���
		else
		{
			//m_scene->drawCircle(x, y + highSize, -1, x, y);
			frametime[frame]++;
			animationRecord(onlytotaltime, frametime[frame], x, y + highSize, -1, -1, x, y);
			animationPrint(onlytotaltime, frametime[frame]);

		}
		if (bTree->ptr[2] != NULL)
			Print_BTree(bTree->ptr[2], x + wideSize * 1.5, y + highSize, wideSize, highSize, x, y, frame);//�Һ���
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
	DestroyBTree(t);//�����B��
	m_scene->clearScreen();//����
	QString data = ui->BinaryTreeDataEdit->text();
	if (!IsNumber_(data)) QMessageBox::critical(this, QString::fromLocal8Bit("�������"), QString::fromLocal8Bit("�����ʽ����Ϊ���ֺ�Ӣ���ַ�"));
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
		history_list_array[i] = x;//����Ϊ����
	}
	history_length = list.size();
	int codeid;
	for (int i = 0; i < list.size(); i++)
	{
		k = list_array[i];
		s = SearchBTree(t, k);
		codeid = InsertBTree(t, s.i, k, s.pt);             //����Ԫ��

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

		frametime[i] = 0;
		onlytotaltime = i;
		history_wideSize[i] = wideSize;
		history_highSize[i] = highSize;
		insertIdCode[i] = codeid;
		//��ӡB_��
		Print_BTree(t, 0, 0, wideSize, highSize, 0, 0, i);
	}


	m_scene->clearScreen();//����
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	m_quickHelp->btree_insert_code(insertIdCode[onlytotaltime]);
	//��Ӧ����
	m_editorView->fitToView();
	//��Ӧ����
	m_scene->addUndoState();
	timestamp = 0;
}