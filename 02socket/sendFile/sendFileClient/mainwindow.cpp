#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->ip->setText("127.0.0.1");
    ui->port->setText("9899");

    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);

    QThread* t = new QThread;
    SendFile* work = new SendFile;

    work->moveToThread(t);

    connect(this, &MainWindow::startConnect, work, &SendFile::connectServer);

    connect(work, &SendFile::connectedOK, this, [=]() {
        QMessageBox::information(this, "连接服务器", "连接服务器已经成功!");
    });


    connect(this, &MainWindow::sendFilePath, work, &SendFile::sendFile);

    connect(work, &SendFile::sendProgressVal, ui->progressBar, &QProgressBar::setValue);

    //发送完毕, 释放资源
    connect(work, &SendFile::alreadyOver, this, [=]() {
        t->quit();
        t->wait();
        t->deleteLater();
        work->deleteLater();
        QMessageBox::information(this, "结束", "已经结束列!");

    });




    //启动线程
    t->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectServerBtn_clicked()
{
    QString ip = ui->ip->text();
    unsigned short port = ui->port->text().toUShort();

    emit this->startConnect(ip, port);
}


void MainWindow::on_chooseFileBtn_clicked()
{
    QString path = QFileDialog::getOpenFileName();

    if (path.isEmpty()) {
        QMessageBox::information(this, "文件不存在", "抱歉, 文件不存在, 请重试");
        return;
    }

    ui->path->setText(path);
}


void MainWindow::on_sendFileBtn_clicked()
{
    emit sendFilePath(ui->path->text());
}

