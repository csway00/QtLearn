#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QVector>

class GenerateRand : public QThread
{
public:
    explicit GenerateRand(QObject *parent = nullptr);

    void recvNum(int num);

    int mNum;

    //void sendArray(QVector<int> vec);

protected:
    void run() override;

signals:
    //void sendArray(QVector<int> vec);
    void sendArray2();

};

#endif // MYTHREAD_H
