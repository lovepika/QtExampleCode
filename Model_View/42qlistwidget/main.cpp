#include "mainwindow.h"
#include <QApplication>

#include <QTableWidget>
#include <QTableWidgetItem>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



// ==========
// TreeWidget
// ==========
    QTreeWidget treewidget;
    treewidget.setColumnCount(1);
    QStringList headers;
    headers << "name" << "Number";
    treewidget.setHeaderLabels(headers);
    QStringList rootTextList;
    rootTextList << "Root" << "0";
    // 树根
    QTreeWidgetItem *root = new QTreeWidgetItem(&treewidget,rootTextList);
    // 树杈1
    new QTreeWidgetItem(root,QStringList() << QString("leaf 1") << "1");
    // 树杈2
    QTreeWidgetItem *leaf2 = new QTreeWidgetItem(root,QStringList() << QString("leaf 2") << "2");
    leaf2->setCheckState(0,Qt::Checked);

    // 这是必须的东西
    QList<QTreeWidgetItem *> rootList;
    rootList << root;
    treewidget.insertTopLevelItems(0,rootList);

    treewidget.show();

    //
    // QTableWidget
    //

    QTableWidget tableWidget;
    tableWidget.setColumnCount(3);
    tableWidget.setRowCount(5);

    QStringList tableHeaders;
    tableHeaders << "ID" << "Name" << "Age" << "Sex";
    tableWidget.setHorizontalHeaderLabels(tableHeaders);
    // 在对应的单元格插入数据
    tableWidget.setItem(0,0,new QTableWidgetItem(QString("001")));
    tableWidget.setItem(1,0,new QTableWidgetItem(QString("001")));
    tableWidget.setItem(2,0,new QTableWidgetItem(QString("001")));
    tableWidget.setItem(3,0,new QTableWidgetItem(QString("001")));
    tableWidget.setItem(4,0,new QTableWidgetItem(QString("001")));
    tableWidget.setItem(0,1,new QTableWidgetItem(QString("001")));
    tableWidget.show();


    return a.exec();
}
