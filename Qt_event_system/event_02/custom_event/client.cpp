#include "client.h"
#include "my_qevent.h"
#include <QCoreApplication>


Client::Client(QObject *parent) : QObject(parent)
{

}

void Client::callFunc(Server *server)
{
    // event
    unsigned char cmd = 0x1;
    const char *pDate = "hello world";
    unsigned int data_size = (unsigned int)strlen(pDate);

    MyQEvent *event = new MyQEvent(MY_QEVENT_DATA);
    event->setValue(cmd, pDate, data_size);

    // post Eevnt
    QCoreApplication::postEvent(server,event);

}
