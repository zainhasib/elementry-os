#include<stdio.h>

void printPattern(int k) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<5;j++){
            if(i==j || j == 5-i-1)printf("*");
            else
            printf(" ");
        }
        
        printf("\n");
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<5;j++){
            if(i==3-j || j-3 == 5-i-1)printf("*");
            else
            printf(" ");
        }
        
        printf("\n");
    }
}

void printPattern2(int k) {
    for(int i=0;i<k;i++) {
        for(int j=0;j<i+1;j++) {
            printf(" ");
        }  
        printf("*"); 
        for(int j=0;j<k-i-1;j++) {
            printf(" ");
        } 
        for(int j=0;j<k-i-1;j++) {
            printf(" ");
        } 
        printf("*");  
        for(int j=0;j<i+1;j++) {
            printf(" ");
        }  
        printf("\n");
    }
    for(int i=0;i<k;i++) {
        for(int j=0;j<k-i-1;j++) {
            printf(" ");
        }  
        printf("*");
        for(int j=0;j<i+1;j++) {
            printf(" ");
        } 
        for(int j=0;j<i+1;j++) {
            printf(" ");
        }  
        printf("*");   
        for(int j=0;j<k-i-1;j++) {
            printf(" ");
        } 
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int k=0;
    printf("Enter the value of k : ");
    scanf("%d", &k);
    printPattern(k);
    return 0;
}
