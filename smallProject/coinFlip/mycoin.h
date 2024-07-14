#ifndef MYCOIN_H
#define MYCOIN_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QPushButton *parent = nullptr);

    MyCoin(QString butImg);

    void changeFlag();//改变标志,执行翻转效果
    QTimer *timer1; //正面翻反面 定时器
    QTimer *timer2; //反面翻正面 定时器
    int min = 1; //最小图片
    int max = 8; //最大图片

    void connectFlip(); //监听操作

    void mousePressEvent(QMouseEvent *e);







    //成员变量
    int posX; //x 坐标
    int posY; //y 坐标
    bool flag; //正反标志

    bool isAnimation = false; //做翻转动画的标志

    bool isWin = false; //是否胜利, true为胜利


signals:
};

#endif // MYCOIN_H
