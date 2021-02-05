#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QEvent>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
signals:

};

#endif // MYWIDGET_H
