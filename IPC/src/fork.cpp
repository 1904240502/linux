#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

#define NUM 2

int main()
{
	pid_t pid;

	int i;
	for (i=0;i<NUM;++i)
	{
		pid=fork();
		if(pid<0)
		{
			perror("fork error\n");
			exit(0);
		}else if(pid==0){
			printf("l am child id: %d,parent id: %d\n",getpid(),getppid());
			break;
		}else{
			printf("l am parent id: %d\n",getpid());
			continue;
		}
	}
	for (i=0;i<NUM;++i)
	{
		wait(NULL);
	}
	return 0;

}

