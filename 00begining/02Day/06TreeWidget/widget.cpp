#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    /*

    heroL1 << "刚被猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    heroL2 << "船长" << "前排坦克，能肉能输出能控场的全能英雄";

    heroM1 << "月骑" << "中排物理输出，可以使用分裂利刃攻击多个目标";
    heroM2 << "小鱼人" << "前排战士，擅长偷取敌人的属性来增强自身战力";

    heroZ1 << "死灵法师" << "前排法师坦克，魔法抗性较高，拥有治疗技能";
    heroZ2 << "巫医" << "后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友";
*/
    ui->setupUi(this);
    ui->treeWidget->setHeaderLabels(QStringList() << "英雄" << "介绍");

    QTreeWidgetItem *power = new QTreeWidgetItem(QStringList() << "power");
    QTreeWidgetItem *agile = new QTreeWidgetItem(QStringList() << "agile");
    QTreeWidgetItem *intelligence = new QTreeWidgetItem(QStringList() << "intelligence");

    ui->treeWidget->addTopLevelItem(power);
    ui->treeWidget->addTopLevelItem(agile);
    ui->treeWidget->addTopLevelItem(intelligence);

    //力量型选手
    QStringList heroL1, heroL2;
    heroL1 << "刚被猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    heroL2 << "船长" << "前排坦克，能肉能输出能控场的全能英雄";
    QTreeWidgetItem *power1 = new QTreeWidgetItem(heroL1);
    QTreeWidgetItem *power2 = new QTreeWidgetItem(heroL2);

    power->addChild(power1);
    power->addChild(power2);

    //敏捷型选手
    QStringList heroM1, heroM2;
    heroM1 << "月骑" << "中排物理输出，可以使用分裂利刃攻击多个目标";
    heroM2 << "小鱼人" << "前排战士，擅长偷取敌人的属性来增强自身战力";
    QTreeWidgetItem *agile1 = new QTreeWidgetItem(heroM1);
    QTreeWidgetItem *agile2 = new QTreeWidgetItem(heroM2);

    agile->addChild(agile1);
    agile->addChild(agile2);


}

Widget::~Widget()
{
    delete ui;
}
