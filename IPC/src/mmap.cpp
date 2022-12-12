#include<sys/mman.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	char *p=NULL;
	int fd;

	fd=open("mmaptest",O_RDWR|O_CREAT|O_TRUNC,0644);
	//fd=open("mmaptest",O_RDONLY);
	if(fd==-1)
	{
		perror("open error\n");
		exit(0);

	}

	//lseek 大小扩展必须要有io操作 文件有写权限
	lseek(fd,9,SEEK_END);
	write(fd,"\0",1);
        
	//ftruncate(fd,10);
	//计算文件大小
	int len=lseek(fd,0,SEEK_END);

	printf("file size= %d\n",len);
	p=(char *)mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	//p=(char *)mmap(NULL,len,PROT_WRITE,MAP_SHARED,fd,0);

	//close(fd);
	if(p==MAP_FAILED)
	{
		perror("mmap error\n");
		exit(0);

	}

	strcpy(p,"mmap write\n");
	printf("read: %s",p);

	int rtn=munmap(p,len);
	if(rtn==-1)
	{
		perror("munmap error\n");
		exit(0);
	}
	close(fd);
	return 0;
}
/*
 * 文件大小0 映射区大于0 总线错误
 *
 * 文件大小0 映射区等于0 无效参数
 *
 * 文件属性为只读 映射区为读写 无效参数
 *
 * 创建映射区需要读权限 
 *
 * 文件描述符在mmap创建后就可以关闭
 *
 * offset必须是4096的整数被（MMU映射的最小单位 4k）
 *
 * MAP_PRIVATE|MAP_SHARED修改是否反映到文件 不同进程是共享还是独占
 *
 */

