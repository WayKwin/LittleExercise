#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int ret_after = 199 ;
void hander()
{
    printf("i've got the alarm,they can't wake up me Hahaha\n");
    printf("我的闹钟还剩%d,就被吵醒了\n",ret_after);
}
int main()
{
    int wake_up_time = 10;
    alarm(wake_up_time);
    sleep(3);
    ret_after = alarm(6);
    signal(SIGALRM,hander);
    while(wake_up_time--)
    {
        printf("wait to wakeup : %d\n",wake_up_time +1);
        sleep(1);
    }
    return 0;
}
