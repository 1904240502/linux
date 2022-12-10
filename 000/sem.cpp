#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *_buf;
};

int P(int semid,int semnum)
{
	struct sembuf sops={semnum ,-1,SEM_UNDO};
	return (semop(semid,&sops,1));
}

int V(int semid,int semnum)
{
	struct sembuf sops={semnum,+1,SEM_UNDO};
	return (semop(semid,&sops,1));
}

int main(int argc,char** argv)
{
	int key,rt;
	int semid,ret;
	union semun arg;
	struct sembuf semop;
	int flag;

	if (argc>2||(argc==2&&strcmp("del",argv[1])!=0))
	{
		printf("usage:%s\n",argv[0]);
		printf("usage:%s\n del\n",argv[0]);
		return -1;
	}

	key=ftok("/tmp",0x66);

	if(key<0)
	{
		perror("ftok key error\n");
		return -1;
	}

	semid=semget(key,3,IPC_CREAT|0600);
	printf("semid %d\n",semid);
	if(semid==-1)
	{
		perror("create semget seeor\n");
		return -1;
	}

	if(argc==1)
	{
		arg.val=1;
		ret=semctl(semid,0,SETVAL,1);

		if(ret<0)
		{
			perror("ctl sem erroe\n");
			rt=semctl(semid,0,IPC_RMID);
			if(rt==-1)
			{
				perror("semctl\n");
			}else
			{
				printf("semaphore %d deleted!\n",semid);
			}
			return -1;
		}

		ret=semctl(semid,0,GETVAL,arg);
		printf("after semctl setval sem[0].val=[%d]\n",ret);
		system("date");

		printf("P operate begin\n");

		flag=P(semid,0);

		if(flag)
		{
			perror("P operate error\n");
			return -1;
		}

		printf("P operate end\n");

		ret=semctl(semid,0,GETVAL,arg);
		printf("after P sem[0].val=[%d]\n",ret);
		system("date");

		printf("waiting for 5 second\n");
		sleep(5);

		printf("V operate begin\n");

		if(V(semid,0)<0)

		{
			perror("V operate error\n");
			return -1;
		}

		printf("V operate end\n");

		ret=semctl(semid,0,GETVAL,arg);
		printf("after V sem[0].val=[%d]\n",ret);
		system("date");
	}else if(argc==2)
	{
		rt=semctl(semid,0,IPC_RMID);

		if(rt==-1)
		{
			perror("semctl\n");
		}else
		{
			printf("smaphore %d deleted!\n",semid);
		}
	}
	return 0;
}

		
		
