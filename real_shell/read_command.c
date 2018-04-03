#include"shell.h"
/*#ifdef READLINE_ON*/
#include<readline/readline.h>
#include<readline/history.h>
/*#endif*/
extern char* buf;
int read_command(char* command[], char*parameters[], char *prompt)
{
    //待解决: 下次读入buf  如何清空数组
    //buf[0] = 0 segement falut
    memset(buf,0,sizeof(buf));
    buf = readline(prompt);
    if(feof(stdin))
    {
        //readline不会把回车键的换行写入文本
        //write  写入buf会是  abcd\n\0的形式
        /*printf("\n");*/
        return 0;
    }
    if(buf[0] == '\0')
        return -1;
    int i = 0;
    int command_status = 0;
    //当 遇到第一个空格
    int status= 1;
    int command_count = 0;
    int parameters_count = 0;
    for(i = 0;buf[i] == ' ';i++);
    for(; buf[i]; buf++)
    {
        if(!isspace(buf[i]) && command_status == 0 )
        {
            command[command_count++] = buf + i;
            command_status = 1;
        }
       else  if(!isspace(buf[i]) && status == 0)
        {
            parameters[parameters_count++] = buf + i;
            status = 1;
        }
        if(isspace(buf[i]))
        {
            status= 0;
            buf[i] = '\0';
        }
    }
    printf("command[] = ");
    i = 0;
    while(command[i])
    {
        printf("%s ",command[i]);
        i++;
    }
    i = 0;
    printf("\n");
    printf("parameters[] = ");
    while(parameters[i])
    {
        printf("%s ",parameters[i]);
        i++;
    }
    return 0;
}
int main()
{
    char buff[256];
    char* a[100];
    char *b[100];
    while(1)
    {
        type_prompt(buff);
        read_command(a,b,buff);
    }
}
/*#endif*/
