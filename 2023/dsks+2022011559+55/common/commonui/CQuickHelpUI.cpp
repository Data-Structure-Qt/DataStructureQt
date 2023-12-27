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
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("��ʼB_������") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;if �ؼ����ڽڵ��ڣ�����ѭ��") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ���С�ڽڵ��һ��ֵ����������") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ��һ��ֵ ���� �ؼ���С�ڽڵ�ڶ���ֵ�������м亢��") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ�ڶ���ֵ ���� �ؼ���С�ڽڵ������ֵ �������Һ���") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie δ�ҵ��ؼ��֣�������һ���ڵ㲻ΪNULL") + "< / div>"
			"< / div>");
		break;
	case 2:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("�ҵ��ؼ��֣�����ѭ��") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;if �ؼ����ڽڵ��ڣ�����ѭ��") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ���С�ڽڵ��һ��ֵ����������") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ��һ��ֵ ���� �ؼ���С�ڽڵ�ڶ���ֵ�������м亢��") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ�ڶ���ֵ ���� �ؼ���С�ڽڵ������ֵ �������Һ���") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie δ�ҵ��ؼ��֣�������һ���ڵ㲻ΪNULL") + "< / div>"
			"< / div>");
		break;
	case 3:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("��������") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;if �ؼ����ڽڵ��ڣ�����ѭ��") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ���С�ڽڵ��һ��ֵ����������") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ��һ��ֵ ���� �ؼ���С�ڽڵ�ڶ���ֵ�������м亢��") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ�ڶ���ֵ ���� �ؼ���С�ڽڵ������ֵ �������Һ���") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie δ�ҵ��ؼ��֣�������һ���ڵ㲻ΪNULL") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("����ѭ��") + "< / div>"
			"<div id = \" code0\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ����ڽڵ��ڣ�����ѭ��") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ���С�ڽڵ��һ��ֵ����������") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ��һ��ֵ ���� �ؼ���С�ڽڵ�ڶ���ֵ�������м亢��") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ�ڶ���ֵ ���� �ؼ���С�ڽڵ������ֵ �������Һ���") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie δ�ҵ��ؼ��֣�������һ���ڵ㲻ΪNULL") + "< / div>"
			"< / div>");
		break;
	case 4:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("�����м亢��") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;if �ؼ����ڽڵ��ڣ�����ѭ��") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ���С�ڽڵ��һ��ֵ����������") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ��һ��ֵ ���� �ؼ���С�ڽڵ�ڶ���ֵ�������м亢��") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ�ڶ���ֵ ���� �ؼ���С�ڽڵ������ֵ �������Һ���") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie δ�ҵ��ؼ��֣�������һ���ڵ㲻ΪNULL") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("����ѭ��") + "< / div>"
			"<div id = \" code0\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ����ڽڵ��ڣ�����ѭ��") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ���С�ڽڵ��һ��ֵ����������") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ��һ��ֵ ���� �ؼ���С�ڽڵ�ڶ���ֵ�������м亢��") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ�ڶ���ֵ ���� �ؼ���С�ڽڵ������ֵ �������Һ���") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie δ�ҵ��ؼ��֣�������һ���ڵ㲻ΪNULL") + "< / div>"
			"< / div>");
		break;
	case 5:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("�����Һ���") + "< / div>"
			"<div id = \" code0\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ����ڽڵ��ڣ�����ѭ��") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ���С�ڽڵ��һ��ֵ����������") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ��һ��ֵ ���� �ؼ���С�ڽڵ�ڶ���ֵ�������м亢��") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ�ڶ���ֵ ���� �ؼ���С�ڽڵ������ֵ �������Һ���") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie δ�ҵ��ؼ��֣�������һ���ڵ㲻ΪNULL") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("����ѭ��") + "< / div>"
			"<div id = \" code0\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ����ڽڵ��ڣ�����ѭ��") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ���С�ڽڵ��һ��ֵ����������") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ��һ��ֵ ���� �ؼ���С�ڽڵ�ڶ���ֵ�������м亢��") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ�ڶ���ֵ ���� �ؼ���С�ڽڵ������ֵ �������Һ���") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie δ�ҵ��ؼ��֣�������һ���ڵ㲻ΪNULL") + "< / div>"
			"< / div>");
		break;
	case 6:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("��ɱ�����δ�ҵ��ؼ���") + "< / div>"
			"<div id = \" code0\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);\">< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("do") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ����ڽڵ��ڣ�����ѭ��") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ���С�ڽڵ��һ��ֵ����������") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ��һ��ֵ ���� �ؼ���С�ڽڵ�ڶ���ֵ�������м亢��") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;if �ؼ��ִ��ڽڵ�ڶ���ֵ ���� �ؼ���С�ڽڵ������ֵ �������Һ���") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("whlie δ�ҵ��ؼ��֣�������һ���ڵ㲻ΪNULL") + "< / div>"
			"< / div>");
	}
}

void CQuickHelpUI::sleepTime(int time)
{
	QTime dieTime = QTime::currentTime().addMSecs(time);//��ȡ�Զ�������ʱ��
	while (QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);	//�������̣߳�����qt�����¼�
	}
}

void CQuickHelpUI::btree_insert_code(int act)
{
	switch (act) {
	case 1:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("��ʼB_������") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("��(p == NULL)  t�ǿ���") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;���ɽ����ؼ���k�ĸ����t  �������") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("���� ѭ�� ��(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���ؼ���x�ͽ��q�ֱ���뵽p->key[i + 1]��p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;��p->keynum \<= Max  �������") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���� ���ѽ�� �����¸����t, p��qΪ����ָ��") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;����x�Ĳ���λ�� �������") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("���ɽ����ؼ���k�ĸ����t  �������") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("��(p == NULL)  t�ǿ���") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;���ɽ����ؼ���k�ĸ����t  �������") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("���� ѭ�� ��(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���ؼ���x�ͽ��q�ֱ���뵽p->key[i + 1]��p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;��p->keynum \<= Max  �������") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���� ���ѽ�� �����¸����t, p��qΪ����ָ��") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;����x�Ĳ���λ�� �������") + "< / div>"
			"< / div>");
		break;
	case 2:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("ѭ�� ��(endflag == 0 && newflag == 0)") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("��(p == NULL)  t�ǿ���") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;���ɽ����ؼ���k�ĸ����t  �������") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("���� ѭ�� ��(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���ؼ���x�ͽ��q�ֱ���뵽p->key[i + 1]��p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;��p->keynum \<= Max  �������") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���� ���ѽ�� �����¸����t, p��qΪ����ָ��") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;����x�Ĳ���λ�� �������") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();

		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("���ؼ���x�ͽ��q�ֱ���뵽p->key[i + 1]��p->ptr[i + 1]") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("��(p == NULL)  t�ǿ���") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;���ɽ����ؼ���k�ĸ����t  �������") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("���� ѭ�� ��(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���ؼ���x�ͽ��q�ֱ���뵽p->key[i + 1]��p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;��p->keynum \<= Max  �������") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���� ���ѽ�� �����¸����t, p��qΪ����ָ��") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;����x�Ĳ���λ�� �������") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();

		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(254, 197, 21); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("��p->keynum \<= Max  �������") + "< / div >"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46, 187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("��(p == NULL)  t�ǿ���") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;���ɽ����ؼ���k�ĸ����t  �������") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46, 187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("���� ѭ�� ��(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���ؼ���x�ͽ��q�ֱ���뵽p->key[i + 1]��p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;��p->keynum \<= Max  �������") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���� ���ѽ�� �����¸����t, p��qΪ����ָ��") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;����x�Ĳ���λ�� �������") + "< / div>"
			"< / div>");
		break;
	case 3:
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("ѭ�� ��(endflag == 0 && newflag == 0)") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("��(p == NULL)  t�ǿ���") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;���ɽ����ؼ���k�ĸ����t  �������") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(0, 0, 0);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("���� ѭ�� ��(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���ؼ���x�ͽ��q�ֱ���뵽p->key[i + 1]��p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;��p->keynum \<= Max  �������") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���� ���ѽ�� �����¸����t, p��qΪ����ָ��") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;����x�Ĳ���λ�� �������") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();
		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("���� ���ѽ�� �����¸����t, p��qΪ����ָ��") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("��(p == NULL)  t�ǿ���") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;���ɽ����ؼ���k�ĸ����t  �������") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("���� ѭ�� ��(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���ؼ���x�ͽ��q�ֱ���뵽p->key[i + 1]��p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;��p->keynum \<= Max  �������") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���� ���ѽ�� �����¸����t, p��qΪ����ָ��") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;����x�Ĳ���λ�� �������") + "< / div>"
			"< / div>");
		sleepTime(500);
		ui->Viewer->clear();

		ui->Viewer->append("<div id = \"codet\" class = \"panel\" style = background-color: rgb(46, 187, 209); width: 420px;>"
			"<div id = \" code\" style = \"   background-color: rgb(254, 197, 21); color: rgb(0, 0, 0);font-size:18px;\">" + QString::fromLocal8Bit("����x�Ĳ���λ�� �������") + "< / div>"
			"< / div>");
		ui->Viewer->append("<div id = \"codetrace1\" class = \"pane2\" style = \"background-color: rgb(46, 187, 209); width: 2000px;\">"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< / div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(254, 197, 21); color: rgb(254, 197, 21);font-size:18px;\">__< /div >"
			"<div id = \"code1\" style = \" background-color: rgb(255, 255, 255); color: rgb(255, 255, 255);font-size:18px;\">__< / div >"
			"<div id = \"code2\" style = \" background-color: rgb(46, 187, 209); color: rgb(46, 187, 209);font-size:18px;\">__< / div >"
			"< / div>");//�ָ���
		ui->Viewer->append("<div id = \"codetrace\" class = \"panel\" style = \"background-color: rgb(46, 187, 209); width: 420px; height: 420px;\">"
			"<div id = \" code1\" style = \"   background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("��(p == NULL)  t�ǿ���") + "< / div>"
			"<div id = \"code2\" style = \" background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit(" &nbsp;���ɽ����ؼ���k�ĸ����t  �������") + "< / div>"
			"<div id = \"code3\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("���� ѭ�� ��(endflag == 0 && newflag == 0)") + "< / div>"
			"<div id = \"code4\" style = \" background-color: rgb(46,187, 209);  color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���ؼ���x�ͽ��q�ֱ���뵽p->key[i + 1]��p->ptr[i + 1]") + "< / div>"
			"<div id = \"code5\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;��p->keynum \<= Max  �������") + "< / div>"
			"<div id = \" code6\" style = \"background-color: rgb(46,187, 209); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;���� ���ѽ�� �����¸����t, p��qΪ����ָ��") + "< / div>"
			"<div id = \" code7\" style = \"background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);font-size:18px;\">" + QString::fromLocal8Bit("&nbsp;&nbsp;����x�Ĳ���λ�� �������") + "< / div>"
			"< / div>");

	}
}