#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>

  char *argv[8];
  int argc = 0;
void  do_parse(char *buf)
{
    int i;
    int status = 0;
    argc = 0;
    for(i = 0;buf[i];i++)
    {
        if(!isspace(buf[i]) && status == 0 )
        {
            argv[argc++] = buf + i;
            status = 1;
        }
        else if(isspace(buf[i]))
        {
            status = 0;
            //遇到空白把变成\0 表示此段结束
            buf[i] = '\0';
        }
    }
    //exec函数必须以NULL结尾
    argv[argc] = NULL;
}
void do_execute()
{
    pid_t id = fork();
    switch(id)
    {
    case -1:
         perror("fork");
         break;
    case 0:
         //第一个是执行的文件名,后面是执行的参数
        execvp(argv[0],argv);
        printf("error\n");
        exit(2);
        break;
    default:
        {
        int st;
        /*wait(&st);*/
        //只要不是
        while(wait(&st) != id);
        WIFEXITED(st);
        break;
        }
    }
}
int main()
{
    /*char *a[]={*/
        /*"ls",*/
        /*"-a",*/
        /*NULL,*/
    /*};*/
    /*execvp(a[0],a);*/
    /*printf("execute fail \n");*/
        char buf[1024] = {};
    while(1)
    {
        scanf("%[^\n]%*c",buf);
        do_parse(buf);
        do_execute();
    }

    /*for(i; argv[i];i++)*/
    /*{*/
        /*printf("%s\n",argv[i]);*/
    /*}*/
        /*[>printf("%s\n",getenv("VAL"));<]*/
    /*char input[100]={};*/
    /*puts(input);*/
    /*printf("%s",input);*/
    return 0;
}
