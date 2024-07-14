#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //设置默认界面
    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->btnToolBox, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btnScrollArea, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(1);
    });

    connect(ui->btnRadio, &QPushButton::clicked, this, [=](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    int i = 0;
    //设置循环切换
    connect(ui->btnSwitch, &QPushButton::clicked, this, [&](){
        i = (i+1) % 3;
        ui->stackedWidget->setCurrentIndex(i);
    });


    ui->comboBox->addItem("奔驰");
    ui->comboBox->addItem("宝马");
    ui->comboBox->addItem("拖拉机");

    //点击按钮 选中拖拉机选项
    connect(ui->btnSelect,&QPushButton::clicked,[=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("拖拉机");
    });

    ui->label->setPixmap(QPixmap(":/R-C.png"));
    ui->label->setPixmap(QPixmap(":/OIP-C.jfif"));


}

Widget::~Widget()
{
    delete ui;
}
