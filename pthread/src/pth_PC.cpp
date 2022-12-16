#include<pthread.h>
#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

#define func_err(no,msg) \
{ errno=no; perror(msg);exit(-1);}

typedef struct nodeSrc
{
	int num;
	struct nodeSrc * next;
} *SRC,SN;

//初始 同步锁 以及 处理异步的条件变量
pthread_mutex_t mutex;
pthread_cond_t cond;


SRC head,rear,front;

void * func_p(void * p)
{
	while(1)
	{
		SRC node;
		node =(SRC) malloc(sizeof(SN));
		node->num=1;

		pthread_mutex_lock(&mutex);
		/*--------临界资源----------*/
		if(head->next==NULL)
		{
			front=node;
			rear=front;
		}else
		{
			rear->next=node;
			rear=rear->next;
		}
		head->num++;
		printf("生成产品 现有产品：%d \n",head->num);
                /*--------------------------*/
		pthread_mutex_unlock(&mutex);

		printf("生产完可以进行其它\n");
		pthread_cond_signal(&cond);
		//sleep(1);
	}


	return NULL;
}

void * func_c(void * c)
{
	while(1)
	{
		pthread_mutex_lock(&mutex);
		/*--------临界资源----------*/
		while(head->num==0)
		{
			pthread_cond_wait(&cond,&mutex);
		}
		if(front==rear)
		{
			free(front);
			front=head->next;
			rear=front;
		}else
		{
			head->next=front->next;
			free(front);
			front=head->next;
		}
		head->num--;
		printf("消耗产品 还剩 %d 个产品\n",head->num);
                /*--------------------------*/
		pthread_mutex_unlock(&mutex);
		printf("消耗完可以进行其它\n");
		//sleep(1);
	}
	return NULL;
}

int main()
{

	head =(SRC) malloc(sizeof(SN));
	head->num=0;
	head->next=NULL;

        rear=head->next;
	front=head->next;
	


	pthread_mutex_init(&mutex,NULL);
	pthread_cond_init(&cond,NULL);
	
	pthread_t p,c;
	void * retval;
	int rtn;

	pthread_create(&c,NULL,func_c,NULL);

	pthread_create(&p,NULL,func_p,NULL);

	rtn=pthread_join(p,&retval);
	if(rtn!=0)
	{
		func_err(rtn,"没有等到生产者\n");
	}

	rtn=pthread_join(c,&retval);
	if(rtn!=0)
	{
		func_err(rtn,"没有等到消费者\n");
	}

	return 0;
}
