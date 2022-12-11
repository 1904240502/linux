#include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

//int execl(const char *pathname, const char *arg, ...,  (char  *) NULL);
//int execlp(const char *file, const char *arg, ... ,(char  *) NULL);
//int execle(const char *pathname, const char *arg, ..., (char *) NULL, char *const envp[]);
//int execv(const char *pathname, char *const argv[]);
//int execvp(const char *file, char *const argv[]);
//int execvpe(const char *file, char *const argv[], char *const envp[]);

/* 
 * l：可变参数 
 * p：第一个参数为file 在path中指定的
 * e：通过envp[] 传递环境变量 
 * v：第二个参数是 数组
 * */

int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("creat fork error\n");
		exit(0);
	}else if(pid==0)
	{
		wait(NULL);
		printf("parent run\n");
	}else{
		printf("child run\n");
		//execlp("ls","-l","-h",NULL); 
		// error 传入参数从argv[0] 终止NULL 
	 	execlp("ls","ls","-l","-h",NULL);
		perror("exec error\n");
		exit(0);
	}
	return 0;
}
