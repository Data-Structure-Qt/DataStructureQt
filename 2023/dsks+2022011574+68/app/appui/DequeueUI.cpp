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
void DequeueUI::on_create_btn_clicked()
{
	for (int i = 1; i <= DequeueList.size(); ++i) //ɾ�����нڵ�
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
		if (DequeueList.size() < 20)
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
				QString::fromLocal8Bit("ջ���!������ 20 ����������"),
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
void DequeueUI::on_shellsort_btn_clicked()//ϣ������ť����
{
	m_scene->clearScreen();//����
	int gap = DequeueList.size();//��ó�ʼ����
	int act = 1;
	for (int i = 1; i <= DequeueList.size(); ++i) //�����󴴽� 
	{
		m_scene->deletenode(i);
	}
	if (DequeueList.isEmpty()) //������Ϊ��ʱ
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("��������ؼ�������"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}
	while (gap>1)
	{
		gap /= 2;
		
		for (int i = gap; i < 18; i++) {
			DequeueList.shellsort(gap,i);//����������1ʱ��������
			m_scene->clearScreen();//����
			m_quickHelp->shellsort_push_code(act++);//����׷��
			int q = 0;
			for (int j = 0; j < DequeueList.size(); ++j)//���������
			{
				QString tmp = (*DequeueList.at(j)).m_StrName;
				bool ok2;
				int x = tmp.toUInt(&ok2);
				if (!ok2)
					return;
				m_scene->insertnode(j, x);
				q = j;
			}
			int k = i - gap;
			while (k>=0)
			{
				if (!DequeueList.numswap())//û�з�������
				{
					m_scene->drawline(gap, i);
					m_scene->drawline(gap, k);
				}
				else
				{
					m_scene->drawlineswap(gap, i);
					m_scene->drawlineswap(gap, k);
				}
				k -= gap;
			}
			m_scene->drawText(7);
			sleeptime(500);//ʱ������
		}
		
	}
}
void DequeueUI::on_shellsortshow9_btn_clicked() {
	m_scene->clearScreen();//����
	for (int i = 1; i <= DequeueList.size(); ++i) //�����󴴽�
	{
		m_scene->deletenode(i);
	}
	if (DequeueList.isEmpty()) //������Ϊ��ʱ
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("��������ؼ�������"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}
	int q = 0;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at2(0,i)).m_StrName;//�����������Ϊ9��������
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		q = i;
	}
	m_scene->drawText(7);
	m_quickHelp->shellsort_push_code(1);//����׷��
}
void DequeueUI::on_shellsortshow4_btn_clicked() {
	m_scene->clearScreen();//����
	for (int i = 1; i <= DequeueList.size(); ++i) //�����󴴽�
	{
		m_scene->deletenode(i);
	}
	if (DequeueList.isEmpty()) //������Ϊ��ʱ
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("��������ؼ�������"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}
	int q = 0;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at2(1, i)).m_StrName;//�����������Ϊ4��������
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		q = i;
	}
	m_scene->drawText(7);
	m_quickHelp->shellsort_push_code(2);//����׷��
}
void DequeueUI::on_shellsortshow2_btn_clicked() {
	m_scene->clearScreen();//����
	for (int i = 1; i <= DequeueList.size(); ++i) //�����󴴽�
	{
		m_scene->deletenode(i);
	}
	if (DequeueList.isEmpty()) //������Ϊ��ʱ
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("��������ؼ�������"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}
	int q = 0;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at2(2, i)).m_StrName;//�����������Ϊ2��������
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		q = i;
	}
	m_scene->drawText(7);
	m_quickHelp->shellsort_push_code(3);
}
void DequeueUI::on_shellsortshow1_btn_clicked() {
	m_scene->clearScreen();//����
	for (int i = 1; i <= DequeueList.size(); ++i) //�����󴴽�
	{
		m_scene->deletenode(i);
	}
	if (DequeueList.isEmpty()) //������Ϊ��ʱ
	{
		QMessageBox::warning(this, QString::fromLocal8Bit("��ʾ"),
			QString::fromLocal8Bit("��������ؼ�������"),
			QMessageBox::Cancel | QMessageBox::Ok);
		return;
	}
	int q = 0;
	for (int i = 0; i < DequeueList.size(); ++i)
	{
		QString tmp = (*DequeueList.at2(3, i)).m_StrName;//�����������Ϊ1��������
		bool ok2;
		int x = tmp.toUInt(&ok2);
		if (!ok2)
			return;
		m_scene->insertnode(i, x);
		q = i;
	}
	m_scene->drawText(7);
	m_quickHelp->shellsort_push_code(4);
}
void DequeueUI::sleeptime(int time)//ʱ�����ߺ���
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//��ȡ�Զ�������ʱ��
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);	//�������̣߳�����qt�����¼�
	}
}

//26, 27, 14, 13, 22, 17, 12, 23, 11, 28, 25, 24, 19, 18, 16, 15, 20, 21