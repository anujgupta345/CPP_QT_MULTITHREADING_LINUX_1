#include "Worker.h"
#include <QDebug>
#include <QThread>
Worker::Worker()
{

}

void Worker::doWork() {
    qDebug() << "doWork() slot called in thread:" << QThread::currentThread();
}
