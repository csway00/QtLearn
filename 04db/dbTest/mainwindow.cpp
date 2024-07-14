#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("test.db");

    if (!db.open()) {
        qDebug() << "error falied to open" << db.lastError();
    } else {
        qDebug() << "打开成功";
    }

    // QStringList list = QSqlDatabase::drivers();
    // qDebug() << list;

    QSqlQuery query;

    QString dropSql = QString("drop table if exists staff");
    query.exec(dropSql);


    //数据库创建
    QString creatSql01 = QString("create table staff ("
                                 "id integer primary key autoincrement, "
                                 "name varchar(20),"
                                 "age int);");   //autoincrement
    query.exec(creatSql01);


    QString sqlInsert = QString("insert into staff("
                                "id, name, age)"
                                " values(0, 'lisi', 18);");
    if (!query.exec(sqlInsert)) {
        qDebug() << "insert data error" << db.lastError();
    }

    sqlInsert = QString("insert into staff("
                        "id, name, age)"
                        " values(2, '张三', 18);");
    if (!query.exec(sqlInsert)) {
        qDebug() << "insert data error" << db.lastError();
    }


    sqlInsert = QString("insert into staff(id, age)"
                        "values(1, 18);");
    if (!query.exec(sqlInsert)) {
        qDebug() << "insert data error" << db.lastError();
    }


    // QString sqlSelect = QString("select * from staff");
    // if (!query.exec(sqlSelect)) {
    //     qDebug() << "select data error" << db.lastError();
    // } else {
    //     while (query.next()) {
    //         qDebug() << "id: " << query.value("id").toInt();
    //         qDebug() << "name: " << query.value("name").toString();
    //         qDebug() << "age: " << query.value("age").toInt();
    //         qDebug() << "-------------------------";
    //     }
    // }

    // QString sqlDelect = QString("delete from staff where id = 1;");
    // if (!query.exec(sqlDelect)) {
    //     qDebug() << "delect data error" << db.lastError();
    // }

    //更新数据
    QString sqlUpdate = QString("update staff set name = 'zhangsan', age = 22 where id = 2");
    if (!query.exec(sqlUpdate)) {
        qDebug() << "sqlUpdate data error" << db.lastError();
    }

    QString sqlSelect = QString("select * from staff");
    if (!query.exec(sqlSelect)) {
        qDebug() << "select data error" << db.lastError();
    } else {
        while (query.next()) {
            // qDebug() << "id: " << query.value("id").toInt();
            // qDebug() << "name: " << query.value("name").toString();
            // qDebug() << "age: " << query.value("age").toInt();
            // qDebug() << "-------------------------";
            ui->idLabel->setText(QString::number( query.value("id").toInt() ) );
            ui->nameLabel->setText(query.value("name").toString());
            ui->ageLabel->setText(QString::number( query.value("age").toInt() ) );
        }
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}
