#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int pid,pid1,pid2;
    pid = fork();
    if(pid == -1) {
        printf("error");
        exit(1);
    }
    if(pid!=0) {
        pid1 = getpid();
        printf("P process = %d\n",pid1);
        wait(NULL);
        printf("Child terminated\n");

    }else {
        pid2 = getpid();
        printf("Child p = %d\n",pid2);
    }
    return 0;
}