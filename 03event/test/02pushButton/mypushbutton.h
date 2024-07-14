#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>

class MyPushButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent* ev);
    void mouseReleaseEvent(QMouseEvent* ev);
    void enterEvent(QEvent* ev);
    void leaveEvent(QEvent* ev);

    void paintEvent(QPaintEvent* ev);


private:
    QPixmap mPix;



signals:
};

#endif // MYPUSHBUTTON_H
