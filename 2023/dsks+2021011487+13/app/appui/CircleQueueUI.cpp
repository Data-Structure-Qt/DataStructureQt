#include "CircleQueueUI.h"
#include "ui_CircleQueueUI.h"
#include "CNodeEditorScene.h"
CircleQueueUI::CircleQueueUI(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CircleQueueUI),
	m_scene(NULL)
{
	ui->setupUi(this);
	aq.InitCircleQueue(); //初始化循环队列
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
	m_scene->startSort(0); //清屏
	QString data = ui->lineEdit->text(); //获取输入数字
	bool flag;
	int x = data.toUInt(&flag);
	if (!flag)
		return;
	if (aq.FullQueue()) {
		m_quickHelp->push_code(1);
		QMessageBox msgBox;
		msgBox.setText(QString::fromLocal8Bit("循环队列已满，无法入队列"));
		msgBox.exec();
		return;
	}
	CircleQueuenode* node = new CircleQueuenode();
	node->m_Name = x;
	aq.EnQueue(node);
	m_quickHelp->push_code(2);
	//绘制圆环
	m_scene->circleDraw();
	//绘制头指针
	m_scene->headarrowDraw(aq.getQueuefront());
	//绘制尾指针
	m_scene->tailarrowDraw(aq.getQueuerear());
	//输出队列 
	for (int i = aq.getQueuerear(); i != aq.getQueuefront(); i++) { //从队尾开始
		if (i >= MAX) {
			i = -1;
		}
		//输出存储值 从队尾到队头输出
		if (i != -1)
		{
			m_scene->circleDataDraw((*aq.at(i)).m_Name, i + 1);//数字 位置
		}
	}
}
void CircleQueueUI::on_btn_dequeue_clicked()
{
	m_scene->startSort(0); //清屏
	int x;
	if (aq.EmptyQueue()) {
		m_quickHelp->pop_code(1);
		QMessageBox msgBox;
		msgBox.setText(QString::fromLocal8Bit("循环队列已空，无法出队列"));
		msgBox.exec();
		return;
	}
	CircleQueuenode* node = new CircleQueuenode();
	node->m_Name = x;
	aq.DeQueue(node); //出队的值返回到 x
	m_quickHelp->pop_code(2);
	//绘制圆环
	m_scene->circleDraw();//绿色
	//绘制头指针
	m_scene->headarrowDraw(aq.getQueuefront());
	//绘制尾指针
	m_scene->tailarrowDraw(aq.getQueuerear());
	//打印队列
	for (int i = aq.getQueuerear(); i != aq.getQueuefront(); i++) {
		if (i >= MAX) {
			i = -1;
		}
		if (i != -1)
		{
			m_scene->circleDataDraw((*aq.at(i)).m_Name, i + 1);//数字 位置
		}
	}
}