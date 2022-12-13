#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<signal.h>
#include<stdlib.h>

void sig_handler(int sig)
{
	;
}
unsigned int mysleep(unsigned int seconds)
{
	//注册信号屏蔽字
	struct sigaction act,oldact;
	act.sa_handler=sig_handler;
	sigemptyset(&act.sa_mask);
	sigemptyset(&oldact.sa_mask);
	sigaddset(&act.sa_mask,SIGALRM);
	act.sa_flags=0;
	int rtn=sigaction(SIGALRM,&act,&oldact);
	if(rtn==-1)
	{
		perror("sigaction error\n");
		exit(0);
	}
        /*--------------开始记时------------------*/
	alarm(seconds);
	//设置临时屏蔽字 取消SIGALRM屏蔽
	sigset_t temp;
	temp=oldact.sa_mask;
	if(sigismember(&temp,SIGALRM))
	{
		sigdelset(&temp,SIGALRM);
	}

	//------------失去cpu，回来先执行信号 pause 接受不到信号了 阻塞
	
	//sigsuspend调用期间，采用临时屏蔽字替换原有屏蔽字
	/*----------------------阻塞等信号唤醒-----------------*/
        sigsuspend(&temp);  //原子操作
	/*rtn=pause();
	if(rtn==-1 && errno==EINTR)
	{
		printf("pause sucess\n");
	}*/


	sigaction(SIGALRM,&oldact,NULL);

	rtn=alarm(0);

	return rtn;
}

int main()
{
	while(1)
	{
		mysleep(2);
		printf("------------------\n");
	}
	return 0;
}
/*   alarm闹钟 SIGALRM signal唤醒
 *   pause 当前进程（线程）sleep 当传递信号会 终止进程/调用捕捉函数
 */


