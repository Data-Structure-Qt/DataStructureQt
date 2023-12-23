/*






*/

#ifndef CSIMPLEUNDOMANAGER_H
#define CSIMPLEUNDOMANAGER_H

#include "IUndoManager.h"

#include <QtCore/QByteArray>
#include <QtCore/QList>

class CEditorScene;


class CSimpleUndoManager : public IUndoManager
{
public:
	CSimpleUndoManager(CEditorScene &scene);

	// reimp
	virtual void reset();
	virtual void addState();
	virtual void revertState();
	virtual void undo();
	virtual void redo();
	virtual int availableUndoCount() const;
	virtual int availableRedoCount() const;

private:
	CEditorScene *m_scene;
	QList<QByteArray> m_stateStack;
	int m_stackIndex;
};

#endif // CUNDOMANAGER_H
