#include <QtWidgets/QApplication>
#include "dequeueMainWindow.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Q_INIT_RESOURCE(commonui);
	Q_INIT_RESOURCE(appbase);
	a.setWindowIcon(QIcon(":/Icons/AppIcon"));
	dequeueMainWindow w;
	w.init(a.arguments());
	return a.exec();
}
