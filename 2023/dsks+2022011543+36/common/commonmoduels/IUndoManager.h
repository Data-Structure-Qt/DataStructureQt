/*






*/

#pragma once


class IUndoManager
{
public:
	virtual void reset() = 0;
	virtual void addState() = 0;
	virtual void revertState() = 0;
	virtual void undo() = 0;
	virtual void redo() = 0;
	virtual int availableUndoCount() const = 0;
	virtual int availableRedoCount() const = 0;
};
