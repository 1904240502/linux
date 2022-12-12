#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int sig)
{
	switch(sig)
	{
		case SIGINT:
			printf("SIGINT caught\n");
			sleep(3);
			break;
		case SIGQUIT:
			printf("SIGQUIT caught\n");
		default:
			printf("caught other\n");
	}
}
int main()
{

	struct sigaction act,oldact;
        act.sa_handler=sig_handler;
        sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask,SIGQUIT);
        act.sa_flags=0;	
	sigaction(SIGINT,&act,&oldact);
	while(1){
	}
	return 0;
}
/*
 *  xxx信号屏蔽期间，xxx信号被屏蔽，多次递送，只接受一次
 *  sa_mask 信号执行期间执行的屏蔽字
 */


