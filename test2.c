#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include<wait.h>

int main(int argc, char const *argv[])
{
    printf("A\n");
    int r = 1;
    for(int i=0;i<3;i++) {
        r = fork();
        if(r == 0) 
        {
            break;
        }
    }
    //sleep(10);
    printf("B : %d \t%d\n", getpid(), getppid());

    wait(NULL);
    return 0;
}

