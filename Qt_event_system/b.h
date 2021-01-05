#ifndef B_H
#define B_H

#include "a.h"

class B : public A
{
    Q_OBJECT
public:
//    explicit B(QPushButton *parent);
    B();

protected:
    void mousePressEvent(QMouseEvent *e) override;
};

#endif // B_H
