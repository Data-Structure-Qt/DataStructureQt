/*






*/

#include "CGraphBase.h"
#include <qDebug>

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
	qDebug() << "nodes.count()" << nodes.count();
	for (int i = 0; i < nodes.count(); ++i)
	{
		qDebug() << "nodes.at(i).id"<< nodes.at(i).id;
		qDebug() << "bid" << bid;

		if (nodes.at(i).id == bid)
		{
			return i;
		}
	}

	return -1;
}
