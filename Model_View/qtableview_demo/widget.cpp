#include "widget.h"
#include "ui_widget.h"
#include <QStandardItemModel>
#include <QStringList>

#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "width:" << this->width() << "width:"  << this->height();
    ui->tableView->resize(this->width(),this->height());// 调整tableView窗口大小和父窗口一致
    ui->tableView->setShowGrid(true);  //背景网格线设置,默认也是 true
    ui->tableView->setGridStyle(Qt::DotLine); // 网格背景画笔
    ui->tableView->setSortingEnabled(true); // 排序功能

    // model
    QStandardItemModel *model = new QStandardItemModel(this);
    // 设置列表头
    QStringList label =QObject::tr("频率,功率,误差").simplified().split(",");
    // 这里要讲讲simplified()功能.
    // 这个函数把一个字符串首尾的空格全部清除，不管首尾是几个空格哦。
    // 字符串中间的空格（包括单个空格、多个空格、\t、\n）都统一转化成一个空格，
    // 这样就方便提取了，我们再使用split（）函数就能很好拆分了。
    model->setHorizontalHeaderLabels(label);

    //实现各表内容的填充
    QStandardItem *item = nullptr;
    for(int i = 0 ; i <10 ; ++i){
        // void setItem(int row, int column, QStandardItem *item);
        item = new QStandardItem(QString("%1").arg(i));
        model->setItem(i,0,item);
        item = new QStandardItem(QString("%1").arg(i*2));
        model->setItem(i,1,item);
        item = new QStandardItem(QString("%1").arg(i*3));
        model->setItem(i,2,item);
    }

    ui->tableView->setModel(model);

    ui->tableView->show();

}

Widget::~Widget()
{
    delete ui;
}
