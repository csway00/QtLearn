#include "mythread.h"

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{}

void MyThread::run() {
    int i = 0;
    while (mNum--) {
        emit sendNum(i++);
        QThread::usleep(1);
    }

}
