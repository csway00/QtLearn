#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyPushButton* mbtn = new MyPushButton(":/hook.png", ":/revoke.jpg", ":/revoke.png");
    mbtn->setParent(this);

    /*\
MyPushButton * startBtn = new
MyPushButton(":/res/MenuSceneStartButton.png");
startBtn->setParent(this);
startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height()
*0.7);
*
*/

}

MainWindow::~MainWindow()
{
    delete ui;
}
