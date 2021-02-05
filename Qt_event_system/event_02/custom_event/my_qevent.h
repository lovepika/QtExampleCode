#ifndef MYEVENT_H
#define MYEVENT_H

#include <QEvent>

static const QEvent::Type MY_QEVENT_DATA = static_cast<QEvent::Type>(QEvent::registerEventType(QEvent::User+1));
static const QEvent::Type MY_QEVENT_PROGRESS = (QEvent::Type)QEvent::registerEventType(QEvent::User+2);

class MyQEvent : public QEvent
{
public:
    MyQEvent(QEvent::Type type);
    virtual ~MyQEvent();

public:
    bool setValue(unsigned char nCommand, unsigned char * pData, unsigned int nSize);
    unsigned char getCommand() {return m_nCommand;}
    unsigned const char *getData() {return m_pData;}
    unsigned int getSize() {return m_nSize;}

private:
    unsigned char m_nCommand;
    unsigned char *m_pData;
    unsigned int m_nSize;
};

#endif // MYEVENT_H
