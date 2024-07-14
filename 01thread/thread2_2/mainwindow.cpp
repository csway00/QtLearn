#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_startBtn_clicked()
{
    // emit starting(); //主线程发送开始信号;

    qDebug() << "主线程地址:" << QThread::currentThread();

    MyThread* work = new MyThread;
    QThread* t1 = new QThread;

    work->moveToThread(t1);
    t1->start();

    //以下注释的代码会在主线程中执行, 造成程序卡顿
    // connect(ui->startBtn, &QPushButton::clicked, this, [=](){

    //     work->working();

    //     //connect(this, &MainWindow::starting, work, &MyThread::working);

    // });




    //connect(ui->startBtn, &QPushButton::clicked, work, &MyThread::working);


    connect(this, &MainWindow::starting, work, &MyThread::working);

    emit starting(); //主线程发送开始信号;

    connect(work, &MyThread::sendNum, this, [=](int num) {
        ui->label->setText(QString::number(num));
    });




    //释放资源
    connect(this, &MainWindow::destroyed, this, [=]() {
        t1->quit();
        t1->wait();
        t1->deleteLater();


        work->deleteLater();
        work->deleteLater();
        work->deleteLater();
        qDebug() << "资源已释放";

    });


}


