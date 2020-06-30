#include "widget.h"
#include "ui_widget.h"

#include <QBitmap>
#include <QPainter>
#include <QPixmap>
#include <QImage>
#include <QPicture>
#include <QDir>


// 需要看哪一个的效果，把宏的注释放开，其他的宏注释掉就行了
//#define MY_QPIXMAP_AND_QBITMAP "演示QPixmap和QBitmap"
//#define MY_QIMAGE "演示Qimage"
//#define MY_QPICTURE "演示QPicture"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }
/**
 * @brief Widget::paintEvent
 */
void Widget::paintEvent(QPaintEvent *) {

    QPainter painter(this);

#ifdef MY_QPIXMAP_AND_QBITMAP
  // QPixmap QBitmap
  QPixmap pixmap(":/images/resource/img/butterfly.png");
  QPixmap pixmap1(":/images/resource/img/butterfly1.png");

  QBitmap bitmap(":/images/resource/img/butterfly.png");
  QBitmap bitmap1(":/images/resource/img/butterfly1.png");

  painter.drawPixmap(0, 0, pixmap);
  painter.drawPixmap(200, 0, pixmap1);
  painter.drawPixmap(0, 130, bitmap);
  painter.drawPixmap(200, 130, bitmap1);
#endif


#ifdef MY_QIMAGE
  // QImage
  QImage image(300, 300, QImage::Format_RGB32);
  QRgb value;
  //将图片背景填充为白色
  image.fill(Qt::white);

  //改变指定区域的像素点的值
  for (int i = 50; i < 100; ++i) {
    for (int j = 50; j < 100; ++j) {
      value = qRgb(255, 0, 0);  // 红色
      image.setPixel(i, j, value);
    }
  }

  //将图片绘制到窗口中
  painter.drawImage(QPoint(0, 0), image);
#endif

#ifdef MY_QPICTURE
  QPicture picture;
  // 将图像绘制到QPicture中,并保存到文件
  painter.begin(&picture);
  painter.drawEllipse(20,20,100,50);
  painter.fillRect(20,100,100,100,Qt::red);
  painter.end();
  // 保存到文件my_picture.pic
  picture.save(QDir::homePath()+"/my_picture.pic");

  //将保存的绘图动作重新绘制到设备上，这里只是演示，直接使用上面的QPicture对象了。
  picture.load(QDir::homePath()+"/my_picture.pic");
  painter.begin(this);
  painter.drawPicture(200,200,picture);
  painter.end();
#endif
}
