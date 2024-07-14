#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QSound>
#include <QMediaPlayer>
#include <QSoundEffect>

#include "mypushbutton.h"
#include "chooselevelscene.h"
#include "coinflip.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainScene;
}
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();

    void paintEvent(QPaintEvent *);


    //选择关卡场景
    ChooseLevelScene *chooseScene = new ChooseLevelScene;


    //开始音效
    QSound *startSound = new QSound(":/res/TapButtonSound.wav",this);

    QSound *backgroundMusic = new QSound(":/res/y2086.wav",this);
    //QSoundEffect *backgroundMusic2 = new QSoundEffect(this);



private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
