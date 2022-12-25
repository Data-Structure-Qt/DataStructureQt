#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "visualization.h"
#include "messagetips.h"

#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include <QClipboard>
#include <QPropertyAnimation>
#include <QAbstractAnimation>
#include <QParallelAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsView>

QString FE_s;
int FE_e;
bool sign;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("科学计数法转换器");
    this->setWindowIcon(QIcon(":/pic/dccf457bca73b812975f37c8a6874044_副本3.png"));
    this->setFixedSize(365, 225);
    ui->label_2->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString ss = ui->FE_Edit->text();
    ui->Res_Edit->setText(convert(ss));
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->FE_Edit->clear();
    ui->Res_Edit->clear();
}

void MainWindow::on_commandLinkButton_clicked()
{
    QString ss = ui->FE_Edit->text();
    convert(ss);
    visualization *V = new visualization;
    V->setWindowModality(Qt::ApplicationModal);
    V->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label_2->show();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->Res_Edit->text());
    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->label_2);
    animation1->setDuration(500);
    animation1->setTargetObject(ui->label_2);
    animation1->setPropertyName("geometry");
    animation1->setStartValue(QRect(245, 135, 75, 25));
    animation1->setEndValue(QRect(245, 35, 75, 25));
    animation1->setEasingCurve(QEasingCurve::InCirc);
    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->label_2);
    animation2->setDuration(500);
    animation2->setTargetObject(ui->label_2);
    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect();
    ui->label_2->setGraphicsEffect(opacity);
    opacity->setOpacity(1);
    animation2->setTargetObject(opacity);
    animation2->setPropertyName("opacity");
    animation2->setStartValue(1);
    animation2->setEndValue(0);
    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group->start(QParallelAnimationGroup::DeleteWhenStopped);
}

QString MainWindow::convert(QString ss)    // 按常规方式得到结果，同时判断输入格式是否正确
{
    QString res;
    if(ss[0] < '0' || ss[0] > '9')
    {
        MessageTips *M = new MessageTips("输入格式错误！");
        M->show();
        ui->FE_Edit->clear();
        ui->Res_Edit->clear();
        return "";
    }
    res = res + ss[0];
    int i = 2;
    if(ss[1] == '.')
    {
        for(; ss[i] != 'e' && ss[i] != 'E'; ++i)
        {
            if(i >= ss.length()-1 || ss[i] < '0' || ss[i] > '9')
            {
                MessageTips *M = new MessageTips("输入格式错误！");
                M->show();
                ui->FE_Edit->clear();
                ui->Res_Edit->clear();
                return "";
            }
            res = res + ss[i];
        }
        ++i;
    }
    if(ss[i] == '-')
    {
        if(i == ss.length()-1)
        {
            MessageTips *M = new MessageTips("输入格式错误！");
            M->show();
            ui->FE_Edit->clear();
            ui->Res_Edit->clear();
            return "";
        }
        sign = true;
        ++i;
    }
    else
    {
        sign = false;
    }
    int zero = 0, len = ss.length() - i;
    FE_s = ss;
    FE_s.chop(len+1);
    for(int k = i; k < ss.length(); ++k)
    {
        if(ss[k] < '0' || ss[k] > '9')
        {
            MessageTips *M = new MessageTips("输入格式错误！");
            M->show();
            ui->FE_Edit->clear();
            ui->Res_Edit->clear();
            return "";
        }
        zero += pow(10, --len) * ((int)(ss[k].QCharRef::cell())-48);
    }
    FE_e = zero;
    if(sign)
    {
        FE_s.chop(1);
        for(int j = 0; j < zero; ++j)
            res.insert(0, '0');
        res.insert(1, '.');
    }
    else
    {
        if(zero >= res.length()-1)
        {
            int cou = zero - res.length() + 1;
            for(int j = 0; j < cou; ++j)
                res = res + '0';
        }
        else
        {
            res.insert(zero+1, '.');
        }
    }
    return res;
}


