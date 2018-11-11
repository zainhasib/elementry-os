#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fdOne[2][2], fdTwo[2][2], fdThree[2][2];
    if((pipe(fdOne[0])) == -1) {
        perror("Pipe");
    }
    if((pipe(fdOne[1])) == -1) {
        perror("Pipe");
    }
    if((pipe(fdTwo[0])) == -1) {
        perror("Pipe");
    }
    if((pipe(fdTwo[1])) == -1) {
        perror("Pipe");
    }
    if((pipe(fdThree[0])) == -1) {
        perror("Pipe");
    }
    if((pipe(fdThree[1])) == -1) {
        perror("Pipe");
    }
    int i=0, r;
    for(i=0; i<3; i++) {
        r = fork();
        if(r==0) {
            break;
        }
    }
    // IPC part
    int q, w;

    int num1, num2, temp1, temp2, temp3;

    if(r>0) {
        printf("Enter the first Number : ");
        scanf("%d", &num1);
        printf("Enter the second Number : ");
        scanf("%d", &num2);
        write(fdOne[0][1], &num1, sizeof(int));
        write(fdOne[0][1], &num2, sizeof(int));
        write(fdTwo[0][1], &num1, sizeof(int));
        write(fdTwo[0][1], &num2, sizeof(int));
        write(fdThree[0][1], &num1, sizeof(int));
        write(fdThree[0][1], &num2, sizeof(int));
        //wait(NULL);
        read(fdOne[1][0], &temp1, sizeof(int));
        read(fdTwo[1][0], &temp2, sizeof(int));
        read(fdThree[1][0], &temp3, sizeof(int));
        printf("Sum : %d\n", temp1+temp2+temp3);
    }else if(r==0 && i==0) {
        // Divide
        int num3, num4;
        read(fdOne[0][0], &num3, sizeof(int));
        read(fdOne[0][0], &num4, sizeof(int));
        num3 = num3 / num4;
        write(fdOne[1][1], &num3, sizeof(int));
    }else if(r==0 && i==1) {
        // Multiply
        int num3, num4;
        read(fdTwo[0][0], &num3, sizeof(int));
        read(fdTwo[0][0], &num4, sizeof(int));
        num3 = num3 * num4;
        write(fdTwo[1][1], &num3, sizeof(int));
    }else if(r==0 && i==2) {
        // Subtract
        int num3, num4;
        read(fdThree[0][0], &num3, sizeof(int));
        read(fdThree[0][0], &num4, sizeof(int));
        num3 = num3 - num4;
        write(fdThree[1][1], &num3, sizeof(int));
    }

    while((w = wait(&q)) > 0);
    return 0;
}