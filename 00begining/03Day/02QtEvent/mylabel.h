#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

    void enterEvent(QEvent* event);

    void leaveEvent(QEvent* event);


    virtual void mouseMoveEvent(QMouseEvent *ev);

    virtual void  mousePressEvent(QMouseEvent *ev);

    virtual void mouseReleaseEvent(QMouseEvent *ev);



    //通过event事件分发器 拦截 鼠标按下事件
    bool event(QEvent *e);



signals:
};

#endif // MYLABEL_H
