#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        perror("Fork failed");
    } else if (pid == 0) {
        // Child process
        printf("Child process is running 'ls' using exec...\n");
        execl("/bin/ls", "ls", "-l", NULL);  // Replace with `ls -l`
        perror("execl failed");
    } else {
        // Parent process
        printf("Parent process waiting...\n");
        wait(NULL);  // Wait for child to complete
        printf("Child finished.\n");
    }

    return 0;
}
