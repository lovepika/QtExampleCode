#include "b.h"
#include <QDebug>

//B::B(QPushButton *parent):
//    A(parent)
//{

//}

B::B(){

}

void B::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "Press B";

}
