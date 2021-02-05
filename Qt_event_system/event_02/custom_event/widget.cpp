#include "widget.h"
#include "my_qevent.h"

#include <QDebug>
#include <QKeyEvent>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::customEvent(QEvent *event)
{
    if(event->type() == MY_QEVENT_DATA){
        MyQEvent * event = static_cast<MyQEvent *>(event);
        // do something
        qDebug() << "处理自定义事件";
    }
}

bool Widget::event(QEvent *event)
{
    if(event->type() == MY_QEVENT_DATA){
        MyQEvent * event = static_cast<MyQEvent *>(event);
        // do something
        qDebug() << "处理自定义事件";
        return true;
    }
    return QWidget::event(event);
}
