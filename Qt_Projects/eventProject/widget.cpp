#include "widget.h"
#include <QPushButton>
#include <QDebug>
#include <QMouseEvent>
#include <QKeyEvent>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->installEventFilter(&myfilter);
    setFixedSize(500, 500);
    QPushButton * button = new QPushButton(this);
    button->setText("click me!!");
    connect(button, &QPushButton::clicked, [](){

        qDebug() << "push button clicked";

    });

}

Widget::~Widget() {}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug() << event->pos();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << (char)event->key();
}
