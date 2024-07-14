#include "teacher.h"

Teacher::Teacher(QObject *parent)
    : QObject{parent}
{}


void Teacher::classOver2() {
    emit hungry();
}
