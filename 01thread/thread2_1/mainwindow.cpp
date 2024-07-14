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
    MyThread* th = new MyThread(this);  //挂上对象树, 自动回收

    th->mNum = mNum;
    connect(th, &MyThread::sendNum, this, [=](int num) {
        ui->label->setText(QString::number(num));
    });
    th->start();

}

