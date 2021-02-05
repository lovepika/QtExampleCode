#ifndef MYEVENT_H
#define MYEVENT_H

#include <QEvent>

// 工程经验建议。项目中的event_type全部定义在一个头文件中
// #include "inc_event_type" 定义一些数值宏
// 使用：
// QEvent::registerEventType(QEvent::User+TYPE_NO1)

// style 1
static const QEvent::Type MY_QEVENT_DATA = static_cast<QEvent::Type>(QEvent::registerEventType(QEvent::User+1));
// style 2
static const QEvent::Type MY_QEVENT_PROGRESS = (QEvent::Type)QEvent::registerEventType(QEvent::User+2);

class MyQEvent : public QEvent
{
public:
    MyQEvent(QEvent::Type type);
    virtual ~MyQEvent();

public:
    bool setValue(unsigned char nCommand,const char * pData, unsigned int nSize);
    unsigned char getCommand() {return m_nCommand;}
    const char *getData() {return m_pData;}
    unsigned int getSize() {return m_nSize;}

private:
    unsigned char m_nCommand;
    const char *m_pData;
    unsigned int m_nSize;
};

#endif // MYEVENT_H
