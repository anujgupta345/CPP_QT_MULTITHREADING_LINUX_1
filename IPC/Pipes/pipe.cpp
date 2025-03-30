#include <iostream>
#include <unistd.h>
#include <cstring>

int main() {
    int fd[2]; // File descriptors: fd[0] - read, fd[1] - write
    pipe(fd);  // Create an anonymous pipe

    pid_t pid = fork(); // Create child process

    if (0 == pid) { // Child Process (Reader)
        close(fd[1]); // Close unused write end
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer)); // Read from pipe
        std::cout << "Child Received: " << buffer << std::endl;
        close(fd[0]); // Close read end
    } else { // Parent Process (Writer)
        close(fd[0]); // Close unused read end
        const char* message = "Hello from Parent!";
        write(fd[1], message, strlen(message) + 1); // Write to pipe
        close(fd[1]); // Close write end
    }
    return 0;
}
