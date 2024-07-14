#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "主线程地址:" << QThread::currentThread();


    //1. 创建子线程对象
    Generate* gen = new Generate;
    BubbleSort* buSort = new BubbleSort;
    QuickSort* quiSort = new QuickSort;

    QThread* t1 = new QThread;
    QThread* t2 = new QThread;
    QThread* t3 = new QThread;

    gen->moveToThread(t1);
    buSort->moveToThread(t2);
    quiSort->moveToThread(t3);


    connect(this, &MainWindow::starting, gen, &Generate::working);

    //2. 启动子线程
    connect(ui->startBtn, &QPushButton::clicked, this, [=](){
        emit starting(10000);
        t1->start();
    });

    //接受子线程发送的数据
    connect(gen, &Generate::sendArray, buSort, &BubbleSort::working);

    connect(gen, &Generate::sendArray, quiSort, &QuickSort::working); //在子线程中执行

    //以下的代码会在主线程中执行;,
    // connect(gen, &Generate::sendArray, this, [=](QVector<int> vec){
    //     quiSort->working(vec);
    //     buSort->working(vec);
    // });


    connect(gen, &Generate::sendArray, this, [=](QVector<int> v){
        t2->start();
        t3->start();
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


    //释放资源
    connect(this, &MainWindow::destroyed, this, [=]() {
        t1->quit();
        t1->wait();
        t1->deleteLater();

        t2->quit();
        t2->wait();
        t2->deleteLater();

        t3->quit();
        t3->wait();
        t3->deleteLater();

        gen->deleteLater();
        quiSort->deleteLater();
        buSort->deleteLater();

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


