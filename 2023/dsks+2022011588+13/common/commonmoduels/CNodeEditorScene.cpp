#include "CNodeEditorScene.h"
#include "CNodeSceneActions.h"
#include "CNode.h"
#include "CNodePort.h"
#include "CEdge.h"
#include "CDirectEdge.h"
#include "CPolyEdge.h"
#include "CControlPoint.h"
#include "CEditorSceneDefines.h"
#include "CEditorScene_p.h"

#include <CGraphBase.h>

#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QColorDialog> 
#include <QKeyEvent>
#include <QApplication>
#include <QDebug>
#include <QTimeLine> 
#include <QElapsedTimer>
#include <QGraphicsItemAnimation>
#include "SortCreator.h"

CNodeEditorScene::CNodeEditorScene(QObject *parent) :
	Super(parent),
	m_editMode(EM_Default),
	m_startNode(NULL),
	m_endNode(NULL),
	m_connection(NULL),
	m_realStart(false),
	m_state(IS_None)
{
	// default factories
	registerItemFactory<CDirectEdge>();
	registerItemFactory<CNode>();
	registerItemFactory<CPolyEdge>();

	m_nodesFactory = factory<CNode>();
	m_edgesFactory = factory<CDirectEdge>();
	orgin.setX(-300);
	orgin.setY(-50);
	flag = false;


	// go
	initialize();
}


bool CNodeEditorScene::fromGraph(const Graph& g)
{
	reset();


	// Graph attrs
	for (const auto& attr : g.graphAttrs)
	{
		if (attr.id == attr_labels_visIds)
		{
			auto graphVis = CUtils::visFromString(attr.defaultValue.toString());
			setVisibleClassAttributes("", graphVis);
			continue;
		}

		createClassAttribute("", attr.id, attr.name, attr.defaultValue, ATTR_NONE);
	}

	for (auto it = g.attrs.constBegin(); it != g.attrs.constEnd(); ++it)
	{
		if (it.key() == attr_labels_visIds)
			continue;

		setClassAttribute("", it.key(), it.value());
	}


	// Class attrs
	for (const auto& attr : g.nodeAttrs)
	{
		if (attr.id == attr_labels_visIds)
		{
			auto nodeVis = CUtils::visFromString(attr.defaultValue.toString());
			setVisibleClassAttributes("node", nodeVis);
			continue;
		}

		if (attr.id == attr_size)
			continue;	// ignore for now

		createClassAttribute("node", attr.id, attr.name, attr.defaultValue, ATTR_NONE);
	}


	for (const auto& attr : g.edgeAttrs)
	{
		if (attr.id == attr_labels_visIds)
		{
			auto edgeVis = CUtils::visFromString(attr.defaultValue.toString());
			setVisibleClassAttributes("edge", edgeVis);
			continue;
		}

		createClassAttribute("edge", attr.id, attr.name, attr.defaultValue, ATTR_NONE);
	}


	// Nodes
	QMap<QByteArray, CNode*> nodesMap;

	for (const Node& n : g.nodes)
	{
		CNode* node = createNewNode();
		addItem(node);

		node->setId(n.id);
		nodesMap[n.id] = node;

		for (auto it = n.attrs.constBegin(); it != n.attrs.constEnd(); ++it)
		{
			node->setAttribute(it.key(), it.value());
		}

		for (auto it = n.ports.constBegin(); it != n.ports.constEnd(); ++it)
		{
			CNodePort* port = node->addPort(it.key().toLatin1(), it.value().anchor, it.value().x, it.value().y);
			Q_ASSERT(port != nullptr);
			port->setColor(it.value().color);
		}
	}


	// Edges
	for (const Edge& e : g.edges)
	{
		bool isPolyEdge = e.attrs.contains("points");
		CPolyEdge* polyEdge = isPolyEdge ? new CPolyEdge : nullptr;
		if (polyEdge)
		{
			QString pointStr = e.attrs["points"].toString();
			polyEdge->setPoints(CUtils::pointsFromString(pointStr));
		}

		CEdge* edge = polyEdge ? polyEdge : new CDirectEdge;
		addItem(edge);

		edge->setId(e.id);
		edge->setFirstNode(nodesMap[e.startNodeId], e.startPortId);
		edge->setLastNode(nodesMap[e.endNodeId], e.endPortId);

		for (auto it = e.attrs.constBegin(); it != e.attrs.constEnd(); ++it)
		{
			edge->setAttribute(it.key(), it.value());
		}
	}

	// finalize
	setSceneRect(itemsBoundingRect());

	addUndoState();

	return true;
}


bool CNodeEditorScene::toGraph(Graph& g)
{
	g.clear();


	// class attributes
	auto graphAttrs = getClassAttributes("", false);
	for (auto it = graphAttrs.constBegin(); it != graphAttrs.constEnd(); ++it)
	{
		const auto& attr = *it;
		if (attr.flags & ATTR_VIRTUAL)
			continue;
		g.graphAttrs[it.key()] = attr;
	}

	auto nodeAttrs = getClassAttributes("node", false);
	for (auto it = nodeAttrs.constBegin(); it != nodeAttrs.constEnd(); ++it)
	{
		const auto& attr = *it;
		if (attr.flags & ATTR_VIRTUAL)
			continue;
		g.nodeAttrs[it.key()] = attr;
	}

	auto edgeAttrs = getClassAttributes("edge", false);
	for (auto it = edgeAttrs.constBegin(); it != edgeAttrs.constEnd(); ++it)
	{
		const auto& attr = *it;
		if (attr.flags & ATTR_VIRTUAL)
			continue;
		g.edgeAttrs[it.key()] = attr;
	}

	// temp solution
	g.nodeAttrs.remove("size");
	g.nodeAttrs.remove("pos");


	// visibility
	static AttrInfo _vis_({ attr_labels_visIds , "Visible Labels", QVariant::StringList });

	auto nodeVis = getVisibleClassAttributes("node", false);
	if (nodeVis.size())
	{
		_vis_.defaultValue = CUtils::byteArraySetToStringList(nodeVis);
		g.nodeAttrs[attr_labels_visIds] = _vis_;
	}

	auto edgeVis = getVisibleClassAttributes("edge", false);
	if (edgeVis.size())
	{
		_vis_.defaultValue = CUtils::byteArraySetToStringList(edgeVis);
		g.edgeAttrs[attr_labels_visIds] = _vis_;
	}

	auto graphVis = getVisibleClassAttributes("", false);
	if (graphVis.size())
	{
		_vis_.defaultValue = CUtils::byteArraySetToStringList(graphVis);
		g.graphAttrs[attr_labels_visIds] = _vis_;
	}


	// nodes
	auto nodes = getItems<CNode>();
	for (const auto &node : nodes)
	{
		Node n;
		n.id = node->getId().toLatin1();

		QByteArrayList ports = node->getPortIds();
		for (const auto &portId : ports)
		{
			auto port = node->getPort(portId);
			Q_ASSERT(port != NULL);

			NodePort p;
			p.name = portId;
			p.anchor = port->getAlign();
			p.x = port->getX();
			p.y = port->getY();
			p.color = port->getColor();

			n.ports[portId] = p;
		}

		n.attrs = node->getLocalAttributes();
		// temp solution
		n.attrs["x"] = node->pos().x();
		n.attrs["y"] = node->pos().y();
		n.attrs.remove("pos");
		n.attrs["width"] = node->getSize().width();
		n.attrs["height"] = node->getSize().height();
		n.attrs.remove("size");

		g.nodes.append(n);
	}


	// edges
	auto edges = getItems<CEdge>();
	for (const auto &edge : edges)
	{
		Edge e;
		e.id = edge->getId().toLatin1();
		e.startNodeId = edge->firstNode()->getId().toLatin1();
		e.endNodeId = edge->lastNode()->getId().toLatin1();
		e.startPortId = edge->firstPortId();
		e.endPortId = edge->lastPortId();

		e.attrs = edge->getLocalAttributes();

		// polypoints
		auto polyEdge = dynamic_cast<CPolyEdge*>(edge);
		if (polyEdge)
		{
			const QList<QPointF>& points = polyEdge->getPoints();
			if (points.size())
				e.attrs["points"] = CUtils::pointsToString(points);
		}

		g.edges.append(e);
	}


	// TODO

	return true;
}


// reimp

void CNodeEditorScene::initialize()
{
	Super::initialize();


	// common constrains
	static CAttributeConstrainsList *edgeStyles = new CAttributeConstrainsList();
	if (edgeStyles->ids.isEmpty()) {
		edgeStyles->names << tr("None") << tr("Solid") << tr("Dots") << tr("Dashes") << tr("Dash-Dot") << tr("Dash-Dot-Dot");
		edgeStyles->ids << "none" << "solid" << "dotted" << "dashed" << "dashdot" << "dashdotdot";
	}


	// default node attr
	CAttribute nodeAttr("color", "Color", QColor(Qt::magenta), ATTR_FIXED);
	setClassAttribute("node", nodeAttr);

	CAttribute shapeAttr("shape", "Shape", "square", ATTR_FIXED);
	setClassAttribute("node", shapeAttr);

	createClassAttribute("node", "size", "Size", QSizeF(48.0, 48.0), ATTR_MAPPED | ATTR_FIXED);
	//createClassAttribute("node", "width", "Width", 11.0f, ATTR_MAPPED);
	//createClassAttribute("node", "height", "Height", 11.0f, ATTR_MAPPED);

	//createClassAttribute("node", "pos", "Position", QPointF(), ATTR_NODEFAULT | ATTR_MAPPED);
	createClassAttribute("node", "x", "X-Coordinate", 0.0f, ATTR_NODEFAULT | ATTR_MAPPED | ATTR_FIXED);
	createClassAttribute("node", "y", "Y-Coordinate", 0.0f, ATTR_NODEFAULT | ATTR_MAPPED | ATTR_FIXED);

	createClassAttribute("node", "stroke.style", "Stroke Style", "solid", ATTR_FIXED, edgeStyles);
	createClassAttribute("node", "stroke.size", "Stroke Size", 1.0, ATTR_FIXED);
	createClassAttribute("node", "stroke.color", "Stroke Color", QColor(Qt::black), ATTR_FIXED);

	createClassAttribute("node", "degree", "Degree", 0, ATTR_NODEFAULT | ATTR_VIRTUAL | ATTR_FIXED);


	// default edge attr
	CAttribute edgeAttr("color", "Color", QColor(Qt::gray), ATTR_FIXED);
	setClassAttribute("edge", edgeAttr);

	CAttribute directionAttr("direction", "Direction", "directed", ATTR_FIXED);
	setClassAttribute("edge", directionAttr);

	CAttribute weightAttr("weight", "Weight", 1.0, ATTR_FIXED);
	setClassAttribute("edge", weightAttr);

	CAttribute styleAttr("style", "Style", "solid", ATTR_FIXED);
	setClassAttribute("edge", styleAttr);

	createClassAttribute("edge", "points", "Polyline Points", "", ATTR_NODEFAULT | ATTR_MAPPED | ATTR_FIXED);


	static CAttributeConstrainsList *edgeDirections = new CAttributeConstrainsList();
	if (edgeDirections->ids.isEmpty()) {
		edgeDirections->names << tr("Directed (one end)") << tr("Mutual (both ends)") << tr("None (no ends)");
		edgeDirections->ids << "directed" << "mutual" << "undirected";
		edgeDirections->icons << QIcon(":/Icons/Edge-Directed") << QIcon(":/Icons/Edge-Mutual") << QIcon(":/Icons/Edge-Undirected");
	}
	setClassAttributeConstrains("edge", "direction", edgeDirections);

	setClassAttributeConstrains("edge", "style", edgeStyles);

	static CAttributeConstrainsList *nodeShapes = new CAttributeConstrainsList();
	if (nodeShapes->ids.isEmpty()) {
		nodeShapes->names << tr("Disc") << tr("Square") << tr("Triangle (up)") << tr("Triangle (down)") << tr("Diamond") << tr("Hexagon");
		nodeShapes->ids << "disc" << "square" << "triangle" << "triangle2" << "diamond" << "hexagon";
		nodeShapes->icons << QIcon(":/Icons/Node-Disc") << QIcon(":/Icons/Node-Square") << QIcon(":/Icons/Node-Triangle")
			<< QIcon(":/Icons/Node-Triangle-Down") << QIcon(":/Icons/Node-Diamond") << QIcon(":/Icons/Node-Hexagon");
	}
	setClassAttributeConstrains("node", "shape", nodeShapes);
}


// nodes creation

void CNodeEditorScene::setEditMode(EditMode mode)
{
	if (m_editMode != mode)
	{
		m_editMode = mode;

		switch (m_editMode)
		{
		case EM_Transform:
			getCurrentView()->setDragMode(QGraphicsView::RubberBandDrag);
			startTransform(true, false);
			break;

		case EM_Factor:
			getCurrentView()->setDragMode(QGraphicsView::RubberBandDrag);
			startTransform(true, true);
			break;

		case EM_AddNodes:
			getCurrentView()->setDragMode(QGraphicsView::NoDrag);
			startTransform(false);
			break;

		default:
			getCurrentView()->setDragMode(QGraphicsView::RubberBandDrag);
			startTransform(false);
			break;
		}

		Q_EMIT editModeChanged(m_editMode);
	}
}


bool CNodeEditorScene::startNewConnection(const QPointF& pos)
{
	if (m_editMode == EM_Transform)

		return false;

	if (m_editMode == EM_Factor)
		return false;

	if (QGraphicsItem* item = getItemAt(pos))
	{
		if (!item->isEnabled())
			return false;

		// check for port first
		CNodePort *port = dynamic_cast<CNodePort*>(item);
		if (port)
		{
			CNode *node = port->getNode();
			Q_ASSERT(node != NULL);

			if (!node->allowStartConnection())
				return false;

			m_realStart = false;
			m_startNode = node;
			m_startNodePort = port;
		}
		else
		{
			// check for node
			CNode *node = dynamic_cast<CNode*>(item);
			if (!node)
				return false;

			if (!node->allowStartConnection())
				return false;

			m_realStart = false;
			m_startNode = node;
			m_startNodePort = NULL;
		}
	}
	else
	{
		m_realStart = true;
		m_startNode = createNewNode(getSnapped(pos));
		m_startNodePort = NULL;
	}

	m_endNode = createNewNode(getSnapped(pos));

	Super::startDrag(m_endNode);

	m_connection = createNewConnection(m_startNode, m_endNode);

	if (m_startNodePort)
		m_connection->setFirstNode(m_startNode, m_startNodePort->getId());

	m_state = IS_Creating;

	// auto select created items
	m_startNode->setSelected(false);
	m_connection->setSelected(true);
	m_endNode->setSelected(true);

	return true;
}


void CNodeEditorScene::cancel(const QPointF& /*pos*/)
{
	// nothing to cancel
	if (m_state == IS_None)
		return;

	// if not cancelling already
	if (m_state != IS_Cancelling)
	{
		// cancel current drag operation
		Super::finishDrag(NULL, m_startDragItem, true);
	}

	m_state = IS_None;

	// if no creating state: return
	if (m_connection == NULL)
		return;

	// kill connector
	m_connection->setFirstNode(NULL);
	m_connection->setLastNode(NULL);
	delete m_connection;
	m_connection = NULL;

	// kill end
	delete m_endNode;
	m_endNode = NULL;

	// kill start if real
	delete m_startNode;

	m_startNode = NULL;
	m_realStart = false;
}


CNode* CNodeEditorScene::createNewNode() const
{
	if (m_nodesFactory)
	{
		auto node = dynamic_cast<CNode*>(m_nodesFactory->create());
		Q_ASSERT(node);
		node->copyDataFrom(m_nodesFactory);
		return node;
	}

	// here default
	return new CNode;
}


CNode* CNodeEditorScene::createNewNode(const QPointF& pos)
{
	auto node = createNewNode();
	addItem(node);
	node->setPos(pos);
	return node;
}


CEdge* CNodeEditorScene::createNewConnection() const
{
	if (m_edgesFactory)
	{
		auto edge = dynamic_cast<CEdge*>(m_edgesFactory->create());
		Q_ASSERT(edge);
		edge->copyDataFrom(m_edgesFactory);
		return edge;
	}

	// here default
	return new CDirectEdge();
}


CEdge* CNodeEditorScene::createNewConnection(CNode* startNode, CNode* endNode)
{
	auto edge = createNewConnection();
	addItem(edge);
	edge->setFirstNode(startNode);
	edge->setLastNode(endNode);
	return edge;
}


void CNodeEditorScene::setNodesFactory(CNode* nodeFactory)
{
	m_nodesFactory = nodeFactory;
}


void CNodeEditorScene::setEdgesFactory(CEdge* edgeFactory)
{
	m_edgesFactory = edgeFactory;
}

void CNodeEditorScene::insertnode(int location, int data)
{
	if (location == 0)
	{
		orgin.setX(-300);
		orgin.setY(-50);
		flag = false;
	}
	qDebug("%d", data);
	QPointF addnext(100, 0);

	auto node1 = createNewNode(getSnapped(orgin));//绘制矩形
	node1->setSelected(true);

	QGraphicsItem *hoverItem = getItemAt(getSnapped(orgin));
	CItem *item = dynamic_cast<CItem*>(hoverItem);
	onActionEditLabel(item, data);

	if (flag)
	{
		auto node = createNewNode(getSnapped(orgin - addnext));//绘制矩形

		createNewConnection(node, node1);//绘制箭头
	}
	QPointF next(50, 0);
	orgin = orgin + next;
	auto node2 = createNewNode(getSnapped(orgin));//绘制矩形
	node2->setSelected(true);

	addUndoState();
	orgin = orgin + addnext;
	flag = true;
}


void CNodeEditorScene::changeNodeColor(int location)
{
	QPointF modify(location * 150 - 450, -50);
	QGraphicsItem *hoverItem = getItemAt(getSnapped(modify));
	CItem *item = dynamic_cast<CItem*>(hoverItem);

}



void CNodeEditorScene::modifynode(int location, int data)
{
	QPointF modify(location * 150 - 450, -50);
	QGraphicsItem *hoverItem = getItemAt(getSnapped(modify));
	CItem *item = dynamic_cast<CItem*>(hoverItem);
	onActionEditLabel(item, data);
}

void CNodeEditorScene::deletenode(int location)
{
	QPointF modify(location * 150 - 450, -50);
	QGraphicsItem *hoverItem = getItemAt(getSnapped(modify));
	CItem *item = dynamic_cast<CItem*>(hoverItem);
	delete item;

	QPointF modify1(location * 150 - 400, -50);
	QGraphicsItem *hoverItem1 = getItemAt(getSnapped(modify1));
	CItem *item1 = dynamic_cast<CItem*>(hoverItem1);
	delete item1;

	QPointF modify2(location * 150 - 400, -50);
	QGraphicsItem *hoverItem2 = getItemAt(getSnapped(modify2));
	CItem *item2 = dynamic_cast<CItem*>(hoverItem2);
	delete item2;

}

// events

void CNodeEditorScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
	if (m_cancelled)
	{
		// call super
		Super::mouseReleaseEvent(mouseEvent);
		return;
	}

	if (m_editItem)
	{
		// call super
		Super::mouseReleaseEvent(mouseEvent);
		return;
	}

	if (m_startDragItem == NULL)
	{
		// call super
		Super::mouseReleaseEvent(mouseEvent);
		return;
	}
	else
		// cancel on RMB
		if (mouseEvent->button() == Qt::RightButton)
		{
			m_state = IS_Cancelling;
			m_skipMenuEvent = true;
		}

	// release local grabber if any
	if (m_state == IS_Creating)
	{
		m_state = IS_Finishing;

		// cancel on RMB
		if (mouseEvent->button() == Qt::RightButton)
		{
			m_state = IS_Cancelling;
			m_skipMenuEvent = true;
		}

		// cancel on same position
		if (m_startNode->pos() == m_endNode->pos())
		{
			m_state = IS_Cancelling;
		}
	}

	// finish or cancel drag
	finishDrag(mouseEvent, m_startDragItem, m_state == IS_Cancelling);

	// finalize
	if (m_state == IS_Cancelling)
	{
		cancel(mouseEvent->scenePos());
	}

	m_state = IS_None;

	// necessary to handle scene events properly
	QGraphicsScene::mouseReleaseEvent(mouseEvent);

	updateCursorState();
}


void CNodeEditorScene::keyReleaseEvent(QKeyEvent *keyEvent)
{
	// forward scene events if in text editor mode
	if (m_editItem)
	{
		bool done = m_pimpl->m_labelEditor.onKeyReleased(*this, keyEvent);
		if (done)
			updateCursorState();
		return;
	}

	Super::keyReleaseEvent(keyEvent);
}


void CNodeEditorScene::keyPressEvent(QKeyEvent *keyEvent)
{
	// forward scene events if in text editor mode
	if (m_editItem)
	{
		m_pimpl->m_labelEditor.onKeyPressed(*this, keyEvent);
		return;
	}

	bool isCtrl = (keyEvent->modifiers() == Qt::ControlModifier);
	//	bool isAlt = (keyEvent->modifiers() == Qt::AltModifier);
	//	bool isShift = (keyEvent->modifiers() == Qt::ShiftModifier);

		// Ctrl+Up/Down; alter node size by 10%
	if (keyEvent->key() == Qt::Key_Up && isCtrl)
	{
		auto &nodes = getSelectedNodes();
		if (nodes.isEmpty())
		{
			keyEvent->accept();
			return;
		}

		for (auto &node : nodes)
		{
			node->setAttribute(attr_size, node->getSize() * 1.1);
		}

		addUndoState();

		keyEvent->accept();
		return;
	}


	if (keyEvent->key() == Qt::Key_Down && isCtrl)
	{
		auto &nodes = getSelectedNodes();
		if (nodes.isEmpty())
		{
			keyEvent->accept();
			return;
		}

		for (auto &node : nodes)
		{
			node->setAttribute(attr_size, node->getSize() / 1.1);
		}

		addUndoState();

		keyEvent->accept();
		return;
	}


	// Ctrl+Left/Right; alter edge weight by 10%
	if (keyEvent->key() == Qt::Key_Right && isCtrl)
	{
		auto &edges = getSelectedEdges();
		if (edges.isEmpty())
		{
			keyEvent->accept();
			return;
		}

		for (auto &edge : edges)
		{
			edge->setAttribute(attr_weight, edge->getWeight() * 1.1);
		}

		addUndoState();

		keyEvent->accept();
		return;
	}


	if (keyEvent->key() == Qt::Key_Left && isCtrl)
	{
		auto &edges = getSelectedEdges();
		if (edges.isEmpty())
		{
			keyEvent->accept();
			return;
		}

		for (auto &edge : edges)
		{
			edge->setAttribute(attr_weight, edge->getWeight() / 1.1);
		}

		addUndoState();

		keyEvent->accept();
		return;
	}


	// cancel label edit
	if (keyEvent->key() == Qt::Key_Escape)
	{
		cancel();
		return;
	}

	Super::keyPressEvent(keyEvent);
}


// handlers

void CNodeEditorScene::onLeftButtonPressed(QGraphicsSceneMouseEvent *mouseEvent)
{
	Super::onLeftButtonPressed(mouseEvent);

	// add nodes?
	if (m_editMode == EM_AddNodes || isItemAt<CNodePort>(mouseEvent->scenePos()))
	{
		deselectAll();

		// skip calling super to avoid auto selection
		mouseEvent->accept();
	}
}


bool CNodeEditorScene::onClickDrag(QGraphicsSceneMouseEvent *mouseEvent, const QPointF &clickPos)
{
	// add nodes?
	if ((m_editMode == EM_AddNodes) || isItemAt<CNodePort>(clickPos))
	{
		if (startNewConnection(clickPos))
		{
			//setEditMode(EM_Default);
			return true;
		}
	}

	// else super
	return Super::onClickDrag(mouseEvent, clickPos);
}


bool CNodeEditorScene::onDoubleClickDrag(QGraphicsSceneMouseEvent *mouseEvent, const QPointF &clickPos)
{
	// debug
	if (clickPos == QPointF())
		qDebug() << "bug";

	// try to start new connection at click point
	if (startNewConnection(clickPos))
	{
		//mouseEvent->accept();
		return true;
	}

	// else call super
	return Super::onDoubleClickDrag(mouseEvent, clickPos);
}


void CNodeEditorScene::onDropped(QGraphicsSceneMouseEvent* mouseEvent, QGraphicsItem* dragItem)
{
	CNode *dragNode = dynamic_cast<CNode*>(dragItem);
	CEdge *dragEdge = dynamic_cast<CEdge*>(dragItem);

	// perform snap
	auto keys = mouseEvent->modifiers();
	bool isSnap = (keys & Qt::AltModifier) ? !gridSnapEnabled() : gridSnapEnabled();
	if (isSnap)
	{
		// control point:
		if (auto cp = dynamic_cast<CControlPoint*>(dragItem))
		{
			auto newPos = getSnapped(cp->scenePos());
			cp->setPos(newPos);
			return;
		}

		// nodes & edges:
		QSet<QGraphicsItem*> items;
		QSet<CEdge*> edges;

		if (dragEdge)
		{
			edges << dragEdge;

			dragNode = dragEdge->firstNode();
		}

		if (dragNode)
		{
			items << dragNode;

			auto newPos = getSnapped(dragNode->scenePos());
			auto d = newPos - dragNode->scenePos();

			for (auto item : selectedItems())
			{
				if (auto edge = dynamic_cast<CEdge*>(item))
				{
					edges << edge;

					if (dragEdge)
					{
						items << edge->firstNode();
						items << edge->lastNode();
					}
				}
				else
					items << item;
			}

			for (auto item : items)
				item->moveBy(d.x(), d.y());

			for (auto edge : edges)
				edge->onItemMoved(d);

			return;
		}

		// whatever:
	}

	Super::onDropped(mouseEvent, dragItem);
}


void CNodeEditorScene::onLeftClick(QGraphicsSceneMouseEvent* mouseEvent, QGraphicsItem* clickedItem)
{
	if (m_editMode == EM_AddNodes)
	{
		// clicked on empty space?
		if (!clickedItem)
		{
			onLeftDoubleClick(mouseEvent, clickedItem);
			//setEditMode(EM_Default);
			return;
		}
	}

	Super::onLeftClick(mouseEvent, clickedItem);
}



void CNodeEditorScene::onLeftDoubleClick(QGraphicsSceneMouseEvent* mouseEvent, QGraphicsItem* clickedItem)
{
	// clicked on empty space?
	if (!clickedItem)
	{
		// create a node here
		auto node1 = createNewNode(getSnapped(mouseEvent->scenePos()));
		node1->setSelected(true);
		QPointF next = mouseEvent->scenePos();
		QPointF add(50, 0);
		auto node2 = createNewNode(getSnapped(next + add));
		node2->setSelected(true);
		addUndoState();
		return;
	}

	Super::onLeftDoubleClick(mouseEvent, clickedItem);
}


// movement

void CNodeEditorScene::moveSelectedEdgesBy(const QPointF& d)
{
	auto edges = getSelectedEdges();
	if (edges.size())
	{
		QSet<CNode*> unselNodes;	// not selected nodes

		// move selected edges
		for (auto edge : edges)
		{
			if (!edge->firstNode()->isSelected())
				unselNodes << edge->firstNode();

			if (!edge->lastNode()->isSelected())
				unselNodes << edge->lastNode();

			edge->onItemMoved(d);
		}

		// force move non selected nodes of the selected edges
		for (auto node : unselNodes)
		{
			node->moveBy(d.x(), d.y());
		}
	}
}


// reimp

void CNodeEditorScene::moveSelectedItemsBy(const QPointF& d, bool snapped)
{
	QSet<QGraphicsItem*> items;
	QSet<CEdge*> edges;
	QGraphicsItem* focusItem = nullptr;

	// if dragging nodes and there are selected nodes: do not drag not-selected nodes
	auto dragNode = dynamic_cast<CNode*>(m_startDragItem);

	for (auto item : selectedItems())
	{
		if (!(item->flags() & item->ItemIsMovable))
			continue;

		if (!focusItem)
			focusItem = item;

		if (auto edge = dynamic_cast<CEdge*>(item))
		{
			edges << edge;

			if (!dragNode)
			{
				items << edge->firstNode();
				items << edge->lastNode();
			}
		}
		else
			items << item;
	}

	for (auto item : items)
		item->moveBy(d.x(), d.y());

	if (snapped)
		for (auto item : items)
			item->setPos(getSnapped(item->pos()));

	for (auto edge : edges)
		edge->onItemMoved(d);

	if (focusItem)
		focusItem->ensureVisible();
}


QList<QGraphicsItem*> CNodeEditorScene::getCopyPasteItems() const
{
	// only selected edges & their nodes
	QList<QGraphicsItem*> result;

	QSet<QGraphicsItem*> nodes;

	for (auto item : selectedItems())
	{
		if (auto edge = dynamic_cast<CEdge*>(item))
		{
			result << edge;
			nodes << edge->firstNode();
			nodes << edge->lastNode();
		}
		else
			if (auto node = dynamic_cast<CNode*>(item))
			{
				// orphaned nodes only
				if (node->nodeFlags() & NF_OrphanAllowed)
					nodes << node;
			}
			else
				result << item;
	}

	result << nodes.toList();

	return result;
}


QList<QGraphicsItem*> CNodeEditorScene::getTransformableItems() const
{
	QList<QGraphicsItem*> result;

	auto items = getSelectedItems();
	for (auto item : items)
		result << item->getSceneItem();

	return result;
}


bool CNodeEditorScene::doUpdateCursorState(Qt::KeyboardModifiers keys, Qt::MouseButtons buttons, QGraphicsItem *hoverItem)
{
	// port?
	if (CNodePort *portItem = dynamic_cast<CNodePort*>(hoverItem))
	{
		if (portItem->isEnabled())
		{
			setSceneCursor(Qt::CrossCursor);
			setInfoStatus(SIS_Hover_Port);
			return true;
		}
	}

	// hover item?
	if (m_editMode == EM_AddNodes)
	{
		if (hoverItem)
		{
			if (hoverItem->isEnabled())
			{
				setSceneCursor(Qt::CrossCursor);
				setInfoStatus(SIS_Hover);
				return true;
			}
		}
	}

	// handled by super?
	if (Super::doUpdateCursorState(keys, buttons, hoverItem))
		return true;

	// still not handled
	return false;
}


// painting

void CNodeEditorScene::drawBackground(QPainter *painter, const QRectF &r)
{
	Super::drawBackground(painter, r);
}



// selections

const QList<CNode*>& CNodeEditorScene::getSelectedNodes() const
{
	if (m_selNodes.isEmpty())
		prefetchSelection();

	return m_selNodes;
}


const QList<CEdge*>& CNodeEditorScene::getSelectedEdges() const
{
	if (m_selEdges.isEmpty())
		prefetchSelection();

	return m_selEdges;
}


const QList<CItem*>& CNodeEditorScene::getSelectedNodesEdges() const
{
	if (m_selItems.isEmpty())
		prefetchSelection();

	return m_selItems;
}


void CNodeEditorScene::onSelectionChanged()
{
	// drop cached selections
	m_selNodes.clear();
	m_selEdges.clear();
	m_selItems.clear();

	Super::onSelectionChanged();
}


void CNodeEditorScene::prefetchSelection() const
{
	m_selNodes.clear();
	m_selEdges.clear();
	m_selItems.clear();

	auto selItems = selectedItems();

	for (auto* item : selItems)
	{
		if (CNode* node = dynamic_cast<CNode*>(item))
		{
			m_selNodes << node;
			m_selItems << node;
			continue;
		}

		if (CEdge* edge = dynamic_cast<CEdge*>(item))
		{
			m_selEdges << edge;
			m_selItems << edge;
			continue;
		}
	}
}


// menu & actions

QObject* CNodeEditorScene::createActions()
{
	return new CNodeSceneActions(this);
}





/*
一般的冒泡排序写法
template<typename T>
void bubble_sort(T arr[], int len)
{
	int i, j;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j],arr[j+1]);
			}
}
*/

void CNodeEditorScene::dataDraw(double x, double  y, double  w, double h, int arr)
{
	QGraphicsRectItem *rectItem = new QGraphicsRectItem;//绘制矩形
	QPen pen = rectItem->pen();//画笔 绘制外框
	//pen.setWidth(w);//宽
	pen.setColor(Qt::green);//外边框的颜色
	rectItem->setPen(pen);
	rectItem->setBrush(QBrush(QColor(0, 160, 230)));//填充颜色
	rectItem->setRect(QRectF(x, y, w, h));
	//rectItem->setPos(QPointF(x, -200));//位置
	addItem(rectItem);

	//绘制文字
	QGraphicsTextItem *pItem = new QGraphicsTextItem();
	pItem->setPlainText(QString::number(arr));  // 纯文本
	pItem->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem->setPos(QPointF(x, 350));//位置
	QFont font = pItem->font();
	font.setPixelSize(w / 2);  // 像素大小
	pItem->setFont(font);
	addItem(pItem);

}

void CNodeEditorScene::dataDraw(double x, double  y, double  w, double h, int arr, int flag)
{
	QGraphicsRectItem *rectItem = new QGraphicsRectItem;//绘制矩形
	QPen pen = rectItem->pen();//画笔 绘制外框
	//pen.setWidth(w);//宽
	pen.setColor(Qt::green);//外边框的颜色
	rectItem->setPen(pen);
	if (flag == 1)
	{
		rectItem->setBrush(QBrush(QColor(220, 0, 0)));//填充颜色
	}
	else if (flag == 2)
	{
		rectItem->setBrush(QBrush(QColor(225, 225, 0)));//填充颜色
	}
	else if (flag == 3)
	{
		rectItem->setBrush(QBrush(QColor(255, 102, 51)));//填充颜色
	}
	rectItem->setRect(QRectF(x, y, w, h));
	//rectItem->setPos(QPointF(x, -200));//位置
	addItem(rectItem);

	//绘制文字
	QGraphicsTextItem *pItem = new QGraphicsTextItem();
	pItem->setPlainText(QString::number(arr));  // 纯文本
	pItem->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem->setPos(QPointF(x, 350));//位置
	QFont font = pItem->font();
	font.setPixelSize(w / 2);  // 像素大小
	pItem->setFont(font);
	addItem(pItem);

}
void CNodeEditorScene::headarrowDraw(int num)
{
	arrowLine(200 * cos((62.5 - num * 45)*3.1415 / 180), -200 * sin((62.5 - num * 45)*3.1415 / 180), 250 * cos((62.5 - num * 45)*3.1415 / 180), -250 * sin((62.5 - num * 45)*3.1415 / 180));

	QGraphicsTextItem *pItem = new QGraphicsTextItem();
	pItem->setPlainText(QString::fromLocal8Bit("尾指针"));  // 纯文本
	pItem->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem->setPos(QPointF(280 * cos((62.5 - num * 45)*3.1415 / 180) - 20, -280 * sin((62.5 - num * 45)*3.1415 / 180) - 20));//位置
	QFont font = pItem->font();
	font.setPixelSize(20);  // 像素大小
	pItem->setFont(font);
	addItem(pItem);

}
void CNodeEditorScene::tailarrowDraw(int num)
{
	arrowLine(200 * cos((72.5 - num * 45)*3.1415 / 180), -200 * sin((72.5 - num * 45)*3.1415 / 180), 250 * cos((72.5 - num * 45)*3.1415 / 180), -250 * sin((72.5 - num * 45)*3.1415 / 180));
	QGraphicsTextItem *pItem = new QGraphicsTextItem();
	pItem->setPlainText(QString::fromLocal8Bit("头指针"));  // 纯文本
	pItem->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem->setPos(QPointF(280 * cos((72.5 - num * 45)*3.1415 / 180) - 20, -280 * sin((72.5 - num * 45)*3.1415 / 180) - 20));//位置
	QFont font = pItem->font();
	font.setPixelSize(20);  // 像素大小
	pItem->setFont(font);
	addItem(pItem);
}

void CNodeEditorScene::circleDataDraw(int data, int position)//数字 位置
{
	QGraphicsTextItem *pItem = new QGraphicsTextItem();
	pItem->setPlainText(QString::number(data));  // 纯文本
	pItem->setDefaultTextColor(QColor(0, 0, 0));  // 文本色
	pItem->setPos(QPointF(150 * cos((67.5 - position * 45)*3.1415 / 180) - 20, -150 * sin((67.5 - position * 45)*3.1415 / 180) - 20));//位置
	QFont font = pItem->font();
	font.setPixelSize(40);  // 像素大小
	pItem->setFont(font);
	addItem(pItem);
}

void CNodeEditorScene::arrowLine(double head_x, double head_y, double tail_x, double tail_y)
{
	QGraphicsLineItem *lineItem = new QGraphicsLineItem();
	QPen pen = lineItem->pen();//画笔 绘制外框
	pen.setColor(QColor(100, 149, 237));//外边框的颜色
	pen.setWidth(5);
	lineItem->setPen(pen);
	lineItem->setLine(head_x, head_y, tail_x, tail_y);
	addItem(lineItem);
}

void CNodeEditorScene::circleDraw()
{
	// 定义一个 item
	QGraphicsEllipseItem *pItem2 = new QGraphicsEllipseItem();
	// 设置画笔、画刷
	QPen pen2 = pItem2->pen();
	pen2.setWidth(5);
	pen2.setColor(QColor(135, 206, 235));
	pItem2->setPen(pen2);
	pItem2->setBrush(QBrush(QColor(135, 206, 235)));
	// 矩形区域 起点：(50, 50) 宽：200 高：100
	pItem2->setRect(QRectF(-200, -200, 400, 400));
	pItem2->setStartAngle(0);  // 起始角度
	pItem2->setSpanAngle(5760);// 跨角
	addItem(pItem2);

	// 定义一个 item
	QGraphicsEllipseItem *pItem = new QGraphicsEllipseItem();
	// 设置画笔、画刷
	QPen pen = pItem->pen();
	pen.setWidth(5);
	pen.setColor(QColor(135, 206, 235));
	pItem->setPen(pen);
	pItem->setBrush(QBrush(QColor(255, 255, 255)));
	// 矩形区域 起点：(50, 50) 宽：200 高：100
	pItem->setRect(QRectF(-100, -100, 200, 200));
	pItem->setStartAngle(0);  // 起始角度
	pItem->setSpanAngle(5760);  // 跨角
	addItem(pItem);

	QGraphicsLineItem *lineItem1 = new QGraphicsLineItem();
	QPen pen1 = lineItem1->pen();//画笔 绘制外框
	pen1.setColor(QColor(100, 149, 237));//外边框的颜色
	pen1.setWidth(5);
	lineItem1->setPen(pen1);
	lineItem1->setLine(0, -100, 0, -200);
	addItem(lineItem1);

	QGraphicsLineItem *lineItem2 = new QGraphicsLineItem();
	QPen pen02 = lineItem2->pen();//画笔 绘制外框
	pen02.setColor(QColor(100, 149, 237));//外边框的颜色
	pen02.setWidth(5);
	lineItem2->setPen(pen02);
	lineItem2->setLine(0, 100, 0, 200);
	addItem(lineItem2);

	QGraphicsLineItem *lineItem3 = new QGraphicsLineItem();
	QPen pen3 = lineItem3->pen();//画笔 绘制外框
	pen3.setColor(QColor(100, 149, 237));//外边框的颜色
	pen3.setWidth(5);
	lineItem3->setPen(pen3);
	lineItem3->setLine(100, 0, 200, 0);
	addItem(lineItem3);

	QGraphicsLineItem *lineItem4 = new QGraphicsLineItem();
	QPen pen4 = lineItem4->pen();//画笔 绘制外框
	pen4.setColor(QColor(100, 149, 237));//外边框的颜色
	pen4.setWidth(5);
	lineItem4->setPen(pen4);
	lineItem4->setLine(-100, 0, -200, 0);
	addItem(lineItem4);

	QGraphicsLineItem *lineItem5 = new QGraphicsLineItem();
	QPen pen5 = lineItem5->pen();//画笔 绘制外框
	pen5.setColor(QColor(100, 149, 237));//外边框的颜色
	pen5.setWidth(5);
	lineItem5->setPen(pen5);
	lineItem5->setLine(70.710678, 70.710678, 141.42135, 141.42135);
	addItem(lineItem5);

	QGraphicsLineItem *lineItem6 = new QGraphicsLineItem();
	QPen pen6 = lineItem6->pen();//画笔 绘制外框
	pen6.setColor(QColor(100, 149, 237));//外边框的颜色
	pen6.setWidth(5);
	lineItem6->setPen(pen6);
	lineItem6->setLine(-70.710678, -70.710678, -141.42135, -141.42135);
	addItem(lineItem6);

	QGraphicsLineItem *lineItem7 = new QGraphicsLineItem();
	QPen pen7 = lineItem7->pen();//画笔 绘制外框
	pen7.setColor(QColor(100, 149, 237));//外边框的颜色
	pen7.setWidth(5);
	lineItem7->setPen(pen7);
	lineItem7->setLine(70.710678, -70.710678, 141.42135, -141.42135);
	addItem(lineItem7);

	QGraphicsLineItem *lineItem8 = new QGraphicsLineItem();
	QPen pen8 = lineItem8->pen();//画笔 绘制外框
	pen8.setColor(QColor(100, 149, 237));//外边框的颜色
	pen8.setWidth(5);
	lineItem8->setPen(pen8);
	lineItem8->setLine(-70.710678, 70.710678, -141.42135, 141.42135);
	addItem(lineItem8);


	QGraphicsTextItem *pItem1 = new QGraphicsTextItem();
	pItem1->setPlainText(QString::number(0));  // 纯文本
	pItem1->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem1->setPos(QPointF(80 * cos(67.5*3.1415 / 180) - 10, -80 * sin(67.5*3.1415 / 180) - 10));//位置
	QFont font1 = pItem1->font();
	font1.setPixelSize(20);  // 像素大小
	pItem1->setFont(font1);
	addItem(pItem1);
	QGraphicsTextItem *pItem02 = new QGraphicsTextItem();
	pItem02->setPlainText(QString::number(1));  // 纯文本
	pItem02->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem02->setPos(QPointF(80 * cos(22.5*3.1415 / 180) - 10, -80 * sin(22.5*3.1415 / 180) - 10));//位置
	QFont font2 = pItem1->font();
	font2.setPixelSize(20);  // 像素大小
	pItem02->setFont(font2);
	addItem(pItem02);

	QGraphicsTextItem *pItem3 = new QGraphicsTextItem();
	pItem3->setPlainText(QString::number(2));  // 纯文本
	pItem3->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem3->setPos(QPointF(80 * cos(-22.5*3.1415 / 180) - 10, -80 * sin(-22.5*3.1415 / 180) - 10));//位置
	QFont font3 = pItem3->font();
	font3.setPixelSize(20);  // 像素大小
	pItem3->setFont(font3);
	addItem(pItem3);
	QGraphicsTextItem *pItem4 = new QGraphicsTextItem();
	pItem4->setPlainText(QString::number(3));  // 纯文本
	pItem4->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem4->setPos(QPointF(80 * cos(-67.5*3.1415 / 180) - 10, -80 * sin(-67.5*3.1415 / 180) - 10));//位置
	QFont font4 = pItem4->font();
	font4.setPixelSize(20);  // 像素大小
	pItem4->setFont(font4);
	addItem(pItem4);
	QGraphicsTextItem *pItem5 = new QGraphicsTextItem();
	pItem5->setPlainText(QString::number(4));  // 纯文本
	pItem5->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem5->setPos(QPointF(80 * cos(-112.5*3.1415 / 180) - 10, -80 * sin(-112.5*3.1415 / 180) - 10));//位置
	QFont font5 = pItem5->font();
	font5.setPixelSize(20);  // 像素大小
	pItem5->setFont(font5);
	addItem(pItem5);
	QGraphicsTextItem *pItem6 = new QGraphicsTextItem();
	pItem6->setPlainText(QString::number(5));  // 纯文本
	pItem6->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem6->setPos(QPointF(80 * cos(-157.5*3.1415 / 180) - 10, -80 * sin(-157.5*3.1415 / 180) - 10));//位置
	QFont font6 = pItem6->font();
	font6.setPixelSize(20);  // 像素大小
	pItem6->setFont(font6);
	addItem(pItem6);
	QGraphicsTextItem *pItem7 = new QGraphicsTextItem();
	pItem7->setPlainText(QString::number(6));  // 纯文本
	pItem7->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem7->setPos(QPointF(80 * cos(157.5*3.1415 / 180) - 10, -80 * sin(157.5*3.1415 / 180) - 10));//位置
	QFont font7 = pItem7->font();
	font7.setPixelSize(20);  // 像素大小
	pItem7->setFont(font7);
	addItem(pItem7);
	QGraphicsTextItem *pItem8 = new QGraphicsTextItem();
	pItem8->setPlainText(QString::number(7));  // 纯文本
	pItem8->setDefaultTextColor(QColor(0, 160, 230));  // 文本色
	pItem8->setPos(QPointF(80 * cos(112.5*3.1415 / 180) - 10, -80 * sin(112.5*3.1415 / 180) - 10));//位置
	QFont font8 = pItem8->font();
	font8.setPixelSize(20);  // 像素大小
	pItem8->setFont(font8);
	addItem(pItem8);
}




//
//////重建重复数据函数
//void CNodeEditorScene::dataReset(int currentIndex, int count)  //排序方案号，随机数个数
//{
//
//
//	QGraphicsRectItem *rectItem = new QGraphicsRectItem;//绘制矩形
//	QPen pen2 = rectItem->pen();//画笔 绘制外框
//	pen2.setWidth(2);
//	pen2.setColor(Qt::green);//外边框的颜色
//	rectItem->setPen(pen2);
//	rectItem->setBrush(QBrush(QColor(0, 160, 230)));//填充颜色
//	rectItem->setRect(QRectF(0, 0, 20, 100));
//	QTimeLine *timer = new QTimeLine(500);//时间线
//	timer->setFrameRange(0, 100);//移动帧数
//	QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;//动画
//	animation->setItem(rectItem);//加入小球
//	animation->setTimeLine(timer);//加入时间线
//
//	for (int i = 0; i <= 200; ++i)//循环设置位置
//		animation->setPosAt(i / 200.0, QPointF(i,0));
//	addItem(rectItem);
//	timer->start();
//
//	qDebug()<<"  "<<endl;
//
//
//	QGraphicsRectItem *rectItem2 = new QGraphicsRectItem;//绘制矩形
//	QPen pen3 = rectItem2->pen();//画笔 绘制外框
//	pen3.setWidth(2);
//	pen3.setColor(Qt::green);//外边框的颜色
//	rectItem2->setPen(pen3);
//	rectItem2->setBrush(QBrush(QColor(0, 160, 230)));//填充颜色
//	rectItem2->setRect(QRectF(0, 0, 20, 100));
//	rectItem2->setFlags(QGraphicsItem::ItemIsSelectable);
//	rectItem2->setPos(QPointF(200, 200));
//	addItem(rectItem2);
//

	//SortObejct *obj = SortCreator::createSortObject(currentIndex, this);

	////重置数据，目前sortobj是一次性的
	//if (_sortObj) {
	//	_sortObj->deleteLater();
	//	_sortObj = nullptr;
	//}
	//_sortObj = obj;
	//if (_sortObj) {
	//	connect(_sortObj, &SortObejct::sortUpdated, this, [this] {
	//		update();
	//	});
	//	connect(_sortObj, &SortObejct::sortFinished, this, [this] {
	//		update();
	//		emit finished();
	//	});
	//	_sortObj->dataReset(count);
	//}
	//update();//填充好数据刷新
	//}

////重建开始排序函数
void  CNodeEditorScene::startSort(int interval)
{
	QRectF Rect(-1000, -1000, 2000, 2000);//删除-1000 -1000 1000 1000 方块内的所有图形
	QList<QGraphicsItem *> itemList = items(Rect);
	for (auto i = 0; i < itemList.size(); i++) {
		removeItem(itemList[i]);
		delete itemList[i];
	}
}


