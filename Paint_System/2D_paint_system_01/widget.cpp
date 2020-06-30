#include "widget.h"
#include "ui_widget.h"

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QLinearGradient> //线性渐变

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
 * @param event
 */
void Widget::paintEvent(QPaintEvent *event)
{
//        QPainter painter(this);
    //    painter.setPen(Qt::red);
    //    //  开启抗锯齿
    //    painter.setRenderHint(QPainter::Antialiasing);
    //    painter.drawLine(80, 100, 650, 500);

    /*渐变填充的代码演示*/
    QPainter painter(this);
    QLinearGradient line_gradien(QPointF(40,190),QPointF(70,190));
    // 插入颜色
    line_gradien.setColorAt(0,Qt::yellow);
    line_gradien.setColorAt(0.5,Qt::red);
    line_gradien.setColorAt(1,Qt::green);
    // 指定渐变区域以外的区域的扩散方式
    line_gradien.setSpread(QGradient::RepeatSpread);
    painter.setBrush(line_gradien);
    painter.drawRect(10,170,90,40);

    // 辐射渐变

    QRadialGradient radia_gradient(QPointF(200,190),50,QPointF(275,200));
    radia_gradient.setColorAt(0,QColor(255,255,100,150));
    radia_gradient.setColorAt(1,QColor(0,0,0,50));


}
