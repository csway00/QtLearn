/********************************************************************************
** Form generated from reading UI file 'showtext.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWTEXT_H
#define UI_SHOWTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowText
{
public:

    void setupUi(QWidget *ShowText)
    {
        if (ShowText->objectName().isEmpty())
            ShowText->setObjectName(QString::fromUtf8("ShowText"));
        ShowText->resize(400, 300);

        retranslateUi(ShowText);

        QMetaObject::connectSlotsByName(ShowText);
    } // setupUi

    void retranslateUi(QWidget *ShowText)
    {
        ShowText->setWindowTitle(QCoreApplication::translate("ShowText", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowText: public Ui_ShowText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWTEXT_H
