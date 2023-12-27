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
	dij_code(1);


}


CQuickHelpUI::~CQuickHelpUI()
{

}



void CQuickHelpUI::dfs_code(int act)
{
	switch (act) {
	case 1:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("循环 检查节点u的每个相邻节点v是否被访问过") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("循环 检查节点u的每个相邻节点v") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;如果v未访问，则将v添加到已访问，DFS（v）") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;如果v都已访问，则返回上一节点") + "< / div>"
			"< / div>");
		break;
	case 2:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("如果v未访问，则将v添加到已访问，DFS（v）") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("循环 检查节点u的每个相邻节点v") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;如果v未访问，则将v添加到已访问，DFS（v）") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;如果v都已访问，则返回上一节点") + "< / div>"
			"< / div>");
		break;
	case 3:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("如果检查节点u的每个相邻节点v都已访问，则返回上一节点") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("循环 检查节点u的每个相邻节点v") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;如果v未访问，则将v添加到已访问，DFS（v）") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;如果v都已访问，则返回上一节点") + "< / div>"
			"< / div>");
	}
}



void CQuickHelpUI::dij_code(int act)
{
	switch (act) {
	case 1:
		ui->Viewer->clear();
ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = \"background-color: rgb(254, 197, 21); width: 420px;\">"
	"<div id = \"code\" style = \" background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("层序遍历代码追踪") + "</div>"
	"</div>");
ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px;\">"
	"<div id = \"code1\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">__</div>"
	"<div id = \"code1\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">__</div>"
	"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__</div>"
	"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__</div>"
	"</div>");//分隔符
ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px;\">"
	"</div>");
break;
	case 2:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("如果v未访问，则将v添加到已访问，DFS（v）") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("循环 检查节点u的每个相邻节点v") + "< / div>"

			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;如果v都已访问，则返回上一节点") + "< / div>"
			"< / div>");
		break;
	case 3:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("如果检查节点u的每个相邻节点v都已访问，则返回上一节点") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("循环 检查节点u的每个相邻节点v") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;如果v未访问，则将v添加到已访问，DFS（v）") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;如果v都已访问，则返回上一节点") + "< / div>"
			"< / div>");

	case 4:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("如果检查节点u的每个相邻节点v都已访问，则返回上一节点") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("循环 检查节点u的每个相邻节点v") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;如果v未访问，则将v添加到已访问，DFS（v）") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;如果v都已访问，则返回上一节点") + "< / div>"
			"< / div>");
	}
}
void CQuickHelpUI::level_code(int act)
{
	switch (act) {
	case 1:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("层序遍历") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("根节点入队") + "< / div>"
			"< / div>");
		break;
	case 2:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("该节点是否访问") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("该节点未被访问") + "< / div>"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("邻节点入队") + "< / div>"
			"< / div>");
		break;
	case 3:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("该节点是否访问") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("该节点未被访问") + "< / div>"
			"<div id = \" code1\" style = \"   background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("邻节点入队") + "< / div>"
			"< / div>");
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
void CQuickHelpUI::Setuitext(int i)
{

	ui->Viewer->clear();
	ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
		"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">" + QString::fromLocal8Bit("冒泡排序") + "< / div>"
		"< / div>");
	ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
		"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);\">__< / div>"
		"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);\">__< / div>"
		"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);\">__< / div>"
		"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);\">__< / div>"
		"< / div>");//分隔符
	ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
		"<div id = \" code1\" style = \"   background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
		"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;changed = 假") + "< / div>"
		"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp; 遍历 i = 1 到 未遍历元素索引-1") + "< / div>"
		"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp; &nbsp; 如果 左边气泡 > 右边气泡") + "< / div>"
		"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp; &nbsp; &nbsp;  交换（左边气泡，右边气泡） ") + "< / div>"
		"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp; &nbsp; &nbsp; changed = 真; 交换次数计数器++") + "< / div>"
		"<div id = \" code7\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("while changed 为真") + "< / div>"
		"< / div>");
}