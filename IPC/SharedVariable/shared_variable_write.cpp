#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>

#define SHM_NAME "/my_shm"  // Shared memory name
#define BUFFER_SIZE 1024

// Define a shared data structure
struct SharedData {
    int number;
    char message[BUFFER_SIZE - sizeof(int)];
};

int main() {
    // 1️⃣ Create shared memory
    int fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open failed");
        return 1;
    }

    // 2️⃣ Set the size of the shared memory
    if (ftruncate(fd, sizeof(SharedData)) == -1) {
        perror("ftruncate failed");
        close(fd);
        return 1;
    }

    // 3️⃣ Map shared memory into process space
    SharedData* shared_memory = static_cast<SharedData*>(
        mmap(nullptr, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)
    );

    if (shared_memory == MAP_FAILED) {
        perror("mmap failed");
        close(fd);
        return 1;
    }

    // 4️⃣ Write data to shared memory
    shared_memory->number = 42;
    strcpy(shared_memory->message, "Hello from Shared Memory!");

    std::cout << "Writer: Data written -> Number: " << shared_memory->number 
              << ", Message: " << shared_memory->message << std::endl;

    // 5️⃣ Keep the process running to allow the reader to access data
    std::cout << "Writer: Press Enter to exit...";
    std::cin.get();

    // 6️⃣ Cleanup
    munmap(shared_memory, sizeof(SharedData));
    close(fd);
    shm_unlink(SHM_NAME);  // Remove shared memory after use

    return 0;
}
