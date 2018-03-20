#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
char * arg[] = {
    "ls",
    "-a",
    NULL,
};
void func(char * arg[])
{
    execvp(arg[0],arg);
}
void process_create(void (*func)( char* arg[]),char *arg[] )
{
   pid_t pid = fork();
    switch(pid)
    {
        case -1:
            perror("fork\n ");
            break;
        case 0:
            printf("start creating process\n");
            /*execvp(arg[0],arg);*/
            func(arg);
            printf("error\n");
            exit(1);
            break;
        default:
            {
            int status = 0;
             waitpid(-1,&status,0);
            }
            break;
    }
}
int main()
{

    process_create(func,arg);
    return 0;
}
