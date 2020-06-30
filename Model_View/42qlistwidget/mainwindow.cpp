#include "mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
        QLabel *label = new QLabel(this);
        label->setText(QString("hhhhhhhhhhhhhhhhhhhhhhhhhhhhh"));
        label->setFixedWidth(80);
        QListWidget * listWidget  = new QListWidget(this);
        listWidget->resize(200,100);
        listWidget->setMouseTracking(true);


        //   insert item  method 1
        new QListWidgetItem(QIcon(""),tr("firefox"),listWidget);
        new QListWidgetItem(QIcon(""),tr("firefox"),listWidget);
        new QListWidgetItem(QIcon(""),tr("firefox"),listWidget);
        new QListWidgetItem(QIcon(""),tr("firefox"),listWidget);
        new QListWidgetItem(QIcon(""),tr("firefox"),listWidget);

    //    // insert item  method 2
    //    listWidget->addItem(new QListWidgetItem(QIcon(":/Chrome.png"),tr("chrome")));
    //    listWidget->addItem(new QListWidgetItem(QIcon(":/Chrome.png"),tr("chrome")));
    //    listWidget->addItem(new QListWidgetItem(QIcon(":/Chrome.png"),tr("chrome")));
    //    listWidget->addItem(new QListWidgetItem(QIcon(":/Chrome.png"),tr("chrome")));
    //    listWidget->addItem(new QListWidgetItem(QIcon(":/Chrome.png"),tr("chrome")));

    //    insert item  method 3  lei si 2
    //    QListWidgetItem *newItem = new QListWidgetItem;
    //    newItem->setIcon(QIcon(""));
    //    newItem->setText(tr("Maxthon"));
    //    listWidget->insertItem(3,newItem);

    //    layout
        QHBoxLayout *layout = new QHBoxLayout;
        layout->addWidget(label);
        layout->addWidget(listWidget);
        setLayout(layout);


//        connect(listWidget, SIGNAL(currentTextChanged(QString)),
//                label, SLOT(setText(QString)));

        connect(listWidget,&QListWidget::currentTextChanged,label,&QLabel::setText);

}

MainWindow::~MainWindow()
{

}
