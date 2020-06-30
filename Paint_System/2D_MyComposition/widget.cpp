#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QImage>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Widget::paintEvent
 */
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter;

    QImage image(400,300,QImage::Format_ARGB32_Premultiplied);
    // 使用绘图设备，绘制到绘图设备上
    painter.begin(&image);
    // 绘制一个矩形
    painter.setBrush(Qt::green);
    painter.drawRect(100,50,200,200);

    //在四个角分别绘制一个矩形，使用不同的复合模式(composition)
    painter.setBrush(QColor(0,0,255,150));
    //composition没有设置则使用默认的SourceOver
    painter.drawRect(50,0,100,100);
    //QPainter::CompositionMode_SourceIn
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.drawRect(250,0,100,100);
    //QPainter::CompositionMode_DestinationOver
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.drawRect(50,200,100,100);
    //QPainter::CompositionMode_Xor
    painter.setCompositionMode(QPainter::CompositionMode_Xor);
    painter.drawRect(250,200,100,100);
    painter.end();

    // 绘制到当前部件
    painter.begin(this);
    painter.drawImage(0,0,image);

}
