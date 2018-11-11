#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    int pipefd[2], pipefd2[2];
    int cid;
    if((pipe(pipefd)) == -1) {
        perror("Pipe");
    }
    if((pipe(pipefd2)) == -1) {
        perror("Pipe");
    }
    if((cid = fork()) < 0) {
        perror("Fork Error");
    }
    if(cid > 0) {
        char b[20];
        close(pipefd[0]);
        write(pipefd[1], "Hello", 6);
        int l = read(pipefd2[0], b, 20);
        b[l] = '\0';
        printf("PARENT : %s\n", b);
    }else {
        char a[20];
        int l;
        close(pipefd[1]);
        l = read(pipefd[0], a, 20);
        l = sprintf(a, "%s Hi", a);
        write(pipefd2[1], a, l);
        printf("CHILD : %s\n", a);
    }
    wait(NULL);
    return 0;
}
