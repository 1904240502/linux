#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;

    fd = open("out.txt", O_RDONLY | O_CREAT, 0644);

    printf("fd=%d\n", fd);

    close(fd);

    return 0;
}
