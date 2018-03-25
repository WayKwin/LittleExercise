#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
    char buf[64];
    int fd[2];
    int r = pipe(fd);
    if ( r == -1 )
    {
        perror("make pipe\n");
        return 2;
    }
    pid_t pid = fork();
    if( pid == 0 )
    {
        close(fd[0]);
        scanf("%s",buf);
        /*char *msg = "hello world";*/
        write(fd[1],buf,strlen(buf));
        /*printf("write : %d\n",strlen());*/
        close(fd[1]);
    }
    if( pid > 0  )
    {
        close(fd[1]);
        while(1)
        {
            // 读文件  sizeof  和strlen 输出形式不一样
            // 使用strlen 每次只能读出一个字符
            // 警告, 使用strlen求未初始化数组的长度
        ssize_t s = read(fd[0],buf,sizeof(buf) - 1);
        if( s > 0 )
        {
            buf[s] = '\0';
            printf("%s\n",buf);
        }
        if(s == 0)
        {
            break;
        }
        /*printf("%d\n",s);*/
        /*printf("read : %d\n",strlen(buf));*/
        }
    }
    return 0;
}
