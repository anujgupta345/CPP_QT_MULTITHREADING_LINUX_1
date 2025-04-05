#ifndef PIPE_H
#define PIPE_H

#include <QObject>
#include "ipc.h"

class Pipe : public IPC
{
    Q_OBJECT
public:
    Pipe();

    // IPC interface
public:
    void writeIPC();
};

#endif // PIPE_H
