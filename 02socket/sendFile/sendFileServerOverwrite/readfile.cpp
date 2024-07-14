#include "readfile.h"

ReadFile::ReadFile(qintptr sock, QObject *parent)
    : QThread{parent}
{
    mTcp = new QTcpSocket(this);
    mTcp->setSocketDescriptor(sock);

}


/*
发送的格式:
0: int fileSize 4B
1: int 后缀名size 4B
2: char* 后缀名, 后缀名的长度;
3: 正文
*/
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

        // char* suffixName = "";
        // int suffixSize;


        if (!cnt) {
            mTcp->read((char*)&total, 4);

            //mTcp->read((char*)&suffixSize, 4);
            //mTcp->read(suffixName, suffixSize);  //客户端是写了20字节过来;
        }

        QByteArray all = mTcp->readAll();
        cnt += all.size();
        file->write(all);

        if (cnt == total) {
            mTcp->close();
            mTcp->deleteLater();
            file->close();
            file->deleteLater();

            //改变文件后缀名
            // QString suffixName2(suffixName);
            // qDebug() << "接收到的后缀名:" << suffixName2;
            // file->rename("recv"+suffixName2);
            emit over();
        }

    });

    //进入事件循环
    exec();

}
