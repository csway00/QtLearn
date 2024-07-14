#include "butterfly.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QRandomGenerator>

ButterFly::ButterFly(QWidget *parent)
    : QWidget{parent}
{
    mIndex = 0;
    mPix.load(":/0");
    setFixedSize(mPix.size());

    startTimer(100);
}

void ButterFly::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);
    p.drawPixmap(rect(), mPix);
}

void ButterFly::timerEvent(QTimerEvent *ev)
{
    this->fly(10, 30);
}

void ButterFly::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton) {
        mPoint = ev->globalPos() - this->geometry().topLeft();
    }
}

void ButterFly::mouseMoveEvent(QMouseEvent *ev)
{
    if (ev->buttons() & Qt::LeftButton) {
    // if (ev->buttons()) { //崩溃
        this->move(ev->globalPos() - mPoint);
    }
}

void ButterFly::enterEvent(QEvent *ev)
{
    fly(-200, 200);
}

void ButterFly::fly(int _min, int _max)
{
    mIndex = (mIndex+1) % 2;

    //qDebug() << "mIndex:" << mIndex;

    QString name = QString(":/%1").arg(mIndex);
    mPix.load(name);
    update();

    int stepX = QRandomGenerator::global()->bounded(_min, _max);
    int stepY = QRandomGenerator::global()->bounded(_min, _max);

    int curX = this->geometry().topLeft().x() + stepX;
    int curY = this->geometry().topLeft().y() + stepY;

    QDesktopWidget* desk = QApplication::desktop();

    if (curX >= desk->screenGeometry().right()) {
        curX = desk->screenGeometry().left();
    }

    if (curY >= desk->screenGeometry().bottom()) {
        curY = desk->screenGeometry().top();
    }

    move(curX, curY);
}





