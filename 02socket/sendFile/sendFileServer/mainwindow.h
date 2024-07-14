#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QMessageBox>
#include <QThread>

#include "readfile.h"

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

private:
    Ui::MainWindow *ui;
    QTcpServer* mServer;

    QTcpSocket* mTcp;

};
#endif // MAINWINDOW_H
