#include "mylabel.h"
#include <QDebug>
#include <QString>

MyLabel::MyLabel(QWidget *parent)
    : QLabel{parent}
{
    //设置鼠标追踪状态
    setMouseTracking(true);
}


void MyLabel::enterEvent(QEvent* event) {
    //qDebug() << "鼠标进入了";
}

void MyLabel::leaveEvent(QEvent* event) {
    //qDebug() << "鼠标离开了";
}

void  MyLabel::mousePressEvent(QMouseEvent *ev) {
    if (ev->button() == Qt::RightButton) {
        QString str = QString("鼠标按下了, x = %1, y = %2\n").arg(ev->x()).arg(ev->y());
        QString str2 = QString("globalX = %1,globalY = %2").arg(ev->globalX()).arg(ev->globalY());

         qDebug() << str << str2;
    }
}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev) {
    if (ev->button() == Qt::RightButton) {
        QString str = QString("鼠标释放了, x = %1, y = %2\n").arg(ev->x()).arg(ev->y());
        QString str2 = QString("globalX = %1,globalY = %2").arg(ev->globalX()).arg(ev->globalY());

        qDebug() << str << str2;
    }

}


void MyLabel::mouseMoveEvent(QMouseEvent *ev) {
    //if (ev->button() == Qt::RightButton) {
    //if (ev->buttons() & Qt::RightButton) {
        QString str = QString("鼠标移动了X = %1,globalY = %2").arg(ev->globalX()).arg(ev->globalY());
        QString str2 = QString("------, x = %1, y = %2\n").arg(ev->x()).arg(ev->y());

        qDebug() << str << str2;
    //}
}

//通过event事件分发器 拦截 鼠标按下事件
bool MyLabel::event(QEvent *e) {
    QMouseEvent* ev = static_cast<QMouseEvent*>(e);
    if (e->type() == QEvent::MouseButtonPress) {
        QString str = QString("evnet----鼠标按下了, x = %1, y = %2\n").arg(ev->x()).arg(ev->y());
        QString str2 = QString("globalX = %1,globalY = %2").arg(ev->globalX()).arg(ev->globalY());

        qDebug() << str << str2;
        return true;
    }

    //加下来的交给父类处理
    return QLabel::event(e);
}
