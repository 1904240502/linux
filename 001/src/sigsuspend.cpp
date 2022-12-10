#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>

void sig_handler(int sig)
{
	switch(sig)
	{
		case SIGQUIT:
			printf("SIGQUIT is caught\n");
			break;
		case SIGINT:
			printf("SIGINT is caught\n");
			break;
		default:
			printf("other signal\n");
	}

}


int main()
{
	sigset_t newset,oldset;

//	signal(SIGQUIT,sig_handler);
	signal(SIGINT,sig_handler);

	sigemptyset(&newset);
	sigaddset(&newset,SIGINT);
//	sigaddset(&newset,SIGQUIT);

	sigprocmask(SIG_SETMASK,&newset,&oldset);
	printf("please enter Ctrl-\\...\n");
	//sigsuspend(&newset);
	sleep(10);
	
	printf("after sigsuspend retuen\n");
   	sigprocmask(SIG_SETMASK,&oldset,NULL);
	pause();
	return 0;
}	
