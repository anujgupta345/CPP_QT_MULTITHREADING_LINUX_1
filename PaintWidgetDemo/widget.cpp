#include "widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QLabel>
#include <QPainterPath>
void Widget::drawPixmapUsingLabelAndStyleusingQPainter()
{
    //Get a pixmap
    //set pixmap to qlabel
    // give pixmap to QPainter for adding colors adding rect and drawings
    QLabel *label = new QLabel(this);

    QPixmap pixmap(300, 300);
    pixmap.fill(Qt::blue);

    QPainter painter(&pixmap);

    QPen pen;
    pen.setColor(Qt::red);  // Setting color
    pen.setWidth(3);        // Optional: Set line thickness
    painter.setPen(pen);

    // Draw a diagonal red line
    painter.drawLine(50, 50, 250, 150);

    // Draw "Hello World!!" inside the pixmap
    painter.setPen(Qt::white);  // Set text color
    painter.drawText(100, 200, "Hello World!!");

    label->setPixmap(pixmap);
    label->show();
}

void Widget::saveQImageOnDiskUsingLabelAndStyleusingQPainter()
{
    QImage image(300, 300, QImage::Format_ARGB32);//same can be done with QPixmap
    image.fill(Qt::blue);
    QPainterPath path;
    path.addEllipse(150, 150, 100, 50);

    QPainter painter(&image);
    QPen pen;
    pen.setColor(Qt::red);  // Setting color
    pen.setWidth(3);        // Optional: Set line thickness
    painter.setPen(pen);
    // Draw a diagonal red line
    painter.drawPath(path);

    // Draw "Hello World!!" inside the pixmap
    painter.setPen(Qt::white);  // Set text color
    painter.fillPath(path, Qt::red);
    painter.drawEllipse(100, 200, 100, 40);

    image.save("output Saved Image.png");
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
//    drawPixmapUsingLabelAndStyleusingQPainter();
//    saveQImageOnDiskUsingLabelAndStyleusingQPainter();

}

Widget::~Widget()
{
}

