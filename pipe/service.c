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
    umask(0);
   if(mkfifo("pipe",0644) == -1)
   {
       ERR_EXIT("mkfifo");
   }
    int rfd = open("pipe",O_RDONLY);
    if( rfd < 0 )
    {
        ERR_EXIT("read file open");
    }
    char buf[1024];
    while(1)
    {
        buf[0] = 0;
        printf("plase wait\n");
        /*fflush(stdout);*/
        ssize_t s = read(rfd, buf, sizeof(buf) - 1);
        if(s > 0)
        {
            buf[s] = 0;
            printf("client say# %s\n",buf);
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
    close(rfd);
    return 0;
}


