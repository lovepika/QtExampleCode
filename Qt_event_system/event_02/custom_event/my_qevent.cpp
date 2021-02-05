#include "my_qevent.h"

MyQEvent::MyQEvent(QEvent::Type type):QEvent(type) {}

MyQEvent::~MyQEvent() {}

bool MyQEvent::setValue(unsigned char nCommand, const char *pData, unsigned int nSize)
{
    m_nCommand = nCommand;
    m_pData = pData;
    m_nSize = nSize;
    return true;
}
