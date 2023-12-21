#include "DequeueUI.h"
#include "ui_DequeueUI.h"
#include "CNodeEditorScene.h"
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QMessageBox>
DequeueUI::DequeueUI(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::DequeueUI),
	m_scene(NULL)
{
	ui->setupUi(this);
}
void DequeueUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);
}
void DequeueUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);
	m_scene = scene;
	setEnabled(m_scene);
	if (m_scene)
		onSceneAttached(m_scene);
}
void DequeueUI::onSceneAttached(CEditorScene* scene) {}
void DequeueUI::setCQuickHelpUI(CQuickHelpUI* quickHelp)
{
	m_quickHelp = quickHelp;
	setEnabled(m_quickHelp);
}
DequeueUI::~DequeueUI() {}
void DequeueUI::on_create_btn_clicked()//根据输入创建双端队列
{
	for (int i = 1; i <= DequeueList.size(); ++i) //删除所有节点
	{
		m_scene->deletenode(i);
	}
	DequeueList.clear();
	QList<CNode*> nodes = m_scene->getSelectedNodes();
	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	if (data.contains(",")) {//实现对于输入数据格式的判断
		temp = data.split(",");
	}
	else {
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("请注意输入格式(使用英文输入)"),
			QMessageBox::Cancel | QMessageBox::Ok);
	}
	for (int i = 0; i < temp.size(); ++i)
	{
		Dequeuenode* node = new Dequeuenode();
		node->m_StrName = temp.at(i);
		if (DequeueList.size() < 8)
		{//添加进队列
			DequeueList.tailenqueue(node);
		}
		else
		{
			int q = 0;
			for (int i = 0; i < DequeueList.size(); ++i)
			{
				QString tmp = (*DequeueList.at(i)).m_StrName;
				bool flag;
				int x = tmp.toUInt(&flag);
				if (!flag)
					return;
				m_scene->insertnode(i, x);//向屏幕绘制
				q = i;
			}
			m_scene->drawText(7);
			QMessageBox::warning(this, QString::fromLocal8Bit("提示"),
				QString::fromLocal8Bit("栈溢出!请输入 8 个以内数字"),
				QMessageBox::Cancel | QMessageBox::Ok);
			return;
		}
	}
	int q = 0;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at(i)).m_StrName;
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		m_scene->insertnode(i, x);//向屏幕绘制
		q = i;
	}
	m_scene->drawText(7);
}
void DequeueUI::on_clean_btn_clicked() //清除按钮槽函数
{
	ui->dataEdit->clear();
	m_scene->clearScreen();//清屏
	for (int i = 1; i <= DequeueList.size(); ++i)
	{
		m_scene->deletenode(i);
	}
	DequeueList.clear();
}
void DequeueUI::on_headinsert_btn_clicked()//双端队列前端入队功能
{
	m_scene->clearScreen();//清屏
	m_quickHelp->headinsertButton_code();//显示代码
	for (int i = 1; i <= DequeueList.size(); ++i)
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insertEdit->text();
	Dequeuenode* node = new Dequeuenode();
	node->m_StrName = data;
	if (DequeueList.size() < 8)
	{//添加进队列
		DequeueList.headenqueue(node);
	}
	else
	{
		int q = 0;
		for (int i = 0; i < DequeueList.size(); ++i)
		{
			QString tmp = (*DequeueList.at(i)).m_StrName;
			bool flag;
			int x = tmp.toUInt(&flag);
			if (!flag)
				return;
			m_scene->insertnode(i, x);//向屏幕绘制
			q = i;
		}
		m_scene->drawText(7);
		m_quickHelp->front_push_code(2);
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("栈溢出!请输入 8 个以内数字"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}
	int q = 0;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at(i)).m_StrName;
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		q = i;
	}
	m_scene->drawText(7);
	m_quickHelp->front_push_code(1);
}
void DequeueUI::on_tailinsert_btn_clicked()//双端队列尾端入队功能
{
	m_scene->clearScreen();//清屏
	m_quickHelp->tailinsertButton_code();
	for (int i = 1; i <= DequeueList.size(); ++i) //清屏后创建
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insertEdit->text();
	int list_size = DequeueList.size();
	Dequeuenode* node = new Dequeuenode();
	node->m_StrName = data;
	if (DequeueList.size() < 8)
	{
		DequeueList.tailenqueue(node); //尾部插入
	}
	else
	{
		int q = 0;
		for (int i = 0; i < DequeueList.size(); ++i)
		{
			QString tmp = (*DequeueList.at(i)).m_StrName;
			bool flag;
			int x = tmp.toUInt(&flag);
			if (!flag)
				return;
			m_scene->insertnode(i, x);//向屏幕绘制
			q = i;
		}
		m_scene->drawText(7);
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("栈溢出!请输入 8 个以内数字"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}
	int q = 0;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at(i)).m_StrName;
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		q = i;
	}
	m_scene->drawText(7);
}//
void DequeueUI::on_headdelete_btn_clicked()//双端队列前端出队功能
{
	m_scene->clearScreen();//清屏
	m_quickHelp->headdeleteButton_code();
	for (int i = 1; i <= DequeueList.size(); ++i) //清屏后创建
	{
		m_scene->deletenode(i);
	}
	if (!DequeueList.isEmpty())
	{
		DequeueList.headdequeue();//删除第一个元素
	}
	else
	{
		int q = 0;
		for (int i = 0; i < DequeueList.size(); ++i)
		{
			QString tmp = (*DequeueList.at(i)).m_StrName;
			bool flag;
			int x = tmp.toUInt(&flag);
			if (!flag)
				return;
			m_scene->insertnode(i, x);//向屏幕绘制
			q = i;
		}
		m_scene->drawText(7);
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("栈已空!不可继续删除"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}
	int q = 0;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at(i)).m_StrName;
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		q = i;
	}
	m_scene->drawText(7);
}
void DequeueUI::on_taildelete_btn_clicked()//双端队列尾端出队功能
{
	m_scene->clearScreen();//清屏
	m_quickHelp->taildeleteButton_code();
	for (int i = 1; i <= DequeueList.size(); ++i) //清屏后创建
	{
		m_scene->deletenode(i);
	}
	if (!DequeueList.isEmpty())
	{
		DequeueList.taildequeue();//删除最后一个元素
	}
	else
	{
		int q = 0;
		for (int i = 0; i < DequeueList.size(); ++i)
		{
			QString tmp = (*DequeueList.at(i)).m_StrName;
			bool flag;
			int x = tmp.toUInt(&flag);
			if (!flag)
				return;
			m_scene->insertnode(i, x);//向屏幕绘制
			q = i;
		}
		m_scene->drawText(7);
		QMessageBox::warning(this, QString::fromLocal8Bit("提示"),
			QString::fromLocal8Bit("栈已空!不可继续删除"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}
	int q = 0;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at(i)).m_StrName;
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		q = i;
	}
	m_scene->drawText(7);
}
int DequeueUI::Max(int i, int j)
{
	if (i > j) return i;
}

int DequeueUI::Min(int i, int j)
{
	if (i < j) return i;
}
void DequeueUI::on_tong_btn_clicked()//桶排序功能
{
	//m_scene->clearScreen();//清屏
	m_quickHelp->tongButton_code();//显示代码 显示部分为tongButton_code()
	QList<CNode*> nodes = m_scene->getSelectedNodes();
	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	for (int i = 0; i < temp.size(); ++i)
	{
		Dequeuenode* node = new Dequeuenode();
		node->m_StrName = temp.at(i);
		if (DequeueList.size() < 8)
		{//添加进队列
			DequeueList.tailenqueue(node);
		}
	}
	int max, min, n, size, count;//命名最大值max，最小值min，数据个数n，桶大小size，桶个数count
	n = DequeueList.size();
	QString tmp = (*DequeueList.at(0)).m_StrName;
	bool OK1;
	int x = tmp.toUInt(&OK1);
	if (!OK1)
		return;	
	min = x;//初始化min max
	max = x;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at(i)).m_StrName;
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		max = Max(max, x);//找出序列中的max,min
		min = Min(min, x);
	}
	size = (max - min) / n + 1;
	count = (max - min) / size + 1;


	//m_scene->tongResult(0, size);//检查参数值

	//int arr[8];
	int* arr = new int[n];//实现桶排序
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at(i)).m_StrName;
		bool ok2;
		int x_i = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		arr[i] = x_i;
	}
	 //创建桶数组
	/*int b[max+1];*/
	int* b = new int[max + 1];
	for (int i = 0; i <= max; i++)
	{
		b[i] = 0;
	}
	// 将数据放入桶中
	for (int i = 0; i < n; i++) 
	{
		b[arr[i]]++;
	}
	// 将桶中的数据按顺序放回原数组
	int index = 0;
	for (int i = 0; i <= max; i++) 
	{
		while (b[i] > 0) {
			arr[index++] = i;
			b[i]--;
		}
	}//arr为桶排序后的数组


	m_scene->drawTong(7);//打印“桶排序过程”
	for (int i = 0; i < count; i++)//绘制桶
	{
		int temp;
		temp = 0;
		for (int j = 0; j < count; j++)
		{
			if (arr[j] >= min && arr[j] < min + size)
			{
				m_scene->tong(i,temp, arr[j]);//void CNodeEditorScene::tong(int i, int location, int data)//桶排序屏幕实现 i表示第几桶
				temp ++ ;
			}
		}
		if (temp == 0)
		{
			m_scene->kongtong(i, temp, 0);
		}
		/*m_scene->tongsize(i,temp);*/
		min += size;
	}





	
	
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		m_scene->tongResult(i, arr[i]);//屏幕显示桶排序结果
	}
	m_scene->drawResult(7);//打印“桶排序结果”
	delete[]arr;
	arr = NULL;
	delete[]b;
	b = NULL;
}