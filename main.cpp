#include "mainwindow.h"
#include "visualization.h"

#include <QApplication>
#include <QGuiApplication>
#include <qqmlapplicationengine>
#include <qtqml>
#include <QTextCodec>
#include <QQmlContext>
#include <QQuickView>

#include <QDateTime> //添加QDateTime头文件
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/pic/5b3f075762894574e9957fafcf223509_副本.png"));
    splash->show();
    for(int i = 0; i < 200; ++i)
    {
        splash->repaint();
    }

    MainWindow w;
    w.show();

    splash->finish(&w);
    delete splash;

    return a.exec();
}
