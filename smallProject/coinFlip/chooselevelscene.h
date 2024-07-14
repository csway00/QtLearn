#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QLabel>
#include <QFont>
#include <QSound>

#include "coinflip.h"
#include "mypushbutton.h"
#include "playscene.h"

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    void chooseLevelBtn();





    PlayScene *pScene = NULL;

    //选择关卡按钮音效
    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav",this);

    //返回按钮音效
    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);



signals:
    void chooseSceneBack1();
};

#endif // CHOOSELEVELSCENE_H
