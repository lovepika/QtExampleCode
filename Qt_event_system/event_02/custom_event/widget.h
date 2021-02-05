#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QEvent>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


protected:
    // 处理自定义事件 方法1
    void customEvent(QEvent *event)override;
    // 处理自定义事件 方法2
    bool event(QEvent * event) override;
};

#endif // WIDGET_H
