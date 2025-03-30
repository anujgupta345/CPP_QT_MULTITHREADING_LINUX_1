#ifndef SHARED_VARIABLE_H
#define SHARED_VARIABLE_H


#include "ipc.h"

class Shared_Variable : public IPC
{
    Q_OBJECT
public:
    explicit Shared_Variable(QWidget *parent = nullptr);
    void writeIPC()override;
signals:

};

#endif // SHARED_VARIABLE_H
