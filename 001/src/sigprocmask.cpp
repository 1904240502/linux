#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<pthread.h>

int main()
{
	sigset_t oldset;
	int member;
	if(sigprocmask(SIG_BLOCK,NULL,&oldset)==0)
	{
		if((member=sigismember(&oldset,SIGINT))==1)
		{
			printf("is member\n");
		}
		else if(member==0)
		{
			printf("is not member\n");
		}
		else{
			printf("sigismember error\n");
		}
	}
	pthread_exit(0);
}
