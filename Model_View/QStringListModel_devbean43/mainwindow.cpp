#include "mainwindow.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>

// QStringListModel Demo
// https://www.devbean.net/2013/02/qt-study-road-2-qstringlistmodel/


MainWindow::MainWindow(QMainWindow *parent)
    : QMainWindow(parent)
{

    QStringList data;
    data << "Letter A" << "Letter B" << "Letter C";
    model = new QStringListModel(this);
    model->setStringList(data);
    //
    listView = new QListView(this);
    listView->setModel(model);

    //
    QHBoxLayout *btnLayout = new QHBoxLayout;
    QPushButton *insertBtn = new QPushButton(tr("insert"),this);
    connect(insertBtn, &QAbstractButton::clicked, this, &MainWindow::insertData);
    QPushButton *delBtn = new QPushButton(tr("Delete"),this);
    connect(delBtn, &QAbstractButton::clicked, this, &MainWindow::deleteData);
    QPushButton *showBtn = new QPushButton(tr("Show"),this);
    connect(showBtn, &QAbstractButton::clicked, this, &MainWindow::showData);

    //
    btnLayout->addWidget(insertBtn);
    btnLayout->addWidget(delBtn);
    btnLayout->addWidget(showBtn);
    //
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(listView);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);

}

MainWindow::~MainWindow()
{

}

void MainWindow::insertData()
{
    bool isOK;
        QString text = QInputDialog::getText(this, "Insert",
                                             "Please input new data:",
                                             QLineEdit::Normal,
                                             "You are inserting new data.",
                                             &isOK);
        if (isOK) {
            QModelIndex currIndex = listView->currentIndex();
            model->insertRows(currIndex.row(), 1); // 插入行
            model->setData(currIndex, text); // 设置数据
            listView->edit(currIndex); // 调用edit()函数，使这一行可以被编辑
        }

//    下面的写法过于冗余，但是函数的学习很不错
//    bool isOK;
//    QString text = QInputDialog::getText(this,
//                                         "Insert.",
//                                         "Please input data",
//                                         QLineEdit::Normal,
//                                         "You are inserting new data.",
//                                         &isOK);

//    if(isOK){
//        int row = listView->currentIndex().row();
//        model->insertRows(row,1);
//        QModelIndex index = model->index(row);
//        model->setData(index,text);
//        listView->setCurrentIndex(index);
//        listView->edit(index);
//    }

}

void MainWindow::deleteData()
{
    if(model->rowCount() > 1){
        model->removeRows(listView->currentIndex().row(),1);
    }

}

void MainWindow::showData()
{
    QStringList data = model->stringList();
    QString str;
    for(QString s:data){
        str += s + "\n";
    }
    QMessageBox::information(this,"data",str);
}
