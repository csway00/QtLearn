#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLabel>
#include <QPixmap>


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



private slots:
    void on_startListenBtn_clicked();

    void on_sendBtn_clicked();

private:
    Ui::MainWindow *ui;

    QTcpServer* mServer;

    int mPort = 8990;

    QTcpSocket* mTcp;

    QLabel* mStatus;
};
#endif // MAINWINDOW_H
