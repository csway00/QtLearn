#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // GenerateRand* gen = new GenerateRand;

    // connect(this, &MainWindow::starting, gen, &GenerateRand::recvNum);


    // connect(ui->startBtn, QPushButton::clicked, this, [=](){ //启动子进程
    //     emit starting(10000);
    //     gen->start();


    // });

    //接收数据
    // connect(gen, &GenerateRand::sendArray, this, [=](QVector<int> vec){
    //     for (int i = 0; i < vec.size(); i++) {
    //         ui->randList->addItem(QString::number(vec[i]));
    //     }
    // });


}

MainWindow::~MainWindow()
{
    delete ui;
}
