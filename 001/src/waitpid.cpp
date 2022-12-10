#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CHILDS 5

int main(int args, const char *argv[])
{

	int i, stats;
	pid_t pids[CHILDS];
	pid_t pid_w = -1;
    
	printf("pid=%d,ppid=%d\n", getpid(), getppid());
	for (i = 0; i < CHILDS; i++)
	{
		pids[i] = fork();
		//printf("%d\n", i);
		// printf("pid=%d,ppid=%d\n",getpid(),getppid());
		if (pids[i] < 0)
		{
			perror("error");
			exit(-1);
		}
		else if (pids[i] == 0)
		{
			sleep(i);
			printf("pid=%d,ppid=%d\n", getpid(), getppid());
			exit(i);
		}
	}
	pid_w = waitpid(pids[2], &stats, 0);
	

	return 0;
}
