#ifndef IPC_H
#define IPC_H

//Linux
#include <unistd.h>   // fork(), execvp()
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>    // shm_open(), mmap(), munmap(), shm_unlink()
#include <sys/stat.h>    // Permission constants like S_IRUSR, S_IWUSR
#include <fcntl.h>       // O_CREAT, O_RDWR
#include <unistd.h>      // close()
#include <cstring>       // memset(), memcpy()

//C++
#include <iostream>

//Qt
#include <QThread>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>

class IPC : public QWidget
{
    Q_OBJECT
public:
    explicit IPC(QWidget *parent = nullptr);
    QPushButton* processA;
    QPushButton* processB;
    QHBoxLayout* hLayout;
    virtual void writeIPC() = 0;
signals:
signals:
};

#endif // IPC_H
