#include<stdio.h>

int main() {
    int a = 8;
    int *p = &a;
    //printf("%d", *p);
    int arr[3] = {0};
    int *q=arr;
    int b=p-q;
    printf("%d",arr[b]);
    return 0;
}