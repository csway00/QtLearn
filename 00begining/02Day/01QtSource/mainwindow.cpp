#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->actionopen->setIcon(QIcon("F:/picture/github/R-C.png"));
    ui->actionopen->setIcon(QIcon(":/new/prefix1/OIP-C.jfif"));

    ui->actionclose->setIcon(QIcon(":/new/prefix1/R-C.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
