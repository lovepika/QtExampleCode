//#include "mainwindow.h"
#include <QApplication>
#include <QStandardItemModel>
#include <QTreeView>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    // 创建标准项模型
    QStandardItemModel model;
    // 获取模型的根项，根项是不可见的
    QStandardItem *parentItem = model.invisibleRootItem();

    // 创建标准项item0，并设置显示文字，图标和工具提示
    QStandardItem *item0 = new QStandardItem;
    item0->setText("A");
    QPixmap pixmap0(50,50);
    pixmap0.fill("red");
    item0->setIcon(QIcon(pixmap0));
    item0->setToolTip("indexA");

    // 将创建的标准项作为根项的子项
    parentItem->appendRow(item0);

    //将创建的item0作为新的父项
    parentItem = item0;

    // 创建新的子项item1，他将作为item0的子项
    QStandardItem *item1 = new QStandardItem;
    item1->setText("B");
    QPixmap pixmap1(50,50);
    pixmap1.fill("blue");
    item1->setIcon(QIcon(pixmap1));
    item1->setToolTip("indexB");
    parentItem->appendRow(item1);

    // 创建新的标准项，这里使用setData的方式来设置文本，图标，工具提示
    QStandardItem *item2 = new QStandardItem;
    QPixmap pixmap2(50,50);
    pixmap2.fill(Qt::green);
    item2->setData("C",Qt::EditRole);
    item2->setData("indexC",Qt::ToolTipRole);
    item2->setData(QIcon(pixmap2),Qt::DecorationRole);
    parentItem->appendRow(item2);

    // 在树视图中显示模型
    QTreeView view;
    view.setModel(&model);
    view.show();

    // 获取item0的索引并输出item0的子项数目.
    QModelIndex indexA = model.index(0,0,QModelIndex());
    qDebug() << "indexA row count: " << model.rowCount(indexA);
    // 获取获取item1的索引并输出item1的信息.
    QModelIndex indexB = model.index(0,0,indexA);
    qDebug() << "indexB text :" << model.data(indexB,Qt::EditRole).toString();
    qDebug() << "indexB Icon :" << model.data(indexB,Qt::DecorationRole).value<QIcon>();// 设置的ICON就需要取QIcon
    qDebug() << "indexB ToolTip :" << model.data(indexB,Qt::ToolTipRole).toString();

    //获取获取item2的索引并输出item2的信息.
    QModelIndex indexC =  model.index(1,0,indexA);
    qDebug() << "indexC text :" << model.data(indexC,Qt::EditRole).toString();
    qDebug() << "indexC Icon :" << model.data(indexC,Qt::DecorationRole).value<QIcon>();
    qDebug() << "indexC ToolTip :" << model.data(indexC,Qt::ToolTipRole).toString();

    return app.exec();
}

// output
/**
indexA row count:  2
indexB text : "B"
indexB Icon : QIcon(availableSizes[normal,Off]=(QSize(50, 50)),cacheKey=0x200000000)
indexB ToolTip : "indexB"
indexC text : "C"
indexC Icon : QIcon(availableSizes[normal,Off]=(QSize(50, 50)),cacheKey=0x300000000)
indexC ToolTip : "indexC"
*/







#if 0
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
#endif
