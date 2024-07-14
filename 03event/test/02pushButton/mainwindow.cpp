#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //MyPushButton* btn = new MyPushButton(this);

    //去边框
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

    //设置窗口透明
    setAttribute(Qt::WA_TranslucentBackground);

    //窗口最大化显示
    showMaximized();

    for (int i = 0; i < 100; i++) {
        ButterFly* butter = new ButterFly(this);
        butter->move(QRandomGenerator::global()->bounded(this->width()),
                     QRandomGenerator::global()->bounded(this->height())
            );
        butter->show();

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
