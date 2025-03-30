#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>

#define FIFO_NAME "/tmp/my_fifo"

int main() {
    mkfifo(FIFO_NAME, 0666); // Create FIFO (Named Pipe)

    int fd = open(FIFO_NAME, O_WRONLY); // Open FIFO for writing

    const char* messages[] = {"Message1", "Message2", "Message3", "END"};
    for (const char* msg : messages) {
        write(fd, msg, strlen(msg) + 1); // Write message to FIFO
        std::cout << "Produced: " << msg << std::endl;
        sleep(1); // Simulate delay
    }

    close(fd); // Close FIFO
    return 0;
}
