#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPoint>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
protected:
    // 重写鼠标按下 移动 释放事件
    void mousePressEvent(QMouseEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
    // 重绘事件
    void paintEvent(QPaintEvent *event)override;

private:
    Ui::Widget *ui;
    // buff
    QPixmap pix_buffer_;
    // temp_buffer
    QPixmap temp_pix_buffer_;
    QPoint start_point_;
    QPoint end_point_;
    // 是否正在绘图flag
    bool is_drawing_;
};

#endif // WIDGET_H
