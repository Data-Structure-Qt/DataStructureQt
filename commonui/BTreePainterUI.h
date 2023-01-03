#pragma once

#include "../base/CNodeEditorScene.h"
#include "base\CEditorView.h"
#include "../base/CNodeEditorScene.h"
#include <QWidget>
#include "ui_BTreePainterUI.h"
#include "BTree.h"
#include <QPainter>
#include <QPoint>
#include <QQueue>
namespace Ui { class BTreePainterUI; }
class BTreePainterUI : public QWidget
{
	Q_OBJECT

public:
	BTreePainterUI(QWidget *parent = nullptr);
	~BTreePainterUI();
	void setScene(CNodeEditorScene* scene);
	//void setCQuickHelpUI(CQuickHelpUI* scene);
	void setCEditorView(CEditorView* editorView);
	void drawtree();//»­Ê÷
private slots:
	void on_create_Btn_clicked();
	void on_onelevel_Btn_clicked();
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::BTreePainterUI *ui;
	BTree mytree;
	CNodeEditorScene *m_scene;
	CEditorView *m_editorView;
	CNode *m_nodeFactory;
	CEdge *m_edgeFactory;
	//CQuickHelpUI *m_quickHelp;
};
