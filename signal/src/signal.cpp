#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void printf_set(sigset_t set)
{
	for(int i=1;i<=32;++i)
	{
		if(sigismember(&set,i))
		{
			putchar('1');
		}else
		{
			putchar('0');
		}
		if(i%10==0){
			putchar(' ');
		}
	}
	printf("\n");
}
void sig_handler(int sig)
{
	switch(sig)
	{
		case SIGINT:
			printf("SIGINT caught\n");
			break;
		default:
			printf("caught other\n");
	}
}
int main()
{
        sigset_t newset,oldset;
	sigemptyset(&newset);
	sigemptyset(&oldset);

	sigprocmask(SIG_BLOCK,NULL,&oldset);
	printf("---------------------\n");
	printf_set(oldset);
	printf("---------------------\n");
	sigaddset(&newset,SIGINT);
	sigprocmask(SIG_SETMASK,&newset,&oldset);
	printf_set(newset);

	signal(SIGINT,sig_handler);
	while(1){
	}
	return 0;
}
