#include <iostream>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>

#define SHM_NAME "/my_shm"  // Shared memory name
#define BUFFER_SIZE 1024


// for shared variable create or open existing or new shared variable using same shm_open API with different flags
//map a variable of type data which we want to write or read => means getting the address/pointer of created shared variable 
//now read or write with any API C or C++ like writing to a memory location 


// Define a shared data structure (same as in the writer)
struct SharedData {
    int number;
    char message[BUFFER_SIZE - sizeof(int)];
};

int main() {
    // 1️⃣ Open existing shared memory
    int fd = shm_open(SHM_NAME, O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open failed");
        return 1;
    }

    // 2️⃣ Map shared memory
    SharedData* shared_memory = static_cast<SharedData*>(
        mmap(nullptr, sizeof(SharedData), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0)
    );

    if (shared_memory == MAP_FAILED) {
        perror("mmap failed");
        close(fd);
        return 1;
    }

    // 3️⃣ Read data from shared memory
    std::cout << "Reader: Data read -> Number: " << shared_memory->number 
              << ", Message: " << shared_memory->message << std::endl;

    // 4️⃣ Cleanup
    munmap(shared_memory, sizeof(SharedData));
    close(fd);

    return 0;
}
