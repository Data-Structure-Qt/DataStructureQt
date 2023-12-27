/*






*/

#pragma once

#include <QtCore/QByteArray>

class CItem;
class CEditorScene;


/**
	Common interface to scene item creation filters.
*/
class ISceneItemFactory
{
public:
	virtual CItem* createItemOfType(const QByteArray& typeId, const CEditorScene& scene) const = 0;
};
