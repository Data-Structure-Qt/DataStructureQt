
#pragma once

#include "CEditorScene.h"
#include "CEdge.h"

class CNode;
//class CEdge;
class CNodePort;
class CNodeSceneActions;


enum EditMode
{
	EM_Default,
	EM_AddNodes,
	EM_AddEdges,
	EM_Transform,
	EM_Tree,
	EM_Factor
};


class CNodeEditorScene : public CEditorScene
{
	Q_OBJECT

public:
	typedef CEditorScene Super;

	CNodeEditorScene(QObject* parent = NULL);

	// reimp
	virtual CEditorScene* createScene() const {
		return new CNodeEditorScene();
	}

	virtual void initialize();
	virtual bool fromGraph(const Graph& g);
	virtual bool toGraph(Graph& g);

	// operations
	bool startNewConnection(const QPointF& pos);
	void cancel(const QPointF& pos = QPointF());
	void insertnode(int location, int data);
	void insertnode(int x, int y, int data);

	void insertfindnode(int location, int data);
	void modifynode(int location, int data);
	void deletenode(int location);
	void changeNodeColor(int location);
	void clearScreen();
	void pixmapScreen();
	void mousePressEvent(QGraphicsSceneMouseEvent* e); //鼠标按下事件
	void mouseMoveEvent(QGraphicsSceneMouseEvent* e); //鼠标移动事件
	void paintEvent(QPaintEvent*); //绘制事件

	EditMode getEditMode() const {
		return m_editMode;
	}

	template<class E>
	CEdge* changeEdgeClass(CEdge* edge);

	// factorizations
	virtual CNode* createNewNode() const;
	virtual CNode* createSearchNode() const;
	CNode* createNewNode(const QPointF& pos);		// calls createNewNode(), attaches to scene and sets pos
	CNode* createSearchNode(const QPointF& pos);

	virtual CEdge* createNewConnection() const;
	CEdge* createNewConnection(CNode* startNode, CNode* endNode);	// calls createNewConnection(), attaches to scene and sets nodes

	void setNodesFactory(CNode* node);
	void setEdgesFactory(CEdge* node);

	CNode* getNodesFactory() { return m_nodesFactory; }
	CEdge* getEdgesFactory() { return m_edgesFactory; }

	// selections
	virtual void moveSelectedItemsBy(const QPointF& d, bool snapped = false);

	virtual int getBoundingMargin() const { return 5; }

	const QList<CNode*>& getSelectedNodes() const;
	const QList<CEdge*>& getSelectedEdges() const;
	const QList<CItem*>& getSelectedNodesEdges() const;

Q_SIGNALS:
	void editModeChanged(int mode);

public Q_SLOTS:
	void setEditMode(EditMode mode);

protected Q_SLOTS:
	virtual void onSelectionChanged();

protected:
	// selection
	void moveSelectedEdgesBy(const QPointF& d);
	void prefetchSelection() const;

	// scene events

	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouseEvent);
	virtual void keyPressEvent(QKeyEvent* keyEvent);
	virtual void keyReleaseEvent(QKeyEvent* keyEvent);
	virtual void onLeftClick(QGraphicsSceneMouseEvent* mouseEvent, QGraphicsItem* clickedItem);
	virtual void onLeftDoubleClick(QGraphicsSceneMouseEvent*, QGraphicsItem* clickedItem);

	virtual void onLeftButtonPressed(QGraphicsSceneMouseEvent* mouseEvent);
	virtual bool onClickDrag(QGraphicsSceneMouseEvent* mouseEvent, const QPointF& clickPos);
	// called on drag after double click; returns true if handled
	virtual bool onDoubleClickDrag(QGraphicsSceneMouseEvent* mouseEvent, const QPointF& clickPos);
	virtual void onDropped(QGraphicsSceneMouseEvent* mouseEvent, QGraphicsItem* dragItem);


	// reimp
	virtual QList<QGraphicsItem*> getCopyPasteItems() const;
	virtual QList<QGraphicsItem*> getTransformableItems() const;
	virtual bool doUpdateCursorState(Qt::KeyboardModifiers keys, Qt::MouseButtons buttons, QGraphicsItem* hoverItem);
	virtual QObject* createActions();

	// draw
	virtual void drawBackground(QPainter* painter, const QRectF&);

protected:
	// edit mode
	EditMode m_editMode;

	// creating
	CNode* m_startNode = nullptr, * m_endNode = nullptr;
	CEdge* m_connection = nullptr;
	bool m_realStart = false;
	QPointF orgin;
	bool flag;
	QGraphicsItem* m_draggedItem = nullptr;
	CNodePort* m_startNodePort = nullptr, * m_endNodePort = nullptr;

	enum InternState {
		IS_None, IS_Creating, IS_Finishing, IS_Cancelling
	};
	InternState m_state = IS_None;

	CNode* m_nodesFactory = nullptr;
	CEdge* m_edgesFactory = nullptr;

	// cached selections
	mutable QList<CNode*> m_selNodes;
	mutable QList<CEdge*> m_selEdges;
	mutable QList<CItem*> m_selItems;

	// drawing
	int m_nextIndex = 0;

public:
	QPixmap* myPix;  //定义绘制类的指针
	QPointF startPoint;  //画笔的起始位置
	QColor color;  //画笔颜色
	QFont font;  //画笔粗细
	double pensize = 5; //画笔粗细调整
	QGraphicsPixmapItem* pix;
};


// operations

template<class E>
inline CEdge* CNodeEditorScene::changeEdgeClass(CEdge* edge)
{
	if (!edge)
		return NULL;

	// same class, dont change
	if (edge->factoryId() == E::factoryId())
		return edge;

	// clone & kill original
	E* newEdge = new E;
	// assign nodes
	newEdge->setFirstNode(edge->firstNode(), edge->firstPortId());
	newEdge->setLastNode(edge->lastNode(), edge->lastPortId());
	// add to scene
	addItem(newEdge);
	// copy attrs & flags
	newEdge->copyDataFrom(edge);
	// copy id
	QString id = edge->getId();
	// remove original
	removeItem(edge);
	delete edge;
	// set id to copy
	newEdge->setId(id);

	return newEdge;
}
