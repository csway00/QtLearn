#include "mythread.h"

MyThread::MyThread(QObject *parent)
    : QObject{parent}
{}

void MyThread::working() {
    qDebug() << "子线程地址:" << QThread::currentThread();
    int i = 0;
    while (num--) {
        emit sendNum(i++);
        QThread::usleep(1);
    }
    qDebug() << "子线程执行完毕";

}
