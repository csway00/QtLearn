#include "widget.h"


/*
需求:
写2个按钮, 一个打开窗口, 一个关闭窗口;
*/
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
     this->resize(400, 600);

      //MyPushButton *mybn = new MyPushButton;
     // mybn->setParent(this);
     //  mybn->setText("open");

     // this->setWindowTitle("main window");

    //  Widget w;
    // this->show();

     // Widget w2;
     // w2.show();



    //打开窗口的信号
    //connect(mybn, &MyPushButton::clicked, this, &Widget::close);

    // QPushButton* bn1 = new QPushButton;
    // bn1->setParent(this);
    // bn1->setText("close");
    // bn1->move(0, 60);

}

Widget::~Widget() {}
