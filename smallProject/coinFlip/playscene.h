#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <iostream>
#include <QSound>
#include <QTextBrowser>
#include <QTimer>
#include <QTime>

#include <signal.h>
#include <sys/types.h>
#include <unistd.h>    //close head file
//#include <sys/wait.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>


#include "coinflip.h"
#include "playscene.h"
#include "mycoin.h"
#include "dataconfig.h"


class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    PlayScene(int index);

    void back();

    void showCurrentLevel();

    void setCoinBackground();

    void initArray();

    void initCoin(int, int);

    void delayFlipAround(MyCoin * coin);

    void printArray(); //测试数据

    void judgeWin();

    void showWin(QLabel* &label, QString );

    void showResultPicture(QLabel*);

    // void replay();

    // void revoke();

    void gameRule();

    void disabledCoinBtn();


    void timing();  //开始计时
    QTime time;
    QTimer timer, outTimer;
    QLabel timeLabel;
    void overtime(); //超时处理

    void isTimeout();










    //定义变量
    //成员变量 记录关卡索引
    int levalIndex;
    int gameArray[4][4]; //二维数组数据

    MyCoin * coinBtn[4][4]; //金币按钮数组

    bool isWin = true; //是否胜利

    QLabel* winLabel = NULL; //胜利的图片;
    QLabel* defeatLabel = NULL;

    bool startClickFlag = false;

    //返回按钮音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);

    //翻金币音效
    QSound *flipSound = new QSound(":/res/ConFlipSound.wav",this);
    //胜利按钮音效
    QSound *winSound = new QSound(":/res/LevelWinSound.wav",this);






signals:
    void chooseSceneBack();

    void myTimeout();
};

#endif // PLAYSCENE_H
