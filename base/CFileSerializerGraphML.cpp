/*






*/

#include "CFileSerializerGraphML.h"
#include "CAttribute.h"
#include "CNode.h"
#include "CDirectEdge.h"

#include <baseio/CFormatGraphML.h>

#include <QFile>
#include <QDebug>


// reimp

bool CFileSerializerGraphML::load(const QString& fileName, CEditorScene& scene, QString* lastError) const
{
	CFormatGraphML graphML;
	Graph graphModel;

	if (graphML.load(fileName, graphModel, lastError))
		return scene.fromGraph(graphModel);
	else
		return false;
}


bool CFileSerializerGraphML::save(const QString& fileName, CEditorScene& scene, QString* lastError) const
{
	CFormatGraphML graphML;
	Graph graphModel;

	if (scene.toGraph(graphModel))
		return graphML.save(fileName, graphModel, lastError);
	else
		return false;
}

