#ifndef MYTHREAD_H
#define MYTHREAD_H


#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);
    // QThread interface
protected:
    void run();
};

#endif // MYTHREAD_H
