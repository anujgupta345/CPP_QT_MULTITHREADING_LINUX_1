#ifndef WORKER_H
#define WORKER_H

#include <QObject>

class Worker : public QObject {
    Q_OBJECT

public:
    Worker();
signals :void updateCounter(int);
public slots:
    void doWork();
};

#endif // WORKER_H
