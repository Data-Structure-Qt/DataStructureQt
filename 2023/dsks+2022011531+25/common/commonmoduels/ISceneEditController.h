/*






*/

#pragma once

class CEditorScene;

class QGraphicsSceneMouseEvent;
class QPainter;
class QRectF;
class QGraphicsItem;
class QKeyEvent;


class ISceneEditController
{
public:
	virtual void onActivated(CEditorScene& scene) = 0;
	virtual void onDeactivated(CEditorScene& scene) = 0;

	virtual void onSceneChanged(CEditorScene& scene) = 0;
	virtual void onSelectionChanged(CEditorScene& scene) = 0;
	virtual void onDragItem(CEditorScene& scene, QGraphicsSceneMouseEvent *mouseEvent, QGraphicsItem* dragItem) = 0;

	virtual bool onMousePressed(CEditorScene& scene, QGraphicsSceneMouseEvent *mouseEvent) = 0;
	virtual bool onMouseMove(CEditorScene& scene, QGraphicsSceneMouseEvent *mouseEvent) = 0;
	virtual bool onMouseReleased(CEditorScene& scene, QGraphicsSceneMouseEvent *mouseEvent) = 0;

	virtual bool onKeyPressed(CEditorScene& scene, QKeyEvent *keyEvent) { return false; }
	virtual bool onKeyReleased(CEditorScene& scene, QKeyEvent *keyEvent) { return false; }

	virtual void draw(CEditorScene& scene, QPainter *painter, const QRectF &r) = 0;
};
