#include "widget.h"



/*
案例下课后，老师触发饿了信号，学生响应信号，请客吃饭
*/
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->t1 = new Teacher(this);
    this->s1 = new Student(this);


    // connect(t1, &Teacher::hunger, s1, &Student::treat);

    // this->hungerSignel();


    //有参构造
    void (Teacher::*hungerP)(char*) = &Teacher::hunger;
    void (Student::*treatP)(char*) = &Student::treat;

    //connect(t1, hungerP, s1, treatP);
    //this->hungerSignel();

    //创建按钮
    QPushButton* myBn = new MyPushButton;
    myBn->setText("我字节的按钮");
    myBn->setParent(this);
    this->resize(600, 400);

    //点击按钮, 触发下课
    //connect(myBn, &QPushButton::clicked, this, &Widget::hungerSignel);

    //无参信号和槽连接
    void (Teacher::*hungerP2)(void) = &Teacher::hunger;
    void (Student::*treatP2)(void) = &Student::treat;

    // connect(t1, hungerP2, s1, treatP2);
    // connect(myBn, &QPushButton::clicked, t1, hungerP2);

    //connect(myBn, &QPushButton::clicked, this, &Widget::close);

    //QT4版本的写法
    //connect(myBn, SIGNAL(clicked), this, SLOT(close));
    //connect(zt,SIGNAL(hungry()) , st , SLOT(treat()));
    // connect(t1, SIGNAL(Teacher::hunger()), s1, SLOT(Student::treat()));
    // connect(myBn, SIGNAL(clicked()), t1, SLOT(treat()));


    //断开连接
    //disconnect(t1, hungerP2, s1, treatP2);
    //disconnect(myBn, &QPushButton::clicked, t1, hungerP2);
    //connect( 信号的发送者， 发送的信号SIGNAL( 信号) ，信号接受者， 槽函数SLOT(槽函数) )

    QPushButton *bn2 = new QPushButton("按钮2", this);
    bn2->move(50, 70);
    connect(t1, hungerP, s1, treatP);
    connect(bn2, &QPushButton::clicked, this, [=](){
        //this->close();
        this->hungerSignel();
    });



}


Widget::~Widget() {}

void Widget::hungerSignel(){
    //emit t1->hunger();

    emit t1->hunger("宫保鸡丁");
}
