#pragma once
#include<qdebug.h>
#include <QtWidgets/QMainWindow>
#include "ui_BTreeMain.h"
#include "BTreeDataStruct.h"
#include<qpainter.h>
#include<queue>
class BTreeMain : public QMainWindow
{
    Q_OBJECT

public:
    BPTree *bPlusTree;
    BTreeMain(QWidget *parent = nullptr);
    ~BTreeMain();

private:
    void paintEvent(QPaintEvent*);
    Ui::BTreeMainClass ui;
public slots:
    void insertList();
};
