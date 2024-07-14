#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QVector>
#include <QElapsedTimer>
#include <QDebug>

using namespace std;


//生成随机数的类
class Generate : public QThread
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);

    void recvNum(int num);

protected:
    void run() override;

signals:
    void sendArray(QVector<int> vec);

private:
    int mNum;
};


//冒泡排序
class BubbleSort : public QThread
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);

    void recvVec(QVector<int> vec);

protected:
    void run() override;

signals:
    void finish(QVector<int> vec);

private:
    QVector<int> mVec;
};


//快速排序
class QuickSort : public QThread
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);

    void recvVec(QVector<int> vec);

    void quickSort(QVector<int> &s, int l, int r);


protected:
    void run() override;

signals:
    void finish(QVector<int> vec);

private:
    QVector<int> mVec;
};


#endif // MYTHREAD_H
