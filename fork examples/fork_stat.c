#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int global = 5;

int main(int argc, char** argvc[]) {
    int local = 5;
    int i;
    int junk;

    if(fork() == 0){
        printf("CHILD global:%p local:%p\n", &global, &local);

        for (i = 0; i < 10 ; i++) {
            local++;
            global++;
            printf("CHILD global:%d local:%d\n", global, local);
        }
        exit(EXIT_SUCCESS);
    }

    wait(&junk);
    printf("PARENT global: %p local: %p\n",&global,&local);
    for (i = 0; i < 10 ; i++) {
        local--;
        global--;
        printf("PARENT global: %d local: %d\n",global,local);
    }

    return 0;
}