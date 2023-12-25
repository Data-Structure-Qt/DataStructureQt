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
    void Setuitext(int i);
	void head_insert_code(int act);
	void location_delete_code(int act);
	void search_code(int act);
	void sleepTime(int time);
	/*void Search_btn_code(int act);
	void populatePseudocode(int act);
	void headinsertButton_code();
	void tailinsertButton_code();
	void insertButton_code();
	void headdeleteButton_code();
	void taildeleteButton_code();
	void deleteButton_code();*/

private:
	Ui::CQuickHelpUI *ui;
};

