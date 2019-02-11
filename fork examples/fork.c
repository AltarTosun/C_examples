#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    printf("~~~~~ Process begins ~~~~~\n");

    pid_t pid = fork();
    pid_t pid2 = fork();

    if (pid < 0 && pid2 < 0)
        perror("fork() failed\n");

    if(pid == 0){

        wait(NULL);
        printf("It's child and my id:%d my parents id:%d\n", getpid(),getppid());
        printf("child is exiting\n");
        exit(1);

    }

    if(pid2 == 0){

        printf("It's child and my id:%d my parents id:%d\n",getpid(),getppid());
        printf("child is exiting\n");
        exit(1);
    }

    wait(NULL);
    wait(NULL);
    printf("It's parent and my id:%d\n",getpid());
    printf("...Parent is exiting\n");
    printf("~~~~~ Process has ended ~~~~~");
    exit(1);
}
