#include "editquerymodel.h"

#include <QSqlQuery>

EditQueryModel::EditQueryModel(QObject *parent)
    : QSqlQueryModel{parent}
{}

Qt::ItemFlags EditQueryModel::flags(const QModelIndex &index) const
{
    //1. 获取当前单元格可编辑的状态;
    Qt::ItemFlags flag = QSqlQueryModel::flags(index);

    if (index.column() == 0) {  //id不可修改
        return flag;
    }

    //2.设置为可编辑状态
    flag |= Qt::ItemIsEditable;

    return flag;
}

bool EditQueryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //[1]判断是否为有效列 员工表 --id 用户名 年龄 地址 薪资
    if (index.column() < 1 || index.column() > 4) {
        return false;
    }

    //[2]获取列所对应的id
    QModelIndex prinmaryIndex = QSqlQueryModel::index(index.row(), 0);
    int id = this->data(prinmaryIndex).toInt();


    //[3] 在修改前, 将数据清除, 将整个model清空;
    this->clear();
    bool ok;

    //[4]根据需求, 修改数据所对应的列
    int index2 = index.column();
    // qDebug() << "index2 = " << index2;

    switch (index2) {
    case 1:
        ok = setName(id, value.toString());
        break;
    case 2:
        ok = setAge(id, value.toInt());
        break;
    case 3:
        ok = setAddress(id, value.toString());
        break;
    case 4:
        ok = setSalary(id, value.toDouble());
        break;
    }

    //[5]刷新数据
    this->refresh();

    return ok;
}

bool EditQueryModel::setName(int useId, const QString &name)
{
    QSqlQuery query;
    query.prepare("update staff set name = ? where id = ?;");
    query.addBindValue(name);
    query.addBindValue(useId);

    return query.exec();
}

bool EditQueryModel::setAge(int useId, int age)
{
    QSqlQuery query;
    query.prepare("update staff set age = ? where id = ?;");
    query.addBindValue(age);
    query.addBindValue(useId);

    return query.exec();
}

bool EditQueryModel::setAddress(int useId, const QString &address)
{
    QSqlQuery query;
    query.prepare("update staff set address = ? where id = ?;");
    query.addBindValue(address);
    query.addBindValue(useId);

    return query.exec();
}

bool EditQueryModel::setSalary(int useId, double salary)
{
    QSqlQuery query;
    query.prepare("update staff set salary = ? where id = ?;");
    query.addBindValue(salary);
    query.addBindValue(useId);

    return query.exec();
}

void EditQueryModel::refresh()
{
    this->setQuery("select * from staff;");

    this->setHeaderData(0, Qt::Horizontal, "id");
    this->setHeaderData(1, Qt::Horizontal, "name");
    this->setHeaderData(2, Qt::Horizontal, "age");
    this->setHeaderData(3, Qt::Horizontal, "address");
    this->setHeaderData(4, Qt::Horizontal, "salary");
}
