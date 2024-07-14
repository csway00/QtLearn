#include "itemfrom.h"
#include "ui_itemfrom.h"

ItemFrom::ItemFrom(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ItemFrom)
{
    ui->setupUi(this);
}

ItemFrom::ItemFrom(int id, QString name, int age, QString address, double salary)
{
    ui->idLabel->setText(QString::number(id));
    ui->nameLabel->setText(name);
    ui->ageLabel->setText(QString::number(age));
    ui->addressLabel->setText(address);
    ui->salaryLabel->setText(QString::number(salary));
}

void ItemFrom::setStaff(int id, QString name, int age, QString address, double salary)
{
    ui->idLabel->setText(QString::number(id));
    ui->nameLabel->setText(name);
    ui->ageLabel->setText(QString::number(age));
    ui->addressLabel->setText(address);
    ui->salaryLabel->setText(QString::number(salary));
}

ItemFrom::~ItemFrom()
{
    delete ui;
}
