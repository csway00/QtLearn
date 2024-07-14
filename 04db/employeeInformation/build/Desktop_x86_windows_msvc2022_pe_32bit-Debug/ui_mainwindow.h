/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *insertBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *deleteBtn;
    QSpacerItem *verticalSpacer_2;
    QPushButton *selecBtn;
    QSpacerItem *verticalSpacer_3;
    QPushButton *updateBtn;
    QSpacerItem *verticalSpacer_4;
    QListWidget *listWidget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *idEdit;
    QLabel *label_2;
    QLineEdit *nameEdit;
    QLabel *label_3;
    QLineEdit *addressEdit;
    QLabel *label_4;
    QLineEdit *salaryEdit;
    QLabel *label_5;
    QLineEdit *ageEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(835, 563);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        insertBtn = new QPushButton(widget);
        insertBtn->setObjectName(QString::fromUtf8("insertBtn"));

        verticalLayout->addWidget(insertBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        deleteBtn = new QPushButton(widget);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));

        verticalLayout->addWidget(deleteBtn);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        selecBtn = new QPushButton(widget);
        selecBtn->setObjectName(QString::fromUtf8("selecBtn"));

        verticalLayout->addWidget(selecBtn);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        updateBtn = new QPushButton(widget);
        updateBtn->setObjectName(QString::fromUtf8("updateBtn"));

        verticalLayout->addWidget(updateBtn);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);


        gridLayout->addWidget(widget, 0, 1, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        idEdit = new QLineEdit(widget_2);
        idEdit->setObjectName(QString::fromUtf8("idEdit"));

        horizontalLayout->addWidget(idEdit);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        nameEdit = new QLineEdit(widget_2);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        horizontalLayout->addWidget(nameEdit);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        addressEdit = new QLineEdit(widget_2);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));

        horizontalLayout->addWidget(addressEdit);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        salaryEdit = new QLineEdit(widget_2);
        salaryEdit->setObjectName(QString::fromUtf8("salaryEdit"));

        horizontalLayout->addWidget(salaryEdit);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        ageEdit = new QLineEdit(widget_2);
        ageEdit->setObjectName(QString::fromUtf8("ageEdit"));

        horizontalLayout->addWidget(ageEdit);


        gridLayout->addWidget(widget_2, 1, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 835, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        insertBtn->setText(QCoreApplication::translate("MainWindow", "\345\242\236", nullptr));
        deleteBtn->setText(QCoreApplication::translate("MainWindow", "\345\210\240", nullptr));
        selecBtn->setText(QCoreApplication::translate("MainWindow", "\346\237\245", nullptr));
        updateBtn->setText(QCoreApplication::translate("MainWindow", "\346\224\271", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\220\215\345\255\227", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\235\200", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\350\226\252\346\260\264", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\271\264\351\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
