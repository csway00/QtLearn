#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //播放背景音乐;
    backgroundMusic->setLoops(-1); // 无限循环

    backgroundMusic->play();

    // //backgroundMusic2->setSource(QUrl::fromAce(":/res/y2086.wav"));
    // backgroundMusic2->setSource(QUrl(":/res/y2086.wav"));
    // //backgroundMusic2->setLoops(-1); // 无限循环
    // backgroundMusic2->setLoopCount(2);
    // backgroundMusic2->setVolume(50);

    // backgroundMusic2->play();


    //设置固定大小
    //this->setFixedSize(320,588);
    this->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT); //放大1.5倍

    //设置应用图片
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //设置窗口标题
    this->setWindowTitle("翻金币");

    //点击退出，退出程序
    connect(ui->actionQuit,&QAction::triggered,[=](){this->close();});

    //创建开始按钮
    MyPushButton * startBtn = new
        MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5-startBtn->width()*0.5,this->height() * 0.7);


    //监听点击事件，执行特效
    connect(startBtn,&MyPushButton::clicked,[=](){
        // startBtn->zoom1(); //向下跳跃
        // startBtn->zoom2(); //向上跳跃

        //点击开始按钮，播放音效
        startSound->play(); //开始音效

        //延时 0.05 秒后 进入选择场景
        QTimer::singleShot(CLICK_DELAY, this,[=](){
            this->hide();
            chooseScene->setGeometry(this->geometry());
            chooseScene->show();
        });

    });

    //监听选择场景的返回按钮
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack1,[=](){
        this->setGeometry(chooseScene->geometry());
        this->show();
    });





}

void MainScene::paintEvent(QPaintEvent *)
{
    //创建画家，指定绘图设备
    QPainter painter(this);
    //创建 QPixmap 对象
    QPixmap pix;
    //加载图片
    pix.load(":/res/PlayLevelSceneBg.png");
    //绘制背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/res/Title.png");
    //缩放图片
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    //绘制标题
    painter.drawPixmap( 10,30,pix.width(),pix.height(),pix);



}

MainScene::~MainScene()
{
    delete ui;
}
