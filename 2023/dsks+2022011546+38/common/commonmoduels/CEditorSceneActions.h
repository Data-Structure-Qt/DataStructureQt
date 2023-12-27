

#pragma once

#include <QAction>


class CEditorScene;


class CEditorSceneActions: public QObject
{
public:
	CEditorSceneActions(CEditorScene *scene);

	QAction *cutAction;
	QAction *copyAction;
	QAction *pasteAction;
	QAction *delAction;
};

