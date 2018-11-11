#include<stdio.h>

int main(int argc, char const *argv[])
{
    unsigned int arr[3] = {162,3,4};
    printf("arr : %x\n", arr);
    unsigned char *p;
    p = arr;
    printf("p : %x\n", p);
    printf("*p : %x\n", *p);
    printf("*arr : %x\n", *arr);
    printf("arr : %x\n", arr);
    p = (char *) ((int *)p);
    printf("p : %x\n", p);
    printf("*p : %x\n", *p);
    printf("*arr : %x\n", *arr);
    printf("arr : %x\n", arr+1);
    printf("p+1 : %x\n", p+1);
    printf("*p+1 : %x\n", *(p+4));
    p = (int *) (p+1);
    return 0;
}
