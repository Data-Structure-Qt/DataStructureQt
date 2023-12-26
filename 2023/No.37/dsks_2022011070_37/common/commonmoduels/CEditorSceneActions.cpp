
#include <QIcon>
#include <QKeySequence>

#include "CEditorSceneActions.h"
#include "CEditorScene.h"
#include "CNode.h"
#include "CEdge.h"


CEditorSceneActions::CEditorSceneActions(CEditorScene *scene)
{
	cutAction = new QAction(QIcon(":/Icons/Cut"),
		QString::fromLocal8Bit(" 剪切"), scene);
	cutAction->setStatusTip(
		QString::fromLocal8Bit(" 将所选项目剪切到剪贴板"));
	cutAction->setToolTip(QString::fromLocal8Bit(" 剪切已选项目"));
	cutAction->setShortcut(QKeySequence::Cut);
	connect(cutAction, &QAction::triggered, scene, &CEditorScene::cut);
	copyAction = new QAction(QIcon(":/Icons/Copy"),
		QString::fromLocal8Bit(" 复制"), scene);
	copyAction->setStatusTip(
		QString::fromLocal8Bit(" 将所选项目复制到剪贴板"));
	copyAction->setToolTip(QString::fromLocal8Bit(" 复制已选项"));
	copyAction->setShortcut(QKeySequence::Copy);
	connect(copyAction, &QAction::triggered, scene, &CEditorScene::copy);
	pasteAction = new QAction(QIcon(":/Icons/Paste"),
		QString::fromLocal8Bit(" 粘贴"), scene);
	pasteAction->setStatusTip(QString::fromLocal8Bit(" 从剪贴板粘贴项目"));
	pasteAction->setToolTip(QString::fromLocal8Bit(" 从剪切板粘贴"));
	pasteAction->setShortcut(QKeySequence::Paste);
	connect(pasteAction, &QAction::triggered, scene, &CEditorScene::paste);
	delAction = new QAction(QIcon(":/Icons/Delete"), QString::fromLocal8Bit(" 删除"), scene);
	delAction->setStatusTip(QString::fromLocal8Bit(" 删除所选项目"));
	delAction->setToolTip(QString::fromLocal8Bit(" 删除所选内容"));
	delAction->setShortcut(QKeySequence::Delete);
	QObject::connect(delAction, &QAction::triggered, scene, &CEditorScene::del);
}
