#ifndef WORKER_H
#define WORKER_H

#include <QFrame>
#include <QObject>

class Worker :  public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

    void runProcess();
signals:
};

#endif // WORKER_H
