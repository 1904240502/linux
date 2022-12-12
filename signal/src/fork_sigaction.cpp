#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

#define NUM 5
void sig_handler(int sig)
{
	pid_t pid;
	//一次捕捉多次wait
	//第一次捕捉后，轮询wait，只回调了一次
	while((pid =wait(NULL))!=-1)
	{
		printf("caught child id %d\n",getpid());
	}
}

int main()
{
	pid_t pid;
	int i;

	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGCHLD);

	sigprocmask(SIG_UNBLOCK,&set,NULL);
	for(i=0;i<NUM;++i)
	{
		if((pid=fork())<0){
			printf("No %d fork error\n",i);
			exit(0);
		}else if(pid==0)
			break;
	}

	if(i==NUM)
	{
		printf("parent: pid= %d\n",getpid());
		struct sigaction act;
		act.sa_handler=sig_handler;
		sigemptyset(&act.sa_mask);
		act.sa_flags=0;	
		sigaction(SIGCHLD,&act,NULL);

		sigprocmask(SIG_UNBLOCK,&set,NULL);
	}else
	{
		printf("child: pid= %d\n",getpid());
	}

	return 0;
}


