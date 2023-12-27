#include "CircleQueueUI.h"
#include "ui_CircleQueueUI.h"
#include "CNodeEditorScene.h"
CircleQueueUI::CircleQueueUI(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CircleQueueUI),
	m_scene(NULL)
{
	ui->setupUi(this);
	aq.InitCircleQueue(); //��ʼ��ѭ������
}
CircleQueueUI::~CircleQueueUI()
{
}
void CircleQueueUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);
}
void CircleQueueUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);
	m_scene = scene;
	setEnabled(m_scene);
	if (m_scene)
		onSceneAttached(m_scene);
}
void CircleQueueUI::onSceneAttached(CEditorScene* scene)
{
}
void CircleQueueUI::setCQuickHelpUI(CQuickHelpUI* quickHelp)
{
	m_quickHelp = quickHelp;
	setEnabled(m_quickHelp);
}
void CircleQueueUI::on_btn_enqueue_clicked()
{
	m_scene->startSort(0); //����
	QString data = ui->lineEdit->text(); //��ȡ��������
	bool flag;
	int x = data.toUInt(&flag);
	if (!flag)
		return;
	if (aq.FullQueue()) {
		m_quickHelp->push_code(1);
		QMessageBox msgBox;
		msgBox.setText(QString::fromLocal8Bit("ѭ�������������޷������"));
		msgBox.exec();
		return;
	}
	CircleQueuenode* node = new CircleQueuenode();
	node->m_Name = x;
	aq.EnQueue(node);
	m_quickHelp->push_code(2);
	//����Բ��
	m_scene->circleDraw();
	//����ͷָ��
	m_scene->headarrowDraw(aq.getQueuefront());
	//����βָ��
	m_scene->tailarrowDraw(aq.getQueuerear());
	//������� 
	for (int i = aq.getQueuerear(); i != aq.getQueuefront(); i++) { //�Ӷ�β��ʼ
		if (i >= MAX) {
			i = -1;
		}
		//����洢ֵ �Ӷ�β����ͷ���
		if (i != -1)
		{
			m_scene->circleDataDraw((*aq.at(i)).m_Name, i + 1);//���� λ��
		}
	}
}
void CircleQueueUI::on_btn_dequeue_clicked()
{
	m_scene->startSort(0); //����
	int x;
	if (aq.EmptyQueue()) {
		m_quickHelp->pop_code(1);
		QMessageBox msgBox;
		msgBox.setText(QString::fromLocal8Bit("ѭ�������ѿգ��޷�������"));
		msgBox.exec();
		return;
	}
	CircleQueuenode* node = new CircleQueuenode();
	node->m_Name = x;
	aq.DeQueue(node); //���ӵ�ֵ���ص� x
	m_quickHelp->pop_code(2);
	//����Բ��
	m_scene->circleDraw();//��ɫ
	//����ͷָ��
	m_scene->headarrowDraw(aq.getQueuefront());
	//����βָ��
	m_scene->tailarrowDraw(aq.getQueuerear());
	//��ӡ����
	for (int i = aq.getQueuerear(); i != aq.getQueuefront(); i++) {
		if (i >= MAX) {
			i = -1;
		}
		if (i != -1)
		{
			m_scene->circleDataDraw((*aq.at(i)).m_Name, i + 1);//���� λ��
		}
	}
}