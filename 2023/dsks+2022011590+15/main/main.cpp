#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.setWindowTitle("�Թ����ӻ�");
	w.setFixedSize(1200, 800);
	w.show();
	return a.exec();
}

