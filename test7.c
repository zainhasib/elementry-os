#include<stdio.h>

int main(int argc, char const *argv[])
{
    FILE *fp, *fp2;
    if((fp=fopen("terminal.c", "r"))==NULL) {
        perror("Error Opening File\n");
    }
    if((fp2=fopen("terminal_new.c", "w+"))==NULL) {
        perror("Error Opening File\n");
    }
    char ch;
    while((ch = getc(fp)) != EOF) {
        printf("%c", ch);
        putc(ch, fp2);
    }
    printf("\n");

    fclose(fp);
    fclose(fp2);
    return 0;
}
