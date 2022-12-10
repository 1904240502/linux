#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include<sys/types.h>


int global;
char buf[]="stdout\n";


int main(int args, const char *argv[])
{

	int var=0;
	pid_t pid;
    
	if(write(STDOUT_FILENO,buf,strlen(buf))<0){
		perror("wirite error\n");
	}

	printf("fork\n");

	//printf("%d\n",pid=fork()<0);
	if ((pid=fork()) < 0)
	{
		perror("error");
	}
	else if (pid == 0)
	{
		global++;
		var++;
		//printf("child:pid=%d\n", getpid());
	}else{
		//printf("main\n");
		sleep(1);
	}
	
	printf("pid= %d global= %d var= %d\n", getpid(),global,var);
	
	return 0;
}
//printf是在链接终端行缓冲 到文件是全缓冲  子进程继承父进程缓冲区
