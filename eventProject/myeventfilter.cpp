#include "myeventfilter.h"
#include <QMouseEvent>
#include <QKeyEvent>

MyEventFilter::MyEventFilter(QObject *parent)
    : QObject{parent}
{

}

bool MyEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::Type::KeyPress)
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() == Qt::Key_F)
        {
            qDebug() << " pressed key " << keyEvent->key();
            return true;
        }
    }
    return QObject::eventFilter(watched, event);
}
