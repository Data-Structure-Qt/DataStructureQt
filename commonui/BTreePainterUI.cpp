#include "BTreePainterUI.h"


BTreePainterUI::BTreePainterUI(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::BTreePainterUI),
	m_scene(NULL)
{
	ui->setupUi(this);
	ui->data_Edit->setText("ABDH##I##E#J##CF#K##G##");
}
void BTreePainterUI::setScene(CNodeEditorScene* scene)
{
	if (m_scene)
		onSceneDetached(m_scene);
	m_scene = scene;
	setEnabled(m_scene);
	if (m_scene)
		onSceneAttached(m_scene);
}
void BTreePainterUI::onSceneAttached(CEditorScene* scene)
{
}
void BTreePainterUI::onSceneDetached(CEditorScene* scene)
{
	scene->disconnect(this);
}
void BTreePainterUI::setCEditorView(CEditorView* editorView)
{
	m_editorView = editorView;
	setEnabled(m_editorView);
}

void BTreePainterUI::drawtree()
{
	if (mytree.getRoot() == nullptr) return;
	for (int i = 0; i < mytree.size(); i++) {
		if (i != 0)
			m_scene->drawline(mytree.getLines()[i - 1]);//画线
	}
	BNode* cur = mytree.getRoot();
	QQueue<BNode*> q;
	q.enqueue(cur);
	while (!q.isEmpty()) {
		cur = q.dequeue();
		
		m_scene->drawcircle(cur->point, cur->data, cur->sign);//画圆
		if (cur->left)
			q.enqueue(cur->left);
		if (cur->right)
			q.enqueue(cur->right);
	}
}

BTreePainterUI::~BTreePainterUI()
{
}
void BTreePainterUI::on_create_Btn_clicked()
{
	mytree.clear();
	m_scene->clearScreen();//清屏
	if (!ui->data_Edit->text().isEmpty())
		mytree.setpreStr(ui->data_Edit->text());
	else
		return;
	int i = 0;
	BNode *roott = new BNode;
	mytree.createBTree(roott, i);
	mytree.setroot(roott);
	mytree.leveltravl();//层序结点高度设置
	mytree.setmypoints();//结点坐标设置
	drawtree();//画树

	//适应窗口m_editorView->fitToView();
	//适应网格m_scene->addUndoState();
}
void BTreePainterUI::on_onelevel_Btn_clicked()
{
	int level = ui->data_spin->text().toInt();
	BNode* cur = mytree.getRoot();
	QQueue<BNode*> q;
	q.enqueue(cur);
	while (!q.isEmpty()) {
		cur = q.dequeue();
		if (cur->level == level) {
			//qDebug() << "zhaodaole";
			cur->sign = 1;
		}
		else
			cur->sign = 0;
		if (cur->left)
			q.enqueue(cur->left);
		if (cur->right)
			q.enqueue(cur->right);
	}
	m_scene->clearScreen();
	drawtree();
}

