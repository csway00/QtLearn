#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //1. 创建子线程对象
    Generate* gen = new Generate;
    BubbleSort* buSort = new BubbleSort;
    QuickSort* quiSort = new QuickSort;

    connect(this, &MainWindow::starting, gen, &Generate::recvNum);

    //2. 启动子线程
    connect(ui->startBtn, &QPushButton::clicked, this, [=](){
        emit starting(10000);
        gen->start();
    });

    //接受子线程发送的数据
    connect(gen, &Generate::sendArray, buSort, &BubbleSort::recvVec);
    connect(gen, &Generate::sendArray, quiSort, &QuickSort::recvVec);

    connect(gen, &Generate::sendArray, this, [=](QVector<int> v){
        buSort->start();
        quiSort->start();
        for (auto& x : v)  {
            ui->randList->addItem(QString::number(x));
        }
    });


    //显示排序结果
    connect(buSort, &BubbleSort::finish, this, [=](QVector<int> v){

        for (auto& x : v)  {
            ui->bubbleList->addItem(QString::number(x));
        }
    });

    connect(quiSort, &QuickSort::finish, this, [=](QVector<int> v){

        for (auto& x : v)  {
            ui->quickList->addItem(QString::number(x));
        }
    });




}

MainWindow::~MainWindow()
{
    delete ui;
}


