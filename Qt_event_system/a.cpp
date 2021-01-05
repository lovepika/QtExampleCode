#include "a.h"
#include <QDebug>

//A::A(QPushButton * parent):
//    QPushButton(parent)
//{

//}

A::A(){

}

void A::mousePressEvent(QMouseEvent *e)
{
//    Q_UNUSED(e);
    qDebug() << "Press A";
}
