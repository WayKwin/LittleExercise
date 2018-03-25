#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#define ERR_EXIT(m) \
    do \
{ \
    perror(m); \
    exit(EXIT_FAILURE); \
} while(0)
int main()
{
    int infd;
    infd = open("pipe",O_RDONLY);
    if( infd == -1 )
        ERR_EXIT("open read");
    int outfd;
    //O_TRUNC 如果文件存在属性不变
    outfd = open("dst_file",O_WRONLY | O_CREAT | O_TRUNC,0644);
    if( outfd == -1 )
        ERR_EXIT("open write");
    char buf[4096];
    int n;
    while((n = read(infd,buf,sizeof(buf) - 1)) > 0)
    {
        if(n > 0)
        {
            buf[n] = '\0';
           printf("%s\n",buf);
        }
        write(outfd,buf,n);
    }
    close(infd);
    close(outfd);
    //删除管道文件
    unlink("pipe");
    return 0;
}
