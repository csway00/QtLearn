#include "mypushbutton.h"

/*F:\Desktop\QTCode\begining\8\mypushbutton.cpp:3: error: no declaration matches 'MyPushButton::MyPushButton(QWidget*)'
F:\Desktop\QTCode\begining\8\mypushbutton.cpp:3:1: error: no declaration matches 'MyPushButton::MyPushButton(QWidget*)'
    3 | MyPushButton::MyPushButton(QWidget* parent)
      | ^~~~~~~~~~~~*/
MyPushButton::MyPushButton(QWidget* parent)
    : QPushButton(parent){}
