#include "chooselevelscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    //设置窗口固定大小
    this->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("选择关卡");
    //创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("菜单");
    //创建按钮菜单项
    QAction * quitAction = startMenu->addAction("退出");
    //点击退出 退出游戏
    connect(quitAction,&QAction::triggered,[=](){this->close();});

    QAction * backAction = startMenu->addAction("返回");
    connect(backAction,&QAction::triggered,[=](){
        this->hide();
        //触发自定义信号，关闭自身，该信号写到 signals 下做声明

        emit this->chooseSceneBack1();
    });

    //返回按钮
    MyPushButton * closeBtn = new
        MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());

    //返回按钮功能实现
    connect(closeBtn,&MyPushButton::clicked,[=](){
        QTimer::singleShot(CLICK_DELAY, this,[=](){
            this->hide();
            //触发自定义信号，关闭自身，该信号写到 signals 下做声明

            emit this->chooseSceneBack1();
        });
    });

    chooseLevelBtn();






}



void ChooseLevelScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap( (this->width() -
                        pix.width())*0.5,30,pix.width(),pix.height(),pix);

}

void ChooseLevelScene::chooseLevelBtn() {
    //创建关卡按钮
    for(int i = 0 ; i < 20;i++)
    {
        MyPushButton * menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
         menuBtn->move(25 + (i%4)*70 , 130+ (i/4)*70);
        //menuBtn->move(100 + (i%4)*70 , 250+ (i/4)*70);
        //按钮上显示的文字
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());

        QFont font ("Microsoft YaHei", 10, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
        label->setFont(font);

        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter); //设置居中
        label->move(25 + (i%4)*70 , 130+ (i/4)*70);
        label->setAttribute(Qt::WA_TransparentForMouseEvents,true); //鼠标事件穿透

        //监听选择关卡按钮的信号槽
        connect(menuBtn,&MyPushButton::clicked,[=](){
            // qDebug() << "select: " << i;
            if(pScene == NULL) //游戏场景最好不用复用，直接移除掉创建 新的场景
            {
                this->hide();

                pScene = new PlayScene(i+1); //将选择的关卡号 传入给PlayerScene
                pScene->setGeometry(this->geometry());
                pScene->show();


                //选中关卡后，播放音效
                chooseSound->play();


                //这里为什么要写在connect里面;
                ///PlayScene的返回按钮监听，删除该scene并且将指针指向空
                connect(pScene,&PlayScene::chooseSceneBack,[=](){
                    //分别在点击返回按钮后，播放该音效
                    backSound->play();
                    this->setGeometry(pScene->geometry());
                    delete pScene;
                    pScene = NULL;
                    this->show();

                });

            }
        });

    }

}
