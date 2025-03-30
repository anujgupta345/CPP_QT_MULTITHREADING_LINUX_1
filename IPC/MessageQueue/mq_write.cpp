#include <iostream>
#include <fcntl.h>       // For O_* constants
#include <sys/stat.h>    // For mode constants
#include <mqueue.h>      // POSIX message queue
#include <cstring>

#define MQ_NAME "/my_posix_mq"

int main() {
    // 1️⃣ Open/Create a message queue
    mqd_t mq = mq_open(MQ_NAME, O_CREAT | O_WRONLY, 0666, NULL);
    if (mq == -1) {
        perror("mq_open failed");
        return 1;
    }

    // 2️⃣ Send a message
    const char* message = "Hello from POSIX MQ!";
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("mq_send failed");
        return 1;
    }

    std::cout << "Message sent: " << message << std::endl;

    // 3️⃣ Close the queue
    mq_close(mq);
    return 0;
}
