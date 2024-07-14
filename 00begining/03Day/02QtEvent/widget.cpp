#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLabel>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    id1 = startTimer(1000); //1000毫秒

    id2 = startTimer(2000); //2000ms

    QTimer* timer = new QTimer(this);
    timer->start(500);

    connect(timer, &QTimer::timeout, this, [=](){
        static int num3 = 1;
        ui->timeLabel3->setText(QString::number(num3++));
    });

    //给label1 安装事件过滤器
    // 步骤1  安装事件过滤器
    ui->label->installEventFilter(this);

}

//步骤2, 重写步骤过滤事件
bool Widget::eventFilter(QObject *watched, QEvent *event) {
    if (watched == ui->label) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent* ev = static_cast<QMouseEvent*>(event);
            QString str = QString("事件过滤器-----鼠标按下了, x = %1, y = %2\n").arg(ev->x()).arg(ev->y());
            QString str2 = QString("globalX = %1,globalY = %2").arg(ev->globalX()).arg(ev->globalY());

            qDebug() << str << str2;
            return true;
        }

    }
    //加下来的交给父类处理
    return QWidget::eventFilter(watched, event);
}


Widget::~Widget()
{
    delete ui;
}

void Widget::timerEvent(QTimerEvent *e) {
    static int num = 1, num2 = 1;
    if (e->timerId() == id1) {
        ui->timeLabel->setText(QString::number(num++));
    }

    if (e->timerId() == id2) {
        ui->timeLabel2->setText(QString::number(num2++));
    }
}
