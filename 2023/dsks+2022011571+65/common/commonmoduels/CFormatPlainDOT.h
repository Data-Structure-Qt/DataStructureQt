/*



(c) 2016-2021 Ars L. Masiuk (ars.masiuk@gmail.com)


*/

#pragma once

#include <commonmoduels/CGraphBase.h>


class CFormatPlainDOT
{
public:
	bool load(const QString& fileName, Graph& graph, QString* lastError = nullptr) const;
	bool save(const QString& fileName, Graph& graph, QString* lastError = nullptr) const;

private:
	struct GraphInternal
	{
		float g_scale = 1.0;
		float g_x = 1.0;
		float g_y = 1.0;

		Graph* g = nullptr;
	};

	bool parseGraph(const QStringList& refs, GraphInternal &gi) const;
	bool parseNode(const QStringList& refs, GraphInternal &gi) const;
	bool parseEdge(const QStringList& refs, GraphInternal &gi) const;
};



