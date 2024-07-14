#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/github/OIP-C.jfif"));

    QMovie *movie = new QMovie(":/github/earth.gif");
    ui->labelGif->setMovie(movie);
    movie->start();

}

Widget::~Widget()
{
    delete ui;
}
