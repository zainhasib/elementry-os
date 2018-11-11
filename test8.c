#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc, char const *argv[])
{
    int file = open("a.txt", O_RDONLY);
    int file2 = open("b.txt", O_WRONLY);
    char ch[100];
    int length;
    while((length = read(file, ch, 1)) != 0) {
        ch[length] = '\0';
        printf("%s", ch);
        write(file2, ch, 1);
    }
    printf("\n");
    close(file);
    close(file2);
    return 0;
}