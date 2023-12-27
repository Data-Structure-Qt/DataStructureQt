#include "paintui.h"
#include <QRegExp>
#include <QValidator>
#include <qlineedit.h>
#include <qbytearray.h>
#include <qstring.h>



paintui::paintui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//ui.A->setStyleSheet("background: rgb(255,0,0)");
}

paintui::~paintui()
{}

void paintui::add_point()
{
	QLabel *new_point = new QLabel;
	new_point->setText(ui.spinBox->text());
	this->all_point.push_back(new_point);
	
	ui.paintf->addWidget(new_point);
	//delete new_point;
}
void paintui::delete_point()
{
	delete this->all_point[this->all_point.size() - 1];
	this->all_point.pop_back();
}
void paintui::change()
{
	if (ui.spinBox_2->text().toInt() - 1 - 1 > this->all_point.size())
	{
		return;
	}
	else if (ui.spinBox_2->text().toInt() - 1 <= 1)
	{
		return;
	}
	//int a = ui.spinBox_2->text().toInt();
	for (int i = 0; i < (ui.spinBox_2->text().toInt() - 1) / 2; ++i)
	{
		std::swap(all_point[i], all_point[(ui.spinBox_2->text().toInt() - 1) - i]);
	}
	std::vector<QLabel*>tem;
	for (int i = 0; i < this->all_point.size(); ++i)
	{
		QLabel *new_point = new QLabel;
		new_point->setText(this->all_point[i]->text());
		tem.push_back(new_point);
	}
	for (auto &one : this->all_point)
	{
		delete one;
	}
	this->all_point.clear();
	this->all_point = tem;
	for (auto &one : this->all_point)
	{
		ui.paintf->addWidget(one);
	}
}