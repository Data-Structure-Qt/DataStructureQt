/*






*/


#include "CTextLabelEdit.h"
#include "CItem.h"

#include <QTextCursor>
#include <QTextDocument>
#include <QKeyEvent>


CTextLabelEdit::CTextLabelEdit()
{
	setTextInteractionFlags(Qt::TextEditorInteraction);

	connect(document(), &QTextDocument::contentsChanged, this, &CTextLabelEdit::updateGeometry);
}

CTextLabelEdit::~CTextLabelEdit()
{
}


void CTextLabelEdit::updateGeometry()
{
	if (m_item)
	{
		QPointF center = m_item->getLabelCenter();
		double w = boundingRect().width();
		double h = boundingRect().height();
		setPos(center.x() - w/2, center.y() - h/2);
	}
}


bool CTextLabelEdit::onKeyPressed(CEditorScene& scene, QKeyEvent *keyEvent)
{
	return QGraphicsTextItem::sceneEvent(keyEvent);
}


bool CTextLabelEdit::onKeyReleased(CEditorScene& scene, QKeyEvent *keyEvent)
{
	if (keyEvent->matches(QKeySequence::Cancel))				// Esc
	{
		finishEdit(true);
		return true;
	}

	return QGraphicsTextItem::sceneEvent(keyEvent);
}


bool CTextLabelEdit::sceneEvent(QEvent *event)
{
	if (event->type() == QEvent::FocusOut)
	{
		finishEdit(true);
		return true;
	}

	return QGraphicsTextItem::sceneEvent(event);
}


void CTextLabelEdit::startEdit(CItem *item)
{
	m_item = item;

	if (m_item == nullptr)
		return;

	auto scene = m_item->getScene();
	if (scene == nullptr)
		return;

	scene->selectItem(m_item);

	m_storedText = m_item->getAttribute("label").toString();
	m_item->showLabel(false);

	setPlainText(m_storedText);
	setFont(m_item->getAttribute("label.font").value<QFont>());
	setDefaultTextColor(m_item->getAttribute("label.color").value<QColor>());

	updateGeometry();

	QTextCursor c = textCursor();
	c.select(QTextCursor::Document);
	setTextCursor(c);
	
	setFocus();

	scene->addItem(this);
	show();

	Q_EMIT editingStarted(m_item);
}


void CTextLabelEdit::finishEdit(bool accept)
{
	if (m_item == nullptr)
		return;

	Q_EMIT editingFinished(m_item, !accept);

	auto scene = m_item->getScene();
	if (scene == nullptr)
		return;

	QString text = toPlainText();
	QString show = "11111";
	if (accept && m_storedText != text)
	{
		m_item->setAttribute("label", show);
		scene->addUndoState();
	}

	m_item->showLabel(true);

	m_item = nullptr;
	scene->removeItem(this);
}

void CTextLabelEdit::settext(CItem *item, QVariant data)
{
	m_item = item;
	auto scene = m_item->getScene();
	m_item->setAttribute("label", data);
	scene->addUndoState();
	m_item->showLabel(true);
	m_item = nullptr;
	scene->removeItem(this);
}
void CTextLabelEdit::setsearchtext(CItem *item, int data)
{
	m_item = item;
	auto scene = m_item->getScene();
	m_item->setAttribute("label", data);
	scene->addUndoState();
	m_item->showLabel(true);
	m_item = nullptr;
	scene->removeItem(this);
}
