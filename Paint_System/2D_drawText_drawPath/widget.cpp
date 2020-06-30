#include "widget.h"
#include <QPainter>
#include <QPainterPath>
#include <QStaticText>

#include "ui_widget.h"

// 定义的宏，来作为运行drawText 和 drawPath的不同的演示的开关
// 注释其他，来运行来查看某一个的效果

//#define MY_DRAW_TEXT "演示drawText"
//#define MY_DRAW_PATH "演示drawPath"
#define MY_DRAW_PATH_FILLRULE "演示path的填充规则"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
}

Widget::~Widget() { delete ui; }

/**
 * @brief Widget::paintEvent
 */
void Widget::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event)

#ifdef MY_DRAW_TEXT
  QPainter painter(this);
  QRectF rect(10.0, 10.0, 380.0, 380.0);
  painter.setPen(Qt::red);
  painter.drawRect(rect);
  painter.setPen(Qt::blue);
  painter.drawText(rect, Qt::AlignHCenter, tr("AlignHCenter"));
  painter.drawText(rect, Qt::AlignLeft, tr("AlignLeft"));
  painter.drawText(rect, Qt::AlignRight, tr("AlignRight"));
  painter.drawText(rect, Qt::AlignVCenter, tr("AlignVCenter"));
  painter.drawText(rect, Qt::AlignBottom, tr("AlignBottom"));
  painter.drawText(rect, Qt::AlignCenter, tr("AlignCenter"));
  painter.drawText(rect, Qt::AlignBottom | Qt::AlignRight,
                   tr("AlignBottom\AlignRight"));

  // drawStaticText
  painter.drawStaticText(QPoint(120, 120),
                         QStaticText(QString("hello use drawStaticText")));

  // 使用QFont
  QFont font("宋体", 12, QFont::Bold, true);
  // 设置下划线
  font.setUnderline(true);
  // 设置上划线
  font.setOverline(true);
  //设置字母大小写
  font.setCapitalization(QFont::SmallCaps);
  // 设置字符间的间距
  font.setLetterSpacing(QFont::AbsoluteSpacing, 10);

  //使用字体
  painter.setFont(font);
  painter.setPen(Qt::green);
  // void QPainter::drawText(const QPointF &position, const QString &text)
  painter.drawText(120, 80, tr("tudou"));
  painter.translate(100, 100);
  painter.rotate(90);
  painter.drawText(0, 0, tr("helloQt"));
#endif

#ifdef MY_DRAW_PATH
  QPainter painter(this);
  //开启抗锯齿
  painter.setRenderHint(QPainter::Antialiasing);

  QPainterPath path;

  // 创建一个QPainterPath对象后就会以坐标原点为当前点进行绘制，
  // 可以使用moveTo()函数改变当前点，移动当前点到点(50，250)
  path.moveTo(50, 250);
  // 从当前点即(50，250)绘制一条直线到点(50，230).完成后当前点更改为(50，230)
  path.lineTo(50, 230);
  //从当前点和点(120，60)之间绘制一条三次贝塞尔曲线
  path.cubicTo(QPointF(105, 40), QPointF(115, 80), QPointF(120, 60));

  path.lineTo(130, 130);
  //向路径中添加一个椭圆
  path.addEllipse(QPointF(130.0, 130.0), 30, 30);
  // 绘制path
  painter.drawPath(path);

  //平移坐标系统后再次绘制路径
  path.translate(200, 0);
  painter.setPen(Qt::darkBlue);
  painter.drawPath(path);
#endif

#ifdef MY_DRAW_PATH_FILLRULE
  QPainter painter(this);
  QPainterPath path;

  // 此path没有设置fillrule。则使用默认的Qt::OddEvenFill
  path.addEllipse(10,50,100,100);
  path.addRect(50,100,100,100);
  painter.setBrush(Qt::cyan);
  painter.drawPath(path);

  //此path手动设置填充规则
  painter.translate(180,0);
  path.setFillRule(Qt::WindingFill);
  painter.drawPath(path);

#endif

}
