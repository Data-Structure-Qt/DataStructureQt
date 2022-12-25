﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"binarytree.h"
#include<QInputDialog>
#include<QPainter>
#include"mydialog.h"
#include <QButtonGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int t1=0;
    int t2=0;
    QString s1;
    QString s2;
protected:

void  paintEvent(QPaintEvent *);

private slots:
    void on_actionCreat_triggered();        //通过前序建树

    void on_actionSwap_triggered();         //交换树的节点

    void on_actionFind_triggered();         //查找节点

    void on_actionLevel_triggered();        //层次建树

    void on_actionReCreat_triggered();      //前序和中序建树

    void on_pushButton_clicked();


    void on_radioButton_clicked();

    void on_radioButton_2_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::MainWindow *ui;
    BinaryTree * My_Tree;                   //树
    MyDialog *My_Dialog;                    //自己写的对话框，用于前序和中序建树

};

#endif // MAINWINDOW_H
