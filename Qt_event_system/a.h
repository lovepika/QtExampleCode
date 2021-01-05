#ifndef A_H
#define A_H

#include <QPushButton>
#include <QEvent>


class A : public QPushButton
{
    Q_OBJECT
public:
//    explicit  A(QPushButton *parent);
     A();

protected:
    void mousePressEvent(QMouseEvent *e) override;

};

#endif // A_H
