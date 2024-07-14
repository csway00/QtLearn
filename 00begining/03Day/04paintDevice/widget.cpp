#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // //QPixmap;

    // QPixmap pix(300, 300);
    // pix.fill(Qt::white);
    // QPainter painter = QPainter(&pix);

    // painter.drawEllipse(100, 100, 50, 50);

    // pix.save("F:/ellipse.jpg");

       //Pixmap绘图设备 专门为平台做了显示的优化
       // QPixmap pix(300,300);

       // //填充颜色
       // pix.fill(Qt::white);

       // //声明画家
       // QPainter painter(&pix);
       // painter.setPen(QPen(Qt::green));
       // painter.drawEllipse(QPoint(150,150) , 100,100);
       // //保存
       // pix.save("E:\\pix.png");

    //QPicture 绘图设备  可以记录和重现 绘图指令
    // QPicture pic;
    // QPainter painter;
    // painter.begin(&pic);  //开始往pic上画
    // painter.setPen(QPen(Qt::cyan));
    // painter.drawEllipse(QPoint(150,150) , 100,100);
    // painter.end(); //结束画画

    // //保存到磁盘
    // pic.save("E:\\pic.zt");

}

void Widget::paintEvent(QPaintEvent *event) {

    // QPixmap pix(300, 300);
    // pix.fill(Qt::white);
    // QPainter painter = QPainter(&pix);

    // painter.drawEllipse(100, 100, 50, 50);

    // pix.save("F:/ellipse.jpg");

    QPixmap pix(400, 400);
       QPainter painter(&pix);

       //利用QImage 对像素进行修改
       QImage img;
       img.load(":/github/OIP-C.jfif");

       //修改像素点
       for(int i = 100 ;i < 200 ; i++)
       {
           for(int j = 50 ; j < 100;j++)
           {
               QRgb value = qRgb(255,0,0);
               img.setPixel(i,j,value);
           }
       }

       painter.drawImage(0,0,img);
       pix.save("F:/Qimag.png");


    // QPainter painter(this);
    // //重现QPicture的绘图指令
    // QPicture pic;
    // pic.load("E:\\pic.zt");
    // painter.drawPicture(0,0,pic);
}

Widget::~Widget()
{
    delete ui;
}
