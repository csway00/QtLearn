#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <qpushbutton.h>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QPushButton *parent = nullptr);

signals:
};

#endif // MYPUSHBUTTON_H
