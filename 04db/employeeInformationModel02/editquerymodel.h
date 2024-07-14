#ifndef EDITQUERYMODEL_H
#define EDITQUERYMODEL_H

#include <QSqlQueryModel>
#include <QDebug>

class EditQueryModel : public QSqlQueryModel
{
public:
    explicit EditQueryModel(QObject *parent = nullptr);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);


    bool setName(int useId, const QString& name);

    bool setAge(int useId, int age);

    bool setAddress(int useId, const QString& address);

    bool setSalary(int useId, double salary);



    void refresh();




};

#endif // EDITQUERYMODEL_H
