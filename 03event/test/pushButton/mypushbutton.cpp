#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent)
    : QPushButton{parent}
{}

MyPushButton::MyPushButton(QString normalImg, QString enterImg, QString pressImg)
{
    //成员变量 normalImgPath 保存正常显示图片路径
    normalImgPath = normalImg;
    //成员变量 pressedImgPath 保存按下后显示的图片
    pressedImgPath = pressImg;
    enterImgPath = enterImg;

    //创建 QPixmap 对象
    QPixmap pixmap;
    //判断是否能够加载正常显示的图片， 若不能提示加载失败
    bool ret = pixmap.load(normalImgPath);
    if(!ret)
    {
        qDebug() << normalImg << "加载图片失败!";
    } //设置图片的固定尺寸this->setFixedSize( pixmap.width(), pixmap.height() );
    //设置不规则图片的样式表
    this->setStyleSheet("QPushButton{border:0px;}");
    //设置图标
    this->setIcon(pixmap);
    //设置图标大小
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));

}



