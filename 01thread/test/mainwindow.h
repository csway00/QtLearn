#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Student.h"
#include "Teacher.h"

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

    void classOver();


    //
    Student *st ;
    Teacher *tc ;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
