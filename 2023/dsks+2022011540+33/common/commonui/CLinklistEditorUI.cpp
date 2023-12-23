#include "CLinklistEditorUI.h" 
#include "ui_CLinklistEditorUI.h" 
#include "../base/CNodeEditorScene.h" 

#include <QFile> 
#include <QTextStream> 
#include <QTime> 
#include <qDebug>

CLinklistEditorUI::CLinklistEditorUI(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::CLinklistEditorUI),
	m_scene(NULL)
{
	ui->setupUi(this);
}

//..........�ҵ��޸�
void CLinklistEditorUI::goToBeginButton() 
{
	endplaybuttonflag = 1;
	timestamp = 0;
	m_scene->clearScreen();//����
	for (int j = 0; j <= frametime[0]; j++)
	{
		animationDraw(0, j);

	}
	//m_quickHelp->btree_create_code(insertIdCode[timestamp]);
}
void CLinklistEditorUI::stepBackButton()
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
	}
}
void CLinklistEditorUI::playButton()
{
	endplaybuttonflag = 0;
	//for (timestamp; timestamp <= onlytotaltime && endplaybuttonflag != 1; timestamp++)
	//{
	//	m_scene->clearScreen();//����

	//	for (int j = 0; j <= frametime[timestamp]; j++)
	//	{
	//		animationDraw(timestamp, j);
	//		m_quickHelp->head_insert_code(1);
	//	}
	//	sleepTime(500);
	//}
	m_scene->clearScreen();//����

	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
		m_quickHelp->head_insert_code(1);
	}
	timestamp = onlytotaltime;
	sleepTime(500);
}
void CLinklistEditorUI::suspendButton() {
	endplaybuttonflag = 1;
}
void CLinklistEditorUI::stepForwardButton() {
	endplaybuttonflag = 1;
	if (timestamp < onlytotaltime)
	{
		timestamp++;
		m_scene->clearScreen();//����
		for (int j = 0; j <= frametime[timestamp]; j++)
		{
			animationDraw(timestamp, j);
		}
	}
}
void CLinklistEditorUI::goToEndButton() {
	endplaybuttonflag = 1;
	m_scene->clearScreen();//����
	timestamp = onlytotaltime;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	//m_quickHelp->btree_insert_code(insertIdCode[timestamp]);

}

void CLinklistEditorUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//��ȡ�Զ�������ʱ��
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);	//�������̣߳�����qt�����¼�
	}
}
void CLinklistEditorUI::animationRecord(int totaltime, int frame, int x, int data)
{
	animation[totaltime][frame].x = x;
	animation[totaltime][frame].data = data;
}
void CLinklistEditorUI::animationSearchRecord(int totaltime, int frame, int x, int data, int flag, int codeid)
{
	animationSearch[totaltime][frame].x = x;
	animationSearch[totaltime][frame].data = data;
	animationSearch[totaltime][frame].flag = flag;
	animationSearch[totaltime][frame].codeid = codeid;
}
void CLinklistEditorUI::animationClean()
{
	for (int i = 0; i < 200; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			animation[i][j].x = 0;
			animation[i][j].data = 0;
		}
	}
}
void CLinklistEditorUI::animationPrint(int totaltime, int frametime)
{
	qDebug() << "totaltime" << totaltime;
	qDebug() << "frametime" << frametime;
	int i = totaltime;
	int j = frametime;
	qDebug() << "animation[i].x " << animation[i][j].x;
	qDebug() << " animation[i].data " << animation[i][j].data;

}
void CLinklistEditorUI::animationDraw(int totaltime, int frametime)
{
	m_scene->insertnode(animation[totaltime][frametime].x, animation[totaltime][frametime].data); //����ֻ��Ҫ����ÿ�����һ�μ���
}
void CLinklistEditorUI::animationDrawSearch(int totaltime, int frametime, int x)
{
	m_scene->insertfindnode(animation[totaltime][frametime].x, animation[totaltime][frametime].data);
}
//......
void CLinklistEditorUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);

}
void CLinklistEditorUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);

	m_scene = scene;

	setEnabled(m_scene);

	if (m_scene)
		onSceneAttached(m_scene);
}
void CLinklistEditorUI::onSceneAttached(CEditorScene* scene)
{

}
void CLinklistEditorUI::setCQuickHelpUI(CQuickHelpUI* quickHelp)
{
	m_quickHelp = quickHelp;
	setEnabled(m_quickHelp);
}

CLinklistEditorUI::~CLinklistEditorUI()
{
}

void CLinklistEditorUI::on_create_btn_clicked()
{
	/*createflag = 1;
	deleteflag = 0;
	searchflag = 0;*/

	m_scene->clearScreen();

	for (int i = 1; i <= QLinkList.size(); ++i) //ɾ�����нڵ� 
	{
		m_scene->deletenode(i);
	}

	QList<CNode*> nodes = m_scene->getSelectedNodes();

	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	for (int i = 0; i < temp.size(); ++i)
	{
		QListNode* node = new QListNode();
		node->m_StrName = temp.at(i);
		//��ӽ����� 
		QLinkList.append(*node);
	}
	for (int i = 0; i < QLinkList.size(); ++i)
	{
		QString tmp = QLinkList.at(i).m_StrName;
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;

		m_scene->insertnode(i, x);//����Ļ���� 
	}
	// �޸�
	for (int j = 0; j < temp.size(); ++j)
	{
		onlytotaltime = j;
		
		for (int i = 0; i < QLinkList.size(); ++i)
			{
				QString tmp = QLinkList.at(i).m_StrName;
				bool flag;
				int x = tmp.toUInt(&flag);
				if (!flag)
					return;
				// �޸�
				frametime[i] = i;
				animationRecord(onlytotaltime, frametime[i], i, x);
			}
	}

	ui->spinBox->setRange(0, frametime[onlytotaltime]);
	ui->insert_spinBox->setRange(0, frametime[onlytotaltime]);
	ui->delete_spinBox->setRange(0, frametime[onlytotaltime]);
	m_quickHelp->head_insert_code(1);
	timestamp = 0;
}

void CLinklistEditorUI::on_clean_btn_clicked() //�����ť�ۺ���
{ 
	m_scene->clearScreen();
ui->dataEdit->clear();
for (int i = 1; i <= QLinkList.size(); ++i)
{
	m_scene->deletenode(i);
}
QLinkList.clear();
}

void CLinklistEditorUI::on_headinsert_btn_clicked()
{
	// ��¼��ʼ״̬������ʱ������Ϊ0
	// �˴���д����
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		
		animationRecord(0, j, animation[onlytotaltime][j].x, animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;

	for (int i = 1; i <= QLinkList.size(); ++i)
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insert_Edit1->text();
	QListNode* node = new QListNode();
	node->m_StrName = data;
	QLinkList.insert(0, *node);

	onlytotaltime++;
	for (int i = 0; i < QLinkList.size(); ++i)
	{
		QString tmp = QLinkList.at(i).m_StrName;
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);

		//frametime[i] = i;
		animationRecord(1, i, i, x);
		frametime[onlytotaltime] = i;
	}

	ui->spinBox->setRange(0, frametime[onlytotaltime]);
	ui->insert_spinBox->setRange(0, frametime[onlytotaltime]);
	ui->delete_spinBox->setRange(0, frametime[onlytotaltime]);
	timestamp = 1;
	m_quickHelp->head_insert_code(1);
	//playButton();
	//suspendButton();
}

void CLinklistEditorUI::on_tailinsert_btn_clicked() //β�����밴ť�ۺ��� 
{
	// ��¼��ʼ״̬������ʱ������Ϊ0
	// �˴���д����
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{

		animationRecord(0, j, animation[onlytotaltime][j].x, animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;


	for (int i = 1; i <= QLinkList.size(); ++i) //�����󴴽� 
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insert_Edit1->text();
	int list_size = QLinkList.size();
	QListNode* node = new QListNode();
	node->m_StrName = data;
	QLinkList.insert(list_size, *node); //β������ 

	onlytotaltime++;
	for (int i = 0; i < QLinkList.size(); ++i)
	{
		QString tmp = QLinkList.at(i).m_StrName;
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);

		animationRecord(1, i, i, x);
		frametime[onlytotaltime] = i;
	}
	ui->spinBox->setRange(0, frametime[onlytotaltime]);
	ui->insert_spinBox->setRange(0, frametime[onlytotaltime]);
	ui->delete_spinBox->setRange(0, frametime[onlytotaltime]);
	timestamp = 1;
}

void CLinklistEditorUI::on_locationinsert_btn_clicked() //����λ�ò��밴ť�ۺ���
{
	// ��¼��ʼ״̬������ʱ������Ϊ0
	// �˴���д����
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{

		animationRecord(0, j, animation[onlytotaltime][j].x, animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;

	for (int i = 1; i <= QLinkList.size(); ++i) //�����󴴽� 
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insert_Edit2->text();
	int num = ui->insert_spinBox->value();
	int list_size = QLinkList.size();
	if (num<0 || num > list_size + 1)//�������뷶Χ���� 
	{
		return;
	}
	QListNode* node = new QListNode();
	node->m_StrName = data;
	QLinkList.insert(num, *node); //ĳ��λ�ò��� 

	onlytotaltime++;
	for (int i = 0; i < QLinkList.size(); ++i)
	{
		QString tmp = QLinkList.at(i).m_StrName;
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;

		m_scene->insertnode(i, x);

		animationRecord(1, i, i, x);
		frametime[onlytotaltime] = i;
	}

	ui->spinBox->setRange(0, frametime[onlytotaltime]);
	ui->insert_spinBox->setRange(0, frametime[onlytotaltime]);
	ui->delete_spinBox->setRange(0, frametime[onlytotaltime]);
	timestamp = 1;
	m_quickHelp->head_insert_code(1);
}

void CLinklistEditorUI::on_headdelete_btn_clicked() //ͷ���Ƴ���ť�ۺ��� 
{
	/*createflag = 0;
	deleteflag = 1;
	searchflag = 0;*/

	// ��¼��ʼ״̬������ʱ������Ϊ0
	// �˴���д����
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{

		animationRecord(0, j, animation[onlytotaltime][j].x, animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;

	for (int i = 1; i <= QLinkList.size(); ++i) //�����󴴽� 
	{
		m_scene->deletenode(i);
	}  if (!QLinkList.isEmpty())
	{
		QLinkList.removeFirst();//ɾ����һ��Ԫ�� 
	}

	onlytotaltime++;
	for (int i = 0; i < QLinkList.size(); ++i)
	{
		QString tmp = QLinkList.at(i).m_StrName;
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);

		animationRecord(1, i, i, x);
		frametime[onlytotaltime] = i;
	}

	ui->spinBox->setRange(0, frametime[onlytotaltime]);
	ui->insert_spinBox->setRange(0, frametime[onlytotaltime]);
	ui->delete_spinBox->setRange(0, frametime[onlytotaltime]);
	timestamp = 1;
	m_quickHelp->location_delete_code(1);
}

void CLinklistEditorUI::on_taildelete_btn_clicked() //β���Ƴ���ť�ۺ��� 
{
	/*createflag = 0;
	deleteflag = 1;
	searchflag = 0;*/

	// ��¼��ʼ״̬������ʱ������Ϊ0
	// �˴���д����
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{

		animationRecord(0, j, animation[onlytotaltime][j].x, animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;

	for (int i = 1; i <= QLinkList.size(); ++i) //�����󴴽� 
	{
		m_scene->deletenode(i);
	}
	if (!QLinkList.isEmpty())
	{
		QLinkList.removeLast();//ɾ�����һ��Ԫ�� 
	}

	onlytotaltime++;
	for (int i = 0; i < QLinkList.size(); ++i)
	{
		QString tmp = QLinkList.at(i).m_StrName;
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		animationRecord(1, i, i, x);
		frametime[onlytotaltime] = i;
	}

	ui->spinBox->setRange(0, frametime[onlytotaltime]);
	ui->insert_spinBox->setRange(0, frametime[onlytotaltime]);
	ui->delete_spinBox->setRange(0, frametime[onlytotaltime]);
	timestamp = 1;
	m_quickHelp->location_delete_code(1);
}

void CLinklistEditorUI::on_locationdelete_btn_clicked() //����λ���Ƴ���ť�ۺ���
{
	/*createflag = 0;
	deleteflag = 1;
	searchflag = 0;*/

	// ��¼��ʼ״̬������ʱ������Ϊ0
	// �˴���д����
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{

		animationRecord(0, j, animation[onlytotaltime][j].x, animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;

	for (int i = 1; i <= QLinkList.size(); ++i) //�����󴴽� 
	{
		m_scene->deletenode(i);
	}  int num = ui->delete_spinBox->value();
	int list_size = QLinkList.size();
	if (num<0 || num > list_size + 1)//����ɾ����Χ���� 
	{
		return;
	}
	if (!QLinkList.isEmpty())
	{
		QLinkList.removeAt(num);//ɾ��ָ��Ԫ�� 
	}

	onlytotaltime++;
	for (int i = 0; i < QLinkList.size(); ++i)
	{
		QString tmp = QLinkList.at(i).m_StrName;
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);

		animationRecord(1, i, i, x);
		frametime[onlytotaltime] = i;
	}

	ui->spinBox->setRange(0, frametime[onlytotaltime]);
	ui->insert_spinBox->setRange(0, frametime[onlytotaltime]);
	ui->delete_spinBox->setRange(0, frametime[onlytotaltime]);
	timestamp = 1;
	m_quickHelp->location_delete_code(1);
}

void CLinklistEditorUI::on_search_btn_clicked() //�ۺ��� 
{

	QString findata = ui->search_Edit->text();
	m_scene->clearScreen();//���� 
	int lsize = QLinkList.size();
	for (int i = 1; i <= lsize; ++i) {
		if (!QLinkList.isEmpty()) {
			QLinkList.removeLast(); //ɾ�����һ��Ԫ�� 
		}
	}
	QList<CNode*> nodes = m_scene->getSelectedNodes();
	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	for (int i = 0; i < temp.size(); ++i) {
		QListNode* node = new QListNode();
		node->m_StrName = temp.at(i);
		//��ӽ����� 
		QLinkList.append(*node);
	}

	for (int j = 0; j < QLinkList.size(); ++j) {

		QTime dieTime2 = QTime::currentTime().addMSecs(400);//����ʱ�� 
		while (QTime::currentTime() < dieTime2)
			QCoreApplication::processEvents(QEventLoop::AllEvents, 400);

		QTime dieTime3 = QTime::currentTime().addMSecs(400);//����ʱ�� 
		while (QTime::currentTime() < dieTime3)
			QCoreApplication::processEvents(QEventLoop::AllEvents, 400);

		QString tmpj = QLinkList.at(j).m_StrName;
		for (int k = 1; k <= 3; k++)//��˸���� 
		{
			m_scene->clearScreen();//���� 
			for (int i = 0; i < QLinkList.size(); ++i) {
				QString tmp = QLinkList.at(i).m_StrName;
				bool flag;
				int x = tmp.toUInt(&flag);
				if (!flag)
					return;
				if (k % 2 == 1) {
					if (tmp != tmpj) {
						m_scene->insertnode(i, x);//����Ļ���� 
					}
					else {
						m_scene->insertfindnode(i, x);//����Ļ���� ��� 
					}
				}
				else {
					m_scene->insertnode(i, x);//����Ļ���� 
				}
			}
			QTime dieTime = QTime::currentTime().addMSecs(200);//��ȡ�Զ�������ʱ��
				while (QTime::currentTime() < dieTime)
					QCoreApplication::processEvents(QEventLoop::AllEvents, 200);
		}

		if (tmpj == findata)//����ȣ����ٻ��� 
		{
			QTime dieTime6 = QTime::currentTime().addMSecs(400);//����ʱ�� 
			while (QTime::currentTime() < dieTime6)  QCoreApplication::processEvents(QEventLoop::AllEvents, 400);
			m_quickHelp->search_code(1); //�������� 
			return;
		}
		QTime dieTime = QTime::currentTime().addMSecs(200);//��ȡ�Զ�������ʱ��
			while (QTime::currentTime() < dieTime)
				QCoreApplication::processEvents(QEventLoop::AllEvents, 200);
	}
		
		m_quickHelp->search_code(1); //�������� 
}			