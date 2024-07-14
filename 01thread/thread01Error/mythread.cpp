#include "mythread.h"

GenerateRand::GenerateRand(QObject *parent)
    : QThread{parent}
{}

void GenerateRand::recvNum(int num) {
    mNum = num;
}

void GenerateRand::run() {
    qDebug() << "生成随机数的线程的线程地址: " << QThread::currentThread();
    QVector<int> vec;
    QElapsedTimer time;
    time.start();
    for (int i = 0; i < mNum; i++) {
        //vec.emplace_back(qrand % 100000);
        vec.push_back(qrand() % 100000);
    }
    int milsec = time.elapsed();
    qDebug() << "生成" << mNum << "个随机数总共用时:" << milsec << "毫秒";
    //emit sendArray(vec);
    // emit sendArray(vec);
    emit sendArray2();
}
