#include "widget.h"
#include "ui_widget.h"

#include <QMouseEvent>
#include <QPainter>

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  pix_buffer_ = QPixmap(400, 300);
  pix_buffer_.fill(Qt::white);
  temp_pix_buffer_ = pix_buffer_;
  is_drawing_ = false;
}

Widget::~Widget() { delete ui; }

void Widget::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton){
        //当鼠标左键按下时获取当前位置作为矩形的开始点
        start_point_ = event->pos();
        is_drawing_ = true;
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event) {
    if(event->button() & Qt::LeftButton){
        //当按着鼠标左键进行移动时，获取当前位置作为结束点,绘制矩形
        end_point_ = event->pos();
        //将缓冲区的内容复制到临时缓冲区,这样进行动态绘制时
        //每次都是在缓冲区图像的基上进行绘制，就不会产生拖影现象了
        temp_pix_buffer_ = pix_buffer_;
        // 更新显示
        update();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event) {
    if(event->button()== Qt::LeftButton){
        //当鼠标左键松开时，获取当前位置为结束点,完成矩形绘制
        end_point_ = event->pos();
        //标记已经结束绘图
        is_drawing_ = false;
        update();
    }
}

void Widget::paintEvent(QPaintEvent *) {
    int x = start_point_.x();
    int y = start_point_.y();
    int width = end_point_.x();
    int height = end_point_.y();

    QPainter painter;
    painter.setPen(QColor(Qt::red));
    painter.begin(&temp_pix_buffer_);
    painter.drawRect(x,y,width,height);
    painter.end();

    painter.begin(this);
    painter.drawPixmap(0,0,temp_pix_buffer_);
    //如果已经完成了绘制，那么更新缓冲区
    if(!is_drawing_){
        pix_buffer_ = temp_pix_buffer_;
    }


}
