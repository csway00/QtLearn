/********************************************************************************
** Form generated from reading UI file 'itemfrom.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMFROM_H
#define UI_ITEMFROM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ItemFrom
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *idLabel;
    QLabel *label_4;
    QLabel *nameLabel;
    QLabel *label_5;
    QLabel *ageLabel;
    QLabel *label_8;
    QLabel *addressLabel;
    QLabel *label_9;
    QLabel *salaryLabel;

    void setupUi(QMainWindow *ItemFrom)
    {
        if (ItemFrom->objectName().isEmpty())
            ItemFrom->setObjectName(QString::fromUtf8("ItemFrom"));
        ItemFrom->resize(566, 41);
        centralwidget = new QWidget(ItemFrom);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        idLabel = new QLabel(centralwidget);
        idLabel->setObjectName(QString::fromUtf8("idLabel"));
        idLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        horizontalLayout->addWidget(idLabel);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        horizontalLayout->addWidget(nameLabel);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        ageLabel = new QLabel(centralwidget);
        ageLabel->setObjectName(QString::fromUtf8("ageLabel"));
        ageLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        horizontalLayout->addWidget(ageLabel);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        addressLabel = new QLabel(centralwidget);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));
        addressLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        horizontalLayout->addWidget(addressLabel);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout->addWidget(label_9);

        salaryLabel = new QLabel(centralwidget);
        salaryLabel->setObjectName(QString::fromUtf8("salaryLabel"));
        salaryLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        horizontalLayout->addWidget(salaryLabel);

        ItemFrom->setCentralWidget(centralwidget);

        retranslateUi(ItemFrom);

        QMetaObject::connectSlotsByName(ItemFrom);
    } // setupUi

    void retranslateUi(QMainWindow *ItemFrom)
    {
        ItemFrom->setWindowTitle(QCoreApplication::translate("ItemFrom", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ItemFrom", "id", nullptr));
        idLabel->setText(QString());
        label_4->setText(QCoreApplication::translate("ItemFrom", "\345\247\223\345\220\215", nullptr));
        nameLabel->setText(QString());
        label_5->setText(QCoreApplication::translate("ItemFrom", "\345\271\264\351\276\204", nullptr));
        ageLabel->setText(QString());
        label_8->setText(QCoreApplication::translate("ItemFrom", "\345\234\260\345\235\200", nullptr));
        addressLabel->setText(QString());
        label_9->setText(QCoreApplication::translate("ItemFrom", "\350\226\252\346\260\264", nullptr));
        salaryLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ItemFrom: public Ui_ItemFrom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMFROM_H
