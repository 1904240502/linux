#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(int argc,char *argv[])
{
	char *fname=argv[1];
	//char *fname="out";
	int rtn;
	if(fname==NULL)
	{
		perror("invaild file name\n");
		exit(0);
	}
	rtn=mkfifo(fname,0644);

	pid_t pid;
	int fd1,fd2;
	if(rtn==-1)
	{
		perror("mkfifo error\n");
		exit(0);
	}

        /*
	 * 创建进程子读父写
	 * 普通文件没有阻塞属性 设备文件，管道文件，网络具有阻塞 
	 */
	pid = fork();

	if(pid<0)
	{
		perror("fork error\n");
		exit(0);
	}else if(pid==0)
	{
		printf("child begin\n");
	//	sleep(3);
		fd1=open(fname,	O_RDONLY);
		if(fd1<0)
		{
			perror("child open file error\n");
			exit(0);	
		}
                char buf[1024];
		int len=read(fd1,buf,strlen(buf));
		printf("child read len= %d\n",len);
		len=write(STDOUT_FILENO,buf,len);
		printf("child write len=%d\n",len);
		printf("child end\n");
	}else
	{
		printf("parent begin\n");
		fd2=open(fname,O_WRONLY);
		if(fd2<0)
		{
			perror("parent open file error\n");
			exit(0);
		}
                char buf[]="l am parent \n";
		write(fd2,buf,strlen(buf));
		wait(NULL);
		printf("parent end\n");
	}
	return 0;

}

