#include "worker.h"
#include <QDebug>
#include <unistd.h>   // fork(), execvp()
#include <sys/types.h>
#include <sys/wait.h>

#include <sys/mman.h>    // shm_open(), mmap(), munmap(), shm_unlink()
#include <sys/stat.h>    // Permission constants like S_IRUSR, S_IWUSR
#include <fcntl.h>       // O_CREAT, O_RDWR
#include <unistd.h>      // close()
#include <cstring>       // memset(), memcpy()
#include <iostream>
Worker::Worker(QObject *parent)
    : QObject{parent}
{}

void Worker::runProcess() {
    qDebug() << "Process started in worker thread!!!!!!!!";

    pid_t pid = fork();
    if (pid < 0) {
        qDebug() << "Fork failed!";
    }
    else if (pid == 0) {
        // Child process
        qDebug() << "Child process executing";
        // Simulate child process work (e.g., exec() here)
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

        char dataRead[1024];
        strcpy(dataRead, (char*)ptr);
        qDebug()<< dataRead;
        munmap(ptr, 1024);
        ::close(fd);

        shm_unlink("mySharedVariable");

        QFrame w;
        w.setFixedSize(500, 500);


w.show();
        _exit(0);
    }
    else {
        // Parent process
        qDebug() << "Parent process continues";
        waitpid(pid, nullptr, 0);  // Wait for the child process to finish
    }
}
