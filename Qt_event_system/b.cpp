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
#if 1

    #if 0
        // 实验2
        e->accept();
    #endif
    #if 1
        // 实验3
        e->ignore();
    #endif

#endif
    qDebug() << "Press B";

}
