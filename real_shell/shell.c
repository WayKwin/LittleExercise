#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
  char *argv[8];
  int argc = 0;
  //重定向标记
  int redirect_flag = 0;
  int redirect_pos ;
  int append_redirect_flag = 0;
  int append_redirect_pos;
  int pipe_flag = 0;
  int pipe_pos;
void tpye_prompt()
{
    printf("[myshell][%s@%s:%s ",)
}
void  do_parse(char *buf)
{
    int i;
    int status = 0;
    argc = 0;
    for(i = 0;buf[i];i++)
    {
        if(!isspace(buf[i]) && status == 0 )
        {
            argv[argc] = buf + i;
            status = 1;
            // aa bb  cc dd
            // aa (bb cc dd)
            // aa bb (cc dd)
            // aa bb cc dd
            // 所以不能用strmp
            /*if(argv[argc][0] == '>'&& argv[argc][1] != '>')*/
            /*{*/
                /*redirect_flag = 1;*/
                /*// > 的位置*/
                /*redirect_pos = argc;*/
            /*}*/
             /*if(argv[argc][0] == '>' && argv[argc][1] == '>')*/
            /*{*/
                /*append_redirect_flag = 1;*/
                /*append_redirect_flag= argc;*/
            /*}*/
                argc++;
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
void symbol()
{
    int i = 0;
    for(;i < argc; i++)
    {
        if( strcmp(argv[i],">" ) == 0 )
        {

            redirect_flag = 1;
            redirect_pos = i;
        }
        if( strcmp(argv[i],">>") == 0  )
        {
            append_redirect_flag = 1;
            append_redirect_pos = i;
        }
        if( strcmp(argv[i],"|") == 0  )
        {
            pipe_flag= 1;
            pipe_pos= i;
        }
    }
}
void redirect ()
{
    close(1);
    // 将 > 后面的文件打开
    open(argv[++redirect_pos],O_WRONLY);
    //将 > 变成结束符 NULL
    argv[--redirect_pos] = NULL;
}
void append_redirect()
{
    close(1);
    // 将 >> 后面的文件打开
    printf("找到了追加符号:%s\n",argv[append_redirect_pos]);
    open(argv[++append_redirect_pos],O_WRONLY | O_APPEND);
    //将 >> 变成结束符 NULL
    argv[--append_redirect_pos] = NULL;
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
         symbol();
         /*printf("重定向标记:%d\n",redirect_flag);*/
         /*printf("追加重定向标记:%d\n",append_redirect_flag);*/
        if( redirect_flag )
             redirect();
        if( append_redirect_flag)
             append_redirect();
        if(pipe_flag)
            pipe();
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
   char buf[1024] = {};
    while(1)
    {
        type_prompy();
        scanf("%[^\n]%*c",buf);
        do_parse(buf);
        do_execute();
    }

   return 0;
}



