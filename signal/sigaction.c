#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void handler(int signo)
{
    printf("i've got %d sig\n",signo);
}
struct sigaction sig;
struct sigaction old;
int main()
{
    sig.sa_handler = handler;
    sigaction(SIGINT,&sig,&old);
    while(1)
    {
        sleep(1);
        printf("wait ctrl + c \n");
    }
    return 0;
}
