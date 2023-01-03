/*






*/

#include "CFileSerializerPlainDOT.h"
#include "CAttribute.h"
#include "CNode.h"
#include "CDirectEdge.h"

#include <baseio/CFormatPlainDOT.h>

#include <QFile>
#include <QDebug>


// reimp

bool CFileSerializerPlainDOT::load(const QString& fileName, CEditorScene& scene, QString* lastError) const
{
	CFormatPlainDOT graphFormat;
	Graph graphModel;

	if (graphFormat.load(fileName, graphModel, lastError))
		return scene.fromGraph(graphModel);
	else
		return false;
}


bool CFileSerializerPlainDOT::save(const QString& fileName, CEditorScene& scene, QString* lastError) const
{
	CFormatPlainDOT graphFormat;
	Graph graphModel;

	if (scene.toGraph(graphModel))
		return graphFormat.save(fileName, graphModel, lastError);
	else
		return false;
}

