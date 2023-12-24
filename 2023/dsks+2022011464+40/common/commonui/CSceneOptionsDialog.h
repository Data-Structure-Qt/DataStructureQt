

#ifndef CSCENEOPTIONSDIALOG_H
#define CSCENEOPTIONSDIALOG_H

#include <QDialog>

#include <CEditorScene.h>
#include <CEditorView.h>


namespace Ui {
class CSceneOptionsDialog;
}


struct OptionsData
{
	int backupPeriod = 10;

	QString graphvizPath;
	//QStringList graphvizEngines;
	QString graphvizDefaultEngine;
};


class CSceneOptionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CSceneOptionsDialog(QWidget *parent = 0);
    ~CSceneOptionsDialog();

public Q_SLOTS:
	virtual int exec(CEditorScene &scene, CEditorView &view, OptionsData &data);

Q_SIGNALS:
	void testGraphviz(const QString &graphvizPath);

private Q_SLOTS:
	void on_GraphvizTest_clicked();

private:
    Ui::CSceneOptionsDialog *ui;
};

#endif // CSCENEOPTIONSDIALOG_H
