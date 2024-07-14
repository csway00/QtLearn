#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QMediaPlayer>
// #include <TimeEdit>
#include <Qtimer>
#include <QDateTime>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void paintEvent(QPaintEvent *event);


    QMediaPlayer *player = new QMediaPlayer;



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
