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
	DequeueUI(QWidget *parent = 0);//���캯��
	~DequeueUI();//��������
	void setScene(CNodeEditorScene* scene);
	void setCQuickHelpUI(CQuickHelpUI* scene);
	Dequeue DequeueList; //˫�˶���
signals:
	void SearchBtn_SendText();
private slots:
	void on_create_btn_clicked();//��������
	void on_clean_btn_clicked();//��չ���
	void on_headinsert_btn_clicked();//˫�˶���ǰ����ӹ���
	void on_tailinsert_btn_clicked();//˫�˶���β����ӹ���
	void on_headdelete_btn_clicked();//˫�˶���ǰ�˳��ӹ���
	void on_taildelete_btn_clicked();//˫�˶���β�˳��ӹ���
	void on_tong_btn_clicked();//Ͱ������
	void on_tongxian_btn_clicked();//��ʾͰ��ϵͰ������
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