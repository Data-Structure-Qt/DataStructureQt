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
	void on_headinsert_btn_clicked();//双端队列前端入队功能
	void on_tailinsert_btn_clicked();//双端队列尾端入队功能
	void on_headdelete_btn_clicked();//双端队列前端出队功能
	void on_taildelete_btn_clicked();//双端队列尾端出队功能
	void on_tong_btn_clicked();//桶排序功能
	void on_tongxian_btn_clicked();//显示桶关系桶排序功能
	int Max(int i,int j);
	int Min(int i,int j);
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::DequeueUI *ui;
	CNodeEditorScene *m_scene;
	CQuickHelpUI *m_quickHelp;
};