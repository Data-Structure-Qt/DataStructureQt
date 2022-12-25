#include "visualization.h"
#include "ui_visualization.h"
#include "mainwindow.h"
#include "autothread.h"

#include <windows.h>
#include <QDebug>
#include <QTime>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QAbstractAnimation>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPauseAnimation>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsOpacityEffect>
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QColor>
#include <QLabel>
#include <QPixmap>
#include <QMovie>
#include <QtWidgets/QDialog>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QQuickView>

extern QString FE_s;
extern int FE_e;
extern bool sign;

QString s;
int p, e;
bool endflag = false;
int thr;
int t, _t;

visualization::visualization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::visualization)
{
//    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    this->setFixedSize(980, 555);
    this->setWindowTitle("可视化界面");
    this->setWindowIcon(QIcon(":/pic/dccf457bca73b812975f37c8a6874044_副本3.png"));

    ui->label_4->hide();
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap("./pic/15f22a31ece69881bd29efa5e524b999.jpeg")));
    setPalette(pal);

    ui->label_5->setFixedSize(108,39);
    ui->label_5->hide();
    ui->label_6->hide();
    QMovie *movie = new QMovie(":/pic/0508f31a656101be8baa42eb294c74d8.gif");
    movie->setObjectName("movieLoading");
    ui->label_5->setMovie(movie);
    movie->setScaledSize(QSize(96, 56));
    movie->setSpeed(100);
    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect();
    ui->label_5->setGraphicsEffect(opacity);
    opacity->setOpacity(0.8);
    movie->start();

    QButtonGroup *block = new QButtonGroup(this);
    block->addButton(ui->radioButton,0);
    block->addButton(ui->radioButton_2,1);
    block->addButton(ui->radioButton_3,1);
    ui->radioButton->setChecked(1);
    t = 1500000;
    _t = 500;
    init();
}

visualization::~visualization()
{
    qDeleteAll(lablist);
    lablist.clear();
    delete ui;
}

void visualization::init()    // 将数据、界面恢复到初始
{
    ui->reslabel->hide();
    ui->StopButton->setEnabled(false);
    ui->LastButton->setEnabled(false);
    ui->AutoButton->setEnabled(true);
    ui->NextButton->setEnabled(true);
    if(sign)
    {
        ui->FE_num->setText(FE_s + "e-" + QString::number(FE_e));
        ui->Now_num->setText(FE_s + "e-" + QString::number(FE_e));
        ui->lcdNumber->display("-" + QString::number(FE_e));
    }
    else
    {
        ui->FE_num->setText(FE_s + "e" + QString::number(FE_e));
        ui->Now_num->setText(FE_s + "e" + QString::number(FE_e));
        ui->lcdNumber->display(QString::number(FE_e));

    }
    s = FE_s;
    e = FE_e;
    p = 1;
    qDeleteAll(lablist);
    lablist.clear();qDebug() << "LL";
    for(int i = 0; i < s.length(); ++i)
    {
        QLabel *label = new QLabel(this);
        label->clear();
        label->setGeometry(105 + i*35, 260, 32, 33);
        label->setText(s.mid(i, 1));
        label->setAlignment(Qt::AlignCenter);
        QFont Font("Microsoft YaHei", 18, 75);
        label->setFont(Font);
        label->setObjectName("lab" + QString::number(i));
        lablist.append(label);
        QPalette palette;
        palette.setColor(QPalette::Background, QColor(0, 255, 0, 155));
        label->setAutoFillBackground(true);
        label->setPalette(palette);
        label->show();
    }
}

void visualization::on_AutoButton_clicked()
{
    ui->label_5->show();
    ui->label_6->show();
    ui->AutoButton->setText(" ");
    ui->NextButton->setEnabled(false);
    ui->LastButton->setEnabled(false);
    ui->ReButton->setEnabled(false);
    ui->AutoButton->setEnabled(false);
    ui->StopButton->setEnabled(true);

    AutoThread* subThread = new AutoThread;
    thr = -1;
    connect(subThread, SIGNAL(move_1(int )), this, SLOT(_move_1(int )));
    connect(subThread, SIGNAL(move_2(int )), this, SLOT(_move_2(int )));
    connect(subThread, SIGNAL(move_3(int )), this, SLOT(_move_3(int )));
    connect(subThread, SIGNAL(move_4(int )), this, SLOT(_move_4(int )));
    connect(subThread, SIGNAL(move_5(int )), this, SLOT(_move_5(int )));
    connect(subThread, SIGNAL(change()), this, SLOT(_change()));
    connect(subThread, SIGNAL(updata()), this, SLOT(_updata()));
    subThread->start();
}

void visualization::_change()
{
    ui->StopButton->setEnabled(false);
    ui->label_5->hide();
    ui->label_6->hide();
    ui->AutoButton->setText("自动进行");
    ui->LastButton->setEnabled(true);
    ui->ReButton->setEnabled(true);
    if(e)
    {
        ui->AutoButton->setEnabled(true);
        ui->NextButton->setEnabled(true);
    }
    else
    {
        ui->reslabel->show();
        ui->reslabel->setText("结果：" + s);
        ui->lcdNumber->display("0");
    }
}

void visualization::_updata()
{
    _move(1);
    if(sign)
    {
        ui->Now_num->setText(s + "e-" + QString::number(e));
        ui->lcdNumber->display("-" + QString::number(e));
    }
    else
    {
        ui->Now_num->setText(s + "e" + QString::number(e));
        ui->lcdNumber->display(QString::number(e));
    }
}

void visualization::on_NextButton_clicked()
{
    ui->NextButton->setEnabled(false);
    ui->LastButton->setEnabled(false);
    ui->AutoButton->setEnabled(false);
    ui->ReButton->setEnabled(false);
    --e;
    _move(1);
    AutoThread* subThread = new AutoThread;
    connect(subThread, SIGNAL(move_1(int )), this, SLOT(_move_1(int )));
    connect(subThread, SIGNAL(move_2(int )), this, SLOT(_move_2(int )));
    connect(subThread, SIGNAL(move_3(int )), this, SLOT(_move_3(int )));
    connect(subThread, SIGNAL(move_4(int )), this, SLOT(_move_4(int )));
    connect(subThread, SIGNAL(move_5(int )), this, SLOT(_move_5(int )));
    if(sign)
    {
        thr = 1;
        subThread->start();
        connect(subThread, &AutoThread::curNumber, this, [=]()
        {
            ui->Now_num->setText(s + "e-" + QString::number(e));
            ui->lcdNumber->display("-" + QString::number(e));
            ui->LastButton->setEnabled(true);
            ui->ReButton->setEnabled(true);
            if(e > 0)
            {
                ui->NextButton->setEnabled(true);
                ui->AutoButton->setEnabled(true);
            }
            else
            {
                ui->reslabel->show();
                ui->reslabel->setText("结果：" + s);
                ui->lcdNumber->display("0");
            }
        });
    }
    else
    {
        thr = 0;
        subThread->start();
        connect(subThread, &AutoThread::curNumber, this, [=]()
        {
            ui->Now_num->setText(s + "e" + QString::number(e));
            ui->lcdNumber->display(QString::number(e));
            ui->LastButton->setEnabled(true);
            ui->ReButton->setEnabled(true);
            if(e > 0)
            {
                ui->NextButton->setEnabled(true);
                ui->AutoButton->setEnabled(true);
            }
            else
            {
                ui->reslabel->show();
                ui->reslabel->setText("结果：" + s);
                ui->lcdNumber->display("0");
            }
        });
    }
}

void visualization::on_LastButton_clicked()
{
    ui->LastButton->setEnabled(false);
    ui->NextButton->setEnabled(false);
    ui->AutoButton->setEnabled(false);
    ui->ReButton->setEnabled(false);
    ui->reslabel->hide();
    ++e;
    _move(0);
    AutoThread* subThread = new AutoThread;
    connect(subThread, SIGNAL(move_1(int )), this, SLOT(_move_1(int )));
    connect(subThread, SIGNAL(move_2(int )), this, SLOT(_move_2(int )));
    connect(subThread, SIGNAL(move_3(int )), this, SLOT(_move_3(int )));
    connect(subThread, SIGNAL(move_4(int )), this, SLOT(_move_4(int )));
    connect(subThread, SIGNAL(move_5(int )), this, SLOT(_move_5(int )));
    if(sign)
    {
        thr = 0;
        subThread->start();
        connect(subThread, &AutoThread::curNumber, this, [=]()
        {
            ui->Now_num->setText(s + "e-" + QString::number(e));
            ui->lcdNumber->display("-" + QString::number(e));
            ui->NextButton->setEnabled(true);
            ui->AutoButton->setEnabled(true);
            ui->ReButton->setEnabled(true);
            if(e < FE_e)
            {
                ui->LastButton->setEnabled(true);
            }
        });
    }
    else
    {
        thr = 1;
        subThread->start();
        connect(subThread, &AutoThread::curNumber, this, [=]()
        {
            ui->Now_num->setText(s + "e" + QString::number(e));
            ui->lcdNumber->display(QString::number(e));
            ui->NextButton->setEnabled(true);
            ui->AutoButton->setEnabled(true);
            ui->ReButton->setEnabled(true);
            if(e < FE_e)
            {
                ui->LastButton->setEnabled(true);
            }
        });
    }
}

void visualization::on_StopButton_clicked()
{
    endflag = true;
}

void visualization::on_ReButton_clicked()
{
    init();
}

void visualization::on_OverButton_clicked()
{
    this->close();
}

void visualization::_move(int x)
{
    x = sign?(x=1?0:1):x;
    ui->label_4->show();
    ui->label_4->clear();
    ui->label_4->setObjectName("lab");
    QPropertyAnimation *animation1 = new QPropertyAnimation(ui->label_4);
    animation1->setDuration(_t*2);
    animation1->setTargetObject(ui->label_4);
    animation1->setPropertyName("geometry");
    animation1->setEasingCurve(QEasingCurve::InCirc);
    if(x)
    {
        ui->label_4->setText("-1");
        animation1->setStartValue(QRect(479, 130, 32, 33));
        animation1->setEndValue(QRect(479, 65, 32, 33));
    }
    else
    {
        ui->label_4->setText("+1");
        animation1->setStartValue(QRect(479, 65, 32, 33));
        animation1->setEndValue(QRect(479, 130, 32, 33));animation1->start();
    }
    QPropertyAnimation *animation2 = new QPropertyAnimation(ui->label_4);
    animation2->setDuration(_t*2);
    animation2->setTargetObject(ui->label_4);
    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect();
    ui->label_4->setGraphicsEffect(opacity);
//    opacity->setOpacity(x);  // ?????????????????????????????????????????????????????????????????????????????????????????
    animation2->setTargetObject(opacity);
    animation2->setPropertyName("opacity");
    animation2->setStartValue(x);
    animation2->setEndValue(x=0?1:0);
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group->start(QSequentialAnimationGroup::DeleteWhenStopped);
}

void visualization::_move_1(int p)
{
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
    QPropertyAnimation *animation1 = new QPropertyAnimation(lablist.at(p));
    animation1->setDuration(_t);
    animation1->setTargetObject(lablist.at(p));
    animation1->setPropertyName("geometry");
    animation1->setStartValue(QRect(105 + p*35, 260, 32, 33));
    animation1->setEndValue(QRect(140 + p*35, 200, 32, 33));
    animation1->setEasingCurve(QEasingCurve::InCirc);
    QPropertyAnimation *animation2 = new QPropertyAnimation(lablist.at(p));
    animation2->setDuration(_t*2);
    animation2->setTargetObject(lablist.at(p));
    animation2->setPropertyName("geometry");
    animation2->setStartValue(QRect(140 + p*35, 200, 32, 33));
    animation2->setEndValue(QRect(140 + p*35, 260, 32, 33));
    animation2->setEasingCurve(QEasingCurve::OutBounce);
    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group->start(QSequentialAnimationGroup::DeleteWhenStopped);
}

void visualization::_move_2(int p)
{
    QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
    QPropertyAnimation *animation3 = new QPropertyAnimation(lablist.at(p+1));
    animation3->setDuration(_t);
    animation3->setTargetObject(lablist.at(p+1));
    animation3->setPropertyName("geometry");
    animation3->setStartValue(QRect(140 + p*35, 260, 32, 33));
    animation3->setEndValue(QRect(105 + p*35, 320, 32, 33));
    animation3->setEasingCurve(QEasingCurve::InCirc);
    QPropertyAnimation *animation4 = new QPropertyAnimation(lablist.at(p+1));
    animation4->setDuration(_t*2);
    animation4->setTargetObject(lablist.at(p+1));
    animation4->setPropertyName("geometry");
    animation4->setStartValue(QRect(105 + p*35, 320, 32, 33));
    animation4->setEndValue(QRect(105 + p*35, 260, 32, 33));
    animation4->setEasingCurve(QEasingCurve::OutBounce);
    group->addAnimation(animation3);
    group->addAnimation(animation4);
    group->start(QSequentialAnimationGroup::DeleteWhenStopped);

    lablist.swap(p, p+1);
}

void visualization::_move_3(int p)
{
    for(int i = 0; i < s.length(); ++i)
    {
        QPropertyAnimation *animation = new QPropertyAnimation(lablist.at(i));
        animation->setDuration(_t);
        animation->setTargetObject(lablist.at(i));
        animation->setPropertyName("geometry");
        animation->setStartValue(QRect(105 + i*35, 260, 32, 33));
        animation->setEndValue(QRect(p + i*35, 260, 32, 33));
        animation->setEasingCurve(QEasingCurve::InCirc);
        animation->start(QAbstractAnimation::DeleteWhenStopped);
    }
    if(p == 140)
    {
        QLabel *label = new QLabel(this);
        label->clear();
        label->setGeometry(105, 260, 32, 33);
        label->setText("0");
        label->setAlignment(Qt::AlignCenter);
        QFont Font("Microsoft YaHei", 18, 75);
        label->setFont(Font);
        label->setObjectName("lab");
        QPalette palette;
        palette.setColor(QPalette::Background, QColor(0, 255, 0, 155));
        label->setAutoFillBackground(true);
        label->setPalette(palette);
        label->show();
        lablist.prepend(label);

        QPauseAnimation *animation1 = new QPauseAnimation(this);
        animation1->setDuration(_t);
        QPropertyAnimation *animation2 = new QPropertyAnimation(label);
        animation2->setDuration(_t);
        animation2->setTargetObject(label);
        QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect();
        label->setGraphicsEffect(opacity);
        opacity->setOpacity(0);
        animation2->setTargetObject(opacity);
        animation2->setPropertyName("opacity");
        animation2->setStartValue(0);
        animation2->setEndValue(1);
        QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
        group->addAnimation(animation1);
        group->addAnimation(animation2);
        group->start(QSequentialAnimationGroup::DeleteWhenStopped);
    }
    else
    {
        QPauseAnimation *animation1 = new QPauseAnimation(this);
        animation1->setDuration(_t);
        QLabel *label = lablist.takeFirst();
        QPropertyAnimation *animation2 = new QPropertyAnimation(label);
        animation2->setDuration(_t);
        animation2->setTargetObject(label);
        QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect();
        label->setGraphicsEffect(opacity);
        opacity->setOpacity(1);
        animation2->setTargetObject(opacity);
        animation2->setPropertyName("opacity");
        animation2->setStartValue(1);
        animation2->setEndValue(0);
        QSequentialAnimationGroup *group = new QSequentialAnimationGroup;
        group->addAnimation(animation1);
        group->addAnimation(animation2);
        group->start(QSequentialAnimationGroup::DeleteWhenStopped);
//        delete ;
    }
}

void visualization::_move_4(int p)
{
    QLabel* label = lablist.takeLast();
    QPropertyAnimation *animation1 = new QPropertyAnimation(label);
    animation1->setDuration(_t);
    animation1->setTargetObject(label);
    animation1->setPropertyName("geometry");
    animation1->setStartValue(QRect(175 + p*35, 260, 32, 33));
    animation1->setEndValue(QRect(270 + p*35, 260, 32, 33));
    animation1->setEasingCurve(QEasingCurve::InCirc);
    QPropertyAnimation *animation2 = new QPropertyAnimation(label);
    animation2->setDuration(_t*1.5);
    animation2->setTargetObject(label);
    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect();
    label->setGraphicsEffect(opacity);
    opacity->setOpacity(1);
    animation2->setTargetObject(opacity);
    animation2->setPropertyName("opacity");
    animation2->setStartValue(1);
    animation2->setEndValue(0);
    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group->start(QParallelAnimationGroup::DeleteWhenStopped);
//    delete l;
}

void visualization::_move_5(int p)
{
    QLabel *label = new QLabel(this);
    label->clear();
    label->setGeometry(170 + p*35, 260, 32, 33);
    label->setText("0");
    label->setAlignment(Qt::AlignCenter);
    QFont Font("Microsoft YaHei", 18, 75);
    label->setFont(Font);
    label->setObjectName("lab" + QString::number(p));
    lablist.append(label);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(0, 255, 0, 155));
    label->setAutoFillBackground(true);
    label->setPalette(palette);
    label->show();

    QPropertyAnimation *animation1 = new QPropertyAnimation(label);
    animation1->setDuration(_t);
    animation1->setTargetObject(label);
    animation1->setPropertyName("geometry");
    animation1->setStartValue(QRect(140 + p*35, 260, 32, 33));
    animation1->setEndValue(QRect(105 + p*35, 260, 32, 33));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    QPropertyAnimation *animation2 = new QPropertyAnimation(label);
    animation2->setDuration(_t);
    animation2->setTargetObject(label);
    QGraphicsOpacityEffect* opacity = new QGraphicsOpacityEffect();
    label->setGraphicsEffect(opacity);
    opacity->setOpacity(0);
    animation2->setTargetObject(opacity);
    animation2->setPropertyName("opacity");
    animation2->setStartValue(0);
    animation2->setEndValue(1);
    QParallelAnimationGroup *group = new QParallelAnimationGroup;
    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group->start(QParallelAnimationGroup::DeleteWhenStopped);
}

void visualization::on_radioButton_clicked()
{
    t = 1500000;
    _t = 500;
    QMovie *movie = new QMovie(":/pic/0508f31a656101be8baa42eb294c74d8.gif");
    movie->setObjectName("movieLoading");
    ui->label_5->setMovie(movie);
    movie->setScaledSize(QSize(96, 56));
    movie->setSpeed(100);
    movie->start();
}

void visualization::on_radioButton_2_clicked()
{
    t = 3000000;
    _t = 1000;
    QMovie *movie = new QMovie(":/pic/0508f31a656101be8baa42eb294c74d8.gif");
    movie->setObjectName("movieLoading");
    ui->label_5->setMovie(movie);
    movie->setScaledSize(QSize(96, 56));
    movie->setSpeed(50);
    movie->start();
}

void visualization::on_radioButton_3_clicked()
{
    t = 750000;
    _t = 250;
    QMovie *movie = new QMovie(":/pic/0508f31a656101be8baa42eb294c74d8.gif");
    movie->setObjectName("movieLoading");
    ui->label_5->setMovie(movie);
    movie->setScaledSize(QSize(96, 56));
    movie->setSpeed(200);
    movie->start();
}
