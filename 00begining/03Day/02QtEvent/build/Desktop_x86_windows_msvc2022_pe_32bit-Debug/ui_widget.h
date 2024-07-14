/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    MyLabel *label;
    QLabel *timeLabel;
    QLabel *timeLabel2;
    QLabel *timeLabel3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        label = new MyLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 80, 421, 51));
        label->setFrameShape(QFrame::Box);
        timeLabel = new QLabel(Widget);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(60, 180, 571, 81));
        timeLabel->setFrameShape(QFrame::Box);
        timeLabel2 = new QLabel(Widget);
        timeLabel2->setObjectName(QString::fromUtf8("timeLabel2"));
        timeLabel2->setGeometry(QRect(60, 290, 571, 81));
        timeLabel2->setFrameShape(QFrame::Box);
        timeLabel3 = new QLabel(Widget);
        timeLabel3->setObjectName(QString::fromUtf8("timeLabel3"));
        timeLabel3->setGeometry(QRect(60, 410, 571, 81));
        timeLabel3->setFrameShape(QFrame::Box);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QString());
        timeLabel->setText(QString());
        timeLabel2->setText(QString());
        timeLabel3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
