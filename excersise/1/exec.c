#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
    printf("Parent Process: PID = %d\n", getpid());
    pid_t pid = fork();
    if(pid < 0){
        perror("fork failed");
        exit(1);
    }
    if(pid==0){
        printf("Child Process PID: %d, executing 'ls' Command\n",getpid());
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
        exit(1);
        
    }else{
        wait(NULL);
        printf("Parent Process : Child finished execution");
    }
    return 0;
}