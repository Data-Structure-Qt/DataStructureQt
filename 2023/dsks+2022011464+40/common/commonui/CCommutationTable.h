/*






*/

#ifndef CCommutationTable_H
#define CCommutationTable_H

#include <QWidget>
#include <QMap>
#include <QList>
#include <QSettings>

class CEditorScene;
class CNodeEditorScene;
struct CAttribute;
class CEdge;

#include "ui_CCommutationTable.h"


class CCommutationTable : public QWidget
{
	Q_OBJECT

public:
	CCommutationTable(QWidget *parent = 0);
	~CCommutationTable();

	void setScene(CNodeEditorScene* scene);

	void doReadSettings(QSettings& settings);
	void doWriteSettings(QSettings& settings);

protected:
	void connectSignals(CEditorScene* scene);
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);

protected Q_SLOTS:
	void onSceneChanged();
	void onSelectionChanged();
	void on_Table_itemSelectionChanged();
	void on_Table_itemDoubleClicked(QTreeWidgetItem *item, int column);
	void onCustomContextMenu(const QPoint &);
	void onAddSection();
	void onRemoveSection();
	void on_AddColumnButton_clicked();
	void on_RestoreButton_clicked();

private slots:
    //void on_CCommutationTable_windowIconChanged(const QIcon &icon);
    
private:
	Ui::CCommutationTable ui;

	CNodeEditorScene *m_scene;

	QMap<CEdge*, QTreeWidgetItem*> m_edgeItemMap;
	
	QByteArrayList m_extraSectionIds;
};

#endif // CCommutationTable_H
