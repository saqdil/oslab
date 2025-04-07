#include <stdio.h>
#include <unistd.h>

int main() {
    for (int i = 0; i < 3; i++) {  // Create 3 child processes
        int pid = fork();

        if (pid < 0) {  // Check for fork failure
            perror("Fork failed");
            return 1;
        }

        if (pid == 0) {  // Child process
            printf("Child %d: PID = %d, Parent PID = %d\n", i + 1, getpid(), getppid());
            return 0;  // Ensures child does not continue in the loop
        }
    }

    sleep(1); // Allow children to print before parent exits
    printf("Parent Process: PID = %d\n", getpid());

    return 0;
}
