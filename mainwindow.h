#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"binarytree.h"
#include<QInputDialog>
#include<QPainter>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

void  paintEvent(QPaintEvent *);
private slots:
    void on_btn_sel_clicked();

    void on_btn_submit_clicked();

private:
    Ui::MainWindow *ui;
    BinaryTree * My_Tree;                   //树
};

#endif // MAINWINDOW_H
