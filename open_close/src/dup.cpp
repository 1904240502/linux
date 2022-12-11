#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include<unistd.h>
#include<string.h>
//文件描述符重定向 ————>将文件描述符换个位置来描述文件 
//文件描述符指向文件表项 
int main(int argc,char *argv[])
{
    int fd1,fd2;

    fd1 = open(argv[1], O_RDWR);
    fd2 = open(argv[2], O_RDWR);

    printf("fd1=%d\n",fd1);
    printf("fd2=%d\n",fd2);
    //关闭输出
    close(STDOUT_FILENO);
    //printf输出时 结果输入文件描述符为1的文件
    //dup(fd)复制fd1  到最小文件描述符1     
    //fd1返回复制的【新文件】描述符-----最小文件描述符指向的文件   
    fd1=dup(fd1);
    //fd2指向fd1 的文件表项  返回fd2
    fd2=dup2(fd1,fd2);
    printf("fd1=%d\n",fd1);
    printf("fd2=%d\n",fd2);

    char buf[]="dup2 writer\n";
    int rtn=write(fd2,buf,strlen(buf));
    printf("rtn=%d\n",rtn);

    close(fd1);
    close(fd2);

    return 0;
}
