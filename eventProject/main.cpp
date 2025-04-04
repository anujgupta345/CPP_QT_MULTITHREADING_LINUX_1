#include "widget.h"
#include <QInputDevice>
#include <QApplication>
#include <QMouseEvent>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();
    QMouseEvent event(QEvent::MouseButtonPress, QPoint(20,20), QPoint(20,20), Qt::LeftButton, Qt::LeftButton, Qt::NoModifier,

QPointingDevice::primaryPointingDevice("seat0"));
    a.postEvent(&w, &event);
    return a.exec();
}
