#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

    //void working(int num);
    void working();

    int num = 1000;

signals:
    void sendNum(int num);
};

#endif // MYTHREAD_H
