#include "mywidget.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

}

void MyWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "MyWidget" ;
}
