#include "server.h"
#include "my_qevent.h"

#include <QDebug>
#include <QEvent>


Server::Server(QObject *parent)
    : QObject(parent)
{
}

Server::~Server()
{

}

void Server::customEvent(QEvent *event)
{
    if(event->type() == MY_QEVENT_DATA){
        MyQEvent *event = static_cast<MyQEvent *>(event);
        // do something
        qDebug() << event->getData();
        qDebug() << "处理自定义事件";
    }
}

bool Server::event(QEvent *event)
{
    if(event->type() == MY_QEVENT_DATA){
        MyQEvent * event = static_cast<MyQEvent *>(event);
        qDebug() << event->getData();
        // do something
        qDebug() << "处理自定义事件";
        return true;
    }
    return QObject::event(event);
}
