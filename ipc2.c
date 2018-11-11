#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int pipefd[2], pipefd2[2], pipefd3[2];
    int cid1, cid2, cid3;
    char result[100];
    if((pipe(pipefd)) == -1) {
        perror("Pipe");
    }
    if((pipe(pipefd2)) == -1) {
        perror("Pipe");
    }
    if((pipe(pipefd3)) == -1) {
        perror("Pipe");
    }
    if((cid1 = fork()) < 0) {
        perror("Fork Error");
    }
    if(cid1 > 0) {
        char b[20];
        close(pipefd[0]);
        close(pipefd2[1]);
        write(pipefd[1], "5", 2);
        if((cid2 = fork()) < 0) {
            perror("Fork Error");
        }
        if(cid2 > 0) {
            if((cid3 = fork()) < 0) {
                perror("Fork Error");
            }
            if(cid3 > 0) {
            }else {
                char a[20];
                int l;
                close(pipefd[1]);
                close(pipefd2[0]);
                l = read(pipefd3[0], a, 20);
                a[l] = '\0';
                int num = atoi(a);
                num = num + 10;
                l = sprintf(a, "%d", num);
                write(pipefd2[1], a, l);
                printf("CHILD RESULT : %s\n", a);
            }
        }else {
            char a[20];
            int l = read(pipefd2[0], b, 20);
            b[l] = '\0';
            int num = atoi(b);
            num = num + 3;
            l = sprintf(b, "%d", num);
            write(pipefd3[1], b, l);
            printf("CHILD : %s\n", b);
        }
    }else {
        char a[20];
        int l;
        close(pipefd[1]);
        close(pipefd2[0]);
        l = read(pipefd[0], a, 20);
        a[l] = '\0';
        int num = atoi(a);
        num = num + 5;
        l = sprintf(a, "%d", num);
        write(pipefd2[1], a, l);
        printf("CHILD : %s\n", a);
    }
    wait(NULL);
    return 0;
}
