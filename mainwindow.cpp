#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<Qdir>
#include<QPainter>
#include<QPen>
#include<QStack>
#include<QPoint>
#include<QMessageBox>

//构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    My_Tree=nullptr;
}

//析构函数
MainWindow::~MainWindow()
{
    delete ui;
    delete My_Tree;
}

//重构的绘图事件
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(Qt::SolidLine);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    //只有当树部位空的时候才画图

    if(My_Tree!=nullptr)
    {

        for(int i=0;i<My_Tree->size();i++)
        {
            QPoint p=My_Tree->getPoints()[i];//得到各个节点的坐标
            Qt::GlobalColor ch = My_Tree->findNodeByPoint(p);
            pen.setColor(ch);
            pen.setWidth(5);
            painter.setPen(pen);

            painter.drawEllipse(p,25,25);//圆的半径为25
            pen.setColor(Qt::blue);

            painter.setPen(pen);
            painter.drawText(p,QString(My_Tree->getLevelStr()[i]));
            if(i!=0)
                painter.drawLine(My_Tree->getLines()[i-1]);//得到线段的坐标
        }
    }
}

void MainWindow::on_btn_sel_clicked()
{
    //把上一次操作颜色清除
    My_Tree->initTreeColor();
    update();
    QString str1 = ui->lineEdit_d1->text();
    QString str2 = ui->lineEdit_d2->text();
    if(str1.isEmpty() || str2.isEmpty())
    {
        QMessageBox::information(this,QString("警告"),QString("查找节点不能为空"));
        return;
    }

    My_Tree->findStrList.clear();
    My_Tree->Find1(str1.toDouble(),My_Tree->getRoot());
    QStringList findStrList1 =  My_Tree->findStrList;
    My_Tree->findStrList.clear();
    My_Tree->Find1(str2.toDouble(),My_Tree->getRoot());
    QStringList findStrList2 =  My_Tree->findStrList;
    QStringList tmpList;
    for(int i=0; i<findStrList1.size(); i++)
    {
        if(findStrList1[i].isEmpty())
        {
            continue;
        }

        if(findStrList2.contains(findStrList1[i]) )
        {
            tmpList << findStrList1[i];
        }
    }

    QMap<int, BinTreeNode *> nodeMap;
    foreach(QString str, tmpList)
    {
        if(str.isEmpty())
        {
            continue;
        }
        My_Tree->Find(str.toDouble(),My_Tree->getRoot());
        BinTreeNode *node = My_Tree->getCurNode();
        if(node == nullptr && My_Tree->height(node) < 0)
        {
            continue;
        }
        nodeMap[My_Tree->height(node)] = node;
    }
    //map自动排序，第一次层次最低，就是最近的，最远的就是last
    BinTreeNode *pNode = nodeMap.first();
    if(nullptr != pNode)
    {
        pNode->eColor = Qt::red;
    }
    update();
}

void MainWindow::on_btn_submit_clicked()
{
    QString text=ui->lineEdit_data->text();
    if(!text.isEmpty())
    {
        int i=text.count(',');
        if(My_Tree!=nullptr)
            My_Tree->clear();
        My_Tree=new BinaryTree(text);
        update();
    }
    update();
}
