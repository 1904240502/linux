#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void *thread_fun(void *ptr);

pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
int count=0;

int main(int argc,const char**argv)
{
	int rtn1,rtn2;
	pthread_t thread_id1,thread_id2;
	rtn1=pthread_create(&thread_id1,NULL,&thread_fun,NULL);
	if(rtn1!=0)
	{
		perror("pthread1_create error !");
		exit(1);
	}
	rtn2=pthread_create(&thread_id2,NULL,&thread_fun,NULL);
	if(rtn2!=0)
	{
		perror("pthread2_create error !");
		exit(1);
	}

	pthread_join(thread_id1,NULL);
	pthread_join(thread_id2,NULL);
	pthread_exit(0);
	printf("-------------main end-------------\n");
}

void *thread_fun(void *ptr)
{
	//pthread_mutex_lock(&mutex);
	count++;
	sleep(2);
	printf("count=%d\n",count);
	//pthread_mutex_unlock(&mutex);
}
