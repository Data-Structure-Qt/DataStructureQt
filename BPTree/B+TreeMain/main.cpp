#include "BTreeMain.h"
#include <QtWidgets/QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BTreeMain w;
    w.show();
    return a.exec();
}
