#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n,i=0;
    printf("Enter the Number: ");    
    i = scanf("%d", &n);
    int temp = n;
    int l;
    while(temp != 0) {
        l = temp%10;
        printf("%d\n", l);
        temp = temp/10;
    }
    return 0;
}
