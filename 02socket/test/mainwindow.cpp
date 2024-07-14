#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //发送后缀名:
    /*
QString  str;
char*  ch;
QByteArray ba = str.toLatin1(); // must
ch=ba.data();
*/

    QString path = "abcd.pdf";
    char* dot;
    QByteArray ba = path.toLatin1();
    dot = ba.data();
    // 自右向左查找‘.’字符, 如不存在返回NULL
    // dot = strrchr(name, '.');
    // if (dot == NULL)
    //     return "text/plain; charset=utf-8";
    // if (strcmp(dot, ".html") == 0 || strcmp(dot, ".htm") == 0)

    dot = strrchr(dot, '.');
    qDebug() << "后缀名: " << dot << " ,size = " << strlen(dot);

    fileTest();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileTest() {
    /*
    QFile* file = new QFile("recv.txt");
    file->open(QFile::WriteOnly);

    //接受数据
    connect(mTcp, &QTcpSocket::readyRead, this, [=]() {
        qDebug() << "开始接收数据";
        static int cnt = 0;
        static int total = 0;

        char* suffixName = "";


        if (!cnt) {
            mTcp->read((char*)&total, 4);
            mTcp->read(suffixName, 20);  //客户端是写了20字节过来;
            file->rename("recv"+suffixName);
        }
*/
    QFile *file = new QFile("recv.txt");
    file->open(QFile::WriteOnly);

    char* ch = ".pdf";

}
