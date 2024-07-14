#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QMessageBox>
#include <QFileDialog>

#include "sendfile.h"

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
    void on_connectServerBtn_clicked();

    void on_chooseFileBtn_clicked();

    void on_sendFileBtn_clicked();

private:
    Ui::MainWindow *ui;

signals:
    void startConnect(QString ip, unsigned short port);

    void sendFilePath(QString path);
};
#endif // MAINWINDOW_H
