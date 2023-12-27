#pragma once

#include <QMainWindow>
#include "ui_paintui.h"

class paint : public QMainWindow
{
	Q_OBJECT

public:
	paint(QWidget *parent = nullptr);
	~paint();

private:
	Ui::paintuiClass ui;
};
