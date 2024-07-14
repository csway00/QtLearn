#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(5);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "姓名" << "性别" << "年龄");

    //设置正文
    //ui->tableWidget->setItem(0, 0, new QTableWidgetItem("亚瑟") );
    QStringList nameList, sexList;
    nameList << "李白" << "韩信" << "花木兰" << "孙悟空" << "哪吒";
    sexList << "男" << "男" << "女" << "男" << "女";

    for (int i = 0; i < 5; i++) {
        int count = 0;
        ui->tableWidget->setItem(i,count++, new QTableWidgetItem(nameList[i]));
        ui->tableWidget->setItem(i,count++, new QTableWidgetItem(sexList[i]));
        ui->tableWidget->setItem(i,count++, new QTableWidgetItem(QString::number(i+18)));
    }

}

Widget::~Widget()
{
    delete ui;
}
