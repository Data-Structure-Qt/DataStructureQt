#pragma once 
#include "CNodeEditorScene.h" 
#include "CQuickHelpUI.h" 
#include <QFile> 
#include <QTextStream> 
#include <QTime> 
#include <qdebug.h> 
#include<QMessageBox> 
#include <QWidget> 
#include <cstdio> 
#include <iostream> 
#include "CircleQueue.h" 
#define MAX 10
using namespace std;
class CEditorScene;
namespace Ui {
	class CircleQueueUI;
}

class CircleQueueUI : public QWidget
{
	Q_OBJECT
public:
	CircleQueueUI(QWidget *parent = 0);
	~CircleQueueUI();
	void setScene(CNodeEditorScene* scene);
	void setCQuickHelpUI(CQuickHelpUI* scene);
signals:
	void  SearchBtn_SendText();
private slots:
	void on_btn_enqueue_clicked();  //����а�ť�ۺ��� 
	void on_btn_dequeue_clicked();  //�����а�ť�ۺ��� 
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::CircleQueueUI *ui;
	CNodeEditorScene *m_scene;
	CQuickHelpUI *m_quickHelp;
	CircleQueue aq;   //����ѭ������ 
};