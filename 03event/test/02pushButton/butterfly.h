#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QWidget>
#include <QDebug>

class ButterFly : public QWidget
{
    Q_OBJECT
public:
    explicit ButterFly(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent* ev);
    void timerEvent(QTimerEvent* ev);

    void mousePressEvent(QMouseEvent* ev);
    void mouseMoveEvent(QMouseEvent* ev);
    void enterEvent(QEvent* ev);


private:
    QPixmap mPix;

    int mIndex;

    QPoint mPoint;

    void fly(int _min, int _max);

signals:
};

#endif // BUTTERFLY_H
