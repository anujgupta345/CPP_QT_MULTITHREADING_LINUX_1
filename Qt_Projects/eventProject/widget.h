#ifndef WIDGET_H
#define WIDGET_H
#include "myeventfilter.h"
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    MyEventFilter myfilter;

    // QWidget interface
protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
};
#endif // WIDGET_H
