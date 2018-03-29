#include"shell.h"
/*#ifdef READLINE_ON*/
#include<readline/readline.h>
#include<readline/history.h>
/*#endif*/
extern char* buf;
int read_command(char* command[], char*parameters[], char *prompt)
{
    buf = readline(prompt);
    if(feof(stdin))
    {
        //readline不会把回车键的换行写入文本
        //write  写入buf会是  abcd\n\0的形式
        printf("\n");
        return 0;
    }
    return 0;
}
int main()
{
    char buff[256];
    while(1)
    {
        type_prompt(buff);
        read_command(NULL,NULL,buff);
    }
}
/*#endif*/
