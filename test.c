#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include<wait.h>

int main(int argc, char const *argv[])
{
    printf("PID : %d\tPPID : %d\n", getpid(), getppid());
    int r = fork();
    if(r==0) {
        sleep(10);
        printf("CHILD RETURN VALUE : %d\tPID : %d\tPPID : %d\n", r,getpid(), getppid());
        fflush(stdout);
    }else {
        printf("PARENT RETURN VALUE : %d\tPID : %d\tPPID : %d\n", r,getpid(), getppid());
        fflush(stdout);
        wait(NULL);
    }
    return 0;
}

