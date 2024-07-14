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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *Timelabel;
    QHBoxLayout *horizontalLayout;
    QPushButton *startBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *resetBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *recordBtn;
    QTextBrowser *timeBrowser;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(626, 387);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Timelabel = new QLabel(Widget);
        Timelabel->setObjectName(QString::fromUtf8("Timelabel"));
        QFont font;
        font.setPointSize(24);
        Timelabel->setFont(font);
        Timelabel->setLayoutDirection(Qt::RightToLeft);
        Timelabel->setFrameShape(QFrame::Box);
        Timelabel->setTextFormat(Qt::MarkdownText);
        Timelabel->setScaledContents(false);
        Timelabel->setAlignment(Qt::AlignCenter);
        Timelabel->setIndent(-1);

        verticalLayout->addWidget(Timelabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        startBtn = new QPushButton(Widget);
        startBtn->setObjectName(QString::fromUtf8("startBtn"));

        horizontalLayout->addWidget(startBtn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeBtn = new QPushButton(Widget);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));

        horizontalLayout->addWidget(closeBtn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        resetBtn = new QPushButton(Widget);
        resetBtn->setObjectName(QString::fromUtf8("resetBtn"));

        horizontalLayout->addWidget(resetBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        recordBtn = new QPushButton(Widget);
        recordBtn->setObjectName(QString::fromUtf8("recordBtn"));

        horizontalLayout->addWidget(recordBtn);


        verticalLayout->addLayout(horizontalLayout);

        timeBrowser = new QTextBrowser(Widget);
        timeBrowser->setObjectName(QString::fromUtf8("timeBrowser"));

        verticalLayout->addWidget(timeBrowser);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Timelabel->setText(QString());
        startBtn->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213", nullptr));
        closeBtn->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
        resetBtn->setText(QCoreApplication::translate("Widget", "\351\207\215\347\275\256", nullptr));
        recordBtn->setText(QCoreApplication::translate("Widget", "\346\211\223\347\202\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
