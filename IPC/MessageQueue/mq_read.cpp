#include <iostream>
#include <fcntl.h>       
#include <sys/stat.h>    
#include <mqueue.h>      
#include <cstring>
#include <cstdlib>

#define MQ_NAME "/my_posix_mq"

int main() {
    // 1️⃣ Open the existing queue
    mqd_t mq = mq_open(MQ_NAME, O_RDONLY);
    if (mq == -1) {
        perror("mq_open failed");
        return 1;
    }

    // 2️⃣ Get queue attributes (to determine max message size)
    struct mq_attr attr;
    if (mq_getattr(mq, &attr) == -1) {
        perror("mq_getattr failed");
        return 1;
    }

    std::cout << "Max Message Size: " << attr.mq_msgsize << " bytes" << std::endl;

    // 3️⃣ Allocate buffer dynamically based on max message size
    char* buffer = (char*)malloc(attr.mq_msgsize);
    if (!buffer) {
        perror("malloc failed");
        return 1;
    }

    // 4️⃣ Receive message with proper buffer size
    if (mq_receive(mq, buffer, attr.mq_msgsize, NULL) == -1) {
        perror("mq_receive failed");
        free(buffer);
        return 1;
    }

    std::cout << "Message received: " << buffer << std::endl;

    // 5️⃣ Cleanup//////
    free(buffer);
    mq_close(mq);
    mq_unlink(MQ_NAME);

    return 0;
}
