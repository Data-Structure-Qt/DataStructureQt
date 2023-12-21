#pragma once

#include <QWidget>
#include <QtWidgets/QPushButton>

namespace Ui {
	class CQuickHelpUI;
}


class CQuickHelpUI : public QWidget
{
	Q_OBJECT

public:
	CQuickHelpUI(QWidget *parent = 0);
	~CQuickHelpUI();
	QPushButton *searchButton;
	void Setuitext(int);
	void Search_btn_code();
	void headinsertButton_code();
	void tailinsertButton_code();
	void insertButton_code();
	void headdeleteButton_code();
	void taildeleteButton_code();
	void deleteButton_code();

	void push_code(int act);

	void pop_code(int act);

private:
	Ui::CQuickHelpUI *ui;
};

