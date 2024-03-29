/*






*/

#pragma once

#include <QGraphicsTextItem> 

class CItem;
class CEditorScene;


class CTextLabelEdit: public QGraphicsTextItem
{
	Q_OBJECT

public:
	CTextLabelEdit();
	~CTextLabelEdit();

	void startEdit(CItem *item);
	void settext(CItem *item,int data);
	void setsearchtext(CItem *item, int data);
	void finishEdit(bool accept = true);

	virtual bool onKeyPressed(CEditorScene& scene, QKeyEvent *keyEvent);
	virtual bool onKeyReleased(CEditorScene& scene, QKeyEvent *keyEvent);

Q_SIGNALS:
	void editingStarted(CItem *item);
	void editingFinished(CItem *item, bool cancelled);

protected:
	virtual bool sceneEvent(QEvent *event);

private Q_SLOT:
	void updateGeometry();

private:
	CItem *m_item = nullptr;
	QString m_storedText;
};

