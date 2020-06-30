#include "widget.h"
#include <QApplication>

// 演示Qt 2D绘图的双缓冲绘图

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
