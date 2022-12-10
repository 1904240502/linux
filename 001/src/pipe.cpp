#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<pthread.h>
#include<string.h>


int main(int argc,char *argv[])
{
	int rtn;
	int fd[2];
	pid_t pid;
	rtn=pipe(fd);
	if(rtn==-1){
		perror("pipe error\n");
		exit(0);
	}

	pid=fork();
	if(pid<0)
	{
		perror("create fork error\n");
		exit(0);
	}else if(pid==0){
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
	}else{
		close(fd[0]);  
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
	}
	return 0;
}
