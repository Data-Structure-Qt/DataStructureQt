/*






*/

#pragma once

#include <QtCore/QSettings>

#include "base/IFileSerializer.h"


class CNode;

class CFileSerializerXGR : public IFileSerializer
{
public:
	// reimp
	virtual QString description() const {
		return "base graph scene format";
	}

	virtual QString filters() const {
		return "*.xgr";
	}

	virtual QString defaultFileExtension() const {
		return "xgr";
	}

	virtual bool loadSupported() const {
		return true;
	}

	virtual bool load(const QString& fileName, CEditorScene& scene, QString* lastError = nullptr) const;

	virtual bool saveSupported() const {
		return true;
	}

	virtual bool save(const QString& fileName, CEditorScene& scene, QString* lastError = nullptr) const;
};

