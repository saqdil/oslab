#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main() {
    int shmid;
    char *shm_ptr;
    pid_t pid;

    shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        shm_ptr = (char *)shmat(shmid, NULL, 0);
        printf("Child reads: %s\n", shm_ptr);
        shmdt(shm_ptr);
    } else {
        shm_ptr = (char *)shmat(shmid, NULL, 0);
        strcpy(shm_ptr, "Hello from parent!");
        sleep(1);
        shmdt(shm_ptr);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}