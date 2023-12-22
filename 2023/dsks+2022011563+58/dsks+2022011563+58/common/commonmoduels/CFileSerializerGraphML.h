/*






*/

#pragma once

#include "IFileSerializer.h"


class CFileSerializerGraphML : public IFileSerializer
{
public:

	// reimp
	virtual QString description() const {
		return "GraphML Format";
	}

	virtual QString filters() const {
		return "*.graphml";
	}

	virtual QString defaultFileExtension() const {
		return "graphml";
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



