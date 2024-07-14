#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

    void on_sendBtn_clicked();

    void on_connectBtn_clicked();


    void on_disConnectBtn_clicked();

private:
    Ui::MainWindow *ui;

    int mPort = 8990;
    QString mIp = "127.0.0.1";

    QTcpSocket* mTcp;

    QLabel* mStatus;
};
#endif // MAINWINDOW_H
