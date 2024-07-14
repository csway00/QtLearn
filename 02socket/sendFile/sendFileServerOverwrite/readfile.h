#ifndef READFILE_H
#define READFILE_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QTcpSocket>

class ReadFile : public QThread
{
    Q_OBJECT
public:
    explicit ReadFile(qintptr, QObject *parent = nullptr);

    void run() override;

private:
    QTcpSocket* mTcp;

signals:
    void over();
};

#endif // READFILE_H
