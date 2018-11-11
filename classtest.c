#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int check(int num) {
    if(num == 0) {
        return 0;
    }else {
        return 1;
    }
}

int main() {
    int fdOne[2], fdTwo[2], fdThree[2], fdFour[2];
    if((pipe(fdOne)) == -1) {
        perror("Pipe");
    }
    if((pipe(fdTwo)) == -1) {
        perror("Pipe");
    }
    if((pipe(fdThree)) == -1) {
        perror("Pipe");
    }
    if((pipe(fdFour)) == -1) {
        perror("Pipe");
    }
    int i=0, r;
    for(i=0; i<3; i++) {
        r = fork();
        if(r>0) {
            break;
        }
    }
    // IPC part
    int q, w;

    int num1 = 5, temp1, temp2, temp3;
    int once = 1;
    while(num1) {
        if(i==0) {
            if(once) {
                write(fdOne[1], &num1, sizeof(int));
                once = 0;
            }
            read(fdFour[0], &temp1, sizeof(int));
            num1 = temp1;
            num1--;
            if(num1 == 0) {
                printf("Found 0");
                //break;
            }
            write(fdOne[1], &num1, sizeof(int));
        }else if(i==1) {
            read(fdOne[0], &temp1, sizeof(int));
            num1 = temp1;
            num1--;
            if(num1 == 0) {
                printf("Found 1");
                break;
            }
            write(fdTwo[1], &num1, sizeof(int));
        }else if(i==2) {
            read(fdTwo[0], &temp2, sizeof(int));
            num1 = temp2;
            num1--;
            if(num1 == 0) {
                printf("Found 2");
                //break;
            }
            write(fdThree[1], &num1, sizeof(int));
        }else if(i==3) {
            read(fdThree[0], &temp3, sizeof(int));
            num1 = temp3;
            num1--;
            if(num1 == 0) {
                printf("Found 3");
                //break;
            }
            write(fdFour[1], &num1, sizeof(int));
        }
    }

    return 0;
}