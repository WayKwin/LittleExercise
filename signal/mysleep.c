#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void really_void()
{

}
int  mysleep( int sleep_time )
{
    //bug
    int unsleep;
    struct sigaction act,oldact;
    act.sa_handler = really_void;
    sigaction(SIGALRM,&act,&oldact);
    //保证闹钟和挂起是原子操作
    alarm(sleep_time);
    pause();
    //有可能进入函数之前设置了闹钟,而且闹钟比mysleep函数闹钟早响
    //所以用alarm(0)取消后响的闹钟并返回后响的闹钟还有几秒响
    unsleep = alarm(0);
    sigaction(SIGALRM,&oldact,NULL);
    return unsleep;
}
int main()
{
    printf("i will sleep 3 s\n");
    mysleep(3);
    printf("im wake up\n");
    return 0;
}
