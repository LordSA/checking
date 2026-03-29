#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
    printf("P s\n");
    int fd = open("demo.txt",O_CREAT|O_WRONLY, 0644);
    pid_t pid = fork();
    if(pid == 0){
        printf("child p created\n");
        printf("child pid = %d\n",getpid());
        close(fd);
        printf("c closed");
        printf("c terminated");
        exit(0);
    }
    else{
        printf("p proc\n");
        printf("p pid %d\n",getpid());
        close(fd);
        printf("p closed");
        printf("p terminated");
        exit(0);
    }
}