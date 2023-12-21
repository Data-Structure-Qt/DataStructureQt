/*






*/

#include "CEditorScene_p.h"
#include "CEditorScene.h"
#include "CItem.h"


CEditorScene_p::CEditorScene_p(class CEditorScene *scene): 
    m_transformRect(),
    m_scene(scene)
{
	//QObject::connect(&m_labelEditor, &CTextLabelEdit::editingStarted, m_scene, &CEditorScene::onItemEditingStarted);
	QObject::connect(&m_labelEditor, &CTextLabelEdit::editingFinished, m_scene, &CEditorScene::onItemEditingFinished);
}
