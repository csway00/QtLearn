#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QPushButton * btn = new QPushButton("游戏规则", this);

    QTextBrowser *textBrowser = new QTextBrowser(this);
    textBrowser->setText("当我们点击一个金币时, 它将翻转, 同时,"
                         "它上下左右四个方向的金币也会跟着翻转,"
                         "我们需要将所有金币都翻成金色, 即为胜利!");

    textBrowser->resize(300, 150);
    textBrowser->move(100, 100);
    textBrowser->hide();
    connect(btn, &QPushButton::clicked, this, [=](){
        qDebug() << textBrowser->isVisible();
        if (textBrowser->isVisible() == false) {
            textBrowser->show();
            //textBrowser->setVisible(true);
            qDebug() << textBrowser->isVisible() << " ---------";
        }
        else {
            //textBrowser->setVisible(false);
            textBrowser->hide();
            qDebug() << " ---------"  << textBrowser->isVisible() ;
        }

    });

    //TimeEdit

    // 创建计时器对象
    QTimer *timer = new QTimer(this);
    // 设置定时器精度为毫秒级别
    //timer.setTimerType(Qt::PreciseTimer);

    // 启动定时器，间隔设为1毫秒
    timer->start(1);
    QLabel *label = new QLabel(this);

    connect(timer, &QTimer::timeout, this, [=](){
        static int num = 0;
        label->setText(QString::number(num++));
        label->move(100, 0);
        label->show();


    });

    // 定义起始时间和当前时间变量
    // qint64 startTime = QDateTime::currentMSecsSinceEpoch();
    // qint64 currentTime;
    // // 连接定时器的timeout()信号到槽函数
    // QObject::connect(&timer, &QTimer::timeout, [&]() {
    //     currentTime = QDateTime::currentMSecsSinceEpoch();
    //     qDebug() << "经过时间(ms):" << (currentTime - startTime);
    // });







}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    //QPixmap pix("F:\\Desktop\\QTCode\\smallProject\\coinFlip\res\\LevelCompletedDialogBg.png");

    // QPixmap pix(":/res/LevelCompletedDialogBg.png");

    // QPainter painter(this);

    // painter.drawPixmap(50, 50, pix);
}
