#include "widget.h"
#include <QPushButton>
#include <QDebug>

#include "mypushbutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton;

    btn->setParent(this);

    btn->setText("第一个按钮");

    QPushButton* btn2 = new QPushButton("第2个窗口", this);

    btn2->move(50, 50);

    //resize(600, 400);

    setFixedSize(600, 400);

    setWindowTitle("第一个窗口");

    MyPushButton* bn3 = new MyPushButton(this);
    //bn3->setParent(this);
    bn3->setText("第3个按钮");
    bn3->move(60, 80);

    connect(bn3, &MyPushButton::clicked, this, &QWidget::close);



}

Widget::~Widget() {
    qDebug() << "widget的析构调用";
}
