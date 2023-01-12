/*






*/

#pragma once

#include "CEditorScene.h"
#include "CEdge.h"
#include "SortObejct.h"



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

	CNodeEditorScene(QObject *parent = NULL);

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
	void modifynode(int location,int data);
	void deletenode(int location);
	void changeNodeColor(int location);

	void dataReset(int currentIndex, int count);
	void dataDraw(double x, double  y, double  w, double h, int arr);
	void dataDraw(double x, double  y, double  w, double h, int arr, int flag);
	void clearScreen();
	void drawCircle(int x, int y,int data,int p_x,int p_y); //绘制顶点+边
	void drawCircle_search(int x, int y, int data, int p_x, int p_y, int data1);//绘制搜索结果
	void drawCircle2(int x, int y, int data1, int data2, int p_x, int p_y);
	void drawCircle_simulate(int x, int y, int data, int p_x, int p_y);

	void printInOrd(int x,int y, QString InOrd);//绘制先序遍历



	void CNodeEditorScene::drawcircle(QPoint point, QChar data, bool sign)
	{
		QGraphicsEllipseItem* rectItem = new QGraphicsEllipseItem;//绘制圆形
		QPen pen = rectItem->pen();//画笔 绘制外框
		if (sign)
			rectItem->setBrush(QBrush(QColor(240, 0, 0)));//填充颜色
		else
			rectItem->setBrush(QBrush(QColor(100, 149, 237)));//填充颜色
		pen.setColor(Qt::green);//外边框的颜色
		rectItem->setPen(pen);
		rectItem->setRect(QRectF(point.x(), point.y(), 30, 30));
		addItem(rectItem);

		QGraphicsTextItem* pItem = new QGraphicsTextItem();
		pItem->setPlainText(data);  // 纯文本
		pItem->setDefaultTextColor(QColor(0, 0, 0));  // 文本色
		pItem->setPos(QPoint(point.x() + 8, point.y() + 3));//位置
		QFont font = pItem->font();
		//font.setBold(true);//加粗
		font.setFamily("宋体");
		font.setPixelSize(14);  // 像素大小
		pItem->setFont(font);
		addItem(pItem);
	}

	void CNodeEditorScene::drawline(QLine line)
	{
		QGraphicsLineItem* lineItem = new QGraphicsLineItem();
		QPen pen2 = lineItem->pen();//画笔 绘制外框
		pen2.setColor(QColor(100, 149, 237));//外边框的颜色
		pen2.setWidth(2);
		lineItem->setPen(pen2);
		lineItem->setLine(line.x1() + 15, line.y1() + 15, line.x2() + 15, line.y2() + 15 + 14);
		addItem(lineItem);
	}

	EditMode getEditMode() const {
		return m_editMode;
	}

	template<class E>
	CEdge* changeEdgeClass(CEdge* edge);

	// factorizations
	virtual CNode* createNewNode() const;
	CNode* createNewNode(const QPointF& pos);		// calls createNewNode(), attaches to scene and sets pos
	
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
signals:
	void finished();

public Q_SLOTS:
	void setEditMode(EditMode mode);

protected Q_SLOTS:
	virtual void onSelectionChanged();

protected:
	// selection
	void moveSelectedEdgesBy(const QPointF& d);
    void prefetchSelection() const;

	// scene events

	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
	virtual void keyPressEvent(QKeyEvent *keyEvent);
	virtual void keyReleaseEvent(QKeyEvent *keyEvent);
	virtual void onLeftClick(QGraphicsSceneMouseEvent* mouseEvent, QGraphicsItem* clickedItem);
	virtual void onLeftDoubleClick(QGraphicsSceneMouseEvent*, QGraphicsItem* clickedItem);

	virtual void onLeftButtonPressed(QGraphicsSceneMouseEvent *mouseEvent);
	virtual bool onClickDrag(QGraphicsSceneMouseEvent *mouseEvent, const QPointF &clickPos);
	// called on drag after double click; returns true if handled
	virtual bool onDoubleClickDrag(QGraphicsSceneMouseEvent *mouseEvent, const QPointF &clickPos);
	virtual void onDropped(QGraphicsSceneMouseEvent* mouseEvent, QGraphicsItem* dragItem);
	

	// reimp
	virtual QList<QGraphicsItem*> getCopyPasteItems() const;
	virtual QList<QGraphicsItem*> getTransformableItems() const;
	virtual bool doUpdateCursorState(Qt::KeyboardModifiers keys, Qt::MouseButtons buttons, QGraphicsItem *hoverItem);
	virtual QObject* createActions();

    // draw
    virtual void drawBackground(QPainter *painter, const QRectF &);

protected:
	// edit mode
	EditMode m_editMode;

	// creating
	CNode *m_startNode = nullptr, *m_endNode = nullptr;
	CEdge *m_connection = nullptr;
	bool m_realStart = false;
	QPointF orgin;
	bool flag;
	QGraphicsItem *m_draggedItem = nullptr;
	CNodePort *m_startNodePort = nullptr, *m_endNodePort = nullptr;

	enum InternState {
		IS_None, IS_Creating, IS_Finishing, IS_Cancelling
	};
	InternState m_state = IS_None;

	CNode *m_nodesFactory = nullptr;
	CEdge *m_edgesFactory = nullptr;

    // cached selections
    mutable QList<CNode*> m_selNodes;
	mutable QList<CEdge*> m_selEdges;
	mutable QList<CItem*> m_selItems;

    // drawing
    int m_nextIndex = 0;


	private:
		SortObejct *_sortObj = nullptr;
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
