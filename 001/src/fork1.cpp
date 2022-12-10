#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int args, const char *argv[])
{

	pid_t pid;
    
	pid= fork();
	if (pid < 0)
	{
		perror("error");
		exit(-1);
	}
	else if (pid == 0)
	{
		
		printf("child:pid=%d\n", getpid());
	}else{
		printf("parent:pid=%d\n", getpid());
	}

	
	printf("print this sentence is pid=%d\n", getpid());
	
	return 0;
}
