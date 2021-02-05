#include "widget.h"
#include "my_qevent.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    MyQEvent *event = new MyQEvent(MY_QEVENT_DATA);
    a.postEvent(&w,event);

    return a.exec();
}
