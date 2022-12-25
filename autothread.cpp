#include "autothread.h"
#include "mainwindow.h"
#include "visualization.h"

#include <QDebug>

extern QString FE_s;
extern int FE_e;
extern bool sign;
extern int e, p;
extern QString s;
extern bool endflag;
extern int thr;
extern int t;

AutoThread::AutoThread(QObject *parent) : QThread(parent)
{

}

void AutoThread::run()
{
    qDebug() << "当前线程对象的地址: " << QThread::currentThread();
    if(thr == 1)
    {
        left_move();
    }
    else if(thr == 0)
    {
        right_move();
    }
    else
    {
        if(sign)
        {
            for(; e > 0; --e)
            {
                QThread::usleep(t*2);
                left_move();
                emit updata();
                if(endflag)
                    break;
            }
        }
        else
        {
            for(; e > 0; --e)
            {
                QThread::usleep(t*2);
                right_move();
                emit updata();
                if(endflag)
                    break;
            }
        }
        emit change();
    }
    emit curNumber();
    qDebug() << "run() 执行完毕, 子线程退出";
}

void AutoThread::left_move()    // 当前操作位（小数点）左移一位
{
    s.remove(p, 1);
    s.insert(--p, '.');
    emit move_1(p);
    emit move_2(p);
    usleep(t);
    if(!p)
    {
        emit move_3(140);
        usleep(t);
        s.insert(p++, '0');
    }
    if(p >= FE_s.length()-2)
    {
        emit move_4(p);
        usleep(t);
        s.chop(1);
    }
    qDebug() << s << " " << p << " " << e << " ";
}

void AutoThread::right_move()
{
    emit move_1(p);
    emit move_2(p);
    usleep(t);
    s.remove(p, 1);
    s.insert(++p, '.');
    if(s[0] == '0')
    {
        emit move_3(70);
        usleep(t);
        s.remove(0, 1);
        --p;
    }
    if(p >= FE_s.length()-1)
    {
        emit move_5(p+1);
        usleep(t);
        s.append('0');
    }
    qDebug() << s << " " << p << " " << e << " ";
}
