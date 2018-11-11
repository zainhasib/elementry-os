#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int pipefd[6][2];
    int cid, cid2, cid3;
    if((pipe(pipefd[0])) == -1) {
        perror("Pipe");
    }
    if((pipe(pipefd[1])) == -1) {
        perror("Pipe");
    }
    if((pipe(pipefd[2])) == -1) {
        perror("Pipe");
    }
    if((pipe(pipefd[3])) == -1) {
        perror("Pipe");
    }
    if((pipe(pipefd[4])) == -1) {
        perror("Pipe");
    }
    if((pipe(pipefd[5])) == -1) {
        perror("Pipe");
    }
    if((cid = fork()) < 0) {
        perror("Fork Error");
    }
    if(cid > 0) {
        // Parent
        printf("1. PID: %d, PPID: %d\n", getpid(), getppid());
        int b=20;
        int c = write(pipefd[0][1], &b, sizeof(int));
        printf("%d\n", b);
        int l = read(pipefd[5][0], &b, sizeof(int));
        printf("New %d\n", b);
    }else {
        // Child
        printf("2. PID: %d, PPID: %d\n", getpid(), getppid());
        int b;
        const int num = rand()%20;
        int l = read(pipefd[0][0], &b, sizeof(int));
        b = b + num;
        write(pipefd[1][1], &b, sizeof(int));
        if((cid2 = fork()) < 0) {
            perror("Fork Error");
        }
        if(cid2 > 0) {
            // Parent
        }else {
            // Child
            printf("3. PID: %d, PPID: %d\n", getpid(), getppid());
            char b;
            int l = read(pipefd[1][0], &b, sizeof(int));
            const int num = rand()%20;
            b = b + num;
            write(pipefd[2][1], &b, sizeof(int));
            if((cid3 = fork()) < 0) {
                perror("Fork Error");
            }
            if(cid3 > 0) {
                // Parent
            }else {
                // Child
                printf("4. PID: %d, PPID: %d\n", getpid(), getppid());
                int b;
                int l = read(pipefd[2][0], &b, sizeof(int));
                write(pipefd[3][1], &b, sizeof(int));
            }
            l = read(pipefd[3][0], &b, sizeof(int));
            b = b - num;
            write(pipefd[4][1], &b, sizeof(int));
        }
        l = read(pipefd[4][0], &b, sizeof(int));
        b = b - num;
        write(pipefd[5][1], &b, sizeof(int));
    }
    //wait(NULL);
    return 0;
}
