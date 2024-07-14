#include "student.h"

Student::Student(QObject *parent)
    : QObject{parent}
{

}

void Student::trat() {
    qDebug() << "该吃饭了";
}
