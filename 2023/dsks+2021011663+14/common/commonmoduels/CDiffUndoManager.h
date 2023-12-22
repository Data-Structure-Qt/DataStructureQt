/*






*/

#pragma once

#include "IUndoManager.h"

#include <QtCore/QByteArray>
#include <QtCore/QList>

class CEditorScene;


class CDiffUndoManager : public IUndoManager
{
public:
	CDiffUndoManager(CEditorScene &scene);

	// reimp
	virtual void reset();
	virtual void addState();
	virtual void revertState();
	virtual void undo();
	virtual void redo();
	virtual int availableUndoCount() const;
	virtual int availableRedoCount() const;

private:
	struct Command
	{
		int index;
		int sizeToReplace;
		QByteArray data;
	};

	CEditorScene *m_scene;
	QList<Command> m_redoStack, m_undoStack;
	QList<Command> m_redoStackTemp, m_undoStackTemp;
	QByteArray m_lastState;
};
