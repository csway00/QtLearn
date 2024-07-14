#include "mypushbutton.h"

#include <QPainter>

MyPushButton::MyPushButton(QWidget *parent)
    : QWidget{parent}
{
    mPix.load("://hook.png");
    setFixedSize(mPix.size());
}

void MyPushButton::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    mPix.load("://btn.jpg");
    update();
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev)
    mPix.load("://hook.png");
    update();

}

void MyPushButton::enterEvent(QEvent *ev)
{
    Q_UNUSED(ev)
    mPix.load("://5ad09c880654c_610.jpg");
    update();
}

void MyPushButton::leaveEvent(QEvent *ev)
{
    Q_UNUSED(ev)
    mPix.load("://hook.png");
    update();
}

void MyPushButton::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev)
    QPainter p(this);
    p.drawPixmap(rect(), mPix);
}


