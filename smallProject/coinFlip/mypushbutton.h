#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QPropertyAnimation>

#include "coinflip.h"

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QPushButton *parent = nullptr);

    //normalImg 代表正常显示的图片
    //pressImg 代表按下后显示的图片，默认为空
    MyPushButton(QString normalImg,QString pressImg = "");
    QString normalImgPath; //默认显示图片路径
    QString pressedImgPath; //按下后显示图片路径

    //zoom1 与 zoom2 为 MyPushButton 中扩展的特效代码，具体如下;
    void zoom1();
    void zoom2();

    void mousePressEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);



signals:
};

#endif // MYPUSHBUTTON_H
