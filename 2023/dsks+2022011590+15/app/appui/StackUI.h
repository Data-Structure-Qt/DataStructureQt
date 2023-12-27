#pragma once 
#include "CNodeEditorScene.h" 
#include "CQuickHelpUI.h" 
#include "CEditorView.h" 
#include <QWidget> 
#include "Stack.h" 
#include "Stacknode.h" 

class CEditorScene;
namespace Ui {
	class StackUI;
}

typedef struct Animation {   //����Ƭ�� 
	int x;
	int y;
	int data1;
	int data2;
	int p_x;
	int p_y;
	int flag;
	int codeid;
};

class StackUI : public QWidget
{
	Q_OBJECT
public:
	StackUI(QWidget *parent = 0);
	~StackUI();
	void setScene(CNodeEditorScene* scene);
	void setCQuickHelpUI(CQuickHelpUI* scene);
	void setCEditorView(CEditorView * editorView);

	void goToBeginButton();
	void stepBackButton();
	void playButton();
	void suspendButton();
	void stepForwardButton();
	void goToEndButton();

	Stack QStackList;
signals:
	void  SearchBtn_SendText();
private slots:
	void on_creat_btn_clicked();
	void on_clean_btn_clicked();
	void on_push_btn_clicked();
	void on_pop_btn_clicked();
	void sleepTime(int time);

protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::StackUI *ui;
	CNodeEditorScene *m_scene;
	CNode *m_nodeFactory;
	CEdge *m_edgeFactory;
	CQuickHelpUI *m_quickHelp;
	CEditorView *m_editorView;

	int history_list_array[1010];
	int history_length = 0;
	Animation animation[200][200];   //���� /�ڼ�֡/ÿ֡���岽�� 
	Animation animationSearch[200][200]; //���� /�ڼ�֡/ÿ֡���岽�� 
	int history_wideSize[200], history_highSize[200];
	int frametime[200];
	int frametimeValue[200][200];
	int insertIdCode[200];
	int framesearchtime;
	int onlytotaltime = 0;
	int timestamp = 0;  //���ȿ���ʱ��� 
	int endplaybuttonflag = 0;//ֹͣ���ű�־λ 
};