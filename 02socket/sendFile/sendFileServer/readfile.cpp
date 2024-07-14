#include "readfile.h"

ReadFile::ReadFile( QTcpSocket* tcp, QObject *parent)
    : QThread{parent}
{
    mTcp = tcp;
}

void ReadFile::run()
{
    qDebug() << "服务器子线程:" << QThread::currentThread();
    QFile* file = new QFile("recv.txt");
    file->open(QFile::WriteOnly);

    //接受数据
    connect(mTcp, &QTcpSocket::readyRead, this, [=]() {
        qDebug() << "开始接收数据";
        static int cnt = 0;
        static int total = 0;

        if (!cnt) {
            mTcp->read((char*)&total, 4);
        }

        QByteArray all = mTcp->readAll();
        cnt += all.size();
        file->write(all);

        if (cnt == total) {
            mTcp->close();
            mTcp->deleteLater();
            file->close();
            file->deleteLater();

            emit over();
        }

    });

    //进入事件循环
    exec();

}
