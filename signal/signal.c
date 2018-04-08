#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
sigset_t s,o,p;
void printSIG(sigset_t* p)
{
    int i = 0;
    for(;i < 32; i++)
    {
       if( sigismember(p,i) )
       {
           printf("1 ");
           fflush(stdout);
       }
       else
       {
           printf("0 ");
           fflush(stdout);
       }
    }
    printf("\n");
}
void hander()
{
    printf("i catch you ctrl-c !!!,you can't do it forevor\n");
}
int main()
{
    int block_cnt = 0;
    sigemptyset(&s);
    sigemptyset(&p);
    sigaddset(&s,SIGINT);
    sigprocmask(SIG_SETMASK,&s,&o);
    signal(SIGINT,hander);
    while(1)
    {
        if(block_cnt == 5)
        {

            printf("you are unfrezee\n");
            sigprocmask(SIG_SETMASK,&o,NULL);
        }
        sleep(1);
        sigpending(&p);
        printSIG(&p);
        //接收到信号五秒后解除信号block
        if(sigismember(&p,SIGINT))
        {
            block_cnt++;
            printf("%d\n",block_cnt);
            printf("warning!!  you are trying unblocking!!\n");
        }
    }
}


