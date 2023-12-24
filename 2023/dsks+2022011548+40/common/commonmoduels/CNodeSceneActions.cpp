/*






*/

#include <QColorDialog>
#include <QInputDialog>
#include <QMessageBox>
#include "CNodeSceneActions.h"
#include "CNodeEditorScene.h"
#include "CNode.h"
#include "CEdge.h"


CNodeSceneActions::CNodeSceneActions(CNodeEditorScene *scene) : 
	CEditorSceneActions(scene),
	nodeScene(*scene)
{
}


bool CNodeSceneActions::editNodeId(CNode* editNode)
{
	if (editNode == nullptr)
		return false;
	QString id = editNode->getId();
	QString editId = id;
_again:
	QString newId = QInputDialog::getText(0,
		QStringLiteral("编号"),
		QStringLiteral("填写节点编号:"),
		QLineEdit::Normal,editId);
	if (newId.isEmpty() || newId == id)
		return false;
	auto items = nodeScene.getItemsById(newId);
	for (auto item : items) {
		CNode* node = dynamic_cast<CNode*>(item);
		if (node == NULL || node == editNode)
			continue;
		if (node->getId() == newId) {
			int count = 0;
			QString nextFreeId = newId + QString::number(count++);
			while (nodeScene.getItemsById(nextFreeId).count()) {
				nextFreeId = newId + QString::number(count++);
			}
			QString autoId = QString(QStringLiteral("建议修改为: %1").arg(nextFreeId));
			int r = QMessageBox::warning(0,
				QStringLiteral("警告：该编号正在使用中"),
				QStringLiteral("编号 %1 已被另一个节点使用").arg(newId),
				autoId,
				QStringLiteral("交换节点编号"),
				QStringLiteral("继续编辑"), 0, 2);
			if (r == 2) {
				editId = newId;
				goto _again;
			}
			if (r == 1) {
				editNode->setId(newId);
				node->setId(id);
				nodeScene.addUndoState();
				return true;
			}
			// r = 0
			editId = nextFreeId;
			goto _again;
		}
	}
	editNode->setId(newId);
	nodeScene.addUndoState();
	return true;
}


void CNodeSceneActions::onActionNodeColor()
{
	auto nodes = nodeScene.getSelectedNodes();
	if (nodes.isEmpty())
		return;

	QColor color = QColorDialog::getColor(nodes.first()->getAttribute("color").value<QColor>());
	if (!color.isValid())
		return;

	for (auto node : nodes)
	{
		node->setAttribute("color", color);
	}

	nodeScene.addUndoState();
}


void CNodeSceneActions::onActionLink()
{
	auto nodes = nodeScene.getSelectedNodes();
	if (nodes.count() < 2)
		return;

	auto baseNode = nodes.takeFirst();
	for (auto node : nodes)
	{
		baseNode->merge(node);
	}

	nodeScene.addUndoState();
}



void CNodeSceneActions::onActionUnlink()
{
	auto nodes = nodeScene.getSelectedNodes();
	if (nodes.isEmpty())
		return;

	for (auto node : nodes)
	{
		node->unlink();
	}

	nodeScene.addUndoState();
}


bool CNodeSceneActions::editEdgeId(CEdge* editEdge)
{
	if (editEdge == nullptr)
		return false;
	QString id = editEdge->getId();
	QString editId = id;
_again:
	QString newId = QInputDialog::getText(0,
		QStringLiteral("边权值"),
		QStringLiteral("边权值修改为:"),
		QLineEdit::Normal,
		editId);
	if (newId.isEmpty() || newId == id)
		return false;
	auto items = nodeScene.getItemsById(newId);
	
	editEdge->setId(newId);
	nodeScene.addUndoState();
	return true;
}


void CNodeSceneActions::onActionEdgeColor()
{
	auto edges = nodeScene.getSelectedEdges();
	if (edges.isEmpty())
		return;

	QColor color = QColorDialog::getColor(edges.first()->getAttribute("color").value<QColor>());
	if (!color.isValid())
		return;

	for (auto edge : edges)
	{
		edge->setAttribute("color", color);
	}

	nodeScene.addUndoState();
}


void CNodeSceneActions::onActionEdgeReverse()
{
	auto edges = nodeScene.getSelectedEdges();
	if (edges.isEmpty())
		return;

	for (auto edge : edges)
	{
		edge->reverse();
	}

	nodeScene.addUndoState();
}


void CNodeSceneActions::onActionEdgeDirected()
{
	auto edges = nodeScene.getSelectedEdges();
	if (edges.isEmpty())
		return;

	for (auto edge : edges)
	{
		edge->update();
	}

	nodeScene.addUndoState();
}


void CNodeSceneActions::onActionEdgeMutual()
{
	auto edges = nodeScene.getSelectedEdges();
	if (edges.isEmpty())
		return;
	nodeScene.addUndoState();
}


void CNodeSceneActions::onActionEdgeUndirected()
{
	auto edges = nodeScene.getSelectedEdges();
	if (edges.isEmpty())
		return;

	for (auto edge : edges)
	{
		edge->update();
	}

	nodeScene.addUndoState();
}

