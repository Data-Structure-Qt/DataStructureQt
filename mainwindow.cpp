#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<Qdir>
#include<QPainter>
#include<QPen>
#include<QStack>
#include<QPoint>
#include<QMessageBox>
#include <QButtonGroup>
//构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   My_Dialog=new MyDialog(this);
   My_Tree=nullptr;
   this->setAttribute(Qt::WA_StyledBackground,true);



   //接受从子窗口发射过来的信号
   connect(My_Dialog,&MyDialog::strTransfer,
           [=](QString pre,QString in)
   {
       if(My_Tree!=nullptr)
           My_Tree->clear();
       qDebug()<<pre;
       qDebug()<<in;
       if(pre.size()!=in.size())
       {
            QMessageBox::information(nullptr, "前序、中序构造", "前序、中序构造输入错误", QMessageBox::Yes);
       }
       else
       {
           My_Tree=new BinaryTree(pre,in);
           update();
       }

   }
           );

}

//析构函数
MainWindow::~MainWindow()
{
    delete ui;
    delete My_Tree;
    delete My_Dialog;
}

//重构的绘图事件
void MainWindow::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QPen pen(Qt::SolidLine);
    pen.setWidth(7);
    pen.setColor(Qt::blue);
    painter.setPen(pen);

    //只有当树部位空的时候才画图
    if(My_Tree!=nullptr&&My_Tree->isright==true)
    {

        for(int i=0;i<My_Tree->size();i++)
        {
            pen.setColor(Qt::blue);
            painter.setPen(pen);

            QPoint p=My_Tree->getPoints()[i];//得到各个节点的坐标
            painter.drawEllipse(p,25,25);//圆的半径为25
            //painter.setPen(QPen(Qt::green, 5));
            //painter.setPen(Qt::red);
            painter.drawText(p,QString(My_Tree->getLevelStr()[i]));
            //painter.setPen(QPen(Qt::green, 5));
//            QPen pen(Qt::SolidLine);
//            pen.setWidth(5);
            pen.setColor(Qt::black);
            painter.setPen(pen);
            if(i!=0)
               painter.drawLine(My_Tree->getLines()[i-1]);//得到线段的坐标
        }


    }
    //QPainter painter(this);
    //QPen pen(Qt::SolidLine);
    pen.setWidth(7);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    if(ui->radioButton->isChecked())
     {
        //s1+=My_Tree->a[t1];
        for(int k=0;k<t1;k++)
        {
        My_Tree->Find(My_Tree->a[k]);
        QPoint p=My_Tree->address;
        //QPoint p=My_Tree->getPoints()[1];//得到各个节点的坐标
        qDebug()<<My_Tree->address;
        qDebug()<<k;
        painter.drawEllipse(p,20,20);//圆的半径为25
        }
        //t1++;
        //ui->lineEdit->setText(s1);

    }
    else if(ui->radioButton_2->isChecked())
    {
        for(int k=0;k<t2;k++)
        {
        My_Tree->Find(My_Tree->b[k]);
        QPoint p=My_Tree->address;
        painter.drawEllipse(p,20,20);
        }
    }

}

//前序构造
void MainWindow::on_actionCreat_triggered()
{
    //获得输入的字符串
    bool isOk;
    QString text=QInputDialog::getText(this,QString("构造树"),QString("输入字符串"),
                                       QLineEdit::Normal,0, &isOk);
// QDir::home().dirName()

    if(isOk&&!text.isEmpty())
    {
        //ABC##DE#G##F###
        qDebug()<<text;
        int i=text.count('#');

        //错误判断
        if((2*i-text.size())!=1)
        {
            QMessageBox::information(nullptr, "前序构造", "前序构造输入错误", QMessageBox::Yes);
            return;
        }

        if(My_Tree!=nullptr)
            My_Tree->clear();
         My_Tree=new BinaryTree(text);
         //如果生成树错误,则不刷新屏幕
         if(My_Tree->isright)
         {

             update();
         }
         else
         {
             QMessageBox::information(nullptr, "前序构造", "前序构造输入错误", QMessageBox::Yes);
         }
    }




    /*text.clear();
    text=QString("ABC##DE#G##F###");
    */
}

//层次构造
void MainWindow::on_actionLevel_triggered()
{
    bool isOk;
    QString text=QInputDialog::getText(this,QString("构造树"),QString("输入字符串"),
                                       QLineEdit::Normal, QDir::home().dirName(), &isOk);
    if(isOk&&!text.isEmpty())
    {
        //AB#CD##EF#G####
        qDebug()<<text;

        int i=text.count('#');

        //错误判断
        if((2*i-text.size())!=1)
        {
            QMessageBox::information(nullptr, "层次构造", "层次构造输入错误", QMessageBox::Yes);
            return;
        }

        if(My_Tree!=nullptr)
            My_Tree->clear();
         My_Tree=new BinaryTree(text,1);

         //如果生成树错误,则不刷新屏幕
         if(My_Tree->isright)
             update();
         else
         {
             QMessageBox::information(nullptr, "层次构造", "层次构造输入错误", QMessageBox::Yes);
         }
    }
    /*
     * text.clear();
    text=QString("AB#CD##EF#G####");
    */

}

void MainWindow::on_actionSwap_triggered()
{
    My_Tree->swapTree();
    update();
}

//查找函数
void MainWindow::on_actionFind_triggered()
{
    My_Tree->keyParent.clear();
    bool isOk;
    QString text=QInputDialog::getText(this,QString("查找关键字"),QString("输入关键字"),
                                       QLineEdit::Normal, QDir::home().dirName(), &isOk);
    if(isOk&&!text.isEmpty())
    {

        QChar ch=text[0];
        if(text.size()==1)
        {
            update();
        }
        else
        {
                QMessageBox::information(this,QString("失败"),QString("查找失败"));
        }

    }

}


void MainWindow::on_actionReCreat_triggered()
{
    My_Dialog->show();
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
     {
        s1+=My_Tree->a[t1];
//        //QPoint p=My_Tree->Find(My_Tree->a[t1]);
//        QPoint p=My_Tree->getPoints()[1];//得到各个节点的坐标
//        qDebug()<<My_Tree->getPoints()[1];
//        painter.drawEllipse(p,25,25);//圆的半径为25
        ui->lineEdit->setText(s1);
        t1++;
    }
    else if(ui->radioButton_2->isChecked())
    {
        s2+=My_Tree->b[t2];
        t2++;
        ui->lineEdit->setText(s2);
    }
//    pen.setColor(Qt::blue);
//    painter.setPen(pen);
//    QPoint p=My_Tree->getPoints()[1];//得到各个节点的坐标
//    painter.drawEllipse(p,30,30);//圆的半径为25
    update();
//    for(int i=0;i<My_Tree->size();i++)
//    {


//        QPoint p=My_Tree->getPoints()[i];//得到各个节点的坐标

//        //painter.setPen(QPen(Qt::green, 5));
//        //painter.setPen(Qt::red);
//        painter.drawText(p,QString(My_Tree->getLevelStr()[i]));
//        //painter.setPen(QPen(Qt::green, 5));
//            QPen pen(Qt::SolidLine);
//            pen.setWidth(5);
//        pen.setColor(Qt::black);
//        painter.setPen(pen);
//        if(i!=0)
//           painter.drawLine(My_Tree->getLines()[i-1]);//得到线段的坐标
//    }

}


void MainWindow::on_radioButton_clicked()
{

}


void MainWindow::on_radioButton_2_clicked()
{

}


void MainWindow::on_pushButton_2_clicked()
{
    s1="";
    s2="";
    t1=0;
    t2=0;
     qDebug()<<"hlc";
     ui->lineEdit->setText(s1);
    update();
}

