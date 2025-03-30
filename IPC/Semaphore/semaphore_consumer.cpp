#include <iostream>
#include <fcntl.h>      
#include <sys/mman.h>   
#include <sys/stat.h>   
#include <semaphore.h>  
#include <unistd.h>     

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
    int shm_fd = shm_open(SHM_NAME, O_RDWR, 0666);
    SharedMemory* shm = (SharedMemory*)mmap(0, sizeof(SharedMemory), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // Open semaphores
    sem_t* empty = sem_open(SEM_EMPTY, 0);
    sem_t* full = sem_open(SEM_FULL, 0);
    sem_t* mutex = sem_open(SEM_MUTEX, 0);

    // Consume items
    for (int i = 1; i <= 10; i++) {
        sem_wait(full);  // Wait if buffer is empty
        sem_wait(mutex); // Lock critical section

        // Read from shared memory
        int item = shm->buffer[shm->count - 1];
        std::cout << "Consumed: " << item << std::endl;
        shm->count--;

        sem_post(mutex); // Unlock critical section
        sem_post(empty); // Notify producer

        sleep(2);
    }

    // Cleanup
    sem_close(empty);
    sem_close(full);
    sem_close(mutex);
    munmap(shm, sizeof(SharedMemory));
    close(shm_fd);

    return 0;
}
