/*






*/

#pragma once

#include <QtXml/QDomDocument>
#include <QMap>
#include <QByteArray>
#include <QVariant>
#include <QXmlStreamWriter>

#include <baseio/CGraphBase.h>


class CFormatGraphML
{
public:
	bool load(const QString& fileName, Graph& graph, QString* lastError = nullptr) const;
	bool save(const QString& fileName, Graph& graph, QString* lastError = nullptr) const;

private:
	typedef QMap<QByteArray, QByteArray> KeyAttrMap;		// key:attrId
	typedef QMap<QByteArray, KeyAttrMap> ClassKeyAttrMap;	// class <> (key:attrId)

	bool readAttrKey(int index, const QDomNode &domNode, Graph& graph, ClassKeyAttrMap& cka) const;
	bool readNode(int index, const QDomNode &domNode, Graph& graph, const KeyAttrMap& nodeKeys) const;
	bool readEdge(int index, const QDomNode &domNode, Graph& graph, const KeyAttrMap& edgeKeys) const;

	void writeAttributes(QXmlStreamWriter &xsw, const AttributeInfos &attrs, const QByteArray &classId) const;
	void writeAttribute(QXmlStreamWriter &xsw, const QString &keyId, const QVariant &value) const;
	void writeNodes(QXmlStreamWriter &xsw, const Graph& graph) const;
	void writeEdges(QXmlStreamWriter &xsw, const Graph& graph) const;

	enum EdgeType {
		Directed,
		Undirected,
		Mutual
	};
	mutable QString m_edgeType;
};



