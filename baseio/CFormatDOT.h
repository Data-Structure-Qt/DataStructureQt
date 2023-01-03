/*






*/

#pragma once

#include <baseio/CGraphBase.h>


class CFormatDOT
{
public:
	bool load(const QString& fileName, Graph& graph, QString* lastError = nullptr) const;
	bool save(const QString& fileName, Graph& graph, QString* lastError = nullptr) const;
};



