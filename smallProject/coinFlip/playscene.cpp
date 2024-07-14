#include "playscene.h"

PlayScene::PlayScene(QWidget *parent)
    : QMainWindow{parent}
{}

PlayScene::PlayScene(int index)
{
    this->timing();
    //qDebug() << "当前关卡为"<< index;
    this->levalIndex = index;
    //设置窗口固定大小
    this->setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    //设置图标
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币");
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
        QTimer::singleShot(CLICK_DELAY, this,[=](){
            //分别在点击返回按钮后，播放该音效
            backSound->play();
            this->hide();

            //触发自定义信号，关闭自身，该信号写到 signals 下做声明
            emit this->chooseSceneBack();

        });
    });

    this->back();  //返回按钮

    // this->replay();

    // this->revoke();

    this->gameRule();


    this->showCurrentLevel();

    initArray();

    this->setCoinBackground();

    //printArray();  //测试
}

void PlayScene::initArray() {
    //初始化二维数组
    dataConfig config;
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            gameArray[i][j] = config.mData[this->levalIndex][i][j];
        }
    }
}

void PlayScene::setCoinBackground() {
    this->showWin(winLabel ,":/res/LevelCompletedDialogBg.png");

    this->showWin(defeatLabel ,":/res/defeat3.png");

    // printArray();  //测试
    //创建金币的背景图片
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            //绘制背景图片
            QLabel* label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode.png"));
            label->setParent(this);
             label->move(57 + i*50,200+j*50);
            //label->move(140 + i*50,300+j*50);

            //金币对象
            initCoin(i, j);
        }
        //qDebug() << i ;
    }
}

void PlayScene::initCoin(int i, int j) {
    //qDebug() << "initCoin";
    //金币对象
    QString img;
    //std::cout << gameArray[i][j] << " ";
    if(gameArray[i][j] == 1)
    {
        img = ":/res/Coin0001.png";
    }
    else
    {
        img = ":/res/Coin0008.png";
    }
    MyCoin * coin = new MyCoin(img);
    coin->setParent(this);
    //coin->move(142 + i*50,304+j*50);
    coin->move(59 + i*50,204+j*50);
    coin->posX = i; //记录 x 坐标
    coin->posY = j; //记录 y 坐标
    coin->flag = gameArray[i][j]; //记录正反标志
    coinBtn[i][j] = coin;

    //金币点击功能实现
    connect(coin,&MyCoin::clicked,[=](){
        //this->startClickFlag = true;
        //qDebug() << "点击的位置： x = " << coin->posX << " y = " << coin->posY ;
        coin->changeFlag();
        gameArray[i][j] = gameArray[i][j] == 0 ? 1 : 0; //数组内 部记录的标志同步修改

        this->flipSound->play();

        this->delayFlipAround(coin);
    });

}

void PlayScene::showWin(QLabel* &label, QString path) {

    //胜利图片加载
    label = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(path);
    label->setGeometry(0,0,tmpPix.width(),tmpPix.height());
    label->setPixmap(tmpPix);
    label->setParent(this);

    label->move( (this->width() - tmpPix.width())*0.5 ,
                -tmpPix.height());
}

void PlayScene::judgeWin() {

    //判断是否胜利
    this->isWin = true;
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            //qDebug() << coinBtn[i][j]->flag ;
            if( coinBtn[i][j]->flag == false)
            {
                this->isWin = false;

                i = 5;  //退出双层循环
                break;
            }
        }
    }
    // 如果 isWin 依然是 true，代表胜利了！
    if(this->isWin)
    {
        timer.stop();
        //禁用点金币按钮
        //将所有按钮的胜利标志改为true；如果再次点击按钮，直接return,不做响应
        this->disabledCoinBtn();

        // //胜利图片加载
        this->defeatLabel = nullptr;
        this->showResultPicture(winLabel);
        this->winSound->play();
    }
}

void PlayScene::showResultPicture(QLabel* label) {
    if (label == NULL) {
        qDebug() << "label = nullptr";
        return;
    }

    //label->show();
    // 把胜利的图片显示出来
    // 创建动画对象
    QPropertyAnimation * animation1 = new QPropertyAnimation(label,"geometry");
    //设置时间间隔，单位毫秒
    animation1->setDuration(100);
    //创建起始位置
    animation1->setStartValue(QRect(label->x(),label->y(),label->width(),
                                    label->height()));

    //创建结束位置
    animation1->setEndValue(QRect(label->x(),label->y()+210,label->width(),
                                  label->height()));

    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始执行动画
    animation1->start();

}

void PlayScene::disabledCoinBtn() {
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            coinBtn[i][j]->isWin = true;
        }
    }
}


void PlayScene::delayFlipAround(MyCoin * coin) {
    if (coin == nullptr) {
        qDebug() << "delayFlipAround error";
        return;
    }

    QTimer::singleShot(300, this,[=](){
        if(coin->posX+1 <=3)  //右
        {
            coinBtn[coin->posX+1][coin->posY]->changeFlag();
            gameArray[coin->posX+1][coin->posY] =
                gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
        }
        if(coin->posX-1>=0) //左
        {
            coinBtn[coin->posX-1][coin->posY]->changeFlag();
            gameArray[coin->posX-1][coin->posY] =
                gameArray[coin->posX-1][coin->posY]== 0 ? 1 : 0;
        }
        if(coin->posY+1<=3) //下
        {
            coinBtn[coin->posX][coin->posY+1]->changeFlag();
            gameArray[coin->posX][coin->posY+1] =
                gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
        }
        if(coin->posY-1>=0) //上
        {
            coinBtn[coin->posX][coin->posY-1]->changeFlag();
            gameArray[coin->posX][coin->posY-1] =
                gameArray[coin->posX+1][coin->posY]== 0 ? 1 : 0;
        }

        judgeWin();
    });

}


void PlayScene::showCurrentLevel() {
    //当前关卡标题
    QLabel * label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str = QString("Leavel: %1").arg(this->levalIndex);
    //qDebug() << "str = " << str;
    label->setText(str);
    label->setGeometry(QRect(30, this->height() - 50,200, 50)); //设 置大小和位置
}

void PlayScene::back() {
    //返回按钮
    MyPushButton * closeBtn = new
        MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closeBtn->setParent(this);
    closeBtn->move(this->width()-closeBtn->width(),this->height()-closeBtn->height());

    //返回按钮功能实现
    connect(closeBtn,&MyPushButton::clicked,[=](){
        QTimer::singleShot(CLICK_DELAY, this,[=](){
            //分别在点击返回按钮后，播放该音效
            backSound->play();
            this->hide();

            //触发自定义信号，关闭自身，该信号写到 signals 下做声明
            emit this->chooseSceneBack();

        });
    });
}

// void PlayScene::replay() {
//     //replay按钮
//     MyPushButton * replayBtn = new
//         MyPushButton(":/res/replay.png");
//     replayBtn->setParent(this);
//     replayBtn->move(this->width()*0.5 - replayBtn->width()-5 ,this->height()*0.7);

//     //重玩按钮功能实现
//     connect(replayBtn,&MyPushButton::clicked,[=](){
//         //分别在点击返回按钮后，播放该音效
//         backSound->play();
//         this->hide();

//         //触发自定义信号，关闭自身，该信号写到 signals 下做声明
//         emit this->chooseSceneBack();

//         this->hide();

//         pScene = new PlayScene(i+1); //将选择的关卡号 传入给PlayerScene
//         pScene->setGeometry(this->geometry());
//         pScene->show();

//         // this->initArray();
//         // this->isWin = false;

//         // for(int i = 0 ; i < 4;i++)
//         // {
//         //     for(int j = 0 ; j < 4; j++)
//         //     {
//         //         //金币对象
//         //         delete this->coinBtn[i][j];
//         //         coinBtn[i][j] = NULL;
//         //         //initCoin(i, j);
//         //         //金币对象
//         //         MyCoin * coin = new MyCoin(":/res/Coin0001.png");
//         //         coin->setParent(this);
//         //         //coin->move(59 + i*50,204+j*50);
//         //         coin->move(142 + i*50,304+j*50);

//         //     }
//         //     //qDebug() << i ;
//         // }
//         // // this->printArray();

//         //  //this->setCoinBackground();
//     });
// }

// void PlayScene::revoke() {
//     //返回按钮
//     MyPushButton *revokeBtn = new
//         MyPushButton(":/res/revoke.png");
//     revokeBtn->setParent(this);
//     revokeBtn->move(this->width()*0.5 + 5,this->height()*0.7);
//     //revokeBtn->move(this->width()*0.5,this->height()*0.7);

//     //返回按钮功能实现
//     connect(revokeBtn,&MyPushButton::clicked,[=](){
//         QTimer::singleShot(CLICK_DELAY, this,[=](){
//             //分别在点击返回按钮后，播放该音效
//             backSound->play();
//             this->hide();

//             //触发自定义信号，关闭自身，该信号写到 signals 下做声明
//             emit this->chooseSceneBack();

//         });
//     });
// }

void PlayScene::gameRule() {
    //返回按钮
    MyPushButton *gameRuleBtn = new
        MyPushButton(":/res/gameRule.png");
    gameRuleBtn->setParent(this);
    gameRuleBtn->move(this->width() - gameRuleBtn->width() - 20,this->height()*0.1 - 10);
    //gameRuleBtn->move(this->width()*0.5,this->height()*0.7);

    //显示, 隐藏规则;

    QTextBrowser *textBrowser = new QTextBrowser(this);
    QFont font;
    //font.setFamily("华文新魏");
    font.setFamily("黑体");
    font.setPointSize(13);
    textBrowser->setFont(font);
    textBrowser->setText("当我们点击一个金币时, 它将翻转, 同时,"
                         "它上下左右四个方向的金币也会跟着翻转,"
                         "我们需要将所有金币都翻成金色, 即为胜利!\n"
                         "游戏限时1分钟, 超时即为失败!");
    textBrowser->resize(300, 150);
    textBrowser->move(this->width() * 0.5 - textBrowser->width() * 0.5, this->height()* 0.7);
    textBrowser->hide();

    connect(gameRuleBtn,&MyPushButton::clicked,[=](){
        //qDebug() << textBrowser->isVisible();
        if (textBrowser->isVisible() == false) {
            textBrowser->show();
            //qDebug() << textBrowser->isVisible() << " ---------";
        }
        else {
            textBrowser->hide();
            //qDebug() << " ---------"  << textBrowser->isVisible() ;
        }
    });
}


void PlayScene::paintEvent(QPaintEvent *)
{
    //加载背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //加载标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap( 10,30,pix.width(),pix.height(),pix);
}

void PlayScene::printArray() {
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            //gameArray[i][j] = config.mData[this->levalIndex][i][j];
            std::cout << gameArray[i][j] << " ";
        }
        std::cout << endl;
    }
    std::cout << endl;

}

void PlayScene::timing() {
    timer.start(10); //开始计时

    time.setHMS(0, 0, 0, 0);
    timeLabel.setText("00:00.000");
    QFont font;
    //font.setFamily("华文新魏");
    font.setFamily("黑体");
    font.setPointSize(20);
    timeLabel.setFont(font);

    timeLabel.setGeometry(QRect(this->width()*0.5, this->height()*0.2 - 50,165, 45)); //设 置大小和位置
    timeLabel.move(this->width()*0.5 - timeLabel.width() - 80, this->height()*0.8 + 20);

    //timeLabel.setFrameShape(QFrame::Box);
    timeLabel.setFrameShape(QFrame::Panel);
    timeLabel.setParent(this);
    timeLabel.show();
    connect(&timer, &QTimer::timeout, this, [=](){
        time = time.addMSecs(10);
        QString str = time.toString("mm:ss.zzz");
        //qDebug() << str ;
        timeLabel.setText(str);
        if (str == "01:00.000") {
            timer.stop();
            this->disabledCoinBtn();
            //qDebug() << "---失败-----";
            this->showResultPicture(defeatLabel);
        }
    });
}



