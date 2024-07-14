#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qDebug() << "服务器主线程:" << QThread::currentThread();

    ui->setupUi(this);
    ui->port->setText("9899");

    mServer = new QTcpServer(this);
    setWindowTitle("TCP-服务端");

    connect(mServer, &QTcpServer::newConnection, this, [=]() {
        mTcp = mServer->nextPendingConnection();
        ReadFile* t = new ReadFile(mTcp);
        t->start();

        connect(t, &ReadFile::over, this, [=]() {
            t->quit();
            t->wait();
            t->deleteLater();
            QMessageBox::information(this, "接受数据完毕", "服务端接收数据完毕");
        });
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startListenBtn_clicked()
{
    unsigned short port = ui->port->text().toUShort();
    mServer->listen(QHostAddress::Any, port);
}

