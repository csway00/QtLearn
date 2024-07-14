#include "sendfile.h"

SendFile::SendFile(QObject *parent)
    : QObject{parent}
{

}

void SendFile::connectServer(QString ip, unsigned short port)
{
    mTcp = new QTcpSocket(this);

    mTcp->connectToHost(QHostAddress(ip), port);

    connect(mTcp, &QTcpSocket::connected, this, &SendFile::connectedOK);

    connect(mTcp, &QTcpSocket::disconnected, this, [=]() {
        mTcp->close();
        mTcp->deleteLater();
        emit this->alreadyOver();
    });

}


// 发送格式:
// 0: int fileSize 4B
// 1: int 后缀名size 4B
// 2: char* 后缀名, 后缀名的长度;
// 3: 正文

void SendFile::sendFile(QString path)
{
    QFile file(path);
    QFileInfo info(path);

    file.open(QFile::ReadOnly);

    int fileSize = info.size();

    mTcp->write((char*)&fileSize, 4);

    // //发送后缀名:
    // char* dot;
    // QByteArray ba = path.toLatin1();
    // dot = ba.data();

    // dot = strrchr(dot, '.');  // 自右向左查找‘.’字符,
    // // mTcp->write(dot, strlen(dot));
    // int len = strlen(dot);
    // mTcp->write((char*)&len, 4);  //发送后缀名的长度
    // mTcp->write(dot, len);
    // //qDebug() << "后缀名: " << dot;

    int num = 0;
    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        mTcp->write(line);
        num += line.size();

        int progressVal = num / fileSize * 100;

        emit sendProgressVal(progressVal);
    }

}
