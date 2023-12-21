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
void DequeueUI::on_create_btn_clicked()//�������봴��˫�˶���
{
	for (int i = 1; i <= DequeueList.size(); ++i) //ɾ�����нڵ�
	{
		m_scene->deletenode(i);
	}
	DequeueList.clear();
	QList<CNode*> nodes = m_scene->getSelectedNodes();
	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	if (data.contains(",")) {//ʵ�ֶ����������ݸ�ʽ���ж�
		temp = data.split(",");
	}
	else {
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("��ע�������ʽ(ʹ��Ӣ������)"),
			QMessageBox::Cancel | QMessageBox::Ok);
	}
	for (int i = 0; i < temp.size(); ++i)
	{
		Dequeuenode* node = new Dequeuenode();
		node->m_StrName = temp.at(i);
		if (DequeueList.size() < 8)
		{//��ӽ�����
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
				m_scene->insertnode(i, x);//����Ļ����
				q = i;
			}
			m_scene->drawText(7);
			QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
				QString::fromLocal8Bit("ջ���!������ 8 ����������"),
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
		m_scene->insertnode(i, x);//����Ļ����
		q = i;
	}
	m_scene->drawText(7);
}
void DequeueUI::on_clean_btn_clicked() //�����ť�ۺ���
{
	ui->dataEdit->clear();
	m_scene->clearScreen();//����
	for (int i = 1; i <= DequeueList.size(); ++i)
	{
		m_scene->deletenode(i);
	}
	DequeueList.clear();
}
void DequeueUI::on_headinsert_btn_clicked()//˫�˶���ǰ����ӹ���
{
	m_scene->clearScreen();//����
	m_quickHelp->headinsertButton_code();//��ʾ����
	for (int i = 1; i <= DequeueList.size(); ++i)
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insertEdit->text();
	Dequeuenode* node = new Dequeuenode();
	node->m_StrName = data;
	if (DequeueList.size() < 8)
	{//��ӽ�����
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
			m_scene->insertnode(i, x);//����Ļ����
			q = i;
		}
		m_scene->drawText(7);
		m_quickHelp->front_push_code(2);
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("ջ���!������ 8 ����������"),
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
void DequeueUI::on_tailinsert_btn_clicked()//˫�˶���β����ӹ���
{
	m_scene->clearScreen();//����
	m_quickHelp->tailinsertButton_code();
	for (int i = 1; i <= DequeueList.size(); ++i) //�����󴴽�
	{
		m_scene->deletenode(i);
	}
	QString data = ui->insertEdit->text();
	int list_size = DequeueList.size();
	Dequeuenode* node = new Dequeuenode();
	node->m_StrName = data;
	if (DequeueList.size() < 8)
	{
		DequeueList.tailenqueue(node); //β������
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
			m_scene->insertnode(i, x);//����Ļ����
			q = i;
		}
		m_scene->drawText(7);
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("ջ���!������ 8 ����������"),
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
void DequeueUI::on_headdelete_btn_clicked()//˫�˶���ǰ�˳��ӹ���
{
	m_scene->clearScreen();//����
	m_quickHelp->headdeleteButton_code();
	for (int i = 1; i <= DequeueList.size(); ++i) //�����󴴽�
	{
		m_scene->deletenode(i);
	}
	if (!DequeueList.isEmpty())
	{
		DequeueList.headdequeue();//ɾ����һ��Ԫ��
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
			m_scene->insertnode(i, x);//����Ļ����
			q = i;
		}
		m_scene->drawText(7);
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("ջ�ѿ�!���ɼ���ɾ��"),
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
void DequeueUI::on_taildelete_btn_clicked()//˫�˶���β�˳��ӹ���
{
	m_scene->clearScreen();//����
	m_quickHelp->taildeleteButton_code();
	for (int i = 1; i <= DequeueList.size(); ++i) //�����󴴽�
	{
		m_scene->deletenode(i);
	}
	if (!DequeueList.isEmpty())
	{
		DequeueList.taildequeue();//ɾ�����һ��Ԫ��
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
			m_scene->insertnode(i, x);//����Ļ����
			q = i;
		}
		m_scene->drawText(7);
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("ջ�ѿ�!���ɼ���ɾ��"),
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
void DequeueUI::on_tong_btn_clicked()//Ͱ������
{
	//m_scene->clearScreen();//����
	m_quickHelp->tongButton_code();//��ʾ���� ��ʾ����ΪtongButton_code()
	QList<CNode*> nodes = m_scene->getSelectedNodes();
	QString data = ui->dataEdit->text();
	QStringList temp = data.split(",");
	for (int i = 0; i < temp.size(); ++i)
	{
		Dequeuenode* node = new Dequeuenode();
		node->m_StrName = temp.at(i);
		if (DequeueList.size() < 8)
		{//��ӽ�����
			DequeueList.tailenqueue(node);
		}
	}
	int max, min, n, size, count;//�������ֵmax����Сֵmin�����ݸ���n��Ͱ��Сsize��Ͱ����count
	n = DequeueList.size();
	QString tmp = (*DequeueList.at(0)).m_StrName;
	bool OK1;
	int x = tmp.toUInt(&OK1);
	if (!OK1)
		return;	
	min = x;//��ʼ��min max
	max = x;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at(i)).m_StrName;
		bool flag;
		int x = tmp.toUInt(&flag);
		if (!flag)
			return;
		max = Max(max, x);//�ҳ������е�max,min
		min = Min(min, x);
	}
	size = (max - min) / n + 1;
	count = (max - min) / size + 1;


	//m_scene->tongResult(0, size);//������ֵ

	//int arr[8];
	int* arr = new int[n];//ʵ��Ͱ����
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at(i)).m_StrName;
		bool ok2;
		int x_i = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		arr[i] = x_i;
	}
	 //����Ͱ����
	/*int b[max+1];*/
	int* b = new int[max + 1];
	for (int i = 0; i <= max; i++)
	{
		b[i] = 0;
	}
	// �����ݷ���Ͱ��
	for (int i = 0; i < n; i++) 
	{
		b[arr[i]]++;
	}
	// ��Ͱ�е����ݰ�˳��Ż�ԭ����
	int index = 0;
	for (int i = 0; i <= max; i++) 
	{
		while (b[i] > 0) {
			arr[index++] = i;
			b[i]--;
		}
	}//arrΪͰ����������


	m_scene->drawTong(7);//��ӡ��Ͱ������̡�
	for (int i = 0; i < count; i++)//����Ͱ
	{
		int temp;
		temp = 0;
		for (int j = 0; j < count; j++)
		{
			if (arr[j] >= min && arr[j] < min + size)
			{
				m_scene->tong(i,temp, arr[j]);//void CNodeEditorScene::tong(int i, int location, int data)//Ͱ������Ļʵ�� i��ʾ�ڼ�Ͱ
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
		m_scene->tongResult(i, arr[i]);//��Ļ��ʾͰ������
	}
	m_scene->drawResult(7);//��ӡ��Ͱ��������
	delete[]arr;
	arr = NULL;
	delete[]b;
	b = NULL;
}