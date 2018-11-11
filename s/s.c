#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

pid_t wpid;
int status;

int main()
{
	int i,t1,t2,t3,t4;
	//printf("%d %d \n",getpid(),getppid());
	for(i=0;i<2;i++)
	{
		t1=fork();
		if(t1==0)
		{
			if(i==0)
			{
				t2=fork();
				if(t2==0)
				{
                    for(i=0;i<2;i++)
                    {
                        t3=fork();
                        if(t3==0)
                        break;
                    }
				break;
				}
			}
			else
			{
				for(i=0;i<2;i++)
				{
					t4=fork();
					if(t4==0)
					break;	
				}
			
			}
			break;
		}		
	}
	printf("%d %d \n", getpid(), getppid());
	while ((wpid = wait(&status)) > 0);
	return 0;
}