/*
* Qbrush and QPen
*/


#ifndef BRUSHANDPEN_H
#define BRUSHANDPEN_H

#include <QWidget>
#include <QPaintDevice>
#include <QPainter>

class BrushAndPen : public QWidget
{
    Q_OBJECT
public:
    explicit BrushAndPen(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // BRUSHANDPEN_H
