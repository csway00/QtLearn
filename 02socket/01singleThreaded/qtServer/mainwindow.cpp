#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("TCP-服务器");

    mServer = new QTcpServer(this);

    ui->port->setText(QString::number(mPort));

    connect(mServer, &QTcpServer::newConnection, this, [=]() {
        mTcp = mServer->nextPendingConnection();
        ui->historyText->append("成功和客户端建立了新的连接...");

        mStatus->setPixmap(QPixmap(":/hook.png").scaled(30, 30));

        //检测是否有客户端数据
        connect(mTcp, &QTcpSocket::readyRead, this, [=]() {
            //接受数据
            QString recvMsg = mTcp->readAll();
            ui->historyText->append("客户端say:" + recvMsg);
        });

        connect(mTcp, &QTcpSocket::disconnected, this, [=](){
            mTcp->close();
            mTcp->deleteLater();
            mStatus->setPixmap(QPixmap(":/fork.jpg").scaled(30, 30));

        });



    });

    mStatus = new QLabel;
    mStatus->setPixmap(QPixmap(":/fork.jpg").scaled(30, 30));

    ui->statusbar->addWidget(new QLabel("连接状态:"));
    ui->statusbar->addWidget(mStatus);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startListenBtn_clicked()
{
    unsigned short port = ui->port->text().toUShort();
    mServer->listen(QHostAddress::Any, port);
    ui->startListenBtn->setEnabled(false);  //把开始监听按钮禁用
}


void MainWindow::on_sendBtn_clicked()
{
    QString msg = ui->sendText->toPlainText();
    mTcp->write(msg.toUtf8());
    ui->historyText->append("服务器say:" + msg);

    //清空消息编辑栏:
    ui->sendText->setText("");
}

