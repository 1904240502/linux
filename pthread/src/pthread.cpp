#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

const int NUM=5;

int var=1;
void *start_routine(void *argc)
{
	long i=(long)argc;
	var++;
	sleep(i);
	printf("In i=%ld routine pthread id: %lu\n",i,pthread_self());
	pthread_exit(NULL);
}
int main()
{
	pthread_t pid;
	long i;
	for (i=0;i<NUM;++i)
	{
		pid = pthread_create(&pid,NULL,start_routine,(void *)i);
		if(pid!=0)
		{
			printf("pthread error\n");
			exit(1);
		}
	}
	printf("In main pthread id: %lu  var=%d\n",pthread_self(),var);
	pthread_exit(NULL);
}

