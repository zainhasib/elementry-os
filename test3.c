#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include<wait.h>

int main(int argc, char const *argv[])
{
    int k,q;
    printf("A\n");
    int r = 1;
    for(int i=0;i<3;i++) {
        sleep(2);
        r = fork();
        if(r > 0) 
        {
            break;
        }
    }
    //sleep(10);
    printf("B : %d\t%d", getpid(), getppid());
    while((k=wait(&q))>0 && printf(" %d\n", k));  
    //wait(NULL);
    return 0;
}

