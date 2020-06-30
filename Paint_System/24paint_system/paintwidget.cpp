#include "paintwidget.h"

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(800,600);
    setWindowTitle("Paint Demo");
}

PaintWidget::~PaintWidget()
{

}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this); // why this
    // https://www.devbean.net/2012/10/qt-study-road-2-paint-sys/

    painter.drawLine(80,100,650,500);

    painter.setPen(Qt::red);
    painter.drawRect(10,10,100,400);

    painter.setPen(QPen(Qt::green,10));
    painter.setBrush(Qt::blue);
    painter.drawEllipse(50,150,400,200);

}
