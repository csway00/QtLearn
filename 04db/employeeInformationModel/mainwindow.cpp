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
    //使用QSqlQueryModel来高效的查询数据库操作
    //[1]创建QSqlQueryModel对象，并设置相关的表头信息
    QSqlQueryModel* queryModel = new QSqlQueryModel;

    //执行sqL语句，将查询出来的结果转换成model对象
    queryModel->setQuery("select * from staff;");
    //根据需求设置表头的信息
    queryModel->setHeaderData(0, Qt::Horizontal, "id");
    queryModel->setHeaderData(1, Qt::Horizontal, "name");
    queryModel->setHeaderData(2, Qt::Horizontal, "age");
    queryModel->setHeaderData(3, Qt::Horizontal, "address");
    queryModel->setHeaderData(4, Qt::Horizontal, "salary");

    //给ui控件设置一个模型
    QTableView* view = new QTableView(ui->centralwidget);
    view->setFixedSize(QSize(this->width(), this->height()));
    view->setModel(queryModel);

    view->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

