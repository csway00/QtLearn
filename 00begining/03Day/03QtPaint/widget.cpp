#include "widget.h"
#include "ui_widget.h"
#include <QPainter> //画家类
#include <QPushButton>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btnMove, &QPushButton::clicked, this, [=](){
        this->posX += 20;
        update();
    });

    //定时器第二种方式
    QTimer * timer = new QTimer(this);
    //启动定时器
    timer->start(200);

    connect(timer,&QTimer::timeout,[=](){
        this->posX += 20;
        update();
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event) {
    //QPainter painter = QPainter(this);
    //    //实例化画家对象  this指定的是绘图设备
    //    QPainter painter(this);

    //    //设置画笔
    //    QPen pen(QColor(255,0,0));
    //    //设置画笔宽度
    //    pen.setWidth(3);
    //    //设置画笔风格
    //    pen.setStyle(Qt::DotLine);
    //    //让画家 使用这个笔
    //    painter.setPen(pen);


       // //设置画刷
       // QBrush brush(Qt::cyan);
       // //设置画刷风格
       // brush.setStyle(Qt::Dense7Pattern);
       // //让画家使用画刷
       // painter.setBrush(brush);


       // //画线
       // painter.drawLine(QPoint(0,0) , QPoint(100,100));

       // //画圆 椭圆
       // painter.drawEllipse( QPoint(100,100) , 50,50);

       // //画矩形
       // painter.drawRect(QRect(20,20,50,50));

       // //画文字
       // painter.drawText(QRect(10,200,150,50) , "好好学习，天天向上");



    // //QPen pen(QColor(255,0,0));
    // QPen pen(Qt::red);
    //    //设置画笔宽度
    //    pen.setWidth(3);
    //    //设置画笔风格
    //    pen.setStyle(Qt::DotLine);
    //    //让画家 使用这个笔
    //    painter.setPen(pen);


    // painter.drawLine(0, 0, 400, 400);

    //    painter.drawText(QRect(10, 200, 150, 50), "temet, nosce");

    //////////////////////////////高级设置 ///////////////////////////////

       // QPainter painter(this);
       // painter.drawEllipse(QPoint(100,50) , 50,50);
       // //设置 抗锯齿能力  效率较低
       // painter.setRenderHint(QPainter::Antialiasing);
       // painter.drawEllipse(QPoint(200,50) , 50,50);


    //画矩形
    //    painter.drawRect(QRect(20,20,50,50));

    //    //移动画家
    //    painter.translate(100,0);

    //    //保存画家状态
    //    painter.save();

    //    painter.drawRect(QRect(20,20,50,50));

    //    painter.translate(100,0);

    //    //还原画家保存状态
    //    painter.restore();

    //    painter.drawRect(QRect(20,20,50,50));


    //画图片;
     QPainter painter(this);
    QPixmap pix = QPixmap(":/github/R-C.png");
    if (posX >= this->width()) {
         //posX = 0;
        posX = -pix.width();
     }
    painter.drawPixmap(posX, 50, pix);



}
