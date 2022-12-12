#include<sys/mman.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int var=10;

int main()
{
	int *p=NULL;
	int fd;
	pid_t pid;

	fd=open("mmapfork",O_RDWR|O_CREAT|O_TRUNC,0644);
	if(fd==-1)
	{
		perror("open error\n");
		exit(0);

	}

        
	ftruncate(fd,4);
	int len=lseek(fd,0,SEEK_END);

	printf("file size= %d\n",len);
	p=(int *)mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);

	if(p==MAP_FAILED)
	{
		perror("mmap error\n");
		exit(0);

	}

	close(fd);

	pid=fork();
	if(pid<0)
	{
		perror("fork error\n");
		exit(0);
	}else if(pid==0)
	{
		*p=2000;
		var=1000;
		printf("child: *p= %d,var= %d\n",*p,var);
	}else{
		wait(NULL);
		printf("parent: *p= %d,var= %d\n",*p,var);
	}
	int rtn=munmap(p,len);
	if(rtn==-1)
	{
		perror("munmap error\n");
		exit(0);
	}
	return 0;
}
