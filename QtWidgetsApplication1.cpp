#include "QtWidgetsApplication1.h"
#include<QTimer.h>
QString a[10];
int n = 10;
int i = 0;
QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}
void QtWidgetsApplication1::creat()
{
    
    QString data = ui.lineEdit->text();
    QStringList temp = data.split(",");
    for (int i = 0; i < n; i++)
    {
        a[i] = temp.at(i);
    }
    ui.lineEdit_2->setText(a[0]);
    ui.lineEdit_3->setText(a[1]);
    ui.lineEdit_4->setText(a[2]);
    ui.lineEdit_5->setText(a[3]);
    ui.lineEdit_6->setText(a[4]);
    ui.lineEdit_7->setText(a[5]);
    ui.lineEdit_8->setText(a[6]);
    ui.lineEdit_9->setText(a[7]);
    ui.lineEdit_10->setText(a[8]);
    ui.lineEdit_11->setText(a[9]);
    
    //QString pushtext = "123";
    //ui.lineEdit->setText(pushtext);
    //QString pushText = "test!";
    //ui.lineEdit->setText(pushText);
}
void QtWidgetsApplication1::zhubupaixu()
{
    int j, k;
    k = i;
    for (j = k + 1; j < n; j++)
    {
        if (a[k].toInt() < a[j].toInt())
        {
            k = j;
        }
    }
    QString t = a[i];
    a[i] = a[k];
    a[k] = t;
    ui.lineEdit_2->setText(a[0]);
    ui.lineEdit_3->setText(a[1]);
    ui.lineEdit_4->setText(a[2]);
    ui.lineEdit_5->setText(a[3]);
    ui.lineEdit_6->setText(a[4]);
    ui.lineEdit_7->setText(a[5]);
    ui.lineEdit_8->setText(a[6]);
    ui.lineEdit_9->setText(a[7]);
    ui.lineEdit_10->setText(a[8]);
    ui.lineEdit_11->setText(a[9]);
    i++;
}
void QtWidgetsApplication1::paixu()
{
    int j, k;
   
    for (i; i < n-1; i++)
    {
        k = i;
        for (j = k + 1; j < n; j++)
        {
            if (a[k].toInt() < a[j].toInt())
            {
                k = j;
            }
        }
        QString t = a[i];
        a[i] = a[k];
        a[k] = t;
        ui.lineEdit_2->setText(a[0]);
        ui.lineEdit_3->setText(a[1]);
        ui.lineEdit_4->setText(a[2]);
        ui.lineEdit_5->setText(a[3]);
        ui.lineEdit_6->setText(a[4]);
        ui.lineEdit_7->setText(a[5]);
        ui.lineEdit_8->setText(a[6]);
        ui.lineEdit_9->setText(a[7]);
        ui.lineEdit_10->setText(a[8]);
        ui.lineEdit_11->setText(a[9]);
        QEventLoop loop;
        QTimer::singleShot(5000, &loop, SLOT(quit()));
        loop.exec();
    }
        
}
QtWidgetsApplication1::~QtWidgetsApplication1()
{}
