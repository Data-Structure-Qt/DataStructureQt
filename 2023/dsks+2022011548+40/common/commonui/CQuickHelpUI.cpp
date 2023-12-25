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
	track_code();
}


CQuickHelpUI::~CQuickHelpUI()
{

}

void CQuickHelpUI::track_code()
{
	ui->Viewer->clear();
	ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
		"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("Prim算法和Kruskal算法实现最小生成树") + "< / div >"
		"< / div>");
	ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
		"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
		"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
		"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
		"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
		"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
		"< / div>");//分隔符
	ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
		"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("创建一个空集合以存储选择的顶点") + "< / div>"
		"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("选择某一顶点作为起始点") + "< / div>"
		"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("将选择的顶点添加到集合中") + "< / div>"
		"< / div>");
}

void CQuickHelpUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//获取自定义休眠时间
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);	//开启新线程，处理qt界面事件
	}
}

void CQuickHelpUI::prim_code(int act)
{
	switch (act) {
	case 1:/*46, 187, 209蓝色 254, 197, 21黄色*/
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("循环 找出已加入集合节点的最小边权值") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("找出已加入集合节点的最小边权值") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("标记该节点已经加入集合") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("将选择的边对应的顶点添加到集合中") + "< / div>"
			"< / div>");
		break;
	case 2:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size=18px;\">" + QString::fromLocal8Bit("使用Prim算法查找最小生成树") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("创建一个空集合以存储选择的顶点") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("选择某一顶点作为起始点") + "< / div>"
			"<div id = \"code3\" style = \" background-color:rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("将选择的顶点添加到集合中") + "< / div>"
			"< / div>");
	case 3:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size=18px;\">" + QString::fromLocal8Bit("将选择的顶点添加到集合中") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("找出已加入集合节点的最小边权值") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("标记该节点已经加入集合") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("将选择的边对应的顶点添加到集合中") + "< / div>"
			"< / div>");
		break;
	}
}

void CQuickHelpUI::Kruskal_code(int act)
{
	switch (act) {
	case 1:/*46, 187, 209蓝色 254, 197, 21黄色*/
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("循环 找出集合外节点的最小边权值") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("找出集合外节点的最小边权值") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("判断改变对应的节点是否形成环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("将选择的顶点添加到集合中") + "< / div>"
			"< / div>");
		break;
	case 2:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size=18px;\">" + QString::fromLocal8Bit("使用Kruskal算法查找最小生成树") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("创建一个空集合以存储选择的顶点") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("选择某一顶点作为起始点") + "< / div>"
			"<div id = \"code3\" style = \" background-color:rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("将选择的顶点添加到集合中") + "< / div>"
			"< / div>");
		break;
	case 3:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size=18px;\">" + QString::fromLocal8Bit("将选择的顶点添加到集合中") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("找出集合外节点的最小边权值") + "< / div>"
			"<div id = \"code2\" style = \" background-color:   rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("判断改变对应的节点是否形成环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("将选择的顶点添加到集合中") + "< / div>"
			"< / div>");
		break;
	case 4:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size=18px;\">" + QString::fromLocal8Bit("将选择的顶点添加到集合中") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("找出集合外节点的最小边权值") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("判断改变对应的节点是否形成环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("将选择的顶点添加到集合中") + "< / div>"
			"< / div>");
		break;
	}
}