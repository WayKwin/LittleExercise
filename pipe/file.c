#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main()
{
    int fd[2];
    fd[0] = open("UnknownPipe.txt",O_RDONLY);
    fd[1] = open("UnknownPipe.txt",O_WRONLY);
    pid_t pid = fork();
    if( pid < 0 )
    {
        printf("fork error\n");
        return 1;
    }
    if(pid == 0)
    {
        close(fd[0]);
        char *msg = "talk to the moon\n";
        int cnt = 10;
        while(cnt-- )
        {
            write(fd[1],msg,strlen(msg));
        }
        //普通文件也具有管道效应 互斥同步
        close(fd[1]);
    }
    if(pid > 0)
    {
        close(fd[1]);
        char buf[64];
        while(1)
        {
             ssize_t s =  read(fd[0],buf,sizeof(buf) - 1);
             if(s > 0)
             {
                 buf[s] = '\0';
                 printf("%s",buf);
             }
             if(s == 0)
             {
                 break;
             }
        }
    }
    return 0;
}
