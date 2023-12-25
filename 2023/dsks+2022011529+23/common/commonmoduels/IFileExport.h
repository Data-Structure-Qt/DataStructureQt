/*






*/

#pragma once

#include <QtCore/QString>

class CEditorScene;


/**
	Common interface to file exporters.
*/
class IFileExport
{
public:
	virtual bool save(const QString& fileName, const CEditorScene& scene) const = 0;
};
