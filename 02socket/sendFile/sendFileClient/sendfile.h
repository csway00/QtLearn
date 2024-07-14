#ifndef SENDFILE_H
#define SENDFILE_H

#include <QObject>
#include <QTcpSocket>
#include <QHostAddress>
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>

class SendFile : public QObject
{
    Q_OBJECT
public:
    explicit SendFile(QObject *parent = nullptr);

    //连接服务器
    void connectServer(QString ip, unsigned short port);

    //发送文件到服务器
    void sendFile(QString path);

private:
    QTcpSocket* mTcp;

signals:
    void connectedOK();

    void alreadyOver();

    void sendProgressVal(int num);

};

#endif // SENDFILE_H
