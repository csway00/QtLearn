#include "student.h"
#include <QDebug>

Student::Student(QObject *parent)
    : QObject{parent}
{}

void Student::treat() {
    qDebug() << "学生请吃饭";
}

void Student::treat(char* food) {
     //qDebug() << "学生请吃饭, 老师想吃:" << food.toUtf8().data();
     qDebug() << "学生请吃饭, 老师想吃:" << food;
}
