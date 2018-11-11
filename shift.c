#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define FRAMES 4

int main() {
    unsigned char *table;
    table = (unsigned char *) malloc(sizeof(unsigned int)*FRAMES);
    int p[4][4] = {{1,0,1,1},{1,0,0,0},{0,0,1,1},{0,1,0,1}};
    printf("\n*********************************************\n");
    printf("The initial table is : ");
    for(int i=0;i<FRAMES; i++) {
        printf("\n%x", table[i]);
    }
    printf("\n*********************************************\n");
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            table[i] = table[i] >> 1;
            if(p[i][j]) {
                table[i] += 0x80;
            }
        }
    }
    printf("\n*********************************************\n");
    printf("The new table is : ");
    for(int i=0;i<FRAMES; i++) {
        printf("\n%d", table[i]);
    }
    printf("\n*********************************************\n");
    return 0;
}