#pragma once

#include <QWidget>
#include "ui_paintui.h"
#include <qtextedit.h>
#include <qpainter.h>
#include <map>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <string>


class paintui : public QWidget
{
	Q_OBJECT
public:
	paintui(QWidget *parent = nullptr);
	~paintui();
	std::vector <QLabel*> all_point;
public slots:
	void add_point();
	void delete_point();
	void change();
private:
	Ui::paintuiClass ui;

};
