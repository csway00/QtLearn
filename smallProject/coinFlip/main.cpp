#include "mainscene.h"

#include <QApplication>

#include "dataconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //dataConfig();  //测似数据

    MainScene w;
    w.show();
    return a.exec();
}
