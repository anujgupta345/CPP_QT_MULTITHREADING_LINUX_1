#include <QApplication>
#include <QPushButton>
#include "MyThread.h"
#include <QObject>
#include <QDebug>
#include "Worker.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setFixedSize(500, 500);
    QPushButton button("Click Me", &window);
    window.show();

    //also widgets cannot move to thread and worker should not have a parent
    // worker should not have a parent
    // only thread affinity changes not ownership
    //object still belongs to main thread
    MyThread *thread = new MyThread(nullptr);
    Worker *worker = new Worker;

    worker->moveToThread(thread);

    // Connect button click signal to worker's slot with QueuedConnection
    // need exec in MyThread run function if connection type is queued.
    // for direct connection not requirend
    QObject::connect(&button, &QPushButton::clicked, worker, &Worker::doWork, Qt::QueuedConnection);
    thread->start();
    return app.exec();
}
