#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QListWidgetItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->radioButtonMan->setChecked(true);
    connect(ui->radioButtonWomen, &QRadioButton::clicked, this, [=](){
        qDebug() << "选中了女的";
    });

    //多选按钮  2是选中  0是未选中 1是半选
    connect(ui->checkBoxClear, &QCheckBox::stateChanged, this, [=](int stat){
        qDebug() << stat ;
    });

    //列表添加方式1;
    // QListWidgetItem* item1 = new QListWidgetItem("锄禾日当午");
    // QListWidgetItem* item2 = new QListWidgetItem("锄禾日当午");
    // QListWidgetItem* item3 = new QListWidgetItem("锄禾日当午");
    // ui->listWidget->addItem(item1);
    // ui->listWidget->addItem(item2);
    // ui->listWidget->addItem(item3);
    // item1->setTextAlignment(Qt::AlignHCenter);
    // item2->setTextAlignment(0x0004);

    //列表添加方式2;
    QStringList list;
    list << "锄禾日当午" << "锄禾日当午" << "锄禾日当午" << "锄禾日当午";
    ui->listWidget->addItems(list);



}

Widget::~Widget()
{
    delete ui;
}
