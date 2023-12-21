#include "DequeueUI.h"
#include "ui_DequeueUI.h"
#include "CNodeEditorScene.h"
#include <QFile>
#include <QTextStream>
#include <QTime>
#include <QMessageBox>
DequeueUI::DequeueUI(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::DequeueUI),
	m_scene(NULL)
{
	ui->setupUi(this);
	setSize(19);
}
void DequeueUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);
}
int DequeueUI::getFailNum()
{
	int ret = 0;
	for (int i = 0; i < hashSize; ++i)
	{
		// 查找i的元素
		int v = 1;
		for (int j = 0; j < tableSize; j++)
		{
			if (hashTable[(i + j) % tableSize] == nullptr)
			{
				break;
			}
			v++;
		}
		ret += v;
	}

	return ret;
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
void DequeueUI::on_create_btn_clicked()
{
	for (int i = 1; i <= DequeueList.size(); ++i) //删除所有节点
	{
		m_scene->deletenode(i);
	}
	DequeueList.clear();
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

void DequeueUI::on_headinsert_btn_clicked()
{

	m_scene->clearScreen();//清屏

	int data = ui->insert_Edit1->text().toInt();
	insert(data);
	m_quickHelp->insertData("insert " + ui->insert_Edit1->text());
	for (int i = 0; i < hashTable.size(); ++i)
	{
		auto node = hashTable[i];
		if (node == nullptr)
		{
			m_scene->insertnode(i, -1);
		}
		else
		{
			m_scene->insertnode(i, *node);
		}
	}
	auto ret = getRet();
	ui->label->setText(QString("ASL:success=%1,fail=%2").arg(QString::number(ret.first, 'f', 1)).arg(QString::number(ret.second, 'f', 1)));
}

void DequeueUI::on_tailinsert_btn_clicked()
{
	m_scene->clearScreen();//清屏
	m_quickHelp->tailinsertButton_code();
	for (int i = 1; i <= DequeueList.size(); ++i) //清屏后创建
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insert_Edit1->text();
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
}

void DequeueUI::on_headdelete_btn_clicked()
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

void DequeueUI::on_taildelete_btn_clicked()
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
