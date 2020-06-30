#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintDevice>
#include <QPen>

class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    PaintWidget(QWidget *parent = 0);
    ~PaintWidget();
protected:
    // override paintEvent方法
    void paintEvent(QPaintEvent *event) override;
};

#endif // PAINTWIDGET_H
