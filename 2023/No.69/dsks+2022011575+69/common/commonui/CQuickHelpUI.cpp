#include "CQuickHelpUI.h"
#include "ui_CQuickHelpUI.h"
#include <QFile>
#include <QTextStream>
#include <QTime>


CQuickHelpUI::CQuickHelpUI(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CQuickHelpUI)
{
	ui->setupUi(this);
}


CQuickHelpUI::~CQuickHelpUI()
{

}

void CQuickHelpUI::Setuitext(int i)
{
	if (i == 1) {
		QFile file(":/Help/dfs");
		if (file.open(QFile::ReadOnly | QFile::Text))
		{
			QTextStream stream(&file);
			ui->Viewer->setHtml(stream.readAll());
		}
	}
	else {
		QFile file(":/Help/bfs");
		if (file.open(QFile::ReadOnly | QFile::Text))
		{
			QTextStream stream(&file);
			ui->Viewer->setHtml(stream.readAll());
		}
	}
}
void CQuickHelpUI::Search_btn_code()
{
	ui->Viewer->setText("if empty, return NOT_FOUND \nindex = 0, temp = head \nwhile (temp.item != v) \n\tindex++, temp = temp.next \n\tif temp == null \n\t\t return NOT_FOUND \n return index");
}

void CQuickHelpUI::headinsertButton_code()
{
	ui->Viewer->setText("Vertex vtx = new Vertex(v)\nvtx.next = head\nhead = vtx");
}
void CQuickHelpUI::tailinsertButton_code()
{
	ui->Viewer->setText("Vertex vtx = new Vertex(v)\ntail.next = vtx\ntail = vtx");
}
void CQuickHelpUI::insertButton_code()
{
	ui->Viewer->setText("Vertex pre = head\nfor (k = 0; k < i - 1; k++)\n\tpre = pre.next\nVertex aft = pre.next\nVertex vtx = new Vertex(v)\nvtx.next = aft\npre.next = vtx");
}
void CQuickHelpUI::headdeleteButton_code()
{
	ui->Viewer->setText("if empty, do nothing\ntemp = head\nhead = head.next\ndelete temp");
}
void CQuickHelpUI::taildeleteButton_code()
{
	ui->Viewer->setText("if empty, do nothing\nVertex pre = head\ntemp = head.next\nwhile (temp.next != null)\n\tpre = pre.next\npre.next = null\ndelete temp, tail = pre");
}
void CQuickHelpUI::deleteButton_code()
{
	ui->Viewer->setText("if empty, do nothing\nVertex pre = head\nfor (k = 0; k < i - 1; k++)\n\tpre = pre.next\nVertex del = pre.next, aft = del.next\npre.next = aft // bypass del\ndelete del");
}
void CQuickHelpUI::tongButton_code()//桶排序代码追踪
{
	ui->Viewer->setText("if empty, do nothing\nfind max,find min\nsize=(max-min)/n+1\ncount=(max-min)/size+1\nDivide buckets into buckets with the number of counts\nFill the elements into buckets according to the intervals\nLink the elements in the bucket to get the final sorting result");
}



void CQuickHelpUI::front_push_code(int act)
{
	switch (act) {
	case 1:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("判断队列大小") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若 队列不满") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;则在队头入队") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若 队列已满") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;则 停止入队并提示") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("节点入队") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若 队列不满") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;则在队头入队") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若 队列已满") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;则 停止入队并提示") + "< / div>"
			"< / div>");
		break;
	case 2:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("判断队列大小") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若 队列不满") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;则在队头入队") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若 队列已满") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;则 停止入队并提示") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("停止入队并提示") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若 队列不满") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;则在队头入队") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若 队列已满") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(0,0,0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;则 停止入队并提示") + "< / div>"
			"< / div>");
		break;
	}
}

void CQuickHelpUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//获取自定义休眠时间
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);	//开启新线程，处理qt界面事件
	}
}