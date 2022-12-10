#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int args,const char* argv[]){
	pid_t pid;
	pid=fork();
	
	if(pid<0){
		perror("error");
		exit(1);
	}else if(pid==0){
		printf("child\n");
	}else{
		wait(NULL);
		printf("parent\n");
		while(1);
	}
 return 0;
 }

