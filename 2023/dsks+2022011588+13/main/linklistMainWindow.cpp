#include "linklistMainWindow.h" 
#include "linklistVersion.h" 
#include <QFile> 
#include <QDir> 
#include <QTextStream> 
#include <QApplication> 
#include <QFileInfo> 
#include <QMessageBox> 
#include <QSettings> 
#include <QDebug> 
#include <CPlatformServices.h> 
#include <CNodeEditorUIController.h> 
linklistMainWindow::linklistMainWindow(QWidget* parent) :
	Super(parent)
{
	QString bitString;
	int bits = CPlatformServices::GetPlatformBits();
	if (bits > 0) bitString = QString("%1bit").arg(bits);
	QApplication::setOrganizationName("base");
	QApplication::setApplicationName(QString::fromLocal8Bit("»­°å")); 
	QApplication::setApplicationVersion(linklistVersionString);
	CDocumentFormat xgr = { "XGR binary graph format", "*.xgr", { "xgr" },true, true };
	CDocumentFormat gexf = { "GEXF", "*.gexf", {"gexf"}, true, true };
	CDocumentFormat graphml =
	{ "GraphML", "*.graphml", { "graphml" }, true, true };
	CDocumentFormat gml = { "GML", "*.gml", { "gml" }, false, true };
	CDocumentFormat csv = { "CSV text file", "*.csv", { "csv" }, false, true };
	CDocumentFormat dot = { "DOT/GraphViz", "*.dot *.gv",
   { "dot", "gv" }, true, true };
	CDocumentFormat dotplain =
	{ "Plain DOT/GraphViz", "*.plain *.txt", { "plain", "txt" }, false, true };
	CDocument graph =
	{ tr("Graph Document"), tr("Directed or undirected graph"), "graph", true,
	 { xgr, gexf, graphml, gml, csv, dot, dotplain } };
	addDocument(graph);
	updateFileAssociations();
}
linklistMainWindow::~linklistMainWindow()
{
	// causes crash here 
	destroyDocument();
}
void linklistMainWindow::init(const QStringList& args)
{
	// check portable start 
	QString localINI = QCoreApplication::applicationDirPath() + "/base.ini";
	m_portable = (QFile::exists(localINI));
	Super::init(args);
	if (m_portable)
		statusBar()->showMessage(tr("base started (portable edition)."));
	else
		statusBar()->showMessage(tr("base started."));
}
QSettings& linklistMainWindow::getApplicationSettings() const
{
	if (m_portable)
	{
		static QString localINI =
			QCoreApplication::applicationDirPath() + "/base.ini";
		static QSettings localSettings(localINI, QSettings::IniFormat);
		return localSettings;
	}
	return CMainWindow::getApplicationSettings();
}
bool linklistMainWindow::createDocument(const QByteArray& docType)
{  // scene 
	if (docType == "graph")
	{
		if (m_graphEditController == nullptr)
		{
			m_graphEditController = new CNodeEditorUIController(this);
			m_graphEditController->doReadSettings(getApplicationSettings());
		}
		return true;
	}
	// text 
	if (docType == "text")
	{
		if (m_textEditor == nullptr)
		{
			m_textEditor = new QPlainTextEdit(this);
			setCentralWidget(m_textEditor);
			connect(m_textEditor, &QPlainTextEdit::textChanged,
				this, &CMainWindow::onDocumentChanged);
		}
		return true;
	}
	// unknown type 
	return false;
}
void linklistMainWindow::destroyDocument()
{
	if (m_graphEditController)
	{
		m_graphEditController->disconnect();
		delete m_graphEditController;
		m_graphEditController = nullptr;
	}
	if (m_textEditor)
	{
		m_textEditor->disconnect();
		delete m_textEditor;
		m_textEditor = nullptr;
	}
}
void linklistMainWindow::onNewDocumentCreated(const QByteArray& docType)
{
	// wizard 
	if (docType == "graph") {
		m_graphEditController->onNewDocumentCreated();
	}
}
bool linklistMainWindow::openDocument(const QString& fileName,
	QByteArray& docType)
{
	QString format = QFileInfo(fileName).suffix().toLower();
	// graph formats 
	if (docType == "graph")
	{
		QString lastError;
		if (createDocument(docType))
		{
			if (m_graphEditController->loadFromFile(format,
				fileName, &lastError))
			{
				m_graphEditController->onDocumentLoaded(fileName);
				return true;
			}
			// terminate incomplete document 
			//destroyDocument(); 
		}
		if (lastError.size())
		{
			QMessageBox::critical(NULL, fileName, lastError);
		}
		return false;
	}

	{
		docType = "text";
		if (createDocument(docType))
		{
			QFile f(fileName);
			if (f.open(QFile::ReadOnly))
			{
				QTextStream ts(&f);
				m_textEditor->setPlainText(ts.readAll());
				f.close();
				return true;
			}
			// terminate incomplete document  //destroyDocument(); 
		}
	}
	return false;
}
bool linklistMainWindow::saveDocument(const QString& fileName,
	const QString&/*selectedFilter*/, const QByteArray& docType)
{
	// text 
	if (docType == "text")
	{
		QFile f(fileName);
		if (f.open(QFile::WriteOnly))
		{
			QTextStream ts(&f);
			ts << m_textEditor->toPlainText();
			f.close();
			return true;
		}
		return false;
	}
	// graph 
	if (docType == "graph")
	{
		QString extType = QFileInfo(fileName).suffix().toLower();
		QString lastError; // TODO 
		return m_graphEditController->saveToFile(extType,
			fileName, &lastError);
	}
	// unknown type 
	return false;
}
QString linklistMainWindow::getAboutText() const
{
	return Super::getAboutText()
		+ QString(""
#ifdef USE_OGDF 
			"<br>&nbsp; - OGDF &copy; <i>OGDF development team</i>"
#endif 
		);
}
void linklistMainWindow::doReadSettings(QSettings& settings)
{
	Super::doReadSettings(settings);  if (m_graphEditController)
	{
		m_graphEditController->doReadSettings(settings);
	}
}
void linklistMainWindow::doWriteSettings(QSettings& settings)
{
	Super::doWriteSettings(settings);
	if (m_graphEditController)
	{
		m_graphEditController->doWriteSettings(settings);
	}
}
// privates 
void linklistMainWindow::updateFileAssociations()
{
#if defined Q_OS_WIN32 
	CPlatformWin32::registerFileType("base.xgr",
		"BASE native graph document", ".xgr", 0);
#elif defined Q_OS_LINUX 
	// assuming application-xgr has been already added 
	QSettings mimeapps(QDir::homePath() +
		"/.config/mimeapps.list", QSettings::IniFormat);
	mimeapps.beginGroup("Default Applications");
	mimeapps.setValue("application/xgr", "base.desktop");
	mimeapps.endGroup();
	mimeapps.sync();
	qDebug() << mimeapps.status();
#endif 
}
