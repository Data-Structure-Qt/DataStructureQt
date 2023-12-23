#pragma once

#include <QWidget>

namespace Ui {
	class CQuickHelpUI;
}


class CQuickHelpUI : public QWidget
{
	Q_OBJECT

public:
	CQuickHelpUI(QWidget *parent = 0);
	~CQuickHelpUI();
	void Setuitext(int);

	void btree_search_code(int act);

	void dfs_code(int act);

	void dij_code(int act);

	void sleepTime(int time);

	void btree_insert_code(int act);

private:
	Ui::CQuickHelpUI *ui;
};

