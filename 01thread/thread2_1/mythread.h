#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

    void run() override;

    int mNum;

signals:
    void sendNum(int num);
};

#endif // MYTHREAD_H
