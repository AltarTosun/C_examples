#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define W(x)

int main() {

    int pid = fork();

    if(pid > 0){
        printf("Terminating parent... PID = %d\n",getpid());

    } else{
        sleep(10);
        printf("Running child... PID = %d PPID = %d\n",getpid(),getppid());
    }

    return 0;
}