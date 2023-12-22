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
	DequeueUI(QWidget* parent = 0);//构造函数
	~DequeueUI();//析构函数
	void setScene(CNodeEditorScene* scene);
	void setCQuickHelpUI(CQuickHelpUI* scene);
	Dequeue DequeueList; //双端队列
	void setSize(int size)
	{
		tableSize = size;
		hashTable = QVector<int*>(size, nullptr);
		update();
	}
signals:
	void SearchBtn_SendText();
private slots:
	void on_create_btn_clicked();//创建功能
	void on_clean_btn_clicked();//清空功能
	void on_headinsert_btn_clicked();//双端队列前端入队功能
	void on_tailinsert_btn_clicked();//双端队列尾端入队功能
	void on_headdelete_btn_clicked();//双端队列前端出队功能
	void on_taildelete_btn_clicked();//双端队列尾端出队功能
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::DequeueUI* ui;
	CNodeEditorScene* m_scene;
	CQuickHelpUI* m_quickHelp;
	QVector<int*> hashTable;
	int useSize{ 0 }; // 已经插入的元素个数
	int findFreq{ 0 }; // 查找元素需要的次数的和
	const int hashSize{ 13 };
	int getFailNum();
	int tableSize;

	void insert(int key)
	{
		int index = hash(key);
		findFreq += 1;
		while (hashTable[index] != nullptr) {
			index = (index + 1) % tableSize;
			findFreq += 1;
		}

		hashTable[index] = new int(key);
		useSize++;
		update();
	}

	int hash(int key)
	{
		return key % hashSize;
	}
	QPair<double, double> getRet()
	{
		return QPair<double, double>(findFreq / double(useSize), getFailNum() / double(hashSize));
	}
};
