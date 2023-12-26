/*






*/

#include "CGraphBase.h"


void Graph::clear()
{
	attrs.clear();
	nodes.clear();
	edges.clear();

	nodeAttrs.clear();
	edgeAttrs.clear();
	graphAttrs.clear();
}


int Graph::findNodeIndex(const QString &id) const
{
	QByteArray bid = id.toUtf8();

	for (int i = 0; i < nodes.count(); ++i)
		if (nodes.at(i).id == bid)
			return i;

	return -1;
}
