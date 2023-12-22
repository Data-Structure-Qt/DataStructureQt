#include "LinklistUI.h"  
#include "ui_LinklistUI.h"  
#include "CNodeEditorScene.h"  
#include <QFile>  
#include <QTextStream>  
#include <QTime>  
#include <qDebug> 

LinklistUI::LinklistUI(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::LinklistUI),
	m_scene(NULL)
{
	ui->setupUi(this);
}

void LinklistUI::goToBeginButton()
{
	endplaybuttonflag = 1;
	timestamp = 0;
	m_scene->clearScreen();//清屏 
	for (int j = 0; j <= frametime[0]; j++)
	{
		animationDraw(0, j);

	}
	//m_quickHelp->btree_create_code(insertIdCode[timestamp]); 
}
void LinklistUI::stepBackButton()
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
	}
}
void LinklistUI::playButton()
{
	endplaybuttonflag = 0;

	m_scene->clearScreen();//清屏 

	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
		m_quickHelp->head_insert_code(1);
	}
	timestamp = onlytotaltime;
	sleepTime(500);
}
void LinklistUI::suspendButton() {
	endplaybuttonflag = 1;
}
void LinklistUI::stepForwardButton() {
	endplaybuttonflag = 1;
	if (timestamp < onlytotaltime)
	{
		timestamp++;
		m_scene->clearScreen();//清屏 
		for (int j = 0; j <= frametime[timestamp]; j++)
		{
			animationDraw(timestamp, j);
		}
	}
}
void LinklistUI::goToEndButton() {
	endplaybuttonflag = 1;
	m_scene->clearScreen();//清屏 
	timestamp = onlytotaltime;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationDraw(onlytotaltime, j);
	}
	//m_quickHelp->btree_insert_code(insertIdCode[timestamp]); 

}

void LinklistUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//获取自定义休眠时间 
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100); //开启新线程，
	}
}
void LinklistUI::animationRecord(int totaltime, int frame, int x, int data)
{
	animation[totaltime][frame].x = x;
	animation[totaltime][frame].data = data;
}
void LinklistUI::animationSearchRecord(int totaltime, int frame, int x, int data, int flag, int
	codeid)
{
	animationSearch[totaltime][frame].x = x;
	animationSearch[totaltime][frame].data = data;
	animationSearch[totaltime][frame].flag = flag;
	animationSearch[totaltime][frame].codeid = codeid;
}
void LinklistUI::animationClean()
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
void LinklistUI::animationPrint(int totaltime, int frametime)
{
	qDebug() << "totaltime" << totaltime;
	qDebug() << "frametime" << frametime;
	int i = totaltime;
	int j = frametime;
	qDebug() << "animation[i].x " << animation[i][j].x;
	qDebug() << " animation[i].data " << animation[i][j].data;

}
void LinklistUI::animationDraw(int totaltime, int frametime)
{
	m_scene->insertnode(animation[totaltime][frametime].x,
		animation[totaltime][frametime].data); //链表只需要便利每个结点一次即可 
}
void LinklistUI::animationDrawSearch(int totaltime, int frametime, int x)
{
	m_scene->insertfindnode(animation[totaltime][frametime].x,
		animation[totaltime][frametime].data);
}
//...... 
void LinklistUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);

}
void LinklistUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);

	m_scene = scene;

	setEnabled(m_scene);

	if (m_scene)
		onSceneAttached(m_scene);
}
void LinklistUI::onSceneAttached(CEditorScene* scene)
{

}
void LinklistUI::setCQuickHelpUI(CQuickHelpUI* quickHelp)
{
	m_quickHelp = quickHelp;
	setEnabled(m_quickHelp);
}

LinklistUI::~LinklistUI()
{

}

void LinklistUI::on_headinsert_btn_clicked()
{
	int temp = 0,j;
	for (j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationRecord(0, j, animation[onlytotaltime][j].x,animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;
		for (int i = 1; i <= QLinkList.size(); ++i)  //清屏 
		{
			m_scene->deletenode(i);
		}
	QString data = ui->insert_Edit1->text(); //获取窗口输入 
	LinklistNode* node = new LinklistNode();
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
		m_scene->insertnode(i, x);   //绘制节点 
		animationRecord(1, i, i, x);
		frametime[onlytotaltime] = i;
	}

	ui->spinBox->setRange(0, frametime[onlytotaltime]);
	ui->insert_spinBox->setRange(0, frametime[onlytotaltime]);
	ui->delete_spinBox->setRange(0, frametime[onlytotaltime]);
	timestamp = 1;
	m_quickHelp->head_insert_code(1);
}

void LinklistUI::on_tailinsert_btn_clicked() //尾部插入按钮槽函数  
{
	// 记录初始状态，并将时间轴置为0 
	// 此处编写代码 
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{

		animationRecord(0, j, animation[onlytotaltime][j].x, animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;


	for (int i = 1; i <= QLinkList.size(); ++i) //清屏后创建  
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insert_Edit1->text();
	int list_size = QLinkList.size();
	LinklistNode* node = new LinklistNode();
	node->m_StrName = data;
	QLinkList.insert(list_size, *node); //尾部插入  

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

void LinklistUI::on_locationinsert_btn_clicked() //任意位置插入按钮槽函数 
{
	// 记录初始状态，并将时间轴置为0 
	// 此处编写代码 
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{

		animationRecord(0, j, animation[onlytotaltime][j].x,animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;

	for (int i = 1; i <= QLinkList.size(); ++i) //清屏后创建  
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insert_Edit2->text();
	int num = ui->insert_spinBox->value();
	int list_size = QLinkList.size();
	if (num<0 || num > list_size + 1)//超过插入范围返回  
	{
		return;
	}
	LinklistNode* node = new LinklistNode();
	node->m_StrName = data;
	QLinkList.insert(num, *node); //某个位置插入  

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
void LinklistUI::on_headdelete_btn_clicked() //头部移除按钮槽函数  
{
	// 记录初始状态，并将时间轴置为0 
	// 此处编写代码 
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{

		animationRecord(0, j, animation[onlytotaltime][j].x,
			animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;

	for (int i = 1; i <= QLinkList.size(); ++i) //清屏后创建  
	{
		m_scene->deletenode(i);
	}  if (!QLinkList.isEmpty())
	{
		QLinkList.removeFirst();//删除第一个元素  
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
void LinklistUI::on_taildelete_btn_clicked() //尾部移除按钮槽函数  
{
	// 记录初始状态，并将时间轴置为0 
	// 此处编写代码
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{
		animationRecord(0, j, animation[onlytotaltime][j].x, animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;

	for (int i = 1; i <= QLinkList.size(); ++i) //清屏后创建  
	{
		m_scene->deletenode(i);
	}
	if (!QLinkList.isEmpty())
	{
		QLinkList.removeLast();//删除最后一个元素  
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
void LinklistUI::on_locationdelete_btn_clicked() //任意位置移除按钮槽函数 
{
	// 记录初始状态，并将时间轴置为0 
	// 此处编写代码 
	int temp = 0;
	for (int j = 0; j <= frametime[onlytotaltime]; j++)
	{

		animationRecord(0, j, animation[onlytotaltime][j].x, animation[onlytotaltime][j].data);
		temp = j;
	}
	onlytotaltime = 0;
	frametime[onlytotaltime] = temp;

	for (int i = 1; i <= QLinkList.size(); ++i) //清屏后创建  
	{
		m_scene->deletenode(i);
	}  int num = ui->delete_spinBox->value();
	int list_size = QLinkList.size();
	if (num<0 || num > list_size + 1)//超过删除范围返回  
	{
		return;
	}
	if (!QLinkList.isEmpty())
	{
		QLinkList.removeAt(num);//删除指定元素  
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
void LinklistUI::on_search_btn_clicked() //槽函数  
{
	QString findata = ui->search_Edit->text();
	m_scene->clearScreen();//清屏  
	int lsize = QLinkList.size();
	for (int i = 1; i <= lsize; ++i) {
		if (!QLinkList.isEmpty()) {
			QLinkList.removeLast(); //删除最后一个元素  
		}
	}
	QList<CNode*> nodes = m_scene->getSelectedNodes();
	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	for (int i = 0; i < temp.size(); ++i) {
		LinklistNode* node = new LinklistNode();
		node->m_StrName = temp.at(i);
		//添加进链表  
		QLinkList.append(*node);
	}

	for (int j = 0; j < QLinkList.size(); ++j) {

		QTime dieTime2 = QTime::currentTime().addMSecs(400);//休眠时间  
		while (QTime::currentTime() < dieTime2)
			QCoreApplication::processEvents(QEventLoop::AllEvents, 400);

		QTime dieTime3 = QTime::currentTime().addMSecs(400);//休眠时间  
		while (QTime::currentTime() < dieTime3)
			QCoreApplication::processEvents(QEventLoop::AllEvents, 400);

		QString tmpj = QLinkList.at(j).m_StrName;
		for (int k = 1; k <= 3; k++)//闪烁三次  
		{
			m_scene->clearScreen();//清屏  
			for (int i = 0; i < QLinkList.size(); ++i) {
				QString tmp = QLinkList.at(i).m_StrName;
				bool flag;
				int x = tmp.toUInt(&flag);
				if (!flag)
					return;
				if (k % 2 == 1) {
					if (tmp != tmpj) {
						m_scene->insertnode(i, x);//向屏幕绘制  
					}
					else {
						m_scene->insertfindnode(i, x);//向屏幕绘制 红标  
					}
				}
				else {
					m_scene->insertnode(i, x);//向屏幕绘制  
				}
			}
			QTime dieTime = QTime::currentTime().addMSecs(200);//获取自定义休眠时间 
			while (QTime::currentTime() < dieTime)
				QCoreApplication::processEvents(QEventLoop::AllEvents, 200);
		}

		if (tmpj == findata)//若相等，则不再绘制  
		{
			QTime dieTime6 = QTime::currentTime().addMSecs(400);//休眠时间  
			while (QTime::currentTime() < dieTime6)
				QCoreApplication::processEvents(QEventLoop::AllEvents, 400);
			m_quickHelp->search_code(1); //代码区域  
			return;
		}
		QTime dieTime = QTime::currentTime().addMSecs(200);//获取自定义休眠时间 
		while (QTime::currentTime() < dieTime)
			QCoreApplication::processEvents(QEventLoop::AllEvents, 200);
	}

	m_quickHelp->search_code(1); //代码区域  
}
void LinklistUI::on_create_btn_clicked()
{
	createflag = 1;
	deleteflag = 0;
	searchflag = 0;
	for (int i = 1; i <= QLinkList.size(); ++i) //删除所有节点 
	{
		m_scene->deletenode(i);
	}

	QList<CNode*> nodes = m_scene->getSelectedNodes();

	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	for (int i = 0; i < temp.size(); ++i)
	{
		LinklistNode* node = new LinklistNode();
		node->m_StrName = temp.at(i);
		//添加进链表 
		QLinkList.append(*node);
	}
	for (int i = 0; i < QLinkList.size(); ++i)
	{
		QString tmp = QLinkList.at(i).m_StrName;
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;

		m_scene->insertnode(i, x);//向屏幕绘制 
	}

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
			// 修改 
			frametime[i] = i;
			animationRecord(onlytotaltime, frametime[i], i, x);
		}
	}
	m_quickHelp->head_insert_code(1);
	timestamp = 0;
}


void LinklistUI::on_clean_btn_clicked() //清除按钮槽函数 
{
	m_scene->clearScreen();
	ui->dataEdit->clear();
	for (int i = 1; i <= QLinkList.size(); ++i)
	{
		m_scene->deletenode(i);
	}
	QLinkList.clear();
}
void LinklistUI::josephu() { 
	int begin = ui->spinBox_3->value();
	int m = ui->spinBox_2->value();
	int result;
	while (QLinkList.size() > 1) {
		result = (begin + m - 1) % QLinkList.size();

		for (int i = 1; i <= QLinkList.size(); ++i) //清屏后创建  
		{
			m_scene->deletenode(i);
		}

		int list_size = QLinkList.size();
		if (begin<0 || begin > list_size + 1)//超过删除范围返回  
		{
			return;
		}
		if (!QLinkList.isEmpty())
		{
			QLinkList.removeAt(result);//删除指定元素  
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

		begin = result % QLinkList.size();
	}
}

