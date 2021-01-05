#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include "a.h"
#include "b.h"
#include "mywidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyWidget *myWidget = new MyWidget(this); //mainwindows is parent
    myWidget->resize(200,200);

    A *a = new A();
    a->setParent(myWidget); // myWidget is parent
    a->move(50,50);
    a->setText("A_Button");

    B *b = new B();
    b->setParent(myWidget); // myWidget is parent
    b->move(100,100);
    b->setText("B_Button");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "Press MainWindow";

}

