/*






*/

#pragma once

#include "CEditorSceneActions.h"

class CNodeEditorScene;
class CNode;
class CEdge;


class CNodeSceneActions : public CEditorSceneActions
{
	Q_OBJECT

public:
	CNodeSceneActions(CNodeEditorScene *scene);

public Q_SLOTS:
	bool editNodeId(CNode* node);
	bool editEdgeId(CEdge* edge);

	void onActionNodeColor();
	void onActionLink();
    void onActionUnlink();
    void onActionDFS();
    void onActionBFS();

	void onActionEdgeColor();
	void onActionEdgeReverse();
	void onActionEdgeDirected();
	void onActionEdgeMutual();
	void onActionEdgeUndirected();

private:
	CNodeEditorScene &nodeScene;
};

