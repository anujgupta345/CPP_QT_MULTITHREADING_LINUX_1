#include "pipe.h"

Pipe::Pipe() {
    writeIPC();
}

void Pipe::writeIPC()
{
    int BUFFER_SIZE = 1024;
    int fd[2];
    char buffer[BUFFER_SIZE];
    if(pipe(fd) < 0)
    {
        qDebug() << errno;
        return;
    }
    int pid = fork();
    if(pid < 0 )
    {
        qDebug() << errno;
    }
    else if(pid == 0)
    {
        ::close(fd[1]);// close write end
        read(fd[0], buffer, BUFFER_SIZE);
        qDebug()<< "In child process" << buffer;
        ::close(fd[0]);// close read end after reading finished
    }
    else
    {
        ::close(fd[0]);// close read end
        strcpy(buffer, "Hello I am from PIPE");
        write(fd[1], buffer, BUFFER_SIZE);
        ::close(fd[1]);// close write end after writing finished
        waitpid(pid, nullptr, 0);  // Wait for the child process to finish
    }
}
