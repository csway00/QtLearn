#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //[1]根据数据库类型来连接数据

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("company.db");
    //[2］打开数据库
    if (!db.open()) {
        qDebug() << "error falied to open" << db.lastError();
    }
    //[3］根据需求，创建数据库所需要表
#if 0
    QSqlQuery query;

    QString sqlDrop = QString("drop table if exists staff");
    if (!query.exec(sqlDrop)) {
        qDebug() << "sqlDrop error" << db.lastError();
    }

    //创建表格
    QString sqlCreate = QString("create table staff(id integer primary key autoincrement,"
                                "name varchar,"
                                "age int,"
                                "address varchar,"
                                "salary double)");
    if (!query.exec(sqlCreate)) {
        qDebug() << "create error" << db.lastError();
    }

    //增
    QString sqlInsert = QString("insert into staff(id, name, age, address, salary)"
                                " values(0, 'zhangsan', 17, 'shangdong', 6000)");
    if (!query.exec(sqlInsert)) {
        qDebug() << "sqlInsert error" << db.lastError();
    }

    sqlInsert = QString("insert into staff( name, age, address, salary)"
                        " values( 'zhangsan', 17, 'shangdong', 6000)");
    if (!query.exec(sqlInsert)) {
        qDebug() << "sqlInsert error" << db.lastError();
    }

    sqlInsert = QString("insert into staff( name, age, address, salary)"
                        " values( 'zhangsan', 17, 'shangdong', 6000)");
    if (!query.exec(sqlInsert)) {
        qDebug() << "sqlInsert error" << db.lastError();
    }

    sqlInsert = QString("insert into staff( name, age, address, salary)"
                        " values( 'zhangsan', 17, 'shangdong', 6000)");
    if (!query.exec(sqlInsert)) {
        qDebug() << "sqlInsert error" << db.lastError();
    }

#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertBtn_clicked()
{
    QString name = ui->nameEdit->text();
    QString age = ui->ageEdit->text();
    QString address = ui->addressEdit->text();
    QString salary = ui->salaryEdit->text();

    QSqlQuery query;
    QString sqlInsert = QString("insert into staff(name, age, address, salary)"
                                " values('%1', '%2', '%3', '%4');").arg(name)
                            .arg(age.toInt())
                            .arg(address)
                            .arg(salary.toDouble());

    if (!query.exec(sqlInsert)) {
        qDebug() << "sqlInsert error" << db.lastError();
    }

    //更新数据
    this->on_selecBtn_clicked();
}


void MainWindow::on_deleteBtn_clicked()
{
    QSqlQuery query;
    QString id = ui->idEdit->text();

    if (id == "") {
        QMessageBox msgBox;
        msgBox.setText("请输入要删除的id");
        msgBox.exec();
        return;
    }
    id.toInt();

    QString sqlDelete = QString("delete from staff where id = '%1';").arg(id);

    if (!query.exec(sqlDelete)) {
        qDebug() << "sqlDelete error" << db.lastError();
    }

    //删除控件中相应的数据
    //ui->listWidget->takeItem(id);
    this->on_selecBtn_clicked();
}


void MainWindow::on_selecBtn_clicked()
{
    ui->listWidget->clear();
    QSqlQuery query;
    QString sqlSelect = QString("select * from staff;");
    if (!query.exec(sqlSelect)) {
        qDebug() << "sqlSelect error" << db.lastError();
    } else {
        while (query.next()) {

            int id = query.value("id").toInt();
            QString name = query.value("name").toString();
            int age = query.value("age").toInt();
            QString address = query.value("address").toString();
            double salary = query.value("salary").toDouble();

            qDebug() << id << ", " << name << ", " << age << ", "
                     << address << ", " << salary;

            //ItemFrom* staffItem = new ItemFrom(id, name, age, address, salary);
            ItemFrom* staffItem = new ItemFrom;
            staffItem->setStaff(id, name, age, address, salary);
            //staffItem->setParent(this);

            QListWidgetItem *item = new QListWidgetItem;
            item->setSizeHint(staffItem->size());
            //item->setSizeHint(QSize(1096, 54));

            ui->listWidget->addItem(item);
            ui->listWidget->setItemWidget(item, staffItem);
        }
    }

}


void MainWindow::on_updateBtn_clicked()
{
    QSqlQuery query;

    QString name = ui->nameEdit->text();
    QString age = ui->ageEdit->text();
    QString address = ui->addressEdit->text();
    QString salary = ui->salaryEdit->text();
    QString id = ui->idEdit->text();

    if (id == "") {
        QMessageBox msgBox;
        msgBox.setText("请输入要更改的id");
        msgBox.exec();
        return;
    }
    id.toInt();

    qDebug() << name << ", " << age << ", " << address
             << ", " << salary << ", " << id;

    /*update 表名 set 字段名1=值1,字段名2=值2,字段名3=值3... where 条件;*/
    if (name != "") {
        QString sqlUpdate = QString("update staff set name = '%1' where id = '%2';")
                                .arg(name).arg(id);
        if (!query.exec(sqlUpdate)) {
            qDebug() << "sqlUpdate error" << db.lastError();
        }
    }

    if (address != "") {
        QString sqlUpdate = QString("update staff set address = '%1' where id = '%2';")
                                .arg(address).arg(id);
        if (!query.exec(sqlUpdate)) {
            qDebug() << "sqlUpdate error" << db.lastError();
        }
    }

    if (age != "") {
        QString sqlUpdate = QString("update staff set age = '%1' where id = '%2';")
                                .arg(age.toInt()).arg(id);
        if (!query.exec(sqlUpdate)) {
            qDebug() << "sqlUpdate error" << db.lastError();
        }
    }

    if (salary != "") {
        QString sqlUpdate = QString("update staff set salary = '%1' where id = '%2';")
                                .arg(salary.toDouble()).arg(id);
        if (!query.exec(sqlUpdate)) {
            qDebug() << "sqlUpdate error" << db.lastError();
        }
    }
    this->on_selecBtn_clicked();

}

