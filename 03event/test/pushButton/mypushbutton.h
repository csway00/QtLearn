#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QDebug>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    MyPushButton(QString normalImg, QString enterImg, QString pressImg);

private:
    //成员变量 normalImgPath 保存正常显示图片路径
    QString normalImgPath;
    //成员变量 pressedImgPath 保存按下后显示的图片
    QString pressedImgPath;

     QString enterImgPath;

protected:
    void mousePressEvent(QMouseEvent *event);

signals:

};

#endif // MYPUSHBUTTON_H
