#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int global;

int main(int args,const char* argv[]){
	int var=0;
	pid_t pid;
	printf("befork fork\n");


        //pid =vfork();
        //befork fork
        //pid=1701342. global=1.  var=1.
	pid =fork();
	//befork fork
        //pid=1712710. global=0.  var=0. 
        //vfork 与主进程共享数据空间
	if(pid<0){
		perror("error");
	}
	else if(pid==0){
		global++;
		var++;
		_exit(0);
	}
	sleep(3);
	printf("pid=%d. global=%d.  var=%d.  \n",getpid(),global,var);
	
	exit(0);
	}
