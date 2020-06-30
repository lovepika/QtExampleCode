#include "paintwidget.h"
#include <QApplication>
#include "brushandpen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

// demo 24
//    PaintWidget w;
//    w.show();

    // demo25
    BrushAndPen b;
    b.show();

    return a.exec();
}
