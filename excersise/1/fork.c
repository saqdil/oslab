#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main(){
    pid_t pid = fork();

    if(pid>0){
        printf("This isParent Process\n");
        printf("parent process: %d", getpid());
        printf("Child process: %d", pid);
    }
    else if(pid == 0){
        printf("this is Child Process\n");
        printf("Child Process: %d", getpid());
        printf("Parent Process:%d",getppid());
    }else{
        printf("Fork Failed");
    }
}