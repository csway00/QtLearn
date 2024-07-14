#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    st = new Student;
    tc = new Teacher;

    connect(tc, &Teacher::hungry, st, &Student::trat);

    // classOver();
    tc->classOver2();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void classOver();
void MainWindow::classOver() {
    emit tc->hungry();
}
