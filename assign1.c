#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdlib.h>
#include<wait.h>

int main(int argc, char const *argv[])
{
    int q;
    printf("A :: %d\t %d\n", getpid(), getppid());
    int f1 = fork();
    if(f1 > 0) {
        int f2 = fork();
        if(f2 == 0) {
            int f6 = fork();
            if(f6 > 0) {
                int f7 = fork();
            }
        }
    }else if(f1 == 0) {
        int f3 = fork();
        if(f3 == 0) {
            int f5 = fork();
            if(f5 > 0) {
                int f8 = fork();
            }
        }
    }
    printf("B :: %d\t %d\n", getpid(), getppid());
    wait(&q);
    return 0;
}

