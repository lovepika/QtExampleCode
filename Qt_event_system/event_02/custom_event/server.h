#ifndef WIDGET_H
#define WIDGET_H

#include <QObject>
#include <QEvent>

class Server : public QObject
{
    Q_OBJECT

public:
    Server(QObject *parent = nullptr);
    ~Server();


protected:
    // 处理自定义事件 方法1
    void customEvent(QEvent *event) override;
    // 处理自定义事件 方法2
    bool event(QEvent *event) override;
};

#endif // WIDGET_H
