#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setFixedSize(480, 700);
    this->setWindowTitle("计时器");

    connect(&timer, &QTimer::timeout, this,  timeoutSlot);

    time.setHMS(0, 0, 0, 0);
    ui->Timelabel->setText("00:00:00.000");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timeoutSlot() {
    //qDebug() << "text";
    //ui->Timelabel->setText(QString::number(text++));
    time = time.addMSecs(30);
    ui->Timelabel->setText(time.toString("hh:mm:ss.zzz"));
}

void Widget::on_startBtn_clicked()
{
    timer.start(30);
}


void Widget::on_closeBtn_clicked()
{
    timer.stop();
}


void Widget::on_resetBtn_clicked()
{
    timer.stop();
    time.setHMS(0, 0, 0, 0);
    ui->Timelabel->setText("00:00:00.000");

    ui->timeBrowser->clear();
    count = 0;
}


void Widget::on_recordBtn_clicked()
{
    ui->timeBrowser->append(QString::number(count++));
    ui->timeBrowser->append(time.toString("hh:mm:ss.zzz"));
}

