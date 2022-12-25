#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "mainwindow.h"

#include <QList>
#include <QLabel>
#include <QDialog>

namespace Ui {
class visualization;
}

class visualization : public QDialog
{
    Q_OBJECT

public:
    explicit visualization(QWidget *parent = 0);

    ~visualization();

signals:
    void  up(QString s);

private slots:
    void on_NextButton_clicked();

    void on_AutoButton_clicked();

    void on_LastButton_clicked();

    void on_StopButton_clicked();

    void on_ReButton_clicked();

    void on_OverButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void _change();

    void _updata();

    void _move_1(int p);

    void _move_2(int p);

    void _move_3(int p);

    void _move_4(int p);

    void _move_5(int p);

private:
    Ui::visualization *ui;

    void init();

    void _move(int x);

    QList<QLabel*> lablist;

//    QLabel *lab;

};

#endif // VISUALIZATION_H
