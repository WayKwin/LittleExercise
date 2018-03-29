#include<sys/utsname.h>
#include"shell.h"
#define max_name_len 256
#define max_path_len  1024
char hostname[max_name_len];
char pathname[max_path_len];
void type_prompt(char * prompt)
{
    extern struct passwd* pwd;
    int length;
    pwd = getpwuid( getuid ());
    //获得当前路径
    getcwd(pathname,max_path_len);
    if(gethostname(hostname,max_name_len) == 0 )
    {
        //hostname 后面有.localmain
       *strchr(hostname,'.') = '\0';
        sprintf(prompt,"[myshell][%s@%s ",pwd->pw_name,hostname);
    }
    else
        sprintf(prompt,"[myshell][%s@Unknown ",pwd->pw_name,hostname);
    //提取当前文件夹
    char *dir =strrchr(pathname,'/');
    dir++;
    int len = strlen(prompt);
    if( strcmp(dir,"home") == 0 )
        sprintf(prompt+len,"~]");
    else
        sprintf(prompt+len,"%s]",dir);
    len = strlen(prompt);
    //判断当前是否是root
    if(getuid == 0)
        sprintf(prompt+len,"# ");
    else
        sprintf(prompt+len,"$ ");
    /*printf("%s\n",prompt);*/
}

