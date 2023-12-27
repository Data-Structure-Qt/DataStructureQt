#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <vector>
#include <QDebug>
#include "QFileDialog"
#include <QtMath>
#include <QPainter>
#include <QPaintEvent>
#include <QPointF>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QTimer>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int Status;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct node {
	int x;
	int y;
	char orientation;
};

typedef struct snode {
	node pos;
	struct snode* next;
}snode;

typedef struct linkstack {
	snode* top;
	snode* bottom;
	int length;
}linkstack;

typedef struct
{
	int rx;				//位置x坐标
	int cy;				//位置y坐标
}Set;
typedef struct
{
	Set data[MAXSIZE];
	int length;			//路径长度
} PathType;//定义路径类型

struct Move
{
	int x;
	int y;
};//移动方向坐标


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	bool GenerateMaze(int irow, int icol, QString text);
	void readInput();
	Status showPath(linkstack S);
	Status destroyStack(linkstack* S);
	~MainWindow();

	Status creat(linkstack *S);
	bool empty(linkstack S);
	int size(linkstack S);
	Status push(linkstack *S, node pos);
	Status pop(linkstack *S);
	Status gettop(linkstack S, node &pos);
	void paintPath();
	void useStack();
	void useRecursion(int xis, int yis, int xes, int yes, PathType paths, int maze[8][8]);
private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_4_clicked();
	void paintEvent(QPaintEvent *);

private:
	Ui::MainWindow *ui;
	int row = 0;
	int col = 0;
	int flag = false;
	int num = 0;
	int minpath = 100, b = 0;//求最短路径
	int maze[8][8] = { 1 };
	QString str;
	Move mov[4] = { {-1,0},{0,1},{1,0},{0,-1} };//四个移动方向,右下左上
	bool isCall = false;
	bool isDone = false;
	int pointCount = 1;
	int pathCount = 0;
	QLineEdit* input[MAXSIZE];
	QTimer *timer;
	QPointF point;
	QPointF points[MAXSIZE];
	QPointF path[MAXSIZE];
	QPointF currentPoint;
	QPointF nextPoint;
};
#endif // MAINWINDOW_H

