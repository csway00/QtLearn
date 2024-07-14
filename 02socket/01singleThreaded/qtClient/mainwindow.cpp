#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHostAddress>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("TCP-客户端");

    ui->port->setText(QString::number(mPort));
    ui->ip->setText(mIp);

    ui->connectBtn->setEnabled(true);
    ui->disConnectBtn->setEnabled(false);

    mTcp = new QTcpSocket(this);

    //检测是否有服务器数据
    connect(mTcp, &QTcpSocket::readyRead, this, [=]() {
        //接受数据
        QString recvMsg = mTcp->readAll();
        ui->historyText->append("服务器say:" + recvMsg);
    });

    connect(mTcp, &QTcpSocket::disconnected, this, [=](){
        mTcp->close();
        mStatus->setPixmap(QPixmap(":/fork.jpg").scaled(30, 30));
        ui->historyText->append("已经和服务器断开连接...");

        ui->connectBtn->setEnabled(true);
        ui->disConnectBtn->setEnabled(false);
    });

    connect(mTcp, &QTcpSocket::connected, this, [=](){
        mStatus->setPixmap(QPixmap(":/hook.png").scaled(30, 30));
        ui->historyText->append("已经和服务器连接...");

        ui->connectBtn->setEnabled(false);
        ui->disConnectBtn->setEnabled(true);
    });


    mStatus = new QLabel;
    mStatus->setPixmap(QPixmap(":/fork.jpg").scaled(30, 30));

    ui->statusbar->addWidget(new QLabel("连接状态:"));
    ui->statusbar->addWidget(mStatus);

    ui->connectBtn->setEnabled(true);
    ui->disConnectBtn->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_sendBtn_clicked()
{
    QString msg = ui->sendText->toPlainText();
    mTcp->write(msg.toUtf8());
    ui->historyText->append("客户端say:" + msg);

    //清空消息编辑栏:
    ui->sendText->setText("");
}


void MainWindow::on_connectBtn_clicked()
{
    unsigned port = ui->port->text().toUShort();
    QString ip = ui->ip->text();
    mTcp->connectToHost(QHostAddress(ip), port);

    //ui->connectBtn->setEnabled(false);
}

void MainWindow::on_disConnectBtn_clicked()
{
    mTcp->close();
    ui->connectBtn->setEnabled(true);
    ui->disConnectBtn->setEnabled(false);

}

