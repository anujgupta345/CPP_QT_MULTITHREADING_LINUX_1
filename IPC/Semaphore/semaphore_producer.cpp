#include <iostream>
#include <fcntl.h>      // For O_CREAT, O_EXCL
#include <sys/mman.h>   // For shared memory
#include <sys/stat.h>   // For mode constants
#include <semaphore.h>  // POSIX semaphores
#include <unistd.h>     // For ftruncate, sleep()

#define SHM_NAME "/shm_example"
#define SEM_EMPTY "/sem_empty"
#define SEM_FULL "/sem_full"
#define SEM_MUTEX "/sem_mutex"
#define BUFFER_SIZE 5

struct SharedMemory {
    int buffer[BUFFER_SIZE];
    int count;
};

int main() {
    // Open shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(SharedMemory));
    SharedMemory* shm = (SharedMemory*)mmap(0, sizeof(SharedMemory), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    shm->count = 0;

    // Open semaphores
    sem_t* empty = sem_open(SEM_EMPTY, O_CREAT, 0666, BUFFER_SIZE);
    sem_t* full = sem_open(SEM_FULL, O_CREAT, 0666, 0);
    sem_t* mutex = sem_open(SEM_MUTEX, O_CREAT, 0666, 1);

    // Produce items
    for (int i = 1; i <= 10; i++) {
        sem_wait(empty); // Wait if buffer is full
        sem_wait(mutex); // Lock critical section

        // Write to shared memory
        shm->buffer[shm->count] = i;
        std::cout << "Produced: " << i << std::endl;
        shm->count++;

        sem_post(mutex); // Unlock critical section
        sem_post(full);  // Notify consumer

        sleep(1);
    }

    // Cleanup
    sem_close(empty);
    sem_close(full);
    sem_close(mutex);
    munmap(shm, sizeof(SharedMemory));
    close(shm_fd);

    return 0;
}
