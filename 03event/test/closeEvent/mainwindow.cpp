#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>

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

void MainWindow::closeEvent(QCloseEvent* ev)
{
    int ret = QMessageBox::question(this, "提问", "确认关闭吗");
    if (ret == QMessageBox::Yes) {
        ev->accept();
    } else {
        ev->ignore();
    }
}

void MainWindow::resizeEvent(QResizeEvent *ev)
{
    qDebug() << "oldSize: " << ev->oldSize() << ", "
             << "当前size: " << ev->size();
}
