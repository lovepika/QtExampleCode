#include "brushandpen.h"

BrushAndPen::BrushAndPen(QWidget *parent) : QWidget(parent)
{
   resize(800,600);
   setWindowTitle("brush and pen ");
}

void BrushAndPen::paintEvent(QPaintEvent *event)
{
    QRadialGradient gradient(50, 50, 50, 50, 50);
    gradient.setColorAt(0, QColor::fromRgbF(0, 1, 0, 1));
    gradient.setColorAt(1, QColor::fromRgbF(0, 0, 0, 0));

    QBrush brush(gradient);

 //   QPainter painter(this);
 //   QPen pen(Qt::green, 3, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
 //   painter.setPen(pen);

    QPainter painter(this);
    QPen pen;  // creates a default pen

    pen.setStyle(Qt::DashDotLine);
    pen.setWidth(3);
    pen.setBrush(Qt::green);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);

    painter.setPen(pen);

    painter.drawLine(80,10,60,40);


}
