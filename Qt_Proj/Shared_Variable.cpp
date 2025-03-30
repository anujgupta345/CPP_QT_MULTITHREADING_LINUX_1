#include "Shared_Variable.h"
#include "worker.h"

Shared_Variable::Shared_Variable(QWidget *parent)
    : IPC{parent}
{
    this->setFixedSize(500, 500);
    hLayout = new QHBoxLayout(this);

    processA = new QPushButton("Process A");
    processB = new QPushButton("Process B");
writeIPC();
    hLayout->addWidget(processA);
    hLayout->addWidget(processB);

    // Create a worker and move it to a thread
    Worker *worker = new Worker();
    QThread *thread = new QThread();

    worker->moveToThread(thread);

    // Connect the start button to start the thread
    connect(processA, &QPushButton::clicked, [=]() {
        if (!thread->isRunning()) {  // Prevent multiple starts
            qDebug() << "Starting Process A";
            thread->start();
        } else {
            qDebug() << "Thread is already running!";
        }
    });

    // Connect the thread's started signal to the worker's slot
    connect(thread, &QThread::started, worker, &Worker::runProcess);

    // Proper cleanup after thread finishes
    connect(thread, &QThread::finished, worker, &QObject::deleteLater);
    connect(thread, &QThread::finished, thread, [thread]() {
        qDebug() << "Thread finished, cleaning up";
        thread->quit();
        thread->wait();
        thread->deleteLater();
    });
}

void Shared_Variable::writeIPC()
{
    int fd = shm_open("mySharedVariable", O_CREAT | O_RDWR, 0666);
    if(fd < 0)
    {
        qDebug() << "Error writing";
        return;
    }
    ftruncate(fd, 1024);
    auto ptr = mmap(nullptr, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        qDebug() << "mmap failed";
        ::close(fd);
        return;
    }

    strcpy((char*)ptr, "Hey crazy guy got your data ha!!");
    munmap(ptr, 1024);
    ::close(fd);
}
