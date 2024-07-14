#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "teacher.h"
#include "student.h"
#include "mypushbutton.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void hungerSignel();

private:
    Teacher* t1;
    Student* s1;
};
#endif // WIDGET_H
