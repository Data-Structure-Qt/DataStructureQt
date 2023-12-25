#pragma once
#include "CNodeEditorScene.h"
#include "CQuickHelpUI.h"
#include <QWidget>
#include <QLinkedList>
#include "QListNode.h"
#include "Dequeuenode.h"
#include "Dequeue.h"
class CEditorScene;
namespace Ui {
	class DequeueUI;
}
class DequeueUI : public QWidget
{
	Q_OBJECT
public:
	DequeueUI(QWidget *parent = 0);//构造函数
	~DequeueUI();//析构函数
	void setScene(CNodeEditorScene* scene);
	void setCQuickHelpUI(CQuickHelpUI* scene);
	Dequeue DequeueList; //双端队列
signals:
	void SearchBtn_SendText();
private slots:
	void on_create_btn_clicked();//创建功能
	void on_clean_btn_clicked();//清空功能
	void on_shellsort_btn_clicked();//希尔排序功能
	void sleeptime(int time);
	void on_shellsortshow9_btn_clicked();//不同增量的希尔排序结果
	void on_shellsortshow4_btn_clicked();
	void on_shellsortshow2_btn_clicked();
	void on_shellsortshow1_btn_clicked();
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::DequeueUI *ui;
	CNodeEditorScene *m_scene;
	CQuickHelpUI *m_quickHelp;
};