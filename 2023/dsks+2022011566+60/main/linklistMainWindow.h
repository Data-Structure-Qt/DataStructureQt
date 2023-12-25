#pragma once
#ifndef paintMainWindow_H 
#define paintMainWindow_H 

#include <QPlainTextEdit> 
#include <QStatusBar> 

#include <CMainWindow.h> 

class CNodeEditorUIController;

class linklistMainWindow : public CMainWindow
{
	Q_OBJECT

public:
	typedef CMainWindow Super;

	friend class CNodeEditorUIController;

	linklistMainWindow(QWidget* parent = nullptr);
	virtual ~linklistMainWindow();

	virtual void init(const QStringList& args);

	virtual QSettings& getApplicationSettings() const;

protected:
	virtual bool createDocument(const QByteArray& docType);
	virtual void destroyDocument();
	virtual void onNewDocumentCreated(const QByteArray& docType);
	virtual bool openDocument(const QString& fileName, QByteArray
		& docType);
	virtual bool saveDocument(const QString& fileName, const QString
		& selectedFilter, const QByteArray& docType);
	virtual QString getAboutText() const;

	virtual void doReadSettings(QSettings& settings);
	virtual void doWriteSettings(QSettings& settings);

private:
	void updateFileAssociations();

	CNodeEditorUIController* m_graphEditController = nullptr;

	QPlainTextEdit* m_textEditor = nullptr;

	bool m_portable = false;
};

#endif // paintMainWindow_H 
