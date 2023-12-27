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

void CQuickHelpUI::btree_search_code(int act)
{
	switch (act) {
	case 1:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("开始B_树搜索") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;if 关键字在节点内，结束循环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字小于节点第一个值，查找左孩子") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第一个值 并且 关键字小于节点第二个值，查找中间孩子") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第二个值 并且 关键字小于节点第三个值 ，查找右孩子") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie 未找到关键字，并且下一个节点不为NULL") + "< / div>"
			"< / div>");
		break;
	case 2:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("找到关键字，结束循环") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;if 关键字在节点内，结束循环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字小于节点第一个值，查找左孩子") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第一个值 并且 关键字小于节点第二个值，查找中间孩子") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第二个值 并且 关键字小于节点第三个值 ，查找右孩子") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie 未找到关键字，并且下一个节点不为NULL") + "< / div>"
			"< / div>");
		break;
	case 3:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("查找左孩子") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;if 关键字在节点内，结束循环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字小于节点第一个值，查找左孩子") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第一个值 并且 关键字小于节点第二个值，查找中间孩子") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第二个值 并且 关键字小于节点第三个值 ，查找右孩子") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie 未找到关键字，并且下一个节点不为NULL") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("继续循环") + "< / div>"
			"<div id = \" code0\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字在节点内，结束循环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字小于节点第一个值，查找左孩子") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第一个值 并且 关键字小于节点第二个值，查找中间孩子") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第二个值 并且 关键字小于节点第三个值 ，查找右孩子") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie 未找到关键字，并且下一个节点不为NULL") + "< / div>"
			"< / div>");
		break;
	case 4:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("查找中间孩子") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;if 关键字在节点内，结束循环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字小于节点第一个值，查找左孩子") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第一个值 并且 关键字小于节点第二个值，查找中间孩子") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第二个值 并且 关键字小于节点第三个值 ，查找右孩子") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie 未找到关键字，并且下一个节点不为NULL") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("继续循环") + "< / div>"
			"<div id = \" code0\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字在节点内，结束循环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字小于节点第一个值，查找左孩子") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第一个值 并且 关键字小于节点第二个值，查找中间孩子") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第二个值 并且 关键字小于节点第三个值 ，查找右孩子") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie 未找到关键字，并且下一个节点不为NULL") + "< / div>"
			"< / div>");
		break;
	case 5:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("查找右孩子") + "< / div>"
			"<div id = \" code0\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字在节点内，结束循环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字小于节点第一个值，查找左孩子") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第一个值 并且 关键字小于节点第二个值，查找中间孩子") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第二个值 并且 关键字小于节点第三个值 ，查找右孩子") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie 未找到关键字，并且下一个节点不为NULL") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("继续循环") + "< / div>"
			"<div id = \" code0\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字在节点内，结束循环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字小于节点第一个值，查找左孩子") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第一个值 并且 关键字小于节点第二个值，查找中间孩子") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第二个值 并且 关键字小于节点第三个值 ，查找右孩子") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie 未找到关键字，并且下一个节点不为NULL") + "< / div>"
			"< / div>");
		break;
	case 6:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("完成遍历，未找到关键字") + "< / div>"
			"<div id = \" code0\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字在节点内，结束循环") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字小于节点第一个值，查找左孩子") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第一个值 并且 关键字小于节点第二个值，查找中间孩子") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if 关键字大于节点第二个值 并且 关键字小于节点第三个值 ，查找右孩子") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie 未找到关键字，并且下一个节点不为NULL") + "< / div>"
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

void CQuickHelpUI::btree_insert_code(int act)
{
	switch (act) {
	case 1:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("开始B_树插入") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若(p == NULL)  t是空树") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;生成仅含关键字k的根结点t  插入完成") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("否则 循环 当(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;将关键字x和结点q分别插入到p->key[i + 1]和p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;若p->keynum \<= Max  插入完成") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;否则 分裂结点 生成新根结点t, p和q为子树指针") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;查找x的插入位置 插入完成") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("生成仅含关键字k的根结点t  插入完成") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若(p == NULL)  t是空树") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;生成仅含关键字k的根结点t  插入完成") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("否则 循环 当(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;将关键字x和结点q分别插入到p->key[i + 1]和p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;若p->keynum \<= Max  插入完成") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;否则 分裂结点 生成新根结点t, p和q为子树指针") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;查找x的插入位置 插入完成") + "< / div>"
			"< / div>");
		break;
	case 2:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("循环 当(endflag == 0 && newflag == 0)") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若(p == NULL)  t是空树") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;生成仅含关键字k的根结点t  插入完成") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("否则 循环 当(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;将关键字x和结点q分别插入到p->key[i + 1]和p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;若p->keynum \<= Max  插入完成") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;否则 分裂结点 生成新根结点t, p和q为子树指针") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;查找x的插入位置 插入完成") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();

		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("将关键字x和结点q分别插入到p->key[i + 1]和p->ptr[i + 1]") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若(p == NULL)  t是空树") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;生成仅含关键字k的根结点t  插入完成") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("否则 循环 当(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;将关键字x和结点q分别插入到p->key[i + 1]和p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;若p->keynum \<= Max  插入完成") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;否则 分裂结点 生成新根结点t, p和q为子树指针") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;查找x的插入位置 插入完成") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();

		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("若p->keynum \<= Max  插入完成") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若(p == NULL)  t是空树") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;生成仅含关键字k的根结点t  插入完成") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("否则 循环 当(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;将关键字x和结点q分别插入到p->key[i + 1]和p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;若p->keynum \<= Max  插入完成") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;否则 分裂结点 生成新根结点t, p和q为子树指针") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;查找x的插入位置 插入完成") + "< / div>"
			"< / div>");
		break;
	case 3:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("循环 当(endflag == 0 && newflag == 0)") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若(p == NULL)  t是空树") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;生成仅含关键字k的根结点t  插入完成") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("否则 循环 当(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;将关键字x和结点q分别插入到p->key[i + 1]和p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;若p->keynum \<= Max  插入完成") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;否则 分裂结点 生成新根结点t, p和q为子树指针") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;查找x的插入位置 插入完成") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("否则 分裂结点 生成新根结点t, p和q为子树指针") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若(p == NULL)  t是空树") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;生成仅含关键字k的根结点t  插入完成") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("否则 循环 当(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;将关键字x和结点q分别插入到p->key[i + 1]和p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;若p->keynum \<= Max  插入完成") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;否则 分裂结点 生成新根结点t, p和q为子树指针") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;查找x的插入位置 插入完成") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();

		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("查找x的插入位置 插入完成") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//分隔符
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("若(p == NULL)  t是空树") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;生成仅含关键字k的根结点t  插入完成") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("否则 循环 当(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;将关键字x和结点q分别插入到p->key[i + 1]和p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;若p->keynum \<= Max  插入完成") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;否则 分裂结点 生成新根结点t, p和q为子树指针") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;查找x的插入位置 插入完成") + "< / div>"
			"< / div>");

	}
}