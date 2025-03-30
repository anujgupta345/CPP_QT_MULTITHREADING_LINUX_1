#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstring>
//this file is not stored in disk but as buffer in kernal and when data is read removed from file
#define FIFO_NAME "/tmp/my_fifo"

int main() {
    char buffer[100];

    int fd = open(FIFO_NAME, O_RDONLY); // Open FIFO for reading

    while (true) {
        int bytes = read(fd, buffer, sizeof(buffer)); // Read from FIFO
        if (bytes > 0) {
            std::cout << "Consumed: " << buffer << std::endl;

            if (strcmp(buffer, "END") == 0) { // Stop when "END" is received
                std::cout << "End of Queue. Stopping Reader." << std::endl;
                break;
            }
        }
    }

    close(fd); // Close FIFO
    unlink(FIFO_NAME); // Remove FIFO file
    return 0;
}
