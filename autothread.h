#ifndef AUTOTHREAD_H
#define AUTOTHREAD_H

#include <QThread>

class AutoThread : public QThread
{
    Q_OBJECT
public:
    explicit AutoThread(QObject *parent = nullptr);

protected:
    void run();

    void left_move();

    void right_move();

signals:
    void curNumber();

    void change();

    void updata();

    void move_1(int p);

    void move_2(int p);

    void move_3(int p);

    void move_4(int p);

    void move_5(int p);

private:
};

#endif // MYTHREAD_H
