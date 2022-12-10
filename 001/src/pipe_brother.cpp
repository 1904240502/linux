#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<pthread.h>
#include<string.h>
#include<sys/wait.h>

#define NUM 2
int main(int argc,char *argv[])
{
	int rtn,i;
	int fd[2];
	pid_t pid;
	rtn=pipe(fd);
	if(rtn==-1){
		perror("pipe error\n");
		exit(0);
	}


	for(i=0;i<NUM;++i)
	{
		pid=fork();
		if(pid<0)
		{
			perror("create fork error\n");
			exit(0);
		}else if(pid==0){
                        break; 
		}
	}
	//子进程的i都小于NUM【break】

	if(i==2)
	{
		close(fd[0]);  
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
	}else if(i==0){
                 
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
	}else if(i==2){
		wait(NULL);
		wait(NULL);
	};
	return 0;
}
