#include <qapplication.h>
#include "paintui.h"
#include <ui_paintui.h>
int main(int argc, char*argv[])
{
	QApplication a(argc, argv);
	//Q_INIT_RESOURCE(paintui);
	paintui w;
	w.show();
	return a.exec();
}