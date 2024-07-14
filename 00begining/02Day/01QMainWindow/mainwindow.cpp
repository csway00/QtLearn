#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 400);

    //菜单栏
    QMenuBar *bar = menuBar();

    setMenuBar(bar);

    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    fileMenu->addAction("新建");
    fileMenu->addSeparator();
    fileMenu->addAction("保存");

    QAction *newAction = editMenu->addAction("新建");
    editMenu->addSeparator();
    QAction* saveAction = editMenu->addAction("保存");

    //工具栏
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);
    //设置浮动
    toolBar->setFloatable(false);

    //设置移动 (总开关)
    toolBar->setMovable(false);

    toolBar->addAction(newAction);
    toolBar->addSeparator();
    toolBar->addAction(saveAction);

    QPushButton *btn = new QPushButton("视图", this);
    toolBar->addWidget(btn);

    //状态栏
    QStatusBar *staBar = statusBar();
    setStatusBar(staBar);

    QLabel * label = new QLabel("提示信息",this);
    staBar->addWidget(label);

    QLabel * label2 = new QLabel("右侧提示信息",this);
    staBar->addPermanentWidget(label2);

    //铆接部件 （浮动窗口） 可以有多个
    QDockWidget * dockWidget = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    //设置后期停靠区域，只允许上下
    dockWidget->setAllowedAreas( Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea );


    //设置中心部件 只能一个
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);

}

MainWindow::~MainWindow() {}
