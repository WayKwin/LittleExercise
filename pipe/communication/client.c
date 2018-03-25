#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<errno.h>
#define ERR_EXIT(m) \
    do \
{ \
    perror(m); \
    exit(EXIT_FAILURE); \
} while(0)
int main()
{
    int wfd = open("pipe",O_WRONLY);
    if( wfd < 0 )
    {
        ERR_EXIT("read file open");
    }
    char buf[1024];
    while(1)
    {
        /*buf[0] = 0;*/
        printf("client say#");
        fflush(stdout);
        ssize_t s = read(0, buf, sizeof(buf) - 1);
        if(s > 0)
        {
            buf[s] = 0;
            write(wfd,buf,sizeof(buf) - 1);
        }
        //当读完之后就退出
        else if (s == 0)
        {
            printf("client quit,exit now\n");
            break;
        }
        else if (s < 0 )
        {
            ERR_EXIT("read");
        }

    }
    close(wfd);
    unlink("pipe");
    return 0;
}


