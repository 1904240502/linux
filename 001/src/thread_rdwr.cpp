#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

#define NUM 100 

void ReadFile(int id);
void WriteFile(int id);
void RandomSleep();
void *Reader(void *id);
void *Writer(void *id);

int ReaderNum=0,WriterNum=0;
pthread_rwlock_t rwlock;

int main()
{
	int id[NUM];
	int i;

	pthread_t readThread[NUM],writerThread[NUM];
	pthread_rwlock_init(&rwlock,NULL);
	srand(time(NULL));
	for (i=0;i<NUM;++i)
	{
		id[i]=i;
		pthread_create(&readThread[i],NULL,Reader,(void*)&id[i]);
		pthread_create(&writerThread[i],NULL,Writer,(void*)&id[i]);
	}
	for (i=0;i<NUM;++i)
	{
		pthread_join(readThread[i],NULL);
		pthread_join(writerThread[i],NULL);
	}
	pthread_exit(0);
}


void *Reader(void *id)
{
	RandomSleep();
	pthread_rwlock_rdlock(&rwlock);
	ReaderNum++;
	ReadFile(*((int *)id));
	ReaderNum--;
	pthread_rwlock_unlock(&rwlock);
}

void *Writer(void *id)
{
	RandomSleep();
	pthread_rwlock_wrlock(&rwlock);
	WriterNum++;
	ReadFile(*((int *)id));
	WriterNum--;
	pthread_rwlock_unlock(&rwlock);
}
void RandomSleep()
{
	struct timespec tv;
	tv.tv_sec=0;
	tv.tv_nsec=(long)(rand()*1.0/RAND_MAX*999999999);
	nanosleep(&tv,NULL);
}

void WriteFile(int id)
{
	printf("writer id: %d;reader num: %d,writer num: %d\n",id,ReaderNum,WriterNum);
	RandomSleep();
}

void ReadFile(int id)
{
	printf("reader id: %d;reader num: %d,writer num: %d\n",id,ReaderNum,WriterNum);
	RandomSleep();
}

