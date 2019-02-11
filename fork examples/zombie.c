#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

    pid_t pid = fork();


    if(pid > 0) {
        sleep(5);
        printf("parent process... PID = %d\n",getpid());
        wait(NULL);
    }
    else{
        printf("child process... PID = %d\n",getpid());
        exit(1);
    }


    return 0;

}