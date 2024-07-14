#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

#include "smallwidget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btnGetValue, &QPushButton::clicked, this, [=](){
        qDebug() << ui->widget->getNum();
    });

    connect(ui->btnSetValue, &QPushButton::clicked, this, [=](){
        //ui->btnGetValueSmallWidget::setNum(50);
        ui->widget->setNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}
