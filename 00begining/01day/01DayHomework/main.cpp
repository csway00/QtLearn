#include "widget.h"

#include "qstring.h"
#include "qcollator.h"

#include <QApplication>
#include <string>
#include <QCollator>


//#include "qdbusconnection.h"

void func1() {
    //创建一个主窗口
    Widget *w2 = new Widget();

    MyPushButton *mybn = new MyPushButton;
    mybn->setParent(w2);
    mybn->setText("open");
    w2->setWindowTitle("main window");

    QPushButton* bn2 = new QPushButton("close", w2);
    bn2->move(0, 60);

    w2->show();

    //点击按钮后要弹出的窗口:
    Widget *w3 = new Widget();
    w3->setWindowTitle("clicking window");

    w3->connect(mybn, &QPushButton::clicked, w3, &Widget::show);

    w3->connect(bn2, &QPushButton::clicked, w3, &Widget::close);

    //w3.show();

    // Widget w2;
    // w2.show();
}

//有1个按钮
void func2() {
    //创建一个主窗口
    Widget *w2 = new Widget();

    MyPushButton *mybn = new MyPushButton;
    mybn->setParent(w2);
    w2->setWindowTitle("main window");

    w2->show();

    //点击按钮后要弹出的窗口:
    Widget *w3 = new Widget();
    w3->setWindowTitle("clicking window");

    //while (1) {
        mybn->setText("open");
        w3->connect(mybn, &QPushButton::clicked, w3, &Widget::show);  //弹出窗口
        w3->disconnect(mybn, &QPushButton::clicked, w3, &Widget::show);  //弹出窗口

        // w3->connect(mybn, &QPushButton::clicked, mybn, [=](){
        // mybn->setText("close");
        // });  //改变按钮文字
        // w3->disconnect(mybn, &QPushButton::clicked, mybn, [=](){
        //     mybn->setText("close");
        // });  //改变按钮文字

        w3->connect(mybn, &QPushButton::clicked, w3, &Widget::close);
    //}
}


void func3() {
    Widget *w1 = new Widget();
    w1->setWindowTitle("main window");
     Widget *w2 = new Widget();

    QPushButton *bn = new QPushButton("open", w1);
    w1->show();

    w1->connect(bn, &QPushButton::clicked, w1, [=](){
        if (bn->text() == "open") {
            w2->show();
            bn->setText("close");
        } else {
            w2->close();
            bn->setText("open");
        }
    });

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    func3();
    return a.exec();
}
