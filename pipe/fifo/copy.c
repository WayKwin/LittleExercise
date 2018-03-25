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
    mkfifo("pipe",0644);
    int infd;
    infd = open("a_tab_of_two_cities",O_RDONLY);
    if( infd == -1 )
        ERR_EXIT("open readfile");
    int outfd;
    outfd = open("pipe",O_WRONLY);
    if( outfd == -1 )
        ERR_EXIT("open pipe");
    char buf[4096];
    int n;
    while((n=read(infd,buf,sizeof(buf)))>0)
    {
        write(outfd,buf,n);
    }
    close(infd);
    close(outfd);
    return 0;
}
