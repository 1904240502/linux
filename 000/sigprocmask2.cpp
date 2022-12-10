#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<signal.h>
#include<pthread.h>

int main()
{
	sigset_t set,oldset;
	int member;
	if(sigemptyset(&set)==-1)
	{
		printf("sigemptyset error\n");
		exit(1);
	}
	if(sigaddset(&set,SIGINT)==-1)
	{
		printf("sigaddset error\n");
		exit(2);
	}
	if(sigprocmask(SIG_SETMASK,&set,&oldset)==-1)
	{
		printf("set new procmask error\n");
		exit(3);

	}
	if((member=sigismember(&oldset,SIGINT))==1)
	{
		printf("oldset have this  member\n");
	}
	else if(member==0)
	{
		printf("oldset not have this member\n");
	}
	else{
		printf("sigismember error\n");
	}

	if(sigprocmask(SIG_SETMASK,&oldset,NULL)==-1)
	{
		printf("reset old procmask error\n");
		exit(4);
	}
	pthread_exit(0);
}
