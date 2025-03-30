#ifndef MESSAGEQUEUW_H
#define MESSAGEQUEUW_H

#include <QObject>
#include "ipc.h"

class MessageQueuw : public IPC
{
    Q_OBJECT
public:
    MessageQueuw();

    // IPC interface
public:
    void writeIPC();
};

#endif // MESSAGEQUEUW_H
