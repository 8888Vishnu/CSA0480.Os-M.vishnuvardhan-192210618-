#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024  
struct SharedData {
    int value;
};

int createSharedMemory() {
    key_t key = ftok("shared_memory_example", 65);  

    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    return shmid;
}

void writeDataToSharedMemory(struct SharedData *sharedData) {
    printf("Writing to shared memory...\n");
    sharedData->value = 42;
    printf("Data written: %d\n", sharedData->value);
}
void readDataFromSharedMemory(struct SharedData *sharedData) {
    printf("Reading from shared memory...\n");
    printf("Data read: %d\n", sharedData->value);
}

int main() {
    int shmid = createSharedMemory();

    struct SharedData *sharedData = (struct SharedData *)shmat(shmid, NULL, 0);
    if (sharedData == (struct SharedData *)(-1)) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        readDataFromSharedMemory(sharedData);
    } else {
        writeDataToSharedMemory(sharedData);

        wait(NULL);

        shmdt(sharedData);

        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
