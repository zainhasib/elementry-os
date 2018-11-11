#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{	
	FILE *fp;
	char buf[100],buf1[100];
	for(int i=0;i<2;i++)
	{
		strcpy(buf,"                  ");
		strcpy(buf1," ");
        printf("Before buf1 %s Length : %d\n", buf1, (int)strlen(buf1));
		printf("Enter name of file : ");
		scanf("%s",buf);
		int w=strlen(buf);
		buf[w] = '\0';
		fp = fopen(buf,"r");
		if(fp == NULL)
		{
			printf("file does not exist\n");
		}
		else
		{
			int l=0;
			char ch=fgetc(fp);
			buf1[l]=ch;
			l++;
			while(ch!=EOF)
			{
				ch=fgetc(fp);
				buf1[l]=ch;
				l++;
			}
            int o = strlen(buf1);
            printf("Strlen %d\n", o);
            buf1[o-1] = '\0';
			printf("data in file is:\n%s\n",buf1);
		}
	}
return 0;
}