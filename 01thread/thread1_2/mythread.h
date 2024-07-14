#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QVector>
#include <QElapsedTimer>
#include <QDebug>
#include <QObject>

using namespace std;


//生成随机数的类
class Generate : public QObject
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);

    void working(int num);

signals:
    void sendArray(QVector<int> vec);

};


//冒泡排序
class BubbleSort : public QObject
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);

    void recvVec(QVector<int> vec);

    void working(QVector<int> vec);

signals:
    void finish(QVector<int> vec);
};


//快速排序
class QuickSort : public QObject
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);

    void quickSort(QVector<int> &s, int l, int r);


    void working(QVector<int> vec);

signals:
    void finish(QVector<int> vec);

};


#endif // MYTHREAD_H
