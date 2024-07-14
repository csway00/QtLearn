#ifndef ITEMFROM_H
#define ITEMFROM_H

#include <QMainWindow>

namespace Ui {
class ItemFrom;
}

class ItemFrom : public QMainWindow
{
    Q_OBJECT

public:
    explicit ItemFrom(QWidget *parent = nullptr);

    ItemFrom(int id, QString name, int age, QString address, double salary);

    void setStaff(int id, QString name, int age, QString address, double salary);
    ~ItemFrom();

private:
    Ui::ItemFrom *ui;
};

#endif // ITEMFROM_H
