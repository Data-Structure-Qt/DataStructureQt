#pragma once

/*






*/

#include <QDialog>
#include <QSettings>


namespace Ui {
	class CImageExportDialog;
}

class CEditorScene;


class CImageExportDialog : public QDialog
{
	Q_OBJECT

public:
	CImageExportDialog(QWidget *parent = 0);
	~CImageExportDialog();

	void doReadSettings(QSettings& settings);
	void doWriteSettings(QSettings& settings);

	void setScene(CEditorScene& scene);

	bool cutToContent() const;
	int resolution() const;

private Q_SLOTS:
	void updateTargetSize();

private:
	Ui::CImageExportDialog *ui;

	CEditorScene *m_scene = nullptr;
	int m_dpi = 96;
};

